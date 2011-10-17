%
% "makefile" style code for CSL for the recompilation of parts of REDUCE
%
%         A C Norman.   July 1995



module 'make;


fluid '(r36_modules source_directory);

if null source_directory then source_directory := "..";

r36_modules := '(
   (module   "src/module.red")
   (patches  "src/patches.red")
   (arith    "src/arith.red")
   (alg      "src/alg.red")
   );


symbolic procedure bring_up_to_date();
  begin
    scalar done, m, s;
    for each w in r36_modules do <<
      m := car w;
      s := cadr w;
      file := bldmsg("""%w/%w""", source_directory, m);
      file_date := datestamp file;
      module_date := modulep m;
      prin m; ttab 15; prin file; ttab 40; prin module_date;
      ttab 60; print file_date >>;
%   eval '(begin)
    nil
  end;


endmodule;

end;


