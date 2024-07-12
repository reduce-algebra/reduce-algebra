module logoturtle;   % Logo turtle graphics based on Gnuplot.

% Author: Francis Wright, July 2024

% LogoTurtle is a partial REDUCE emulation of traditional Logo turtle
% graphics (see https://en.wikipedia.org/wiki/Turtle_graphics) with
% one turtle, modelled on Berkeley Logo (see
% http://people.eecs.berkeley.edu/~bh/logo.html) by Brian Harvey and
% FMSLogo (see https://fmslogo.sourceforge.io/) by David Costanzo
% (which is an updated version of George Mills' MSWLogo, a
% multimedia-enhanced version for MS Windows, which is itself based on
% Berkeley Logo).

% This package is inspired by and related to the Turtle package by
% Caroline Cotter (ZIB, Berlin, 1998), and the word "Turtle" below
% (with a capital T) will refer specifically to that package.  Both
% packages are built on the REDUCE gnuplot package, which uses the
% Gnuplot executable to display plots.  This means that plotting is
% not fully interactive; a plot is constructed invisibly and only
% displayed when requested.  This package aims to be more efficient,
% more authentic, more interactive and more complete than Turtle.
% Command names are as in Berkeley Logo and/or FMSLogo, and their
% function is the same or similar.  (Identical behaviour is not always
% possible.)

% LogoTurtle procedures other than queries return nothing (nil) and
% plotting is achieved via side effects, not via returned procedure
% values (unlike Turtle).  A plot is displayed by calling the
% (non-traditional) procedure draw, as for Turtle.  The plot displayed
% need not be complete; draw displays the plot constructed so far
% until it is explicitly cleared.

% Lowering the pen begins a "curve", namely a sequence of two or more
% points connected by straight lines, and raising the pen ends that
% curve.  Each time the pen is lowered and later raised generates a
% distinct curve.

% LogoTurtle uses Lisp floating-point numbers internally and does not
% require any particular REDUCE number domain settings, such as "on
% rounded", although using "on rounded" and the default or lower
% precision makes sense.

% Data structures
% ===============

% A POINT is a pair of floats of the form (x.y) representing the two
% coordinates.

% A CURVE is a list of TWO or more points of the form
%      (point_1 point_2 ...)
% representing one connected curve consisting the points joined by
% straight lines.

% Raising and lowering the pen generates a new curve.  Curves are
% gathered together into one or more curve sequences with the same
% style, such as line colour and width.  Changing the line style
% generates a new curve sequence.

% A CURVE SEQUENCE is a tagged list consisting of a line style
% followed by one or more disconnected curves of the form
%      (curve!-seq linestyle curve_1 ...)
% representing a set of curves with the same line style.

% A PLOT is a list of one or more curve sequences.  Draw displays the
% current plot plus specified saved plots.

load_package gnuplot;

switch trlogoturtle;
% If on then output internal data from draw and logoturtle!-setxy.
% Also, output the commands sent to Gnuplot.
put('trlogoturtle, 'simpfg, '((t (on1 'trplot)) (nil (off1 'trplot))));

fluid '(
   logoturtle!-x!-coord!*   % turtle Cartesian x coordinate (float)
   logoturtle!-y!-coord!*   % turtle Cartesian y coordinate (float)
   logoturtle!-heading!*    % turtle heading (float)
   !*logoturtle!-pen!-down  % turtle pen down (boolean)
   logoturtle!-curve!*      % list of points
   logoturtle!-curve!-seq!* % tagged list of curves with style
   logoturtle!-plot!*       % list of curve sequences
   );

global '(
   logoturtle!-win!-mode!*  % wrap, window, fence, or nil
   logoturtle!-x!-max!*     % -x!-max!* <= x <= x!-max!* (float)
   logoturtle!-y!-max!*     % -y!-max!* <= y <= y!-max!* (float)
   !*logoturtle!-shown      % turtle shown (boolean)
   logoturtle!-rel!-len!*   % turtle length relative to window (float)
   logoturtle!-angle!*      % turtle head half-angle (float)
   logoturtle!-term!*       % name of Gnuplot terminal type (string)
   );

logoturtle!-x!-coord!*  := 0.0;
logoturtle!-y!-coord!*  := 0.0;
logoturtle!-heading!*   := 0.0;
logoturtle!-win!-mode!* := 'wrap;
logoturtle!-x!-max!*    := 100.0;
logoturtle!-y!-max!*    := 100.0;
logoturtle!-rel!-len!*  := 0.1;
logoturtle!-angle!*     := 10.0;

symbolic macro procedure logoturtle!-make!-curve!-seq args;
   % Return a curve sequence data structure as a tagged list of the
   % form (curve!-seq linestyle curve_1 curve_2 ...), where linestyle
   % is a list of items to be printed concatenated as the line style,
   % built from properties of logoturtle!-curve!-seq!*.  If an
   % argument is provided then it should be a colour specification
   % acceptable to Gnuplot, such as a value returned by
   % logoturtle!-colorspec, which overrides the lc property of
   % logoturtle!-curve!-seq!*.

   % Note that within this macro args has the form
   % (logoturtle!-make!-curve!-seq arg1 arg2 ...).
   {'prog, '(lc lw),
      {'setq, 'lc, if cdr args then cadr args
      else '(get 'logoturtle!-curve!-seq!* 'lc)},
      '(setq lw (get 'logoturtle!-curve!-seq!* 'lw)),
      '(return
         (cons 'curve!-seq
            (cons (append
                  (and lc (list " lc rgb """ lc """"))
                  (and lw (list " lw " lw)))
               logoturtle!-curve!-seq!*)))};

flag('(logoturtle!-make!-curve!-seq), 'variadic);

symbolic procedure logoturtle!-new!-curve();
   logoturtle!-curve!* :=
      {logoturtle!-x!-coord!* . logoturtle!-y!-coord!*};

symbolic procedure logoturtle!-new!-curve!-seq();
   <<
      logoturtle!-curve!-seq!* := nil;
      logoturtle!-new!-curve();
   >>;

symbolic procedure logoturtle!-save!-curve();
   if length logoturtle!-curve!* > 1 then
      logoturtle!-curve!-seq!* := logoturtle!-curve!* .
         logoturtle!-curve!-seq!*;

symbolic procedure logoturtle!-save!-curve!-seq();
   <<
      logoturtle!-save!-curve();
      if logoturtle!-curve!-seq!* then
         logoturtle!-plot!* := logoturtle!-make!-curve!-seq() .
            logoturtle!-plot!*;
   >>;

symbolic procedure logoturtle!-get!-plot();
   % Return the current plot including any partial curve and curve
   % sequence, without changing any global variables.
   <<
      logoturtle!-save!-curve!-seq();
      logoturtle!-plot!*
   >> where
      logoturtle!-curve!* = logoturtle!-curve!*,
      logoturtle!-curve!-seq!* = logoturtle!-curve!-seq!*,
      logoturtle!-plot!* = logoturtle!-plot!*;

symbolic procedure draw identifiers;
   % Display the plots stored under all the identifiers in the list
   % IDENTIFIERS followed by the current plot.  Optionally, display
   % the turtle.
   begin scalar plots := logoturtle!-get!-plot();
      % Initially, plots is a single plot, i.e. a list of curve
      % sequences, as returned by logoturtle!-show!-turtle().
      if !*logoturtle!-shown and logoturtle!-win!-mode!* then
         plots := logoturtle!-show!-turtle() . plots;
      % Draw curve sequences in input order so that overlaying is
      % correct, with turtle last and so on top.  Use reverse (not
      % reversip) so as to make a new list and not mangle
      % logoturtle!-plot!*:
      plots := reverse plots;
      % Don't draw an empty plot:
      if identifiers or plots then <<
         plots :=                 % Now plots becomes a list of plots.
         append(
            for each id in identifiers collect
            (begin scalar pl;
               id := reval id;
               if not (idp id and
                  (pl := get('logoturtle!-plot!*, id)))
               then typerr(id, "LogoTurtle LOADPICT identifier");
               return pl
            end), plots and {plots});
         % Now plots is a list of plots, where a plot is a list of
         % curve sequences.
         if !*trlogoturtle then <<
            terpri();
            prettyprint plots;
         >>;

         % Code below based on ploteval in "plotsynt.red".
         bye!-actions!* := union('((plotreset)), bye!-actions!*);
         gp!-init();
         begin scalar bg :=
            get('logoturtle!-plot!*, 'logoturtle!-bg);
            if bg then
               plotprin2lt {"set term ", logoturtle!-term!*,
                  " background rgb """, bg, """"}
         end;
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
         begin scalar ll, fn, styles;
            ll := linelength(1000);

            % Write all plot data to one data file:

            begin scalar f, of;
               of := wrs(f := open(fn := plot!-filename(),'output));
               styles := for each plot in reversip plots join
                  for each curve_seq in plot collect
                     % curve_seq has the form
                     % (curve!-seq linestyle curve_1 curve_2 ...):
                     <<
                        for each curve in cddr curve_seq do <<
                           % curve has the form (point_1 point_2 ...):
                           for each point in curve do <<
                              % Write plot data to the current write stream:
                              prin2 car point; prin2 " "; prin2 cdr point; terpri()
                           >>;
                           % Separate disconnected curves by a single blank line:
                           terpri()
                        >>;
                        % Separate curve sequences (Gnuplot data sets)
                        % by PAIRS of blank lines:
                        terpri();
                        cadr curve_seq  % return style
                     >>;
               wrs of; close f;
            end;

            % Write all plot commands to one command file:

            begin scalar fst := t; integer i;
               for each style in styles do <<
                  if fst then
                     plotprin2lt {"plot '", fn, "'\"}
                  else
                     << plotprin2lt '(",\"); plotprin2 "''" >>;
                  plotprin2l {" index ", i, " with lines"};
                  style and plotprin2l style; % e.g. " lc rgb ""green"""
                  fst := nil;
                  i := i + 1;
               >>;
               plotterpri();
            end;

            linelength(ll);
         end;
         gp!-show();
      >>;
   end;

symbolic procedure plotprin2l l;     % cf. plotprin2lt in gnupldrv.red
   for each x in l do plotprin2 x;

put('draw, 'psopfn, 'draw);

symbolic procedure logoturtle!-show!-turtle();
   % Return a curve sequence representing the turtle.  The turtle is
   % displayed as an isoceles triangle; the actual turtle position is
   % at the midpoint of the base (the short side).  However, the
   % turtle is drawn one step behind its actual position, so that the
   % display of the base of the turtle's triangle does not obscure a
   % line drawn perpendicular to it (as would happen after drawing a
   % square).
   (begin scalar !*logoturtle!-pen!-down,
         logoturtle!-curve!*, logoturtle!-curve!-seq!*,
         length := logoturtle!-rel!-len!* *
         (logoturtle!-x!-max!* + logoturtle!-y!-max!*) / 2.0,
         side := length / cosd logoturtle!-angle!*,
         base := 2.0 * length * tand logoturtle!-angle!*,
         baseangle := 90.0 - logoturtle!-angle!*;
      logoturtle!-forward(length-1); pendown();
      logoturtle!-right(logoturtle!-angle!*); logoturtle!-forward(-side);
      logoturtle!-right(baseangle); logoturtle!-forward(base);
      logoturtle!-right(baseangle); logoturtle!-forward(-side);
      logoturtle!-curve!-seq!* := list logoturtle!-curve!*;
      return logoturtle!-make!-curve!-seq "black"
   end) where
      logoturtle!-x!-coord!* = logoturtle!-x!-coord!*,
      logoturtle!-y!-coord!* = logoturtle!-y!-coord!*,
      logoturtle!-heading!* = logoturtle!-heading!*;

% *** TO DO: Consider using code similar to procedure rdwrap in
% "plotnum.red" to evaluate expressions to Lisp floats RELIABLY! ***

symbolic procedure logoturtle!-number n;
   % Convert N to a Lisp float provided it is a real general REDUCE
   % algebraic-mode number.
   if atom n then
      % integer, float (default number domain) or error
      (if numberp n then float n else typerr(n, "real number"))
   else if eqcar(n, 'quotient) then
      % quotient (default number domain)
      (float eval cadr n)/(float eval caddr n)
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
         logoturtle!-curve!* := (newxcor . newycor)
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
   % specified positive radius, starting at the turtle's heading and
   % extending clockwise through the specified angle
   % (counter-clockwise if angle is negative).  The turtle does not
   % move.
   begin scalar nsteps, h, delta, curve, a;
      angle := logoturtle!-number angle;
      radius := logoturtle!-number radius;
      if radius <= 0.0 then typerr(radius, "radius");
      angle := deg2rad angle;             % angle subtended in radians
      h := deg2rad logoturtle!-heading!*; % heading in radians
      nsteps := fix abs(10.0*angle);      % arcstep = radius/10.0
      delta := angle/nsteps;
      curve := for n := 0 : nsteps collect <<
         a := h + n*delta;
         (logoturtle!-x!-coord!* + radius*sin(a)) .
            (logoturtle!-y!-coord!* + radius*cos(a))
      >>;
      logoturtle!-curve!-seq!* := curve . logoturtle!-curve!-seq!*;
   end;

symbolic operator arc;

symbolic procedure arc2(angle, radius);
   % Move the turtle along a circular arc that sweeps through the
   % specified angle with the specified positive radius.  The turtle
   % always moves forwards: if angle is positive, then the turtle
   % moves forwards in a clockwise direction; if angle is negative,
   % then the turtle moves forwards in a counter-clockwise direction.
   % At the end of the arc, the turtle's heading is increased by
   % angle.
   begin scalar nsteps, a, h, x, y, delta;
      angle := logoturtle!-number angle;
      radius := logoturtle!-number radius;
      if radius <= 0.0 then typerr(radius, "radius");
      if angle < 0 then radius := -radius;
      a := deg2rad angle;                 % angle subtended in radians
      h := deg2rad logoturtle!-heading!*; % heading in radians
      x := logoturtle!-x!-coord!* + radius*cos(h); % centre of arc
      y := logoturtle!-y!-coord!* - radius*sin(h);
      nsteps := fix abs(10.0*a);        % arcstep = radius/10.0
      delta := a/nsteps;
      for n := 1 : nsteps do <<
         a := h + n*delta;
         logoturtle!-setxy(x - radius*cos(a), y + radius*sin(a))
      >>;
      logoturtle!-setheading(logoturtle!-heading!* + angle)
   end;

symbolic operator arc2;

symbolic procedure circle radius;
   % Draw a circle centred on the turtle with the positive radius
   % specified.  The turtle does not move.
   arc(360.0, radius);

symbolic operator circle;

symbolic procedure circle2 radius;
   % Move the turtle clockwise around a circle with the specified
   % positive radius.  The turtle ends in the same position in which
   % it starts.
   arc2(360.0, radius);

symbolic operator circle2;

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
      logoturtle!-plot!* := logoturtle!-curve!-seq!* := nil;
      logoturtle!-curve!* :=
         if !*logoturtle!-pen!-down then
            {logoturtle!-x!-coord!* . logoturtle!-y!-coord!*};
   >>;

symbolic operator clean;

symbolic procedure clearscreen();       % cs;
   % Erase the graphics window and send the turtle to its initial
   % position and heading.  Like HOME and CLEAN together.
   <<
      plotreset;
      logoturtle!-x!-coord!* := 0.0;
      logoturtle!-y!-coord!* := 0.0;
      logoturtle!-heading!* := 0.0;
      clean();
   >>;

symbolic operator clearscreen;

% The LogoTurtle commands WRAP, WINDOW and FENCE accept zero, one or
% two arguments: if the single argument is FALSE then no window mode
% is set, meaning that (like Turtle) LogoTurtle does not use a fixed
% window size and there are no constraints on where the turtle draws;
% otherwise a window mode is set.  If there is a single numerical
% argument N then the size of the graphics window is set to -|N| <=
% x,y <= |N|; if there are two numerical arguments M, N then the size
% of the graphics window is set to -|M| <= x <= |M|, -|N| <= y <= |N|.

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

symbolic procedure pendown();           % pd
   % Set the pen's position to DOWN, without changing its mode.
   % Initialize a new curve if the pen was up.
   if not !*logoturtle!-pen!-down then <<
      logoturtle!-new!-curve();
      !*logoturtle!-pen!-down := t;
   >>;

symbolic operator pendown;

symbolic procedure penup();             % pu
   % Set the pen's position to UP, without changing its mode.
   % Save the current curve if the pen was down.
   if !*logoturtle!-pen!-down then <<
      logoturtle!-save!-curve();
      logoturtle!-curve!* := nil;
      !*logoturtle!-pen!-down := nil;
   >>;

symbolic operator penup;

global '(logoturtle!-colors!*);
logoturtle!-colors!* := mkvect(15);
putv(logoturtle!-colors!*, 0, "black");
putv(logoturtle!-colors!*, 1, "blue");
putv(logoturtle!-colors!*, 2, "green");
putv(logoturtle!-colors!*, 3, "cyan");
putv(logoturtle!-colors!*, 4, "red");
putv(logoturtle!-colors!*, 5, "magenta");
putv(logoturtle!-colors!*, 6, "yellow");
putv(logoturtle!-colors!*, 7, "white");
putv(logoturtle!-colors!*, 8, "brown");
putv(logoturtle!-colors!*, 9, "tan1");          % tan
putv(logoturtle!-colors!*, 10, "forest-green"); % forest
putv(logoturtle!-colors!*, 11, "aquamarine");   % aqua
putv(logoturtle!-colors!*, 12, "salmon");
putv(logoturtle!-colors!*, 13, "purple");
putv(logoturtle!-colors!*, 14, "orange");
putv(logoturtle!-colors!*, 15, "grey");

% Gnuplot 4.6 only supports useful color specifications of the form
% "colorname" or "#RRGGBB".

symbolic procedure setpencolor color;   % setpc color
   % Set the pen color to the given number, which must be an integer
   % between 0 and 15 inclusive.  The initial colour assignments are:

   % 0 black 1 blue 2 green 3 cyan
   % 4 red 5 magenta 6 yellow 7 white
   % 8 brown 9 tan 10 forest 11 aqua
   % 12 salmon 13 purple 14 orange 15 grey

   % but other colors can be assigned to numbers 8--15 by the
   % SETPALETTE command.  Alternatively, sets the pen color to the
   % given RGB values (a list of three nonnegative numbers not greater
   % than 100 specifying the percent saturation of red, green, and
   % blue in the desired color).

   % The argument can be a string or identifier representing a colour
   % in any way that is acceptable to Gnuplot, such as a colour name
   % or hexadecimal number.  Alternatively, it can be the identifier
   % FALSE meaning that no colour is set.
   begin scalar colorspec := logoturtle!-colorspec reval color;
      % Changing the pen colour terminates the current curve
      % sequence with the current line style, saves the new line
      % style and starts a new curve sequence.
      logoturtle!-save!-curve!-seq();
      if colorspec then
         put('logoturtle!-curve!-seq!*, 'lc, colorspec)
      else
         remprop('logoturtle!-curve!-seq!*, 'lc);
      logoturtle!-new!-curve!-seq()
   end;

symbolic operator setpencolor;

symbolic procedure logoturtle!-colorspec color;
   % Return a string or identifier representing a Gnuplot colour
   % specifier, e.g. red, "red" or "#FF0000", or nil.
   if fixp color and color >= 0 and color <= 15 then
      getv(logoturtle!-colors!*, color)
   else if stringp color then
      color
   else if idp color then
      (if not(color eq 'false) then color)
   else if eqcar(color, 'list) then
      logoturtle!-rgblist2hexstring color
   else typerr(color, "color number 0--15, color name, RGB list or false");

global '(logoturtle!-hex!-digits!*);
logoturtle!-hex!-digits!* := mkvect(15);
putv(logoturtle!-hex!-digits!*, 0, '!0);
putv(logoturtle!-hex!-digits!*, 1, '!1);
putv(logoturtle!-hex!-digits!*, 2, '!2);
putv(logoturtle!-hex!-digits!*, 3, '!3);
putv(logoturtle!-hex!-digits!*, 4, '!4);
putv(logoturtle!-hex!-digits!*, 5, '!5);
putv(logoturtle!-hex!-digits!*, 6, '!6);
putv(logoturtle!-hex!-digits!*, 7, '!7);
putv(logoturtle!-hex!-digits!*, 8, '!8);
putv(logoturtle!-hex!-digits!*, 9, '!9);
putv(logoturtle!-hex!-digits!*, 10, '!A);
putv(logoturtle!-hex!-digits!*, 11, '!B);
putv(logoturtle!-hex!-digits!*, 12, '!C);
putv(logoturtle!-hex!-digits!*, 13, '!D);
putv(logoturtle!-hex!-digits!*, 14, '!E);
putv(logoturtle!-hex!-digits!*, 15, '!F);

symbolic procedure logoturtle!-rgblist2hexstring(color);
   % Color = {r,g,b}, where r,g,b are percentages of 255.
   % Return string "#RRGGBB", where R,G,B are hex digits.
   begin scalar v := '(!"), hex_hi, hex_lo;
      if not(length color eq 4) then go to error;
      % For each percent value p in reversed RGB list:
      for each p in reversip cdr color do <<
         p := logoturtle!-number p;
         if p < 0.0 or p > 100.0 then go to error;
         p := fix(p*2.55 + 0.5);
         % Convert p to two hexadecimal digits:
         p := divide(p, 16);         % (quo . rem)
         hex_hi := getv(logoturtle!-hex!-digits!*, car p);
         hex_lo := getv(logoturtle!-hex!-digits!*, cdr p);
         v := hex_hi . hex_lo . v
      >>;
      return compress('!" . '!# . v);
   error: typerr(color, "RGB list of percent color saturations")
   end;

symbolic procedure setpalette(colornumber, rgblist);
   % Set the actual color corresponding to a given number.
   % Colornumber must be an integer N such that 8 <= N <= 15.
   % (LogoTurtle keeps the first 8 colors constant.)  The second input
   % is a list of three nonnegative numbers not greater than 100
   % specifying the percent saturation of red, green, and blue in the
   % desired color.  The second input can be a string or identifier
   % representing a colour in any way that is acceptable to Gnuplot,
   % such as a colour name or hexadecimal number.
   begin scalar n := reval colornumber;
      if fixp n and n >= 0 and n <= 15 then
         putv(logoturtle!-colors!*, n,
            if stringp rgblist or idp rgblist then rgblist
            else if eqcar(rgblist, 'list) then
               logoturtle!-rgblist2hexstring rgblist
            else typerr(rgblist, "color name or RGB list"))
      else
         typerr(n, "color number between 8 and 15");
   end;

symbolic operator setpalette;

symbolic procedure setpensize size;
   % Set the thickness of the pen.  The input is a positive integer
   % representing a multiple of the default thickness, or false,
   % meaning unspecified, which is effectively equivalent to 1 but
   % slightly less efficient.
   begin scalar sz;
      if fixp size and size > 0 then
         sz := size
      else if not(size eq 'false) then
         typerr(size, "positive integer or false");
      % Changing the pen size terminates the current curve sequence
      % with the current line style, saves the new line style and
      % starts a new curve sequence.
      logoturtle!-save!-curve!-seq();
      if sz then
         put('logoturtle!-curve!-seq!*, 'lw, sz)
      else
         remprop('logoturtle!-curve!-seq!*, 'lw);
      logoturtle!-new!-curve!-seq()
   end;

symbolic operator setpensize;

symbolic procedure setbackground color; % setbg color
   % Set the screen background color by slot number or RGB values,
   % etc.  See SETPENCOLOR for details.
   % Currently requires GNUTERM environment variable to be set!
   begin scalar colorspec;
      if null (logoturtle!-term!* or
         (logoturtle!-term!* := getenv "GNUTERM"))
      then return
         msgpri("GNUTERM environment variable not set",nil,nil,nil,nil);
      if (colorspec := logoturtle!-colorspec reval color) then
         put('logoturtle!-plot!*, 'logoturtle!-bg, colorspec)
      else
         remprop('logoturtle!-plot!*, 'logoturtle!-bg)
   end;

symbolic operator setbackground;


% Pen and Background Queries (all procedures return values)
% =========================================================

symbolic procedure pendownp();
   % Output TRUE if the pen is down, FALSE if it's up.
   if !*logoturtle!-pen!-down then 'true else 'false;

symbolic operator pendownp;

% penmode
% outputs one of the words PAINT, ERASE, or REVERSE according to the current pen mode.

symbolic procedure pencolor();          % PC
   % Output the pen colour as a string or identifier that represents a
   % colour in any way that is acceptable to Gnuplot, such as a colour
   % name or hexadecimal number.  Alternatively, output the identifier
   % FALSE meaning that no colour is set.
   begin scalar colorspec := get('logoturtle!-curve!-seq!*, 'lc);
      return if colorspec then colorspec else 'false;
   end;

symbolic operator pencolor;

symbolic procedure palette colornumber;
   % Colornumber must be a nonnegative integer not greater than 15.
   % Output a string or identifier that represents the colour
   % associated with the given number in any way that is acceptable to
   % Gnuplot, such as a colour name or hexadecimal number.
   begin scalar n := reval colornumber;
      if fixp n and n >= 0 and n <= 15 then
         return getv(logoturtle!-colors!*, n)
      else
         typerr(n, "color number between 0 and 15");
   end;

symbolic operator palette;

symbolic procedure pensize();
   % Output a positive integer specifying the thickness of the turtle
   % pen as a multiple of the default thickness, or false, meaning
   % unspecified, which is effectively equivalent to 1 but slightly
   % less efficient.
   begin scalar size :=
      get('logoturtle!-curve!-seq!*, 'lw);
      return if size then size else 'false
   end;

symbolic operator pensize;

% penpattern
% outputs system-specific pen information.

% pen (library procedure)
% outputs a list containing the pen's position, mode, thickness, and hardware-specific characteristics,
% for use by SETPEN.
% See [SETPEN], page 51, .

symbolic procedure background();        % bg
   % Output the graphics background colour as a string or identifier
   % that represents a colour in any way that is acceptable to
   % Gnuplot, such as a colour name or hexadecimal number.
   % Alternatively, output the identifier FALSE meaning that no colour
   % is set.
   begin scalar colorspec :=
      get('logoturtle!-plot!*, 'logoturtle!-bg);
      return if colorspec then colorspec else 'false
   end;

symbolic operator background;


% Saving and Loading Pictures (all return nothing)
% ================================================

% These two procedures save to, and load from, an internal
% LogoTurtle namespace (the property list of the identifier
% logoturtle!-plot!*).

symbolic procedure savepict identifier;
   % Save the current plot to internal storage under the specified
   % identifier without changing it.  The saved plot can be restored
   % as the current plot using LOADPICT or displayed using DRAW.
   begin scalar id := reval identifier;
      if not idp id then typerr(id, "LogoTurtle SAVEPICT identifier");
      put('logoturtle!-plot!*, id, logoturtle!-get!-plot())
   end;

symbolic operator savepict;

symbolic procedure loadpict identifier;
   % Retrieve the plot stored under the specified identifier, which
   % must have been stored by a SAVEPICT command, and make it the
   % current plot.  The previous current plot is lost if not saved
   % using SAVEPICT.
   begin scalar id := reval identifier, pl;
      if not (idp id and
         (pl := get('logoturtle!-plot!*, id)))
      then typerr(id, "LogoTurtle LOADPICT identifier");
      logoturtle!-plot!* := pl;
      logoturtle!-curve!* := logoturtle!-curve!-seq!* := nil
   end;

symbolic operator loadpict;

endmodule;

end;
