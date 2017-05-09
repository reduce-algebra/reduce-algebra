module rlblackbox;

revision('rlblackbox, "$Id$");

copyright('rlblackbox, "(c) 2017 T. Sturm");

fluid '(rl_blackboxes!*);

fluid '(rl_bbl!*);

put('rl_blackbox, 'stat, 'rl_blackboxStat);

asserted procedure rl_blackboxStat(): List;
   % Read the opening curly brace and clean up at the end. The main loop parsing
   % the list is in the next function.
   begin scalar spec;
      scan();
      if cursym!* neq '!*lcbkt!* then
	 rederr {"expecting '{' in rl_blackbox but found", cursym!*};
      spec := rl_blackboxStatList();
      scan();  % !*semicol!*
      return {'rl_blackbox, spec}
   end;

asserted procedure rl_blackboxStatList(): Alist;
   % We hav just read '{'. Parse a list with entries of the form [name = entry].
   % [name] is an alphabetic identifier. [entry]. The result is an Alist
   % corresponding to the input list of equations, and a subsequent formfn is
   % going to take care of the rest.
   begin scalar spec, key, entry;
      scan();
      while cursym!* neq '!*rcbkt!* do <<
	 % We are not on the right hand side of an equation. We need an
	 % alphabetic identifier. We strictly admit only alphabetic characters,
	 % no digits.
      	 if not lto_alphap cursym!* then
	    rederr {"expecting alphabetic key in rl_service but found", cursym!*};
      	 key := cursym!*;
	 % Skip the equal sign.
      	 rl_skipequal("rl_blackbox");
      	 scan();
	 % We are on the right hand side now. Only atoms are admissible here.
	 if not atom cursym!* then
	    rederr {"expecting atomic entry in rl_blackbox but found", cursym!*};
	 entry := cursym!*;
	 push(key . entry, spec);
	 scan();
	 % Expecting ',' or '}' now:
	 if cursym!* neq '!*rcbkt!* then <<
	    if cursym!* neq '!*comma!* then
	       rederr {"expecting ',' or '}' in rl_blackbox but found", cursym!*};
	    scan()
	 >>
      >>;
      return reversip spec
   end;

put('rl_blackbox, 'formfn, 'rl_formBlackbox);

asserted procedure rl_formBlackbox(argl: Alist, vars: List, m: Id): List;
   begin scalar spec, rl_b!*, rl_b, p, name, vn, args, doc, docal; integer n;
      % We are going construct a progn in [p], which is going to be the
      % result of this formfn.
      spec := cadr argl;
      name := lto_eatsoc('name, spec, {"missing name in black box"});
      n := lto_eatsoc('argnum, spec, {"missing argnum in black box", name});
      doc := lto_eatsoc('doc, spec, {"missing doc in black box", name});
      rl_b := intern compress nconc(explode 'rl_, explode name);
      args := for i := 1:n collect mkid('a, i);
      rl_b!* := intern compress nconc(explode rl_b, explode '!*);
      docal := {'synopsis . rl_docSynopsisBb(rl_b, n), 'description . doc};
      push({'put, mkquote rl_b, ''docal, mkquote docal}, p);
      push({'flag, mkquote {rl_b}, ''rl_blackbox}, p);
      push({'fluid, mkquote {rl_b!*}}, p);
      % The rl_bbl!* ist somewhat redundant now and should be removed at some
      % point. I prefer to use the function names now, and to reconstruct the
      % fluid names at runtime during rl_set(), which is not time-critical.
      push({'setq, 'rl_bbl!*, {'cons, mkquote rl_b!*, 'rl_bbl!*}}, p);
      push({'put, mkquote rl_b, ''number!-of!-args, n}, p);
      push({'de, rl_b, args, {'apply, rl_b!*, 'list . args}}, p);
      push({'setq, 'rl_blackboxes!*, {'cons, mkquote rl_b, 'rl_blackboxes!*}}, p);
      return 'progn . reversip p
   end;

asserted procedure rl_docSynopsisBb(f: Id, n: Integer);
   lto_sconcat {lto_at2str f, "/", lto_at2str n};

asserted procedure rl_blackboxP(x: Any): ExtraBoolean;
   idp x and flagp(x, 'rl_blackbox);

endmodule;

end;
