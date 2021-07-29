module int; % Header for REDUCE integration package.

% Authors: A. C. Norman and P. M. A. Moore.
% Modified by: J. Davenport, J. P. Fitch, A. C. Hearn.

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

% $Id: $

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

flag ('(atan dilog Ei erf expt log tan),'transcendental);

COMMENT Kludge to define derivative of an integral and integral of
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

symbolic procedure printc u; prin2t u;   % This could be an inline.


% Selector written as an inline.

inline procedure argof u;
   % Argument of a unary function.
   cadr u;

put('nthroot,'simpfn,'simpiden);
% The binary n-th root operator nthroot(x,2)=sqrt(x)
% no simplification is used here.
% Hope is that pbuild introduces it, and simplog removes it.

% Part of the integration code involves support for a distributed
% representation of expressions. These were originally implemented using
% the constructors ".*" and ".+" (as used with Standard Forms) because the
% meaning is rather similar. This overloading of those operators makes
% some code analysis harder, and so now I will be using distinct names
% for the constructors and accessors, as introduced here.

flag('(newtok infix), 'eval);

newtok '((!. !~ !*) int_mult);
newtok '((!. !~ !+) int_add);

infix .~*, .~+;
precedence .~+, .+;
precedence .~*, .*;

inline procedure a .~* b;
   a . b;

inline procedure a .~+ b;
   a . b;

accessors (int_lpow . int_lc) . int_red, int_lt . !_;

% I will probably really want to make the structure of an int_pow more
% visible and explicit here...

deflist('(
  (int_mult (arrow (times int_power sq) int_term))
  (int_add  (arrow (times int_term int_df) int_df))
  (int_pow  (arrow int_df int_power))
  (int_lc   (arrow int_df sq))
  (int_red  (arrow int_df int_df))
  ), 'procedure_type);

endmodule;

end;
