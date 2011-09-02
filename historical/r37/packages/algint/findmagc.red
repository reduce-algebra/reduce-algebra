MODULE FINDMAGC;

% Author: James H. Davenport.

FLUID '(!*tra MAGICLIST);

SYMBOLIC PROCEDURE FINDMAGIC L;
BEGIN
  SCALAR P,N,PVEC,M,INTVEC,MCOUNT,TEMP;
  % L is a list of things which must be made non-zero by means of
%   a suitable choice of values for the variables in MAGICLIST;
  L:=FOR EACH U IN L COLLECT
     << MAPC(MAGICLIST,FUNCTION (LAMBDA V;
                                 IF INVOLVESF(DENR U,V)
				   THEN INTERR "Hard findmagic"));
        NUMR U >>;
  IF !*TRA THEN <<
    PRINTC "We must make the following non-zero:";
    MAPC(L,FUNCTION PRINTSF);
    PRINC "by suitable choice of ";
    PRINTC MAGICLIST >>;
  % Strategy is random choice in a space which has only finitely
%   many singular points;
  P:=0;
  N:=ISUB1 LENGTH MAGICLIST;
  PVEC:=MKVECT N;
  PUTV(PVEC,0,2);
  FOR I:=1:N DO
    PUTV(PVEC,I,NEXTPRIME GETV(PVEC,ISUB1 I));
  % Tactics are based on Godel (is this a mistake ??) and let P run
%   through numbers and take the prime factorization of them;
  INTVEC:=MKVECT N;
LOOP:
  P:=IADD1 P;
  IF !*TRA THEN <<
    PRINC "We try the number ";
    PRINTC P >>;
  M:=P;
  FOR I:=0:N DO <<
    MCOUNT:=0;
    WHILE CDR(TEMP:=DIVIDE(M,GETV(PVEC,I)))=0 DO <<
      MCOUNT:=IADD1 MCOUNT;
      M:=CAR TEMP >>;
    PUTV(INTVEC,I,MCOUNT) >>;
  IF M NEQ 1
    THEN GO TO LOOP;
  IF !*TRA THEN <<
    PRINTC "which corresponds to ";
    SUPERPRINT INTVEC >>;
  M:=NIL;
  TEMP:=MAGICLIST;
  FOR I:=0:N DO <<
    M:=((CAR TEMP).GETV(INTVEC,I)).M;
    TEMP:=CDR TEMP >>;
  % M is the list of substitutions corresponding to this value of P;
  TEMP:=L;
LOOP2:
  IF NULL NUMR algint!-SUBF(CAR TEMP,M)
    THEN GO TO LOOP;
  TEMP:=CDR TEMP;
  IF TEMP
    THEN GO TO LOOP2;
  IF !*TRA THEN <<
    PRINTC "which corresponds to the values:";
    SUPERPRINT M >>;
  RETURN M
  END;

ENDMODULE;

END;
