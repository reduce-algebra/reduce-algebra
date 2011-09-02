module hdiff;

%% Harmonic differentiation and Integration.

symbolic procedure hdiff(x, u);
if null x then nil
    else fs!:plus(hdiff(fs!:next x,u), hdiffterm(x,u));

symbolic procedure hdiffterm(x, u);
begin scalar n;
   n := getv!.unsafe(fs!:angle x, u);
   if n = 0 then return nil;
   n := multsq( n . 1, fs!:coeff x);
   if fs!:fn x = 'cos then return make!-term('sin, fs!:angle x, negsq n)
   else                    return make!-term('cos, fs!:angle x, n)
end;

symbolic procedure hdiff1(x, u);
if null x then nil
else begin scalar ans, aaa;
        ans := diffsq(fs!:coeff x, u);
        if ans then <<
            aaa := mkvect 3;
            fs!:set!-coeff(aaa, ans); 
            fs!:set!-fn(aaa, fs!:fn x);
            fs!:set!-angle(aaa,fs!:angle x);
            fs!:set!-next(aaa, hdiff1(fs!:next x, u));
            return aaa >>
        else return hdiff1(fs!:next x, u)
end;

symbolic procedure simphdiff uu;
begin scalar x, u;
    if not (length uu = 2) then
        rerror(fourier, 10, "Improper number of arguments to HDIFF");
    x := car uu; uu := cdr uu;
    u := car uu;
    x := simp x;
    if not eqcar(car x, '!:fs!:) then x := !*sq2fourier x ./ 1;
    if not harmonicp u then 
        return (get('fourier, 'tag) . hdiff1(cdar x, u)) ./ 1;
    x := hdiff(cdar x,get(u,'fourier!-angle));
    if null x then return nil ./ 1;
    return (get('fourier, 'tag) . x) ./ 1
end;

put('hdiff, 'simpfn, 'simphdiff);

symbolic procedure hint(x, u);
if null x then nil
%% Bind fs!:zero!-generated ??
    else fs!:plus(hint(fs!:next x,u), hintterm(x,u));

symbolic procedure hintterm(x, u);
begin scalar n;
   n := getv!.unsafe(fs!:angle x, u);
   if n = 0 then return make!-term(fs!:fn x, fs!:angle x, fs!:coeff x);
   n := multsq( 1 ./ n, fs!:coeff x);
   if fs!:fn x = 'cos then return make!-term('sin, fs!:angle x, n)
   else                    return make!-term('cos, fs!:angle x, negsq n)
end;

symbolic procedure hint1(x , u);
if null x then nil
else begin scalar aaa;
        aaa := mkvect 3;
        fs!:set!-coeff(aaa, simpint list(prepsq fs!:coeff x, u)); 
        fs!:set!-fn(aaa, fs!:fn x);
        fs!:set!-angle(aaa,fs!:angle x);
        fs!:set!-next(aaa, hint1(fs!:next x, u));
        return aaa
end;

symbolic procedure simphint uu;
begin scalar x, u;
    if not (length uu = 2) then
        rerror(fourier, 11, "Improper number of arguments to HINT");
    x := car uu; uu := cdr uu;
    u := car uu;
    x := simp x;
    if not eqcar(car x, '!:fs!:) then x := !*sq2fourier x ./ 1;
    if not harmonicp u then 
        return (get('fourier, 'tag) . hint1(cdar x, u)) ./ 1;
    x := hint(cdar x,get(u,'fourier!-angle));
    if null x then return nil ./ 1;
    return (get('fourier, 'tag) . x) ./ 1
end;

put('hint, 'simpfn, 'simphint);

initdmode 'fourier;

endmodule;

end;
