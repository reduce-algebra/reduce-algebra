module gf2groeb;

% Author: Arthur Norman
% Copyright (c) 2025 Arthur Norman

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

% $Id$

% Here is a high level explanation of the Groebner Basis algorithm
% that this code is working towards.

% F is a set of polynomials
% G := F
% for any pair fi,fj in G
%   define aij = lcm leading terms if f1, fj
% DO {
%     Select a particular pair fi, fj
%        Sij = fi*aij/(lt fi) - fj*aij/(lt fj)
%        [note leading terms cancel]
%     Reduce Sij using all polys in the set G.
%        If the result is non-zero add to G
%    } UNTIL all pairs (including ones involving newly added
%            ones) have been handled.
%
% Improvements on basic scheme:
% (1) Ensure every pair in F gets to try to reduce each other first.
% (2) If leading terms of fi, fj do not share variable then
%     Sij will reduce to zero do not compute all of it.
% (3) Review literature for many more ideas.
% (4) Wonder about use of parallel processing.
%
% Possibly Faugere's F4, F5 is actually what is needed!
% I will not consider any of this to start with.

% So the idea here is that gf2_groeb will be handed a list of Reduce
% polynominals. It make a list G that is the same set but in a distributed
% representation. This is processed and then converted back to Reduce form.

symbolic procedure gf2_groeb F;
  begin
    scalar G;
    if not eqcar(F, 'list) then rederr "gf2_groeb needs a list as input";
    G := for each u in cdr F collect prefix_to_gf2 u;
    G := gf2_expand_base G;
    return 'list . for each u in g collect gf2_to_prefix u
  end;

symbolic procedure gf2_expand_base G;
  G;  % Leave unaltered just for now.

symbolic operator gf2_groeb;


endmodule;

end;
