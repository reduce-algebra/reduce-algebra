module showrules; % Display rules known for an operator.

% Author: Herbert Melenk, ZIB, Berlin. E-mail: melenk@sc.zib-berlin.de.

% Copyright (c) 1988 ZIB Berlin. All rights reserved.

% Revisions:
%
%    10 Mar 89.  Missing declaration for "rule" added to showrulesdfn2.
%
%     1 Mar 89.  Includes differentiation rules in output. Removes
%                calls to first, second and third.

global '(!*match );

fluid '(asymplis!*);

% All let-rules for an operator are printed.

% Usage in algebraic mode:
%  e.g. SHOWRULES SIN;
% The rules for exponentiation can be listed by
%       SHOWRULES 'EXPT;

symbolic procedure showrules (opr);
   begin scalar rules,vars,test,svars,target,pattern,!*lower;
        !*lower := t;
        for i:=1:72 do prin2 "="; terpri();
        for i:=1:72 do prin2 "="; terpri();
        prin2 "rules for >>>"; prin2 opr; prin2t "<<<";
        showruleskvalue opr;
        showrulesopmtch opr;
        showrules!*match opr;
        showrulesdfn opr;
        if opr = 'expt then
        <<showrulespowlis!*();
          showrulespowlis1!*();
          showrulesasymplis!*()>>;
        for i:=1:72 do prin2 "="; terpri();
       end;

symbolic procedure showruleskvalue opr;
   begin scalar rules,pattern,vars,svars,target;
        rules := get(opr,'KVALUE);
        for each rule in rules do
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := car rule;
                 vars := selectletvars pattern;
                 svars := for each var in vars
                        collect var . compress cddr explode var;
                 pattern := subla(svars,pattern);
                 target := cadr rule;
                 target := subla (svars,target);
                 prin2!* "let ";
                 mathprint (list('equal, pattern,target));
              >>;
   end;

symbolic procedure showrulesopmtch opr;
   begin scalar rules,pattern,vars,svars,target,test;
        rules := get(opr,'opmtch);
        for each rule in rules do
               showrulesopmtch1 (opr,rule);
   end;

symbolic procedure showrulesopmtch1 (opr,rule);
    % print one single rule
   begin scalar rules,pattern,vars,svars,target,test;
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := car rule;
                 vars := selectletvars pattern;
                 test := cdadr rule;
                 target := caddr rule;
                 svars := for each var in vars
                        collect var . compress cddr explode var;
                 pattern := subla(svars,pattern);
                 test := subla(svars,test);
                 target := subla (svars,target);
                 vars := for each var in svars collect cdr var;
                 svars := vars;
                 test := simpletsymbolic test;
                 target := simpletsymbolic target;
                 prin2 "for all ";
                 while svars do
                   <<prin2 car svars;
                     svars := cdr svars;
                     if svars then prin2 " , ">>;
                 if test and not test = t then
                   <<prin2t " such that ";
                     printest test;
                     terpri ();
                     prin2t "let">>
                  else
                     prin2t " let";
                 mathprint (list('equal,opr . pattern,target));
     end;

symbolic procedure showrulesdfn opr;
      <<showrulesdfn1 opr; showrulesdfn2 opr>>;

symbolic procedure showrulesdfn1 opr;
   % simple derivatives
   begin scalar rules,pattern,vars,svars,target,test;
        rules := get(opr,'dfn);
        for each rule in rules do
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := car rule;
                 vars := selectletvars pattern;
                 target := cdr rule;
                 svars := for each var in vars
                        collect var . compress cddr explode var;
                 pattern := subla(svars,
                                  append(list('df,opr . pattern) ,
                                         pattern));
                 target := subla (svars,target);
                 vars := for each var in svars collect cdr var;
                 svars := vars;
                 target := simpletsymbolic target;
                 prin2 "for all ";
                 while svars do
                   <<prin2 car svars;
                     svars := cdr svars;
                     if svars then prin2 " , ">>;
                 prin2t " let";
                 mathprint (list('equal,pattern,target));
              >>;
     end;

symbolic procedure showrulesdfn2 opr;
   % collect possible rules from df
   begin scalar rule,rules;
       rules := get('df,'opmtch);
       while rules do
       <<rule := car rules; rules := cdr rules;
         if eqcar(caar rule,opr) then showrulesopmtch1 ('df,rule);
       >>;
    end;

symbolic procedure showrules!*match opr;
   begin scalar rules,pattern,vars,svars,target,test,p1,p2;
       for each rule in !*match do
           if smemb (opr,rule) then
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := car rule;
                 p1 := car pattern;
                 p2 := cadr pattern;
                 pattern :=
                   list ('times,prepsq !*p2q p1,
                                prepsq !*p2q p2);
                 vars := selectletvars pattern;
                 test := cdadr rule;
                 target := caddr rule;
                 svars := for each var in vars
                        collect var . compress cddr explode var;
                 pattern := subla(svars,pattern);
                 test := subla(svars,test);
                 target := subla (svars,target);
                 vars := for each var in svars collect cdr var;
                 svars := vars;
                 test := simpletsymbolic test;
                 target := simpletsymbolic target;
                 if svars then
                 <<prin2 "for all ";
                   while svars do
                   <<prin2 car svars;
                     svars := cdr svars;
                     if svars then prin2 " , ">>;
                 >>;
                 if test and not test = t then
                   <<prin2t " such that ";
                     printest test;
                     terpri ();
                     prin2t "let">>
                  else
                     prin2t " let";
                 mathprint (list('equal,pattern,target));
              >>;
     end;



symbolic procedure showrulespowlis!*();
   begin scalar rules,pattern,vars,svars,target,test;
       for each rule in powlis!* do
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := list ('expt,car rule,cadr rule);
                 target := cadddr rule;
                 prin2t " let";
                 mathprint (list('equal,pattern,target));
              >>;
     end;

symbolic procedure showrulespowlis1!*();
   begin scalar rules,pattern,vars,svars,target,test,p1,p2;
       for each rule in powlis1!* do
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 pattern := car rule;
                 p1 := car pattern;
                 p2 := cdr pattern;
                 pattern := list ('expt, p1, p2);
                 vars := selectletvars pattern;
                 test := cdadr rule;
                 target := caddr rule;
                 svars := for each var in vars
                        collect var . compress cddr explode var;
                 pattern := subla(svars,pattern);
                 test := subla(svars,test);
                 target := subla (svars,target);
                 vars := for each var in svars collect cdr var;
                 svars := vars;
                 test := simpletsymbolic test;
                 target := simpletsymbolic target;
                 prin2 "for all ";
                 while svars do
                   <<prin2 car svars;
                     svars := cdr svars;
                     if svars then prin2 " , ">>;
                 if test and not test = t then
                   <<prin2t " such that ";
                     printest test;
                     terpri ();
                     prin2t "let">>
                  else
                     prin2t " let";
                 mathprint (list('equal,pattern,target));
              >>;
     end;

symbolic procedure showrulesasymplis!*();
        for each rule in asymplis!*  do
               <<
                 for i:=1:72 do prin2 "-"; terpri();
                 terpri();
                 prin2 " let ";
                 prin2 car rule;
                 prin2 "**";
                 prin2 cdr rule;
                 prin2t " = 0;"
               >>;

symbolic procedure smemb(opr,ls);
    if opr = ls then t
      else
    if atom ls then nil
      else
    smemb(opr,car ls) or smemb(opr,cdr ls);

symbolic procedure selectletvars u;
     if null u then nil
       else
     if idp u then
             begin scalar bus;
                   bus := explode u;
                   if cdr bus and cadr bus = '!= then
                        return list u
                     else
                        return nil;
             end
       else
     if atom u then nil
       else
     union (selectletvars car u, selectletvars cdr u);

symbolic procedure simpletsymbolic u;
    if atom u then u
       else
    if car u = 'quote then simpletsymbolic cadr u
       else
    if car u = 'aeval then simpletsymbolic cadr u
       else
    if car u = 'reval then simpletsymbolic cadr u
       else
    if car u = 'list then simpletsymbolic cdr u
       else
    if car u = 'cond then 'SHOWCOND . simpletsymbolic cdr u
       else
    if isevalfn car u then simpletsymbolic (isevalfn car u . cdr u)
       else
    simpletsymbolic car u . simpletsymbolic cdr u;

symbolic procedure isevalfn u;
    if idp u then
             begin scalar bus,!*lower;
                   bus := explode u;
                   if car bus = 'E and
                      cadr   bus = 'V and
                      caddr bus = 'A and
                      cadddr bus = 'L then return
                            intern compress cddddr bus
                      else return nil;
            end
    else nil;

symbolic procedure printest u;
    if atom u then
             <<prin2 " "; prin2 u, prin2 " ">>
      else
    if car u = 'NOT then
             <<prin2 " not("; printest cadr u; prin2 ") ";>>
      else
    if car u = 'EQUAL then
             <<prin2 " ("; printest cadr u; prin2 " = ";
               printest caddr u; prin2 ") ">>
      else
    if car u = 'NEQ then
             <<prin2 " ("; printest cadr u; prin2 " neq ";
               printest caddr u; prin2 ") ">>
      else
    if car u = 'AND then
             <<prin2 " (";
               u := cdr u;
               while cdr u do
                  <<printest car u; prin2 " and "; u := cdr u>>;
               printest car u; prin2 ") ">>
      else
    if car u = 'OR then
             <<prin2 " (";
               u := cdr u;
               while cdr u do
                  <<printest car u; prin2 " or "; u := cdr u>>;
               printest car u; prin2 ") ">>
      else
    if get(car u,'prtch) then <<prin2 " ("; printest cadr u;
               prin2 get(car u,'prtch) ;
               printest caddr u; prin2 ") ">>
      else

    if length u = 2 then
             <<prin2 car u;
               prin2 " ";
               printest cadr u;
             >>
      else
             <<prin2 " ";
               prin2 car u;
               prin2 "(";
               u := cdr u;
               while u do
                   <<printest car u;
                     u := cdr u;
                     if u then prin2 ",">>;
               prin2 ") ";
              >>;

symbolic procedure condprin (u);
     begin;
         prin2!* " if ";
         u := cdr u;
         maprin caar u;
         prin2!* " then ";
         maprin cadar u;
         u := cdr u;
  loop:
         if caar u = t then
             <<prin2!* " else ";
               maprin cadar u>>
            else
             <<prin2!* " else if ";
               maprin caar u;
               prin2!* " then ";
               maprin cadar u;
             >>;
        u := cdr u;
        if u then goto loop;
     end;

put ('SHOWCOND,'prifn,'condprin);

symbolic operator showrules;

endmodule;

end;
