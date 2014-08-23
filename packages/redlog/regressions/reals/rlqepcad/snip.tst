% Example from a talk on Isabel by T. Nipkow
% Strict inequality version

rlset r;

load_package qepcad;

rlrndseed 17;

snip := rlall(a>3/4 and a^2<=b*(c+1) and b<=4c impl (a-1)^2<b*c)$

rlqepcad snip;

end;
