module helpasst;

algebraic procedure assist();
<<write " Argument of ASSISTHELP must be an integer between 3 and 14. ";
  write " Each integer corresponds to a section number in the documentation:";
  write  " 3: switches ", "   4: lists      ","  5: bags    ",
         "  6: sets ";
  write " 7: utilities ", "  8: properties and flags ",
                                  " 9: control functions ";
  write " 10: handling of polynomials ";
  write " 11: handling of transcendental functions";
  write " 12: handling of n-dimensional vectors ";
  write " 13: grassmann variables ","          14: matrices";>>;

algebraic procedure assisthelp(n);
 if n = assist then assist()
   else
 if not fixp n then rederr("Argument must be an integer")
   else
 if n>=15 then "Argument must be less then 15"
   else 
 if n<3 then "Argument must be greater or equal to 3"
  else
   begin scalar xx;
    xx:= asflist(n,assist_func);
    return if length xx=1 then rest first xx
             else
                 for each i in xx collect rest i
   end$

algebraic(
assist_func:= {{3,  "switches", "switchorg"},
               {4,  "dot", "mklist", "algnlist", "frequency", "sequences",
                   "split", "kernlist"},
               {4, "delete", "delete_all", "remove"},
               {4, "elmult", "insert", "insert_keep_order", "merge_list"},
               {4, "last", "belast", "position", "depth", "mkdepth_one",
                   "pair", "delpair", "appendn"},
               {4, "repfirst", "represt", "asfirst", "aslast",
                   "asrest","restaslist", "asflist", "asslist"},
               {5, "putbag", "clearbag", "bagp", "baglistp", "alistp",
                   "abaglistp", "listbag"},
               {6, "union", "setp", "mkset", "diffset", "symdiff"},
               {7, "mkidnew", "list_to_ids", "oddp", "followline",
                   "detidnum", "dellastdigit", "=="},
               {7, "randomlist", "mkrandtabl"},
               {7, "permutations", "perm_to_num", "num_to_perm",
                   "combnum", "combinations", "cyclicpermlist", 
                   "symmetrize", "remsym"},
               {7, "extremum", "sortnumlist", "sortlist","algsort"},
               {7, "funcvar", "implicit", "depatom", "explicit",
                   "simplify", "korderlist", "remcom"},
               {7, "checkproplist", "extractlist", "array_to_list", 
                  "list_to_array"},
	       {7, "remvector", "remindex", "mkgam"},	
               {8, "putflag", "putprop", "displayprop", "displayflag",
                   "clearflag", "clearprop"},
               {9, "nordp", "depvarp", "alatomp", "alkernp", "precp"},
               {9, "show", "suppress", "clearop", "clearfunctions"},
               {10, "alg_to_symb", "symb_to_alg"},
               {10, "gcdnl", "distribute", "leadterm", "redexpr",
                    "monom", "lowestdeg", "splitterms", "splitplusminus",
                    "norm_mon", "norm_pol", "list_coeff_pol"},
               {11, "trigexpand", "hypexpand","trigreduce","hypreduce"},
               {12, "sumvect", "minvect", "sscalvect", "crossvect",
                    "mpvect"},
               {13, "putgrass", "remgrass", "grassp", "grassparity",
                    "ghostfactor"},
               {14, "mkidm", "baglmat", "coercemat", "unitmat","submat",
                    "matsubr", "matsubc", "matextr", "matextc"},
               {14, "hconcmat", "vconcmat", "tpmat", "hermat", "seteltmat",
                    "geteltmat"}});
endmodule;
end;

