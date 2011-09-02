module tpsconv;

%*****************************************************************
%
%     Functions converting power series objects to prefix forms
%
%*****************************************************************


exports prep!:ps, ps!:print1, ps!:print, ps!:print0;

fluid '(ps!:exp!-lim !*fort !*nat );

symbolic procedure prep!:ps(ps, highest!-order);
begin scalar x, var, inv;
   var := ps!:mkvar ps;
   inv := (ps!:expansion!-point ps = 'ps!:inf);
   return replus
      for j := ps!:find!-order ps : highest!-order join
      	 << x := prepsq!* ps!:evaluate(ps,j);
            if x = 0 then nil
 	    else  
	       {retimes ((if eqcar (x, 'quotient) 
		              and eqcar (cadr x, 'minus) then
                            {'minus, {'quotient, cadr cadr x, caddr x}}
                          else x) . ps!:mkpow(var, j, inv))}
         >>;
end;

% symbolic procedure ps!:mkpow(bas, exp, inverted);
%    if exp = 0 then {1}
%    else if exp > 0 then
%       (if inverted then {{'quotient, 1, x}} else {x})
% 	 where x = (if exp = 1 then bas else {'expt,bas, exp})
%    else 
%       (if inverted then {x} else {{'quotient, 1, x}})
%        	 where x = (if exp = -1 then bas
%                           else {'expt,bas, -exp});

Comment
 The following coding treats negative order terms in expansions
 about infinity in the same way as Taylor (ie. 1 over negative powers
  of x), whereas the code above prints these as positive powers of x;


symbolic procedure ps!:mkpow(bas, exp, inverted);
   if exp = 0 then {1}
   else 
      (if inverted then {{'quotient, 1, x}} else {x})
	 where x = (if exp = 1 then bas else {'expt,bas, exp});

symbolic procedure ps!:mkvar ps;
begin scalar var0, var;
  var := ps!:depvar ps;
  var0 := ps!:expansion!-point ps;
  if var0 = 0 or var0 = 'ps!:inf then
     return var
  else if numberp var0 and var0 < 0 then
     return {'plus, var, -var0}
  else if eqcar(var0, 'minus) then
     return {'plus, var, cadr var0}
  else if eqcar(var0, 'quotient) and eqcar(cadr var0, 'minus) then
     return {'plus, var, {'quotient, cadadr var0, caddr var0}}
  else
     return {'difference, var, var0}; 
end;

symbolic procedure ps!:big!-o(ps, ord);
  %
  % Generates a big-O notation for power series
  %
  "O" . ps!:mkpow(ps!:mkvar ps,
                  ord,
   	       	  (ps!:expansion!-point ps = 'ps!:inf));

symbolic procedure ps!:print1 u;
begin scalar prepexpr, rest;
    prepexpr := prep!:ps(u, ps!:exp!-lim);
    rest := {ps!:big!-o(u, ps!:exp!-lim+1)};
    return 
       if not eqcar (prepexpr, 'plus) then
	  'plus . (prepexpr or 0) . rest
       else 
	  nconc (prepexpr, rest);
end;

put('!:ps!:, 'fancy!-reform, 'ps!:print1);

symbolic procedure ps!:print(u,p);
  if !*fort then
     fmprint(prep!:ps(u,ps!:exp!-lim),p)
  else if null !*nat then
     	maprint('ps . (ps!:value u) . (ps!:depvar u) .
	           {(if about = 'ps!:inf then 'infinity 
                     else if about = nil then 'undefined else about)
		      where about = ps!:expansion!-point u},
	        p)
  else if constantpsp u then 
     	maprint(prepsqxx ps!:get!-term(u, 0), p)
  else maprint(ps!:print1 u, p);

symbolic procedure ps!:print0 u;
    ps!:print(u,0);

Comment We need another printing function for use with the
        TeX-REDUCE interface; %not yet done;

endmodule;

end;
