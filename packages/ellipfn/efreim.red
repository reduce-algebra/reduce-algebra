module efreim;   % Extract real & imaginary parts of Jacobi Elliptic Functions

% Author: Alan Barnes.

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
symbolic;
fluid '(jacobi!-assoc!-list);

flag ('(jacobisn jacobicn jacobidn jacobisc jacobisd jacobics
        jacobicd jacobids jacobidc jacobins jacobinc jacobind),
      'realvalued);

jacobi!-assoc!-list :=
   {{'jacobisn, {'reimsn1, 'reimsn1, 'reimsd1, -1}},
    {'jacobicn, {'reimcn1, 'reimdn1, 'reimnd1, 0}},
    {'jacobidn, {'reimdn1, 'reimcn1, 'reimcd1, 0}},
    {'jacobins, {'reimns1, 'reimns1, 'reimds1, 1}},
    {'jacobinc, {'reimnc1, 'reimnd1, 'reimdn1, 0}},
    {'jacobind, {'reimnd1, 'reimnc1, 'reimdc1, 0}},  
    {'jacobisc, {'reimsc1, 'reimsd1, 'reimsn1, -1}},  
    {'jacobisd, {'reimsd1, 'reimsc1, 'reimsc1, -1}},
    {'jacobicd, {'reimcd1, 'reimdc1, 'reimnc1, 0}},  
    {'jacobics, {'reimcs1, 'reimds1, 'reimns1, 1}},  
    {'jacobidc, {'reimdc1, 'reimcd1, 'reimcn1, 0}},  
    {'jacobids, {'reimds1, 'reimcs1, 'reimcs1, 1}}}$ 
   

% Currently only cases with a real or imaginary modulus k are supported.
symbolic procedure reimjac u;
   begin scalar rearg, imarg, kr, ki, op, fnlist, res;
      kr := prepsq simprepart cddr u;
      ki := prepsq simpimpart cddr u;
      if kr neq 0 and ki neq 0 then
	 rederr ("reimjac: modulus must be real or purely imaginary");
      op := car u;
      rearg := prepsq simprepart list cadr u;
      imarg := prepsq simpimpart list cadr u;

      fnlist := cadr assoc(op, jacobi!-assoc!-list);
      op := cadddr fnlist;
      if kr neq 0 then
	 if (s1 and s1 < 0)
	    where s1=sign!-of reval({'plus, {'times, kr, kr}, -1})

	 then return apply(car fnlist, {rearg, imarg, kr})
	 else << res := apply(cadr fnlist, {reval {'times,  kr, rearg},
	                                    reval {'times, kr, imarg},
	                                    reval {'quotient, 1, kr}});
	         return if op = 0 then res
	                else if op = -1 then quotsq(res, simp kr)
	                else multsq(res, simp kr);
	 >>
      else << kr := simp {'sqrt, {'plus, {'times, ki, ki}, 1}};
              ki := prepsq kr;
              res := apply(caddr fnlist, {reval {'times, imarg, ki},
		                          reval {'minus, {'times, rearg, ki}},
 		                          reval {'quotient, 1, ki}});
      	      return if op = 0 then res
	             else if op = -1 then multsq(res, quotsq(simp 'i, kr))
                     else multsq(res, multsq(negsq simp 'i, kr));
           >>;
   end;

foreach fn in '(jacobisn jacobicn jacobidn jacobisc jacobisd jacobics
                jacobicd jacobids jacobidc jacobins jacobinc jacobind) do
          	    put(fn, 'cmpxsplitfn, 'reimjac);

symbolic procedure  reimsn1(rp, ip, k);
begin scalar denom, numer1, numer2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    denom := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                simp {'jacobisn, rp, k}));
    denom := addsq(simp 1, multsq(denom, denom));
    numer1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    numer2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});
    return quotsq(addsq(numer1, multsq(simp 'i, numer2)),
                  denom);
end;

symbolic procedure  reimcn1(rp, ip, k);
begin scalar denom, numer1, numer2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    denom := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                   simp {'jacobisn, rp, k}));
    denom := addsq(simp 1, multsq(denom, denom));
    numer1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    numer2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobidn, rp, k}));
    return quotsq(addsq(numer1, negsq multsq(simp 'i, numer2)),
                  denom);
end;

symbolic procedure  reimdn1(rp, ip, k);
begin scalar denom, numer1, numer2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    denom := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                   simp {'jacobisn, rp, k}));
    denom := addsq(simp 1, multsq(denom, denom));
    numer1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
                            simp {'jacobinc, ip, kp}));
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));
    return quotsq(addsq(numer1, negsq multsq(simp 'i, numer2)),
                  denom);
end;

symbolic procedure  reimns1(rp, ip, k);
begin scalar numer, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                   simp {'jacobisn, rp, k}));
    numer := addsq(simp 1, multsq(numer, numer));
    denom1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    denom2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});

    numer := multsq(numer, addsq(denom1, negsq multsq(simp 'i, denom2)));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer, denom1); 
end;

symbolic procedure  reimnc1(rp, ip, k);
begin scalar numer, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                   simp {'jacobisn, rp, k}));
    numer := addsq(simp 1, multsq(numer, numer));

    denom1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    denom2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobidn, rp, k}));

    numer := multsq(numer, addsq(denom1, multsq(simp 'i, denom2)));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2 , denom2));
    return quotsq(numer, denom1); 
end;

symbolic procedure  reimnd1(rp, ip, k);
begin scalar numer, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer := multsq(simp k, multsq(simp {'jacobisc, ip, kp},
                                   simp {'jacobisn, rp, k}));
    numer := addsq(simp 1, multsq(numer, numer));

    denom1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
 			    simp {'jacobinc, ip, kp}));
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));

    numer := multsq(numer, addsq(denom1, multsq(simp 'i, denom2)));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer, denom1); 
end;

symbolic procedure  reimsc1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    numer2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});
    denom1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    denom2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                     simp {'jacobidn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1),
                          negsq multsq(numer2, denom2)),
                    multsq(simp 'i, addsq(multsq(numer1, denom2),
	                                  multsq(numer2, denom1))));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer1, denom1); 
end;

symbolic procedure  reimcs1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    denom1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    denom2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});
    numer1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    numer2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                      simp {'jacobidn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1),
                          negsq multsq(numer2, denom2)),
                    multsq(simp 'i, negsq addsq(multsq(numer1, denom2),
	                                        multsq(numer2, denom1))));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer1, denom1); 
end;

symbolic procedure  reimsd1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    numer2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});
    denom1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
                            simp {'jacobinc, ip, kp}));
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1),
                          negsq multsq(numer2, denom2)),
                    multsq(simp 'i, addsq(multsq(numer1, denom2),
	                                  multsq(numer2, denom1))));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer1, denom1); 
end;

symbolic procedure  reimds1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    denom1 := multsq(simp {'jacobisn, rp, k},
                     multsq(simp {'jacobidc, ip, kp},
			    simp {'jacobinc, ip, kp}));
    denom2 := multsq(multsq(simp {'jacobicn, rp, k},
                            simp {'jacobidn, rp, k}),
                     simp {'jacobisc, ip, kp});
    numer1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
                            simp {'jacobinc, ip, kp}));
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1),
                          negsq multsq(numer2, denom2)),
                    multsq(simp 'i, negsq addsq(multsq(numer1, denom2),
	                                        multsq(numer2, denom1))));
       
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer1, denom1); 
end;

symbolic procedure  reimdc1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
                            simp {'jacobinc, ip, kp}));
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));

    denom1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    denom2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                     simp {'jacobidn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1), multsq(numer2, denom2)),
                    multsq(simp 'i, addsq(multsq(numer1, denom2),
	                                  negsq multsq(numer2, denom1))));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2, denom2));
    return quotsq(numer1, denom1); 
end;

 symbolic procedure  reimcd1(rp, ip, k);
begin scalar numer1, numer2, denom1, denom2, kp;
    kp :=  prepsq simp {'sqrt, {'difference, 1, {'times, k, k}}};
    numer1 := multsq(simp {'jacobicn, rp, k},
                     simp {'jacobinc, ip, kp});
    numer2 := multsq(simp {'jacobisc, ip, kp},
                     simp {'jacobidc, ip, kp});
    numer2 := multsq(numer2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobidn, rp, k}));

    denom1 := multsq(simp {'jacobidn, rp, k},
                     simp {'jacobidc, ip, kp});
    denom2 := multsq(simp {'times, k, k},
                     multsq(simp {'jacobisc, ip, kp},
                            simp {'jacobinc, ip, kp}));
    denom2 := multsq(denom2, multsq(simp {'jacobisn, rp, k},
                                    simp {'jacobicn, rp, k}));
    
    numer1 := addsq(addsq(multsq(numer1, denom1), multsq(numer2, denom2)),
                    multsq(simp 'i, addsq(multsq(numer1, denom2),
	                                  negsq multsq(numer2, denom1))));
    denom1 := addsq(multsq(denom1, denom1), multsq(denom2,denom2));
    return quotsq(numer1, denom1); 
end;


endmodule;

;end;
