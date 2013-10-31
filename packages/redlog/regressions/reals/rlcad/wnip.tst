% Example from a talk on Isabel by T. Nipkow
% Weak inequality version

rlset r;

wnip := rlall(a>=3/4 and a^2<=b*(c+1) and b<=4c impl (a-1)^2<b*c)$

rlcad wnip;

end;
