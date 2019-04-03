module gnuintfc; % REDUCE-gnuplot interface.

% Authors:  Anthony C. Hearn, Herbert Melenk, Arthur C. Norman.
% Modified by FJW for REDUCE on Common Lisp.
% The standard version is "packages/plot/gnuintfc.red".
% Includes some code from "packages/support/psl.red".

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Redistribution and use in source and binary forms, with or without		   %
% modification, are permitted provided that the following conditions are met:  %
%																			   %
%    * Redistributions of source code must retain the relevant copyright	   %
%      notice, this list of conditions and the following disclaimer.		   %
%    * Redistributions in binary form must reproduce the above copyright	   %
%      notice, this list of conditions and the following disclaimer in the	   %
%      documentation and/or other materials provided with the distribution.	   %
%																			   %
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  %
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE	   %
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   %
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR CONTRIBUTORS BE	   %
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR		   %
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF		   %
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS	   %
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN	   %
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)	   %
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   %
% POSSIBILITY OF SUCH DAMAGE.												   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fluid '(dirchar!*);

global '(tempdir!*);

!#if (memq 'win32 lispsystem!*)
   dirchar!* := "\";
   tempdir!* := getenv "TMP" or getenv "TEMP";
!#else
   dirchar!* := "/";
   tempdir!* := "/tmp";
!#endif

% This file complements the (notionally) generic file "gnuplot.red" to
% provide system-specific interfaces between REDUCE and the gnuplot
% application.

fluid '(plotstyle!*);

global '(
   !*plotinterrupts	% list of error codes caused by interrupts (ctl-C)
   !*plotpause		% NIL if gnuplot should not wait
   !*plotusepipe	% T if using pipes, NIL if writing to command file
   plotheader!*	    % list of gnuplot commands (strings) for initializing gnuplot
   plotcleanup!*    % list of OS command for cleaning up (like removing temp files)
   plottmp!*        % dir for temp files (inc. trailing directory separator)
   );

!*plotusepipe := t;					 % declared switch in gnupldrv.red

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

#elif (memq 'win32 lispsystem!*)		% *** MS WINDOWS ***

   if null tempdir!* then
   << prin2t "warning: no TMP directory found. Using >C:<";
      plottmp!* := "C:\" >>
   else plottmp!* := concat(tempdir!*, "\");
   !*plotpause := "mouse close";
   plotdta!* := for i:=1:10 collect
	  bldmsg("%wplotdt%w.dat", plottmp!*, i); % scratch data files
   plotheader!* := "";
   plotcleanup!* :=						% delete data files
	  {concat("del ", plottmp!*, "plotdt*.dat")};
   if !*plotusepipe then				% default as set above
   	  plotcommand!* := "start /b gnuplot.exe"
   else <<
   	  plotcmds!* := concat(plottmp!*, "plotcmds");
   	  plotcommand!* := concat("start /wait wgnuplot.exe ", plotcmds!*);
   	  plotcleanup!* :=					% also delete command file
	  	 {concat(plotcleanup!*, " ", plotcmds!*)};
   >>;

#endif

   !*plotinterrupts := '(10002);
   % end of definition of initialize_gnuplot();
   >>;

% Find path to gnuplot executable on Unix
% =======================================

symbolic procedure find!-gnuplot;
   find!-gnuplot!-aux getenv("GNUPLOT") or "gnuplot";

symbolic procedure find!-gnuplot!-aux path;
  % On Unix, build full pathname for gnuplot executable.
  if null path then nil else <<
     if idp path then path := id2string path;

     % Remove trailing directory separator if present:
	 begin scalar p;
	 	if cadr (p := reversip explode path) eq dirchar!* then
		   path := '!" . compress reversip cddr p;
	 end;

     % Build path:
     path := bldmsg("%w%w%w", path, dirchar!*, "gnuplot");

     % Check existence and return:
     if filep path then path
  >>;

endmodule;

end;
