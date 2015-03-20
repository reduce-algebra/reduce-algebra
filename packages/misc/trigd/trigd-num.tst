% Numerical tests
on rounded;
reslist := {sind(40), cosd(40), tand(40), cotd(40), secd(40), cscd(40)};

% Checks
t:= third reslist$
(first reslist)^2 + (second reslist)^2;
first reslist -t/sqrt(1+t^2);
sind(80)-2t/(1+t^2);
atand(t);    

{atand(1), atand(sqrt 3), atand(sqrt 2-1), acotd(-2), asecd(-2/sqrt(3))};
{atand(1), atand(sqrt 3), atand(sqrt 2-1), acotd 2, acotd(-2),  
acotd(2)+acotd(-2), asecd(-2/sqrt(3))};

reslist := {atan2d(sqrt 3-1, sqrt 3+1), atan2d( -(1+sqrt 3), 1-sqrt 3)};
sind(second reslist)+ sqrt(2)/4*(sqrt 3+1);

{argd(2.1), argd(-1)};

{sind(40+i), atand(1+i), asind(2), asecd(1/2)};  % not evaluated
{argd(1+i), argd(-1-i), argd(1-sqrt(3)*i)}; % not evaluated
atan2d(1+i, 1-i);   % not evaluated

on complex;

{sind(40+i), atand(1+i), asind(2), asecd(1/2)}; 
{argd(1+i), argd(-1-i), argd(1-sqrt(3)*i)}; 

reslist := {acotd(3i), acotd(-3i), atand(3i)};
first reslist + second reslist-180;
90-third reslist-first reslist;

reslist := {acotd(0.3i), acotd(-0.3i), atand(0.3i)};
first reslist + second reslist-180;
90-third reslist-first reslist;

off complex;
precision 50;

reslist := {sind(40), cosd(40), tand(40), cotd(40), secd(40), cscd(40)};

% Checks
t:= third reslist$
(first reslist)^2 + (second reslist)^2;
first reslist -t/sqrt(1+t^2);
sind(80)-2t/(1+t^2);
atand(t); 

{atand(1), atand(sqrt 3), atand(sqrt 2-1), acotd 2, acotd(-2), 
 acotd(2)+acotd(-2), asecd(-2/sqrt(3))};

{argd(2.1), argd(-1)};

{sind(40+i), atand(1+i), asind(2), asecd(1/2)};  % not evaluated
{argd(1+i), argd(-1-i), argd(1-sqrt(3)*i)}; % not evaluated
atan2d(1+i, 1-i);   % not evaluated

on complex;

{sind(40+i), atand(1+i), asind(2), asecd(1/2)}; 
{argd(1+i), argd(-1-i), argd(1-sqrt(3)*i)}; 

reslist := {acotd(3i), acotd(-3i), atand(3i)};
first reslist + second reslist-180;
90-third reslist-first reslist;

reslist := {acotd(0.3i), acotd(-0.3i), atand(0.3i)};
first reslist + second reslist-180;
90-third reslist-first reslist;

% atan2d(1+i, 1-i);   % should cause an error obviously!
precision 12;
% atan2d(1+i, 1-i);   % would cause error

off complex, rounded;
end;