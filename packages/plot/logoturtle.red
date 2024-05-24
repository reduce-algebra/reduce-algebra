module logoturtle;   % Logo turtle graphics based on the plot package.

% Author: Francis Wright, May 2024

% LogoTurtle is a partial REDUCE emulation of traditional Logo turtle
% graphics (see https://en.wikipedia.org/wiki/Turtle_graphics) with
% one turtle, modelled on Berkeley Logo 6.2 by Brian Harvey (see
% http://people.eecs.berkeley.edu/~bh/logo.html).

% This package is inspired by and related to the Turtle package by
% Caroline Cotter (ZIB,Berlin, 1998), and the word "Turtle" below
% (with a capital T) will refer specifically to that package.  Both
% packages are built on the REDUCE plot package, which itself uses
% Gnuplot to display plots.  This means that plotting is not fully
% interactive; a plot is constructed invisibly and only displayed when
% requested.  This package aims to be more efficient, more authentic,
% potentially more interactive and more complete than Turtle.  The
% turtle itself is not displayed.  [But it could be!]  Command names
% are as in Berkeley Logo 6.2.

% LogoTurtle procedures other than queries return nothing (nil) and
% plotting is achieved via side effects, not via returned procedure
% values (unlike Turtle).  A plot is displayed by calling the
% (non-traditional) procedure draw, as for Turtle.  The plot displayed
% need not be complete; draw displays the plot constructed so far
% until it is explicitly cleared.

% Lowering the pen begins a "curve", namely a sequence of points
% connected by straight lines, and raising the pen ends that curve.
% Each time the pen is lowered and later raised produces a distinct
% curve.

% LogoTurtle uses Lisp floating-point numbers internally and does not
% require any particular REDUCE number domain settings, such as "on
% rounded", although using "on rounded" and the default or lower
% precision makes sense.

load_package gnuplot;

global '(
   logo!-turtle!-x!-coord!*     % turtle Cartesian x coordinate (float)
   logo!-turtle!-y!-coord!*     % turtle Cartesian y coordinate (float)
   logo!-turtle!-heading!*      % turtle heading (float)
   logo!-turtle!-pen!-down!*    % turtle pen down (boolean)
   logo!-turtle!-curve!*        % list of alg-mode points
   logo!-turtle!-plot!-list!*   % list of alg-mode curves
   );

logo!-turtle!-x!-coord!* := 0.0;
logo!-turtle!-y!-coord!* := 0.0;
logo!-turtle!-heading!* := 0.0;

% logo!-turtle!-plot!-list!* should be an algebraic-mode list of lists
% of lists; namely a list of "curves" (joined points) of the form
% {curve_1, curve_2, ...}, where curve_n is a list of points of the
% form {point_1, point_2, ...} and point_n is a list of real numbers
% of the form {x, y}.  A "curve" is a list of points that the turtle
% visits with the pen down.  Raising the pen and lowering it again
% starts a new "curve".

symbolic procedure draw variables;
   % Display the plot stored in each variable in the list variables
   % followed by the current plot.
   begin scalar plots :=
      if length logo!-turtle!-curve!* > 1 then
         % Do an implicit penup to include the last partial curve:
         makelist logo!-turtle!-curve!* . logo!-turtle!-plot!-list!*
      else logo!-turtle!-plot!-list!*;
      % Don't draw an empty plot:
      if variables or plots then <<
         plots := append(
            for each v in variables collect <<
               v := reval v;
               % Check each v is a list:
               if not eqcar(v, 'list) then
                  typerr(if eqcar(v,'!*sq) then
                     prepsq cadr v else v, "list");
               v >>, {makelist plots});
         ploteval
            append('((equal title "REDUCE Logo Turtle Plot")
               (equal xlabel "x") (equal ylabel "y")),
               cons(if 'psl memq lispsystem!*
               then '(equal !~size "ratio -1")
               else '(equal size "ratio -1"),
                  plots));
         % algebraic <<
         %    gnuplot(set, "title", """REDUCE Logo Turtle Plot""");
         %    gnuplot(set, "xlabel", """x""");
         %    gnuplot(set, "ylabel", """y""");
         %    gnuplot(set, "size", "square");
         %    gnuplot(plot, x*sin(x), "with lines", "linecolor rgb", """green""");
         %    plotshow;
         % >>;
      >>;
   end;

put('draw, 'psopfn, 'draw);

symbolic procedure logo!-turtle!-number n;
   % Convert N to a Lisp float provided it is a real general REDUCE
   % algebraic-mode number.
   if atom n then
      % integer, float (default number domain) or error
      (if numberp n then float n else typerr(n, "real number"))
   else if eqcar(n, 'quotient) then
      % quotient (default number domain)
      (float cadr n)/caddr n
   else if eqcar(n, '!:rd!:) then
      % rounded number domain
      (if floatp cdr n then cdr n else bf2flr n)
   else if eqcar(n, '!:rn!:) then
      % rational number domain
      (float cadr n)/cddr n
   else if eqcar(n, '!:mod!:) then
      % modular number domain
      float cdr n
   else typerr(n, "real number");


% Turtle Motion (all return nothing)
% ==================================

% Positive X is to the right; positive Y is up.  Distances are
% measured in "turtle steps".  Headings are angles measured in degrees
% (1/360 of a circle) CLOCKWISE FROM THE POSITIVE Y AXIS.  (Note that
% this differs from the common mathematical convention of measuring
% angles counterclockwise from the positive X axis, which is used by
% the Turtle package.)  Distances and angles are represented by real
% numbers.

symbolic procedure forward dist;        % fd dist
   % Move the turtle forward, in the direction that it's facing, by
   % the specified distance.
   logo!-turtle!-forward(+ logo!-turtle!-number dist);

symbolic operator forward;

symbolic procedure back dist;           % bk dist
   % Move the turtle backward, i.e., exactly opposite to the
   % direction that it's facing, by the specified distance. (The
   % heading of the turtle does not change.)
   logo!-turtle!-forward(- logo!-turtle!-number dist);

symbolic operator back;

symbolic procedure logo!-turtle!-forward dist;
   % Move the turtle forward, in the direction that it's facing, by
   % the specified distance, ASSUMED TO BE A LISP NUMBER!
   <<
      setxy(logo!-turtle!-x!-coord!* + dist * sind logo!-turtle!-heading!*,
         logo!-turtle!-y!-coord!* + dist * cosd logo!-turtle!-heading!*);
   >>;

symbolic procedure left degrees;        % lt degrees
   % Turn the turtle counterclockwise by the specified angle
   logo!-turtle!-right(- logo!-turtle!-number degrees);

symbolic operator left;

symbolic procedure right degrees;       % rt degrees
   % Turn the turtle clockwise by the specified angle.
   logo!-turtle!-right(+ logo!-turtle!-number degrees);

symbolic operator right;

symbolic procedure logo!-turtle!-right degrees;
   % Turn the turtle clockwise by the specified angle, ASSUMED TO BE A
   % LISP NUMBER!
   logo!-turtle!-setheading(logo!-turtle!-heading!* + degrees);

symbolic procedure setpos pos;
   % Move the turtle to an absolute position in the graphics window.
   % The input is a list of two numbers, the X and Y coordinates.
   apply('setxy, getrlist pos);

symbolic operator setpos;

symbolic procedure setxy(xcor, ycor);
   % Move the turtle to an absolute position in the graphics window.
   % The two inputs are numbers, the X and Y coordinates.
   logo!-turtle!-setxy(logo!-turtle!-number xcor, logo!-turtle!-number ycor);

symbolic operator setxy;

symbolic procedure logo!-turtle!-setxy(xcor, ycor);
   % Move the turtle to an absolute position in the graphics window.
   % The two inputs are numbers, the X and Y coordinates, ASSUMED TO
   % BE LISP NUMBERS!  This procedure ultimately handles all motion.
   <<
      if logo!-turtle!-pen!-down!* then
         logo!-turtle!-curve!* := {'list, xcor, ycor}
            . logo!-turtle!-curve!*;
      logo!-turtle!-x!-coord!* := xcor;
      logo!-turtle!-y!-coord!* := ycor;
   >>;

symbolic procedure setx xcor;
   % Move the turtle horizontally from its old position to a new
   % absolute horizontal coordinate.  The input is the new X
   % coordinate.
   logo!-turtle!-setxy(logo!-turtle!-number xcor, logo!-turtle!-y!-coord!*);

symbolic operator setx;

symbolic procedure sety ycor;
   % Move the turtle vertically from its old position to a new
   % absolute vertical coordinate.  The input is the new Y coordinate.
   logo!-turtle!-setxy(logo!-turtle!-x!-coord!*, logo!-turtle!-number ycor);

symbolic operator sety;

symbolic procedure setheading degrees;  % seth degrees
   % Turn the turtle to a new absolute heading.  The input is a number,
   % the heading in degrees clockwise from the positive Y axis.
   logo!-turtle!-setheading(logo!-turtle!-number degrees);

symbolic operator setheading;

symbolic procedure logo!-turtle!-setheading degrees;
   % Turn the turtle to a new absolute heading.  The input is a
   % number, the heading in degrees clockwise from the positive Y
   % axis, ASSUMED TO BE A LISP NUMBER!
   <<
      if degrees > 180.0 then
         while degrees > 180.0 do degrees := degrees - 360.0
      else if degrees <= -180.0 then
         while degrees <= -180.0 do degrees := degrees + 360.0;
      logo!-turtle!-heading!* := degrees;
   >>;

symbolic procedure home();
   % Move the turtle to the origin and set the heading to 0.
   % Equivalent to SETPOS {0, 0}; SETHEADING 0.
   <<
      logo!-turtle!-setxy(0.0, 0.0);
      logo!-turtle!-heading!* := 0.0;
   >>;

symbolic operator home;

% procedure arc(angle, radius);           % ???
   % Draw an arc of a circle, with the turtle at the center, with the
   % specified radius, starting at the turtle's heading and extending
   % clockwise through the specified angle. The turtle does not move.


% Turtle Motion Queries (all procedures return values)
% ====================================================

symbolic procedure pos();
   % Output the turtle's current position, as a list of two numbers,
   % the X and Y coordinates.
   {'list, logo!-turtle!-x!-coord!*, logo!-turtle!-y!-coord!* };

symbolic operator pos;

symbolic procedure xcor();
   % Output a number, the turtle's X coordinate.
   logo!-turtle!-x!-coord!*;

symbolic operator xcor;

symbolic procedure ycor();
   % Output a number, the turtle's Y coordinate.
   logo!-turtle!-y!-coord!*;

symbolic operator ycor;

symbolic procedure heading();
   % Output a number, the turtle's heading in degrees.
   logo!-turtle!-heading!*;

symbolic operator heading;

symbolic procedure towards pos;
   % Output a number, the heading at which the turtle should be facing
   % so that it would point from its current position to the position
   % (a list) given as the input.
   <<
      pos := getrlist pos;
      atan2d(logo!-turtle!-number car pos - logo!-turtle!-x!-coord!*,
         logo!-turtle!-number cadr pos - logo!-turtle!-y!-coord!*);
   >>;

symbolic operator towards;

% procedure scrunch;                      % ???
   % Output a list containing two numbers, the X and Y scrunch
   % factors, as used by SETSCRUNCH.  (But note that SETSCRUNCH takes
   % two numbers as inputs, not one list of numbers.)


% Turtle and Window Control (all return nothing)
% ==============================================

symbolic procedure clean();
   % Erase all lines that the turtle has drawn on the graphics window.
   % The turtle's state (position, heading, pen mode, etc.) is not
   % changed.  If the pen is down then start a new curve.
   <<
      logo!-turtle!-plot!-list!* := nil;
      logo!-turtle!-curve!* :=
         if logo!-turtle!-pen!-down!* then
            {{'list, logo!-turtle!-x!-coord!*, logo!-turtle!-y!-coord!*}};
   >>;

symbolic operator clean;

symbolic procedure clearscreen();       % cs;
   % Erase the graphics window and send the turtle to its initial
   % position and heading.  Like HOME and CLEAN together.
   <<
      plotreset; home(); clean();
   >>;

symbolic operator clearscreen;


% Pen and Background Control (all return nothing)
% ===============================================

% The turtle carries a pen that can draw pictures.  At any time the
% pen can be UP (in which case moving the turtle does not change
% what's on the graphics screen) or DOWN (in which case the turtle
% leaves a trace).  Initially, the pen is UP.

symbolic procedure pendown();           % pd
   % Set the pen's position to DOWN, without changing its mode.
   % Initialize a new curve.
   <<
      logo!-turtle!-curve!* :=
         {{'list, logo!-turtle!-x!-coord!*, logo!-turtle!-y!-coord!*}};
      logo!-turtle!-pen!-down!* := t;
   >>;

symbolic operator pendown;

symbolic procedure penup();             % pu
   % Set the pen's position to UP, without changing its mode.
   % Save the current curve.
   <<
      if length logo!-turtle!-curve!* > 1 then
         logo!-turtle!-plot!-list!* := makelist logo!-turtle!-curve!*
         . logo!-turtle!-plot!-list!*;
      logo!-turtle!-curve!* := nil;
      logo!-turtle!-pen!-down!* := nil;
   >>;

symbolic operator penup;

% procedure setpencolor colornumber_or_rgblist; % setpc colornumber_or_rgblist
   % Set the pen color to the given number, which must be a
   % nonnegative integer.  There are initial assignments for the first
   % 16 colors:

   % 0 black 1 blue 2 green 3 cyan
   % 4 red 5 magenta 6 yellow 7 white
   % 8 brown 9 tan 10 forest 11 aqua
   % 12 salmon 13 purple 14 orange 15 grey

   % but other colors can be assigned to numbers by the PALETTE
   % command. Alternatively, sets the pen color to the given RGB
   % values (a list of three nonnegative numbers less than 100
   % specifying the percent saturation of red, green, and blue in the
   % desired color).

% SETPALETTE colornumber rgblist
% sets the actual color corresponding to a given number, if allowed by the hardware and
% operating system. Colornumber must be an integer greater than or equal to 8. (Logo tries
% to keep the first 8 colors constant.) The second input is a list of three nonnegative numbers
% less than 100 specifying the percent saturation of red, green, and blue in the desired color.

% SETPENSIZE size
% sets the thickness of the pen. The input is either a single positive integer or a list of two
% positive integers (for horizontal and vertical thickness). Some versions pay no attention to
% the second number, but always have a square pen.

% SETBACKGROUND colornumber.or.rgblist
% SETBG colornumber.or.rgblist
% set the screen background color by slot number or RGB values. See SETPENCOLOR for details.


% Pen Queries (all procedures return values)
% ==========================================

symbolic procedure pendownp();
   % Output TRUE if the pen is down, FALSE if it's up.
   if logo!-turtle!-pen!-down!* then 'true else 'false;

symbolic operator pendownp;


% Saving and Loading Pictures (all return nothing)
% ================================================

% These two procedures are different from the Berkeley Logo commands
% with the same names in that they save to and load from REDUCE
% variables instead of files.  The values of the variables are REDUCE
% lists, which can be manipulated as usual.

symbolic procedure savepict variable;
   % Assign the current plot to the specified REDUCE variable.  The
   % current plot is not changed.  The saved plot can be restored as
   % the current plot using LOADPICT or displayed using DRAW.
   <<
      setk(variable, makelist if length logo!-turtle!-curve!* > 1 then
         % Do an implicit penup to include the last partial curve:
         makelist logo!-turtle!-curve!* . logo!-turtle!-plot!-list!*
      else logo!-turtle!-plot!-list!*);
   >>;

symbolic operator savepict;

symbolic procedure loadpict variable;
   % Reads a plot from the specified REDUCE variable, which must have
   % been assigned by a SAVEPICT command, and makes it the current
   % plot.  The previous current plot is lost if not saved using
   % SAVEPICT.
   <<
      logo!-turtle!-plot!-list!* := getrlist variable;
      logo!-turtle!-curve!* := nil;
   >>;

symbolic operator loadpict;

endmodule;

end;
