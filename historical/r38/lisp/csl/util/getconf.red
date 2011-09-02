% getconf.red

% Tony Hearn keeps his master configuration data in two DOS batch files. 
% This script extracts the information and puts it here where I want it!


% To run this script you need a working REDUCE. If you were having to
% build for the VERY first time and did not have an existing config.lsp
% file you would need to transcribe the information from the batch files
% mentioned here by hand. But once you have a REDUCE built you can select
% the reduce build directory as current and go
%     r38 $srcdir/../util/getconf.red -D!@srcdir=$srcdir
% to refresh $srcdir/../util/config.lsp from that top-level data.

symbolic;

fluid '(!@srcdir);

symbolic procedure make_conf_file();
  begin
    scalar a, p1, p2, p3, w;
    princ "source directory = "; printc !@srcdir;
    a := open("$srcdir/../../../upackage.bat", 'input);
    p1 := nil;
    while atom p1 and p1 neq !$eof!$ do <<
       a := rds a; p1 := read(); a := rds a >>;

    p2 := w := nil;
    while w neq !$eof!$ do <<
       w := nil;
       while atom w and w neq !$eof!$ do <<
          a := rds a; w := read(); a := rds a >>;
       if not atom w then p2 := append(p2, w) >>;
    close a;
    a := open("$srcdir/../../../xpackage.bat", 'input);
    p3 := w := nil;
    while w neq !$eof!$ do <<
       w := nil;
       while atom w and w neq !$eof!$ do <<
          a := rds a; w := read(); a := rds a >>;
       if not atom w then p3 := append(p3, w) >>;
    close a;
    if filep "$srcdir/../../../getred.pl" then
       a := "$srcdir/../util/devconfig.lsp"
    else a := "$srcdir/../util/config.lsp";
    a := open(a, 'output);
    << a := wrs a; linelength 72;
       terpri();
       printc "% These are packages that get built into the base system that";
       printc "% is used to compile what follows...";
       terpri();
       prettyprint p1; terpri();
       terpri();
       printc "% The next set of modules are all built using a system that";
       printc "% has the above set available. The key issue here is that the";
       printc "% packages in this list of ""extensions"" can all be built";
       printc "% independently of each other.";
       terpri();
% The v3tools module depends on the groebner code already being built, and so
% it must appear late in the list. As I introduce this script the xpackage.bat
% file may not reflect that so FUDGE it here.
       if memq('v3tools, p2) then
          p2 := append(delete('v3tools, p2), '(v3tools));
       prettyprint p2; terpri();
       terpri();
       printc "% Finally we have a list of all the test scripts that REDUCE";
       printc "% is shipped with.";
% As a special HACK I will removbe gnuplot (if present) since at least as
% of the time of working on this its level of interactivity causes the
% profiling job to fail.
       r3 := delete('gnuplot, p3);
       terpri();
       prettyprint p3; terpri();
       terpri();
       printc "% End of configuration file";
       close wrs a >>
  end;

make_conf_file();

end;


