module gf2;  % Polynomial arithmetic where coefficients are in GF(2).

lisp if !*csl then enable!-errorset(3, 3); % Debugging option while I develop.
lisp if !*psl then on backtrace;

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


% This is code that supports either a sparse or dense representation for
% polynomials over the domain GF(2) that has just 2 elements. The
% intent is to explore the calculation and use of Groebner Bases over this
% domain - but at present there is no code to do that part and when there
% is it will start of coded in a naive manner and so will not be especially
% fast. But if that shows promise this package will provide a starting point
% for anybody who wants to extend it to use more sophisticated algorithms
% for the costly bits.

% What works as of July 2025 is (roughly)
%   on/off gf2_sparse;
%         The default is a sparse representation.
%   lisp (gf2_degree_bits := N);
%         Set the width of bitfields used in the dense repre4sentation.
%         This limits the maximum exponent that can be handled, but a
%         small setting saves space and time.
%   gf2_vars {x, y, z, v(1), v(2), v(3)};
%         ONLY names declared this way may appear in the formulae worked
%         with here, and the ordering in the list provided to gf2_vars
%         sets an internal ordering (and that ordering may have big cost
%         implementations for Groebner Base construction).
%   w := prefix_to_gf2 (x^2*y + y^2 + z);
%         Turn a Reduce formula into the special form used here.
%   gf2_to_prefix w;
%         Turn back into a Reduce expression.

% There are internal functions mainly intended for use in symbolic mode:
%   gf2_lt                    get leading term of a distributed form
%   gf2_red                   get reductum (ie remove leading term)
%   gf2_plus, gf2_times       + and *
%   gf2_times_term(term,poly) multiply term and polynomial
%   gf2_quotient_two_terms(t1,t2) divide one term by another. Return nil
%                                 if not possible.
%   gf2_gcd_two_terms              a term that is the gcd of two terms
%   gf2_lcm_two_terms              similarly for lcm

% Remember that over GF(2) subtraction is the same as addition.

create!-package('(gf2 gf2groeb), nil);


% A flag gf2_sparse selects as between a sense and a sparse internal
% representation. The default is sparse. This must be set before declaring
% variables. In the "dense" case you may set the (symbolic mode) variable
% gf2_degree_bits to control space use in a bitmap. The command
%   lisp (gf2_degree_bits := 10);
% would allow degrees of all polynomials that arise to be as large
% as 2^10-1 = 1023. I intend to detect exponent overflow so if you start
% with too small a setting (the default is 12, allowing degrees to be
% as high as 4095) a diagnostic will be issued and you can perhaps restart
% with a larger value. 
%
% One must first declare the variables using a statement such as
%    operator v;
%    gf2_vars {x, v 1, y, z, v 77, v 11};
% Each name must be a symbol or an operator applied to an integer.
% The order in which names are listed may have an impact on computing costs!
%
% Any use of gf2_vars cancels the status of any previous declarations or
% computations.

switch gf2_sparse=on;

fluid '(gf2_var_names gf2_count gf2_degree_bits gf2_overflow_bits);
gf2_var_names := mkhash(16, 0, 1.5);
gf2_degree_bits := 12;

% All gf2_vars will do is to allocate an index in the range 1,2,... to each
% valiable. Polynomials (over GF2) will then be represented as for a graded
% lexographic scheme as
% (1) Sparse:
%     (  ((0 . x0) (i . xi) (j . xj) ...)   more terms)
% where i and j are integers standing for variables, and and the xi, xj are
% the corresponding exponents. Entries in a term are sorted based on ascending
% variable-keys. The special key 0 is such that x0 gived the sum of all the
% rest of the exponents in the term. Terms are sorted such that the largest
% (lexically, including the impact of x0) come first. So
% a polynomial x^2*y + y^2 + z might be
%   ( ((0 . 3) (1 . 2) (2 . 1))
%     ((0 . 2) (2 . 2))
%     ((0 . 1) (3 . 1)) )
% The use of integers as variable names here is motivated by the idea that
% comparisons between small integers is liable to be faster then comparing
% symbolic names.
%
% (2) Dense:
%    ( term1 term2 ...)
% where each term is represented as an integer which can be thought of as
% a concatenation of g2fdegreebits-wide fields, so if that value is set to
% 11 then x^2*y + y^2 + z will be
%   ( 0x003002001000  0x002000002000 0x001000000001)
%       tot  x  y  z    tot  x  y  z   tot  x  y  z
% I will require that the largest exponent present uses at most
% gf2_degree_bits bits so there is a guard bit that should always be zero.
% That ius why a setting of 11 has led to bit-fields of width 12.
% The guard bit us used so that when two monomials are to be divided and
% the integer representations are subtracted, if any resulting exponent would
% end up negative one of the guard bits would be set. Masking with the
% gf2_overflow_bits will make it easy to detect this case. Well I can
% probably afford to test for overflow during multiplication as well.
% This scheme will generally pack multiple exponents into each machine
% word and for a modest number of variables be both compact and fast.

% These selectors get the leading term and reductum of a distrubuted form.

symbolic inline procedure gf2_lt u;
  car u;

symbolic inline procedure gf2_red u;
  cdr u;

symbolic procedure gf2_vars l;
  begin
    scalar guard := lshift(1, gf2_degree_bits);
    gf2_count := 0;
    gf2_overflow_bits := guard;
% Tidy up any previous setting. hashcontents gf2_var_names will be a list
% rather like ( ... (4 x) ... (6 (vv 3)) ...)
    for each v in hashcontents gf2_var_names do <<
      v := cadr v;
      if atom v then remprop(v, 'gf2_index)
      else remprop(car v, 'gf2_opindex) >>;
    clrhash gf2_var_names;
    if not eqcar(l, 'list) then rederr "gf2_vars needs a list as its argument";
    for each v in cdr l do <<
      if not !*gf2_sparse then
        gf2_overflow_bits :=
          lshift(gf2_overflow_bits, gf2_degree_bits+1) + guard;
      gf2_count := gf2_count+1;
% If a name is say "x" then I give x a gf2_index value specifying its index.
% If the name is say "(x 3)" then x will have a gf2_opindex property that is
% a hash table mapping 3 onto the index.
% I will complain if a name is specified more than once.
      if idp v then <<
        if get(v, 'gf2_index) then rederr "repeated name in gf2_vars"
        else put(v, 'gf2_index, gf2_count) >>
      else if atom v or
        not idp car v or
        atom cdr v or
        not fixp cadr v or
        not null cddr v then
        rederr "gf2_vars must have symbols or symbol(integer) names"
      else begin
        scalar h := get(car v, 'gf2_opindex);
% If my "name" is of the form (op int) then I will put a hash table
% on the property list of the operator "op". This will hash based on "EQ"
% since the only keys I should ever use will be fixnums, and that then
% will be as fast as possible.
        if null h then put(car v, 'gf2_opindex, h := mkhash(16, 0, 1.5));
        if gethash(cadr v, h) then
          rederr "repeated (operator) name in gf2_vars"
        else puthash(cadr v, h, gf2_count)
      end;
% gf2_var_names is a hash table that maps from an index back onto the
% name that it represents.
      puthash(gf2_count, gf2_var_names, v . gethash(gf2_count, gf2_var_names)) >>;
    return nil
  end;

symbolic operator gf2_vars;

% Given a name find the index numver that will be used to stand for it.
% The tables accessed here were set up when somebody used gf2_vars.

symbolic procedure gf2_index v;
  if idp v then <<
    v := get(v, 'gf2_index);
    if null v then rederr "unknown variable used"
    else v >>
  else begin
    scalar h := get(car v, 'gf2_opindex);
    if null h then rederr "unknown operator-form variable used";
    v := gethash(cadr v, h);
    if null v then rederr "unknown operator-form variable used"
    else return v
  end;    

% Add two distributed polynominals. Note that the inputs may either be
% tagged or untagged.

symbolic procedure gf2_plus(u, v);
  if eqcar(u, '!*gf2) then gf2_plus(cdr u, v)
  else if eqcar(v, '!*gf2) then gf2_plus(u, cdr v)
  else if !*gf2_sparse then gf2_sparse_plus(u, v)
  else dense_gf2_plus(u, v);

symbolic procedure gf2_sparse_plus(u, v);
  if null u then v
  else if null v then u
  else if gf2_lt u = gf2_lt v then gf2_sparse_plus(gf2_red u, gf2_red v)
  else if gf2_sparse_before(gf2_lt u, gf2_lt v) then
    gf2_lt u . gf2_sparse_plus(gf2_red u, v)
  else gf2_lt v . gf2_sparse_plus(u, gf2_red v);

symbolic procedure gf2_sparse_before(a, b);
  if null a then
    if null b then rederr "a and b identical in gf2_sparse_before"
    else nil
  else if null b then t
% Each of a and b will be lists like ((varindex . degree) ...) and so
% caar accesses the identity of the variable (stored as an integer) and
% cdar gets the associated degree.
  else if caar a > caar b then t     % Order on leading variable
  else if caar a < caar b then nil
  else if cdar a > cdar b then t     % Order on leading degree if vars match
  else if cdar a < cdar b then nil
  else gf2_sparse_before(cdr a, cdr b);% Else consider next variable

symbolic procedure dense_gf2_plus(u, v);
  if null u then v
  else if null v then u
  else if gf2_lt u > gf2_lt v then gf2_lt u . dense_gf2_plus(gf2_red u, v) 
  else if gf2_lt u < gf2_lt v then gf2_lt v . dense_gf2_plus(u, gf2_red v)
  else dense_gf2_plus(gf2_red u, gf2_red v);

% Multiply two distributed polynomials.

symbolic procedure gf2_times(u, v);
  if eqcar(u, '!*gf2) then gf2_times(cdr u, v)
  else if eqcar(v, '!*gf2) then gf2_times(u, cdr v)
  else if !*gf2_sparse then gf2_sparse_times(u, v)
  else dense_gf2_times(u, v);

symbolic procedure gf2_sparse_times(u, v);
  begin
    scalar r;
% I think it is important to use the smallest (ie the last) term of
% u first because that makes eacg gf2_sparse_plus merge in its data towards
% the front of the growing list r. Without the call to reverse it would
% tend to concatenate and that would involve scanning all the way down r.
    for each a in reverse u do
      r := gf2_sparse_plus(r, gf2_sparse_times_term(a, v));
    return r
  end;

symbolic procedure gf2_times_term(a, v);
  if !*gf2_sparse then gf2_sparse_times_term(a, v)
  else dense_gf2_times_term(a, v);

symbolic procedure gf2_sparse_times_term(a, v);
  for each b in v collect gf2_sparse_times_two_terms(a, b);

symbolic procedure gf2_sparse_times_two_terms(a, b);
  if null a then b
  else if null b then a
  else if caar a < caar b then car a . gf2_sparse_times_two_terms(cdr a, b)
  else if caar a > caar b then car b . gf2_sparse_times_two_terms(a, cdr b)
  else (caar a . (cdar a + cdar b)) . gf2_sparse_times_two_terms(cdr a, cdr b);

symbolic procedure dense_gf2_times(u, v);
  begin
    scalar r;
    for each a in reverse u do
      r := dense_gf2_plus(r, dense_gf2_times_term(a, v));
    return r
  end;

symbolic procedure dense_gf2_times_term(a, v);
  for each b in v collect dense_gf2_times_two_terms(a, b);

symbolic procedure dense_gf2_times_two_terms(a, b);
  begin
    scalar r := a + b;
    if land(r, gf2_overflow_bits) neq 0 then
      rederr "exponent overflow in gf2_times"
    else return r
  end;

symbolic procedure gf2_quotient_two_terms(a, b);
  if !*gf2_sparse then gf2_sparse_quotient_two_terms(a, b)
  else gf2_dense_quotient_two_terms(a, b);

symbolic procedure gf2_sparse_quotient_two_terms(a, b);
  begin
    scalar w, r, more:=t;
    while a and b and more do <<
      if caar a < caar b then more := nil
      else if caar a > caar b then push(pop a, r)
      else <<
        w := cdar a - cdar b;
        if w < 0 then more := nil   % breaks out of loop with b non-nil
        else if w neq 0 or caar a = 0 then <<
          pop b; push(car pop a . w, r) >>
        else << pop a; pop b >> >> >>;
    if b then return nil;           % "does not go".
    while r do push(pop r, a);
    return a
  end;

symbolic procedure dense_gf2_quotient_two_terms(a, b);
  begin
    scalar r := a - b;
    if land(r, gf2_overflow_bits) neq 0 then return nil
    else return r
  end;

% My code to convert from Reduce form to the new distributed one may
% recurse deeply and otherwise be inefficient. As against the cost of
% forming a Groebner base I hardly care! This returns a tagged result.

symbolic procedure sf_to_gf2 u;
  if null u then nil
  else if u = 1 then <<
    if !*gf2_sparse then '((0 . 0))
    else '(0) >>
  else if domainp u then rederr "only the constant 1 is allowed here"
  else begin;
    scalar var:=mvar u, x:=ldeg u, c:=lc u, r:= red u, w;
    w := gf2_index var;
    if null w then rederr "undeclared variable in gf2 expression";
    if !*gf2_sparse then w := list list(0 . x, w . x)
    else <<
      if x>=lshift(1, gf2_degree_bits) then
        rederr "degree too high in convert_to_gf2";
      w := list(lshift(x, (gf2_count-w)*(gf2_degree_bits+1)) +
                lshift(x, gf2_count*(gf2_degree_bits+1))) >>;
    if c neq 1 then w := gf2_times(w, sf_to_gf2 c);
    if r neq nil then w := gf2_plus(w, sf_to_gf2 r);
    return w
  end;

% Now code to turn distributed forms back into normal Reduce structures.

symbolic procedure gf2_to_sf u;
  if eqcar(u, '!*gf2) then gf2_to_sf cdr u
  else if !*gf2_sparse then gf2_sparse_to_sf u
  else dense_gf2_to_sf u;

symbolic procedure gf2_to_sq u;
  gf2_to_sf u ./ 1;

symbolic procedure gf2_to_prefix u;
  prepf gf2_to_sf u;

flag('(gf2_to_prefix), 'opfn);

symbolic procedure gf2_sparse_to_sf u;
  begin
    scalar r;
    for each a in reverse u do
      r := addf(r, gf2_sparse_term_to_sf a);
    return r
  end;

symbolic procedure gf2_sparse_term_to_sf a;
  begin
    scalar r := 1, v;
% I will ignore the first term of u because that just holds the total
% degree.
    for each w in cdr a do << 
      v := gethash(car w, gf2_var_names);
      r := multf(r, !*p2f mksp(car v, cdr w)) >>;
    return r 
  end;

symbolic procedure dense_gf2_to_sf u;
  begin
    scalar r;
    for each a in reverse u do r := addf(r, dense_gf2_term_to_sf a);
    return r
  end;

symbolic procedure dense_gf2_term_to_sf a;
  begin
    scalar r:=1, w, x;
    for i := 1:gf2_count do <<
      w := land(a, lshift(1, gf2_degree_bits)-1);
      if w neq 0 then <<
        x := gethash(gf2_count-i+1, gf2_var_names);
        r := multf(r, !*p2f mksp(car x, w)) >>;
      a := lshift(a, -(gf2_degree_bits+1)) >>;
    return r
  end;

% prefix_to_gf2 takes a prefix form and converts it to distributed form.
% So that I can work a bit better in algebraic mode what it returns has
% the operator "*gf2" stuck on the front.

symbolic procedure prefix_to_gf2 u;
  begin
    u := simp u;
    if denr u neq 1 then rederr "prefix_to_gf2 must not be given a fraction";
    return '!*gf2 .  sf_to_gf2 numr u
  end;

% The next few lines arrange that data tagged as "!*gf2" will not get
% simplified by Reduce and can be printed acceptably.

symbolic procedure gf2psopfn u;
  '!*gf2 . u;

put('!*gf2, 'psopfn, 'gf2psopfn);

symbolic procedure gf2_print u;
  begin
    scalar first := t;
    prin2!* "!*gf2(";
    for each a in cdr u do <<
      if null first then prin2!* ", ";
      first := nil;
      prin2!* a >>;
    prin2!* ")";
    return u
  end;

put('!*gf2, 'prifn, 'gf2_print);

symbolic procedure gf2_fancy_print u;
  begin
    scalar first := t;
    fancy!-prin2 "!*gf2(";
    for each a in cdr u do <<
      if null first then fancy!-prin2 ", ";
      first := nil;
      if atom a then fancy!-prin2 a
      else <<
% Ha ha - if the user had just typed in a !*gf2 form it may have
% (cons v x) where I really wanted (v . x).
        if eqcar(a, 'cons) then a := cadr a . caddr a;
        fancy!-prin2 car a;
        fancy!-prin2 " . ";
        fancy!-prin2 cdr a >> >>;
    fancy!-prin2 ")";
    return u
  end;

put('!*gf2, 'fancy!-prifn, 'gf2_fancy_print);

% tr gf2_fancy_print;

symbolic operator prefix_to_gf2;

% I need to be able to take gcd and lcm of single terms.

symbolic procedure gf2_gcd_two_terms(a, b);
  if !*gf2_sparse then gf2_sparse_gcd_two_terms(a, b)
  else dense_gf2_gcd_two_terms(a, b);

% If a and b have entries (v . x1) and (v . x2) the gcd will have
% one (v . min(x1,x2)). Any variables that are present in only one of
% a and b do not show up in the gcd. The total degree term has to be
% calculated afresh.

symbolic procedure gf2_sparse_gcd_two_terms(a, b);
  begin
    scalar n:=0, m, r;
    a := cdr a;   % move past the overall weight.
    b := cdr b;
    while a and b do <<
      if caar a > caar b then a := cdr a
      else if caar b > caar a then b := cdr b
      else <<
        r := (caar a . (m := min(cdar a, cdar b))) . r;
        n := n + m;
        a := cdr a;
        b := cdr b >> >>;
    return (0 . n) . reverse r
  end;

symbolic procedure dense_gf2_gcd_two_terms(a, b);
  nil;

symbolic procedure gf2_lcm_two_terms(a, b);
  if !*gf2_sparse then gf2_sparse_lcm_two_terms(a, b)
  else dense_gf2_lcm_two_terms(a, b);

% (v . x1) and (v . x2) lead to (v . max(x1, x2)) and if a variable
% is mentioned in one but not both of a, b then it appears unchanged
% in the lcm.

symbolic procedure gf2_sparse_lcm_two_terms(a, b);
  begin
    scalar n:=0, m, r;
    a := cdr a;
    b := cdr b;
    while a and b do <<
      if caar a > caar b then <<
         r := car a . r;
         n := n + cdar a;
         a := cdr a >>
      else if caar b > caar a then <<
         r := car b . r;
         n := n + cdar b;
         b := cdr b >>
      else <<
        r := (caar a . (m := max(cdar a, cdar b))) . r;
        n := n + m;
        a := cdr a;
        b := cdr b >> >>;
    while a do <<
      r := car a . r;
      n := n + cdar a;
      a := cdr a >>; 
    while b do <<
      r := car b . r;
      n := n + cdar b;
      b := cdr b >>; 
    return (0 . n) . reverse r
  end;

symbolic procedure dense_gf2_lcm_two_terms(a, b);
  nil;

endmodule;

end;
