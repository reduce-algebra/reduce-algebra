% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2016 T. Sturm
% ----------------------------------------------------------------------
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

module rlservice;
%
%   AM   |   SM
%        |
%  rlb --+-> rl_b!$
%        |   ---> rl_servicewrapper
%        |        ---> rl_!*b
%        |             ---> rl_b
%        |                  ---> apply(rl_b!*)
%

fluid '(rl_servl!*);

load!-package 'rltools;

put('rl_service, 'stat, 'rl_serviceStat);

asserted procedure rl_serviceStat();
   begin scalar w;
      scan();
      if cursym!* neq '!*lcbkt!* then
	 rederr {"expecting '{' in rl_service but found", cursym!*};
      w := rl_serviceStatList();
      scan();  % !*semicol!*
      return {'rl_service, w}
   end;

asserted procedure rl_serviceStatList(): List;
   % We hav just read '{'. Parse a list with entries of the form [name = entry].
   % [name] is an alphabetic identifier. For [entry], there are three
   % possibilities:
   % (a) An atom. This is our default assumption.
   % (b) Another list as the one that we are parsing. This is triggered by the
   %     entry starting with '{.'
   % (c) An expression to be parsed by xread in algebraic mode. This is
   %     triggered with by the [name] "default."
   %
   begin scalar l, key, entry;
      scan();
      while cursym!* neq '!*rcbkt!* do <<
	 % We are not on the right hand side of an equation. We need an
	 % alphabetic identifier. We strictly admit only alphabetic characters,
	 % no digits.
      	 if not lto_alphap cursym!* then
	    rederr {"expecting alphabetic key in rl_service but found", cursym!*};
      	 key := cursym!*;
	 % Now there must come '=':
	 scan();
      	 if cursym!* neq 'equal then
	    rederr {"expecting '=' in rl_service but found", cursym!*};
	 % Now the three cases discussed above:
	 if key eq 'default then
	    entry := xread t where !*mode = 'algebraic
	 else <<
	    scan();
	    if cursym!* eq '!*lcbkt!* then <<
	       entry := rl_serviceStatList()
	    >> else <<
      	       if not atom cursym!* then
	    	  rederr {"expecting atomic entry or list in rl_service but found", cursym!*};
      	       entry := cursym!*
	    >>;
	    scan()
	 >>;
	 push(key . entry, l);
	 % Expecting ',' or '}' now:
	 if cursym!* neq '!*rcbkt!* then <<
	    if cursym!* neq '!*comma!* then
	       rederr {"expecting ',' or '}' in rl_service but found", cursym!*};
	    scan()
	 >>
      >>;
      return reversip l
   end;

put('rl_service, 'formfn, 'rl_formService);

asserted procedure rl_formService(argl: List, vars: List, mode: Id): List;
   % Analyze the equational specifications of services, and generate
   % corresponding functions and bindings.
   % We do not evaluate within the specifications, but they are parsed by xread,
   % which has some issues:
   % 1. Although it appears very tempting, we cannot give default arguments
   %    in AM notiation, because xread parsing happens in SM. Note that in
   %    particular macros are expanded.
   % 2. Some keywords like "switch" must not occur within equations.
   begin
      scalar spec, rl, rl_, b, rl_b, rl_b!*, rl_b!$, rlb, rl_!*b, pos, name, p,
 	 names, type, types, default, defaults, rtype, fluids, mode, rl_args,
 	 rl_!*args;
      integer minswitch, maxother, maxall;
      spec := cadr argl;
      % Determine the base name of the service:
      b := lto_eatsoc('name, spec, {"missing service name in", argl});
      % Valid choices for mode are sm and both. We always build the SM
      % interface, because it is called by the AM interface:
      mode := lto_eatsoc('mode, spec, {"missing mode in", argl});
      if not (mode memq '(sm both)) then
	 rederr {"invalid mode", mode, "in", argl};
      % Determine arguments and their order. Construct corresponding lists of
      % formal paremeters:
      minswitch := length spec;  % initialize with upper bound on number of args
      for each pr in spec do
 	 if car pr eq 'arg then <<
	    name := lto_eatsoc('name, cdr pr,
 	       {"arg without name in service", b});
	    pos := lto_eatsoc('pos, cdr pr,
 	       {"arg", name, "without pos in service", b});
	    if assoc(pos, names) then
	       rederr {"pos", pos, "specified twice in service", b};
	    type := lto_eatsoc('type, cdr pr,
 	       {"arg", name, "without type in service", b});
	    if type eq 'Switch then <<
	       % Switchs are Redlog switches to be lambda-bound during the call.
	       % The argument name is without the leading "rl." Default is
	       % the corresponding (global) switch setting.
	       minswitch := min2(pos, minswitch);  % smallest Switch position
	       maxall := max2(pos, maxall);  % largest overall position
	       default := intern compress append(explode '!*rl, explode name);
	       push(default, fluids);
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
	    push(pos . type, types)
	 >> else if car pr eq 'returns then <<
	    % [rtype] might be not present at all, which means that the service
	    % does not return anything meaningful. On the other hand, if it is
	    % present, then we insist on a type.
	    rtype := lto_eatsoc('type, cdr pr,
 	       {"service", b, "without return type in"})
	 >>;
      % We insist that positions are numbered 1, ..., n without gaps:
      if not eqn(maxall, length names) then
	 rederr {"bad arg position numbering in service", b};
      % Switchs must come after all other arguments:
      if minswitch neq maxother + 1 then
	 rederr {"bad flag positions in service", b};
      % Argument names including Switchs in the right order:
      names := rl_sortAndProject names;
      % Types including Switchs in the right order:
      types := rl_sortAndProject types;
      % Argument names without Switchs in the right order:
      rl_args := rl_sortAndProject rl_args;
      % Non-Switch argument names followed by defaults for the Switchs, i.e.
      % !*rl<flag> instead of <flag>. This will be used within the body of
      % rl_!*<b>:
      rl_!*args := rl_sortAndProject rl_!*args;
      % An Alist mapping names (including Switchs) to default values:
      defaults := rl_sortAndProject defaults;
      % Determine from the name of this macro prefixes of procedures to be
      % generated as lists of identifiers. The reason for using the name of the
      % macro is that there is rl_ and sl_ around, where sl_ is an experiment,
      % which might be removed at some point:
      rl_ := reversip explode nth(argl, 1);
      while not eqcar(rl_, '!_) do
 	 rl_ := cdr rl_;
      % The AM prefix has no underscore:
      rl := reverse cdr rl_;
      rl_ := reversip rl_;
      rl_b := intern compress append(rl_, explode b);
      rl_!*b := intern compress append(rl_, append(explode '!*, explode b));
      if mode eq 'both then <<
	 % Build the AM interface: rl<b> is the AM entry point. It is a psopfn
	 % pointing to rl<b>!$:
      	 rlb := intern compress append(rl, explode b);
      	 rl_b!$ := intern compress nconc(explode rl_b, '(!! !$));
	 % We are going construct a progn in [p], which is going to be the
	 % result of this macro.
	 %
	 % rtypepart is the rtype of the part function. TS does not exactly
	 % understand anymore why this is used here. It might again have to do
	 % with rl vs. sl.
	 push({'put, mkquote rlb, ''rtypefn, ''rtypepart}, p);
	 push({'put, mkquote rlb, ''psopfn, mkquote rl_b!$}, p);
	 push({'put, mkquote rl_b!$, ''number!-of!-args, 1}, p);
	 push({'de, rl_b!$, '(u), {'rl_servicewrapper, mkquote rl_!*b, 'u,
 	    mkquote names, mkquote types, mkquote defaults, mkquote rtype}}, p)
      >>;
      % Build the SM interface: rl_<b> is the SM entry point. It applies the
      % function stored in a fluid rl_<b>!*. That function depends on the
      % current context. All those fluids are collected in in fluid list
      % rl_servl!*, where they are found and rebound with context swithes via
      % rl_set.
      rl_b!* := intern compress nconc(explode rl_b, '(!! !*));
      push({'fluid, mkquote fluids}, p);
      push({'put, mkquote rl_!*b, ''number!-of!-args, maxall}, p);
      push({'de, rl_!*b, rl_!*args, {'apply, mkquote rl_b, 'list . rl_args}}, p);
      push({'fluid, mkquote {rl_b!*}}, p);
      push({'setq, 'rl_servl!*, {'cons, mkquote rl_b!*, 'rl_servl!*}}, p);
      push({'put, mkquote rl_b, ''number!-of!-args, maxother}, p);
      push({'de, rl_b, rl_args, {'apply, rl_b!*, 'list . rl_args}}, p);
      return 'progn . reversip p
   end;

asserted procedure rl_sortAndProject(al: Alist): List;
   for each pr in sort(al, function(lambda(x, y); car x < car y)) collect
      cdr pr;

asserted procedure rl_servicewrapper(rl_!*b: Function, u: List, names: List, types: List, defaults: Alist, rtype: Id): Any;
   % [rl_bname] is the SM entry point of the service called. [args] are the
   % passed arguments; [names] are the names of the specified arguments, [types]
   % are their types, and defaults are their default values. [rtype] is the type
   % of the return value of [rl_bname].
   begin scalar g, rargs, nargs, w, name; integer argc, pos;
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
      % still have to be evaluated.
      rargs := for each arg in rargs collect
	 if fluidp arg then
	    eval arg
	 else
      	    apply(get(pop types, 'a2s), {arg});
      % Finally apply the service, evaluate the result for AM, and return.
      w := apply(rl_!*b, rargs);
      if rl_excP w then  % handle exceptions
	 rl_excErr w;
      w := apply(get(rtype, 's2a), {w});
      return w
   end;

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
% auoloads in support/entry.red must be removed, too. Note that using copyd here
% would not be compatible with autoloading.

asserted procedure rl_exception(x: Any): DottedPair;
   rl_exc x;

asserted procedure rl_exceptionp(x: Any): Boolean;
   rl_excp x;

endmodule;

end;
