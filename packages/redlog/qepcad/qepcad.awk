# ----------------------------------------------------------------------
# $Id: qepcad.awk,v 1.2 2002/09/18 15:14:14 dolzmann Exp $
# ----------------------------------------------------------------------
# Written by Thomas Sturm, (c) Universitaet Passau, 1995
# ----------------------------------------------------------------------
# $Log: qepcad.awk,v $
# Revision 1.2  2002/09/18 15:14:14  dolzmann
# Added hack for qepcad B. (Phrase "In other words" is missing.)
#
# Revision 1.1  1996/03/22 12:15:20  sturm
# Moved.
#
# Revision 1.2  1995/12/06  11:04:53  sturm
# Made results available to Reduce.
# Added proper treatment of the switches rlverbose and time.
#
# Revision 1.1  1995/12/06  10:51:57  sturm
# Initial check-in.
#
# ----------------------------------------------------------------------
BEGIN {time=tolower(time); verb=tolower(verb)}
/^In other words/ {f=0}
/^==============================/ {f=0}
(f==1) {
  if (verb=="t") print
  for (i=1; i<=NF; i++) {
    oi = $i;
    gsub(/\\\//," or ",$i);
    gsub(/\/\\/," and ",$i);
    gsub(/\[/,"(",$i);
    gsub(/\]/,")",$i);
    gsub(/\/=/,"<>",$i);
    printf("%s",$i) > rf
    if (match(oi,/[a-z0-9]+/) && i<NF && match($(i+1),/[a-z0-9]+/))
      printf("*") > rf
  }
  printf("\n") > rf
}
/^System time:/ && (time=="t") {print}
/^\*\*/ {print ""; print}
/^Failure occurred in:/ {print ""; print}
/^Reason for the failure:/ {print}
/^An equivalent quantifier-free formula:/ {f=1}
END {printf("; end;\n") > rf}
