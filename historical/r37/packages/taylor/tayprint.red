module TayPrint;

%*****************************************************************
%
%     Functions for printing Taylor kernels
%
%*****************************************************************


exports Taylor!*print, Taylor!*print1;

imports

% from the REDUCE kernel:
        denr, eqcar, fmprint, kernp, lastpair, maprint, mvar, numr,
        prepsq, simp!*, smemq, typerr,

% from the header module:
        TayCfSq, TayCoeffList, TayOrig, TayTemplate, TayTpElOrder,
        TayTpElPoint, TayTpElVars,

% from module Tayconv:
        prepTaylor!*, prepTaylor!*1, Taylor!-gen!-big!-O;


fluid '(!*fort !*nat !*taylorprintorder Taylor!-truncation!-flag
        TaylorPrintTerms);

symbolic procedure check!-print!-terms u;
  begin scalar x;
    x := simp!* u;
    if kernp x and mvar numr x eq 'all then return nil
     else if denr x = 1 and fixp numr x then return numr x
     else typerr (x, "value of TaylorPrintTerms")
  end;


symbolic procedure Taylor!*print1 u;
  if smemq('!~,u) or atom TayCoeffList u and not null TayCoeffList u
    then 'Taylor . cdr u
   else begin scalar Taylor!-truncation!-flag, prepexpr, rest, nterms;
    nterms := if !*taylorprintorder
                then check!-print!-terms TaylorPrintTerms
               else nil;
    prepexpr := prepTaylor!*1 (
                  TayCoeffList u,
                  TayTemplate u,
                  nterms);
    if !*taylorprintorder then <<
      rest := {Taylor!-gen!-big!-O TayTemplate u};
      if Taylor!-truncation!-flag then begin integer notprinted;
           notprinted := -nterms;
           for each pp in TayCoeffList u do
             if not null numr TayCfSq pp then
               notprinted := notprinted + 1;
           if notprinted=1 then rest := "(1 term)" . rest
            else rest := compress append('(!" !(),
                           nconc(explode notprinted,
                                 '(!  !t !e !r !m !s !) !"))) . rest
        end
        %%%if prepexpr=0 and null cdr rest then return car rest
        >>
     else rest := {'!.!.!.};
    return if not eqcar (prepexpr, 'plus)
             then 'plus . (prepexpr or 0) . rest
            else nconc (prepexpr, rest)
  end;

comment The following statement is the interface for the XReduce
        fancy printer;

put('Taylor!*,'fancy!-reform,'Taylor!*print1);


symbolic procedure Taylor!*print(u,p);
  if !*fort then fmprint(prepTaylor!* u,0)
   else if null !*nat then maprint(
                     'taylor . 
                        (if TayOrig u
                           then prepsq Tayorig u
                          else prepTaylor!* u) .
                        for each el in TayTemplate u join
                          {if null cdr TayTpElVars el
                             then car TayTpElVars el
                            else 'list . TayTpElVars el,
                           TayTpElPoint el,
                           TayTpElOrder el},
                     p)
   else maprint(Taylor!*print1 u,p);

put('Taylor!*,'pprifn,'Taylor!*print);


comment We need another printing function for use with the 
        TeX-REDUCE interface; %not yet done;


endmodule;

end;
