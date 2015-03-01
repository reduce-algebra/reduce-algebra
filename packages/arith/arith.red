module arith;  % Header module for real arith package.

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


% Last updated Dec 14, 1992

% Assumptions being made on the underlying arithmetic:
%
% (1) The integer arithmetic is binary.
%
% (2) It is possible to convert any lisp float into an integer
%     by applying fix, and this yields the result with the full
%     precision of the float.
%


create!-package('(arith smlbflot bfauxil paraset math rounded comprd
                  rdelem crelem bfelem), nil);

flag('(arith),'core_package);

exports ashift, bfloat, bfminusp, bfnzp, bfp!:, bfzp, crim, crrl,
        divbf, ep!:, gfzerop, i2bf!:, lshift, make!:cr, make!:ibf,
        make!:rd, msd!:, mt!:, oddintp, preci!:, rdp, retag, rndpwr,
        sgn, tagrl, tagim, timbf;

imports eqcar, round!:mt;

fluid '(!*noconvert !:bprec!: dmode!*);

switch noconvert;

symbolic inline procedure mt!: u;
   % This function selects the mantissa of U, a binary bigfloat
   % representation of a number.
   cadr u;

symbolic inline procedure ep!: u;
   % This function selects the exponent of U, a binary bigfloat
   % representation of a number.
   cddr u;

symbolic procedure make!:ibf (mt, ep);
   '!:rd!: . (mt . ep);

symbolic inline procedure i2bf!: u; make!:ibf (u, 0);

symbolic inline procedure make!:rd u;
   '!:rd!: . u;

symbolic inline procedure rdp x;
   % This function returns true if X is a rounded number
   % representation, else NIL.  X is any Lisp entity.
   eqcar(x,'!:rd!:);

symbolic inline procedure float!-bfp x; atom cdr x;

symbolic inline procedure rd2fl x; cdr x;

symbolic inline procedure fl2rd x; make!:rd x;

symbolic inline procedure bfp!:(x);
   % This function returns true if X is a binary bigfloat
   % representation, else NIL.  X is any Lisp entity.
   rdp x and not float!-bfp x;

symbolic inline procedure retag u;
   if atom u then u else '!:rd!: . u;

symbolic inline procedure rndpwr j; normbf round!:mt(j,!:bprec!:);

symbolic procedure msd!: m;
  % returns the position n of the most significant (binary) digit
  % of a positive binary integer m, i.e. floor(log2 m) + 1
  begin integer i,j,k;
    j := m;
    while (j := ((k := j) / 65536)) neq 0 do i := i + 16;
    j := k;
    while (j := ((k := j) / 256)) neq 0 do i := i + 8;
    j := k;
    while (j := ((k := j) / 16)) neq 0 do i := i + 4;
    j := k;
    while (j := ((k := j) / 2)) neq 0 do i := i + 1;
    return (i + 1);
  end;

% For both PSL and CSL this is a built-in, so making it inline here is not
% useful and at one time it cause me pain.

symbolic procedure ashift(m,d);
   % This procedure resembles loosely an arithmetic shift.
   %  It returns m*2**d
   if d=0 then m
    else if d<0 then m/2**(-d)
    else m*2**d;

symbolic inline procedure lshift(m,d);
   % Variant of ashift that is called ONLY when m>=0.
   %  This should be redefined for Lisp systems that provide
   %  an efficient logical shift.
   ashift(m,d);

symbolic inline procedure oddintp n; not evenp n;

symbolic inline procedure preci!: nmbr;
   % This function counts the precision of a number "n". NMBR is a
   % binary bigfloat representation of "n".
   msd!: abs mt!: nmbr;


symbolic inline procedure divbf(u,v); normbf divide!:(u,v,!:bprec!:);

symbolic inline procedure timbf(u,v); rndpwr times!:(u,v);

symbolic inline procedure bfminusp u;
  if atom u then minusp u else minusp!: u;

symbolic inline procedure bfzp u;
  if atom u then zerop u else mt!: u=0;

symbolic inline procedure bfnzp u; not bfzp u;

symbolic inline procedure bfloat x;
  if floatp x then fl2bf x
   else normbf(if not atom x then x
                else if fixp x then i2bf!: x
                else read!:num x);

symbolic inline procedure rdfl2rdbf x; fl2bf rd2fl x;

symbolic inline procedure rd!:forcebf x;
   % forces rounded number x to binary bigfloat representation
   if float!-bfp x then rdfl2rdbf x else x;

symbolic inline procedure crrl x; cadr x;

symbolic inline procedure crim x; cddr x;

symbolic inline procedure make!:cr (re,im);
   '!:cr!: . (re . im);

symbolic inline procedure crp x;
   % This function returns true if X is a complex rounded number
   % representation, else NIL.  X is any Lisp entity.
   eqcar(x,'!:cr!:);

symbolic inline procedure tagrl x; make!:rd crrl x;

symbolic inline procedure tagim x; make!:rd crim x;

symbolic inline procedure gfrl u; car u;

symbolic inline procedure gfim u; cdr u;

symbolic inline procedure mkgf (rl,im); rl . im;

symbolic inline procedure gfzerop u;
  if not atom gfrl u then mt!: gfrl u = 0 and mt!: gfim u = 0
   else u = '(0.0 . 0.0);

% symbolic inline procedure sgn x;
%   if x>0 then 1 else if x<0 then -1 else 0;


global '(bfz!* bfhalf!* bfone!* bftwo!* bfthree!* bffive!* bften!*
         !:bf60!* !:180!* !:bf1!.5!*);

global '(!:bf!-0!.25        %0.25
         !:bf!-0!.0625      %0.0625
         !:bf0!.419921875   %0.419921875
        );

%Miscellaneous constants

bfz!* := make!:ibf(0,0);

bfhalf!* := make!:ibf(1,-1);

bfone!* := make!:ibf(1,0);

!:bf1!.5!* := make!:ibf (3, -1);

bftwo!* := make!:ibf (2, 0);

bfthree!* := make!:ibf (3, 0);

bffive!* := make!:ibf (5, 0);

bften!* := make!:ibf (5, 1);

!:bf60!* := make!:ibf (15, 2);

!:180!* := make!:ibf (45, 2);

!:bf!-0!.25 := make!:ibf(1,-2);

!:bf!-0!.0625 := make!:ibf (1, -4);

!:bf0!.419921875 := make!:ibf(215, -9);

% These need to be added to other modules.

symbolic procedure dn!:simp u;
  if car u = 0 then nil ./ 1
   else if u = '(10 . -1) and null !*noconvert then 1 ./ 1
   else if dmode!* memq '(!:rd!: !:cr!:)
    then rd!:simp cdr decimal2internal (car u, cdr u)
   else if cdr u >= 0 then !*f2q (car u * 10**cdr u)
   else simp {'quotient, car u, 10**(-cdr u)};

put ('!:dn!:, 'simpfn, 'dn!:simp);

symbolic procedure dn!:prin u;
  bfprin0x (cadr u, cddr u);

put ('!:dn!:, 'prifn, 'dn!:prin);

endmodule;

end;
