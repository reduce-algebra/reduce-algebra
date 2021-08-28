module rlbuiltin;

revision('rlbuiltin, "$Id$");

copyright('rlbuiltin, "(c) 2020 T. Sturm");

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
global '(rl_builtins!*);

put('rl_builtin, 'stat, 'rl_builtinStat);

asserted procedure rl_builtinStat();
   begin scalar l, key, entry;
      rl_skiplcbkt "rl_builtin";
      scan();
      while cursym!* neq '!*rcbkt!* do <<
         if not idp cursym!* then
            rederr {"expecting identifier in rl_builtin but found", cursym!*};
         key := cursym!*;
         rl_skipequal "rl_builtin";
         if key eq 'doc then
            entry := rl_builtinStatDoc()
         else if key memq '(name) then <<
            % The entry must be an atom now:
            scan();
            if not atom cursym!* then
               rederr {"expecting atom in rl_builtin but found", cursym!*};
            entry := cursym!*;
            scan()
         >> else
            rederr {"unknown keyword", key, "in rl_builtin"};
         push(key . entry, l);
         % Expecting ',' or '}' now:
         if cursym!* neq '!*rcbkt!* then <<
            if cursym!* neq '!*comma!* then
               rederr {"expecting ',' or '}' in rl_builtin but found", cursym!*};
            scan()
         >>
      >>;
      scan();  % !*semicol!*
      return {'rl_builtin, reversip l}
   end;

asserted procedure rl_builtinStatDoc();
   begin scalar key, entry, l;
      rl_skiplcbkt "rl_builtin doc";
      scan();
      while cursym!* neq '!*rcbkt!* do <<
         if not idp cursym!* then
            rederr {"expecting identifier in rl_builtin doc but found", cursym!*};
         key := cursym!*;
         if key memq '(description returns) then <<
            rl_skipequal("rl_builtin");
            scan();
            if not stringp cursym!* then
               rederr {"expecting a string in rl_builtin doc but found", cursym!*};
            entry := cursym!*;
            scan()
         >> else if key memq '(synopsis arg) then <<
            rl_skipequal "rl_builtin doc arguments";
            rl_skiplcbkt "rl_builtin doc arguments";
            entry := rl_serviceStatList();
            scan()
         >> else if key memq '(seealso) then <<
            rl_skipequal("rl_builtin");
            scan();
            if not idp cursym!* then
               rederr {"expecting an identifier in rl_builtin doc but found", cursym!*};
            entry := cursym!*;
            scan()
         >> else
            rederr {"unknown keyword", key, "in rl_builtin doc"};
         push(key . entry, l);
         % Expecting ',' or '}' now:
         if cursym!* neq '!*rcbkt!* then <<
            if cursym!* neq '!*comma!* then
               rederr {"expecting ',' or '}' in rl_builtin doc but found", cursym!*};
            scan()
         >>
      >>;
      scan();
      return reversip l
   end;

put('rl_builtin, 'formfn, 'rl_formBuiltin);

asserted procedure rl_formBuiltin(argl: List, vars: List, mode: Id): List;
   begin scalar spec, name, doc, p, synal, description, returns, argal, seealsol, docal, rlbuiltin;
      spec := cadr argl;
      name := lto_eatsoc('name, spec, {"missing name in ", argl});
      doc := lto_eatsoc('doc, spec, {"missing doc in", argl});
      for each x in doc do
         if pairp x and car x eq 'synopsis then
            push(
               lto_eatsoc('pos, cdr x, {"missing pos in", x, "in", argl}) .
                  lto_eatsoc('text, cdr x, {"missing text in", x, "in", argl}),
               synal)
         else if pairp x and car x eq 'description then
            description := x
         else if pairp x and car x eq 'returns then
            returns := x
         else if pairp x and car x eq 'arg then
            push(
               lto_eatsoc('pos, cdr x, {"missing pos in", x, "in", argl}) .
                  (lto_eatsoc('name, cdr x, {"missing name in", x, "in", argl}) .
                     lto_eatsoc('text, cdr x, {"missing text in", x, "in", argl})),
               argal)
         else if pairp x and car x eq 'seealso then
            push(cdr x, seealsol)
         else if not eqcar(x, 'name) then
            rederr {"unknown keyword", car x, "in", argl};
      push('synopsis . reversip synal, docal);
      push(description, docal);
      push(returns, docal);
      push('arguments . reversip argal, docal);
      push('seealso . reversip seealsol, docal);
      push('doc . reversip docal, rlbuiltin);
      push({'setq, 'rl_builtins!*,
         {'cons, mkquote name, {'delete, mkquote name, 'rl_builtins!*}}}, p);
      push({'put, mkquote name, ''rl_support, ''rl_builtin}, p);
      push({'put, mkquote name, ''rl_builtin, mkquote rlbuiltin}, p);
      return 'progn . reversip p
   end;

asserted procedure rl_builtinP(x: Any): Boolean;
   idp x and get(x, 'rl_support) eq 'rl_builtin;

endmodule;

end;
