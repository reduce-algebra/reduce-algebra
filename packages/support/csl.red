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

fluid '(!!nbfpd);

remflag ('(fl2bf msd!: fix2 rndpwr timbf),'lose);

symbolic inline procedure fix2 u; fix u;

%remflag('(lshift ashift), 'lose);
%
%% lshift & ashift are now built in to CSL
%
%symbolic inline procedure lshift(m,d); ash(m,d);
%
%symbolic inline procedure ashift(m,d); ash1(m,d);

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
      ep := lsd mt;
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

% At the stage that there was a "patch" mechanism used to update Reduce
% this definition was needed here - including the jollies with the 'lose
% flag - so that patching could apply to code within rlisp. Since the
% Sourceforge release of Reduce the old patch mechanism has become redundant
% and so this ugliness can be removed. This makes some comments in
% cslprolo redundant too.

%remflag('(copyd), 'lose);
%
%symbolic procedure copyd(new,old);
%% Copy the function definition from old id to new.
%   begin scalar x;
%      x := getd old;
%% If loading with !*savedef = '!*savedef then the actual definitions
%% do not get loaded, but the source forms do...
%      if null x then <<
%        if not (!*savedef = '!*savedef)
%          then rerror('rlisp,1,list(old,"has no definition in copyd"))>>
%      else << putd(new,car x,cdr x);
%              if flagp(old, 'lose) then flag(list new, 'lose) >>;
%% The transfer of the saved definition is needed if the REDUCE "patch"
%% mechanism is to work fully properly.
%      if (x := get(old, '!*savedef)) then put(new, '!*savedef, x);
%      return new
%   end;
%
%flag('(copyd), 'lose);

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

%symbolic macro procedure csl u;
%   cadr u;

%symbolic macro procedure psl u;
%   nil;

symbolic macro procedure printf u;
  list('printf1, cadr u, 'list . cddr u);

symbolic procedure printf1(fmt, args);
% this is the inner works of print formatting.
% the special sequences that can occur in format strings are
%       %b    do that many spaces
%       %c    next arg is a numeric character code. display character
%       %d    print an integer (actually just the same as %w)
% *     %f    do a terpri() unless posn()=0
%       %l    prin2 items from given list, blank separated
% *     %n    do a terpri()
%       %o    print in octal
%       %p    print using prin1
%       %t    do a ttab to move to given column
%       %w    use prin2
%       %x    print in hexadecimal
% *     %%    print a '%' character (items marked * do not use an arg).
% All except those marked with "*" use an argument.
  begin
    scalar a, c;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if c = '!% then <<
         c := car fmt;
         fmt := cdr fmt;
         if c = '!f then << if not zerop posn() then terpri() >>
         else if c = '!n then terpri()
         else if c = '!% then prin2 c
         else <<
            a := car args;
            args := cdr args;
            if c = '!b then spaces a
            else if c = '!c then tyo a
            else if c = '!l then <<
               if not atom a then <<
                  prin2 car a;
                  for each w in cdr a do << prin2 " "; prin2 w >> >> >>
            else if c = '!o then prinoctal a
            else if c = '!p then prin1 a
            else if c = '!t then ttab a
            else if c = '!w or c = '!d or c = '!s then prin2 a
            else if c = '!x then prinhex a
            else rerror('cslrend,1,list(c,"bad format character")) >> >>
      else prin2 c >>
  end;

% The format options with bldmsg are intended to match those used
% with printf. If I had make!-string!-output!-stream() available in
% Standard Lisp mode it would let me use one copy of this code and things
% would thus be tidier!

symbolic macro procedure bldmsg u;
  list('bldmsg1, cadr u, 'list . cddr u);

symbolic procedure bldcolumn(s, n);
  if null s or eqcar(s, !$eol!$) then n
  else bldcolumn(cdr s, n+1);

symbolic procedure bldmsg1(fmt, args);
  begin
    scalar a, c, r;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if c = '!% then <<
         c := car fmt;
         fmt := cdr fmt;
         if c = '!f then <<
             if not zerop bldcolumn(r, 0) then r := !$eol!$ . r >>
         else if c = '!n then r := !$eol!$ . r
         else if c = '!% then r := c . r
         else <<
            a := car args;
            args := cdr args;
            if c = '!b then for i := 1:a do r := '!  . r
            else if c = '!c then r := a . r
            else if c = '!l then <<
               if not atom a then <<
                  r := append(reverse explode2 car a, r);
                  for each w in cdr a do <<
                     r := '!  . r;
                     r := append(reverse explode2 w, r) >> >> >>
            else if c = '!o then r := append(reverse explodeoctal a, r)
            else if c = '!p then r := append(reverse explode a, r)
            else if c = '!t then while bldcolumn(r, 0)<a do r := '!  . r
            else if c = '!w or c = '!d or c = '!s
             then r := append(reverse explode2 a, r)
            else if c = '!x then r := append(reverse explodehex a, r)
            else rerror('cslrend,1,list(c,"bad format character")) >> >>
      else r := c . r >>;
    return list2string nreverse r
  end;

put('gc, 'simpfg, '((t (verbos t)) (nil (verbos nil))));
flag('(gc), 'switch);

endmodule;

end;
