open(FL,"r38.tmp") or die "r38.tmp not there\n";

open(FLO,">r38.tex");

while (<FL>) {
   s/ *$//g;           # Remove trailing blanks.
   s/\t/        /g;    # Convert tabs.

   s/\\begin{verbatim}/{\\small\\begin{verbatim}/;
   s/\\end{verbatim}/\\end{verbatim}}/;

   print FLO $_;

             }

close FL; close FLO;

exit(0);

