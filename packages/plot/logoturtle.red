module logoturtle;   % Logo turtle graphics based on the plot package.

% Author: Francis Wright, June 2024

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
% more interactive and more complete than Turtle.  Command names are
% as in Berkeley Logo 6.2.

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

switch trlogoturtle;
% If on then output internal data from draw and logoturtle!-setxy.

fluid '(
   logoturtle!-x!-coord!*   % turtle Cartesian x coordinate (float)
   logoturtle!-y!-coord!*   % turtle Cartesian y coordinate (float)
   logoturtle!-heading!*    % turtle heading (float)
   !*logoturtle!-pen!-down  % turtle pen down (boolean)
   logoturtle!-curve!*      % list of alg-mode points
   );

global '(
   logoturtle!-plot!-list!* % list of alg-mode curves
   logoturtle!-win!-mode!*  % wrap, window, fence, or nil
   logoturtle!-x!-max!*     % -x!-max!* <= x <= x!-max!* (float)
   logoturtle!-y!-max!*     % -y!-max!* <= y <= y!-max!* (float)
   !*logoturtle!-shown      % turtle shown (boolean)
   logoturtle!-rel!-len!*   % turtle length relative to window (float)
   logoturtle!-angle!*      % turtle head half-angle (float)
   );

logoturtle!-x!-coord!*  := 0.0;
logoturtle!-y!-coord!*  := 0.0;
logoturtle!-heading!*   := 0.0;
logoturtle!-win!-mode!* := 'wrap;
logoturtle!-x!-max!*    := 100.0;
logoturtle!-y!-max!*    := 100.0;
logoturtle!-rel!-len!*  := 0.1;
logoturtle!-angle!*     := 10.0;

% logoturtle!-plot!-list!* should be an algebraic-mode list of lists
% of lists; namely a list of "curves" (joined points) of the form
% {curve_1, curve_2, ...}, where curve_n is a list of points of the
% form {point_1, point_2, ...} and point_n is a list of real numbers
% of the form {x, y}.  A "curve" is a list of points that the turtle
% visits with the pen down.  Raising the pen and lowering it again
% starts a new "curve".

symbolic procedure draw variables;
   % Display the plot stored in each variable in the list variables
   % followed by the current plot.  Optionally, display the turtle.
   begin scalar plots :=
      if length logoturtle!-curve!* > 1 then
         % Do an implicit penup to include the last partial curve:
         makelist logoturtle!-curve!* . logoturtle!-plot!-list!*
      else logoturtle!-plot!-list!*;
      if !*trlogoturtle then mathprint makelist plots;
      % Don't draw an empty plot:
      if variables or plots then <<
         plots :=                       % list of alg-mode lists
         append(
            for each v in variables collect <<
               v := reval v;
               % Check each v is a list:
               if not eqcar(v, 'list) then
                  typerr(if eqcar(v,'!*sq) then
                     prepsq cadr v else v, "list");
               v >>, plots and {makelist plots});
         if !*logoturtle!-shown and logoturtle!-win!-mode!* then
            plots := logoturtle!-show!-turtle() . plots;
         % Below is essentially the body of ploteval in "plotsynt.red":
         bye!-actions!* := union('((plotreset)), bye!-actions!*);
         gp!-init();
         plotprin2lt '("set title ""REDUCE Logo Turtle Plot""");
         plotprin2lt '("set xlabel ""x""");
         plotprin2lt '("set ylabel ""y""");
         if logoturtle!-win!-mode!* then <<
            plotprin2lt {"set xrange [", -logoturtle!-x!-max!*, ":",
               logoturtle!-x!-max!*, "]"};
            plotprin2lt {"set yrange [", -logoturtle!-y!-max!*, ":",
               logoturtle!-y!-max!*, "]"};
         >>;
         plotprin2lt '("set size ratio -1");
         plotprin2lt '("unset key");
         begin scalar m, !*exp;
            m := plotrounded(nil);
            % ploteval0 plot; -- plot is an alg-mode list
            plots := reversip for each plot in plots collect
               cadr (plotpoints cdr plot);
            plotrounded(m);
         end;
         % ploteval2x('x, 'points) calls
         % gp!-2exp(plot!-2exp, 'x, 'points, nil, plots);
         begin scalar many;             % t if more than one plot
            plotprin2 "plot ";
            foreach plot in plots do <<
               if many then plotprin2lt '(",\");
               plotprin2 "'"; plotprin2 plot; plotprin2 "'";
               plotprin2 " with lines"; % " linecolor rgb ""green"""
               many := t;
            >>;
            plotterpri();
         end;
         gp!-show();
      >>;
   end;

put('draw, 'psopfn, 'draw);

symbolic procedure logoturtle!-show!-turtle();
   % The turtle is represented as an isoceles triangle; the actual
   % turtle position is at the midpoint of the base (the short side).
   % However, the turtle is drawn one step behind its actual position,
   % so that the display of the base of the turtle's triangle does not
   % obscure a line drawn perpendicular to it (as would happen after
   % drawing a square).
   (begin scalar !*logoturtle!-pen!-down, logoturtle!-curve!*,
         length := logoturtle!-rel!-len!* *
         (logoturtle!-x!-max!* + logoturtle!-y!-max!*) / 2.0,
         side := length / cosd logoturtle!-angle!*,
         base := 2.0 * length * tand logoturtle!-angle!*,
         baseangle := 90.0 - logoturtle!-angle!*;
      logoturtle!-forward(length-1); pendown();
      logoturtle!-right(logoturtle!-angle!*); logoturtle!-forward(-side);
      logoturtle!-right(baseangle); logoturtle!-forward(base);
      logoturtle!-right(baseangle); logoturtle!-forward(-side);
      return makelist logoturtle!-curve!*;
   end) where
      logoturtle!-x!-coord!* = logoturtle!-x!-coord!*,
      logoturtle!-y!-coord!* = logoturtle!-y!-coord!*,
      logoturtle!-heading!* = logoturtle!-heading!*;

symbolic procedure logoturtle!-number n;
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

% LogoTurtle attempts to scale the graphics window so that (by
% default) turtle coordinates (-100, -100) and (100, 100) fit (but the
% size can be changed), and so that the aspect ratio is 1:1.  The
% center of the graphics window is turtle location (0, 0), i.e. the
% origin or home.  Positive X is to the right; positive Y is up.
% Distances are measured in "turtle steps".  Headings are angles
% measured in degrees (1/360 of a circle) CLOCKWISE FROM THE POSITIVE
% Y AXIS.  (Note that this differs from the common mathematical
% convention of measuring angles counterclockwise from the positive X
% axis, which is used by the Turtle package.)  Distances and angles
% are represented by real numbers.

symbolic procedure forward dist;        % fd dist
   % Move the turtle forward, in the direction that it's facing, by
   % the specified distance.
   logoturtle!-forward(+ logoturtle!-number dist);

symbolic operator forward;

symbolic procedure back dist;           % bk dist
   % Move the turtle backward, i.e., exactly opposite to the
   % direction that it's facing, by the specified distance. (The
   % heading of the turtle does not change.)
   logoturtle!-forward(- logoturtle!-number dist);

symbolic operator back;

symbolic procedure logoturtle!-forward dist;
   % Move the turtle forward, in the direction that it's facing, by
   % the specified distance, ASSUMED TO BE A LISP NUMBER!
   <<
      logoturtle!-setxy(logoturtle!-x!-coord!* + dist * sind logoturtle!-heading!*,
         logoturtle!-y!-coord!* + dist * cosd logoturtle!-heading!*);
   >>;

symbolic procedure left degrees;        % lt degrees
   % Turn the turtle counterclockwise by the specified angle
   logoturtle!-right(- logoturtle!-number degrees);

symbolic operator left;

symbolic procedure right degrees;       % rt degrees
   % Turn the turtle clockwise by the specified angle.
   logoturtle!-right(+ logoturtle!-number degrees);

symbolic operator right;

symbolic procedure logoturtle!-right degrees;
   % Turn the turtle clockwise by the specified angle, ASSUMED TO BE A
   % LISP NUMBER!
   logoturtle!-setheading(logoturtle!-heading!* + degrees);

symbolic procedure setpos pos;
   % Move the turtle to an absolute position in the graphics window.
   % The input is a list of two numbers, the X and Y coordinates.
   apply('setxy, getrlist pos);

symbolic operator setpos;

symbolic procedure setxy(xcor, ycor);
   % Move the turtle to an absolute position in the graphics window.
   % The two inputs are numbers, the X and Y coordinates.
   logoturtle!-setxy(logoturtle!-number xcor, logoturtle!-number ycor);

symbolic operator setxy;

symbolic procedure logoturtle!-setxy(xcor, ycor);
   % Move the turtle to an absolute position in the graphics window.
   % The two inputs are numbers, the X and Y coordinates, ASSUMED TO
   % BE LISP NUMBERS!  This procedure ultimately handles all motion.
   begin scalar newxcor := xcor, newycor := ycor, newx, newy;
      if !*trlogoturtle then << terpri();
         prin2 if !*logoturtle!-pen!-down then "draw" else "move";
         prin2 " from ("; prin2 logoturtle!-x!-coord!*;
         prin2 ", "; prin2 logoturtle!-y!-coord!*;
         prin2 ") to ("; prin2 xcor; prin2 ", "; prin2 ycor; prin2t ")";
      >>;
      if logoturtle!-win!-mode!* memq '(fence wrap) then
      begin
         % Does turtle cross right or left window boundary?
         if xcor > logoturtle!-x!-max!* then <<
            newx := logoturtle!-x!-max!*;
         >> else if xcor < -logoturtle!-x!-max!* then <<
            newx := -logoturtle!-x!-max!*;
         >>;
         if newx then <<
            newycor := logoturtle!-y!-coord!* +
            (ycor - logoturtle!-y!-coord!*)/
            (xcor - logoturtle!-x!-coord!*) * (newx - logoturtle!-x!-coord!*);
            % Is crossing between top and bottom boundary?
            if newycor <= logoturtle!-y!-max!* and
               newycor >= -logoturtle!-y!-max!* then
                  return (newxcor := newx);
            newx := nil;
            newycor := ycor;
         >>;
         % Does turtle cross top or bottom window boundary?
         if ycor > logoturtle!-y!-max!* then <<
            newy := logoturtle!-y!-max!*;
         >> else if ycor < -logoturtle!-y!-max!* then <<
            newy := -logoturtle!-y!-max!*;
         >>;
         if newy then <<
            newxcor := logoturtle!-x!-coord!* +
            (xcor - logoturtle!-x!-coord!*)/
            (ycor - logoturtle!-y!-coord!*) * (newy - logoturtle!-y!-coord!*);
            newycor := newy;
         >>;
      end;

      if logoturtle!-win!-mode!* eq 'fence and (newx or newy) then
         write "Turtle out of bounds!";

      if !*logoturtle!-pen!-down then
         logoturtle!-curve!* := {'list, newxcor, newycor}
            . logoturtle!-curve!*;
      logoturtle!-x!-coord!* := newxcor;
      logoturtle!-y!-coord!* := newycor;

      if logoturtle!-win!-mode!* eq 'wrap then <<
         % Call logoturtle!-setxy recursively:
         if newx then <<
            if !*logoturtle!-pen!-down then <<
               logoturtle!-save!-curve(); % implicit pen up
               logoturtle!-x!-coord!* := newxcor - 2*newx;
               logoturtle!-new!-curve(); % implicit pen down
            >> else
               logoturtle!-x!-coord!* := newxcor - 2*newx;
            logoturtle!-setxy(xcor - 2*newx, ycor);
         >> else if newy then <<
            if !*logoturtle!-pen!-down then <<
               logoturtle!-save!-curve(); % implicit pen up
               logoturtle!-y!-coord!* := newycor - 2*newy;
               logoturtle!-new!-curve(); % implicit pen down
            >> else
               logoturtle!-y!-coord!* := newycor - 2*newy;
            logoturtle!-setxy(xcor, ycor - 2*newy);
         >>;
      >>;
   end;

symbolic procedure setx xcor;
   % Move the turtle horizontally from its old position to a new
   % absolute horizontal coordinate.  The input is the new X
   % coordinate.
   logoturtle!-setxy(logoturtle!-number xcor, logoturtle!-y!-coord!*);

symbolic operator setx;

symbolic procedure sety ycor;
   % Move the turtle vertically from its old position to a new
   % absolute vertical coordinate.  The input is the new Y coordinate.
   logoturtle!-setxy(logoturtle!-x!-coord!*, logoturtle!-number ycor);

symbolic operator sety;

symbolic procedure setheading degrees;  % seth degrees
   % Turn the turtle to a new absolute heading.  The input is a number,
   % the heading in degrees clockwise from the positive Y axis.
   logoturtle!-setheading(logoturtle!-number degrees);

symbolic operator setheading;

symbolic procedure logoturtle!-setheading degrees;
   % Turn the turtle to a new absolute heading.  The input is a
   % number, the heading in degrees clockwise from the positive Y
   % axis, ASSUMED TO BE A LISP NUMBER!
   <<
      if degrees > 180.0 then
         while degrees > 180.0 do degrees := degrees - 360.0
      else if degrees <= -180.0 then
         while degrees <= -180.0 do degrees := degrees + 360.0;
      logoturtle!-heading!* := degrees;
   >>;

symbolic procedure home();
   % Move the turtle to the origin and set the heading to 0.
   % Equivalent to SETPOS {0, 0}; SETHEADING 0.
   <<
      logoturtle!-setxy(0.0, 0.0);
      logoturtle!-heading!* := 0.0;
   >>;

symbolic operator home;

symbolic procedure arc(angle, radius);
   % Draw an arc of a circle, with the turtle at the center, with the
   % specified radius, starting at the turtle's heading and extending
   % clockwise through the specified angle. The turtle does not move.
   begin scalar nsteps, h, delta, curve;
      angle := deg2rad angle;           % angle subtended in radians
      nsteps := fix(10.0*angle);        % arcstep = radius/10.0
      h := deg2rad heading();           % heading in radians
      delta := angle/nsteps;
      curve := for n := 0 : nsteps collect
         begin scalar a := h + n*delta;
            return {'list,
               logoturtle!-x!-coord!* + radius*sin(a),
               logoturtle!-y!-coord!* + radius*cos(a)}
         end;
      logoturtle!-plot!-list!* :=
         makelist curve . logoturtle!-plot!-list!*;
   end;

symbolic operator arc;


% Turtle Motion Queries (all procedures return values)
% ====================================================

symbolic procedure pos();
   % Output the turtle's current position, as a list of two numbers,
   % the X and Y coordinates.
   {'list, logoturtle!-x!-coord!*, logoturtle!-y!-coord!* };

symbolic operator pos;

symbolic procedure xcor();
   % Output a number, the turtle's X coordinate.
   logoturtle!-x!-coord!*;

symbolic operator xcor;

symbolic procedure ycor();
   % Output a number, the turtle's Y coordinate.
   logoturtle!-y!-coord!*;

symbolic operator ycor;

symbolic procedure heading();
   % Output a number, the turtle's heading in degrees.
   logoturtle!-heading!*;

symbolic operator heading;

symbolic procedure towards pos;
   % Output a number, the heading at which the turtle should be facing
   % so that it would point from its current position to the position
   % (a list) given as the input.
   <<
      pos := getrlist pos;
      atan2d(logoturtle!-number car pos - logoturtle!-x!-coord!*,
         logoturtle!-number cadr pos - logoturtle!-y!-coord!*);
   >>;

symbolic operator towards;

% procedure scrunch;                      % ???
   % Output a list containing two numbers, the X and Y scrunch
   % factors, as used by SETSCRUNCH.  (But note that SETSCRUNCH takes
   % two numbers as inputs, not one list of numbers.)


% Turtle and Window Control (all return nothing)
% ==============================================

symbolic procedure showturtle();        % st
   % Make the turtle visible.
   <<
      !*logoturtle!-shown := t;
   >>;

symbolic operator showturtle;

symbolic procedure hideturtle();        % ht
   %% Make the turtle invisible.
   <<
      !*logoturtle!-shown := nil;
   >>;

symbolic operator hideturtle;

symbolic procedure clean();
   % Erase all lines that the turtle has drawn on the graphics window.
   % The turtle's state (position, heading, pen mode, etc.) is not
   % changed.  If the pen is down then start a new curve.
   <<
      logoturtle!-plot!-list!* := nil;
      logoturtle!-curve!* :=
         if !*logoturtle!-pen!-down then
            {{'list, logoturtle!-x!-coord!*, logoturtle!-y!-coord!*}};
   >>;

symbolic operator clean;

symbolic procedure clearscreen();       % cs;
   % Erase the graphics window and send the turtle to its initial
   % position and heading.  Like HOME and CLEAN together.
   <<
      plotreset; home(); clean();
   >>;

symbolic operator clearscreen;

% As an extension to Berkeley Logo, the LogoTurtle commands WRAP,
% WINDOW and FENCE accept zero, one or two arguments: if the single
% argument is FALSE then no window mode is set, meaning that (like
% Turtle) LogoTurtle does not use a fixed window size and there are no
% constraints on where the turtle draws; otherwise a window mode is
% set.  If there is a single numerical argument N then the size of the
% graphics window is set to -|N| <= x,y <= |N|; if there are two
% numerical arguments M, N then the size of the graphics window is set
% to -|M| <= x <= |M|, -|N| <= y <= |N|.

symbolic procedure logoturtle!-win!-mode(mode, args);
   begin scalar l, m, n;
      if null args then <<
         logoturtle!-win!-mode!* := mode;
         return
      >> else if (l := length args) = 1 then
         (if numberp(n := reval car args) then <<
            logoturtle!-x!-max!* := logoturtle!-y!-max!* := abs n;
            logoturtle!-win!-mode!* := mode;
            return
         >> else if n eq 'false then <<
            logoturtle!-win!-mode!* := nil;
            return
         >> else if n eq 'true then <<
            % redundant user convenience
            logoturtle!-win!-mode!* := mode;
            return
         >>)
      else if l = 2 then
         (if numberp(m := reval car args) and
         numberp(n := reval cadr args) then <<
            logoturtle!-x!-max!* := abs m;
            logoturtle!-y!-max!* := abs n;
            logoturtle!-win!-mode!* := mode;
            return
         >>)
      else if l > 2 then
         typerr(args,
            concat("arguments to ", id2string mode));
      typerr(if n then if m then {m,n} else n,
         concat("argument(s) to ", id2string mode));
   end;

symbolic procedure wrap(args);
   % Tell the turtle to enter wrap mode: From now on, if the turtle is
   % asked to move past the boundary of the graphics window, it will
   % "wrap around" and reappear at the opposite edge of the window.
   % The top edge wraps to the bottom edge, while the left edge wraps
   % to the right edge.  (So the window is topologically equivalent to
   % a torus.)  This is the turtle's initial mode.
   logoturtle!-win!-mode('wrap, args);

put('wrap, 'psopfn, 'wrap);

symbolic procedure window(args);
   % Tell the turtle to enter window mode: From now on, if the turtle
   % is asked to move past the boundary of the graphics window, it
   % will move offscreen.  The visible graphics window is considered
   % as just part of an infinite graphics plane; the turtle can be
   % anywhere on the plane.
   logoturtle!-win!-mode('window, args);

put('window, 'psopfn, 'window);

symbolic procedure fence(args);
   % Tell the turtle to enter fence mode: From now on, if the turtle
   % is asked to move past the boundary of the graphics window, it
   % will move as far as it can and then stop at the edge with an "out
   % of bounds" error message.
   logoturtle!-win!-mode('fence, args);

put('fence, 'psopfn, 'fence);


% Turtle and Window Queries
% =========================

symbolic procedure shownp();
   % Outputs TRUE if the turtle is shown (visible), FALSE if the
   % turtle is hidden. See SHOWTURTLE and HIDETURTLE.
   if !*logoturtle!-shown then 'true else 'false;

symbolic operator shownp;

symbolic procedure turtlemode();
   % Output the word WRAP, FENCE, WINDOW or FALSE depending on the
   % current turtle (window) mode.
   if logoturtle!-win!-mode!* then logoturtle!-win!-mode!* else 'false;

symbolic operator turtlemode;


% Pen and Background Control (all return nothing)
% ===============================================

% The turtle carries a pen that can draw pictures.  At any time the
% pen can be UP (in which case moving the turtle does not change
% what's on the graphics screen) or DOWN (in which case the turtle
% leaves a trace).  Initially, the pen is UP.

symbolic procedure logoturtle!-new!-curve();
   logoturtle!-curve!* :=
      {{'list, logoturtle!-x!-coord!*, logoturtle!-y!-coord!*}};

symbolic procedure pendown();           % pd
   % Set the pen's position to DOWN, without changing its mode.
   % Initialize a new curve if the pen was up.
   if not !*logoturtle!-pen!-down then <<
      logoturtle!-new!-curve();
      !*logoturtle!-pen!-down := t;
   >>;

symbolic operator pendown;

symbolic procedure logoturtle!-save!-curve();
   if length logoturtle!-curve!* > 1 then
      logoturtle!-plot!-list!* := makelist logoturtle!-curve!*
      . logoturtle!-plot!-list!*;

symbolic procedure penup();             % pu
   % Set the pen's position to UP, without changing its mode.
   % Save the current curve if the pen was down.
   if !*logoturtle!-pen!-down then <<
      logoturtle!-save!-curve();
      logoturtle!-curve!* := nil;
      !*logoturtle!-pen!-down := nil;
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
   if !*logoturtle!-pen!-down then 'true else 'false;

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
      setk(car variable, makelist if length logoturtle!-curve!* > 1 then
         % Do an implicit penup to include the last partial curve:
         makelist logoturtle!-curve!* . logoturtle!-plot!-list!*
      else logoturtle!-plot!-list!*);
   >>;

put('savepict, 'psopfn, 'savepict);

symbolic procedure loadpict variable;
   % Reads a plot from the specified REDUCE variable, which must have
   % been assigned by a SAVEPICT command, and makes it the current
   % plot.  The previous current plot is lost if not saved using
   % SAVEPICT.
   <<
      logoturtle!-plot!-list!* := getrlist variable;
      logoturtle!-curve!* := nil;
   >>;

symbolic operator loadpict;

endmodule;

end;
