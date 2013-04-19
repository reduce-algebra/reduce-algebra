MODULE ABASIC;   % Basic definitions for algebraic function integrator.

% Author: James H. Davenport.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


% Modifications by: Anthony C. Hearn.

FLUID '(!*CONSCOUNT !*NOEXTEND);

GLOBAL '(INITL!* LIST!-OF!-MEDIUM!-PRIMES SQRTS!-MOD!-8);

INITL!* := APPEND('(!*NOEXTEND), INITL!*);

!*CONSCOUNT:=10000; % DEFAULT MAXIMUM NUMBER OF CONSES IN CERTAIN
                    % OPERATIONS;

LIST!-OF!-MEDIUM!-PRIMES:='(101 103 107 109);   % Used in MODLINEQ

SQRTS!-MOD!-8:=MKVECT 7;

PUTV(SQRTS!-MOD!-8,0,T);

PUTV(SQRTS!-MOD!-8,1,T);

PUTV(SQRTS!-MOD!-8,4,T);

PUT('NTHROOT,'SIMPFN,'SIMPIDEN);
% THE BINARY N-TH ROOT OPERATOR NTHROOT(X,2)=SQRT(X)
% NO SIMPLIFICATION IS USED HERE;
% HOPE IS THAT PBUILD INTRODUCES IT, AND SIMPLOG REMOVES IT;

symbolic inline procedure !*KK2Q A; ((MKSP(A,1) .* 1) .+ NIL) ./ 1;

symbolic inline procedure DIVSF(U,V); SQRT2TOP(U ./ V);

SYMBOLIC PROCEDURE INT!-SQRT U;
   % Integer square root function;
   BEGIN SCALAR X,Y;
      X := SQRT U;
      IF FIXP X THEN RETURN X
       ELSE IF X = FLOAT(Y := FIX X) THEN RETURN Y ELSE RETURN X
   END;

symbolic inline procedure MANINP(U,V,W);
   INTERR "MANINP called -- not implemented";


% SELECTORS FOR THE TAYLOR STRUCTURE:

% ***STORE-HACK-1***;
% REMOVE THIS MACRO IF MORE STORE IS AVAILABLE;

symbolic inline procedure TAYSHORTEN U;NIL;

symbolic inline procedure TAYLORDEFN U; CAR U;

symbolic inline procedure TAYLORNUMBERS U; CADR U;

symbolic inline procedure TAYLORFIRST U; CAADR U;

symbolic inline procedure TAYLORLAST U; CDADR U;

symbolic inline procedure TAYLORLIST U; CDDR U;

%FUNCTION.((FIRST.LAST COMPUTED SO FAR)
%       .ASSOC LIST OF COMPUTED TERMS);

symbolic inline procedure TAYLORMAKE(FN,NUMS,ALIST); FN.(NUMS.ALIST);

ENDMODULE;

END;

