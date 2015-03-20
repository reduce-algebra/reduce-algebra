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

end;

