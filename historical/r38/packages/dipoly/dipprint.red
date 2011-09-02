module dipprint;   %/* printing routines for distributive polynomials*/

% Authors: R. Gebauer, A. C. Hearn, H. Kredel

symbolic procedure diplprint u;
%    Prints a list of distributive polynomials using dipprint
     for each v in u do dipprint v;

symbolic procedure dipprint u;
%   Prints a distributive polynomial in infix form
   <<terpri(); dipprint1(u,nil); terpri(); terpri()>>;

symbolic procedure dipprint1(u,v);
%     Prints a distributive polynomial in infix form.
%     U is a distributive form. V is a flag which is true if a term
%     has preceded current form
   if dipzero!? u then if null v then dipprin2 0 else nil
    else begin scalar bool,w;
       w := diplbc u;
       if bcminus!? w then <<bool := t; w := bcneg w>>;
       if bool then dipprin2 " - " else if v then dipprin2 " + ";
       (if not bcone!? w or evzero!? x then <<bcprin w; dipevlpri(x,t)>>
	 else dipevlpri(x,nil))
	   where x = dipevlmon u;
       dipprint1(dipmred u,t) end;

symbolic procedure dipprin2 u;
%   Prints u, preceding by two EOL's if we have reached column 70
   <<if posn()>69 then <<terpri(); terpri()>>; prin2 u>>;

endmodule;;end;
