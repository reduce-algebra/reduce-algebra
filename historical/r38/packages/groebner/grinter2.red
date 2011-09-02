module grinter2;% Interface of Groebner package to REDUCE:
% autoloadint entry points to operators of groebnr2.
 
symbolic procedure groebnr2entry(fn,u);
<<groebnr2load();apply(get(fn,'psopfn),{u})>>;

symbolic procedure groebnr2load();load!-package'groebnr2;

put('gsort,'psopfn,'(lambda(u)(groebnr2entry 'gsort u)));
put('gsplit,'psopfn,'(lambda(u)(groebnr2entry 'gsplit u)));
put('gspoly,'psopfn,'(lambda(u)(groebnr2entry 'gspoly u)));
put('gvars,'psopfn,'(lambda(u)(groebnr2entry 'gvars u)));
put('greduce,'psopfn,'(lambda(u)(groebnr2entry 'greduce u)));
put('greduce_orders,'psopfn,
 '(lambda(u)(groebnr2entry 'greduce_orders u)));
put('preduce,'psopfn,'(lambda(u)(groebnr2entry 'preduce u)));
put('groebnert,'psopfn,'(lambda(u)(groebnr2entry 'groebnert u)));
put('preducet,'psopfn,'(lambda(u)(groebnr2entry 'preducet u)));
put('groebnerm,'psopfn,'(lambda(u)(groebnr2entry 'groebnerm u)));
put('glexconvert,'psopfn,'(lambda(u)(groebnr2entry 'glexconvert u)));
put('hilbertpolynomial,'psopfn,
 '(lambda(u)(groebnr2entry 'hilbertpolynomial u)));
put('gzerodim!?,'psopfn,
    '(lambda(u)(groebnr2entry 'gzerodim!? u)));
put('dd_groebner,'psopfn,'(lambda(u)(groebnr2entry 'dd_groebner u)));

put('trgroeb,'simpfg,'((t(groebnr2load))));
put('trgroebs,'simpfg,'((t(groebnr2load)(setq !*trgroeb t))
                      (nil(setq !*trgroeb nil))));
put('trgroebr,'simpfg,'((t(groebnr2load))));
put('groebstat,'simpfg,'((t(groebnr2load))));
put('groebweak,'simpfg,'((t(groebnr2load))));
% put('groebres,'simpfg,'((t(groebnr2load))));

symbolic procedure groebtestrestriction(a1,a2);
<<groebnr2load();apply('groebtestrestriction,{a1,a2})>>;
put('groebner_walk,'psopfn,
 '(lambda(u)(groebnr2entry'groebner_walk u)));

endmodule;;end;
