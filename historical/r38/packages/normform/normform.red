module normform; % Package for the computation of several normal forms.
%                                                                      %
% This file contains routines for computation of the following         %
% normal forms of matrices:                                            %
%                                                                      %
%  - smithex_int                                                       %
%  - smithex                                                           %
%  - frobenius                                                         %
%  - ratjordan                                                         %
%  - jordansymbolic                                                    %
%  - jordan                                                            %
%                                                                      %
% The manual for this package is found in the normform.tex file.       %
% It includes descriptions of the various normal forms.                %
%                                                                      %
% Further examples are found in the normform.log file.                 %
%                                                                      %
% For a description of the algorithms see the comments.                %
%                                                                      %
%                                                                      %
% Author: Matt Rebbeck   Nov '93 - Feb '94                             %
%                                                                      %
% This code has been converted from the normform and Normform packages %
% written by T.M.L. Mulders and A.H.M. Levelt for Maple.               %
%                                                                      %
% normform contains one switch: looking_good. If using xr, the X       %
% interface for REDUCE, switching this on will improve the appearance  %
% of the output. The switch serves no (useful) purpose in standard     %
% REDUCE (ie: not using xr).                                           %
%                                                                      %
%**********************************************************************%

create!-package('(normform jordan jordsymb ratjord froben matarg
		  nestdom smithex smithex1),'(contrib normform));

endmodule;

end;




















