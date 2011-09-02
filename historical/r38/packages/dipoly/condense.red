module condense;  % unify exponent vectors for lower memory consumption.

% Author: Herbert Melenk

dipevlist!*:={nil};

symbolic procedure dipcondense f;
 begin scalar dl,ev;
  dl:=dipevlist!*;
  while f do
  <<ev := dipevlmon f; 
    while cdr dl and evcompless!?(dipevlmon f,cadr dl) do dl:=cdr dl;
    if cdr dl and ev=cadr dl 
      then car f := cadr dl
      else cdr dl:= ev.cdr dl; 
    f:=dipmred f >> end;

endmodule;;end;
