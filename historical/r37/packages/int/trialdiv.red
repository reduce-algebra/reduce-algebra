module trialdiv;  % Trial division routines.

% Authors: Mary Ann Moore and Arthur C. Norman.

fluid '(!*trint intvar loglist tanlist);

exports countz,findsqrts,findtrialdivs,trialdiv,simp,mksp;

imports !*multf,printsf,quotf;

symbolic procedure countz dl;
% DL is a list of S.F.s;
    begin         scalar s,n,rl;
loop2:  if null dl then return arrangelistz rl;
        n:=1;
loop1:  n:=n+1;
        s:=car dl;
        dl:=cdr dl;
        if not null dl and (s eq car dl) then
            go to loop1
        else rl:=(s.n).rl;
        go to loop2
    end;

symbolic procedure arrangelistz d;
    begin         scalar n,s,rl,r;
        n:=1;
        if null d then return rl;
loopd:  if (cdar d)=n then s:=(caar d).s
        else r:=(car d).r;
        d:=cdr d;
        if not null d then go to loopd;
        d:=r;
        rl:=s.rl;
        s:=nil;
        r:=nil;
        n:=n+1;
        if not null d then go to loopd;
        return reversip rl
    end;

symbolic procedure findtrialdivs zl;
%zl is list of kernels found in integrand. result is a list
%giving things to be treated specially in the integration
%viz: exps and tans.
%Result is list of form ((a . b) ...)
% with a a kernel and car a=expt or tan
% and b a standard form for either expt or (1+tan**2).
    begin         scalar dlists1,args1;
        while not null zl do <<
            if exportan car zl then <<
                if caar zl='tan
                  then << args1:=(mksp(car zl,2) .* 1) .+ 1;
                    tanlist:=(args1 ./ 1) . tanlist>>
                else args1:=!*k2f car zl;
                dlists1:=(car zl . args1) . dlists1>>;
            zl:=cdr zl >>;
        return dlists1
    end;

symbolic procedure exportan dl;
    if atom dl then nil
     else begin
    % extract exp or tan fns from the z-list.
	if eq(car dl,'tan) then return t;
   nxt: if not eq(car dl,'expt) then return nil;
        dl:=cadr dl;
%       if atom dl then return t;
%       if atom dl or constant_exprp dl then return t;
	if atom dl or not smember(intvar,dl) then return t;
% Make sure we find nested exponentials?
        go to nxt
    end;

symbolic procedure findsqrts z; 
    begin  scalar r; 
        while not null z do << 
            if eqcar(car z,'sqrt) then r:=(car z) . r; 
            z:=cdr z >>; 
        return r 
    end; 

symbolic procedure trialdiv(x,dl);
    begin         scalar qlist,q;
    while not null dl do
        if not null(q:=quotf(x,cdar dl)) then <<
            if (caaar dl='tan) and not eqcar(qlist,cdar dl) then
                loglist:=('iden . simp cadr caar dl) . loglist;
                         %tan fiddle!
            qlist:=(cdar dl).qlist;
            x:=q >>
        else dl:=cdr dl;
    return qlist.x
    end;

endmodule;

end;
