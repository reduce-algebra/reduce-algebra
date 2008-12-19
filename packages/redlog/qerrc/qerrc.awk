# ----------------------------------------------------------------------
# $Id: qerrc.awk,v 1.1 1996/10/18 07:14:55 dolzmann Exp $
# ----------------------------------------------------------------------
# Written by Andreas Dolzmann, (c) Universitaet Passau, 1996
# ----------------------------------------------------------------------
# $Log: qerrc.awk,v $
# Revision 1.1  1996/10/18 07:14:55  dolzmann
# Initial check-in.
#
# ----------------------------------------------------------------------
BEGIN {
  hugo="";
  verb=tolower(verb);
}

/^=====/ {f=0}

(f==1) {
  hugo=sprintf("%s%s",hugo,$0);
}

/^An equivalent quantifier-free formula:/ {f=1}

/^Statistic for complete quantifier elimination:/ && (time=="t") {
  /* print; */
  getline tmi;
  print tmi;
}

END {
  gsub(/\\\//," or ",hugo);
  gsub(/\/\\/," and ",hugo);
  gsub(/--/," not ",hugo);
  gsub(/\[/,"",hugo);
  gsub(/\]/,"",hugo);
  gsub(/EX/,"ex(",hugo);
  gsub(/:\(/,",",hugo);
  gsub(/ALL/,"all(",hugo);
  gsub(/:\(/,",",hugo);
  new = "";
  while (match(hugo,/[a-zA-Z0-9] [a-zA-Z0-9]/)) {
    new = sprintf("%s%s%s",new,substr(hugo,1,RSTART),"*");
    hugo=substr(hugo,RSTART+2);
  }
  hugo=sprintf("%s%s",new,hugo);
  printf("%s;\n",hugo) > rf 
  printf("end;\n") > rf
}
