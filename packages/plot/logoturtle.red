module logoturtle;   % Logo turtle graphics based on Gnuplot.

% Author: Francis Wright, August 2024

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%  * Redistributions of source code must retain the relevant copyright
%    notice, this list of conditions and the following disclaimer.
%
%  * Redistributions in binary form must reproduce the relevant
%    copyright notice, this list of conditions and the following
%    disclaimer in the documentation and/or other materials provided
%    with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
% FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
% COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
% INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
% BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
% LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
% CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
% LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
% ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.

% $Id$

% LogoTurtle is a REDUCE emulation of traditional Logo turtle graphics
% (see https://en.wikipedia.org/wiki/Turtle_graphics) with one turtle,
% modelled on Berkeley Logo (see
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
% rounded".

% Data structures
% ===============

% A POINT is a pair of floats of the form (x.y) representing the two
% coordinates.

% A CURVE is a list of TWO or more points of the form
%      (point_1 point_2 ...)
% representing one connected curve consisting of the points joined by
% straight lines.

% Raising and lowering the pen generates a new curve.  Curves are
% gathered together into one or more curve sequences with the same
% style, namely line colour and width.  Changing the line style
% generates a new curve sequence.

% A CURVE SEQUENCE is a list consisting of a line style followed by
% one or more curves of the form
%      (style curve_1 curve_2 ...)
% representing a sequence of disconnected curves with the same line
% style.

% A PLOT is a list of one or more curve sequences.  Draw displays the
% current plot and any incomplete curves.


% A LABEL is a list of the form
%      (text-list (x.y) style-list)
% where text-list is a list of atoms representing the label text,
% (x.y) is a pair of floats representing the two coordinates at the
% left of the label, and style-list is a list of atoms representing
% the label font and colour.

load_package gnuplot;
% LogoTurtle uses the following functions from the gnuplot package:
% gp!-init, plotprin2, plotprin2lt, plotterpri, plot!-filename,
% gp!-show, plotrounded, plotreset.  It also uses the trplot switch,
% which affects plotprin2 etc.

switch trlogoturtle;
% If on then output internal data from draw and logoturtle!-setxy.
% Also, output the commands sent to Gnuplot.
put('trlogoturtle, 'simpfg, '((t (on1 'trplot)) (nil (off1 'trplot))));

switch logoturtle_autodraw;
% If on then automatically call draw after every command that changes
% the plot.

fluid '(
   logoturtle!-x!-coord!*   % turtle Cartesian x coordinate (float)
   logoturtle!-y!-coord!*   % turtle Cartesian y coordinate (float)
   logoturtle!-heading!*    % turtle heading (float)
   !*logoturtle!-pen!-down  % turtle pen down (boolean)
   logoturtle!-curve!*      % list of points
   logoturtle!-curve!-seq!* % list of curves with style
   logoturtle!-plot!*       % list of curve sequences
   logoturtle!-win!-mode!*  % wrap, window, fence, or nil
   !*logoturtle!-draw!-nothing          % draw nothing (boolean)
   );

global '(
   logoturtle!-x!-max!*     % -x!-max!* <= x <= x!-max!* (float)
   logoturtle!-y!-max!*     % -y!-max!* <= y <= y!-max!* (float)
   !*logoturtle!-shown      % turtle shown (boolean)
   logoturtle!-rel!-len!*   % turtle length relative to window (float)
   logoturtle!-angle!*      % turtle head half-angle (float)
   logoturtle!-term!*       % name of Gnuplot terminal type (string)
   logoturtle!-labels!*     % list of label data structures
   logoturtle!-noarg!*      % list of commands that take no args
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
   % Return a curve sequence data structure as a list of the form
   % (style curve_1 curve_2 ...), where style is a list of items to be
   % printed concatenated as the style (following "with "), built from
   % properties of logoturtle!-curve!-seq!*.  If an argument is
   % provided then it should be a colour specification acceptable to
   % Gnuplot, such as a value returned by logoturtle!-colorspec, which
   % overrides the lc property and ignores the lw property of
   % logoturtle!-curve!-seq!*.

   % Note that within this macro args is a list of the form
   % (logoturtle!-make!-curve!-seq arg1 arg2 ...).
   'prog . '(lc lw) . append(
      if cdr args then
         {'setq . 'lc . cdr args}
      else
         '((setq lc (get 'logoturtle!-curve!-seq!* 'lc))
           (setq lw (get 'logoturtle!-curve!-seq!* 'lw))),
      '((return
         (cons
            (cons "lines"
               (append
                  (and lc (list " lc rgb """ lc """"))
                  (and lw (list " lw " lw))))
            logoturtle!-curve!-seq!*))));

symbolic macro procedure logoturtle!-make!-fill args;
   % cf. logoturtle!-make!-curve!-seq but for a filled curve sequence
   % consisting of just the current curve and ignoring line width.

   % Note that within this macro args is a list of the form
   % (logoturtle!-make!-fill arg1 arg2 ...).
   {'prog, '(lc),
      {'setq, 'lc, if cdr args then cadr args
      else '(get 'logoturtle!-curve!-seq!* 'lc)},
      '(return
         (cons
            (cons "filledcurves"
               (and lc (list " lc rgb """ lc """")))
            (list logoturtle!-curve!*)))};

flag('(logoturtle!-make!-curve!-seq logoturtle!-make!-fill), 'variadic);

symbolic procedure logoturtle!-new!-curve;
   logoturtle!-curve!* :=
      {logoturtle!-x!-coord!* . logoturtle!-y!-coord!*};

symbolic procedure logoturtle!-new!-curve!-seq;
   <<
      logoturtle!-curve!-seq!* := nil;
      logoturtle!-new!-curve();
   >>;

symbolic procedure logoturtle!-save!-curve;
   if length logoturtle!-curve!* > 1 then
      logoturtle!-curve!-seq!* := logoturtle!-curve!* .
         logoturtle!-curve!-seq!*;

symbolic procedure logoturtle!-save!-curve!-seq;
   <<
      logoturtle!-save!-curve();
      if logoturtle!-curve!-seq!* then
         logoturtle!-plot!* := logoturtle!-make!-curve!-seq() .
            logoturtle!-plot!*;
   >>;

symbolic procedure logoturtle!-get!-plot;
   % Return the current plot including any partial curve and curve
   % sequence, without changing any global variables.
   <<
      logoturtle!-save!-curve!-seq();
      logoturtle!-plot!*
   >> where
      logoturtle!-curve!* = logoturtle!-curve!*,
      logoturtle!-curve!-seq!* = logoturtle!-curve!-seq!*,
      logoturtle!-plot!* = logoturtle!-plot!*;

% The following list of all the commands that take no arguments will
%  have a special read function applied at the end of this file:
logoturtle!-noarg!* :=
   '(draw home pos xcor ycor heading showturtle hideturtle clean
     clearscreen wrap window fence fill shownp windowsize turtlemode
     labelfont labelcolor pendown penup pendownp pencolor pensize
     background);

for each cmd in logoturtle!-noarg!* do remprop(cmd, 'stat);

symbolic procedure draw;
   % Display the current plot and, optionally, the turtle.
   begin scalar plot := logoturtle!-get!-plot();
      % logoturtle!-show!-turtle returns a curve sequence representing
      % the turtle.
      if !*logoturtle!-shown then
         plot := logoturtle!-show!-turtle() . plot;

      % Don't draw an empty plot (unless specifically requested):
      if plot or logoturtle!-labels!* or !*logoturtle!-draw!-nothing
      then <<
         % Draw curve sequences in input order so that overlaying is
         % correct, with turtle last and so on top.  Use reverse (not
         % reversip) so as to make a new list and not mangle
         % logoturtle!-plot!*:
         plot := reverse plot;

         if !*trlogoturtle then << terpri(); prettyprint plot >>;

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
         for each label in logoturtle!-labels!* do
         begin scalar pos := cadr label;
            plotprin2 "set label """;
            plotprin2l car label;
            plotprin2l {""" at ", car pos, ",", cdr pos, " front"};
            if cddr label then <<
               plotprin2lt '("\");      % keep lines short
               plotprin2l cddr label    % label style
            >>;
            plotterpri()
         end;

         begin scalar fn, styles;

            % Write all plot data to one data file:

            begin scalar f, of;
               of := wrs(f := open(fn := plot!-filename(),'output));
               styles := for each curve_seq in plot collect
                  % curve_seq has the form
                  % (linestyle curve_1 curve_2 ...):
                  <<
                     for each curve in cdr curve_seq do <<
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
                     car curve_seq  % return style
                  >>;
               wrs of; close f;
            end;

            % Write the plot command:

            if styles then
            begin scalar fst := t; integer i;
               for each style in styles do <<
                  if fst then
                     plotprin2lt {"plot '", fn, "'\"}
                  else
                     << plotprin2lt '(",\"); plotprin2 "''" >>;
                  plotprin2l {" index ", i, " with "};
                  plotprin2l style;    % e.g. "lines lc rgb ""green"""
                  fst := nil;
                  i := i + 1;
               >>;
               plotterpri();
            end
            else <<
               % Plot nothing to display only labels or an empty plot:
               plotprin2lt '("plot '-' with lines");
               plotprin2lt '("0 0");
               plotprin2lt '("e");
            >>;

         end;
         gp!-show()
      >>;
   end;

symbolic inline procedure logoturtle!-autodraw;
   if !*logoturtle_autodraw then draw();

symbolic inline procedure logoturtle!-autodraw!-nothing;
   if !*logoturtle_autodraw then
   begin scalar !*logoturtle!-draw!-nothing := t;
      draw()
   end;

symbolic procedure plotprin2l l;     % cf. plotprin2lt in gnupldrv.red
   for each x in l do plotprin2 x;

symbolic procedure logoturtle!-show!-turtle;
   % Return a curve sequence representing the turtle.  The turtle is
   % displayed as an isoceles triangle; the actual turtle position is
   % at the midpoint of the base (the short side).  However, the
   % turtle is drawn one step behind its actual position, so that the
   % display of the base of the turtle's triangle does not obscure a
   % line drawn perpendicular to it (as would happen after drawing a
   % square).  The turtle is always drawn as a black default-thickness
   % line that is never wrapped, although it is clipped if any turtle
   % mode is in effect, i.e. for drawing the turtle any windowing mode
   % other than false is treated as window.
   (begin scalar !*logoturtle_autodraw, logoturtle!-win!-mode!*,
         !*logoturtle!-pen!-down,
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
      logoturtle!-curve!-seq!* := {logoturtle!-curve!*};
      return logoturtle!-make!-curve!-seq "black"
   end) where
      logoturtle!-x!-coord!* = logoturtle!-x!-coord!*,
      logoturtle!-y!-coord!* = logoturtle!-y!-coord!*,
      logoturtle!-heading!* = logoturtle!-heading!*;

symbolic procedure logoturtle!-float!-args(cmdname, nargs, args);
   % If nargs is list then check that args contains a single rlist and
   % evaluate that as args; otherwise check that the length of list
   % args equals nargs.  Evaluate each element of args to a Lisp float
   % provided it is a real general REDUCE algebraic-mode number.  If
   % nargs = 1 then return a single float, otherwise return a list of
   % floats.
   begin scalar rlstp, pr, r, !*exp;
      if nargs eq 'list then << rlstp := t; nargs := 1 >>;
      if not(length args eq nargs) then
         rederr {"Improper number of arguments to", cmdname};
      pr := plotrounded nil;            % turn on rounded mode safely
      precision 10;
      if rlstp then <<
         args := getrlist reval car args;
         nargs := nil
      >>;
      if nargs eq 1 then
         (if numberp(r := reval car args) then float r
         else if eqcar(r, '!:rd!:) and floatp(r := cdr r) then r
         else typerr(r, "real number"))
      else
         r := for each arg in args collect <<
            if not rlstp then arg := reval arg;
            if numberp arg then float arg
            else if eqcar(arg, '!:rd!:) and floatp(arg := cdr arg) then arg
            else typerr(args, "real numbers")
         >>;
      plotrounded pr;                   % restore global domain mode
      return r
   end;


% Turtle Motion Commands (all return nothing)
% ===========================================

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
   logoturtle!-forward(+ logoturtle!-float!-args("FORWARD", 1, dist));

put('forward, 'psopfn, 'forward);

symbolic procedure back dist;           % bk dist
   % Move the turtle backward, i.e., exactly opposite to the
   % direction that it's facing, by the specified distance. (The
   % heading of the turtle does not change.)
   logoturtle!-forward(- logoturtle!-float!-args("BACK", 1, dist));

put('back, 'psopfn, 'back);

symbolic procedure logoturtle!-forward dist;
   % Move the turtle forward, in the direction that it's facing, by
   % the specified distance, ASSUMED TO BE A LISP NUMBER!
   <<
      logoturtle!-setxy(logoturtle!-x!-coord!* + dist * sind logoturtle!-heading!*,
         logoturtle!-y!-coord!* + dist * cosd logoturtle!-heading!*);
   >>;

symbolic procedure left degrees;        % lt degrees
   % Turn the turtle counterclockwise by the specified angle
   logoturtle!-right(- logoturtle!-float!-args("LEFT", 1, degrees));

put('left, 'psopfn, 'left);

symbolic procedure right degrees;       % rt degrees
   % Turn the turtle clockwise by the specified angle.
   logoturtle!-right(+ logoturtle!-float!-args("RIGHT", 1, degrees));

put('right, 'psopfn, 'right);

symbolic procedure logoturtle!-right degrees;
   % Turn the turtle clockwise by the specified angle, ASSUMED TO BE A
   % LISP NUMBER!
   logoturtle!-setheading(logoturtle!-heading!* + degrees);

symbolic procedure setpos posn;
   % Move the turtle to an absolute position in the graphics window.
   % The input is a list of two numbers, the X and Y coordinates.
   apply('logoturtle!-setxy, logoturtle!-float!-args("POS", 'list, posn));

put('setpos, 'psopfn, 'setpos);

symbolic procedure setxy args;          % (xcor, ycor)
   % Move the turtle to an absolute position in the graphics window.
   % The two inputs are numbers, the X and Y coordinates.
   apply(function logoturtle!-setxy, logoturtle!-float!-args("SETXY", 2, args));

put('setxy, 'psopfn, 'setxy);

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
      if !*logoturtle_autodraw and
         (!*logoturtle!-pen!-down or !*logoturtle!-shown) then draw();
   end;

symbolic procedure setx xcor;
   % Move the turtle horizontally from its old position to a new
   % absolute horizontal coordinate.  The input is the new X
   % coordinate.
   logoturtle!-setxy(logoturtle!-float!-args("SETX", 1, xcor),
      logoturtle!-y!-coord!*);

put('setx, 'psopfn, 'setx);

symbolic procedure sety ycor;
   % Move the turtle vertically from its old position to a new
   % absolute vertical coordinate.  The input is the new Y coordinate.
   logoturtle!-setxy(logoturtle!-x!-coord!*,
      logoturtle!-float!-args("SETY", 1, ycor));

put('sety, 'psopfn, 'sety);

symbolic procedure setheading degrees;  % seth degrees
   % Turn the turtle to a new absolute heading.  The input is a number,
   % the heading in degrees clockwise from the positive Y axis.
   logoturtle!-setheading(logoturtle!-float!-args("SETHEADING", 1, degrees));

put('setheading, 'psopfn, 'setheading);

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
      if !*logoturtle_autodraw and !*logoturtle!-shown then draw();
   >>;

symbolic procedure home;
   % Move the turtle to the origin and set the heading to 0.
   % Equivalent to SETPOS {0, 0}; SETHEADING 0.
   <<
      logoturtle!-heading!* := 0.0;
      logoturtle!-setxy(0.0, 0.0);      % may autodraw
   >>;

symbolic procedure arc args;            % (angle, radius)
   % Draw an arc of a circle, with the turtle at the center, with the
   % specified positive radius, starting at the turtle's heading and
   % extending clockwise through the specified angle
   % (counter-clockwise if angle is negative).  The turtle does not
   % move.
   apply(function logoturtle!-arc,
      logoturtle!-float!-args("ARC", 2, args));

put('arc, 'psopfn, 'arc);

symbolic procedure circle radius;
   % Draw a circle centred on the turtle with the positive radius
   % specified.  The turtle does not move.
   logoturtle!-arc(360.0, logoturtle!-float!-args("CIRCLE", 1, radius));

put('circle, 'psopfn, 'circle);

symbolic procedure logoturtle!-arc(angle, radius);
   begin scalar nsteps, h, delta, curve, a;
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
      logoturtle!-autodraw()
   end;

symbolic procedure ellipticarc args;
   %   (paramrange, crosswise_semiaxis, inline_semiaxis, paramstart)
   % Draw an elliptic arc based on the turtle's position and heading.
   % The turtle does not move.  The center-point of the ellipse is the
   % turtle's current position.  The size and shape of the ellipse are
   % determined by the positive CROSSWISE_SEMIAXIS and
   % INLINE_SEMIAXIS.  The CROSSWISE_SEMIAXIS is the distance from the
   % turtle to the ellipse in the direction perpendicular to the
   % turtle's current heading.  The INLINE_SEMIAXIS is the distance
   % from the turtle to the ellipse in the direction in which the
   % turtle is currently heading.  Hence the turtle's heading
   % determines the orientation of the ellipse.  The elliptic arc
   % starts at angle parameter PARAMSTART degrees and the angle
   % parameter sweeps through a range of PARAMRANGE degrees.  The
   % elliptic arc is drawn clockwise if PARAMRANGE is positive and
   % counter-clockwise if PARAMRANGE is negative.
   apply(function logoturtle!-ellipticarc,
      logoturtle!-float!-args("ELLIPTICARC", 4, args));

put('ellipticarc, 'psopfn, 'ellipticarc);

symbolic procedure ellipse args; % (crosswise_semiaxis, inline_semiaxis)
   % Draw an ellipse based on the turtle's position and heading.  The
   % turtle does not move.  The center-point of the ellipse is the
   % turtle's current position.  The size and shape of the ellipse are
   % determined by the positive CROSSWISE_SEMIAXIS and
   % INLINE_SEMIAXIS.  The CROSSWISE_SEMIAXIS is the distance from the
   % turtle to the ellipse in the direction perpendicular to the
   % turtle's current heading.  The INLINE_SEMIAXIS is the distance
   % from the turtle to the ellipse in the direction in which the
   % turtle is currently heading.  Hence the turtle's heading
   % determines the orientation of the ellipse.
   apply(function logoturtle!-ellipticarc,
      360.0 . nconc(logoturtle!-float!-args("ELLIPSE", 2, args), '(0.0)));

put('ellipse, 'psopfn, 'ellipse);

symbolic procedure logoturtle!-ellipticarc(range, cross, inlin, start);
   begin scalar nsteps, h, delta, curve, cos_h, sin_h,
         inlin_sin_h,  cross_cos_h, inlin_cos_h, cross_sin_h;
      if cross <= 0.0 then typerr(cross, "ellipse semi-axis");
      if inlin <= 0.0 then typerr(inlin, "ellipse semi-axis");
      range := deg2rad range;   % angle param range in radians
      start := deg2rad start;   % initial angle param range in radians
      h := deg2rad logoturtle!-heading!*; % heading in radians
      cos_h := cos(h);  sin_h := sin(h);
      inlin_sin_h := inlin*sin_h;  cross_cos_h := cross*cos_h;
      inlin_cos_h := inlin*cos_h;  cross_sin_h := cross*sin_h;
      nsteps := fix abs(10.0*range);    % arcstep = radius/10.0
      delta := range/nsteps;
      curve := for n := 0 : nsteps collect
         begin scalar a := start + n*delta, cos_a := cos(a), sin_a := sin(a);
            return
               (logoturtle!-x!-coord!* + inlin_sin_h*cos_a + cross_cos_h*sin_a) .
                  (logoturtle!-y!-coord!* + inlin_cos_h*cos_a - cross_sin_h*sin_a)
         end;
      logoturtle!-curve!-seq!* := curve . logoturtle!-curve!-seq!*;
      logoturtle!-autodraw()
   end;

symbolic procedure arc2 args;           % (angle, radius)
   % Move the turtle along a circular arc that sweeps through the
   % specified angle with the specified positive radius.  The turtle
   % always moves forwards: if angle is positive, then the turtle
   % moves forwards in a clockwise direction; if angle is negative,
   % then the turtle moves forwards in a counter-clockwise direction.
   % At the end of the arc, the turtle's heading is increased by
   % angle.
   apply(function logoturtle!-arc2,
      logoturtle!-float!-args("ARC2", 2, args));

put('arc2, 'psopfn, 'arc2);

symbolic procedure circle2 radius;
   % Move the turtle clockwise around a circle with the specified
   % positive radius.  The turtle ends in the same position in which
   % it starts.
   logoturtle!-arc2(360.0, logoturtle!-float!-args("CIRCLE2", 1, radius));

put('circle2, 'psopfn, 'circle2);

symbolic procedure logoturtle!-arc2(angle, radius);
   begin scalar nsteps, a, h, x, y, delta;
      if radius <= 0.0 then typerr(radius, "radius");
      if angle < 0 then radius := -radius;
      a := deg2rad angle;                 % angle subtended in radians
      h := deg2rad logoturtle!-heading!*; % heading in radians
      x := logoturtle!-x!-coord!* + radius*cos(h); % centre of arc
      y := logoturtle!-y!-coord!* - radius*sin(h);
      nsteps := fix abs(10.0*a);        % arcstep = radius/10.0
      delta := a/nsteps;
      begin scalar !*logoturtle_autodraw;
         for n := 1 : nsteps do <<
            a := h + n*delta;
            logoturtle!-setxy(x - radius*cos(a), y + radius*sin(a))
         >>
      end;
      logoturtle!-setheading(logoturtle!-heading!* + angle);
      if !*logoturtle_autodraw and
         (!*logoturtle!-pen!-down or !*logoturtle!-shown) then draw()
   end;


% Turtle Motion Queries (all return values)
% =========================================

symbolic procedure pos;
   % Return the turtle's current position, as a list of two numbers,
   % the X and Y coordinates.
   {'list, logoturtle!-x!-coord!*, logoturtle!-y!-coord!* };

symbolic procedure xcor;
   % Return a number, the turtle's X coordinate.
   logoturtle!-x!-coord!*;

symbolic procedure ycor;
   % Return a number, the turtle's Y coordinate.
   logoturtle!-y!-coord!*;

symbolic procedure heading;
   % Return a number, the turtle's heading in degrees.
   logoturtle!-heading!*;

symbolic procedure towards posn;
   % Return a number, the heading at which the turtle should be facing
   % so that it would point from its current position to the position
   % given as input, which must be a list containing two items, the X
   % and Y coordinates.
   <<
      posn := logoturtle!-float!-args("TOWARDS", 'list, posn);
      atan2d(car posn - logoturtle!-x!-coord!*,
         cadr posn - logoturtle!-y!-coord!*)
   >>;

put('towards, 'psopfn, 'towards);

symbolic procedure distance posn;
    % Return a number, the distance the turtle must travel along a
    % straight line to reach the position given as input, which must
    % be a list containing two items, the X and Y coordinates.
   <<
      posn := logoturtle!-float!-args("DISTANCE", 'list, posn);
      hypot(car posn - logoturtle!-x!-coord!*,
         cadr posn - logoturtle!-y!-coord!*)
   >>;

put('distance, 'psopfn, 'distance);


% Turtle and Window Control (all commands return nothing)
% =======================================================

symbolic procedure showturtle;          % st
   % Make the turtle visible.
   if not !*logoturtle!-shown then <<
      !*logoturtle!-shown := t;
      logoturtle!-autodraw()
   >>;

symbolic procedure hideturtle;          % ht
   % Make the turtle invisible.
   if !*logoturtle!-shown then <<
      !*logoturtle!-shown := nil;
      logoturtle!-autodraw!-nothing()
   >>;

symbolic procedure clean;
   % Erase all lines that the turtle has drawn on the graphics window.
   % Also, erase all labels.
   % The turtle's state (position, heading, pen mode, etc.) is not
   % changed.  If the pen is down then start a new curve.
   <<
      logoturtle!-labels!* := logoturtle!-plot!* :=
      logoturtle!-curve!-seq!* := nil;
      logoturtle!-curve!* :=
         if !*logoturtle!-pen!-down then
            {logoturtle!-x!-coord!* . logoturtle!-y!-coord!*};
      logoturtle!-autodraw!-nothing()
   >>;

symbolic procedure clearscreen;         % cs;
   % Erase the graphics window and send the turtle to its initial
   % position and heading.  Like HOME and CLEAN together.
   begin scalar !*logoturtle_autodraw;
      plotreset;
      logoturtle!-x!-coord!* := 0.0;
      logoturtle!-y!-coord!* := 0.0;
      logoturtle!-heading!* := 0.0;
      clean()
   end;

symbolic procedure setwindowsize args;
   % If there is a single numerical argument N then the size of the
   % graphics window is set to -|N| <= x,y <= |N|; if there is a
   % single list argument {M, N} in which M and N are numerical or
   % there are two numerical arguments M, N then the size of the
   % graphics window is set to -|M| <= x <= |M|, -|N| <= y <= |N|.
   begin scalar l, m, n;
      if (l := length args) = 1 then
         (if numberp(n := reval car args) then <<
            logoturtle!-x!-max!* := logoturtle!-y!-max!* := abs n;
            return
         >> else if rlistp n and
            numberp(m := cadr n) and
            numberp(n := caddr n) then <<
               logoturtle!-x!-max!* := abs m;
               logoturtle!-y!-max!* := abs n;
               return
            >>)
      else if l = 2 then
         (if numberp(m := reval car args) and
            numberp(n := reval cadr args) then <<
               logoturtle!-x!-max!* := abs m;
               logoturtle!-y!-max!* := abs n;
               return
            >>);
      typerr(args, "argument(s) to SETWINDOWSIZE");
   end;

put('setwindowsize, 'psopfn, 'setwindowsize);

symbolic procedure wrap;
   % Tell the turtle to enter wrap mode: From now on, if the turtle is
   % asked to move past the boundary of the graphics window, it will
   % "wrap around" and reappear at the opposite edge of the window.
   % The top edge wraps to the bottom edge, while the left edge wraps
   % to the right edge.  (So the window is topologically equivalent to
   % a torus.)  This is the turtle's initial mode.
   <<
      logoturtle!-win!-mode!* := 'wrap;
   >>;

symbolic procedure window;
   % Tell the turtle to enter window mode: From now on, if the turtle
   % is asked to move past the boundary of the graphics window, it
   % will move offscreen.  The visible graphics window is considered
   % as just part of an infinite graphics plane; the turtle can be
   % anywhere on the plane.
   <<
      logoturtle!-win!-mode!* := 'window;
   >>;

symbolic procedure fence;
   % Tell the turtle to enter fence mode: From now on, if the turtle
   % is asked to move past the boundary of the graphics window, it
   % will move as far as it can and then stop at the edge with an "out
   % of bounds" error message.
   <<
      logoturtle!-win!-mode!* := 'fence;
   >>;

symbolic procedure setturtlemode mode;
   % Set the turtle (window) mode to one of WRAP, FENCE, WINDOW with
   % meaning as above or FALSE, meaning that (like Turtle) there are
   % no constraints on where the turtle draws.
   <<
      if mode memq '(wrap fence window) then
         logoturtle!-win!-mode!* := mode
      else if mode eq 'false then
         logoturtle!-win!-mode!* := nil
      else typerr(mode, "turtle mode");
   >>;

symbolic operator setturtlemode;

symbolic procedure fill;
   % Fill the region of the graphics window bounded by the lines that
   % have just been drawn, i.e. the current curve if the pen is down
   % or the last curve if the pen is up (or the pen colour or size has
   % been changed).  The fill colour is the current pen colour and the
   % pen size is ignored.  The curve is implicitly closed but the
   % turtle is not moved.
   begin                                % in order to use return
      if length logoturtle!-curve!* > 1 then
         % Current curve exists.  Save the current curve sequence
         % without the current curve:
         (if logoturtle!-curve!-seq!* then
            logoturtle!-plot!* := logoturtle!-make!-curve!-seq() .
               logoturtle!-plot!*)
      else
         % No current curve so retrieve the last curve saved as the
         % current curve:
         (if logoturtle!-curve!-seq!* then <<
            logoturtle!-curve!* := car logoturtle!-curve!-seq!*;
            logoturtle!-curve!-seq!* := cdr logoturtle!-curve!-seq!*;
            if logoturtle!-curve!-seq!* then
               logoturtle!-plot!* := logoturtle!-make!-curve!-seq() .
                  logoturtle!-plot!*
         >> else if logoturtle!-plot!* then <<
            logoturtle!-curve!-seq!* := car logoturtle!-plot!*;
            logoturtle!-plot!* := cdr logoturtle!-plot!*;
            logoturtle!-curve!* := caddr logoturtle!-curve!-seq!*;
            if cdddr logoturtle!-curve!-seq!* then <<
               logoturtle!-curve!-seq!* := car logoturtle!-curve!-seq!* .
                  cadr logoturtle!-curve!-seq!* .
                     cdddr logoturtle!-curve!-seq!*;
               logoturtle!-plot!* := logoturtle!-curve!-seq!* .
                  logoturtle!-plot!*
            >>
         >> else return);               % nothing to fill!

      % Save the current curve to a new filled curve sequence:
      logoturtle!-plot!* := logoturtle!-make!-fill() .
         logoturtle!-plot!*;
      % Start a new curve sequence:
      logoturtle!-new!-curve!-seq();
      logoturtle!-autodraw()
   end;

symbolic procedure filled args;         % (color, commands)
   % The first argument should specify a colour as a colour number,
   % RGB list, etc, or false meaning that the current pen colour is
   % used; otherwise the pen colour is ignored.  Subsequent arguments
   % should be commands or lists of commands that move the turtle or
   % draw curves.  Execute these in the order written, remembering all
   % points visited.  Then draw the resulting curve, starting and
   % ending with the turtle's initial position, filled with the
   % specified colour.  The pen size and whether the pen is up or down
   % are ignored.
   begin scalar !*logoturtle!-pen!-down := t,
         color := logoturtle!-colorspec reval car args
            or get('logoturtle!-curve!-seq!*, 'lc);
      logoturtle!-save!-curve!-seq();
      logoturtle!-new!-curve();
      % Run the turtle motion commands...
      for each arg in cdr args do reval arg;
      % which may generate a current curve or (arc, circle) a current
      % curve sequence, so if no current curve then retrieve the last
      % curve saved as the current curve:
      if length logoturtle!-curve!* <= 1 then <<
         if logoturtle!-curve!-seq!* then <<
            logoturtle!-curve!* := car logoturtle!-curve!-seq!*;
            logoturtle!-curve!-seq!* := cdr logoturtle!-curve!-seq!*;
            if logoturtle!-curve!-seq!* then
               logoturtle!-plot!* := logoturtle!-make!-curve!-seq() .
                  logoturtle!-plot!*
         >> else return                 % nothing to fill!
      >>;
      logoturtle!-plot!* := logoturtle!-make!-fill color .
         logoturtle!-plot!*;
      logoturtle!-new!-curve!-seq();
      logoturtle!-autodraw()
   end;

put('filled, 'psopfn, 'filled);

symbolic procedure label text;
   % Take a printable item or list of printable items as input and
   % print it on the graphics window, starting at the turtle's
   % position.  The items in a list are concatenated with no
   % additional spacing.  Long labels may fail!
   begin scalar font, color, style;
      if atom text then text := {text}
      else <<
         if not rlistp text then typerr(text, "label text");
         for each x in cdr text do
            if not atom x then typerr(text, "label text");
         text := cdr text
      >>;
      if (font := get('logoturtle!-labels!*, 'font)) then
         begin scalar face := car font, size := cdr font;
            % font "{<name>}{,<size>}"
            font := '("""");
            if size then font := "," . size . font;
            if face then font := face . font;
            font := " font """ . font;
         end;
      if (color := get('logoturtle!-labels!*, 'color)) then
         color := {" textcolor rgb """, color, """"};
      style := append(font, color);
      logoturtle!-labels!* :=
         (text . (logoturtle!-x!-coord!* . logoturtle!-y!-coord!*) . style) .
            logoturtle!-labels!*;
      logoturtle!-autodraw()
   end;

symbolic operator label;

symbolic procedure setlabelfont args; % (face/size, size) or {face, size}
   % Set the face and/or size of the label font.  If the face is
   % specified then it should be the only or first input and must be
   % an identifier or string, e.g. \"Arial\".  If the size is
   % specified then it should be the only or second input and must be
   % a positive integer.  If only one of the face and size is set then
   % the other reverts to the default, not the previous value set.
   % Alternatively, the single input can be a list of the form {face,
   % size}, or false to revert to the default.  The inputs must
   % specify a font in a way that is accepted by Gnuplot but the
   % details of font setting depend on the Gnuplot terminal in use.
   % The defaults for the wxt terminal are face Sans and size 10.  For
   % the canvas terminal (and hence on Web REDUCE) setting the label
   % font face is ignored.
   begin scalar face, size, arg1 := reval car args;
      if arg1 eq 'false then <<
         if cdr args then go to error;
         remprop('logoturtle!-labels!*, 'font);
         return
      >>;
      if rlistp arg1 then <<
         if cdr args then go to error;
         face := cadr arg1;
         size := caddr arg1
      >> else if fixp arg1 then <<
         if cdr args then go to error;
         size := arg1
      >> else <<
         face := arg1;
         if cdr args then size := reval cadr args
      >>;
      if face and not(idp face or stringp face) then
         typerr(face, "font face");
      if size and not(fixp size and size > 0) then
         typerr(size, "font size");
      put('logoturtle!-labels!*, 'font, face . size);
      return;
   error: typerr(args, "multiple SETLABELFONT arguments")
   end;

put('setlabelfont, 'psopfn, 'setlabelfont);

symbolic procedure setlabelcolor color;
   % Set the label foreground colour, cf. setpencolor.
   <<
      if (color := logoturtle!-colorspec color) then
         put('logoturtle!-labels!*, 'color, color)
      else
         remprop('logoturtle!-labels!*, 'color);
   >>;

symbolic operator setlabelcolor;


% Turtle and Window Queries (all return values)
% =============================================

symbolic procedure shownp;
   % Return TRUE if the turtle is shown (visible), FALSE if the turtle
   % is hidden. See SHOWTURTLE and HIDETURTLE.
   if !*logoturtle!-shown then 'true else 'false;

symbolic procedure windowsize;
   % Return the current size of the graphics window as a list of the
   % form {x_max, y_max}.
   {'list, logoturtle!-x!-max!*, logoturtle!-y!-max!*};

symbolic procedure turtlemode;
   % Return the word WRAP, FENCE, WINDOW or FALSE depending on the
   % current turtle (window) mode.
   logoturtle!-win!-mode!* or 'false;

symbolic procedure labelfont;
   % Return a list of the current label font face and size if both are
   % set, or whichever of the face or size is set, or false.
   begin scalar font, face, size;       % font = (face . size)
      if not (font := get('logoturtle!-labels!*, 'font)) then
         return 'false;
      face := car font;  size := cdr font;
      if face then
         return if size then {'list, face, size} else face;
      return size or 'false
   end;

symbolic procedure labelcolor;
   % Return the current label foreground colour, cf. pencolor.
   begin scalar color := get('logoturtle!-labels!*, 'color);
      return if color then color else 'false;
   end;


% Pen and Background Control (all commands return nothing)
% ========================================================

% The turtle carries a pen that can draw pictures.  At any time the
% pen can be UP (in which case moving the turtle does not change
% what's on the graphics screen) or DOWN (in which case the turtle
% leaves a trace).  Initially, the pen is UP.

symbolic procedure pendown;             % pd
   % Set the pen's position to DOWN, without changing its mode.
   % Initialize a new curve if the pen was up.
   if not !*logoturtle!-pen!-down then <<
      logoturtle!-new!-curve();
      !*logoturtle!-pen!-down := t;
   >>;

symbolic procedure penup;               % pu
   % Set the pen's position to UP, without changing its mode.
   % Save the current curve if the pen was down.
   if !*logoturtle!-pen!-down then <<
      logoturtle!-save!-curve();
      logoturtle!-curve!* := nil;
      !*logoturtle!-pen!-down := nil;
   >>;

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
   <<
      color := logoturtle!-colorspec color;
      % Changing the pen colour terminates the current curve
      % sequence with the current line style, saves the new line
      % style and starts a new curve sequence.
      logoturtle!-save!-curve!-seq();
      if color then
         put('logoturtle!-curve!-seq!*, 'lc, color)
      else
         remprop('logoturtle!-curve!-seq!*, 'lc);
      logoturtle!-new!-curve!-seq();
   >>;

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
   % Evaluate r,g,b to Lisp floats or throw a type error,
   % cf. logoturtle!-float!-args.
   % Return string "#RRGGBB", where R,G,B are hex digits.
   begin scalar pr, v := '(!");
      if not(length color eq 4) then
         typerr(color, "RGB list of percent color saturations");
      pr := plotrounded nil;            % turn on rounded mode safely
      precision 10;
      % For each percent value p in reversed RGB list:
      for each p in reversip cdr color do <<
         p := reval p;
         p := if fixp p then float p
         else if eqcar(p, '!:rd!:) and floatp(p := cdr p) then p;
         % else nil!
         if null p or p < 0.0 or p > 100.0 then
            typerr(color, "RGB list of percent color saturations");
         p := fix(p*2.55 + 0.5);
         % Convert p to two hexadecimal digits:
         p := divide(p, 16);         % (quo . rem)
         v := getv(logoturtle!-hex!-digits!*, car p) .
            getv(logoturtle!-hex!-digits!*, cdr p) . v
      >>;
      plotrounded pr;                   % restore global domain mode
      return compress('!" . '!# . v)
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
   <<
      if fixp colornumber and colornumber >= 0 and colornumber <= 15 then
         putv(logoturtle!-colors!*, colornumber,
            if stringp rgblist or idp rgblist then rgblist
            else if eqcar(rgblist, 'list) then
               logoturtle!-rgblist2hexstring rgblist
            else typerr(rgblist, "color name or RGB list"))
      else
         typerr(colornumber, "color number between 8 and 15");
   >>;

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
   begin                                % for return!
      if null (logoturtle!-term!* or
         (logoturtle!-term!* := getenv "GNUTERM"))
      then return
         msgpri("GNUTERM environment variable not set",nil,nil,nil,nil);
      if (color := logoturtle!-colorspec color) then
         put('logoturtle!-plot!*, 'logoturtle!-bg, color)
      else
         remprop('logoturtle!-plot!*, 'logoturtle!-bg)
   end;

symbolic operator setbackground;


% Pen and Background Queries (all return values)
% ==============================================

symbolic procedure pendownp;
   % Return TRUE if the pen is down, FALSE if it's up.
   if !*logoturtle!-pen!-down then 'true else 'false;

symbolic procedure pencolor;            % PC
   % Return the pen colour as a string or identifier that represents a
   % colour in any way that is acceptable to Gnuplot, such as a colour
   % name or hexadecimal number.  Alternatively, output the identifier
   % FALSE meaning that no colour is set.
   begin scalar color := get('logoturtle!-curve!-seq!*, 'lc);
      return if color then color else 'false;
   end;

symbolic procedure palette colornumber;
   % Colornumber must be a nonnegative integer not greater than 15.
   % Return a string or identifier that represents the colour
   % associated with the given number in any way that is acceptable to
   % Gnuplot, such as a colour name or hexadecimal number.
   if fixp colornumber and colornumber >= 0 and colornumber <= 15 then
      getv(logoturtle!-colors!*, colornumber)
   else
      typerr(colornumber, "color number between 0 and 15");

symbolic operator palette;

symbolic procedure pensize;
   % Return a positive integer specifying the thickness of the turtle
   % pen as a multiple of the default thickness, or false, meaning
   % unspecified, which is effectively equivalent to 1 but slightly
   % less efficient.
   begin scalar size :=
      get('logoturtle!-curve!-seq!*, 'lw);
      return if size then size else 'false
   end;

symbolic procedure background;          % bg
   % Return the graphics background colour as a string or identifier
   % that represents a colour in any way that is acceptable to
   % Gnuplot, such as a colour name or hexadecimal number.
   % Alternatively, output the identifier FALSE meaning that no colour
   % is set.
   begin scalar colorspec :=
      get('logoturtle!-plot!*, 'logoturtle!-bg);
      return if colorspec then colorspec else 'false
   end;


% Saving and Loading Pictures (all commands return nothing)
% =========================================================

% These two commands save to, and load from, an internal LogoTurtle
% namespace (the property list of the identifier logoturtle!-plot!*).
% The data saved has the form (plot . label-list).

symbolic procedure savepict identifier;
   % Save the current plot and labels to internal storage under the
   % specified identifier without changing them.  The saved data can
   % be restored as the current plot and labels using LOADPICT.
   <<
      if not idp identifier then
         typerr(identifier, "LogoTurtle SAVEPICT identifier");
      put('logoturtle!-plot!*, identifier,
         logoturtle!-get!-plot() . logoturtle!-labels!*);
   >>;

symbolic operator savepict;

symbolic procedure loadpict identifiers;
   % Retrieve the plots and labels stored under the specified
   % identifiers, which must have been stored by a SAVEPICT command,
   % merge them in input order so that later plots and labels overlay
   % earlier ones, and make the result current.  The previous current
   % plot and labels are lost if not saved using SAVEPICT.
   begin scalar tmp;
      % Normally curve sequences are consed onto the front of
      % logoturtle!-plot!* as they are generated; then the plot is
      % reversed in draw.  But labels are drawn in list order without
      % being reversed.
      logoturtle!-plot!* := logoturtle!-labels!* := nil;
      for each id in identifiers do
      <<
         if not( idp(id := reval id)
            and (tmp := get('logoturtle!-plot!*, id)) ) then
               typerr(id, "LogoTurtle LOADPICT identifier");
         % Use append to copy each plot list and avoid any mangling!
         if car tmp then
            logoturtle!-plot!* := append(car tmp, logoturtle!-plot!*);
         if cdr tmp then nconc(logoturtle!-labels!*, cdr tmp)
      >>;
      logoturtle!-curve!* := logoturtle!-curve!-seq!* := nil;
      logoturtle!-autodraw()
   end;

put('loadpict, 'psopfn, 'loadpict);


% Special processing for commands that take no arguments
% ======================================================

symbolic procedure logoturtle!-stat;
   % Read a command that takes no arguments, like endstat but without
   % trying to read an end comment.  Also, ignore following empty
   % parentheses and ignore but complain about any arguments.
   begin scalar cmd := cursym!*;
      scan();
      if cursym!* eq '!*lpar!* then <<
         scan();
         if not(cursym!* eq '!*rpar!*) then <<
            lprim {cmd, "takes no arguments"};
            while not(cursym!* eq '!*rpar!*) do scan()
         >>;
         scan()
      >>;
      return list cmd
   end;

flag('(logoturtle!-stat), 'endstatfn);

for each cmd in logoturtle!-noarg!* do
   put(cmd, 'stat, 'logoturtle!-stat);

% Don't change display mode to symbolic for these query commands:
flag('(pos windowsize labelfont), 'nochange);

endmodule;

end;
