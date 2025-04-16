lisp;
on comp, echo;
load_package compiler;
in "$PC/bytecode.red";

123+456;

bytecoded eek a;
   (eek here is some stuff)
   (loadlit2 !:exitlabel exit jumpt_b exitlabel);

eek 22;
jit!-eek 22;
jit!-eek 22;
jit!-eek 22;


end;




