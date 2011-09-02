module tpssum;

% Written by Alan Barnes.  September 1990
% Allows power series whose general term is given to be manipulated.
%
%   pssum(<sumvar>=<lowlim>, <coeff>, <depvar>, <about>, <power>);
%
%     <sumvar>    summation variable                  (a kernel)
%     <lowlim>    lower limit of summation            (an integer)
%     <coeff>     general coefficient of power series (algebraic)
%     <depvar>    expansion variable of series        (a kernel)
%     <about>     expansion point of series           (algebraic)
%     <power>     general exponent of power series    (algebraic)
% <power> must be a strictly increasing function of <sumvar>
%         this is now partially checked by the system


symbolic procedure ps!:summation!-erule(a,n);
begin scalar power, coeff,sumvar,current!-index,last!-exp,current!-exp;
   current!-index:= rand2 a;
   sumvar:= rand1 a; coeff := cdddr a;
   power:= cadr coeff; coeff:=car coeff;
   last!-exp:= ieval reval subst(current!-index,sumvar,power);
   repeat <<
     current!-index:=current!-index+1;
     current!-exp:= ieval reval subst(current!-index,sumvar,power);
     if current!-exp leq last!-exp then
       rerror(tps,39,"Exponent not strictly increasing: ps:summation");
     if  current!-exp < n then <<
         ps!:set!-term(ps,current!-exp,
                        simp!* subst(current!-index,sumvar,coeff));
         rplaca(cddr a,current!-index)>>;
     last!-exp:=current!-exp>>
   until current!-exp geq n;
   return if current!-exp = n then <<
              rplaca(cddr a,current!-index);
              simp!* subst(current!-index,sumvar,coeff) >>
          else (nil ./ 1)
end;

put('ps!:summation, 'ps!:erule, 'ps!:summation!-erule);
put('ps!:summation, 'simpfn, 'simpiden);
put('pssum, 'simpfn, 'simppssum);

symbolic procedure simppssum a;
begin scalar !*nosubs,from,sumvar,lowlim,coeff,
              power,depvar,about,psord,term;
   if length a neq 5 then rerror(tps,40,
   "Args should be <FROM>,<coeff>,<depvar>,<point>,<power>: simppssum");
   !*nosubs := t;  % We don't want left side of eqns to change.
   from := reval car a;
   !*nosubs := nil;
   if not eqexpr from then
      errpri2(car a,t)
   else <<sumvar:= cadr from;
          if not kernp simp!* sumvar then
              typerr(sumvar, "kernel:  simppssum");
          lowlim:= ieval caddr from >>;
   coeff:= prepsqxx simp!* cadr a;
   a:= cddr a;
   depvar := car a; about:=prepsqxx simp!* cadr a;
   if about = 'infinity then about := 'ps!:inf;
   power:= prepsqxx simp!* caddr a;
   if not kernp simp!* depvar then
        typerr(depvar, "kernel:  simppssum")
   else if depvar=sumvar then  rerror(tps,41,
           "Summation and expansion variables are the same:  simppssum")
   else if  smember(depvar,about) then
        rerror(tps,42,"Expansion point depends on depvar:  simppssum")
   else if  smember(sumvar,about) then rerror(tps,43,
            "Expansion point depends on summation var:  simppssum")
   else if not smember(sumvar,power) then rerror(tps,44,
         "Exponent does not depend on summation variable: simppssum");
   lowlim:=lowlim-1;
   repeat <<
     lowlim:=lowlim+1;
     psord:= ieval reval subst(lowlim,sumvar,power)>>
   until (term:=simp!* subst(lowlim,sumvar,coeff)) neq '(nil . 1);
   ps:=make!-ps(list('ps!:summation,sumvar,lowlim,coeff,power),
                list('ps!:summation,from,coeff,depvar,about,power),
                depvar, about);
   ps!:set!-order(ps,psord);
   ps!:set!-term(ps,psord, term);
   return (ps ./ 1)
end;

endmodule;

end;
