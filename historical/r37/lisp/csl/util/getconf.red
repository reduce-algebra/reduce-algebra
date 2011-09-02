% getconf.red

% Hearn keeps his master configuration data (at least in a pre-release
% version of 3.7) in two DOS batch files. This script extracts the
% information and puts it here where I want it!


% To run this script you need a working REDUCE. If you were having to
% build for the VERY first time and did not have an existing config.lsp
% file you would need to transcribe the information from the batch files
% mentioned here by hand. But once you have a REDUCE built you can select
% the reduce build directory as current and go
%     r37 ../util/getconf.red
% to refresh ../util/config.lsp from that top-level data.

symbolic;

a := open("../../../upackage.bat", 'input);
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
a := open("../../../xpackage.bat", 'input);

p3 := w := nil;
while w neq !$eof!$ do <<
   w := nil;
   while atom w and w neq !$eof!$ do <<
      a := rds a; w := read(); a := rds a >>;
   if not atom w then p3 := append(p3, w) >>;

close a;

a := open("../util/config.lsp", 'output);
<< a := wrs a; linelength 72;
   print p1; terpri();
   print p2; terpri();
   print p3; terpri();
   close wrs a >>;

end;

