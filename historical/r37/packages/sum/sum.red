module sum;  % Driver for various sum capabilities.

% Author: Anthony C. Hearn, derived from code by F. Kako and W. Koepf.

create!-package('(sum sum2 complx prod),'(contrib sum));
% create!-package('(sum sum2 complx prod zeilberg),'(contrib sum));

fluid '(!*zeilberg);

switch zeilberg;

put('sum,'simpfn,'simp!-sum);

symbolic procedure simp!-sum u;
   %ARGUMENT  CAR U: expression of prefix form.
   %         CADR U: kernel.
   %        CADDR U: lower bound.
   %       CADDDR U: upper bound.
   %value          : expression of sq form.
   begin scalar y;
      y := cdr u;
      u := simp!* car u;
      return if null numr u then u
	      else if atom y
               then !*p2f(car fkern(list('sum,prepsq u)) .* 1) ./ 1
	      else if !*zeilberg then gosper!*(mk!*sq u,y)
	      else simp!-sum0(u,y)
   end;

endmodule;

end;
