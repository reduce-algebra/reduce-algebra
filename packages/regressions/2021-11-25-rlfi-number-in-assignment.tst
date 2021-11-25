
%%  Problem reported by Tony Roberts on the reduce-algebra-developers mailing list:
%%
%%  With rlfi and on latex the input
%%
%%  z := 1;
%%
%%  causes an error (cdr of an atom).
%%
%%  The input
%%
%%  z := a;
%%
%%  does not.
%%
%%  Analysis: the change triggering the error is r5188:
%%
%%  Changed the package rlfi to use an outputhandler. This allows now to also turn on Latex output
%%  from within a procedure. It was necessary to make an adjustment to the outputhandler mechanism
%%  itself. For the assgnpri slot now all three arguments to assgnpri are passed on (as a list).
%%
%%  Further analysis shows that rlfi treats numbers specially. Any other expression is wrapped in 
%%
%%   (TeX expression)
%%
%%  but numbers are not. This causes the input z := 1 to be printed as
%%
%%   (setq z 1)
%%
%%  whereas z := a is printed as
%%
%%   (setq z (tex (!*sq ((((a . 1) . 1)) . 1) t)))
%%
%%  Therefore the former is printed a standard way, whereas for the latter the rlfi printing function is called.
%%  "The standard way" causes the error in the outputhandler. 
%%
%%  The internal workaround is to treat  "z := number" in the rlfi outputhandler as "(setq z (tex 1))", and 
%%  input of the form " x := y := 1; " as well.
%%

load_package rlfi;

on latex;

z := a;

z := (a+b)^2;

z := 1;

(a+b)^2;

1;

on verbatim;

z := a;

z := (a+b)^2;

z := 1;

(a+b)^2;

1;

off verbatim;
off latex;

end;


