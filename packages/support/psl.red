module psl;

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


imports big2sys, bigp, floatloworder, floathighorder, gtneg, gtpos,
        i2bf!:, idifference, igetv, ilessp, iminus, inf, iplus, isub1,
        itimes, land, lshift, make!:ibf, neq, sys2int, trimbignum,
        vecinf, veclen, wand, wdifference, wminus, wor, wplus2, wputv,
        wquotient, wshift;

exports ashift, msd!:, fl2bf, integerp!:, normbf, oddintp, preci!:;

fluid '(bbits!*);

global '(bfz!* bitsperword dirchar!* tempdir!*);

!#if (intersection '(dos os2 winnt alphant win32 win64 cygwin) lispsystem!*)
   dirchar!* := "\";
   tempdir!* := getenv "TMP" or getenv "TEMP";
!#else
   dirchar!* := "/";
   tempdir!* := "/tmp";
!#endif


compiletime
  global '(!!fleps1exp !!plumaxexp !!pluminexp !!timmaxexp !!timminexp);

remflag ('(ashift msd!: fl2bf ff0 ff1
           bf!-bits bf!-bits!-mask integerp!: normbf oddintp preci!:),
         'lose);

flag('(cond),'eval);   % Enable conditional compilation.

%-------------------------------------------------------------------

% % The following routines support fast float operations by exploiting
% % the IEEE number format explicitly.
%
% compiletime
%  if 'ieee member lispsystem!* then
%    remflag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose)
%      else
%    flag('(safe!-fp!-plus safe!-fp!-times safe!-fp!-quot),'lose);

% Currently 32 and 64 bit IEEE machines are supported.
%
% The following macros assume that on 64 bit machines floathighorder
% and floatloworder both load the full 64 bit floating point number.

% The version here has been adjusted by ACN who was simultaneously
% working on the corresponding code within CSL - the aim is that the
% two Lisp systems behave identically. And the adjusted code here
% will be able to use machine floating point arithmetic in a number of cases
% that the previous version of the code could not.

compiletime
<<
  define!-constant(ieeeshift,12 - bitsperword);  % 32 bits:-20
  define!-constant(signshift,1 - bitsperword);   % 32 bits:-31
  define!-constant(ieeebias,1023);
  define!-constant(ieeemask,2047);
  define!-constant(ieeemaxexp,1024);
  define!-constant(ieeeminexp,-1023);
  ds(floathiword,x(),floathighorder inf x);
  ds(floatloword,x(),floatloworder inf x);

  if bitsperword=32 then
  <<
% ACN worries about "-0.0" here ...
    ds(ieeezerop,u(), weq(0,floathiword u) and weq(0,floatloword u));
% Again is "+0.0" equal to "-0.0" and is "NaN" equal to "NaN"? Doing
% a bit-pattern comparison could be held to be dangerous, but provided
% the user is aware of these issues I do not mind.
    ds(ieeeequal,u2(v),
           weq(floathiword u2,floathiword v)
       and weq(floatloword u2,floatloword v));
% In the newer code in this file and the implemention of safe!-fp!-XX
% the mantissa is never needed. But perhaps somewhere else it will be
% useful.
    ds(ieeemant,f(),
       (lor(lshift(
               wor(wshift(wand (floathiword f, 1048575), % 16#FFFFF
                          6),
                   wshift(lf,-26)),
               26),
               wand(lshift(-1,-6), lf))
         where lf := floatloword f));
   >>
   else if bitsperword=64 then
   <<
% Again the issues of "-0.0" and "NaN" arise...
    ds(ieeezerop,u(), weq(0,floathiword u));
    ds(ieeeequal,u2(v), weq(floathiword u2,floathiword v));
    ds(ieeemant,f(), wand (floathiword f,
                           4503599627370495)); % 16#FFFFFFFFFFFFF
   >>
   else error(99,"#### unknown bit size");

  ds(ieeeexpt,u(),
      wdifference(wand(ieeemask,
                       wshift(floathiword u,ieeeshift)),
                 ieeebias));
  ds(ieeesign,u(),wshift(floathiword u,signshift));
     % ieeemant is the mantissa part of the upper 32 bit group.

%  define!-constant(!!plumaxexp,1018);
%  define!-constant(!!pluminexp,-979);
%  define!-constant(!!timmaxexp,509);
%  define!-constant(!!timminexp,-510);
%  define!-constant(!!fleps1exp,-40)
>>;

symbolic procedure float!-is!-finite x;
  floatp x and ieeeexpt x < ieeemaxexp;

symbolic procedure float!-is!-nan x;
  floatp x and ieeeexpt x = ieeemaxexp and ieeemant x neq 0;

symbolic procedure float!-is!-infinite x;
  floatp x and ieeeexpt x = ieeemaxexp and ieeemant x = 0;

symbolic procedure float!-is!-subnormal x;
  floatp x and ieeeexpt x = 0;


remflag('(fp!-infinite fp!-nan fp!-finite fp!-subnorm),'lose);

symbolic inline procedure fp!-infinite x;
  float!-is!-infinite x;

symbolic inline procedure fp!-nan x;
  float!-is!-nan x;

symbolic inline procedure fp!-finite x;
  float!-is!-finite x;

symbolic inline procedure fp!-subnorm x;
  float!-is!-subnormal x;

flag('(fp!-infinite fp!-nan fp!-finite fp!-subnorm),'lose);

%---------------------------------------------------------------

deflist('((iminus iminus)),'unary);

symbolic inline procedure ashift (m,d);
  if and(numberp m, m < 0) then -lshift(-m,d) else lshift(m,d);

symbolic inline procedure oddintp x;
   wand(if bigp x then wgetv(inf x,2)
         else if fixnp x then fixval inf x
         else x,1) eq 1;

symbolic macro procedure bf!-bits (x); {'quote, bbits!*};

%symbolic macro procedure bf!-bits!-mask (x);
%   {'quote, lshift(1, bf!-bits()) - 1};

%symbolic procedure ff1 (w,n);
%  if n eq 0 then w else
%  if wshift (w, wminus n) eq 0 then
%        ff1 (w,wquotient(n,2))
%    else iplus2(ff1 (wshift (w, wminus n),wquotient(n,2)),n) ;

symbolic inline procedure ff1 (ww,nn);
  <<while not (n eq 0) do <<
      x := wshift(w,wminus n);
      if not (x eq 0) then % left half
        << w := x; y := iplus2(y,n) >>;   % Iplus2 etc. used for
      n := wquotient (n,2)                % bootstrapping.
    >>;
    iplus2(y,w) >>
    where w=ww,n=nn,x=nil,y=0;

%symbolic procedure ff0 (w,n);
%%   returns the number of 0 bits at the least significant end
%  if n eq 0 then w else
%   begin scalar lo;
%     lo := wand(w,isub1 wshift(1,n));
%  return if lo eq 0
%           then iplus2(n,ff0 (wshift(w,wminus n),wquotient(n,2)))
%          else ff0 (lo,wquotient(n,2)) ;
%  end;

COMMENT ff0 determines the number of 0 bits at the least significant
        end of an integer, ie. the largest power of two by which the
        integer is divisible;

compiletime put('hu_hu_hu,'opencode,'((!*move (reg 1) (reg 1))));

symbolic inline procedure ff0 (ww,nn);
  <<while not (n eq 0) do <<
      lo := wand(w,isub1 wshift(1,n));
      if lo eq 0 then % left half
        << w := wshift(w,wminus n);
           y := iplus2(y,n) >>;           % Iplus2 etc. used for
      n := wquotient (n,2)                % bootstrapping.
    >>;
    if not eq(w,0) then << w := 17; hu_hu_hu (w); y >> else iadd1 y >>
                    % we have to destroy w for gc !!
    where w=ww,n=nn,lo=nil,y=0;

% use wshift(bitsperword,-1) rather than bitsperword/2 as the former
% is open compiled


COMMENT we split msd!: into two parts: one for bignums, one for
        machine words. That will greatly reduce the size of preci!:
        below;

symbolic inline procedure word!-msd!: u;
   ff1(u,wshift(bitsperword,-1));

symbolic inline procedure big!-msd!: u;
   iplus2(itimes2(bf!-bits(),isub1 s),word!-msd!: igetv(u,s))
       where s := veclen vecinf u;

symbolic inline procedure msd!: u;
   if bigp u then big!-msd!: u
    else if fixnp u then word!-msd!: fixval inf u
    else word!-msd!: u;

%symbolic inline procedure msd!: u;
%  % returns the most significant (binary) digit of a positive integer u
%  if bigp u
%    then iplus2(itimes2(bf!-bits(),isub1 s),
%                ff1(igetv(u,s),wshift(bitsperword,-1)))
%       where s := veclen vecinf u
%   else if fixnp u then ff1 (fixval inf u,wshift(bitsperword,-1))
%   else ff1 (u,wshift(bitsperword,-1));

symbolic inline procedure mt!: u; cadr u;
symbolic inline procedure ep!: u; cddr u;

symbolic inline procedure preci!: nmbr;
   % This function counts the precision of a number "n". NMBR is a
   % binary bigfloat representation of "n".
   % msd!: abs mt!: nmbr
   (if bigp m then big!-msd!: m
     else if fixnp m
      then (word!-msd!:(if iminusp n then iminus n else n)
                         where n = fixval inf m)
     else if iminusp m then word!-msd!:(iminus m)
     else word!-msd!: m)
    where m = mt!: nmbr;

%symbolic inline procedure preci!: nmbr;
%   % This function counts the precision of a number "n". NMBR is a
%   % binary bigfloat representation of "n".
%   % msd!: abs mt!: nmbr
%   (if bigp m then msd!: m
%     else if fixnp m
%      then (ff1(if iminusp n then iminus n else n,
%                wshift(bitsperword,-1))
%              where n = fixval inf m)
%     else if iminusp m then ff1(iminus m,wshift(bitsperword,-1))
%     else ff1(m,wshift(bitsperword,-1)))
%    where m = mt!: nmbr;

remflag('(make!:ibf), 'lose);

symbolic inline procedure make!:ibf (mt, ep);
  '!:rd!: . (mt . ep);

flag('(make!:ibf), 'lose);

if not('ieee memq lispsystem!*) then
     flag('(fl2bf),'lose);

% Use "!#if" not "#if" for bootstrapping reasons.
!#if (eq bitsperword 64)

symbolic procedure fl2bf f;
  % u is a floating point number
  % result is a binary bigfloat
  if fixp f then i2bf!: f
   else begin scalar m,e;
      m := ieeemant f;
      e := ieeeexpt f;
      % if exponent <> -1023 add 16#10000000000000, implicit highest bit
      if e neq  -1023 then m := lor (m, lshift(1,52));
      return
        if izerop m then bfz!*
         else normbf make!:ibf (if ieeesign f eq 1 then -m else m,
                                idifference(e,52))
     end;

!#else

symbolic procedure fl2bf f;
  % u is a floating point number
  % result is a binary bigfloat
  if fixp f then i2bf!: f
   else begin scalar m,e;
      m:=
        lor(lshift(
               wor(wshift(wand (floathiword f, 1048575), % 16#FFFFF
                          6),
                   wshift(floatloword f,-26)),
               26),
            wand(lshift(-1,-6), floatloword f));
      %% m := ieeemant f;
      e := ieeeexpt f;
      % if exponent <> -1023 add 16#10000000000000, implicit highest bit
      if e neq  -1023 then m := lor (m, lshift(1,52));
      return
        if izerop m then bfz!*
         else normbf make!:ibf (if ieeesign f eq 1 then -m else m,
                                idifference(e,52))
     end;

!#endif

symbolic procedure normbf x;
   begin scalar mt,s;integer ep,ep1;
      if (mt := mt!: x)=0 then go to ret;
      if mt<0 then <<mt := -mt; s := t>>;
      ep := ep!: x;
%      ep1 := remainder(ep,bf!-bits());
%      if ep1 < 0 then ep1 := ep1 + bf!-bits();
%      if ep1 neq 0 then <<ep := ep - ep1; mt := lshift(mt,ep1)>>;
      while bigp mt and wgetv(inf mt,2) eq 0 do <<
        mt := lshift(mt,-bf!-bits());
        ep := ep+bf!-bits() >>;
      ep1 := ff0(if bigp mt then wgetv(inf mt,2)
                  else if fixnp mt then fixval inf mt
                  else mt,wshift(bitsperword,-1));
      if not (ep1 eq 0) then <<mt := lshift(mt,wminus ep1);
                               ep := ep + ep1>>;
      if s then mt := -mt;
ret:    return make!:ibf(mt,ep) end;

symbolic procedure integerp!: x;
% This function returns T if X is a BINARY BIG-FLOAT
%      representing an integer, else it returns NIL.
% X is any LISP entity.
bfp!: x and
  (ep!: x >= 0 or
    preci!: x > - ep!: x and
      land(abs mt!: x,lshift(2,-ep!: x) - 1) = 0);

flag ('(ashift lshift msd!: fl2bf ff0 ff1
        bf!-bits bf!-bits!-mask integerp!: normbf oddintp preci!:),
      'lose);

if not('ieee memq lispsystem!*) then remflag('(fl2bf),'lose);

% This belong in $pxu/nbig30a.

symbolic(bigfloathi!* :=  (2 ** 53 - 1) * 2 ** 971);

symbolic(bigfloatlow!* := - bigfloathi!*);

remflag('(cond),'eval);

% Put in some CSL compatibility here...

symbolic inline procedure princ x; prin2 x;
symbolic inline procedure prin x;  prin1 x;
symbolic inline procedure printc x; << prin2 x; terpri(); x >>;

symbolic inline procedure list!-to!-vector a; list2vector a;

symbolic procedure hexdig w;
  cdr assoc(w, '((0 . !0) (1 . !1) (2 . !2) (3 . !3)
                 (4 . !4) (5 . !5) (6 . !6) (7 . !7)
                 (8 . !8) (9 . !9) (10 . !a) (11 . !b)
                 (12 . !c) (13 . !d) (14 . !e) (15 . !f)));

symbolic procedure explodehex n;
  begin
% Only for use with integers
    scalar r, s;
    if n = 0 then return "0";
    if n < 0 then << n := -n; s = t >>;
    while not zerop n do <<
       r := hexdig remainder(n, 16) . r;
       n := n / 16 >>;
    if s then r := '!- . r;
    return r
  end;


% A function to expand a filename glob (pattern) via a pipe
%  A couple of tricky issues here:
%    a) set *raise to nil so that upper case characters in strings are not changed to lower case
%    b) unwind-protect so that (global) raise is always restored to its former value
%    c) Unix Bourne shell returns the pattern string if no match, so check for this

symbolic procedure glob!-filenames pat;
  if not stringp pat then rederr " glob!-filenames needs a string parameter"
   else begin scalar cmd,chan,oldchan,filelist,strbuf,chr,raise;
!#if (or (memq 'win32 lispsystem!*) (memq 'win64 lispsystem!*) (memq 'cygwin lispsystem!*))
     cmd := "cmd /C FOR %%H IN (%w) DO @ECHO %%H";
!#else
     cmd := "sh -c 'for h in %w ; do echo $h ;done'";
!#endif
     raise := !*raise; !*raise := nil;
     unwind!-protect(
       <<cmd := bldmsg(cmd,pat);
         chan := pipe!-open(cmd,'input);
         if chan=0 then return rederr "error opening pipe";
         oldchan := rds chan;
         strbuf := nil;
         while (chr := readch()) neq !$eof!$ do <<
           if chr neq !$eol!$
             then strbuf := chr . strbuf    % collect character for filename
            else <<                         % eol - finish filename
	     filelist := (list2string reversip strbuf) . filelist;
             strbuf := nil>>;
         >>;
         close rds oldchan>>,
       !*raise := raise);
!#if (not (or (memq 'win32 lispsystem!*) (memq 'win64 lispsystem!*) (memq 'cygwin lispsystem!*)))
     if null cdr filelist and car filelist = pat then return nil;
!#endif
     return reversip filelist
   end;

symbolic procedure delete!-file!-wildcard pat;
  if not stringp pat then nonstringerror(pat,'delete!-file!-wildcard)
   else for each fi in glob!-filenames pat do delete!-file fi;

% emulate delete!-file via an external command if not defined in PSL

symbolic procedure delete!-file!-slow fi;
!#if (or (memq 'win32 lispsystem!*) (memq 'win64 lispsystem!*) (memq 'cygwin lispsystem!*))
  filep fi and system bldmsg("del ""%s""",fi);
!#else
  system bldmsg("rm -f %s", fi);
!#endif

loadtime if not getd 'delete!-file then copyd('delete!-file,'delete!-file!-slow);

% HP-Risc and IBM RS architectures need special handling of fltinf in
% fastmath.red

if 'hp!-risc member lispsystem!* then
   <<remflag('(fltinf),'lose);
     ds(fltinf,x(),mkitem(vector!-tag,x));
     flag('(fltinf),'lose)>>;

if 'ibmrs member lispsystem!* then
   <<remflag('(fltinf),'lose);
     ds(fltinf,x(),mkstr x);
     flag('(fltinf),'lose)>>;

% find path to gnuplot executable

global '(!*gnuplot_name!*);

!#if (intersection '(dos os2 winnt alphant win32 win64 cygwin) lispsystem!*)
    !*gnuplot_name!* := "gnuplot.exe";
!#else
    !*gnuplot_name!* := "gnuplot";
!#endif

symbolic procedure find!-gnuplot;
  begin scalar path;
    % first check environment variable gnuplot
    path := find!-gnuplot!-aux getenv("GNUPLOT");
    if path then return find!-gnuplot!-quotify path;

!#if (intersection '(winnt alphant win32 win64 cygwin) lispsystem!*)
    % if on windows, check registry
    path := get!-registry!-value("HKLM","Software\Microsoft\Windows\CurrentVersion\App Paths\gnuplot.exe",nil);
    if path and car path = 1 and filep cdr path
      then return find!-gnuplot!-quotify cdr path;
!#endif

    % last resort: return the name without path
    return find!-gnuplot!-quotify !*gnuplot_name!*;
  end;

symbolic procedure find!-gnuplot!-quotify path;
  %
  % for Windows, put double quotes around path
  %
!#if (intersection '(winnt alphant win32 win64 cygwin) lispsystem!*)
  concat("""",concat(path,""""));
!#else
  path;
!#endif

symbolic procedure find!-gnuplot!-aux path;
  %
  % check that dirpath path contains gnuplot executable
  %
  if null path then nil
   else <<
    if idp path then path := id2string path;

    % remove trailing directory separator if present
    if subseq(path,isub1 string!-length path, string!-length path) member '(!\ !/)
      then path := subseq(path,0,isub1 string!-length path);
    % build path
    path := bldmsg("%w%w%w",path,dirchar!*,!*gnuplot_name!*);

    % check existence
    (filep path and path)>>;

!#if (intersection '(dos os2 winnt alphant win32 win64 cygwin) lispsystem!*)

% When the Windows version of PSL is launched from a cygwin (mintty) shell
% it can be that neither TEMP nor TMP is set. Under cygwin the directory
% "/tmp" should be available but the path to it required by Reduce will
% be something like "C:\cygwin\tmp" and the exact location that cygwin
% had been installed in may vary from case to case. The code here tries
% to sort this out!

global '(cygin_tmp!*);

cygwin_tmp!* := nil;

symbolic procedure tempdir_for_cygwin();
  begin
    scalar a, b, c;
% I will only make the tests here once (if they succeed).
    if cygwin_tmp!* then return cygwin_tmp!*;
% The next line will generate output like "sh: 1: cygpath: not found" if
% cygpath is not available, and something like "c:\cygwin\tmp" if it is!
    a := errorset('(pipe!-open "cygpath -w /tmp 2>&1" 'input), nil, nil);
    if not errorp a then <<
      b := rds car a;
      c := readline();
      rds b;
      close car a  >> where !*echo = nil;
    a := explode2 c;
% I will assume that if the result ended up as "x:\..." for some x that it
% was valid.
    if a and eqcar(cdr a, '!:) and eqcar(cddr a, '!\) then
      return (cygwin_tmp!* := c)
    else return nil
  end;

!#endif

symbolic procedure get!-tempdir();
  begin
!#if (intersection '(dos os2 winnt alphant win32 win64 cygwin) lispsystem!*)
   tempdir!* := getenv "TMP" or getenv "TEMP";
   if null tempdir!* then tempdir!* := tempdir_for_cygwin();
!#else
!#if (member 'vms lispsystem!*)
   tempdir!* := "SYS$SCRATCH:";
!#else
   tempdir!* := "/tmp";
!#endif
!#endif
   return tempdir!*;
  end;

endmodule;

end;
