module rlservice;

revision('rlservice, "$Id$");

copyright('rlservice, "(c) 2016 T. Sturm");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

%
%   AM   |   SM
%        |
%  rl<service> --+-> rl_<service>!$
%                |   ---> rl_servicewrapper
%                |        ---> rl_!*<service>
%                |             ---> rl_<service>
%                |                  ---> apply(rl_<service>!*)
%

fluid '(!*lower);
fluid '(!*raise);
fluid '(mode!*);

global '(rl_services!*);
fluid '(rl_servl!*);

% We provide a stat and a formfn for the rl_service specifications in
% redlog/rl/rlservices.red. Although, those specifications are just listed nests
% of equations, there are several issues parsing them directly with xread: The
% equations may contain RLISP keywords, default arguments should be xread in
% AM, and we want to parse types in CamelCase.

put('rl_service, 'stat, 'rl_serviceStat);

asserted procedure rl_serviceStat(): List;
   % Read the opening curly brace and clean up at the end. The main loop parsing
   % the list is in the next function.
   begin scalar spec;
      scan();
      if cursym!* neq '!*lcbkt!* then
	 rederr {"expecting '{' in rl_service but found", cursym!*};
      spec := rl_serviceStatList();
      scan();  % !*semicol!*
      return {'rl_service, spec}
   end;

asserted procedure rl_serviceStatList(): Alist;
   % We hav just read '{'. Parse a list with entries of the form [name = entry].
   % [name] is an alphabetic identifier. For [entry], there are four
   % cases:
   % (a) An atom. This is our default assumption.
   % (b) Another list such as the one we are currently parsing. This is
   %     triggered by the entry starting with '{.'
   % (c) An expression to be parsed by xread in algebraic mode. This is
   %     triggered by by the [name] "default."
   % (d) An expression to be parsed by xread in symbolic mode and
   %     case-sensitive. This is triggered by by the [name] "type."
   % At the time of writing this code Reduce is not case-sensitve, and upper
   % case would be folded by the Lisp reader. We are going to suppress that
   % folding when reading types, because we wangt to preserve CamelCase for our
   % help system. On the other hand, we do not want to bring mixed-case
   % identifiers into the system at the present stage. Our solution is to
   % keep all types as strings, and to convert them into expressions on the fly
   % when needed. The result is going to be an Alist corresponding to the input
   % (nested) list of equations, and a subsequent formfn is going to take care
   % of the rest.
   begin scalar spec, key, entry;
      scan();
      while cursym!* neq '!*rcbkt!* do <<
	 % We are not on the right hand side of an equation. We need an
	 % alphabetic identifier. We strictly admit only alphabetic characters,
	 % no digits.
      	 if not lto_alphap cursym!* then
	    rederr {"expecting alphabetic key in rl_service but found", cursym!*};
      	 key := cursym!*;
	 % Now the four cases (a)-(d) discussed above:
	 entry := if key eq 'default then  % case (c)
	    rl_amReadDefaultToForm()
	 else if key eq 'type then  % case (d)
	    rl_csReadTypeToString()
	 else  % case (a) or (b)
	    rl_readListOrAtom();
	 push(key . entry, spec);
	 % Expecting ',' or '}' now:
	 if cursym!* neq '!*rcbkt!* then <<
	    if cursym!* neq '!*comma!* then
	       rederr {"expecting ',' or '}' in rl_service but found", cursym!*};
	    scan()
	 >>
      >>;
      return reversip spec
   end;

asserted procedure rl_amReadDefaultToForm(): List;
   begin scalar !*mode;
      !*mode := 'algebraic;
      rl_skipequal("rl_service");
      return xread t
   end;

asserted procedure rl_csReadTypeToString(): String;
   % Locally case-sensitive scanning of CamelCase types. It is important to have
   % case-sensitivity switched on already with the scanning of the '=' because
   % there is a lookahead with nextsym!*.
   begin scalar !*lower, !*raise;
      rl_skipequal("rl_service");
      return ioto_smaprin xread t
   end;

asserted procedure rl_readListOrAtom(): String;
   begin scalar entry;
      rl_skipequal("rl_service");
      scan();
      if cursym!* eq '!*lcbkt!* then <<  % case (b)
	 entry := rl_serviceStatList()
      >> else <<  % case (a)
	 if not atom cursym!* then
	    rederr {"expecting atomic entry or list in rl_service but found", cursym!*};
	 entry := cursym!*
      >>;
      scan();
      return entry
   end;

put('rl_service, 'formfn, 'rl_formService);

asserted procedure rl_formService(argl: List, vars: List, m: Id): List;
   % Analyze the equational specifications of services, and generate
   % corresponding functions and bindings.
   begin scalar mode;
      % Valid choices for mode are sm and both. We always build the SM
      % interface, because it is called by the AM interface:
      mode := lto_eatsoc('mode, cadr argl, {"missing mode in", argl});
      if mode eq 'both then
	 return rl_formServiceBoth cadr argl;
      if mode eq 'sm then
	 return rl_formServiceSm cadr argl;
      rederr {"invalid mode", mode, "in", argl}
   end;

asserted procedure rl_formServiceBoth(spec: Alist): List;
   begin
      scalar b, doc, names, types, defaults, docs, rtype, rl_args, rl_!*args;
      scalar rl_b!*, rl_b, rl_!*b, rl_b!$, rlb;
      scalar p, docal, fluids;
      {b, doc, names, types, defaults, docs, rtype, rl_args, rl_!*args} :=
 	 rl_formServiceAnalyzeSpec spec;
      {rl_b!*, rl_b, rl_!*b, rl_b!$, rlb} := rl_formServiceFunctionNames('rl_, b);
      % We are going construct a progn in [p], which is going to be the
      % result of this macro.
      %
      % rtypepart is the rtype of the part function. TS does not exactly
      % understand anymore why this is used here. It might again have to do
      % with rl vs. sl.
      push({'put, mkquote rlb, ''rtypefn, ''rtypepart}, p);
      % An Alist for documentation with the rlhelp submodule:
      docal := {
	 'synopsis . rl_docSynopsis(rlb, names, types, defaults),
	 'returns . rtype,
	 'description . doc,
	 'arguments . rl_docArguments(names, types, docs),
	 'switches . rl_docSwitches(names, types, docs)};
      push({'put, mkquote rlb, ''docal, mkquote docal}, p);
      push({'put, mkquote rlb, ''intypes, mkquote types}, p);
      push({'put, mkquote rlb, ''outtype, rtype}, p);
      push({'setq, 'rl_services!*, {'cons, mkquote rlb, 'rl_services!*}}, p);
      % A psopfn as the AM entry point:
      push({'put, mkquote rlb, ''psopfn, mkquote rl_b!$}, p);
      % The function bound to the psopfn:
      push({'put, mkquote rl_b!$, ''cleanupfn, ''rl_cleanup}, p);
      push({'put, mkquote rl_b!$, ''number!-of!-args, 1}, p);
      push(
	 {'de, rl_b!$, '(u),
 	    {'rl_servicewrapper,
	       mkquote rl_!*b,
 	       'u,
	       mkquote names,
 	       mkquote for each x in types collect rl_typeString2TypeForm x,
 	       mkquote defaults,
 	       mkquote rl_typeString2TypeForm rtype,
	       mkquote rl_b!*,
	       mkquote rlb}},
 	 p);
      % All switches corresponding to switch arguments are made fluid:
      if fluids then push({'fluid, mkquote fluids}, p);
      % A wrapper around the SM entry point with lambda binding for the
      % switches:
      push({'put, mkquote rl_!*b, ''number!-of!-args, length rl_!*args}, p);
      push({'de, rl_!*b, rl_!*args, {'apply, mkquote rl_b, 'list . rl_args}}, p);
      p := rl_formServiceSm1(rl_b, rl_b!*, rl_args, p);
      p := rl_formServiceBlackBoxes(spec, p);
      return 'progn . reversip p
   end;

asserted procedure rl_formServiceAnalyzeSpec(spec: Alist): List;
   begin
      scalar b, doc, names, types, defaults, docs, rtype, rl_args, rl_!*args,
 	 default, pos, name, type;
      integer minswitch, maxother, maxall;
      % Determine the base name of the service:
      b := lto_eatsoc('name, spec, {"missing service name in", spec});
      % Determine arguments and their order. Construct corresponding lists of
      % formal parameters:
      minswitch := length spec;  % initialize with upper bound on number of args
      for each pr in spec do
 	 if car pr eq 'arg then <<
	    name := lto_eatsoc('name, cdr pr,
 	       {"arg without name in service", b});
	    pos := lto_eatsoc('pos, cdr pr,
 	       {"arg", name, "without pos in service", b});
	    if assoc(pos, names) then
	       rederr {"pos", pos, "specified twice in service", b};
	    doc := lto_catsoc('doc, cdr pr) or "";
	    % In [spec] there are both [type] and [typestring] present, where
	    % the latter has been generated by the stat. We need the strings to
	    % preserve case for the help system. Within the present function we
	    % are using both [type] and [typestring]. For the sake of
	    % modularization we return only the string, at the price of
	    % converting them once more into identifiers later on. All this
	    % happens during compilation and is not time-critical. Also, there
	    % is some hope for a case-sensitive Reduce in the future where that
	    % reduncance would entirly disappear.
	    type := lto_eatsoc('type, cdr pr,
 	       {"arg", name, "without type in service", b});
	    if type = "Switch" then <<
	       % Switches are Redlog switches to be lambda-bound during the
	       % call. The argument name is without the leading "rl." Default is
	       % the corresponding (global) switch setting.
	       minswitch := min2(pos, minswitch);  % smallest Switch position
	       maxall := max2(pos, maxall);  % largest overall position
	       default := intern compress append(explode '!*rl, explode name);
	       push(pos . (name . default), defaults);
	       push(pos . default, rl_!*args)
	    >> else <<
	       maxother := max2(pos, maxother);  % largest non-Switch position
	       maxall := max2(pos, maxall);
	       default := atsoc('default, cdr pr);
	       if default then
	       	  push(pos . (name . cdr default), defaults);
	       push(pos . name, rl_args);
	       push(pos . name, rl_!*args)
	    >>;
	    push(pos . name, names);
	    push(pos . doc, docs);
	    push(pos . type, types)
	 >> else if car pr eq 'returns then <<
	    % [returns] may be not present at all, which means that the service
	    % does not return anything meaningful. On the other hand, if it is
	    % present, then we insist on the specification of a return type.
	    rtype := lto_eatsoc('type, cdr pr,
 	       {"service", b, "without return type"})
	 >>;
      % We insist that positions are numbered 1, ..., n without gaps:
      if not eqn(maxall, length names) then
	 rederr {"bad arg position numbering in service", b};
      % Switches must come after all other arguments:
      if minswitch neq length spec and minswitch neq maxother + 1 then
	 rederr {"bad switch positions in service", b};
      % Argument names including Switches in the right order:
      names := rl_sortAndProject names;
      % Argument doc strings, possible empty, in the right order:
      docs := rl_sortAndProject docs;
      % Types including Switches in the right order:
      types := rl_sortAndProject types;
      % Argument names without Switches in the right order:
      rl_args := rl_sortAndProject rl_args;
      % Non-Switch argument names followed by defaults for the Switchs, i.e.
      % !*rl<flag> instead of <flag>. This will be used within the body of
      % rl_!*<b>:
      rl_!*args := rl_sortAndProject rl_!*args;
      % PSL has a limitation of 14 function arguments. We do not want to make an
      % effort to work around this in any way. Our philosophy is rather that no
      % function should depend on more than 14 parameters (including relevant
      % switches). At present, e.g., cl_simpl already depends on more. We have
      % to work on this soon.
      if length rl_!*args > 14 then
	 rederr {"too many arguments for service", b};
      % An Alist mapping names (including Switchs) to default values:
      defaults := rl_sortAndProject defaults;
      doc := lto_catsoc('doc, spec) or "";
      return {b, doc, names, types, defaults, docs, rtype, rl_args, rl_!*args}
   end;

asserted procedure rl_formServiceFunctionNames(rl_: Id, b: Id): List;
   begin scalar rl, rl_b, rl_!*b, rlb, rl_b!$, rl_b!*;
      rl_ := reversip explode rl_;
      % The AM prefix has no underscore:
      rl := reverse cdr rl_;
      rl_ := reversip rl_;
      rl_b := intern compress append(rl_, explode b);
      rl_!*b := intern compress append(rl_, append(explode '!*, explode b));
      rlb := intern compress append(rl, explode b);
      rl_b!$ := intern compress nconc(explode rl_b, '(!! !$));
      % rl_b!* will actually be a fluid, not a function:
      rl_b!* := intern compress nconc(explode rl_b, '(!! !*));
      return {rl_b!*, rl_b, rl_!*b, rl_b!$, rlb}
   end;

asserted procedure rl_typeString2TypeForm(s: String): Any;
   % Here we are at a very subtle point: The string [s] contains a type either
   % atomic like "Integer" or composite like "List(Integer)." We want to use our
   % xread-based ioto_sxread rather than parsing composite types ourselves. The
   % problem is that we are not case-sensitve so that xread would crash on
   % reading Integer, which is an RLISP type. Our solution here is to once more
   % locally switch on case-sensitivity and then explicitly convert to lower
   % case AFTER parsing. Notice that there is an assumtion here that our type in
   % [s] is either an identifier or a flat list of identifiers. In fact, already
   % in our stat above, where [s] originates from, only local case-sensitivity
   % allowed us to parse types using xread. In the rltype module the problem
   % does not occur, because there are only atomic types, and we do not use
   % xread but scan. If Reduce becomes case-sensitive in the future the code
   % here must be revised, and all type strings would probably disappear. If
   % someone decided that in a case-sensitive Reduce both [integer] and
   % [Integer] should denote that RLISP type, then we would have to think even
   % more.
   begin scalar x;
      x := ioto_sxread s where !*lower=nil, !*raise=nil;
      if idp x then
      	 return intern lto_downcase x;
      return for each y in x collect lto_downcase y
   end;

asserted procedure rl_formServiceSm(spec: Alist): List;
   begin scalar b, rl_b, argl; integer n;
      b := lto_eatsoc('name, spec, {"missing service name in", spec});
      rl_b := intern compress nconc(explode 'rl_, explode b);
      rl_b!* := intern compress nconc(explode rl_b, '(!! !*));
      n := lto_eatsoc('argnum, spec, {"missing argnum in", spec});
      argl := for i := 1:n collect mkid('a, i);
      return 'progn . reversip rl_formServiceSm1(rl_b, rl_b!*, argl, nil)
   end;

asserted procedure rl_formServiceSm1(rl_b: Id, rl_b!*: Id, argl: List, p: List): List;
   % Build the SM interface: rl_<b> is the SM entry point. It applies the
   % function stored in a fluid rl_<b>!*. That function depends on the current
   % context. All those fluids are collected in in fluid list rl_servl!*, where
   % they are found and rebound with context swithes via rl_set. Prog statements
   % are aadd to p, all in reverse order.
   begin scalar rl_b!*;
      % Make the rl_<b>!* identifier fluid, and add it to rl_servl!*, which is
      % used by rl_set:
      push({'fluid, mkquote {rl_b!*}}, p);
      push({'setq, 'rl_servl!*, {'cons, mkquote rl_b!*, 'rl_servl!*}}, p);
      % Create the actual SM entry point function:
      push({'put, mkquote rl_b, ''number!-of!-args, length argl}, p);
      push({'de, rl_b, argl, {'apply, rl_b!*, 'list . argl}}, p);
      return p
   end;

asserted procedure rl_formServiceBlackBoxes(spec: Alist, p: List): List;
   begin
      scalar d, name, args, vn;
      integer n;
      for each pr in spec do
	 if eqcar(pr, 'blackbox) then <<
	    d := cdr pr;
	    name := lto_eatsoc('name, d, {"missing name in black box"});
	    n := lto_eatsoc('argnum, d, {"missing argnum in black box", n});
	    name := intern compress nconc(explode 'rl_, explode name);
	    args := for i := 1:n collect mkid('a, i);
	    vn := intern compress nconc(explode name, explode '!*);
      	    push({'fluid, mkquote {vn}}, p);
      	    push({'setq, 'rl_bbl!*, {'cons, mkquote vn, 'rl_bbl!*}}, p);
      	    push({'put, mkquote name, ''number!-of!-args, n}, p);
      	    push({'de, name, args, {'apply, vn, 'list . args}}, p)
	 >>;
      return p
   end;

asserted procedure rl_sortAndProject(al: Alist): List;
   for each pr in sort(al, function(lambda(x, y); car x < car y)) collect
      cdr pr;

asserted procedure rl_docSynopsis(f: Id, names: List, types: List, defaults: Alist): String;
   begin scalar sl, name, default;
      push(id2string f, sl);
      push("(", sl);
      while types and car types neq "Switch" do <<
	 name := pop names;
	 push(id2string name, sl);
	 default := atsoc(name, defaults);
	 if default then <<
	    push(" = ", sl);
	    if stringp cdr default then <<
	       push("""", sl);
	       push(cdr default, sl);
	       push("""", sl)
	    >> else
	       push(ioto_smaprin cdr default, sl)
	 >>;
	 push(": ", sl);
	 push(pop types, sl);
	 if types then
	    push(", ", sl)
      >>;
      if types then
	 push("...", sl);
      push(")", sl);
      return lto_sconcat reversip sl
   end;

asserted procedure rl_docArguments(names: List, types: List, docs: List): Alist;
   begin scalar sl;
      while types and car types neq "Switch" do <<
	 pop types;
	 push(id2string pop names . pop docs, sl)
      >>;
      return reversip sl
   end;

asserted procedure rl_docSwitches(names: List, types: List, docs: List): Alist;
   begin scalar sl;
      while types and car types neq "Switch" do <<
	 pop types;
	 pop names;
	 pop docs
      >>;
      while names do
	 push(id2string pop names . pop docs, sl);
      return sl
   end;

asserted procedure rl_servicewrapper(rl_!*b: Applicable, u: List, names: List, types: List, defaults: Alist, rtype: Any, rl_b!*: Id, rlb: Id): Any;
   % [rl_bname] is the SM entry point of the service called. [args] are the
   % passed arguments; [names] are the names of the specified arguments, [types]
   % are their types, and defaults are their default values. [rtype] is the type
   % of the return value of [rl_bname].
   begin scalar g, rargs, nargs, w, name, type, f; integer argc, pos;
      if null eval rl_b!* then
	 rederr {"service", rlb, "not available in current context", rl_cid!*};
      % Construct a list [rlist] to be filled in-place with the parameters
      % determined throughout this procedure. Switches are inintialized with
      % themselves, because the default is to use the global switch setting. All
      % other parameters are initialized with a safe placeholder.
      argc := length names;
      g := gensym();
      for i := 1:argc do push(g,rargs);
      % We follow the Python convention that positional parameters have priority
      % over named parameters. In a first pass we fill positional parameters
      % into [rargs] and save named parameters in an Alist [nargs].
      for each arg in u do <<
	 pos := pos + 1;
	 % For named parameters we admit both '=>' (replaceby) and '=' equal.
	 % However, '=' can lead to ambiguities, when the "equations" occurs at
	 % a position where it would make sense as a positional parameter (e.g.
	 % a formula). In such cases we decide in favor of the positional
	 % argument. We expect such situations to be rare. Users would use
	 % variables names in single equations that do not clash with parameter
	 % names, or just use '=>' in such cases. Relevant types are explicitly
	 % flagged [equational].
	 if eqcar(arg, 'replaceby) or
 	    eqcar(arg, 'equal) and not flagp(nth(types, pos), 'equational)
	 then
	    push(cadr arg . caddr arg, nargs)
	 else
	    nth(rargs, pos) := arg
      >>;
      % Second pass: Fill the gaps in [rargs] with named parameters while
      % makeing sure the following:
      % 1. Accept no clashes. In particular, named parameters must not clash
      %    with previously determined positional parameters.
      % 2. Accept no named parameter with an unknown name.
      for each arg in nargs do <<
	 w := memq(car arg, names);
	 if not w then
	    rederr {"unknown named parameter", car arg};
	 % Determine the position from the name, and check whether that spot is
	 % stil free.
	 pos := argc - length w + 1;
	 if nth(rargs, pos) neq g then
	    rederr {"ambiguous specification for parameter", car arg};
	 % If so, fill it in-place.
	 nth(rargs, pos) := cdr arg
      >>;
      % Third pass: In the end every formal parameter must be filled with
      % default values and those default values must exist. We do this also
      % in-place.
      pos := 0;
      for each arg on rargs do <<
	 pos := pos + 1;
	 if car arg eq g then <<
	    name := nth(names, pos);
	    w := atsoc(name, defaults);
	    if not w then
	       rederr {"missing parameter", name, "at position", pos};
	    car arg := cdr w
      	 >>
      >>;
      % Now [rargs] is a complete list of arguments in the correct order, which
      % still have to be evaluated/converted.
      rargs := for each arg in rargs collect
	 rl_convertArg(arg, pop types, 'a2s);
      % Finally apply the service, evaluate the result for AM, and return.
      w := apply(rl_!*b, rargs);
      if rl_excP w then  % handle exceptions
	 rl_excErr w;
      w := rl_convertArg(w, rtype, 's2a);
      return w
   end;

asserted procedure rl_convertArg(x: Any, type: Any, x2y: Id): Any;
   apply(rl_conversionFunction(type, x2y), {x});

asserted procedure rl_conversionFunction(type: Any, x2y: Id): Any;
   begin scalar type, super, f, fl, kwl;
      if idp type then <<
	 f := get(type, x2y);
	 if f then
	    return f;
	 super := get(type, 'inherits);
	 if super then
	    return rl_conversionFunction(super, x2y);
	 rederr {"missing", x2y, "conversion for type", type}
      >>;
      if intern car type eq 'enum and x2y eq 'a2s then <<
	 kwl := for each h in cdr type collect intern h;
      	 return {'lambda, '(x), {'apply, {'function, 'rl_a2sKeyword}, {'list, 'x, mkquote kwl}}};
      >>;
      % Now type is something like Pair(List(Atom), Formula), where Pair, List,
      % Atom, Formula have conversion functions of arity 1+2, 1+1, 1+0, 1+0,
      % resp., counting "data + parameter functions."
      f . fl := for each ty in type collect
 	 {'function, rl_conversionFunction(ty, x2y)};
      return {'lambda, '(x), {'apply, f, {'cons, 'x, 'list . fl}}}
   end;

asserted procedure rl_a2sKeyword(x: Any, keywords: List);
   if x memq keywords then
      x
   else
      typerr(x, ioto_smaprin('!One!Of . keywords)) where !*lower=nil, !*raise=nil;

put('enum, 'docal, {'syntax . "Admissible REDLOG KEYWORDS"});

% The following documents how to implement fancy printing of Enum types.
% However, with the current setup, it is necessary that the printed form can be
% parsed by xread for type conversion.
%
% asserted procedure rl_priEnum(s);
%    <<
%       prin2!* "[";
%       prin2!* cadr s;
%       for each x in cddr s do << prin2!* "|", prin2!* x >>;
%       prin2!* "]";
%       terpri!* nil
%    >>;
%
% put('!Enum, 'prifn, 'rl_priEnum);

asserted procedure rl_exc(x: Any): DottedPair;
   % Create an "exception" as a return value in case of unexpected situations,
   % e.g. inconsistent theories. Exceptions are recognized by
   % [rl_servicewrapper] in the AM/SM interface, where rl_excErr is called with
   % ['!*rl_exc!* . x]. SM Redlog code might explicitly checked for exceptions
   % using [rl_excP] and not necessarily throw an error, since some exceptions
   % can be managed.
   '!*rl_exc!* . x;

% Return values constructed with [rl_exc] should be ignored by the assert
% module. For Redlog it is recommended to specifiy, e.g., "Formula" as a return
% type of a function, which might use [rl_exc].
flag('(!*rl_exc!*), 'assert_ignore);

asserted procedure rl_excP(x: Any): Boolean;
   % Check is return value is an exception.
   eqcar(x, '!*rl_exc!*);

asserted procedure rl_excErr(exc: DottedPair);
   % Throw an error in case of exception.
   rederr cdr exc;

% The following is temporary, and when finally removing it the corresponding
% autoloads in support/entry.red must be removed, too. Note that using copyd
% here would not be compatible with autoloading.

asserted procedure rl_exception(x: Any): DottedPair;
   rl_exc x;

asserted procedure rl_exceptionp(x: Any): Boolean;
   rl_excp x;

endmodule;

end;
