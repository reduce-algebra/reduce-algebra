MODULE JHDDIFF;

% Author: James H. Davenport.

% Differentiation routines for algebraic expressions;
SYMBOLIC PROCEDURE !*DIFFSQ(U,V);
   %U is a standard quotient, V a kernel.
   %Value is the standard quotient derivative of U wrt V.
   %Algorithm: df(x/y,z)= (x'-(x/y)*y')/y;
   !*MULTSQ(!*ADDSQ(!*DIFFF(NUMR U,V),
		    NEGSQ !*MULTSQ(U,!*DIFFF(DENR U,V))),
          1 ./ DENR U);

SYMBOLIC PROCEDURE !*DIFFF(U,V);
   %U is a standard form, V a kernel.
   %Value is the standard quotient derivative of U wrt V;
   IF DOMAINP U THEN NIL ./ 1
    ELSE !*ADDSQ(!*ADDSQ(MULTPQ(LPOW U,!*DIFFF(LC U,V)),
			!*MULTSQ(LC U ./ 1,!*DIFFP(LPOW U,V))),
	       !*DIFFF(RED U,V));

SYMBOLIC PROCEDURE !*DIFFP(U,V);
%  Special treatment of SQRT's (JHD is not sure why,
%  but it seems to be necessary);
IF ATOM (CAR U) THEN DIFFP(U,V)
  ELSE IF NOT(CAAR U EQ 'SQRT) THEN DIFFP(U,V)
    ELSE BEGIN
           SCALAR W,DW;
           W:=SIMP ARGOF CAR U;
	   DW:= !*DIFFSQ(W,V);
           IF NULL NUMR DW THEN RETURN DW;
	   RETURN !*MULTSQ(!*MULTSQ(DW,INVSQ W),
			   !*MULTF(CDR U,MKSP(CAR U,1) .* 1 .+ NIL)./ 2)
           END;

ENDMODULE;

END;
