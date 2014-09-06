module matproc;   %  Support for matrix valued procedures.

% Author: Eberhard Schruefer

% Copyright (c) 2014, Eberhard Schruefer.  All rights reserved.

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

global '(cursym!*);

symbolic procedure readmatproc;
   begin
     cursym!* := 'procedure;
     return 'matproc . procstat1 'algebraic
   end;

put('matrixproc,'stat,'readmatproc);

symbolic procedure formmatproc(u,v,w);
   begin scalar x;
     flag({caddr u},'formc);
     x := formproc(cdr u,v,w);
     return car x . cadr x .  
             {'put,mkquote caddr u,''rtypefn,''(lambda(x) 'matrix)}
             . {'put,mkquote caddr u,''matrixfn,
               {'list,''lambda,''(x y),
                     {'list,''matproceval,mkquote mkquote caddr u,''x,''y}}}
             . cdddr x
   end;

put('matproc,'formfn,'formmatproc);

symbolic procedure matproceval(op,u,v);
   reval1(opfneval(op . u),v);

% If the arguments of a procedure get passed by value, we must be able
% to get and set matrix elements on the matrix structure directly.

symbolic procedure getmatstructelem u;
   begin scalar x,y;
      x := car u;
      y := reval_without_mod cadr u;
      if not fixp y or y<=0 then typerr(y,"positive integer");
      x := nth(cdr x,y);
      y := reval_without_mod caddr u;
      if not fixp y or y<=0 then typerr(y,"positive integer");
      return nth(x,y)
   end;

put('mat,'structfn,'getmatstructelem);

symbolic procedure setmatstructelem(u,v);
   begin scalar x,y;
      x := car u;
      y := cdr u;
      y := reval_without_mod cadr u;
      if not fixp y or y<=0 then typerr(y,"positive integer");
      x := nth(cdr x,y);
      y := reval_without_mod caddr u;
      if not fixp y or y<=0 then typerr(y,"positive integer");
      return rplaca(pnth(x,y),v)
   end;

put('mat,'setstructfn,'setmatstructelem);

endmodule;

end;
