%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Test file for IEEE non-finite arguments to basic functions
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic;

comment Create floats for +/-inf and NaN;

!+inf := 1.0 / 0.0;

!-inf := - !+inf;

!!NaN := !+inf - !+inf;

float !+inf;
float !-inf;
float !!NaN;

on echo;

write "Testing sqrt"$
sqrt !+inf;
sqrt !-inf;
sqrt !!NaN;
sqrt 0;
sqrt(-1);

write "Testing cbrt"$
cbrt !+inf;
cbrt !-inf;
cbrt !!NaN;
cbrt 0;
cbrt(-1);

write "Testing hypot"$
hypot(0,0);
hypot(1,1);
hypot(!+inf,1);
hypot(-1,!-inf);;
hypot(!!NaN,!!NaN);;

write "Testing floor"$
floor !+inf;
floor !-inf;
floor !!NaN;
floor 0;
floor(-1);
floor(1.5);
floor(-1.5);

write "Testing ceiling"$
ceiling !+inf;
ceiling !-inf;
ceiling !!NaN;
ceiling 0;
ceiling(-1);
ceiling(1.5);
ceiling(-1.5);

write "Testing round"$
round !+inf;
round !-inf;
round !!NaN;
round 0;
round(-1);
round(1.5);
round(-1.5);

write "Testing log"$
log !+inf;
log !-inf;
log !!NaN;
log 0;
log(-1);
log(1.5);
log(-1.5);

write "Testing atan"$
atan !+inf;
atan !-inf;
atan !!NaN;
atan 0;
atan(-1);
atan(1.5);
atan(-1.5);

write "Testing atand"$
atand !+inf;
atand !-inf;
atand !!NaN;
atand 0;
atand(-1);
atand(1.5);
atand(-1.5);

write "Testing sin"$
sin !+inf;
sin !-inf;
sin !!NaN;
sin 0;
sin(-1);
sin(1.5);
sin(-1.5);

write "Testing sind"$
sind !+inf;
sind !-inf;
sind !!NaN;
sind 0;
sind(-1);
sind(1.5);
sind(-1.5);

write "Testing tan"$
tan !+inf;
tan !-inf;
tan !!NaN;
tan 0;
tan(-1);
tan(1.5);
tan(-1.5);

write "Testing tand"$
tand !+inf;
tand !-inf;
tand !!NaN;
tand 0;
tand(-1);
tand(1.5);
tand(-1.5);

write "Testing sinh"$
sinh !+inf;
sinh !-inf;
sinh !!NaN;
sinh 0;
sinh(-1);
sinh(1.5);
sinh(-1.5);

write "Testing exp"$
exp !+inf;
exp !-inf;
exp !!NaN;
exp 0;
exp(-1);
exp(1.5);
exp(-1.5);

%expt

end;


