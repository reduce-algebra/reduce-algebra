module mvmatch;  % Side relation matching against expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All Rights Reserved.

symbolic procedure mv!-compact(u,v,w);
   % Compares a multivariate form u with a multivariate form template v
   % and reduces u appropriately.
   % Previously, the content was removed from u.  However, this does
   % not work well if the same content is in v.
   begin scalar x,y;   % z;
      if null u then return mv!-reverse w;
%     if null w then <<z := mv!-content u; u := mv!-term!-!/(u,z)>>
%      else z := nzeros length mv!-lpow u . 1;
	% check first terms.
      if (x := mv!-pow!-chk(u,v))
	  and (y := mv!-compact2(u,mv!-pow!-mv!-!+(x,v)))
%       then return mv!-term!-!*(z,mv!-compact(y,v,w))
	then return mv!-compact(y,v,w)
	% check second terms.
       else if (x := mv!-pow!-chk(u,mv!-red v))
	  and not mv!-pow!-assoc(y := mv!-pow!-!+(x,mv!-lpow v),w)
	  and (y := mv!-compact2(mv!-!.!+(mv!-!.!*(y,0),u),
				 mv!-pow!-mv!-!+(x,v)))
%       then return mv!-term!-!*(z,mv!-compact(y,v,w))
%      else return mv!-term!-!*(z,mv!-compact(mv!-red u,v,mv!-lt u . w))
	then return mv!-compact(y,v,w)
       else return mv!-compact(mv!-red u,v,mv!-lt u . w)
   end;

symbolic procedure mv!-pow!-assoc(u,v); assoc(u,v);

symbolic procedure mv!-reverse u; reversip u;

symbolic procedure mv!-pow!-chk(u,v);
%  (u := mv!-pow!-!-(caar u,caar v)) and not mv!-pow!-minusp u and u;
   if v and (u := mv!-pow!-!-(caar u,caar v)) and not mv!-pow!-minusp u
     then u
    else nil;

symbolic procedure mv!-compact2(u,v);
   % U and v are multivariate forms whose first powlists are equal.
   % Value is a suitable multiplier of v which when subtracted from u
   % results in a more compact expression.
   begin scalar x,y,z;
      x := equiv!-coeffs(u,v);
      z := mv!-domainlist v;
      y := reduce(x,z);
      return if y=x then nil
	   else mv!-!+(mv!-coeff!-replace(v,mv!-domainlist!-!-(y,x)),u)
   end;

symbolic procedure mv!-coeff!-replace(u,v);
   % Replaces coefficients of multivariate form u by those in domain
   % list v.
   if null u then nil
    else if car v=0 then mv!-coeff!-replace(mv!-red u,cdr v)
    else mv!-!.!+(mv!-!.!*(mv!-lpow u,car v),
		mv!-coeff!-replace(mv!-red u,cdr v));

symbolic procedure equiv!-coeffs(u,v);
   if null u then nzeros length v
    else if null v then nil
    else if mv!-lpow u = mv!-lpow v
     then cdar u . equiv!-coeffs(cdr u,cdr v)
    else if mv!-pow!-!>(mv!-lpow u,mv!-lpow v)
     then equiv!-coeffs(cdr u,v)
    else 0 . equiv!-coeffs(u,cdr v);

endmodule;

end;
