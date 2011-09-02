module TayConv;

%*****************************************************************
%
%     Functions converting Taylor kernels to prefix forms
%
%*****************************************************************


exports prepTaylor!*!*, prepTaylor!*, prepTaylor!*1,
        Taylor!-gen!-big!-O;

imports

% from the REDUCE kernel:
        eqcar, lastpair, prepsq!*, replus, retimes, reval,

% from the header module:
        prepTayExp, TayCfPl, TayCfSq, TayCoeffList, TayTemplate,
        TayTpElNext, TayTpElPoint, TayTpElVars;


fluid '(convert!-Taylor!*
        TaylorPrintTerms
        Taylor!-truncation!-flag);


symbolic procedure prepTaylor!*1 (coefflist, template, no!-of!-terms);
  replus for each cc in coefflist join
    begin scalar x; integer count;
      if Taylor!-truncation!-flag then return nil;
      x := prepTaylor!*2 (cc, template);
      if null x or null no!-of!-terms then return x;
      no!-of!-terms := no!-of!-terms - 1;
      if no!-of!-terms < 0
        then << Taylor!-truncation!-flag := t;
                return nil >>;
      return x
    end;

symbolic procedure prepTaylor!*2 (coeff, template);
  (lambda (pc);
    if pc = 0 then nil
     else {retimes (
            (if eqcar (pc, 'quotient) and eqcar (cadr pc, 'minus)
               then {'minus, {'quotient, cadr cadr pc, caddr pc}}
              else pc) . preptaycoeff (TayCfPl coeff, template))})
    (prepsq!* TayCfSq coeff);


symbolic procedure checkdifference (var, var0);
  if var0 = 0 then var else {'difference, var, var0};

symbolic procedure checkexp(bas,exp);
  if exp = 0 then 1
   else if exp = 1 then bas
   else {'expt,bas,prepTayExp exp};

symbolic smacro procedure checkpower (var, var0, n);
  if var0 eq 'infinity
    then if n = 0 then 1
          else {'quotient, 1, checkexp (var, n)}
   else checkexp (checkdifference (var, reval var0), n);

symbolic procedure preptaycoeff (cc, template);
  begin scalar result;
    while not null template do begin scalar ccl;
      ccl := car cc;
      for each var in TayTpElVars car template do <<
        result := checkpower (var, TayTpElPoint car template, car ccl)
                    . result;
        ccl := cdr ccl >>;
      cc := cdr cc;
      template := cdr template
    end;
    return result
  end;

put ('taylor!*, 'prepfn2, 'preptaylor!*!*);

symbolic procedure prepTaylor!*!* u;
   if null convert!-taylor!* then u else preptaylor!* u;

symbolic procedure prepTaylor!* u;
   prepTaylor!*1 (TayCoeffList u, TayTemplate u, nil);

symbolic procedure Taylor!-gen!-big!-O tp;
  %
  % Generates a big-O notation for the Taylor template tp
  %
  "O" . for each el in tp collect
          if null cdr TayTpElVars el
            then checkpower(car TayTpElVars el,TayTpElPoint el,
                            TayTpElNext el)
           else begin scalar var0;
             var0 := reval TayTpElPoint el;
             return
               if var0 eq 'infinity
                 then {'quotient,1,
                       checkexp('list . TayTpElVars el,TayTpElNext el)}
                else checkexp(
                 'list .
                   for each krnl in TayTpElVars el collect
                     checkdifference(krnl,var0),
                 TayTpElNext el)
           end;

endmodule;

end;
