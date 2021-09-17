module rltype;

revision('rltype, "$Id$");

copyright('rltype, "(c) 2016-2020 T. Sturm");

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

fluid '(mode!*);

put('rl_type, 'stat, 'rl_typeStat);

asserted procedure rl_typeStat();
   begin scalar l, key, entry;
      rl_skiplcbkt "rl_type";
      scan();
      while cursym!* neq '!*rcbkt!* do <<
         if not idp cursym!* then
            rederr {"expecting identifier in rl_type but found", cursym!*};
         key := cursym!*;
         scan();
         if cursym!* neq 'equal then
            % There is a flag, e.g., 'equational'
            push(key . t, l)
         else <<
            % There is a key-entry pair
            if key eq 'doc then
               entry := rl_typeStatDoc()
            else if key memq '(name inherits) then <<
               scan();
               if not idp cursym!* then
                  rederr {"expecting identifier in rl_type but found", cursym!*};
               entry := cursym!*;
               scan()
            >>
            else if key memq '(a2s s2a) then
               entry := xread t
            else
               rederr {"unknown keyword", key, "in rl_type"};
            push(key . entry, l);
         >>;
         % Expecting ',' or '}' now:
         if cursym!* neq '!*rcbkt!* then <<
            if cursym!* neq '!*comma!* then
               rederr {"expecting ',' or '}' in rl_type but found", cursym!*};
            scan()
         >>
      >>;
      scan();  % !*semicol!*
      return {'rl_type, reversip l}
   end;

asserted procedure rl_typeStatDoc();
   begin scalar key, entry, l;
      rl_skiplcbkt "rl_type doc";
      scan();
      while cursym!* neq '!*rcbkt!* do <<
         if not idp cursym!* then
            rederr {"expecting identifier in rl_type doc but found", cursym!*};
         key := cursym!*;
         if key memq '(description syntax semantics url example) then <<
            rl_skipequal("rl_type");
            scan();
            if not stringp cursym!* then
               rederr {"expecting a string in rl_type doc but found", cursym!*};
            entry := cursym!*;
            scan()
         >> else
            rederr {"unknown keyword", key, "in rl_type doc"};
         push(key . entry, l);
         % Expecting ',' or '}' now:
         if cursym!* neq '!*rcbkt!* then <<
            if cursym!* neq '!*comma!* then
               rederr {"expecting ',' or '}' in rl_type doc but found", cursym!*};
            scan()
         >>
      >>;
      scan();
      return reversip l
   end;

put('rl_type, 'formfn, 'rl_formType);

asserted procedure rl_formType(argl: List, vars: List, mode: Id): List;
   begin scalar spec, name, p, rltype;
      spec := cadr argl;
      name := lto_eatsoc('name, spec, {"missing type name in", argl});
      for each x in spec do
         if pairp x and car x memq '(a2s s2a doc inherits equational) then
            push(x, rltype)
         else if not eqcar(x, 'name) then
            rederr {"unknown keyword", car x , "in", argl};
      push({'put, mkquote name, ''rl_support, ''rl_type}, p);
      push({'put, mkquote name, ''rl_type, mkquote rltype}, p);
      return 'progn . reversip p
   end;

asserted procedure rl_typeP(x: Any): Boolean;
   idp x and get(x, 'rl_support) eq 'rl_type;

asserted procedure rl_typeEquationalP(type: Id): Boolean;
   begin scalar w;
      w := atsoc('equational, get(type, 'rl_type));
      return pairp w and cdr w
   end;

asserted procedure rl_typeA2s(type: Id): Applicable;
   rl_typeEntry(type, 'a2s);

asserted procedure rl_typeS2a(type: Id): Applicable;
   rl_typeEntry(type, 's2a);

asserted procedure rl_typeDoc(type: Id): Alist;
   rl_typeEntry(type, 'doc);

asserted procedure rl_typeInherits(type: Id): Id;
   rl_typeEntry(type, 'inherits);

asserted procedure rl_typeEntry(type: Id, entry: Id): Any;
   begin scalar w;
      w := atsoc(entry, get(type, 'rl_type));
      return if pairp w then cdr w
   end;

asserted procedure rl_typeArity(type: Id): Atom;
   begin scalar ar;
      ar :=  if type eq 'enum then
         'n
      else
         get(rl_typeA2s type or rl_typeS2a type, 'number!-of!-args) or '!?;
      if fixp ar then ar := ar - 1;
      return  ar
   end;

endmodule;

end;
