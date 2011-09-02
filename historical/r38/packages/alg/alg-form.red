module alg!-form;   % Some particular algebraic mode analysis functions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 RAND.  All rights reserved.

global '(inputbuflis!* resultbuflis!* ws);

symbolic procedure forminput(u,vars,mode);
   begin scalar x;
      u := cadr u; if eqcar(u,'!:int!:) then u := cadr u;
      if null(x := assoc(u,inputbuflis!*))
        then rerror(alg,1,list("Entry",u,"not found"));
      return caddr x
   end;

put('input,'formfn,'forminput);

symbolic procedure formws(u,vars,mode);
   begin scalar x;
      u := cadr u; if eqcar(u,'!:int!:) then u := cadr u;
      if x := assoc(u,resultbuflis!*) then return mkquote cdr x
       else rerror(alg,2,list("Entry",u,"not found"))
   end;

put('ws,'formfn,'formws);

endmodule;

end;
