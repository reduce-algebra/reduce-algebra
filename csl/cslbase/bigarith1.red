on echo;
lisp spool "bigarith1.log";
lisp enable!-errorset(3,3);

% bigarith.red                           Copyright (C) A C Norman 2022-2024

% Big-number arithmetic code for use testing the native arithmetic package.

% $Id$

% Load this file with the variable nocheck set and it just defines functions
% without runnning the test. If you do run the test then setting
% seed to a string that looks like an integer uses that as a random seed
% to influence the exact test sequence.


% Please note that that this is GROTTY code not intended for general re-use.
% It is JUST to provide a regression test on CSL arithmetic. It calls upon a
% number of CSL specials (eg validate!-number, which checks if the internal
% format of a number is proper - specifically if checks that there are no
% bignums with unwanted leading zero digits and no bignums where the value
% could have been represented as a fixnum). Well I am trying to make it
% do something with PSL too, but the detailed low level testing of number
% formats is not fully refined yet.


% The code tests a lot of arithmetic cases that I expect to be close to
% critical values (eg near powers of two) and also a load of random
% values - these random values should be different each time the test is
% run.

% **************************************************************************
% * Copyright (C) 2024, Codemist.                         A C Norman       *
% *                                                                        *
% * Redistribution and use in source and binary forms, with or without     *
% * modification, are permitted provided that the following conditions are *
% * met:                                                                   *
% *                                                                        *
% *     * Redistributions of source code must retain the relevant          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer.                                                      *
% *     * Redistributions in binary form must reproduce the above          *
% *       copyright notice, this list of conditions and the following      *
% *       disclaimer in the documentation and/or other materials provided  *
% *       with the distribution.                                           *
% *                                                                        *
% * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
% * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
% * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
% * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
% * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
% * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
% * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
% * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
% * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
% * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
% * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
% * DAMAGE.                                                                *
% *************************************************************************/


lisp;
on comp;

#if !*psl

% validate!-number is intended to check that the internal representation
% of a number is as it should be. For CSL that involves two main things.
% first if the value is in the range where it ought to be a fixnum
% rather than a bignum it must be represented that way and not as a
% degenerate case of a bignum. Then if it is a bignum it must be stored
% with the correct number of digits and (for instance) no spurious
% leading zeros.

% The PSL sketch here is not intended as just a place-holder or a start!

% If one believes that "lessp" is working properly and if one knows the
% number of bits being used then sys2int etc can police the fixnum
% vs bignum issue, where I will try a sketch here. Noting bignums
% with unwanted leading zeros needs more expertise than I have!

fluid '(largest!-fixnum smallest!-fixnum);

largest!-fixnum := 2^56-1;
smallest!-fixnum := -2^56;

symbolic procedure is!-fixnum a;
    a eq sys2int a;

% representation(a, t) in CSL displays the internal representation
% of the value a. In particular for integers it shows whether there
% is a bignum or a fixnum, and for bignums it displays all the
% digits. This is useful in the context of code that checks things
% at the level that the stuff here does!

symbolic procedure representation(a, flg);
   begin
      scalar r;
      r := sys2int a;
      prin2 a;
      prin2 ": ";
      print a;
      return r;
   end;

symbolic procedure moan(a, m1, m2);
   begin
      terpri();
      prin2 "@@@@@ ";
      prin2 a;
      prin2 " ";
      prin2 m1;
      prin2 " : ";
      prin2 m2;
      terpri();
      representation(a, t);
      rederr "bad number"
   end;

% validate!-number checks an integer wrt the fixnum/bignum divide and
% ideally it checks if the bignum has the correct number of (big) digits.

symbolic procedure validate!-number(a, msg);
   begin
% I am commenting out my code sketch for now...
%     if a >= smallest!-fixnum and
%        a <= largest!-fixnum then <<
%        if is!-fixnum a then return a
%        else moan(a, msg, "should be a fixnum") >>
%     else if is!-fixnum a then moan(a, msg, "should be a bignum"); 
      return a
   end;

% When I try it I seem to find exitwithstatus (from the PSL manual)
% unavailable. Well I am not really fussed about return codes anyway.

symbolic procedure stop n;
   exitlisp();

symbolic procedure logxor(a, b);
   lxor(a, b);   % CSL and PSL use different names!

symbolic procedure last l;
  if null l then nil
  else if null cdr l then car l
  else last cdr l;

symbolic procedure prinhex n;
   if n = 0 then nil
   else if n = -1 then prin2 "~f"
   else begin
      scalar q, r;
      q := n / 16;
      r := n - 16*q;
      if r < 0 then << q := q - 1; r := r + 16 >>;
      prinhex q;
      print nth('(!0 !1 !2 !3 !4 !5 !6 !7
                  !8 !9 !a !b !c !d !e !f), r+1)
   end;


#endif

% In PSL at least some of the basic arithmetic functions are macros not
% functions, and that would mean that use of them via APPLY is jolly
% delicate, so I provide simple function versions here.

symbolic procedure plusfn(a, b); a+b;
symbolic procedure differencefn(a, b); a-b;
symbolic procedure timesfn(a, b); a*b;
symbolic procedure logandfn(a, b); land(a,b);
symbolic procedure logorfn(a, b); lor(a,b);
symbolic procedure logxorfn(a, b); lxor(a,b);
symbolic procedure logeqvfn(a, b); lnot lxor(a,b);


global '(magic);
magic := 777167;   % Well not very magic! But a prime.

% I am going to believe that arithmetic involving magic*x will be different
% enough from that on just x that any errors will differ. The two cases
% "ought not" to hit special cases at the same time. So that can be a basis
% for validation. It is OK if it is the arithmetic scaled by magic that
% fails provided that it fails in a way inconsistent with the direct version!

symbolic procedure myminus a;
   magic - (a + magic);

symbolic procedure myplus(a,b);
    (magic*a + magic*b)/magic;

symbolic procedure mydifference(a,b);
    (magic*a - magic*b)/magic;

symbolic procedure mytimes(a,b);
    (a-magic)*(b+magic) - a*magic + b*magic + magic*magic;

symbolic procedure myquotient(a,b);
    (a*magic)/(b*magic);

symbolic procedure mymod(a,b);
    mod(a*magic, b*magic)/magic;

symbolic procedure myremainder(a,b);
    remainder(a*magic, b*magic)/magic;

symbolic procedure mylogand(a,b);
   lshift(logand(lshift(a, 23), lshift(b, 23)), -23);

symbolic procedure mylogor(a,b);
   lshift(logor(lshift(a, 23), lshift(b, 23)), -23);

symbolic procedure mylogxor(a,b);
   lshift(logxor(lshift(a, 23), lshift(b, 23)), -23);

symbolic procedure mylogeqv(a,b);
   lshift(logeqv(lshift(a, 23), lshift(b, 23)), -23);

symbolic procedure mygreaterp(a,b);
    a*magic > b*magic;

symbolic procedure mylshift(a, n);
   if n = 0 then a
   else if n = 1 then 2*a
   else if n = -1 then
      if a>=0 then a/2
      else (a-1)/2
   else mylshift(mylshift(a, n/2), n-n/2);

% tr mylshift;

symbolic procedure check!-one!-arg(native,mine,a); 
   begin scalar r1,r2; 
      validate!-number(a,list("one arg",native,mine)); 
      r1 := validate!-number(apply1(native,a),
                             list("one arg result",native,mine,a)); 
      r2 := apply1(mine, a); 
      if r1=r2 then return nil; 
      terpri(); 
      princ "+++ Failure with "; 
      print native; 
      princ "(setq a "; 
      prin a; 
      printc ")"; 
      princ "computed: "; 
      prin r1; 
      princ " "; 
      prinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      prinhex r2; 
      terpri();  
      representation(a,t); 
      representation(apply1(native,a),t); 
      terpri(); 
      printc "+++ Stopping"; 
      stop 1
   end;

symbolic procedure check!-minus a;
   check!-one!-arg('minus,'myminus,a);

symbolic procedure check!-one!-plus!-int!-arg(native,mine,a,n); 
   begin scalar r1,r2; 
      validate!-number(a,list("one+n arg",native,mine)); 
      validate!-number(n,list("one+n arg",native,mine)); 
      r1 := validate!-number(apply2(native,a,n),
                             list("one+n arg result",native,mine,a,n)); 
      r2 := apply2(mine,a,n); 
      if r1=r2 then return nil; 
      terpri(); 
      princ "+++ Failure with "; 
      print native; 
      princ "(setq a "; 
      prin a; 
      printc ")"; 
      princ "(setq n "; 
      prin n; 
      printc ")"; 
      princ "computed: "; 
      prin r1; 
      princ " "; 
      prinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      prinhex r2; 
      terpri(); 
      representation(a,t); 
      representation(n,t); 
      representation(apply2(native,a,n),t); 
      stop 1
   end;

symbolic procedure check!-lshift(a,n); 
   check!-one!-plus!-int!-arg('lshift,'mylshift,a,n);

symbolic procedure check!-two!-args(native,mine,a,b); 
   begin scalar r1,r2; 
      validate!-number(a,list("two args",native,mine,a,b)); 
      validate!-number(b,list("two args",native,mine,a,b)); 
      r1 := validate!-number(apply2(native,a,b),
                             list("two args result",native,mine,a,b)); 
      r2 := apply2(mine,a, b); 
      if r1=r2 then return nil; 
      terpri(); 
      princ "+++ Failure with "; 
      print native; 
      princ "(setq a "; 
      prin a; 
      printc ")"; 
      princ "(setq b "; 
      prin b; 
      printc ")"; 
      princ "computed: "; 
      prin r1; 
      princ " "; 
      prinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      prinhex r2; 
      terpri(); 
      prin2 "a="; representation(a,t); 
      prin2 "b="; representation(b,t); 
      prin2 "native="; representation(r1,t); 
      prin2 "checking="; representation(r2,t); 
      terpri(); 
      printc "+++ Stopping"; 
      stop 1
   end;

symbolic procedure check!-two!-args!-bool(native,mine,a,b); 
   begin scalar r1,r2; 
      validate!-number(a,list("two args",native,mine,a,b)); 
      validate!-number(b,list("two args",native,mine,a,b)); 
      r1 := apply2(native,a,b);
      r2 := apply2(mine,a,b); 
      if r1=r2 then return nil; 
      terpri(); 
      princ "+++ Failure with "; 
      print native; 
      princ "(setq a "; 
      prin a; 
      printc ")"; 
      princ "(setq b "; 
      prin b; 
      printc ")"; 
      princ "computed: "; 
      prin r1; 
      princ " "; 
      prinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      prinhex r2; 
      terpri(); 
      representation(a,t); 
      representation(b,t); 
      representation(apply2(native,a,b),t); 
      terpri(); 
      printc "+++ Stopping"; 
      stop 1
   end;

symbolic procedure check!-plus(a,b);
   check!-two!-args('plusfn,'myplus,a,b);

symbolic procedure check!-difference(a,b); 
   check!-two!-args('differencefn,'mydifference,a,b);

symbolic procedure check!-times(a,b);
   check!-two!-args('timesfn,'mytimes,a,b);

symbolic procedure check!-quotient(a,b); 
   check!-two!-args('quotient,'myquotient,a,b);

symbolic procedure check!-mod(a,b);
   check!-two!-args('mod,'mymod,a,b);

symbolic procedure check!-remainder(a,b); 
   check!-two!-args('remainder,'myremainder,a,b);

symbolic procedure check!-logand(a,b);
   check!-two!-args('logandfn,'mylogand,a,b);

symbolic procedure check!-logor(a,b);
   check!-two!-args('logorfn,'mylogor,a,b);

symbolic procedure check!-logxor(a,b);
   check!-two!-args('logxorfn,'mylogxor,a,b);

symbolic procedure check!-logeqv(a,b);
   check!-two!-args('logeqvfn,'mylogeqv,a,b);

symbolic procedure check!-greaterp(a,b); 
   check!-two!-args!-bool('greaterp,'mygreaterp,a,b);

% My expectation is that boundary cases will be most frequent with
% operands near a power of 2, and so I will arrange to check all
% cases that are 2^k-1, 2^k, 2^k+1 or the negative of one of those.
% I will also check these values when combined with 0.

fluid '(onlydivide);

onlydivide := nil;

symbolic procedure checkall(a,b,mode);
   begin
      if mode eq 'quotient and not zerop b then <<
         check!-quotient(a,b);
         check!-mod(a,b);
         check!-remainder(a,b) >>
       else if mode eq 'plus then <<
          check!-plus(a,b);
          check!-difference(a,b);
          check!-greaterp(a,b) >>
       else <<
          check!-times(a,b);
          check!-logand(a,b);
          check!-logor(a,b);
          check!-logxor(a,b);
          check!-logeqv(a,b) >>
   end;

symbolic procedure checksigns(a,b,mode);
   begin
      checkall(a,b,mode);
      checkall(validate!-number(-a,"minus"),b,mode);
      checkall(a,validate!-number(-b,"minus"),mode);
      checkall(-a,-b,mode)
   end;

symbolic procedure checknear(a,b,mode);
   <<checksigns(a,b,mode); 
     checksigns(validate!-number(a + 1,"add1"),b,mode); 
     checksigns(validate!-number(a + -1,"sub1"),b,mode); 
     checksigns(a,validate!-number(b + 1,"add1"),mode); 
     checksigns(a,validate!-number(b + -1,"sub1"),mode); 
     checksigns(a + 1,b + 1,mode); 
     checksigns(a + 1,b + -1,mode); 
     checksigns(a + -1,b + 1,mode); 
     checksigns(a + -1,b + -1,mode); 
     if not zerop a and not zerop b and not onep b and not onep ( - b)
       then <<checksigns(a,
                         validate!-number(add1 random b,"random"),
                         mode); 
              checksigns(a + 1,
                         validate!-number(add1 random b,"random"),
                         mode); 
              checksigns(a + -1,
                         validate!-number(add1 random b,"random"),
                         mode); 
              checksigns(validate!-number(random a,"random"),b,mode); 
              checksigns(validate!-number(random a,"random"),
                         b + 1,mode); 
              checksigns(validate!-number(random a,"random"),
                         b + -1,mode); 
              checksigns(validate!-number(random a,"random"),
                         validate!-number(add1 random b,"random"),
                         mode); 
              checksigns(validate!-number(random a,"random"),
                         validate!-number(add1 random b,"random"),
                         mode); 
              checksigns(validate!-number(random a,"random"),
                         validate!-number(add1 random b,"random"),
                         mode)>>>>;

symbolic procedure checkall1 a;
   <<check!-minus a;
     for i := 0:163 do check!-lshift(a,i - 70);
     nil>>;

symbolic procedure checksigns1 a;
   begin
     scalar nega;
     checkall1 a;
     nega := - a;
     validate!-number(nega, "minus");
     checkall1 nega
   end;

symbolic procedure checknear1 a;
   <<checksigns1 a; 
     checksigns1 validate!-number(a + 1,"add1"); 
     checksigns1 validate!-number(a + -1,"sub1")>>;

% If the variable !*nocheck is set when this file is read in it
% will define all the functions but not actually run any tests!

% This will check near 2^0 to some bigger power of 2.

% While testing it is sometimes useful to be able to resume testing some
% way through, so one can set the variable "startat" so that small cases
% get skipped. E.g. the commented out setting to 59 causes the testing to
% begin where the first argument to functions is about to be a bignum not
% a fixnum on 64-bit platforms.

fluid '(mode startat limit a b);

symbolic procedure checksome limit;
  for i := 0:limit do
    if i >= startat then <<
      a := 2**i;
      validate!-number(a, list("power of 2", i));
      princ i; ttab 5; princ "check near "; print a;
      checknear(a, 0, mode);
      checknear(0, a, mode);
      for j := 0:limit do <<
         b := 2**j;
         validate!-number(b, list("power of 2", j));
         checknear(a, b, mode) >> >>;


symbolic procedure checksome1();
  for i := 0:100 do <<
    a := 2**i;
    princ i; ttab 5; princ "check 1 arg and shifts near "; print a;
    validate!-number(a, list("power of 2", i));
    checknear1 a >>;

fluid '(tests endat cc vv);
tests := '(plus times quotient);

if not boundp 'nocheck or not nocheck then <<
  if boundp 'seed then random_new_seed compress explodec seed;
  startat := -1;
  if boundp 'start then startat := compress explodec eval 'start;
  endat := 163;
  if boundp 'end then endat := compress explodec eval 'end;
  cc := 0;
  if boundp 'cons then cc := compress explodec eval 'cons;
  vv := 0;
  if boundp 'vec then vv := compress explodec eval 'vec;
  if not zerop cc or not zerop vv then verbos t;
  gc!-forcer(cc, vv);
  checknear1 0;
  if boundp 'test then tests := list compress explodec test;
  for each mode in tests do <<
    terpri();
    princ "Start testing in mode "; printc mode;
    if mode = 'quotient and not boundp 'test then limit := 2*endat
    else limit := endat;
    gc!-forcer(cc, vv);
    checksome limit >>;
  gc!-forcer(cc, vv);
  if not boundp 'test then checksome1();
  if not zerop cc or not zerop vv then gc!-forcer nil;
  nil;
 >>;

% End of bigarith.red
