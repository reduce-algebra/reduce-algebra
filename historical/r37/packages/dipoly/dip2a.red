module dip2a;

%/* Functions for converting distributive forms into prefix forms*/

%/*Authors: R. Gebauer, A. C. Hearn, H. Kredel*/

expr procedure dip2a u;
%   /* Returns prefix equivalent of distributive polynomial u*/
   if dipzero!? u then 0 else dipreplus dip2a1 u;

expr procedure dip2a1 u;
   if dipzero!? u then nil
    else ((if bcminus!? x then list('minus,dipretimes(bc2a bcneg x . y))
           else dipretimes(bc2a x . y))
         where x = diplbc u, y = expvec2a dipevlmon u)
           . dip2a1 dipmred u;

expr procedure dipreplus u;
   if atom u then u else if null cdr u then car u else 'plus . u;

expr procedure dipretimes u;
%   /* U is a list of prefix expressions the first of which is a number.
%     Result is prefix representation for their product*/
   if car u = 1 then if cdr u then dipretimes cdr u else 1
    else if null cdr u then car u
    else 'times . u;

endmodule;

end;
