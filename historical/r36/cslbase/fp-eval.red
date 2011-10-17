
deflist('(
    (RETURN        32)
    (PLUS          33)
    (DIFFERENCE    34)
    (TIMES         35)
    (QUOTIENT      36)
    (MINUS         37)
    (SQUARE        38)
    (CUBE          39)
    (SIN           40)
    (COS           41)
    (TAN           42)
    (EXP           43)
    (LOG           44)
    (SQRT          45)), 'fp!-eval);

symbolic procedure make!-fp!-eval(exprn, vars);
  if numberp exprn then 
  