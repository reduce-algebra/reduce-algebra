MODULE IDEPEND;  % Routines for considering dependency among variables.

% Authors: Mary Ann Moore and Arthur C. Norman.

FLUID '(TAYLORVARIABLE);

EXPORTS DEPENDSPL,DEPENDSP,INVOLVESQ,INVOLVSF;

IMPORTS DOMAINP;

SYMBOLIC PROCEDURE DEPENDSP(X,V);
   IF NULL V THEN T
    ELSE IF DEPENDS(X,V) THEN X
    ELSE IF ATOM X THEN IF X EQ V THEN X ELSE NIL
    ELSE IF CAR X = '!*SQ THEN INVOLVESQ(CADR X,V)
    ELSE IF TAYLORP X
     THEN IF V EQ TAYLORVARIABLE THEN TAYLORVARIABLE ELSE NIL
    ELSE BEGIN SCALAR W;
       IF X=V THEN RETURN V;
       % Check if a prefix form expression depends on the variable v.
       % Note this assumes the form x is in normal prefix notation;
       W := X; % preserve the dependency;
       X := CDR X; % ready to recursively check arguments;
 SCAN: IF NULL X THEN RETURN NIL; % no dependency found;
       IF DEPENDSP(CAR X,V) THEN RETURN W;
       X:=CDR X;
       GO TO SCAN
    END;

SYMBOLIC PROCEDURE INVOLVESQ(SQ,TERM);
   INVOLVESF(NUMR SQ,TERM) OR INVOLVESF(DENR SQ,TERM);
  
SYMBOLIC PROCEDURE INVOLVESF(SF,TERM);
   IF DOMAINP SF OR NULL SF THEN NIL
    ELSE DEPENDSP(MVAR SF,TERM)
       OR INVOLVESF(LC SF,TERM)
       OR INVOLVESF(RED SF,TERM);

SYMBOLIC PROCEDURE DEPENDSPL(DEP!-LIST,VAR);
   % True if any member of deplist (a list of prefix forms) depends on
   % var.
   DEP!-LIST
      AND (DEPENDSP(CAR DEP!-LIST,VAR) OR DEPENDSPL(CDR DEP!-LIST,VAR));

SYMBOLIC SMACRO PROCEDURE TAYLORFUNCTION U; CAAR U;

SYMBOLIC PROCEDURE TAYLORP EXXPR;
   % Sees if a random entity is a taylor expression.
   NOT ATOM EXXPR
       AND NOT ATOM CAR EXXPR
       AND FLAGP(TAYLORFUNCTION EXXPR,'TAYLOR);

ENDMODULE;

END;
