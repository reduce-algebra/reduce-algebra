module fourplus;

%% ARITHMETIC

%% Addition of Fourier expressionsis really a merge operation

symbolic procedure fs!:plus!:(x,y);
 %% Top level addition of two fourier series
    if fs!:zerop!: y then x
    else if fs!:zerop!: x then y
    else get('fourier,'tag)
	    . fs!:plus(copy!-tree cdr x, copy!-tree cdr y);

% I cannot rely on the CAMAL selective copy, so I take the coward's way
% out.
symbolic procedure copy!-tree x;
   if null x then nil
   else begin scalar ans;
      ans := mkvect 3;
      fs!:set!-coeff(ans,fs!:coeff x); 
      fs!:set!-fn(ans,fs!:fn x);
      fs!:set!-angle(ans,fs!:angle x); 
      fs!:set!-next(ans, copy!-tree fs!:next x); 
      return ans
   end;

symbolic procedure fs!:plus(x, y);
  %% The real addition.  x is a new tree to which y must be merged.
  if null y then x
  else if null x then y
  else if fs!:fn x = fs!:fn y
     and angles!-equal(fs!:angle x, fs!:angle y) then
        begin scalar coef;
            coef := addsq(fs!:coeff x, fs!:coeff y);
        % Really I should deal with the zero case here
	    if null car coef
	      then return fs!:plus(fs!:next x, fs!:next y);
            fs!:set!-coeff(x, coef);
            fs!:set!-next(x, fs!:plus(fs!:next x, fs!:next y));
            return x 
        end
    else if fs!:angle!-order(x, y) then <<
          fs!:set!-next(x, fs!:plus(fs!:next x, y));
          x >>
    else <<
          fs!:set!-next(y, fs!:plus(fs!:next y,x));
          y >>;

symbolic procedure angles!-equal(x, y);
% Are all angles the same?
begin scalar i;
    i := 0;
top:
    if not(getv!.unsafe(x,i)=getv!.unsafe(y,i)) then return nil;
    i := i+1;
    if (i<8) then go to top;
    return t;
end;

symbolic procedure fs!:angle!-order(x, y);
% Ordering function for angle expressions, also taking account of angle.
begin scalar ans, i, xx, yy;
    i := 0;
    xx := fs!:angle x;
    yy := fs!:angle y;
top:
    ans := (getv!.unsafe(xx,i)-getv!.unsafe(yy,i));
    if not(ans = 0) then return ans>0;
    i := i+1;
    if (i<8) then go to top;
    return
      if fs!:fn x = fs!:fn y then nil
       else if fs!:fn x = 'sin then nil else t;
end;

endmodule;

end;
