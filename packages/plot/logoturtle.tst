% Test file for Logo turtle graphics.

% Author: Francis Wright, July 2024

% Part 1: Based on "turtle.tst" by Caroline Cotter, ZIB,Berlin, 1998
% ==================================================================

% The plots drawn by this part of the test file should be the same as
% those drawn by "turtle.tst" except that they are better labelled,
% use equally scaled axes by default, and are mirrored about the line
% y = x due to the different definition of heading.

% load_package logoturtle;

% No fixed window size and no constraints on where the turtle moves:
window false;

on rounded;

on demo;
% Each test is in its own group statement so that demo mode makes
% sense.

% 1) Draw 36 rays of length 100
% (Taken from MapleTech -- Maple in Mathematics and the Sciences,
% Special Issue 1994)

<<
   clearscreen();
   for i := 1 : 36 do <<
      setheading(i*10); pendown(); forward 100; penup(); back 100;
   >>;
   draw();
>>;


% 2) Draw a "fan" of 36 straight spikes.

<<
   clearscreen();
   for i := 1 : 36 do <<
      setheading(i*10); pendown(); forward 100; penup(); back 95;
   >>;
   draw();
>>;


% 3) Draw a "fan" of 36 curved rays.

<<
   clearscreen();
   for i := 1 : 36 do <<
      setheading(i*10); pendown();
      for j := 1 : 4 do << forward 20; left 20; >>; forward 20;
      penup();
      for j := 1 : 4 do << back 20; right 20; >>; back 18;
   >>;
   draw();
>>;


% 4) Draw 12 regular polygons with 12 sides of length 40, each polygon
% forming an angle of 360/n degrees with the previous one.
% (Taken from MapleTech -- Maple in Mathematics and the Sciences,
% Special Issue 1994)

<<
   clearscreen(); pendown();
   for i := 1 : 12 do <<
      left 30;
      for j := 1 : 12 do << forward 40, left 30; >>;
   >>;
   draw();
>>;


% 5) A "peak" pattern.

<<
procedure peak(r);
   for i := 0 : r do <<
      setpos{xcor() + 5,  ycor() - 10};
      setpos{xcor() + 10, ycor() + 60};
      setpos{xcor() + 10, ycor() - 60};
      setpos{xcor() + 5,  ycor() + 10};
   >>;

clearscreen(); pendown(); peak 3;
draw();
>>;

% This procedure can then be part of a longer chain of commands:

<<
   clearscreen(); pendown();
   setpos{5, 50}; peak(3);
   setpos{xcor() + 10, -100};
   peak(2); setpos{xcor() + 10, 0};
   draw();
>>;


% 6) Write a recursive procedure which draws "trees" such that every
% branch is half the length of the previous branch.
% (Taken from MapleTech -- Maple in Mathematics and the Sciences,
% Special Issue 1994)

<<
procedure tree(a, b);
   % a is the start length, b is the number of levels.
   % Check b is a positive integer.
   if fixp b and b > 0 then <<
      left(45); forward a; tree(a/2, b-1);
      back a; right(90); forward a; tree(a/2, b-1);
      back a; left(45);
   >>;

clearscreen(); pendown(); tree(130, 7);
draw();
>>;

% This can be rotated so that the tree grows to the right:

<<
   clearscreen(); setheading(90); pendown(); tree(130, 7);
   draw();
>>;


% 7) A 36-point star.

<<
   clearscreen(); pendown();
   for i := 1 : 36 do <<
      left(10); forward 100; left(10); back 100;
   >>;
   draw();
>>;


% 8) Draw 100 equilateral triangles with the leading points equally
% spaced on a circular path.

<<
   clearscreen();
   for i := 1 : 100 do <<
      pendown();
      forward 150; right(60); back(150); right(60); forward 150;
      penup(); setheading(i*3.6);
   >>;
   draw();
>>;


% 9) Plots can be saved to and later loaded from REDUCE variables or
% displayed as distinct plots; this example illustrates various ways
% to display two previous plots superimposed.

<<
   % Graph 4 again:
   clearscreen(); pendown();
   for i := 1 : 12 do <<
      left(30); for j := 1 : 12 do << forward 40; left(30); >>;
   >>;
   penup();
   savepict gr4;

   % Graph 8 again:
   clearscreen();
   for i := 1 : 100 do <<
      pendown();
      forward 150; right(60); back(150); right(60); forward 150;
      penup(); setheading(i*3.6);
   >>;

   % Draw gr4 and the current plot together.
   draw(gr4);
>>;

<<
   % Save and clear the current plot.
   savepict gr8;
   clearscreen();
   % Then plot gr4 and gr8 together.
   % The result should be the same as previously.
   draw(gr4, gr8);
>>;

<<
   % Note that there is no current plot, so nothing is displayed:
   plotreset;
   draw();
>>;

<<
   % Load gr8 as current plot.
   loadpict gr8;
   % Again, draw gr4 and the current plot together.
   % The result should be the same as previously.
   draw(gr4);
>>;


% Part 2: Facilities not provided by the Turtle package
% =====================================================

% Turtle and Window Control (plus Arc etc.)
% -----------------------------------------

% Wrap two long straight lines around the default window size.

<<
   wrap();
   clearscreen();
   pendown(); setheading(60); forward 1000; penup();
   home();
   pendown(); setheading(-30); forward 1000; penup();
   draw();
>>;

% Two arcs and show the turtle.

<<
   clearscreen(); penup();
   arc(180, 50); setheading 180; arc(180, 100);
   setheading 45; forward 25;
   showturtle(); draw(); hideturtle();
>>;

% Two arcs clipped to a smaller window size and show the turtle.  No
% error message because the turtle does not move outside the fence.

<<
   fence 75;
   clearscreen(); penup();
   arc(180, 50); setheading 180; arc(180, 100);
   setheading 45; forward 25;
   showturtle(); draw(); hideturtle(); window 100;
>>;

% Pen and Background Control
% --------------------------

% An equilateral triangle with side length 100 centred on the origin,
% with one vertex on the positive Y axis.  The sides are coloured red,
% green and blue, and have thicknesses 1, 2 and 3.

<<
   clearscreen(); penup(); setpensize false;
   on rounded;
   forward(100/sqrt 3); pendown();
   setpencolor "red"; right 150; forward 100;
   setpencolor "green"; setpensize 2; right 120; forward 100;
   setpencolor "blue"; setpensize 3; right 120; forward 100;
   setpensize false; draw();
>>;

% 16 rays of length 100 using all 16 predefined colours in sequence
% within a circle in the default colour.  (Note that the white ray is
% not visible against the white background!)

begin scalar delta;
   on rounded; delta := 360/16;
   clearscreen(); penup();
   for i := 0 : 15 do <<
      setheading(i*delta); setpencolor i;
      pendown(); forward 100; penup(); home();
   >>;
   setpencolor false; circle(100);
   draw();
end;

% As above, but with a grey background.  (Now the grey ray is not
% visible against the grey background!)

begin scalar delta;
   on rounded; delta := 360/16;
   clearscreen(); setbackground grey;
   for i := 0 : 15 do <<
      setheading(i*delta); setpencolor i;
      pendown(); forward 100; penup(); home();
   >>;
   setpencolor false; circle(100);
   draw(); setbackground false;
end;

% As above, but with default colour:

begin scalar delta;
   on rounded; delta := 360/16;
   clearscreen();
   for i := 0 : 15 do <<
      setheading(i*delta);
      pendown(); forward 100; penup(); home();
   >>;
   arc(360, 100);
   draw();
end;

% Coloured circles and arcs drawn clockwise and outer coloured arcs
% drawn counter-clockwise.  These arcs do not use the pen and the
% turtle does not move, although it rotates.

<<
   clearscreen(); penup();
   setpencolor red; circle(10); arc(90, 50); right 90;
   setpencolor blue; circle(20); arc(90, 50); right 90;
   setpencolor green; circle(30); arc(90, 50); right 90;
   setpencolor black; circle(40); arc(90, 50); right 90;
   setpencolor red; arc(-90, 60); left 90;
   setpencolor blue; arc(-90, 60); left 90;
   setpencolor green; arc(-90, 60); left 90;
   setpencolor black; arc(-90, 60); left 90;
   setpencolor false; draw();
>>;

% Inner square with rounded corners drawn clockwise and
% outer square with rounded corners drawn counter-clockwise:

<<
   clearscreen(); penup();
   setxy(-20, 40); setheading 90; pendown();
   for i := 1:4 do << forward 40; arc2(90, 20); >>;
   penup();
   setxy(40, 80); setheading(-90); pendown();
   for i := 1:4 do << forward 80; arc2(-90, 40); >>;
   penup(); draw();
>>;

end;
