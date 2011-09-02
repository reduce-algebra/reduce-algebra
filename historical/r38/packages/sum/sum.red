module sum;  % Driver for various sum capabilities.

% Author: Anthony C. Hearn, derived from code by F. Kako and W. Koepf.

create!-package('(sum sum2 complx prod),'(contrib sum));
% create!-package('(sum sum2 complx prod zeilberg),'(contrib sum));

fluid '(!*zeilberg);

switch zeilberg;

put('sum,'simpfn,'simp!-sum);

symbolic procedure freeof!-df(u, v);
   % check u contains differential operator with respect to v;
   if atom u then t
    else if car(u) eq 'df
     then freeof!-df(cadr u,v) and not smember(v,cddr u)
    else freeof!-dfl(cdr u,v);

symbolic procedure freeof!-dfl(u, v);
   if null u then t else freeof!-df(car u,v) and freeof!-dfl(cdr u,v);

symbolic procedure simp!-sum u;
   %ARGUMENT  CAR U: expression of prefix form.
   %         CADR U: kernel.
   %        CADDR U: lower bound.
   %       CADDDR U: upper bound.
   %value          : expression of sq form.
   begin scalar y;
      y := cdr u;
      u := car u;
      if not atom y and not freeof!-df(u, car y) then
	if atom y
	       then return !*p2f(car fkern(list('sum,u)) .* 1) ./ 1
	 else return sum!-df(u, y);
      u := simp!* u;
      return if null numr u then u
	      else if atom y
               then !*p2f(car fkern(list('sum,prepsq u)) .* 1) ./ 1
	      else if !*zeilberg then gosper!*(mk!*sq u,y)
	      else simp!-sum0(u,y)
   end;

endmodule;

end;
