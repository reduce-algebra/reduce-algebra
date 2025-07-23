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
% Note that I untag the distributed forms (ie remove the "!*g2f" from the
% front of the list.
    G := for each u in cdr F collect cdr prefix_to_gf2 u;
    G := gf2_expand_base G;
    return 'list . for each u in g collect gf2_to_prefix u
  end;

% I am going to code this with emphasis on clarity and minimal code
% and no real concern about performance!

symbolic procedure gf2_expand_base G;
  begin
    scalar ul, S,
           pending:=for each p on G collect p;
% Here pending is a list of points in G where the first element has not
% been looked at. So I can take an item from pending and make an S
% polynomial from its first and each of the remaining items in it. If this S
% is non-zero I add it to G and add an item to pending so it will in due
% course be processed. This scheme should avoid computing both S(u,v) and
% S(v,u).
% It would be acceptable to make pending a priority queue rather than
% a simple stack if one could invent a cheap heuristic that would lead to
% productive cases being handled first.
    while pending do <<
      ul := pop pending;
princ "ul="; print ul;
      for each v in cdr ul do <<
        S := gf2_S(car ul, v, G);
        if S then <<
% Am I supposed to reduce everything in G by S here? 
          G := S . G;
          push(G, pending) >> >> >>;
% To get a reduced base here I would need to scan G and spot cases
% where one leading coefficient divided nicely into the other...
    return G
  end;

symbolic procedure gf2_S(u, v, G);
  begin
    scalar gg := gf2_gcd_two_terms(gf2_lt u, gf2_lt v),
           u0 := gf2_quotient_two_terms(gf2_lt u, gg),
           v0 := gf2_quotient_two_terms(gf2_lt v, gg),
           S := gf2_plus(gf2_times_term(v0, u),
                         gf2_times_term(u0, v));
    printc "Generate S poly from";
    princ "u="; print u;
    princ "v="; print v;
    princ "S="; print S;
% Now I need to reduce S using all the polynomials on G
    return nil
  end;

tr gf2_S, gf2_term_gcd, gf2_quotient_two_terms;

symbolic operator gf2_groeb;

endmodule;

end;
