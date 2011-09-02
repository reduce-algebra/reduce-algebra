module dint;  % Definite integration support.

% Author: Anthony C. Hearn.

fluid '(!*precise);

symbolic procedure simpdint u;
   begin scalar low,upp,fn,var,x,y;
      if length u neq 4
	then rerror(int,2,"Improper number of arguments to INT");
      fn := car u;
      var := cadr u;
      low := caddr u;
      upp := cadddr u;
      low := reval low;
      upp := reval upp;
      if low = upp then return nil ./ 1
       else if null getd 'new_defint then nil
       else if upp = 'infinity
	then if low = 0
	       then if not smemql('(infinity unknown),
				  x := defint!* {fn,var})
		      then return simp!* x else nil
	      else if low = '(minus infinity)
	       then return mkinfint(fn,var)
	      else if freeof(var,low)
	       then if not smemql('(infinity unknown),
				  x := defint!* {fn,var})
		     and not smemql('(infinity unknown),
				  y := indefint!* {fn,var,low})
		      then return simp!* {'difference,x,y} else nil
	      else nil
       else if upp = '(minus infinity) or low = 'infinity
	then return negsq simpdint {fn,var,upp,low}
       else if low = '(minus infinity)
	then return
	   simpdint{prepsq simp{'sub,{'equal,var,{'minus,var}},fn},
		     var,{'minus,upp},'infinity}
       else if low = 0
	then if freeof(var,upp)
		and not smemql('(infinity unknown),
			       x := indefint!* {fn,var,upp})
	       then return simp!* x else nil
       else if freeof(var,upp) and freeof(var,low)
		 and not smemq('(infinity unknown),
			       x := indefint!* {fn,var,upp})
		 and not smemql('(infinity unknown),
			       y := indefint!* {fn,var,low})
	then return simp!* {'difference,x,y};
      return mkdint(fn,var,low,upp)
   end;

symbolic procedure defint!* u;
   (if errorp x then 'unknown else car x)
    where x = errorset2 {'new_defint,mkquote u};

symbolic procedure indefint!* u;
   (if errorp x or eqcar(car x,'indefint2) then 'unknown else car x)
    where x = errorset2 {'new_indefint,mkquote u};

symbolic procedure mkdint(fn,var,low,upp);
   % This could be used as an entry point to other dint procedures.
   % Should we handle infinity, - infinity differently?
   begin scalar x; % ,!*precise;
      if getd 'defint0
	 and not((x := defint0 {fn,var,low,upp}) eq 'failed)
	then return simp x
       else if not smemq('infinity,low) and not smemq('infinity,upp)
	then <<x := prepsq!* simpint {fn,var};
	       if not eqcar(x,'int)
		 then return simp!* {'difference,
				     subeval {{'equal,var,upp},x},
				     subeval {{'equal,var,low},x}}>>;
      return mksq({'int,fn,var,low,upp},1)
   end;

symbolic procedure mkinfint(fn,var);
   begin scalar x,y;
      if getd 'defint0
	 and not((x := defint0 {fn,var,'(minus infinity),'infinity})
		 eq 'failed) then return simp x;
      x := simpdint {fn,var,0,'infinity};
      y := simpdint {fn,var,'(minus infinity),0};
      if kernp x and eqcar(mvar numr x,'int)
	 and kernp y and eqcar(mvar numr y,'int)
	then return mkdint(fn,var,'(minus infinity),'infinity)
       else return addsq(x,y)
   end;

endmodule;

end;
