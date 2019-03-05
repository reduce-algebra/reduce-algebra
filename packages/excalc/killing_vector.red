module killingvec;

% Author: Eberhard Schruefer

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

global '(basisforml!* basisvectorl!* metricd!* naturalvector2framevector);

symbolic procedure killing_vector kname;
   % Sets up the pde's for a Killing vector.
   % Returns a list containing as the first element the Killing vector with
   % unspecified components and as the second element a list of pde's for the
   % components. 
   begin scalar oldkord, coords, kf, b1, b2, lb1, lb2, l12, res, kv;
     kname := car kname;
     l12 := nil ./ 1;
     putform({kname, nil}, 0); 
     remflag({kname}, 'covariant);
     coords := for each j in naturalframe2coframe collect car j;
     kf := kname . coords;
     fdomain1 {{'equal,kname,kf}};
     if basisvectorl!* 
        then for each l in basisvectorl!* do
               kv := addpf(multpfs(partitop l, partitop({kname, cadadr l})), kv)
      else for each l in coords do 
             kv := addpf(multpfs(partitop {'partdf, l}, partitop({kname, l})), kv);
     oldkord := setkorder basisforml!*;
     for each k in metricd!* do
       for each l in cdr k do
         <<b1 := partitop rassoc({car k}, basisforml!*);
           b2 := partitop rassoc({car l}, basisforml!*);
           lb1 := multsq(!*pf2sq b2, !*pf2sq multpfsq(liedfpf(kv, b1), simp cdr l));
           lb2 := multsq(!*pf2sq b1, !*pf2sq liedfpf(kv, multpfsq(b2, simp cdr l)));
           l12 := addsq(addsq(lb1, lb2), l12)>>;
     setkorder oldkord;
     res := for each j on numr l12 conc 
              if ldeg j = 2 then {killing_normalize_pde lc j}
               else for each m on lc j collect killing_normalize_pde lc m;
     return {'list, mk!*sq !*pf2sq kv, 'list . res}
   end;

symbolic procedure killing_normalize_pde u;
   begin scalar c;
     if minusp lnc u then u := negf u;
     c := comfac u;
     c := ignore_partdf cdr c;
     return mk!*sq(quotf1(u, c) ./ 1)
   end;

symbolic procedure ignore_partdf u;
   if domainp u then u
    else if eqcar(mvar u, 'partf) then ignore_partdf lc u
    else lpow u .* ignore_partdf lc u .+ ignore_partdf red u;
   

put('killing_vector, 'psopfn, 'killing_vector);

endmodule;

end;

