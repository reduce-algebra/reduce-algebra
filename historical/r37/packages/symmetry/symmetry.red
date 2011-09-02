module symmetry;
%
% ----------------------------------------------------------
%                       Symmetry Package 
% ----------------------------------------------------------
%
% Author : Karin Gatermann
%          Konrad-Zuse-Zentrum fuer
%          Informationstechnik Berlin
%          Heilbronner Str. 10
%          W-1000 Berlin 31
%          Germany
%          Email: Gatermann@sc.ZIB-Berlin.de
%
% Version 1.0   9. December 1991
% 
% Abstract:
% ---------
% This program is an implementation of the algorithm
% for computation of symmetry adapted bases from the
% theory of linear representations of finite grous.
% Projections for the computation of block diagonal form 
% of matrices are computed having the symmetry of a group.
%
% 
% REDUCE 3.4 is required.
%
% References:
% -----------
% J.-P. Serre, Linear Representations of Finite Groups.
% Springer, New York (1977).
% E. Stiefel, A. F{\"a}ssler, Gruppentheoretische
%  Methoden und ihre Anwendung. Teubner, Stuttgart (1979). 
%  (English translation to appear by Birkh\"auser (1992)).
%
% Keywords: 
% --------
%           linear representations, symmetry adapted bases,
%           matrix with the symmetry of a group,
%           block diagonalization
%
% symmetry.red
% definition of available algebraic operators

% To build a fast loading version of this package, the following
% sequence of commands should be used:

create!-package('(symmetry symdata1 symdata2),'(contrib symmetry));

load!-package 'symaux;

endmodule;

end;
