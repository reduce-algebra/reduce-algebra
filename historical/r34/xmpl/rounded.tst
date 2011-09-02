% Tests in the exact mode.

x := 1/2;

y := x + 0.7;

% Tests in approximate mode.

on rounded;

y;   % as expected not converted to approximate form.

z := y+1.2;

z/3;

% Let's raise this to a high power.

ws^24;

% Now a high exponent value.

% 10.2^821;

% Elementary function evaluation.

cos(pi);

symbolic ws;

z := sin(pi);

symbolic ws;

% Handling very small quantities.

% With normal defaults, underflows are converted to 0.

exp(-100000.1**2);

% However, if you really want that small number, roundbf can be used.

on roundbf;

exp(-100000.1**2);

off roundbf;

% Now let us evaluate pi.

pi;


% Let us try a higher precision.

precision 50;

pi;

% Now find the cosine of pi/6.

cos(ws/6);

% This should be the sqrt(3)/2.

ws**2;


%Here are some well known examples which show the power of this system.

precision 10;

% This should give the usual default again.

let xx=e**(pi*sqrt(163));

let yy=1-2*cos((6*log(2)+log(10005))/sqrt(163));

% First notice that xx looks like an integer.

xx;

% and that yy looks like zero.

yy;

% but of course it's an illusion.

precision 50;

xx;

yy;

%now let's look at an unusual way of finding an old friend;

precision 50;

procedure agm;
  <<a := 1$ b := 1/sqrt 2$ u:= 1/4$ x := 1$ pn := 4$ repeat
   <<p := pn;
     y := a; a := (a+b)/2; b := sqrt(y*b); % Arith-geom mean.
     u := u-x*(a-y)**2; x := 2*x; pn := a**2/u;
     write "pn=",pn>> until pn>=p; p>>;

let ag=agm();

ag;

% The limit is obviously.

pi;

end;
