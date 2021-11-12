% (c) 2019 by T. Sturm (http://science.thomas-sturm.de/)
%
% This software is distributed under CC BY-NC-ND 4.0
% https://creativecommons.org/licenses/by-nc-nd/4.0/legalcode
%
% You are free to: SHARE — copy and redistribute the material in any medium or
% format. The licensor cannot revoke these freedoms as long as you follow the
% following license terms: ATTRIBUTION — You must give appropriate credit,
% provide a link to the license, and indicate if changes were made. You may do
% so in any reasonable manner, but not in any way that suggests the licensor
% endorses you or your use. NON-COMMERCIAL — You may not use the material for
% commercial purposes. NO-DERIVATIVES — If you remix, transform, or build upon
% the material, you may not distribute the modified material.
%
module strings;

algebraic procedure cat(l);
   symbolic lto_sconcat cdr l;

algebraic procedure strDowncase(s);
   symbolic lto_downcase s;

symbolic operator strEqual;
symbolic procedure strEqual(s1, s2);
   if s1 = s2 then 1 else 0;

symbolic operator strFromExpr;
symbolic procedure strFromExpr(x, convert);
   compress for each c in explode ioto_smaprin x join
      if convert = 1 and c eq '!{ then
    {'![}
      else if convert = 1 and c eq '!} then
    {'!]}
      else if c eq '!, then
    {'!,, '! }
      else if c neq !$eol!$ then
    {c};

symbolic operator strFromStrList;
symbolic procedure strFromStrList(x, convert);
   % Requires special treatment, because AM prints strings without double
   % quotes.
   begin scalar s; integer comma;
      s := if convert = 1 then "[" else "{";
      comma := "";
      for each c in cdr x do <<
    s := lto_sconcat {s, comma, """", c, """"};
          comma := ", "
      >>;
      s := lto_sconcat {s, if convert = 1 then "]" else "}"};
      return s
   end;

symbolic operator strFromRoundedExpr;
symbolic procedure strFromRoundedExpr(x, convert);
   % x is an numeric expression or nested lists containing only numeric
   % expressions.
   strFromExpr(exprToFloatExpr x, convert);

symbolic procedure exprToFloatExpr(x);
   % x is an numeric expression or nested lists containing only numeric
   % expressions.
   if eqcar(x, 'list) then
      'list . for each y in cdr x collect exprToFloatExpr y
   else
      evalf0 {x, 12};

endmodule;

end;
