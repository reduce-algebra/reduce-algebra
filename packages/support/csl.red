module csl;  % Support for fast floating point arithmetic in CSL.

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


imports ash, ash1, logand, msd;

exports msd!:;

global '(!!nbfpd);

remflag ('(fl2bf msd!: fix2 rndpwr timbf),'lose);

symbolic inline procedure fix2 u; fix u;

flag('(lshift ashift), 'lose);

symbolic inline procedure msd!: u; msd u;

remflag('(make!:ibf), 'lose);

symbolic inline procedure make!:ibf (mt, ep);
  '!:rd!: . (mt . ep);

flag('(make!:ibf), 'lose);

fluid '(!:bprec!:);

symbolic inline procedure rndpwr j;
  begin
    scalar !#w;   % I use an odd name here to avoid clashes (inline)
%   !#w := mt!: j;
    !#w := cadr j;
    if !#w = 0 then return make!:ibf(0, 0);
    !#w := inorm(!#w, !:bprec!:);
%   return make!:ibf(car !#w, cdr !#w + ep!: j)
    return make!:ibf(car !#w, cdr !#w + cddr j)
  end;

symbolic procedure csl_normbf x;
   begin
      scalar mt,s;
      integer ep;
% Note I write out mt!: and ep!: here because the inlines for them are
% not yet available.
      if (mt := cadr x)=0 then return '(!:rd!: 0 . 0);
      if mt<0 then <<mt := -mt; s := t>>;
% This is pretty well the only place that the LSD function from CSL is used in Reduce.
% Reduce. Up to June 2016 it returned a result perhaps better described as
% "count trailing zeros" rather than "least significant digit". At that stage
% it was rationalized to match its name. The hack here allows fof either old
% or new behaviour.
!#if (equal (lsd 1) 0)
      ep := lsd mt;
!#else
      ep := sub1 lsd mt;
!#endif
      mt := lshift(mt, -ep);
      if s then mt := -mt;
      ep := ep + cddr x;
      return make!:ibf(mt,ep)
   end;

% Use "!#if" not "#if" for bootstrapping reasons.

!#if (not (memq 'vsl lispsystem!*))

remflag('(normbf), 'lose);

symbolic procedure normbf x;
   csl_normbf x;

flag('(normbf), 'lose);

symbolic procedure csl_timbf(u, v);
  begin
     scalar m;
%    m := mt!: u * mt!: v;
     m := cadr u * cadr v;
     if m = 0 then return '(!:rd!: 0 . 0);
     m := inorm(m, !:bprec!:);
%    return make!:ibf(car m, cdr m + ep!: u + ep!: v)
     return make!:ibf(car m, cdr m + cddr u + cddr v)
  end;

symbolic inline procedure timbf(u, v); csl_timbf(u, v);

!#endif

symbolic procedure fl2bf x;
  if not fp!-finite x then rederr "Floating point infinity or NaN" else
  begin scalar u;
    u := frexp x;
    x := cdr u; % mantissa between 0.5 and 1
    u := car u; % exponent
    x := fix(x*2**!!nbfpd);
    return normbf make!:ibf(x,u-!!nbfpd)
  end;

!#if (memq 'vsl lispsystem!*)
flag ('(fl2bf msd!: fix2), 'lose);
!#else
flag ('(fl2bf msd!: fix2 rndpwr timbf), 'lose);
!#endif

set!-print!-precision 6;

% The following definition is appropriate for MSDOS, and the value of
% !!maxbflexp should be OK for all IEEE systems. BEWARE if you have a
% computer with non-IEEE arithmetic, and worry a bit about !!flexperr
% (which is hardly ever used anyway...).
% I put this here to avoid having arith.red do a loop that is terminated
% by a floating point exception, since as of Nov 1994 CSL built using
% Watcom C 10.0a can not recover from such errors more than (about) ten
% times in any one run - this avoids that during system building.
%
% Hahaha - the above comments shows traces of the way in which historical
% real oddities and pain can end up frozen into code. In February 2015
% comments about the situation in November 1994 seem "historical".

global '(!!flexperr !!!~xx !!maxbflexp);

remflag('(find!!maxbflexp), 'lose);

symbolic procedure find!!maxbflexp();
  << !!flexperr := t;
     !!!~xx := expt(2.0, 1023);
     !!maxbflexp := 1022 >>;

flag('(find!!maxbflexp), 'lose);

inline procedure int2id x; % Turns 8-bit value into name. Only OK is under 0x80
  intern list2string list x;

inline procedure id2int x; % Gets first octet of UTF-8 form of name
  car string2list x;

symbolic macro procedure bothtimes u;
   list('eval!-when, '(compile load eval), cadr u);

symbolic macro procedure compiletime u;
   list('eval!-when, '(compile eval), cadr u);

symbolic macro procedure loadtime u;
   list('eval!-when, '(load eval), cadr u);

put('gc, 'simpfg, '((t (verbos t)) (nil (verbos nil))));
flag('(gc), 'switch);

endmodule;

end;
