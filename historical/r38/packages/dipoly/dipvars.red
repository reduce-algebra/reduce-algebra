module dipvars;

% Determine distributive polynomial variables in a prefix form

% Authors: R. Gebauer, A. C. Hearn, H. Kredel

symbolic procedure dipvars u;
%   Returns list of variables in prefix form u
   dipvars1(u,nil);

symbolic procedure dipvars1(u,v);
   if atom u then if constantp u or u memq v then v else u . v
    else if idp car u and get(car u,'dipfn)
     then dipvarslist(cdr u,v)
    else if u memq v then v
    else u . v;

symbolic procedure dipvarslist(u,v);
   if null u then v
    else dipvarslist(cdr u,union(dipvars car u,v));

endmodule;;end;
