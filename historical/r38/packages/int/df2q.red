module df2q;   % Conversion from distributive to standard forms.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(indexlist zlist);

exports df2q;

imports addf,gcdf,mksp,!*multf,quotf;

Comment We assume that results already have reduced powers, so
        that no power substitution is necessary;

symbolic procedure df2q p;
   % Converts distributed form P to standard quotient.
   begin scalar n,d,w;
        if null p then return nil ./ 1;
        d:=denr lc p;
        w:=red p;
	while w do
	   <<n:=gcdf(d,denr lc w); % Get denominator of answer ...
	     d:=!*multf(d,quotf(denr lc w,n));
		 % ... as lcm of denoms in input.
	     w:=red w>>;
	n := nil; % Place to build numerator of answer.
	while p do
	   <<w := sqrt2top lc p;
	     n := addf(n,quotf(!*multf(xl2f(lpow p,zlist,indexlist),
				       !*multf(numr w,d)),
		       denr w));
	     p:=red p>>;
	return n ./ d
    end;

symbolic procedure xl2f(l,z,il);
% L is an exponent list from a D.F., Z is the Z-list,
% IL is the list of indices.
% Value is L converted to standard form. ;
    if null z then 1
        else if car l=0 then xl2f(cdr l,cdr z,cdr il)
        else if not atom car l then
            begin       scalar temp;
                if caar l=0 then temp:= car il
                else temp:=list('plus,car il,caar l);
                temp:=mksp(list('expt,car z,temp),1);
                return !*multf(((temp .* 1) .+ nil),
                               xl2f(cdr l,cdr z,cdr il))
            end
%       else if minusp car l then                                     ;
%            multsq(invsq (((mksp(car z,-car l) .* 1) .+ nil)),       ;
%                  xl2f(cdr l,cdr z,cdr il))                          ;
        else !*multf((mksp(car z,car l) .* 1) .+ nil,
                    xl2f(cdr l,cdr z,cdr il));

endmodule;

end;
