off exp; off mcd;
mrv_limit(e^x,x,infinity);

mrv_limit(e^-x,x,infinity);

mrv_limit(2^x,x,infinity);
mrv_limit(2^-x,x,infinity);

mrv_limit(log(x),x,infinity);

mrv_limit(1/log(x),x,infinity);

a:=e^(1/x-e^-x)-e^(1/x);
a:=a/e^(-x);
% Result is -1 (correct)
mrv_limit(a,x,infinity);

b:=e^x*(e^(1/x-e^-x)-e^(1/x));
% Result is -1 (correct)
mrv_limit(b,x,infinity);

%c:=e^x*(e^(1/x+e^(-x)+e^(-x^2))-e^(1/x-e^(-e^x)))
mrv_maxi1({e^(-x^2)},{e^x});

c:=e^x*(e^(1/x+e^(-x)+e^(-x^2))-e^(1/x-e^(-e^x)));

aa:=e^(e^(e^x));
% Result is infinity (correct)
mrv_limit(aa,x,infinity);

bb:=e^(e^(e^(x-e^(-e^x))));
% Result is infinity (correct only with on mcd)
mrv_limit(bb,x,infinity);

misc1:=1/(e^(-x+e^-x))-e^x;
% Result is -1 (correct)
mrv_limit(misc1,x,infinity);

misc2:=(e^(1/x-e^-x)-e^(1/x))/(e^-x);
% Result is -1 (correct)
mrv_limit(misc2,x,infinity);

misc3:=e^(-log(x+e^-x));
% Result is 0 (correct)
mrv_limit(misc3,x,infinity);

misc4:=e^(x-e^x);
% Result is 0 (correct)
mrv_limit(misc4,x,infinity);

% Example from section 3.5 of Gruntz' thesis, result is 0 (correct)
mrv_limit(log(log(x*e^(x*e^x)+1)) - exp(exp(log(log(x))+1/x)),x,infinity);

% Example from section 4.1.2 of Gruntz' thesis, result is 1 (correct)
mrv_limit(e^(1/x)-(e^(1/x)-1)/e^(1/x),x,infinity);

% Example from section 7.1 of Gruntz' thesis
% Should be 5, but doesn't work

% Example 8.1 from Gruntz' thesis, limit is -1 (correct)
ex1:=(e^x)*(e^((1/x)-e^(-x))-e^(1/x));
mrv_limit(ex1,x,infinity);

% Example 8.2 from Gruntz' thesis, limit is 1
ex2:=(e^x)*(e^((1/x)+e^(-x)+e^(-x^2))-e^((1/x)-e^(-e^x)));
%%% mrv_limit(ex2,x,infinity);

% Example 8.3 from Gruntz' thesis, limit is infinity
ex3:=e^(e^(x-e^(-x))/(1-1/x))-e^(e^x); % returns - infinity
%%% mrv_limit(ex3,x,infinity);

% Example 8.4 from Gruntz' thesis, limit is -infinity
ex4:=e^(e^((e^x)/(1-1/x)))-e^(e^((e^x)/(1-1/x-(log(x))^(-log(x)))));
%%% mrv_limit(ex4,x,infinity);

% Example 8.5 from Gruntz' thesis, limit is 0
ex5:=(e^(e^(e^(x+e^-x))))/(e^(e^(e^x)));
%%% mrv_limit(ex5,x,infinity);

% Example 8.6 from Gruntz' thesis, limit is infinity
ex6:=(e^(e^(e^x)))/(e^(e^(e^(x-e^(-e^x)))));
%%% mrv_limit(ex6,x,infinity);

% Example 8.7 from Gruntz' thesis, limit is 1
ex7:=(e^(e^(e^x)))/(e^(e^(e^(x-e^(-e^(e^x))))));
%%% mrv_limit(ex7,x,infinity);

% Example 8.8 from Gruntz' thesis, limit is 1
ex8:=(e^(e^x))/(e^(e^(x-e^(-e^(e^x)))));
%%% mrv_limit(ex8,x,infinity);

% Example 8.9 from Gruntz' thesis, limit is 0
ex9:=((log(x)^2)*e^(sqrt(log(x))*((log(log(x)))^2)*e^((sqrt(log(log(x))))*(log(log(log(x)))^3))))/sqrt(x);
%%% mrv_limit(ex9,x,infinity);

% Example 8.10 from Gruntz' thesis, limit is 1/3
ex10:=((x*log(x))*(log(x*e^x-x^2))^2)/(log(log(x^2+2*e^(3*x^3*log(x)))));
%%% mrv_limit(ex10,x,infinity);

% Example 8.11 from Gruntz' thesis, limit is -e^2
ex11:=(e^(x*e^x/(e^(-x)+e^(-2*x^2/(x+1))))-e^x)/x;
%%% mrv_limit(ex11,x,infinity);

% Example 8.12 from Gruntz' thesis, limit is 5
ex12:=(3^x+5^x)^(1/x);
%%% mrv_limit(ex12,x,infinity);

% Example 8.13 from Gruntz' thesis, limit is infinity (correct)
ex13:=x/log(x^((log(x))^(log(2)/log(x))));
mrv_limit(ex13,x,infinity);

% Example 8.14 from Gruntz' thesis, limit is infinity
ex14:=(e^(e^(2*log(x^5+x)*log(log(x)))))/(e^(e^(10*log(x)*log(log(x)))));
%%% mrv_limit(ex14,x,infinity);

% Example 8.15 from Gruntz' thesis, limit is infinity
ex15:=4/9*(exp(e^(5/2*x^(-5/7)+21/8*x^(6/11)+2*x^(-8)+54/17*x^(49/45)))^8)/(log(log(-log(4/3*x^(-5/14)))))^(7/6);
%%% mrv_limit(ex15,x,infinity);

% Example 8.16 from Gruntz' thesis, limit is 1
ex16:= (exp(4*x*e^(-x)/(1/e^x+1/exp(2*x^2/(x+1))))-e^x)/(e^x)^4;
mrv_limit(ex16,x,infinity);

% Example 8.17 from Gruntz' thesis, limit is 1 (correct)
ex17:=(exp((x*e^(-x))/(e^(-x)+e^(-2*x^2/(x+1)))))/e^x;
mrv_limit(ex17,x,infinity);

% Example 8.18 from Gruntz' thesis, limit is 2
ex18:=(e^(e^(-x/(1+e^(-x)))*e^(-x/(1+e^(-x/(1+e^(-x)))))*e^(-x+e^(-x/(1+e^(-x))))))/(e^(-x/(1+e^(-x))))^2;
%%% mrv_limit(ex18,x,infinity);

% Example 8.19 from Gruntz' thesis, limit is 1
ex19:=log(log(x)+log(log(x)))-log(log(x));
ex19:=ex/(log(log(x)+log(log(log(x)))));
ex19:=ex*log(x);
mrv_limit(ex19,x,infinity);

% Example 8.20 from Gruntz' thesis, limit is e (correct)
ex20:= e^(log(log(x+e^(log(x)*log(log(x)))))/log(log(log(e^x+x+log(x)))));
mrv_limit(ex20,x,infinity);

end;
