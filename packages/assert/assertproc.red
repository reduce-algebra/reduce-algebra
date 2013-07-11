% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2012 Thomas Sturm
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

lisp <<
   fluid '(assertproc_rcsid!* assertproc_copyright!*);
   assertproc_rcsid!* := "$Id$";
   assertproc_copyright!* := "(c) 2012 T. Sturm"
>>;

module assertproc;

procedure assert_procstat();
   begin scalar fname, w, body;
      scan();
      if cursym!* neq 'procedure then
	 assert_rederr {"expecting keyword procedure but found", cursym!*};
      scan();
      fname := cursym!*;
      if not idp cursym!* then
	 assert_rederr {"expecting procedure name but found", cursym!*};
      scan();
      if cursym!* neq '!*lpar!* then
	 assert_rederr {"expecting '(' but found", cursym!*};
      scan();
      w := assert_procstat!-argl();
      scan();
      if cursym!* neq '!*semicol!* then
	 assert_rederr {"expecting ';' but found", cursym!*};
      body := xread t;
      return  {'assert_procedure, fname, w, body}
   end;

procedure assert_procstat!-argl();
   begin scalar var, type, w, argtypel;
      while cursym!* neq '!*rpar!* do <<
      	 eolcheck();
	 if not idp cursym!* then
	    assert_rederr {"Expecting identifier but found", cursym!*};
	 var := cursym!*;
	 scan();
	 type := if cursym!* eq '!*colon!* then <<
	    scan();
	    if not assert_typesyntaxp cursym!* then
	       assert_rederr {"Expecting type but found", cursym!*};
	    w := cursym!*;
	    scan();
	    w
	 >>;
	 argtypel := (var . type) . argtypel;
	 if not memq(cursym!*, '(!*comma!* !*rpar!*)) then
	    assert_rederr {"Expecting ',' or ')' but found", cursym!*};
	 if cursym!* eq '!*comma!* then
	    scan();
      >>;
      type := if nxtsym!* eq '!*colon!* or nxtsym!* eq '!: then <<
 	 scan();
	 scan();
	 if not assert_typesyntaxp cursym!* then
	    assert_rederr {"Expecting type but found", cursym!*};
 	 cursym!*
      >>;
      argtypel := ('returnvalue . type) . argtypel;
      argtypel := reversip argtypel;
      return argtypel
   end;

procedure assert_typesyntaxp(s);
   if !*assert then assert_dyntypep s else idp s;

procedure assert_formproc(u, vars, mode);
   begin scalar fname, targl, body, argl, atypel, rtype, fpc, assrt;
      if mode neq 'symbolic then
	 rederr {"asserted procedures are available in symbolic mode only"};
      fname := cadr u;
      targl := caddr u;
      body := cadddr u;
      targl := reverse targl;
      rtype := cdr car targl;
      targl := cdr targl;
      for each pr in targl do <<
	 argl := car pr . argl;
	 atypel := cdr pr . atypel
      >>;
      fpc := formproc({'procedure, fname, nil, 'expr, argl, body}, vars, mode);
      if not !*assert then
	 return fpc;
      assrt := assert_declarestat1 {fname, atypel, rtype};
      return {'progn, fpc, assrt}
   end;

procedure assert_rederr(l);
   << while cursym!* neq '!*semicol!* do scan(); xread t; rederr l >>;

put('asserted, 'stat, 'assert_procstat);
put('assert_procedure, 'formfn, 'assert_formproc);

endmodule;

end;  % of file
