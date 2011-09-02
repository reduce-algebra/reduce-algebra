module rgpcsl.red; % REDUCE-gnuplot configuration for CSL

%
% The file complements the (notionally) generic file "gnuplot.red" to
% provide system-specific interfaces between REDUCE and the gnuplot
% package itself.
%        A C Norman. 1996

global '(plottemp!* plotdir!* dirchar!* opsys!* tempdir!*);

symbolic procedure channelflush x;
  << x := wrs x; flush(); wrs x >>;

symbolic procedure gtmpnam base;
  if null tempdir!* then base
  else compress ('!" . append(explodec tempdir!*, 
                              car explodec dirchar!* . cdr explode base));

% In general I want the initialisation actions indicated here to be
% obeyed at load-time. I achieve this by packaging them all inside
% a function, which I then call. I could be even more CSL-specific by
% using eval-when style options imported from the Common Lisp world...

symbolic procedure init_gnuplot();
 <<

!*plotpause := -1;                % wait for newline from user

% plotcleanup!* is a list of commands to be obeyed after a gnuplot run.
% it is mainly needed to get rid of the data file (used even when pipes
% are available).
plotcleanup!* := {};

tempdir!* := getenv 'tmp;
if null tempdir!* then tempdir!* := getenv 'temp;


dirchar!* := "/";
plotcommand!* := "gnuplot";
opsys!* := assoc('opsys, lispsystem!*);
if null opsys!* then opsys!* := 'unknown
else opsys!* := cdr opsys!*;

% If a shell variable "gnuplot" is set it is expected to be the
% directory within which gnuplot binaries can be found.
plotdir!* := getenv "gnuplot";
% Otherwise, and this is what I hope and expect to happen more often, I
% will expect to find gnuplot in the same directory that REDUCE was
% loaded from. This will all work wonderfully under Windows, but under Unix
% there is a much greater chance that I will need to set an environment
% variable "gnuplot".
if null plotdir!* and not (opsys!* = 'unix) then
   plotdir!* := get!-lisp!-directory();


if opsys!* = 'win32 then <<
% For Microsoft Windows use I try to use "wgnuplot" rather than "gnuplot",
% and the options provided are copied from the PSL case above.
    plotcommand!* := "wgnuplot";
    plotheader!* := "";
    dirchar!* := "\";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcleanup!* := if null tempdir!* then {"erase gnutmp.tm*"}
                     else {bldmsg("erase %w\gnutmp.tm*", tempdir!*)} >>
    
else if opsys!* = 'msdos then <<
% Under MSDOS the PSL version sets a VGA screen explicitly - that seems to
% upset the version of gnuplot that I have to test.  Also I find "tmpnam"
% somewhat unhelpful, I can do a bit better (I hope) here.
    plotheader!* := "";      % ?? "set term vga";
    dirchar!* := "\";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcmds!*:= gtmpnam "gnutmp.tm0";
    plotcleanup!* := if null tempdir!* then {"erase gnutmp.tm*"}
                     else {bldmsg("erase %w\gnutmp.tm*", tempdir!*)} >>

else if opsys!* = 'riscos then <<
% Under RiscOS I need to be running under the window system for GNUPLOT
% to be available. I will not test for that here but will expect the
% "PLOT" command to fail if run from the command line.
    plotheader!* := "";
    dirchar!* := ".";
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotcleanup!* :=
       bldmsg("remove %w", plotcmds!*) .
          for each f in plotdta!* collect bldmsg("remove %w", f)
    >>

else if opsys!* = 'unix then <<
% For Unix I assume X11.
    plotheader!* := "set term x11";
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotcleanup!* :=
       bldmsg("rm %w", plotcmds!*) .
          for each f in plotdta!* collect bldmsg("rm %w", f) >>

else <<
% Other systems set up for a dumb terminal.  This is probably unsatisfactory,
% but you can easily change the source here to adjust for what you want.
% If you just comment out the "rederr" line you will have gnuplot working
% in dumb-terminal mode.
    rederr bldmsg("gnuplot for %w not available yet", opsys!*);
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotheader!* := "set term dumb" >>;



% If there are no pipes available gnuplot will need a command-line
% argument indicating where its input file is.

if 'pipes member lispsystem!* then !*plotusepipe:=t
else plotcommand!* := bldmsg("%w %w", plotcommand!*, plotcmds!*);

% If I have a directory to look for gnuplot in I either just give a
% full path or (under Unix) I temporarily switch current directories
% to there.

if plotdir!* then
    plotcommand!* := bldmsg("%w%w%w",
                            plotdir!*, dirchar!*, plotcommand!*);

% Under Windows 95 I want the plotting sub-task to finish before I
% resume running REDUCE (and delete the temporary files). This may be an
% area where Windows 95 and NT are not compatible. If so tough luck for now.
% Actually if I am going to call wgnuplot rather than gnuplot this is
% not a useful thing to do after all...

%  if 'win95 member lispsystem!* then
%      plotcommand!* := bldmsg("start /w %w", plotcommand!*);

   nil >>;

init_gnuplot();

endmodule;

end;

