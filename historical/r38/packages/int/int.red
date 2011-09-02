module int; % Header for REDUCE integration package.

% Authors: A. C. Norman and P. M. A. Moore.
% Modified by: J. Davenport, J. P. Fitch, A. C. Hearn.

% Note that at one point, INT had been flagged SIMP0FN.  However, that
% lead to problems when the arguments of INT contained pattern
% variables.

create!-package('(int contents csolve idepend df2q distrib divide driver
		  symint intfac ibasics makevars jpatches reform
                  simpsqrt hacksqrt sqrtf isolve tidysqrt trcase
		  halfangl trialdiv vect dint),   % simplog
		  % cuberoot d3d4 factr kron lowdeg unifac uniform tdiff
		'(int trans));

fluid '(!*noextend !*pvar frlis!* gaussiani);

global '(gensymcount initl!*);

!*pvar:='!_a;

gaussiani := !*kk2f '(sqrt -1);

gensymcount := 0;

initl!* := append('(!*noextend), initl!*);

flag('(interr),'transfer);   %For the compiler;

flag ('(atan dilog ei erf expt log tan),'transcendental);

comment Kludge to define derivative of an integral and integral of
        a derivative;

frlis!* := union('(!=x !=y),frlis!*);

put('df,'opmtch,'(((int !=y !=x) !=x) (nil . t)
                  (evl!* !=y) nil) . get('df,'opmtch));

put('int,'opmtch,'(((df !=y !=x) !=x) (nil . t)
                  (evl!* !=y) nil) . get('int,'opmtch));

put('evl!*,'opmtch,'(((!=x) (nil . t) !=x nil)));

put('evl!*,'simpfn,'simpiden);


% Various functions used throughout the integrator.

symbolic procedure flatten u;
   if null u then nil
    else if atom u then list u
    else if atom car u then car u . flatten cdr u
    else nconc(flatten car u,flatten cdr u);

symbolic procedure int!-gensym1 u;
   <<gensymcount:=gensymcount+1;
     compress append(explode '!!,
                     append(explode u,explode gensymcount))>>;

symbolic procedure mknill n; if n=0 then nil else nil . mknill(n-1);

symbolic procedure printc u; prin2t u;   % This could be an smacro.


% Selector written as an smacro.

smacro procedure argof u;
   % Argument of a unary function.
   cadr u;

put('nthroot,'simpfn,'simpiden);
% The binary n-th root operator nthroot(x,2)=sqrt(x)
% no simplification is used here.
% Hope is that pbuild introduces it, and simplog removes it.

endmodule;

end;
