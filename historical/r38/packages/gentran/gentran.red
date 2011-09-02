module gentran;  % Header module for gentran package.

% Author: Barbara L. Gates.

% Modifications by:  Michael C. Dewar.

create!-package('(gentran utils intrfc templt pre gparser redlsp segmnt
		  lspfor lsprat lspc lsppasc goutput),
		'(contrib gentran));

symbolic smacro procedure smallfloatp u;
   % Returns true if <structure> is a small rounded.
   atom u;

endmodule;

end;
