% Homage to Mondrian using Logo Turtle Graphics.

% Author: Francis Wright, August 2024

% $Id:$

% See "Head" by Piet Mondrian
% https://www.artchive.com/artwork/head-piet-mondrian/

load_package logoturtle;

setwindowsize(100, 60);
setlabelfont("Old English Text MT", 60);
setxy(-50, 0);
label("Mondrian");

width := 10;

procedure horizontal(colour, y);
   % Draw a horizonal stripe with specified y coord at the bottom.
   <<
      setxy(-100, y);
      filled(colour, setx(100), sety(y + width), setx(-100))
   >>;

procedure vertical(colour, x);
   % Draw a vertical stripe with specified x coord at the left.
   <<
      setxy(x, 60);
      filled(colour, sety(-60), setx(x + width), sety(60))
   >>;

horizontal(blue, 0);
vertical(blue, -70);
horizontal(yellow, 15);
horizontal(red, 40);
vertical(yellow, -90);
vertical(yellow, -50);
vertical(red, 50);
horizontal(yellow, -60);
vertical(yellow, 90);

draw;

;end;
