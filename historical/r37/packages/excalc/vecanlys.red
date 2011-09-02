module vecanlys;

%author: Eberhard Schruefer;

symbolic procedure basis u;
   cofram(for each j in u collect cdr j,nil);

rlistat '(basis);

symbolic procedure simpgrad u;
   simp!*('d . u);

put('grad,'simpfn,'simpgrad);

symbolic procedure simpcurl u;
   simp!* list('hodge,'d . u);

put('curl,'simpfn,'simpcurl);

symbolic procedure simpdiv u;
   simp!* list('hodge,list('d,'hodge . u));

put('div,'simpfn,'simpdiv);

newtok '((!. !* !.) crossprod);
infix crossprod;

symbolic procedure simpcrossprod u;
   simp!* list('hodge,'wedge . u);

put('crossprod,'simpfn,'simpcrossprod);

symbolic procedure simpdotprod u;
   simp!* list('hodge,list('wedge,car u,list('hodge,cadr u)));

put('cons,'simpfn,'simpdotprod);

symbolic procedure hodge3dpri u;
   %converts the form notation to vector notation for output;
   if caar u eq 'd then
        if eqcar(cadar u,'hodge) then maprin('div . cdadar u)
         else maprin('curl . cdar u)
    else if caar u eq 'wedge then
              if eqcar(cadar u,'hodge) then
                     inprint('cons,0,cdadar u)
               else inprint('crossprod,0,cdar u);

endmodule;

end;
