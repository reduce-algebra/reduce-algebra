module vecanlys;

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


% Author: Eberhard Schruefer

global '(dimex!* sgn!*);

fluid '(!*excalc_utf8);

newtok '((#bullet;) dotprod);
newtok '((!|) dotprod);
infix dotprod;
precedence dotprod,times;


newtok '((!. !* !.) crossprod);
newtok '((#times;) crossprod);
infix crossprod;
precedence crossprod,dotprod;
put('crossprod,'prtch,'!.!*!.);


symbolic procedure !3dvectors u;
   begin 
     dimex!* := 3;
     sgn!* := 1 ./ 1;
     for each j in u do putform(j,1);
     put('hodge,'prifn,'(lambda (x) (maprin (!*ext2vec x))));
     remprop('d,'prifn);
     put('d,'prifn,'(lambda (x) (maprin (!*ext2vec x))))
   end;

rlistat '(!3dvectors);

symbolic procedure !3dfunctions u;
   begin 
     dimex!* := 3;
     sgn!* := 1 ./ 1;
     for each j in u do putform(j,nil)
   end;

rlistat '(!3dfunctions);

symbolic procedure basis u;
   cofram(for each j in u collect cdr j,nil);

rlistat '(basis);

symbolic procedure simpgrad u;
   !*pf2sq partitgradient u;

symbolic procedure partitgradient u;
   exdfpf partitop car u;

put('grad,'simpfn,'simpgrad);
put('grad,'partitfn,'partitgradient);

symbolic procedure simp0grad u;
   !*k2q('d . cdr u);

put('grad,'simp0fn,'simp0grad);

symbolic procedure simprot u;
   !*pf2sq partitrotation u;

symbolic procedure partitrotation u;
   hodgepf exdfpf partitop car u;

put('rot,'simpfn,'simprot);
put('rot,'partitfn,'partitrotation);

symbolic procedure simp0rot u;
   !*k2q {'d,'hodge . cdr u};

put('rot,'simp0fn,'simp0rot);

symbolic procedure simpdiv u;
   !*pf2sq partitdivergence u;

symbolic procedure partitdivergence u;
   hodgepf exdfpf hodgepf partitop car u;

put('div,'simpfn,'simpdiv);
put('div,'partitfn,'partitdivergence);

symbolic procedure simp0div u;
   !*k2q {'hodge,{'d,'hodge . cdr u}};

put('div,'simp0fn,'simp0div);


put('crossprod,'prtch,'!.!*!.);

symbolic procedure simpcrossprod u;
   !*pf2sq partitcrossprod u;

symbolic procedure partitcrossprod u;
   crossprodpf(partitop car u,partitop cadr u);

symbolic procedure crossprodpf(u,v);
   hodgepf mkuniquewedge wedgepf2(u,mkunarywedge v); 

put('crossprod,'simpfn,'simpcrossprod);
put('crossprod,'partitfn,'partitcrossprod);
flag('(crossprod),'spaced);

symbolic procedure simp0crossprod u;
   !*k2q {'hodge,'wedge . cdr u};

put('crossprod,'simp0fn,'simp0crossprod);

symbolic procedure simpdotprod u;
   !*pf2sq partitdotprod u;

symbolic procedure partitdotprod u;
   dotprodpf(partitop car u,partitop cadr u);

symbolic procedure dotprodpf(u,v);
   hodgepf mkuniquewedge wedgepf2(hodgepf u,mkunarywedge v); 

put('dotprod,'simpfn,'simpdotprod);
put('dotprod,'partitfn,'partitdotprod);

symbolic procedure simp0dotprod u;
   !*k2q {'hodge,{'wedge,car u,'hodge . cddr u}};

put('dotprod,'simp0fn,'simp0dotprod);

symbolic procedure simpspat u;
   !*pf2sq partitspat u;

symbolic procedure partitspat u;
   spatpf(partitop car u,partitop cadr u,partitop caddr u);

symbolic procedure spatpf(u,v,w);
   hodgepf mkuniquewedge wedgepf2(u,wedgepf2(v,mkunarywedge w)); 

put('spat,'simpfn,'simpspat);
put('spat,'partitfn,'partitspat);

symbolic procedure simp0spat u;
   !*k2q {'hodge,'wedge . u};

put('spat,'simp0fn,'simp0spat);


symbolic procedure !*ext2vec u;
   if atom u then u
    else if car u eq 'd then {'grad,!*ext2vec cadr u}
    else if car u eq 'hodge 
            then if eqcar(cadr u,'wedge) then hodgewedge2vec cdadr u
                  else if eqcar(cadr u,'d)
                          then if deg!*form cadadr u = 1 
                                  then {'rot,!*ext2vec cadadr u}
                                else {'div,!*ext2vec cadr cadadr u}
    else u;

symbolic procedure hodgewedge2vec u;
   if length u = 3 
      then {'spat,!*ext2vec car u,!*ext2vec cadr u,!*ext2vec caddr u}
    else if deg!*form car u = 1
            then if deg!*form cadr u = 2
                    then {'dotprod,!*ext2vec car u,
                           if eqcar(cadr u,'d) then {'rot,!*ext2vec cadadr u}
                            else !*ext2vec cadadr u}
                  else {'crossprod,!*ext2vec car u,!*ext2vec cadr u}
          else {'dotprod,if eqcar(car u,'d) then {'rot,!*ext2vec cadar u}
                          else !*ext2vec cadar u,!*ext2vec cadr u};

endmodule;

end;
