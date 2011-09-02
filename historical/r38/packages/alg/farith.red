module farith;  % Operators for fast arithmetic.

% Authors: A. C. Norman and P. M. A. Moore, 1981.

symbolic procedure iplus2(u,v); u+v;

symbolic procedure itimes2(u,v); u*v;

symbolic procedure isub1 a; a-1;

symbolic procedure iadd1 a; a+1;

remprop('iminus,'infix);

symbolic procedure iminus a; -a;

symbolic procedure idifference(a,b); a-b;

symbolic procedure iquotient(a,b); a/b;

symbolic procedure iremainder(a,b); remainder(a,b);

symbolic procedure igreaterp(a,b); a>b;

symbolic procedure ilessp(a,b); a<b;

symbolic procedure iminusp a; a<0;

symbolic smacro procedure iequal(u,v); eqn(u,v);

newtok '((!#) hash);
newtok '((!# !+) iplus2);
newtok '((!# !-) idifference);
newtok '((!# !*) itimes2);
newtok '((!# !/) iquotient);
newtok '((!# !>) igreaterp);
newtok '((!# !<) ilessp);
newtok '((!# !=) iequal);

infix #+,#-,#*,#/,#>,#<,#=;

precedence #+,+;
precedence #-,-;
precedence #*,*;
precedence #/,/;
precedence #>,>;
precedence #<,<;
precedence #=,=;

deflist('((idifference iminus)),'unary);

deflist('((iminus iminus)),'unary);

deflist('((iminus iplus2)), 'alt);

endmodule;

end;
