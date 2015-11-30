module specbess;  % Special functions package; Bessel and relatives.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...
%          contribution from various authors ...

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


remprop('BesselI,'simpfn);
remprop('BesselJ,'simpfn);
remprop('BesselY,'simpfn);
remprop('BesselI,'simpfn);
remprop('BesselK,'simpfn);
remprop('hankel1,'simpfn);
remprop('hankel2,'simpfn);
remprop('KummerM,'simpfn);
remprop('KummerU,'simpfn);
remprop('StruveH,'simpfn);
remprop('StruveL,'simpfn);
remprop('lommel1,'simpfn);
remprop('lommel2,'simpfn);
remprop('WhittakerM,'simpfn);
remprop('WhittakerW,'simpfn);
remprop('Airy_Ai,'simpfn);
remprop('Airy_Bi,'simpfn);
remprop('Airy_Aiprime,'simpfn);
remprop('Airy_Biprime,'simpfn);


create!-package ('(specbess sfbes sfkummer sfother sfairy),
                 '(contrib specfn));

symbolic inline procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   !:bprec!:;

% These functions are needed in other modules.
%  complex!*on!*switch and complex!*off!*switch return t iff the
%  switch complex was already in the correct position

algebraic procedure complex!*on!*switch;
  symbolic 
    if not !*complex then <<(onoff('complex,t) where !*msg := nil); nil>>
     else t;

algebraic procedure complex!*off!*switch;
   if symbolic !*complex then
      if symbolic !*msg then
         << off msg; off complex; on msg >>
      else off complex
   else t;

% complex!*restore!*switch takes the value returned by complex!*on!*switch or
%  complex!*off!*switch and restore the switch complex to its former value,
%  i.e. the switch is flipped if the argument is nil

algebraic procedure complex!*restore!*switch(fl);
  symbolic
    begin scalar !*msg;
      if not fl then onoff('complex,not !*complex)
    end;

endmodule;

end;

