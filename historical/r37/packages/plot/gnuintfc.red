module gnuintfc; % REDUCE-gnuplot interface.

% Authors:  Anthony C. Hearn, Herbert Melenk, Arthur C. Norman.

% The file complements the (notionally) generic file "gnuplot.red" to
% provide system-specific interfaces between REDUCE and the gnuplot
% package itself.

fluid '(plotstyle!*);

global '(!*plotinterrupts !*plotpause !*plotusepipe plotheader!*
	 plotcleanup!* plottmp!*);

!#if (member 'psl lispsystem!*)
   !#if (member 'unix lispsystem!*)

   !*plotusepipe:=t;               % pipes: yes
   load pipes;
   !*plotpause:=nil;                 % pause: no
   plottmp!* := "/tmp/";
   if getenv "LOGNAME" then
      plottmp!* := bldmsg("%w%w.",plottmp!*,getenv "LOGNAME")
    else if getenv "USER" then
      plottmp!* := bldmsg("%w%w.",plottmp!*,getenv "USER");
   plotdta!* := for i:=1:10 collect
         bldmsg("%wplotdta%w*",plottmp!*,i); % scratch data files
   plotcmds!* :=bldmsg("%wplotcmds*",plottmp!*); % if pipes not accessible
    
     % select header lines for setting the appropriate GNUPLOT
     % terminal type.

   if null plotheader!* then
   << if null x then x:='(nil."dumb");
      plotheader!* := bldmsg("set term %w",cdr x);
   >> 
     where x = 
      assoc(getenv "TERM",
           '(
          %% You may want to extend or modify the terminal list above
                ("xterm" . "x11")
		("sun-cmd" . "x11")  ("sun" . "x11")
                ("hpterm" . "x11")
                ("vt52"  . "tek40xx")
                ("vt100" . "tek40xx")
                ("vt102" . "tek40xx")
           ));
                   
      % add $reduce/plot to the path when using X11 (gnuplot will load a child).
   plotcommand!*:=
    begin scalar p;
     if not(p:=getenv "gnuplot") then
        p:=bldmsg("%w/plot",getenv "reduce");
     return bldmsg("PATH=$PATH:%w;export PATH;gnuplot",p);
    end;
    
   plotcleanup!* :=                  % delete scratch files
       {"rm /tmp/plotdt*","rm /tmp/plotcmds!*"};
   !*plotinterrupts := '(10002);

   !#elif (intersection '(dos os2 win32 winnt alphant) lispsystem!*)

fluid '(!*!*windows);

     % the following system selection must be done at load time

   plottmp!* := bldmsg("%w\",getenv "tmp" or getenv "temp");
   if null plottmp!* then
   <<prin2t "warning: no TMP directory found. Using >C:<";
     plottmp!*:="c:";
   >>;
   !*plotpause:=nil;                       % no pause 
   plotdta!* := for i:=1:10 collect
         bldmsg("%wplotdt%w.dat",plottmp!*,i); % scratch data files

   if member ('win95,lispsystem!*) then
    <<
      % for Win95 until we have something better
      %   pass commands as parameter file
      %   write command file and data to directory /tmp

     !*plotusepipe:=nil;                   % no pipes
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);
     plotcommand!* :=                        
%    fnexpand bldmsg("$reduce\plot\wgnuplot.exe %w",plotcmds!*);
     fnexpand bldmsg("$reduce\wutil\win32\wgnuplot.exe %w",plotcmds!*);
     plotheader!* :=  "";
     plotcleanup!* := NIL;                 % delete scratch files
     !*plotpause := -1;
     copyd('plot!-exec,'system);
     flag('(plot!-exec),'lose);
    >> else

   if !*!*windows eq 1 or member('winnt,lispsystem!*)
                       or member('win32 ,lispsystem!*) then
   <<    
      % for windows:
      %  use plot pipe
     load w!-pipes;
     !*plotusepipe:=t;     
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);;           
     plotcommand!* := bldmsg(
%      "%w\plot\wgnupl32.exe;wgnuplot_parent;wgnuplot_text",
%      "%w\plot\wgnuplot.exe;wgnuplot_parent;wgnuplot_text",
       "%w\wutil\win32\wgnuplot.exe;wgnuplot_parent;wgnuplot_text",
        getenv("reduce"));
     plotheader!* := "";
     plotcleanup!* :=                     % delete scratch files
       bldmsg("del %w",plotcmds!*) .
        for each f in plotdta!* collect bldmsg("del %w",f);
    >> 
  else if member('os2,lispsystem!*) then
    <<
     !*plotusepipe:=nil;                   % no pipes
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);
     plotcommand!* := ""; 
     plotheader!* := "";

     symbolic procedure plot!-exec u;
       <<
         prin2 "====> invoke GNUPLOT for file ";
         prin2t plotcmds!*;
       >>;

     loadtime flag('(plot!-exec),'lose);
    >>
  else 
    <<
      % for dos:
      %   pass commands as parameter file
      %   write command file and data to directory /tmp

     !*plotusepipe:=nil;                   % no pipes
     plotcmds!* := bldmsg("%w\plotcmds",plottmp!*);
     plotcommand!* := 
     fnexpand bldmsg("$reduce\plot\gnuplot.exe %w",plotcmds!*);
     plotheader!* :=  "set term vga";
     plotcleanup!* :=                     % delete scratch files
       bldmsg("del %w",plotcmds!*).
        for each f in plotdta!* collect bldmsg("del %w",f);
    >>;


  plotmax!* := 3e36;                    % IEEE single precision 
  !*plotinterrupts := '(10002);

   !#elif (member 'vms lispsystem!*)

   !*plotusepipe:=NIL;               % pipes: yes
   !*plotpause:=nil;                 % pause: no
   plottmp!* := "SYS$SCRATCH";
   plotdta!* := for i:=1:10 collect
	 bldmsg("%w:plotdt%w",plottmp!*,i); % scratch data files
   plotcmds!* :=bldmsg("%w:plotcmds",plottmp!*); % if pipes not accessible
   plotcommand!* := bldmsg("gnuplot %w",plotcmds!*);
   plotheader!* :=  "set term x11";  % header: set terminal to X11
   plotcleanup!* :=                  % delete scratch files
       {"del SYS$SCRATCH:plotdt*;*","del SYS$SCRATCH:plotcmds*;*"};
   !*plotinterrupts := '(10002);

  !#endif

 !#elif(member 'csl lispsystem!*)

global '(plotdir!* dirchar!* opsys!* tempdir!*);

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
if getenv "gnuplot" then plotdir!* := getenv "gnuplot"
% Otherwise, and this is what I hope and expect to happen more often, I
% will expect to find gnuplot in the same directory that REDUCE was
% loaded from. This will all work wonderfully under Windows, but under Unix
% there is a much greater chance that I will need to set an environment
% variable "gnuplot". However, I still want to leave open the possibility
% of plotdir!* being set.
 else if null plotdir!* and not (opsys!* = 'unix)
  then plotdir!* := get!-lisp!-directory();


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

!#endif

endmodule;

end;
