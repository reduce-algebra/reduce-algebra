% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 2010 Thomas Sturm
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

module assertcheckfn;

compiletime on1 'assert;

% Primitive data types (2.1 of the SL Report)
struct integer checked by fixp;
struct floating checked by floatp;
struct id checked by idp;
struct string checked by stringp;
struct dottedpair checked by pairp;
struct vector checked by vectorp;
struct functionpointer checked by codep;

% Classes of Primitive Data Types (2.2. of the SL Report)
struct boolean checked by booleanp;
struct extraboolean;
struct ftype checked by ftypep;
struct number checked by numberp;
struct constant checked by constantp;
struct any;
struct atom checked by atom;

% Structures (2.3 of SL Report)
struct list checked by listp;
struct alist checked by alistp;
struct condform checked by condformp;
struct lambdaexpression checked by lambdap;
struct function checked by functionp;

% Lists of Fixed Length:
struct list1 checked by list1p;
struct list2 checked by list2p;
struct list3 checked by list3p;
struct list4 checked by list4p;
struct list5 checked by list5p;
struct list6 checked by list6p;
struct list7 checked by list7p;

% Standard Forms and Standard Quotients etc.
struct sf checked by sfpx;
struct sf!* checked by sfpx!*;  % non-zero SF
struct noordsf checked by noordsfpx;
struct sq checked by sqp;
struct domain checked by domainp;
struct kernel checked by assert_kernelp;

compiletime off1 'assert;

procedure booleanp(x);
   x eq t or x eq nil;

procedure ftypep(x);
   x eq 'expr or x eq 'fexpr or x eq 'macro;

% procedure alistp(l);
%    not l or pairp l and pairp car l and alistp cdr l;

procedure condformp(x);
   not x or pairp x and list2p car x and condformp cdr x;

procedure lambdap(x);
   pairp x and eqcar(x,'lambda) and
      pairp cdr x and listp cadr x and
      pairp cddr x and listp caddr x and
      not cdddr x;

procedure functionp(x);
   codep x or lambdap x;

procedure list1p(x);
   pairp x and not cdr x;

procedure list2p(x);
   pairp x and list1p cdr x;

procedure list3p(x);
   pairp x and list2p cdr x;

procedure list4p(x);
   pairp x and list3p cdr x;

procedure list5p(x);
   pairp x and list4p cdr x;

procedure list6p(x);
   pairp x and list5p cdr x;

procedure list7p(x);
   pairp x and list6p cdr x;

procedure sfpx(u);
   sfpx1(u,nil,nil,0,t);

procedure noordsfpx(u);
   sfpx1(u,nil,nil,0,nil);

procedure sfpx1(u,vl,v,d,chkord);
   % Variables from vl must not occur in u and the variable v must occur
   % in u only with a degress less than d. New-found main variables must
   % be smaller than v and smaller than all variables in vl wrt.
   % korder!* and orderp.
   begin scalar c,l,p,r,vv; integer dd;
      if domainp u then
	 return t;
      if not pairp u then
 	 return nil;
      % Decompose u as follows: u = l + r, l = c * p, p = vv ^ dd
      l := lt u;
      r := red u;
      if not pairp l then
 	 return nil;
      c := tc l;
      p := tpow l;
      if not pairp p then
 	 return nil;
      vv := car p;
      if not assert_kernelp vv then
	 return nil;
      dd := pdeg p;
      if vv eq v then
	 % We are considering a reductum and the variable has not changed.
	 return dd < d and
 	    sfpx1(c,v . vl,nil,0,chkord) and sfpx1(r,vl,v,dd,chkord);
      % We are considering the original form or an lc, or a reductum
      % where the variable has changed from v to vv.
      if v then
	 vl := v . vl;
      % vv must be smaller than all variables in vl wrt. the current
      % kernel order. By recursion, vl is sorted so that it is
      % sufficient to compare with car vl. I construct linear powers in
      % order to use ordpp; I could not find a suitable function for
      % directly comparing (possibly composite) kernels. The relevant
      % code is mostly in alg/order.red and hardly documented.
      if chkord and vl and ordpp(vv .** 1,car vl .** 1) then
	 % We have seen a smaller variable before.
	 return nil;
      return sfpx1(c,vv . vl,nil,0,chkord) and sfpx1(r,vl,vv,dd,chkord)
   end;

procedure assert_kernelp(u);
   begin scalar w;
      if idp u then
 	 return t;
      if not pairp u then
 	 return nil;
      if get(car u,'fkernfn) then
	 return t;
      w := if atom car u then get(car u,'klist) else exlist!*;
      return atsoc(u,w)
   end;

procedure sfpx!*(u);
   % non-zero standard form predicate (extended).
   u and sfpx u;

procedure sqp(q);
   pairp q and sfpx numr q and sfpx denr q;

procedure am_listp(u);
   listp u and eqcar(u,'list);

procedure am_polyp(u);
   domainp u or idp u or
      pairp u and (assert_polyopp car u or car u eq '!*sq and denr cadr u eq 1);

procedure assert_polyopp(op);
   op memq '(plus difference minus times expt);

endmodule;

end;  % of file
