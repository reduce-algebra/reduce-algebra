module gnuintfc; % REDUCE-gnuplot interface.

% Authors:  Anthony C. Hearn, Herbert Melenk, Arthur C. Norman.

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%


% The file complements the (notionally) generic file "gnuplot.red" to
% provide system-specific interfaces between REDUCE and the gnuplot
% package itself.

fluid '(plotstyle!*);

global '(
   !*plotinterrupts			% list of error codes caused by interrupts (ctl-C)
   !*plotpause 				% NIL if gnuplot should not wait 
   !*plotusepipe	                % T if using pipes, NIL if writing to command file
   plotheader!*				% list of Gnuplot commands (strings) for initializing GNUPLOT
   plotcleanup!*                        % list of OS command for cleaning up (like removing temp files
   plottmp!*				% location of temporary files (including trailing directory spearator)
      );

% Since it was first introduced the GNUPLOT package has passed a command
% "set term XXX" to gnuplot, where XXX has typically been x11, aqua, vga
% tek40xx or even dumb. At least with early versions of gnuplot that
% was essential. It is possible - even probable - that modern versions of
% gnuplot inspect their environment and choose a good terminal for themselves.
% But it is reported that even now there are some users who are not content
% with either the choices we make here or the ones that gnuplot makes for
% itself so thet feel that they need to override things by putting directives
% in comfiguration files or ebvironment variables that will control exactly
% how gnuplot behaves. Such people are then invonvenienced if this Reduce
% code forces an issue. So to preserve backwards compatibility and keep
% everybody safe while supporting the latestm this switch is provided.
% The default in "on force_gnuplot_term;" and that behaves just as Reduce has
% for some while. If you specify "off force_gnuplot_term;" then it is probably
% that in many circumstances gnuplot itself will pick sensible options, but
% more importantly you gain the ability to guess better than gnuplot itself and
% force your own customised choice of behaviour using ~/.gnuplot or
% GNUPLOT.INI, or by setting GNUTERM etc - all as described in the gnuplot
% documentation.
% If somebody can show that they have done sufficiently extensive tests using
% a wide range of current and somewhat elderly operating systems as well as
% current and legacy versions of gnuplot so as to document that it would be
% safe these days to make the default of this switch "off" rather than "on"
% we can then change the default.
% A further mess here is that I need to put the switch declaration in
% support/entry.red so that it can be used before gnuplot is loaded and also
% to be fully certain that the establishment of its initial value is not
% re-done during the package loading process. I also need to ensure that
% nothing that depends on it is activated at load time rather than just
% when an attempt is made to create a plot.

% switch force_gnuplot_term=on;

global '(plotcommand!* gnuplot_select_terminal!*);

% The initialize_gnuplot() function will set plotcommand!*.

gnuplot_select_terminal!* :=
"if(strstrt(GPVAL_TERMINALS,""aqua"")!=0)set terminal aqua;else set term x11;";

#if (member 'psl lispsystem!*)
%%%%%%%%%%%%%%%%%%%%%%%%%%% PSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(!*!*windows);

symbolic procedure initialize_gnuplot();
 <<
   #if (member 'unix lispsystem!*)

   !*plotusepipe:=t;               % pipes: yes
   !*plotpause:=nil;                 % pause: no
   if getenv "LOGNAME" then
      plottmp!* := bldmsg("%w%w%w.",get!-tempdir(),dirchar!*,getenv "LOGNAME")
    else if getenv "USER" then
      plottmp!* := bldmsg("%w%w%w.",get!-tempdir(),dirchar!*,getenv "USER")
    else 
      plottmp!* := concat(get!-tempdir(),dirchar!*);
   plotdta!* := for i:=1:10 collect
         bldmsg("%wplotdt%w",plottmp!*,i); % scratch data files
   plotcmds!* :=bldmsg("%wplotcmds",plottmp!*); % if pipes not accessible

     % select header lines for setting the appropriate GNUPLOT
     % terminal type if force_gnuplot_term is set on.

   if null plotheader!* then
   if null !*force_gnuplot_term then plotheader!* := ""
   else << if null x then
      if getenv "DISPLAY" then x := nil . gnuplot_select_terminal!*
                        else x:='(nil."dumb");
      if wlessp (strlen strinf cdr x, 20) 
                 then  plotheader!* :=bldmsg("set term %w",cdr x)
                       else plotheader!* := cdr x ;
   >>
     where x =
      assoc(getenv "TERM",
	    ("xterm" . gnuplot_select_terminal!*) .
	    ("xterm-color" . gnuplot_select_terminal!*) .
           '(
          %% You may want to extend or modify the terminal list above
                ("sun-cmd" . "x11")
                ("sun" . "x11")
                ("hpterm" . "x11")
                ("vt52"  . "tek40xx")
                ("vt100" . "tek40xx")
                ("vt102" . "tek40xx")
           ));

   plotcommand!* := find!-gnuplot();

   plotcleanup!* :=                  % delete scratch files
       {bldmsg("rm %wplotdt*",plottmp!*),bldmsg("rm %wplotcmds*",plottmp!*)};
   !*plotinterrupts := '(10002);

   #elif (intersection '(dos os2 win32 win64 winnt alphant) lispsystem!*)

   if null get!-tempdir() then
   <<prin2t "warning: no TMP directory found. Using >C:<";
     plottmp!*:="C:\" >>
   else plottmp!* := bldmsg("%w%w",get!-tempdir(),dirchar!*);
   !*plotpause:=nil;                       % no pause
   plotdta!* := for i:=1:10 collect
         bldmsg("%wplotdt%w.dat",plottmp!*,i); % scratch data files

%:   if member ('win95,lispsystem!*) then    % No longer worth supporting?
%:    <<
%:     !*plotusepipe:=nil;                   % no pipes
%:     plotcmds!* := bldmsg("%wplotcmds",plottmp!*);
%:     plotcommand!* :=
%:       % The path on the next line will no longer apply!
%:       fnexpand bldmsg("$reduce\wutil\win32\wgnuplot.exe %w",plotcmds!*);
%:     plotheader!* :=  "";
%:     plotcleanup!* := NIL;                 % delete scratch files
%:     !*plotpause := -1;
%:    >> else

   if !*!*windows eq 1 or member('winnt,lispsystem!*)
                       or member('win32,lispsystem!*)
                       or member('win64,lispsystem!*) then
   <<
     if not getd 'pipe!-open then load w!-pipes;
     !*plotusepipe:=t;
     plotcmds!* := bldmsg("%wplotcmds",plottmp!*);;
     plotcommand!* := find!-gnuplot();
     plotheader!* := "";
     plotcleanup!* :=                     % delete scratch files
       bldmsg("del %w",plotcmds!*) .
        for each f in plotdta!* collect bldmsg("del %w",f);
%: I am commenting out the support for OS2 and DOS. It looks as if on
%: OS2 the code here wrote out data to a file and asked the user to launch
%: gnuplot. For DOS it assumed there was a gnuplot executable at the path
%: $reduce\wutil\dos386\gnuplot.exe and that is certainly not something that
%: is routinely available in current versions of Reduce.
%:    >>
%:  else if member('os2,lispsystem!*) then  % Does anybody still use OS2?
%:    <<
%:     !*plotusepipe:=nil;                   % no pipes
%:     plotcmds!* := bldmsg("%wplotcmds",plottmp!*);
%:     plotcommand!* := "";
%:     plotheader!* := "";
%:
%:     symbolic procedure plot!-exec u;
%:       <<
%:         prin2 "====> invoke GNUPLOT for file ";
%:         prin2t plotcmds!*;
%:       >>;
%:
%:     loadtime flag('(plot!-exec),'lose);
%:    >>
%:  else
%:    <<
%:      % for dos:
%:      %   pass commands as parameter file
%:      %   write command file and data to directory /tmp
%:
%:     !*plotusepipe:=nil;                   % no pipes
%:     plotcmds!* := bldmsg("%wplotcmds",plottmp!*);
%:     plotcommand!* :=
%:       fnexpand bldmsg("$reduce\wutil\dos386\gnuplot.exe %w",plotcmds!*);
%:     if !*force_gnuplot_term then plotheader!* :=  "set term vga";
%:     else plotheader!* := "";
%:     plotcleanup!* :=                     % delete scratch files
%:       bldmsg("del %w",plotcmds!*).
%:        for each f in plotdta!* collect bldmsg("del %w",f);
    >>;
  !*plotinterrupts := '(10002);

   #elif (member 'vms lispsystem!*)

   !*plotusepipe:=NIL;               % pipes: no
   !*plotpause:=nil;                 % pause: no
   %plottmp!* := "SYS$SCRATCH:";
   plottmp!* := get!-tempdir();
   plotdta!* := for i:=1:10 collect
         bldmsg("%wplotdt%w",plottmp!*,i); % scratch data files
   plotcmds!* :=bldmsg("%wplotcmds",plottmp!*); % if pipes not accessible
   plotcommand!* := bldmsg("gnuplot %w",plotcmds!*);
   if !*force_gnuplot_term then plotheader!* :=    "set term x11;";
   else plotheader!* := "";
   plotcleanup!* :=                  % delete scratch files
       {bldmsg("del %wplotdt*;*",plottmp!*),bldmsg("del %wplotcmds*;*",plottmp!*)};
   !*plotinterrupts := '(10002);

  #endif
% end of definition of initialize_gnuplot();
  >>;

%%%%%%%%%%%%%%%%%%%%%%%%%%% CSL %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#elif (member 'csl lispsystem!*)

%
% If the user has set environment variables called "tmp" or "temp" then
% that specify (in that priority order) directories to place temporary data
% in. If neither is set then a function tmpdir() from CSL is called to deliver
% a suitable location.


global '(plotdir!* dirchar!* opsys!* tempdir!*);

symbolic procedure channelflush x;
  << x := wrs x; flush(); wrs x >>;

symbolic procedure gtmpnam base;
  if null tempdir!* then base
  else compress ('!" . append(explode2 tempdir!*,
                              car explode2 dirchar!* . cdr explode base));

symbolic procedure initialize_gnuplot();
begin
  scalar w;
  !*plotpause := -1;                % wait for newline from user

  tempdir!* := getenv 'tmp;
  if null tempdir!* then tempdir!* := getenv 'temp;
% Because the tmpdir() function is new in October 2014 I will check for
% its availability before use. On cygwin tmpdir passes back a "mixed" format
% name such as "C:/cygwin/tmp" which tends to make it safe to pass to the
% shell in case where back-slashes might be an issue, however note that
% there could be whitespace in the path.
  if null tempdir!* and getd 'tmpdir then tempdir!* := tmpdir();

  !*plotusepipe := t;
% find-gnuplot returns the full name of a version of gnuplot (if it can
% find one).
  plotcommand!* := find!-gnuplot();
% The Cygwin case can be "funny" here, and the case I wish to trap is
% where a Cygwin version of Reduce is trying to use the native Windows
% version of gnuplot. I believe I can detect this by seeing of
% the plotcommand!* starts off as "/cygdrive/"...
  w := explode2 plotcommand!*;
  if eqcar(w, '!") and
     eqcar(w:= cdr w, '!/) and
     eqcar(w:= cdr w, 'c) and
     eqcar(w:= cdr w, 'y) and
     eqcar(w:= cdr w, 'g) and
     eqcar(w:= cdr w, 'd) and
     eqcar(w:= cdr w, 'r) and
     eqcar(w:= cdr w, 'i) and
     eqcar(w:= cdr w, 'v) and
     eqcar(w:= cdr w, 'e) and
     eqcar(w:= cdr w, '!/) then w := t
  else w := nil;
  if memq('win32, lispsystem!*) or memq('win64, lispsystem!*) or w then <<
    plotheader!* := "";
    dirchar!* := "\";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcleanup!* := if null tempdir!* then {"erase gnutmp.tm*"}
                     else {bldmsg("erase ""%w\gnutmp.tm*""", tempdir!*)} >>
  else if memq('cygwin, lispsystem!*) then <<
    plotheader!* := "";
    dirchar!* := "/";
    plotdta!* := for each n in
       {"gnutmp.tm1", "gnutmp.tm2", "gnutmp.tm3", "gnutmp.tm4",
        "gnutmp.tm5", "gnutmp.tm6", "gnutmp.tm7", "gnutmp.tm8"}
       collect gtmpnam n;
    plotcleanup!* := if null tempdir!* then {"rm gnutmp.tm*"}
                     else {bldmsg("rm ""%w\gnutmp.tm*""", tempdir!*)} >>
  else <<  % Assume Unix or Linux or BSD with X11, or a Macintosh.
    dirchar!* := "/";
    if null !*force_gnuplot_term then plotheader!* := ""
    else plotheader!* := gnuplot_select_terminal!*;
    plotdta!* := for i:=1:10 collect tmpnam();
    plotcmds!*:= tmpnam();
    plotcleanup!* := bldmsg("rm ""%w""", plotcmds!*) .
      for each f in plotdta!* collect bldmsg("rm ""%w""", f) >>;
  return nil
end;
  
#endif

endmodule;

end;
