% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% (c) 2016 T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

module rlservices;

rl_service {
   name = cad,
   arg = {pos = 1, name = formula, type = Formula},
   arg = {pos = 2, name = porder, type = VarList, default = {}},
   arg = {pos = 3, name = xpolys, type = PolyList, default = {}},
   arg = {pos = 4, name = verbose, type = Switch},
   returns = {type = Formula},
   mode = both};

rl_service {
   name = simpl,
   arg = {pos = 1, name = formula, type = Formula},
   arg = {pos = 2, name = theory, type = Theory, default = {}},
   arg = {pos = 3, name = depth, type = Integer, default = -1},
   arg = {pos = 4, name = siso, type = Switch},
   arg = {pos = 5, name = sisocx, type = Switch},
   arg = {pos = 6, name = siidem, type = Switch},
   arg = {pos = 7, name = sichk, type = Switch},
   arg = {pos = 8, name = sipo, type = Switch},
   arg = {pos = 9, name = sipw, type = Switch},
   arg = {pos = 10, name = sism, type = Switch},
   arg = {pos = 11, name = sipd, type = Switch},
   arg = {pos = 12, name = siexpl, type = Switch},
   arg = {pos = 13, name = siexpla, type = Switch},
   arg = {pos = 14, name = sifac, type = Switch},
%%    arg = {pos = 15, name = sifaco, type = Switch},
%%    arg = {pos = 16, name = siatadv, type = Switch},
%%    arg = {pos = 17, name = sitsqspl, type = Switch},
%%    arg = {pos = 18, name = siplugtheo, type = Switch},
%%    arg = {pos = 19, name = sid, type = Switch},
   returns = {type = Formula},
   mode = both};

endmodule;

end;
