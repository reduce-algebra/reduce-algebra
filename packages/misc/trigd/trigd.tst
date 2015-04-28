% Simplification tests

{sind(0), cosd(0), tand(0), secd(0)};
{sind(180), cosd(180), tand(180),secd(180)};
{sind(360), cosd(360), tand(360),secd(360)};
{sind(90), cosd(90), cotd(90), cscd(90)};
{sind(270), cosd(270), cotd(270), cscd(270)};
{sind(450), cosd(450), cotd(450), cscd(450)};

l:=for j:=1:5 collect sind(15j);
asind l;
l:=for j:=1:5 collect cosd(15j);
acosd l;
l:=for j:=1:5 collect tand(15j);
atand l;
l:=for j:=1:5 collect cotd(15j);
acotd l;
l:=for j:=1:5 collect secd(15j);
asecd l;
l:=for j:=1:5 collect cscd(15j);
acscd l;

{sind(-a), cosd(-a), tand(-a), cotd(-a), cscd(-a), secd(-a)};

{sind(a+190), cosd(a+190), tand(a+190), cotd(a+190), cscd(a+190), secd(a+190)};
{sind(a+290), cosd(a+290), tand(a+290), cotd(a+290), cscd(a+290), secd(a+290)};
{sind(a-370), cosd(a-370), tand(a-370), cotd(a-370), cscd(a-370), secd(a-370)};
{sind(a-470), cosd(a-470), tand(a-470), cotd(a-470), cscd(a-470), secd(a-470)};

{sind(a+1500/7), cosd(a+1500/7), tand(a+1500/7), cotd(a+1500/7), cscd(a+1500/7), secd(a+1500/7)};
{sind(a+1900/7), cosd(a+1900/7), tand(a+1900/7), cotd(a+1900/7), cscd(a+1900/7), secd(a+1900/7)};

{sind(a+270), cosd(a+270), tand(a+270), cotd(a+270), cscd(a+270), secd(a+270)};
{sind(a+450), cosd(a+450), tand(a+450), cotd(a+450), cscd(a+450), secd(a+450)};

{asind(-a), acosd(-a), atand(-a), acotd(-a), acscd(-a), asecd(-a)};

{sind asind(-a), cosd acosd(-a), tand atand(-a), 
cotd acotd(-a), cscd acscd(-a), secd asecd(-a)};

{atan2d(1,0), atan2d(-1,0), atan2d(0, 1), atan2d(0, -1)};
{atan2d(1,1), atan2d(1,-1), atan2d(-1, 1), atan2d(-1, -1)};
atan2d(y^2, -x^2);

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


