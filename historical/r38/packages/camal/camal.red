module camal;  % Package for calculations in celestial mechanics.

% Author: John P. Fitch <jpff@maths.bath.ac.uk>

create!-package('(camal fourdom fourplus makefour hsub hdiff),
		'(contrib camal));

%% This section is to define macros and simple functions to handle the
%% data structures for harmonic forms.
%% The structure is a vector:
%% Coeff | FN | Angle | Next
%
%% This version only allows 8 angles.  Consider extending this later.

switch fourier;

%% A vector and counter to record link between angle names and index

global '(next!-angle!* fourier!-name!*);
next!-angle!* := 0;
if vectorp fourier!-name!* then <<
	for i :=0:7 do remprop(getv(fourier!-name!*, i),'fourier!-angle)
>>;
fourier!-name!* := mkvect 7;

%% For non Cambridge LISP add 
smacro procedure putv!.unsafe(x,y,z); putv(x,y,z);
smacro procedure getv!.unsafe(x,y); getv(x,y);

%% Data abtraction says that we should define macros for access to 
%% the parts of the Fourier structure

smacro procedure fs!:set!-next(f,p); putv!.unsafe(f, 3, p);

smacro procedure fs!:next(f); getv!.unsafe(f,3);

smacro procedure fs!:set!-coeff(f,p); putv!.unsafe(f, 0, p);

smacro procedure fs!:coeff(f); getv!.unsafe(f, 0);

smacro procedure fs!:set!-fn(f,p); putv!.unsafe(f, 1, p);

smacro procedure fs!:fn(f); getv!.unsafe(f, 1);

smacro procedure fs!:set!-angle(f,p); putv!.unsafe(f, 2, p);

smacro procedure fs!:angle(f); getv!.unsafe(f, 2);

%% Some support functions for angle expressions

symbolic procedure fs!:make!-nullangle();
begin scalar ans;
    ans := mkvect 7;
    for i:=0:7 do putv!.unsafe(ans,i,0);
    return ans;
end;

symbolic procedure fs!:null!-angle!: u;
  fs!:null!-angle cdr u;

symbolic procedure fs!:null!-angle u;
begin scalar ans, i, x;
    x := fs!:angle u;
    ans := t;
    i := 0;
top:
    if not(getv!.unsafe(x,i)=0) then return nil;
    i := i+1;
    if (i<8) then go to top;
    return ans;
end;

endmodule;

end;
