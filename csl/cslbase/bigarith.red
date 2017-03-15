% bigarith.red                                Copyright (C) A C Norman 2017

% Big-number arithmetic done digit by digit for use testing the
% native arithmetic package.

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
% * Copyright (C) 2017, Codemist.                         A C Norman       *
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
on echo, comp;

if !*csl then <<
   enable!-errorset(3, 3);   % Always generate backtraces even if
                             % errorset tries to prevent that.
   verbos nil;               % no garbage collection messages.
   make!-random!-state 0 >>; % Different sequence on each run!

#if !*psl

% validate!-number is intended to check that the internal representation
% of a number is as it should be. For CSL that involves two main things.
% first if the value is in the range where it ought to be a fixnum
% rather than a bignum it must be represented that way and not as a
% degenerate case of a bignum. Then if it is a bignum it must be stored
% with the correct number of digits and (for instance) no spurious
% leading zeros.

% If one believes that "lessp" is working properly and if one knows the
% number of bits being used then sys2int etc can police the fixnum
% ve bignum issue, where I will try a sketch here. Noting bignums
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
   lxor(a, b);

symbolic procedure random!-number n;
   random n;

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



% Numbers are stored radix 10 with the least significant digit first
% in a list. They use sign and mangnitude representation with the symbol
% '!- on the front of a list that denotes a nagative number. Really
% crude!

symbolic procedure mynum n;
   <<validate!-number(n,"mynum"); 
     if zerop n then nil
      else if n<0 then '!- . mynum validate!-number( - n,"negated")
      else if n<10 then {n}
      else append(mynum validate!-number(n/10,{"quotient",n,10}),
                  {validate!-number(remainder(n,10),"remainder")})>>;

symbolic procedure mynum1 n; 
   if numberp n then mynum n
    else if not atom n then mynum1 car n . mynum1 cdr n
    else n;

symbolic procedure myzerop a;
   a=nil;

symbolic procedure myonep a;
   a='(1);

symbolic procedure myminusp a;
   eqcar(a,'!-);

symbolic procedure myabs a;
   if eqcar(a,'!-) then cdr a else a;

symbolic procedure myplusp a;
   not null a and not eqcar(a,'!-);

symbolic procedure myminus a; 
   if eqcar(a,'!-) then cdr a else if null a then nil else '!- . a;

symbolic procedure mygreaterp(a,b); 
   if eqcar(a,'!-) then if eqcar(b,'!-) then mygreaterp(cdr b,cdr a) else nil
    else if eqcar(b,'!-) then t
    else if a=b then nil
    else if length a>length b then t
    else if length a<length b then nil
    else if null a then nil
    else if car a=car b then mygreaterp(cdr a,cdr b)
    else car a>car b;

symbolic procedure mylessp(a,b);
   mygreaterp(b,a);

symbolic procedure mygeq(a,b);
   not mygreaterp(b,a);

symbolic procedure myleq(a,b);
   not mygreaterp(a,b);

symbolic procedure myplus(a,b); 
   if eqcar(a,'!-) then mydifference(b,cdr a)
    else if eqcar(b,'!-) then mydifference(a,cdr b)
    else if null a then b
    else if null b then a
    else myadd(reverse a,reverse b,0);

symbolic procedure mydifference(a,b); 
   if eqcar(a,'!-) then myminus myplus(b,cdr a)
    else if eqcar(b,'!-) then myplus(a,cdr b)
    else if null a then myminus b
    else if null b then a
    else if mygreaterp(a,b) then mysubtract(reverse a,reverse b,0)
    else myminus mysubtract(reverse b,reverse a,0);

symbolic procedure myadd1 a;
   myplus(a,'(1));

symbolic procedure mysub1 a;
   mydifference(a,'(1));

% myadd and mysubtract handle just positive values and each has an extra
% argument that is a carry or borrow.

symbolic procedure myadd(a,b,c); 
   begin scalar d,r; 
    top: 
      if null a and null b and zerop c then return r; 
      if null a then d := c else <<d := car a + c; a:= cdr a>>; 
      if b then <<d := d + car b; b := cdr b>>; 
      if d>9 then <<d := d - 10; c := 1>> else c := 0; 
      r := d . r; 
      go to top
   end;

% for mysubtract I should have ensured that a >= b.

symbolic procedure mysubtract(a,b,c); 
   begin scalar d,r; 
    top: 
      if null a and zerop c then go to done; 
      if null a then d := c else <<d := car a + c; a := cdr a>>;
      if b then <<d := d - car b; b := cdr b>>; 
      if d<0 then <<d := d + 10; c := -1>> else c := 0; 
      r := d . r; 
      go to top; 
    done: 
      if null r or not zerop car r then return r; 
      r := cdr r; 
      go to done
   end;

symbolic procedure myhalve a; 
   if eqcar(a,'!-) then myminus myhalve myminus a
    else <<a := myhalve1 a;
           if eqcar(a, 0) then cdr a else a>>;

symbolic procedure myhalve1 a; 
   if null a then nil
    else if null cdr a then list(car a/2)
    else if evenp car a then (car a/2) . myhalve1 cdr a
    else (car a/2) . myhalve1 ((10 + cadr a) . cddr a);

% Some demo cases just to check...

myhalve '(1 0 0);
myhalve '(5 0);
myhalve '(2 5);

symbolic procedure mydouble a;
   myplus(a,a);

symbolic procedure myoddp a;
   a and oddp last a;

symbolic procedure myevenp a;
   null a or evenp last a;

symbolic procedure mytimes(a,b); 
   if eqcar(a,'!-) then myminus mytimes(cdr a,b)
    else if eqcar(b,'!-) then myminus mytimes(a,cdr b)
    else if null a then nil
    else if a='(1) then b
    else if myevenp a then mydouble mytimes(myhalve a,b)
    else myplus(mydouble mytimes(myhalve a,b),b);

symbolic procedure myexpt(a,n); 
   if zerop n then '(1)
    else if onep n then a
    else if evenp n then <<n := myexpt(a,n/2); mytimes(n,n)>>
    else <<n := myexpt(a,n/2); mytimes(a,mytimes(n,n))>>;

symbolic procedure mydivide(a,b); 
   begin scalar a1,a2,q1,r1,q,r,w,w1; 
      a1 := myvalof a; 
      a2 := myvalof b; 
      a2 := myvalof b; 
      a1 := myvalof a; 
      a1 := myvalof a; 
      a2 := myvalof b; 
      w := divide(a1,a2); 
      q := mynum car w; 
      r := mynum cdr w; 
      w1 := myplus(mytimes(q,b),r); 
      if not (w1=a)
        then <<princ "Divide  "; 
               print a; 
               princ "by "; 
               print b; 
               princ "giving "; 
               print w; 
               princ "q*b+r = "; 
               print w1; 
               error(1,"Problem with division")>>; 
      if not null r
        then if myminusp a and not myminusp r or not myminusp a and myminusp r
               then error(1,"Problem with sign of remainder"); 
      if mygreaterp(myabs b,myabs r) then nil
       else error(1,"Problem with magnitude of remainder"); 
      return q . r
   end;

symbolic procedure myquotient(a,b);
   car mydivide(a,b);

symbolic procedure myremainder(a,b);
   cdr mydivide(a,b);

% For mymod the sign of the result will match the sign of b.

symbolic procedure mymod(a,b); 
   begin scalar c; 
      c := myremainder(a,b); 
      if myminusp b and myplusp c then return myplus(b,c)
       else if myplusp b and myminusp c then return myplus(b,c)
       else return c
   end;

symbolic procedure mylshift(a,n); 
   if zerop n then a
    else if n>0 then mytimes(a,mynum (2**n))
    else if not eqcar(a,'!-) then myquotient(a,mynum (2** - n))
    else mydifference(myquotient(myplus(a,'(1)),mynum (2** - n)),'(1));

% For boolean operations there is some fun because I am storing things
% in decimal and with a variable number of digits. I need to (in effect)
% convert to binary and treat negative values as if they had an inifinite
% number of leading "1" bits . I cope with this by using DeMorgan so that
% I either end up performing an OR on a pair of positive numbers or an AND
% where at least one of the numbers is positive (and hence it provides
% a limit on the number of bits I will generate in the result).

symbolic procedure mylognot n;
   myplus(myminus n,'(!- 1));

symbolic procedure mylogand!-bin(a,b); 
   if null a or null b then nil
    else if a='(!- 1) and b='(!- 1) then a
    else if myevenp a
     then if myevenp b then append(mylogand!-bin(myhalve a,myhalve b),'(0))
           else append(mylogand!-bin(myhalve a,myhalve mysub1 b),'(0))
    else if myevenp b
           then append(mylogand!-bin(myhalve mysub1 a,myhalve b),'(0))
          else append(mylogand!-bin(myhalve mysub1 a,myhalve mysub1 b),'(1));

symbolic procedure flipbits a; 
   if null a then nil
    else if eqcar(a,0) then 1 . flipbits cdr a
    else 0 . flipbits cdr a;

symbolic procedure mybinnum a; 
   if eqcar(a,'!-) then mylognot mybinnum flipbits cdr a
    else if null a then nil
    else if zerop car a then mybinnum cdr a
    else begin scalar r; 
          top: 
            if null a then return r; 
            r := mydouble r; 
            if not zerop car a then r := myadd1 r; 
            a := cdr a; 
            go to top
         end;

symbolic procedure mylogand(a,b);
   mybinnum mylogand!-bin(a,b);

symbolic procedure mylogor!-bin(a,b); 
   if a='(!- 1) or b='(!- 1) then '(!- 1)
    else if null a and null b then nil
    else if myevenp a
     then if myevenp b then append(mylogor!-bin(myhalve a,myhalve b),'(0))
           else append(mylogor!-bin(myhalve a,myhalve mysub1 b),'(1))
    else if myevenp b then append(mylogor!-bin(myhalve mysub1 a,myhalve b),'(1))
          else append(mylogor!-bin(myhalve mysub1 a,myhalve mysub1 b),'(1));

symbolic procedure mylogor(a,b);
   mybinnum mylogor!-bin(a,b);

symbolic procedure mylogxor!-bin(a,b); 
   if a='(!- 1) and b='(!- 1) then nil
    else if null a and null b then nil
    else if a='(!- 1) and null b then '(!- 1)
    else if null a and b='(!- 1) then '(!- 1)
    else if myevenp a
     then if myevenp b then append(mylogxor!-bin(myhalve a,myhalve b),'(0))
           else append(mylogxor!-bin(myhalve a,myhalve mysub1 b),'(1))
    else if myevenp b
           then append(mylogxor!-bin(myhalve mysub1 a,myhalve b),'(1))
          else append(mylogxor!-bin(myhalve mysub1 a,myhalve mysub1 b),'(0));

symbolic procedure mylogxor(a,b);
   mybinnum mylogxor!-bin(a,b);

symbolic procedure mylogeqv(a,b);
   mylognot mylogxor(a,b);

symbolic procedure myprinhex n;
   if null n then princ "0"
    else if eqcar(n,'!-)
     then <<princ "~f"; myprinneg myplus(myminus n,'(!- 1))>>
    else myprinpos n;

symbolic procedure myvalof n; 
   begin scalar r; 
      if eqcar(n,'!-) then return  - myvalof cdr n; 
      r := 0; 
    top: 
      if null n then return r; 
      r := r*10 + car n; 
      n := cdr n; 
      go to top
   end;

symbolic procedure myprinpos n; 
   if mylessp(n,'(1 6)) then prinhex myvalof n
    else <<myprinpos myquotient(n,'(1 6));
           prinhex myvalof myremainder(n,'(1 6))>>;

symbolic procedure myprinneg n; 
   if mylessp(n,'(1 6)) then prinhex logxor(15,myvalof n)
    else <<myprinneg mylshift(n,-4);
           prinhex logxor(15,myvalof mymod(n,'(1 6)))>>;

% The function that is being checked is called using "apply" which
% calls it as from the interpreter. That means that if the compiler
% generates in-line code that will need checking independently and if the
% bytecode interpreter has its own special version of anything that too
% will need special treatment...

symbolic procedure check!-one!-arg(native,mine,a); 
   begin scalar r1,r2; 
      validate!-number(a,list("one arg",native,mine)); 
      r1 := 
       mynum1 validate!-number(apply1(native,a),
                               list("one arg result",native,mine,a)); 
      r2 := apply1(mine,mynum a); 
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
      myprinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      myprinhex r2; 
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
      r1 := 
       mynum1 validate!-number(apply2(native,a,n),
                               list("one+n arg result",native,mine,a,n)); 
      r2 := apply2(mine,mynum a,n); 
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
      myprinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      myprinhex r2; 
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
      r1 := 
       mynum1 validate!-number(apply2(native,a,b),
                               list("two args result",native,mine,a,b)); 
      r2 := apply2(mine,mynum a,mynum b); 
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
      myprinhex r1; 
      terpri(); 
      princ "reference:"; 
      prin r2; 
      princ " "; 
      myprinhex r2; 
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
   check!-two!-args('greaterp,'mygreaterp,a,b);

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
                         validate!-number(add1 random!-number b,"random"),
                         mode); 
              checksigns(a + 1,
                         validate!-number(add1 random!-number b,"random"),
                         mode); 
              checksigns(a + -1,
                         validate!-number(add1 random!-number b,"random"),
                         mode); 
              checksigns(validate!-number(random!-number a,"random"),b,mode); 
              checksigns(validate!-number(random!-number a,"random"),
                         b + 1,mode); 
              checksigns(validate!-number(random!-number a,"random"),
                         b + -1,mode); 
              checksigns(validate!-number(random!-number a,"random"),
                         validate!-number(add1 random!-number b,"random"),
                         mode); 
              checksigns(validate!-number(random!-number a,"random"),
                         validate!-number(add1 random!-number b,"random"),
                         mode); 
              checksigns(validate!-number(random!-number a,"random"),
                         validate!-number(add1 random!-number b,"random"),
                         mode)>>>>;

symbolic procedure checkall1 a;
   <<check!-minus a; for i := 0:140 do check!-lshift(a,i - 70); nil>>;

symbolic procedure checksigns1 a;
   <<checkall1 a; checkall1 validate!-number( - a,"minus")>>;

symbolic procedure checknear1 a;
   <<checksigns1 a; 
     checksigns1 validate!-number(a + 1,"add1"); 
     checksigns1 validate!-number(a + -1,"sub1")>>;

% This will check near 2^0 to 2^100.

% While testing it is sometimes useful to be able to resume testing some
% way through, so one can set the variable "startat" so that small cases
% get skipped. E.g. the commented out setting to 59 causes the testing to
% begin where the first argument to functions is about to be a bignum not
% a fixnum on 64-bit platforms.

fluid '(startat);
startat := -1;
% startat := 58;

fluid '(mode limit a b);

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

% tr validate!-number, mynum1, check!-plus, check!-two!-args, myplus;

for each mode in '(plus times quotient) do <<
     terpri();
     princ "Start testing in mode "; printc mode;
     if mode = 'quotient then limit := 200
     else limit := 100;
     if atom errorset(list('checksome, limit), t, t) then <<
       terpri();
       printc "+++ Stopping";
       stop(1) >> >>;

checknear1 0;

symbolic procedure checksome1();
  for i := 0:100 do <<
    a := 2**i;
    princ i; ttab 5; princ "check 1 arg and shifts near "; print a;
    validate!-number(a, list("power of 2", i));
    checknear1 a >>;

if atom errorset('(checksome1), t, t) then <<
  terpri();
  printc "+++ Stopping";
  stop 1 >>;

% End of bigarith.red
