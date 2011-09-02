% ----------------------------------------------------------------------
% $Id: pasfbnf.red,v 1.3 2003/11/05 13:27:14 lasaruk Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2002 A. Dolzmann, A. Seidl, and T. Sturm
% ----------------------------------------------------------------------
% $Log: pasfbnf.red,v $
% Revision 1.3  2003/11/05 13:27:14  lasaruk
% Some major redlog programming rules applied to the code.
% Formulas are made positive acc. to the current kernel order.
%
% Revision 1.2  2003/10/16 16:17:38  lasaruk
% Compiler error messages partially removed. All others are due
% to the noncompleteness of packet.
%
% Revision 1.1  2003/05/22 22:00:58  lasaruk
% DNF added.
%

lisp <<
   fluid '(pasf_bnf_rcsid!* pasf_bnf_copyright!*);
   pasf_bnf_rcsid!* := "$Id: pasfbnf.red,v 1.3 2003/11/05 13:27:14 lasaruk Exp $";
   pasf_bnf_copyright!* :=
      "Copyright (c) 1995-2002 by A. Dolzmann, A. Seidl, and T. Sturm"
>>;

module pasfbnf;

% Methods for DNF and CNF computation

procedure pasf_sacat(a1,a2,gor);
   % Ordered field standard form subsume and cut atomic formula. [a1]
   % and [a2] are atomic formulas; [gor] is one of [or], [and].
   % Returns for the first case trivially nil.
   nil;

endmodule; % pasfbnf

end; % of file



