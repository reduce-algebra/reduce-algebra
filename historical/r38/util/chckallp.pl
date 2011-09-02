$bool = 0;

$MACHINE = $ENV{'MACHINE'};

$package = $ARGV[0];

$reduce = $ENV{'reduce'};

open(FLO,">>$reduce/log/checkall.log");

print FLO "\nChecking $package ...\n\n";

open(FL,"$reduce/package.red") || die "$reduce/package.red not there";

while ($x=<FL>) {
   if ($x =~ /folder/) {
       @y = split(/,'/,substr($x,5,-3));
       if ($y[0] eq $package) {
         if ($MACHINE eq win32) {
           print FLO
	    `$dif $reduce\\log\\$package.rlg $reduce\\packages\\$y[2]\\$package.rlg`;}
	  else {
	   print FLO `diff $reduce/log/$package.rlg $reduce/packages/$y[2]/$package.rlg`;}
       	 $bool = 1; last;}}}

if ($bool == 0) {
  if ($MACHINE eq win32) {
           print FLO
	 `$dif $reduce\\log\\$package.rlg $reduce\\packages\\$package\\$package.rlg`;}
	else {
	 print FLO `diff $reduce/log/$package.rlg $reduce/packages/$package/$package.rlg`;}
		}

close FLO;

exit(0);
