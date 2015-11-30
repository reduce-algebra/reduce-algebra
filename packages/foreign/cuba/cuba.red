% Interface between Reduce/CSL and the Cuba numerical integration library
% http://www.feynarts.de/cuba.

% Author: Kostas N. Oikonomou

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

module cuba;

#if (memq 'csl lispsystem!*)

create!-package('(cuba cuba_main alg_intf), nil);

exports cuba_int, 
   cuba_gen_par, cuba_statefile, cuba_verbosity, 
   cuba_set_flags_bit, cuba_clear_flags_bit,
   cuba_vegas_par, cuba_suave_par, cuba_divonne_par, cuba_cuhre_par;

global '(
   libredcuba_loc!*
   libredcuba!*
   cuba_algorithms!*
   newdoublearray!*
   setdoublearray!*
   freedoublearray!*
   cuba_gen_par!*
   cuba_set_flags_bit!*
   cuba_clear_flags_bit!*
   cuba_vegas_par!*
   cuba_suave_par!*
   cuba_divonne_par!*
   cuba_cuhre_par!*
   cuba_verbosity!*
   cuba_statefile!*
   set_alg!*
   set_integrand!*
   get_result!*
   cuba_int!*
);

share cuba_algorithms;  % see cuba_main.red

#endif

endmodule;  % cuba

end;
