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

module rltype;

put('rl_type, 'stat, 'rl_typeStat);

asserted procedure rl_typeStat();
   begin scalar l, key, entry;
      scan();
      if cursym!* neq '!*lcbkt!* then
	 rederr {"expecting '{' in rl_type but found", cursym!*};
      scan();
      while cursym!* neq '!*rcbkt!* do <<
      	 if not idp cursym!* then
	    rederr {"expecting identifier in rl_type but found", cursym!*};
      	 key := cursym!*;
	 % Now there must come '=':
	 scan();
      	 if cursym!* neq 'equal then
	    push(key, l)
	 else <<
	    % The entry may be an atom for now:
	    scan();
      	    if not atom cursym!* then
	       rederr {"expecting atom in rl_type but found", cursym!*};
      	    entry := cursym!*;
	    push(key . entry, l);
	    scan()
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

put('rl_type, 'formfn, 'rl_formType);

asserted procedure rl_formType(argl: List, vars: List, mode: Id): List;
   begin scalar spec, name, p;
      spec := cadr argl;
      name := lto_eatsoc('name, spec, {"missing type name in", argl});
      for each x in spec do
	 if idp x and x memq '(equational) then
	    push({'flag, mkquote {name}, mkquote x}, p)
	 else if pairp x and car x memq '(a2s s2a) then
	    push({'put, mkquote name, mkquote car x, mkquote cdr x}, p)
	 else if not eqcar(x, 'name) then
	    rederr {"unknown keyword", x , "with type", name};
      return 'progn . reversip p
   end;

endmodule;

end;
