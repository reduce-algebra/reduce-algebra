module homog; % Procedures for factorization of homogeneous polynomials.
 
% Authors: Shuichi Moritsugu <y31046@tansei.cc.u-tokyo.ac.jp>
%          and Eiichi Goto.
 
symbolic procedure homogp s;
   % Confirmation of homogeneous polynomials.
      if domainp s or domainp car s then nil
        else if null cdadr s then nil
	else if domainp cdr lastnondomain cadr s then nil
	else if listsum caaadr s=listsum caar lastnondomain cadr s
	 then t
        else nil;
 
symbolic procedure subs0 nm;
   %Substitution of 0 into exponent list.
      if null nm then nil
        else ((0 . cdaar nm) . cdar nm) . subs0 cdr nm;
 
symbolic procedure varss(v,d);
   % Ss of single variable.
      ((v . nil) . 1) . ((((d . nil) . 1) . nil) . 1);
 
symbolic procedure rconstnm(nm,nv,td);
   % Reconstruction of numerator.
      if null nm then nil
        else if domainp nm then ((td . mkzl(nv+1)) . nm) . nil
        else (((td-listsum caar nm) . caar nm) . cdar nm)
             . rconstnm(cdr nm,nv,td);
 
symbolic procedure rconst1(s,v,td);
   % Reconstruction of one factor.
      if homogp s then s
        else ((v . caar s) . (cdar s+1))
             . (reverse rconstnm(cadr s,cdar s,td) . cddr s);
 
symbolic procedure rconst(p,fctrlis);
   % Reconstruction of factors.
   begin scalar v,d,td,fs,fcf,ffl,x;
      v := car p; d := cdr p; fcf := car fctrlis;
      for i:=2:length fctrlis do
          <<x := nth(fctrlis,i);
            fs := sf2ss car x; td := listsum caaadr fs;
            fs := rconst1(fs,v,td);
            d := d-cdr x*td;
            ffl := aconc(ffl,ss2sf fs . cdr x)>>;
      ffl := fcf . ffl;
      if d>0 then ffl := aconc(ffl,ss2sf varss(v,1) . d);
      return ffl;
   end;

endmodule;

end;
