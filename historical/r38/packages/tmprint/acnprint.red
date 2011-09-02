% ----------------------------------------------------------------------
% $Id: tmprint.red,v 1.10 2004/11/20 20:50:14 seidl Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2003-2004 A. Dolzmann, A. Seidl, and T. Sturm
%                         changes by A C Norman, 2005
% ----------------------------------------------------------------------
%
%
% $Log: tmprint.red,v $
% Revision 1.11  2005/05/02 09:35:13  acn1
% This represents working through the whole code trying to tidy it
% up and remove all the parts that were to do with making this REDUCE
% code take responsibility for line-breaks. As a result so much has been
% changed that the bulk of the change-log information here becomes
% irrelevant for a support basis, so I have removed the bits of change
% log that represent earlier ACN changes, and abbreviated some of the
% earlier ones when they involve adjustments that are either now very
% stable or that have now vanished in more recent re-writes. But I will
% preserve the information about who made changes and when to keep a track
% of credit for work here.
%
% Revision 1.10  2004/11/20 20:50:14  seidl
% Linelength hack established again, only if Texmacs runs. Removed
% centering and curly brackets from fancy-out-header and -trailer.
% New switch promptnumbers, turned off only if Texmacs is running.
%
% Revision 1.9  2004/11/19 00:52:26  seidl  )
% Revision 1.8  2004/11/18 20:44:16  seidl  )
% Revision 1.7  2004/11/09 01:11:17  seidl  ) loads of good updates that
% Revision 1.6  2004/09/24 10:42:41  seidl  ) made this a working system!
% Revision 1.5  2004/08/12 13:04:23  seidl  )
% Revision 1.4  2003/11/20 13:10:44  sturm  )
% Revision 1.3  2003/11/20 12:23:01  sturm  )
% Revision 1.2  2003/11/20 11:06:12  sturm  )
% Texmacs now basically runs.
% Revision 1.1  2003/11/11 11:08:57  sturm
% Inital check-in.
% This is the original version by Andrey Grozin as obtained from fmprint.red
% via patching.
%
% ----------------------------------------------------------------------
module tmprint; % Output module for TeXmacs interface

% Fancy output package for symbolic expressions.
% using TEX as intermediate language. The exact details here are tuned
% to work with TeXmacs, which reuires something close to but not 100%
% identical to standard LaTeX.

% Author: Herbert Melenk, using ideas of maprin.red (A.C.H, A.C.N).
 
% Copyright (c) 1993 RAND, Konrad-Zuse-Zentrum.  All rights reserved.
% Significant subsequent updates by A Grozin, T Sturm,
% A Dolzman, A Seidl and A Norman, 2003-2005

%   Updates made: 8-Sep-94 12-Apr-94 17_Mar-94

% switches
%
%    ON FANCY          enable algebraic output processing by this module
%    ON PROMPTNUMBER   enable the default REDUCE prompt scheme. This
%                      switch is so that numbering can be disabled.
%    ON REDFRONT_MODE  adjustments that help with the REDFRONT interface
%

% properties used in this module:
%
%     fancy-prifn      print function for an operator
%
%     fancy-pprifn     print function for an operator including current 
%                      operator precedence for infix printing
%
%     fancy-prtch      string for infix printing of an operator 
%
%     fancy-special-symbol     
%                      print expression for a non-indexed item
%                      string with TEX expression  "\alpha"
%
%     fancy-infix-symbol    special-symbol for infix operators
%
%     fancy-prefix-symbol   special symbol for prefix operators
%

%     Updates made: 94-Jan-26 94-Jan-17 93-Dec-22

create!-package('(tmprint),nil);

fluid  '(
         !*nat
         !*revpri
         outputhandler!*
         outputhandler!-stack!*
         posn!*
            );

global '(charassoc!* ofl!*);

switch revpri;

% Global variables initialized in this section.

fluid '(  
    fancy!-switch!-on!*
    fancy!-switch!-off!* 
    !*fancy!-mode 
    fancy!-line!*
    fancy!-bstack!*
    !*fancy!-lower);


fancy!-switch!-on!* := int2id 16$
fancy!-switch!-off!* := int2id 17$

!*fancy!-lower := nil;   % case fold things to lower case if TRUE

global '(fancy_lower_digits fancy_print_df);

share fancy_lower_digits; % T, NIL or ALL.

if null fancy_lower_digits then fancy_lower_digits:=t;

share fancy_print_df;     % PARTIAL, TOTAL, INDEXED.

if null fancy_print_df then  fancy_print_df := 'partial;

switch fancy;

put('fancy,'simpfg,
  '((t (fmp!-switch t))
    (nil (fmp!-switch nil)) ));


global '(lispsystem!*);

switch promptnumbers; 

symbolic procedure fmp!-switch mode;        
      if mode then
        <<if outputhandler!* neq 'fancy!-output then 
          <<outputhandler!-stack!* := 
                outputhandler!* . outputhandler!-stack!*;
           outputhandler!* := 'fancy!-output;
          >>;
% with CSL I want to be able to switch texmacs mode on and off dynamically,
% so I switch off prompt numbering as I enter texmacs mode and put it
% back on on the way out.
        if member('csl,lispsystem!*) and 
           member('texmacs,lispsystem!*) then
           off1 'promptnumbers
        >>
      else 
        <<if outputhandler!* = 'fancy!-output then
          <<outputhandler!* := car outputhandler!-stack!*;
            outputhandler!-stack!* := cdr outputhandler!-stack!*;
          >> else
% With CSL I want to have tmprint loaded as part of the initial lisp image,
% and I want to call fmp!-switch early on based on whether I believe I should
% use the CSL internal display mode or an external viewer such as Texmacs.
% I thus want to be able to say "do not use fancy mode" rather explicitly
% from there whether or not it happened to be enabled in the system that
% saved the image file. So I really do not want this rederr call! I switch
% promptnumbers back on here for the case when Texmacs fancy printing is
% not wanted but the prompt colouring stuff from this file is activated (eg
% because redfront is in use, or Texmacs but without the fancy option?). I
% believe that mostly with CSL prompts are handled by CSL itself and so
% the promptnumbering flag is not relevant uless it has been set up for
% external Texmacs use...
        if not member('csl, lispsystem!*) then
           rederr "FANCY is not current output handler";
        if member('csl, lispsystem!*) then on1 'promptnumbers
        >>;

% The following procedure is applicable in the PSL version of REDUCE. The
% CSL interface to TeXmacs uses a different scheme (reduce is launched
% as "r38 --texmacs" and then a flag 'texmacs is put on the variable
% lispsystem!*).
% Texmacs predicate. Returns [t] iff Texmacs is running. 
procedure texmacsp;
   if getenv("TEXMACS_REDUCE_PATH") then t;

% The next two functions provide abstraction for conversion between
% strings and lists of character objects.

!#if (memq 'csl lispsystem!*)

% Convert a list of character objects into a string.
% (The function list!-to!-string already exists...)

% Convert a string into a list of character objects.
smacro procedure string!-to!-list a;
    explode2 a;

% Print a string without ANY conversion or adjustment, so if the string
% has control characters etc in it they get transmitted unchanged. Well
% let me express some reservations about what might happen if the string
% contains tabs and newlines - the lower level system IO code might
% interpret same...
smacro procedure raw!-print!-string s;
    prin2 s;

% Print the character whose code is n.
smacro procedure writechar n;
    tyo n;    % Like "prin2 int2id n"

% Convert a symbol or string to characters but ensure that all
% output characters are folded to lower case.
% CSL already has explode2lc;

!#else

smacro procedure list!-to!-string a;
    compress ('!" . append(a, '(!")));

smacro procedure string!-to!-list a;
    explode2 a;

% I do not know if this has to be like this in PSL, but it reflects
% what was in the code.
symbolic procedure raw!-print!-string s;
     for each x in string!-to!-list s do prin2 x;
% writechar already exists in PSL.

symbolic procedure explode2lc s;
    explode2 s where !*lower = t;

!#endif

symbolic procedure fancy!-tex s;
  % test output: print tex string.
  << prin2 fancy!-switch!-on!*;
     raw!-print!-string s;
     prin2t fancy!-switch!-off!*
  >>;

symbolic procedure fancy!-out!-item(it);
  if atom it then prin2 it else
  if eqcar(it,'ascii) then writechar(cadr it) else
  if eqcar(it,'tab) then
      for i:=1:cdr it do prin2 " "
    else
  if eqcar(it,'bkt) then
     begin scalar m,b,l; integer n;
      m:=cadr it; b:=caddr it; n:=cadddr it;
      l := b member '( !( !{ );
      if l then prin2 "\left" else prin2 "\right";
      if b member '(!{ !}) then prin2 "\";
      prin2 b;
    end
  else rederr "unknown print item";

symbolic procedure set!-fancymode bool;
  if bool neq !*fancy!-mode then <<
     !*fancy!-mode:=bool;
     fancy!-line!*:=nil;
     fancy!-line!*:= '((tab . 1)) >>;


symbolic procedure fancy!-output(mode,l);
% Interface routine.
   if ofl!* or (mode='maprin and posn!*>2) or not !*nat then <<
      if mode = 'maprin then maprin l
      else terpri!*(l) >> where outputhandler!* = nil
   else <<
      set!-fancymode t;
      if mode = 'maprin then <<
          fancy!-maprin0 l
      >>
      else <<
         fancy!-flush() >> >>;

symbolic procedure fancy!-out!-header();
  <<
    if posn()>0 then terpri();
    prin2 int2id 2;
    prin2 "latex:\black$\displaystyle "
  >>;

symbolic procedure fancy!-out!-trailer();
  <<
    prin2 "$";
    prin2 int2id 5
  >>;
   
symbolic procedure fancy!-flush();
  begin
    scalar !*lower;  % Rebinding *lower is needed for PSL here
    if fancy!-line!* and not eqcar(car fancy!-line!*,'tab) then <<
       fancy!-out!-header();
       for each it in reverse fancy!-line!* do fancy!-out!-item it;
       fancy!-out!-trailer() >>;
    fancy!-line!*:= {'tab . 1};
    set!-fancymode nil
  end;

  
%---------------- primitives -----------------------------------


% This one prints its argument without any adjustment at all
symbolic procedure fancy!-princ u;
   fancy!-line!* := u . fancy!-line!*;

% This prints an item, but it adds \mathrm() around it at times,
% maps special symbols, converts a21 to a_{21} and sticks in some
% backslashes where it thinks they are needed...

symbolic procedure fancy!-prin2 u;
  begin scalar str,id, longname;
    if atom u and eqcar(explode2 u,'!\) then <<
       fancy!-line!* := u . fancy!-line!*;
       return >>
    else if numberp u then <<
% The behaviour here seems really odd to me but appears to match what the
% version of tmprint in the development tree at the end of April 2005
% does... I suspect that either ALL numbers should be set in \mathrm or
% none should be.
       if u >= 10 or u < 0 then
          fancy!-line!* := '!} . u . '!\mathrm!{ . fancy!-line!*
       else fancy!-line!* := u . fancy!-line!*;
       return >>;
    str := stringp u;
    id := idp u and not digit u;
    u:= if atom u then <<
             if !*fancy!-lower then explode2lc u
             else explode2 u >>
        else {u};
    if id then <<
       u:=fancy!-lower!-digits fancy!-esc u;
       if car u = '!\mathrm!{ then longname := t >>
    else if car u neq '!\ and cdr u  then <<
       fancy!-line!* := '!\mathrm!{ . fancy!-line!*;
       longname := t >>;
    for each x in u do
    <<if str and (x='!    or x='!_)
         then fancy!-line!* := '!\ . fancy!-line!*;
      fancy!-line!* :=
        (if id and !*fancy!-lower 
          then red!-char!-downcase x else x) . fancy!-line!*;
    >>;
    if longname then fancy!-line!* := "}" . fancy!-line!*;
  end;

symbolic procedure fancy!-last!-symbol();
   if fancy!-line!* then car fancy!-line!*;

charassoc!* :=
         '((!A . !a) (!B . !b) (!C . !c) (!D . !d) (!E . !e) (!F . !f)
           (!G . !g) (!H . !h) (!I . !i) (!J . !j) (!K . !k) (!L . !l)
           (!M . !m) (!N . !n) (!O . !o) (!P . !p) (!Q . !q) (!R . !r)
           (!S . !s) (!T . !t) (!U . !u) (!V . !v) (!W . !w) (!X . !x)
           (!Y . !y) (!Z . !z));

symbolic procedure red!-char!-downcase u;
   (if x then cdr x else u) where x = atsoc(u,charassoc!*);

% Take any sequence of chars and stick "\" in front of any "_".
symbolic procedure fancy!-esc u;
   if not('!_ memq u) then u else
   (if car u eq '!_ then '!\ . w else w)
      where w = car u . fancy!-esc cdr u;

% This is going to split a name of the form abc123 into
% something like abc_{123}. Well it takes a list of characters
% as its argument and any string of digits within that should be
% lowered, so eg abc123xyz789 becomes abc_{123}xyz_{789}
% however as a yet more messy step, if a string of non-digits is a
% special word it gets mapped onto the corresponding symbol, so
% eg alpha, infinity etc het mapped onto \alpha, \infty...

symbolic procedure fancy!-lower!-digits1 u;
  begin
    scalar r, w, w1, longname;
    u := reverse u;
    while u do <<
% Collect the next word (without any digits in it)
      while u and not digit car u do <<
         w := car u . w;
         u := cdr u >>;
      if w then <<
         w1 := intern compress w;
         if stringp (w1 := get(w1, 'fancy!-special!-symbol)) then
            w := explode2 w1;
         longname := car w neq '!\ and cdr w;
         r := append(w, r) >>;
% now process and string of digits
      if u and digit car u then <<
         r := '!} . r;
         while u and digit car u do <<
            r := car u . r;
            u := cdr u >>;
         r := '!_ . '!{ . r >> >>;
% Each time around the loop the next character must be either
% a digit or not a digit, and in either case I make progress.
    if longname then r := '!\mathrm!{ . r;
    return r;
  end;

% This procedure judges whether to rewrite a symbol as a susbcripted
% item. It will detect cases of a name that starts with one or more
% non-digits, has at least one digit, and from the location onwards
% consists only of digits. It is used in the default case when
% fancy_lower_digits is neither NIL nor ALL.

symbolic procedure fancy!-lower!-digitstrail u;
  begin
% an empty name or one starting with a digit should not be lowered
    if null u or digit car u then return nil;
    u := cdr u;
% trim any initial non-digits
    while u and not digit car u do u := cdr u;
% if nothing is left we do not have even a potential subscript
    if null u then return nil;
% scan to check that all the rest is made up of digits, and if so
% declare TRUE.
    while u and digit car u do u := cdr u;
    return null u
  end;

symbolic procedure fancy!-lower!-digits u;
   (if null m then u 
    else if m = 'all or 
            fancy!-lower!-digitstrail u then 
       fancy!-lower!-digits1 u
    else if null cdr u then u
     else '!\mathrm!{ . u
    ) where m=fancy!-mode fancy_lower_digits;

symbolic procedure fancy!-mode u;
   if eqcar(u,'!*sq) then reval u
   else u;

%---------------- central formula converter --------------------

% This is just used at the top level, and it arranges that a number
% printed there is never put as \mathrm even though it might be anywhere
% else!
% The behaviour here seems really odd to me but appears to match what the
% version of tmprint in the development tree at the end of April 2005
% does... I suspect that either ALL numbers should be set in \mathrm or
% none should be.

symbolic procedure fancy!-maprin0 u;
   if numberp u then fancy!-princ u
   else fancy!-maprint(u,0) where !*lower=nil;

symbolic procedure fancy!-maprin1 u;
   fancy!-maprint(u,0) where !*lower=nil;

symbolic procedure fancy!-maprint(l,p);
   % Print expression l at bracket level p without terminating
   % print line.  Special cases are handled by:
   %    pprifn: a print function that includes bracket level as 2nd arg.
   %     prifn: a print function with one argument.
   begin scalar x,pos;
        if null l then return nil;
        if atom l then return fancy!-maprint!-atom(l,p);
               
        if not atom car l then return fancy!-maprint(car l,p);

        l := fancy!-convert(l,nil);

        if (x:=get(car l,'fancy!-reform)) then 
          return fancy!-maprint(apply1(x,l),p);
        if (x := get(car l,'fancy!-pprifn)) then return apply2(x,l,p)
        else if (x := get(car l,'fancy!-prifn)) then return apply1(x,l)
        else if get(car l,'print!-format) then
           return fancy!-print!-format(l,p);

        % eventually convert expression to a different form
        % for printing.

        l := fancy!-convert(l,'infix);

        % printing operators with integer argument in index form.
        if flagp(car l,'print!-indexed) then 
        << fancy!-prefix!-operator(car l);
           fancy!-print!-indexlist cdr l
        >>
      
        else if x := get(car l,'infix) then 
        << p := not(x>p);
          if p then fancy!-in!-brackets(
            {'fancy!-inprint,mkquote car l,x,mkquote cdr l},
               '!(,'!))
              else fancy!-inprint(car l,x,cdr l);
        >>
        else if (x := get(car l,'fancy!-pprifn)) then return apply2(x,l,0)
        else if (x := get(car l,'fancy!-prifn)) then return apply1(x,l)
        else <<
           fancy!-prefix!-operator(car l);
           fancy!-print!-function!-arguments cdr l >>
    end;

symbolic procedure fancy!-convert(l,m);
  % special converters.
  if eqcar(l,'expt) and cadr l= 'e and
     ( m='infix or treesizep(l,20) )
        then {'exp,caddr l}
    else l;

symbolic procedure fancy!-print!-function!-arguments u;
  % u is a parameter list for a function.
    fancy!-in!-brackets(
       u and {'fancy!-inprint, mkquote '!*comma!*,0,mkquote u},
            '!(,'!));

symbolic procedure fancy!-maprint!-atom(l,p);
  begin scalar x;
     if (x:=get(l,'fancy!-special!-symbol)) then fancy!-prin2 x
     else if vectorp l then <<
        fancy!-princ "[";
        l:=for i:=0:upbv l collect getv(l,i);
        fancy!-inprint(",",0,l);
        fancy!-princ "]";
        return nil>>
     else if not numberp l or
             l >= 0 or 
             p <= get('minus,'infix) then fancy!-prin2 l
     else fancy!-in!-brackets({'fancy!-prin2,mkquote l}, '!(,'!));
     return nil;
  end;

put('print_indexed,'psopfn,'(lambda(u)(flag u 'print!-indexed)));

symbolic procedure fancy!-print!-indexlist l;
   fancy!-print!-indexlist1(l,'!_,nil);

symbolic procedure fancy!-print!-indexlist1(l,op,sep);
  % print index or exponent lists, with or without separator.
  begin
    fancy!-prin2 op;
    fancy!-princ "{";
    fancy!-inprint(sep or 'times,0,l);
    fancy!-princ "}";
  end;

symbolic procedure fancy!-print!-one!-index i;
  begin
    fancy!-princ "_{";
    fancy!-inprint('times,0,{i});
    fancy!-princ "}";
  end;

symbolic procedure fancy!-in!-brackets(u,l,r);
  % put form into brackets (round, curly,...).
  % u: form to be evaluated,
  % l,r: left and right brackets to be inserted.
   (begin scalar fp,r1,r2,rec; 
     rec := {0};
     fancy!-bstack!* := rec . fancy!-bstack!*;
     fancy!-adjust!-bkt!-levels fancy!-bstack!*;
     fancy!-prin2 (r1:='bkt.nil.l.rec);
     eval u;
     fancy!-prin2 (r2:='bkt.nil.r.rec);
     car cdr r1:= t; 
     car cdr r2:= t;
     return nil;
   end) where fancy!-bstack!* = fancy!-bstack!*;
     

symbolic procedure fancy!-adjust!-bkt!-levels u;
   if null u or null cdr u then nil
   else if caar u >= caadr u then
    <<car cadr u := car cadr u +1;
      fancy!-adjust!-bkt!-levels cdr u; >>;

symbolic procedure fancy!-exptpri(l,p);
% Prints expression in an exponent notation.
   begin scalar pp,q,w1,w2;
      pp := not((q:=get('expt,'infix))>p);  % Need to parenthesize
      w1 := cadr l; w2 := caddr l;
      if eqcar(w2,'quotient) and cadr w2 = 1 
          and (fixp caddr w2 or liter caddr w2) then
         return fancy!-sqrtpri!*(w1,caddr w2);
      if eqcar(w2,'quotient) and eqcar(cadr w2,'minus)
          then w2 := list('minus,list(car w2,cadadr w2,caddr w2))
          else w2 := negnumberchk w2;
      fancy!-maprint(w1,q);
      fancy!-princ "^";
      if eqcar(w2,'quotient) and fixp cadr w2 and fixp caddr w2 then <<
         fancy!-princ "{";
         fancy!-inprint('!/,0,cdr w2); 
         fancy!-princ "}" >> 
      else fancy!-maprint!-tex!-bkt(w2,0,nil);
   end;

put('expt,'fancy!-pprifn,'fancy!-exptpri);

symbolic procedure fancy!-inprint(op,p,l);
   begin scalar x,y;
     % print product of quotients using *.
     if op = 'times and
        eqcar(car l,'quotient) and 
        cdr l and eqcar(cadr l,'quotient) then
        op:='!*;
     if op eq 'plus and !*revpri then l := reverse l;
     if not get(op,'alt) then  <<
        if op eq 'not then <<
            fancy!-oprin op; 
            return  fancy!-maprint(car l,get('not,'infix)) >>; 
        if op eq 'setq and not atom (x := car reverse l)
             and idp car x and (y := getrtype x)
             and (y := get(get(y,'tag),'fancy!-setprifn))
            then return apply2(y,car l,x);
        if not atom car l and
           idp caar l and
           ((x := get(caar l,'fancy!-prifn)) 
                   or (x := get(caar l,'fancy!-pprifn))) and
           (get(x,op) eq 'inbrackets) then <<
            % to avoid mix up of indices and exponents.
               fancy!-in!-brackets(
                {'fancy!-maprint,mkquote car l,p}, '!(,'!)) >>;
          fancy!-maprint(car l, p);
          l := cdr l >>;
     fancy!-inprint2(op,p,l);
   end;

 
symbolic procedure fancy!-inprint2(op,p,l);
   % second line
  begin scalar lop;
   for each v in l do
     <<lop:=op;
       if op='plus and eqcar(v,'minus) then
              <<lop := 'minus; v:= cadr v>>;
       fancy!-oprin lop;
       fancy!-maprint(negnumberchk v,p)
     >>
  end;

symbolic procedure fancy!-inprintlist(op,p,l);
   % inside algebraic list
 begin scalar fst,v;
  loop:
   if null l then return nil;
   v := car l; l:= cdr l;
   if fst then
       << fancy!-princ "\,";
          fancy!-oprin op;
          fancy!-princ "\,";
       >>;
   fancy!-maprint(v,0);
   fst := t;
   goto loop;
  end; 

put('times,'fancy!-prtch,"\*");

symbolic procedure fancy!-oprin op;
  begin scalar x;
    if (x:=get(op,'fancy!-prtch)) then fancy!-prin2 x
    else if (x:=get(op,'fancy!-infix!-symbol)) then fancy!-prin2 x
    else if null(x:=get(op,'prtch)) then fancy!-prin2 op
    else fancy!-prin2 x
  end;

put('alpha,'fancy!-special!-symbol,"\alpha");
put('beta,'fancy!-special!-symbol,"\beta");
put('gamma,'fancy!-special!-symbol,"\gamma");
put('delta,'fancy!-special!-symbol,"\delta");
put('epsilon,'fancy!-special!-symbol,"\varepsilon");
put('zeta,'fancy!-special!-symbol,"\zeta");
put('eta,'fancy!-special!-symbol,"\eta");
put('theta,'fancy!-special!-symbol,"\theta");
put('iota,'fancy!-special!-symbol,"\iota");
put('kappa,'fancy!-special!-symbol,"\varkappa");
put('lambda,'fancy!-special!-symbol,"\lambda");
put('mu,'fancy!-special!-symbol,"\mu");
put('nu,'fancy!-special!-symbol,"\nu");
put('xi,'fancy!-special!-symbol,"\xi");
put('pi,'fancy!-special!-symbol,"\pi");
put('rho,'fancy!-special!-symbol,"\rho");
put('sigma,'fancy!-special!-symbol,"\sigma");
put('tau,'fancy!-special!-symbol,"\tau");
put('upsilon,'fancy!-special!-symbol,"\upsilon");
put('phi,'fancy!-special!-symbol,"\phi");
put('chi,'fancy!-special!-symbol,"\chi");
put('psi,'fancy!-special!-symbol,"\psi");
put('omega,'fancy!-special!-symbol,"\omega");

!#if (memq 'csl lispsystem!*)

deflist('(
% Many of these are just the same glyphs as ordinary upper case letters,
% and so for compatibility with external viewers I map those ones onto
% letters with the "\mathit" qualifier to force the font.
     (!Alpha "\mathit{A}") (!Beta "\mathit{B}") (!Chi "\Chi ")
     (!Delta "\Delta ") (!Epsilon "\mathit{E}") (!Phi "\Phi ")
     (!Gamma "\Gamma ") (!Eta "\mathit{H}") (!Iota "\mathit{I}")
     (!vartheta "\vartheta") (!Kappa "\Kappa ") (!Lambda "\Lambda ")
     (!Mu "\mathit{M}") (!Nu "\mathit{N}") (!O "\mathit{O}")
     (!Pi "\Pi ") (!Theta "\Theta ") (!Rho "\mathit{R}")
     (!Sigma "\Sigma ") (!Tau "\Tau ") (!Upsilon "\Upsilon ")
     (!Omega "\Omega ") (!Xi "\Xi ") (!Psi "\Psi ")
     (!Zeta "\mathit{Z}") (!varphi "\varphi ")
        ),'fancy!-special!-symbol);

!#else

if 'a neq '!A then deflist('(
    (!Alpha "A") (!Beta "B") (!Chi "\Chi") (!Delta "\Delta")
    (!Epsilon "E")(!Phi "\Phi") (!Gamma "\Gamma")(!Eta "H")
    (!Iota "I") (vartheta "\vartheta")(!Kappa "K")(!Lambda "\Lambda")
    (!Mu "M")(!Nu "N")(!O "O")(!Pi "\Pi")(!Theta "\Theta")
    (!Rho "R")(!Sigma "\Sigma")(!Tau "\Tau")(!Upsilon "\Upsilon")
    (!Omega "\Omega") (!Xi "\Xi")(!Psi "\Psi")(!Zeta "Z") 
    (varphi "\varphi")
       ),'fancy!-special!-symbol);

!#endif

put('infinity,'fancy!-special!-symbol,"\infty ");
put('partial!-df,'fancy!-special!-symbol,"\partial ");
put('empty!-set,'fancy!-special!-symbol,"\emptyset ");
put('not,'fancy!-special!-symbol,"\neg ");
put('not,'fancy!-infix!-symbol,"\neg ");
put('leq,'fancy!-infix!-symbol,"\leq ");
put('geq,'fancy!-infix!-symbol,"\geq ");
put('neq,'fancy!-infix!-symbol,"\neq ");
put('intersection,'fancy!-infix!-symbol,"\cap ");
put('union,'fancy!-infix!-symbol,"\cup ");
put('member,'fancy!-infix!-symbol,"\in ");
put('and,'fancy!-infix!-symbol,"\wedge ");
put('or,'fancy!-infix!-symbol,"\vee ");
put('when,'fancy!-infix!-symbol,"|");
put('!*wcomma!*,'fancy!-infix!-symbol,",\,");
put('replaceby,'fancy!-infix!-symbol,"\Rightarrow ");
put('!~,'fancy!-functionsymbol,"\forall ");


% The following definitions allow for more natural printing of
% conditional expressions within rule lists.

symbolic procedure fancy!-condpri(u,p);
  begin
    if p>0 then fancy!-princ "\left(";
    while (u := cdr u) do <<
        if not(caar u eq 't) then <<
           fancy!-princ "if\ "; 
           fancy!-maprin1 caar u;
           fancy!-princ "\,then\," >>;
        fancy!-maprin1 cadar u;
        if cdr u then <<
           fancy!-princ "\,"; 
           fancy!-princ "else\," >> >>;
    if p>0 then fancy!-prin2 "\right)";
  end;

put('cond,'fancy!-pprifn,'fancy!-condpri);

symbolic procedure fancy!-revalpri u;
   fancy!-maprin1 fancy!-unquote cadr u;

symbolic procedure fancy!-unquote u;
  if eqcar(u,'list) then for each x in cdr u collect 
      fancy!-unquote x
  else if eqcar(u,'quote) then cadr u else u;

put('aeval,'fancy!-prifn,'fancy!-revalpri);
put('aeval!*,'fancy!-prifn,'fancy!-revalpri);
put('reval,'fancy!-prifn,'fancy!-revalpri);
put('reval!*,'fancy!-prifn,'fancy!-revalpri);

put('aminusp!:,'fancy!-prifn,'fancy!-patpri);
put('aminusp!:,'fancy!-pat,'(lessp !&1 0));

symbolic procedure fancy!-patpri u;
  begin scalar p;
    p:=subst(fancy!-unquote  cadr u,'!&1,
             get(car u,'fancy!-pat));
    return fancy!-maprin1 p;
  end;

symbolic procedure fancy!-boolvalpri u;
   fancy!-maprin1 cadr u;

put('boolvalue!*,'fancy!-prifn,'fancy!-boolvalpri);

symbolic procedure fancy!-quotpri u;
   begin
     fancy!-princ "\frac";
     fancy!-maprint!-tex!-bkt(cadr u,0,t);
     fancy!-maprint!-tex!-bkt(caddr u,0,nil);
  end;

symbolic procedure fancy!-maprint!-tex!-bkt(u,p,m);
  % Produce expression with tex brackets {...} if
  % necessary. Ensure that {} unit is in same formula.
  % If m=t brackets will be inserted in any case.
  begin scalar fl;
   if not m and (numberp u and 0<=u and u <=9 or liter u) then 
   << fancy!-prin2 u;
      return nil;
   >>;
   fancy!-princ "{";
   fancy!-maprint(u,p);
   fancy!-princ "}"
  end;
   
put('quotient,'fancy!-prifn,'fancy!-quotpri);

%-----------------------------------------------------------
%
%   support for print format property
%
%-----------------------------------------------------------

symbolic procedure print_format(f,pat);
  % Assign a print pattern p to the operator form f.
put(car f, 'print!-format, (cdr f . pat) . get(car f, 'print!-format));

symbolic operator print_format;

symbolic procedure fancy!-print!-format(u,p);
  begin scalar fmt,fmtl,a;
   fmtl:=get(car u,'print!-format);
 l:
   fmt := car fmtl; fmtl := cdr fmtl;
   if length(car fmt) neq length cdr u then goto l;
   a:=pair(car fmt,cdr u);
   return fancy!-print!-format1(cdr fmt,p,a);
  end;

symbolic procedure fancy!-print!-format1(u,p,a);
  begin scalar x,y,pl,bkt,obkt,q;
   if eqcar(u,'list) then u:= cdr u;
   while u do
   <<x:=car u; u:=cdr u;
     if eqcar(x,'list) then x:=cdr x;
     obkt := bkt; bkt:=nil;
     if obkt then fancy!-princ "{";
     if pairp x then fancy!-print!-format1(x,p,a)
     else if memq(x,'(!( !) !, !. !|)) then 
         <<if x eq '!( then <<pl:=p.pl; p:=0>> else
           if x eq '!) then <<p:=car pl; pl:=cdr pl>>;
           fancy!-prin2 x >>
     else if x eq '!_ or x eq '!^ then <<bkt:=t;fancy!-prin2 x>> 
     else if q:=assoc(x,a) then fancy!-maprint(cdr q,p)
     else fancy!-maprint(x,p);
     if obkt then fancy!-princ "}"
    >>
  end;
     

%-----------------------------------------------------------
%
%   some operator specific print functions
%
%-----------------------------------------------------------

symbolic procedure fancy!-prefix!-operator(u);
 % Print as function, but with a special character.  
   begin scalar sy;
     sy := get(u,'fancy!-functionsymbol) or
           get(u,'fancy!-special!-symbol);
     if sy then fancy!-prin2 sy
     else fancy!-prin2 u
   end;

put('sqrt,'fancy!-prifn,'fancy!-sqrtpri);

symbolic procedure fancy!-sqrtpri(u);
    fancy!-sqrtpri!*(cadr u,2);
    
symbolic procedure fancy!-sqrtpri!*(u,n);
   begin 
     fancy!-princ "\sqrt";
     if n neq 2 then <<
       fancy!-princ "[\,";
       fancy!-prin2 n;
       fancy!-princ "]" >>;
     return fancy!-maprint!-tex!-bkt(u,0,t);
   end;


symbolic procedure fancy!-sub(l,p);
% Prints expression in an exponent notation.
  if get('expt,'infix)<=p then 
      fancy!-in!-brackets({'fancy!-sub,mkquote l,0},'!(,'!))
    else
    begin scalar eqs;
      l:=cdr l;
      while cdr l do <<eqs:=append(eqs,{car l}); l:=cdr l>>;
      l:=car l;
      fancy!-maprint(l,get('expt,'infix));
      fancy!-princ "|_{";
      fancy!-inprint('!*comma!*,0,eqs);
      fancy!-princ "}"
   end;

put('sub,'fancy!-pprifn,'fancy!-sub);
 

put('factorial,'fancy!-pprifn,'fancy!-factorial);

symbolic procedure fancy!-factorial(u,n);
   begin
     if atom cadr u then fancy!-maprint(cadr u,9999)
     else fancy!-in!-brackets({'fancy!-maprint,mkquote cadr u,0},
                               '!(,'!));
     fancy!-princ "!";
   end;

put('binomial,'fancy!-prifn,'fancy!-binomial);

symbolic procedure fancy!-binomial u;
   begin
     fancy!-princ "\left(\begin{matrix}";
     fancy!-maprint(cadr u,0);
     fancy!-princ "\\";
     fancy!-maprint(caddr u,0);
     fancy!-princ "\end{matrix}\right)";
   end;

symbolic procedure fancy!-intpri(u,p);
  if p>get('times,'infix) then 
    fancy!-in!-brackets({'fancy!-intpri,mkquote u,0},'!(,'!))
   else
   begin
     if fancy!-height(cadr u,1.0) > 3 then fancy!-princ "\Int "
     else fancy!-princ "\int ";
     fancy!-maprint(cadr u,0);
     fancy!-princ "\,d\,";
     fancy!-maprint(caddr u,0)
   end;

% It may well be that if TeXmacs does all the layout that this is no longer
% needed.

symbolic procedure fancy!-height(u,h);
  % estimate the height of an expression.
    if atom u then h 
    else if car u = 'minus then fancy!-height(cadr u,h)
    else if car u = 'plus or car u = 'times then
      eval('max. for each w in cdr u collect fancy!-height(w,h))
    else if car u = 'expt then 
         fancy!-height(cadr u,h) + fancy!-height(caddr u,h*0.8)
    else if car u = 'quotient then  
         fancy!-height(cadr u,h) + fancy!-height(caddr u,h)
    else if get(car u,'simpfn) then fancy!-height(cadr u,h)
    else h;

put('int,'fancy!-pprifn,'fancy!-intpri);

symbolic procedure fancy!-sumpri!*(u,p,mode);
  if p>get('minus,'infix) then 
    fancy!-in!-brackets({'fancy!-sumpri!*,mkquote u,0,mkquote mode},
                         '!(,'!))
   else
   begin scalar w,lo,hi,var;
     var := caddr u;
     if cdddr u then lo:=cadddr u;
     if lo and cddddr u then hi := car cddddr u;
     w:=if lo then {'equal,var,lo} else var;
     if mode = 'sum then 
        fancy!-princ "\sum" % big SIGMA
     else if mode = 'prod then 
        fancy!-princ "\prod"; % big PI
     fancy!-princ "_{";
     if w then fancy!-maprint(w,0);
     fancy!-princ "}";
     if hi then <<
        fancy!-princ "^";
        fancy!-maprint!-tex!-bkt(hi,0,nil) >>;
     fancy!-princ "\,";
     fancy!-maprint(cadr u,0);
   end;

symbolic procedure fancy!-sumpri(u,p); fancy!-sumpri!*(u,p,'sum);

put('sum,'fancy!-pprifn,'fancy!-sumpri);
put('infsum,'fancy!-pprifn,'fancy!-sumpri);

symbolic procedure fancy!-prodpri(u,p); fancy!-sumpri!*(u,p,'prod);

put('prod,'fancy!-pprifn,'fancy!-prodpri);

symbolic procedure fancy!-limpri(u,p);
  if p>get('minus,'infix) then 
    fancy!-in!-brackets({'fancy!-sumpri,mkquote u,0},'!(,'!))
   else
   begin scalar lo,var;
     var := caddr u;
     if cdddr u then lo:=cadddr u;
     fancy!-princ "\lim";
     fancy!-princ "_{";
     fancy!-maprint(var,0);
     fancy!-princ "\rightarrow";
     fancy!-maprint(lo,0);
     fancy!-princ "}";
     fancy!-maprint(cadr u,0);
   end;

put('limit,'fancy!-pprifn,'fancy!-limpri);

symbolic procedure fancy!-listpri(u);
 (if null cdr u then fancy!-maprint('empty!-set,0)
   else
  fancy!-in!-brackets(
   {'fancy!-inprintlist,mkquote '!*wcomma!*,0,mkquote cdr u},
               '!{,'!})
  );

put('list,'fancy!-prifn,'fancy!-listpri);

put('!*sq,'fancy!-reform,'fancy!-sqreform);

symbolic procedure fancy!-sqreform u;
    prepsq!* sqhorner!* cadr u;

put('df,'fancy!-pprifn,'fancy!-dfpri);

% 9-Dec-93: 'total repaired

symbolic procedure fancy!-dfpri(u,l);
  (if flagp(cadr u,'print!-indexed) or
      pairp cadr u and flagp(caadr u,'print!-indexed)
    then fancy!-dfpriindexed(u,l)
   else if m = 'partial then fancy!-dfpri0(u,l,'partial!-df)
   else if m = 'total then fancy!-dfpri0(u,l,'!d)
   else if m = 'indexed then fancy!-dfpriindexed(u,l)
   else rederr "unknown print mode for DF")
        where m=fancy!-mode fancy_print_df;

symbolic procedure fancy!-partialdfpri(u,l);
     fancy!-dfpri0(u,l,'partial!-df);

symbolic procedure fancy!-dfpri0(u,l,symb);
 if null cddr u then fancy!-maprin1 {'times,symb,cadr u} else
 if l >= get('expt,'infix) then % brackets if exponented
  fancy!-in!-brackets({'fancy!-dfpri0,mkquote u,0,mkquote symb},
                      '!(,'!))
   else
  begin scalar x,d,q; integer n,m;
    u:=cdr u;
    q:=car u;
    u:=cdr u;
    while u do
    <<x:=car u; u:=cdr u;
      if u and numberp car u then
      <<m:=car u; u := cdr u>> else m:=1;
      n:=n+m;
      d:= append(d,{symb,if m=1 then x else {'expt,x,m}});
    >>;
    return fancy!-maprin1 
       {'quotient, {'times,
                    if n=1 then symb else {'expt,symb,n},q},
                    'times. d};
  end;

symbolic procedure fancy!-dfpriindexed(u,l);
   if null cddr u then fancy!-maprin1{'times,'partial!-df,cadr u}
   else <<
      fancy!-maprin1 cadr u;
      fancy!-print!-indexlist fancy!-dfpriindexedx(cddr u,nil) >>;

symbolic procedure fancy!-dfpriindexedx(u,p);
  if null u then nil else
  if numberp car u then 
     append(for i:=2:car u collect p,fancy!-dfpriindexedx(cdr u,p))
  else car u . fancy!-dfpriindexedx(cdr u,car u);

put('!:rd!:,'fancy!-prifn,'fancy!-rdprin);

symbolic procedure fancy!-rdprin u;
  begin scalar digits; integer dotpos,xp;
   u:=rd!:explode u;
   digits := car u; xp := cadr u; dotpos := caddr u;
   return fancy!-rdprin1(digits,xp,dotpos);
  end;

symbolic procedure fancy!-rdprin1(digits,xp,dotpos);
  begin scalar str;
   if xp>0 and dotpos+xp<length digits-1 then
      <<dotpos := dotpos+xp; xp:=0>>;
    % build character string from number.
   for i:=1:dotpos do 
   <<str := car digits . str;
     digits := cdr digits; if null digits then digits:='(!0);
   >>;
   str := '!. . str;
   for each c in digits do str :=c.str;
   if not(xp=0) then <<
     str:='!e.str;
     for each c in explode2 xp do str:=c.str>>;
   for each c in reversip str do fancy!-prin2 c
  end;

put('!:cr!:,'fancy!-pprifn,'fancy!-cmpxprin);
put('!:cr!:,'fancy!-pprifn,'fancy!-cmpxprin);

symbolic procedure fancy!-cmpxprin(u,l);
   begin scalar rp,ip;
     rp:=reval {'repart,u}; ip:=reval {'impart,u};
     return fancy!-maprint(
       if ip=0 then rp else
       if rp=0 then {'times,ip,'!i} else
        {'plus,rp,{'times,ip,'!i}},l);
   end;

symbolic procedure fancy!-dn!:prin u;
 begin scalar lst; integer dotpos,ex;
  lst := bfexplode0x (cadr u, cddr u);
  ex := cadr lst;
  dotpos := caddr lst;
  lst := car lst;
  return fancy!-rdprin1 (lst,ex,dotpos)
 end;

put ('!:dn!:, 'fancy!-prifn, 'fancy!-dn!:prin);

fmp!-switch t;

endmodule;


%-------------------------------------------------------

module f;   % Matrix printing routines.


symbolic procedure fancy!-setmatpri(u,v);
   fancy!-matpri1(cdr v,u);

put('mat,'fancy!-setprifn,'fancy!-setmatpri);

symbolic procedure fancy!-matpri u;
   fancy!-matpri1(cdr u,nil);
   

put('mat,'fancy!-prifn,'fancy!-matpri);

symbolic procedure fancy!-matpri2(u,x);
   begin scalar fl,fmat,row,elt;
      integer cols,rows,rw,maxpos;
      rows := length u;
      cols := length car u;
% I can and will re-write all of this when I have the rest working again...
      if x then <<
         fancy!-maprint(x,0);
% I think I might use princ on the next line, but the current code renders
% ":=" within \mathrm... ???
         fancy!-prin2 ":=" >>;
      fl := fancy!-line!*;
      fmat := for each row in u collect
        for each elt in row collect
          <<fancy!-line!*:=nil;
            fancy!-maprint(elt,0);
            fancy!-line!* >>;
       % restore output line.
     fancy!-line!* := fl;
       % TEX header
     fancy!-princ "\left(\begin{matrix}";
       % join elements.
     while fmat do
     <<row := car fmat; fmat:=cdr fmat;
       while row do
       <<elt:=car row; row:=cdr row;
         fancy!-line!* := append(elt,fancy!-line!*);
         if row then fancy!-line!* :='!& . fancy!-line!*  
         else if fmat then 
            fancy!-line!* := "\\". fancy!-line!* >> >>;
     fancy!-princ "\end{matrix}\right)"
  end;


symbolic procedure fancy!-matpri1(u,x);
   % Prints a matrix canonical form U with name X.
   % Tries to do fancy display if nat flag is on.
   fancy!-matpri2(u,x); 

put('taylor!*,'fancy!-reform,'Taylor!*print1);

endmodule;

module fancy_specfn;

put('sin,'fancy!-prifn,'fancy!-sin);
put('cos,'fancy!-prifn,'fancy!-cos);
put('tan,'fancy!-prifn,'fancy!-tan);
put('cot,'fancy!-prifn,'fancy!-cot);
put('sec,'fancy!-prifn,'fancy!-sec);
put('csc,'fancy!-prifn,'fancy!-csc);
put('asin,'fancy!-prifn,'fancy!-asin);
put('acos,'fancy!-prifn,'fancy!-acos);
put('atan,'fancy!-prifn,'fancy!-atan);
put('sinh,'fancy!-prifn,'fancy!-sinh);
put('cosh,'fancy!-prifn,'fancy!-cosh);
put('tanh,'fancy!-prifn,'fancy!-tanh);
put('coth,'fancy!-prifn,'fancy!-coth);
put('exp,'fancy!-prifn,'fancy!-exp);
put('log,'fancy!-prifn,'fancy!-log);
put('ln,'fancy!-prifn,'fancy!-ln);
put('max,'fancy!-prifn,'fancy!-max);
put('min,'fancy!-prifn,'fancy!-min);
%put('repart,'fancy!-prifn,'fancy!-repart);
%put('impart,'fancy!-prifn,'fancy!-impart);

symbolic procedure fancy!-sin(u);
  begin
   fancy!-princ "\sin";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-cos(u);
  begin
   fancy!-princ "\cos";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-tan(u);
  begin
   fancy!-princ "\tan";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-cot(u);
  begin
   fancy!-princ "\cot";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-sec(u);
  begin
   fancy!-princ "\sec";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-csc(u);
  begin
   fancy!-princ "\csc";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-asin(u);
  begin
   fancy!-princ "\arcsin";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-acos(u);
  begin
   fancy!-princ "\arccos";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-atan(u);
  begin
   fancy!-princ "\arctan";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-sinh(u);
  begin
   fancy!-princ "\sinh";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-cosh(u);
  begin
   fancy!-princ "\cosh";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-tanh(u);
  begin
   fancy!-princ "\tanh";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-coth(u);
  begin
   fancy!-princ "\coth";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-exp(u);
  begin
   fancy!-princ "\exp";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-log(u);
  begin
   fancy!-princ "\log";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-ln(u);
  begin
   fancy!-princ "\ln";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-max(u);
  begin
   fancy!-princ "\max";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-min(u);
  begin
   fancy!-princ "\min";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-repart(u);
  begin
   fancy!-princ "\Re";
   fancy!-print!-function!-arguments cdr u;
  end;

symbolic procedure fancy!-impart(u);
  begin
   fancy!-princ "\Im";
   fancy!-print!-function!-arguments cdr u;
  end;

put('besseli,'fancy!-prifn,'fancy!-bessel);
put('besselj,'fancy!-prifn,'fancy!-bessel);
put('bessely,'fancy!-prifn,'fancy!-bessel);
put('besselk,'fancy!-prifn,'fancy!-bessel);
put('besseli,'fancy!-functionsymbol,'(ascii 73));
put('besselj,'fancy!-functionsymbol,'(ascii 74));
put('bessely,'fancy!-functionsymbol,'(ascii 89));
put('besselk,'fancy!-functionsymbol,'(ascii 75));

symbolic procedure fancy!-bessel(u);
  begin
   fancy!-prefix!-operator car u;
   fancy!-print!-one!-index cadr u; 
   fancy!-print!-function!-arguments cddr u;
  end;

% Hypergeometric functions.


put('hypergeometric,'fancy!-prifn,'fancy!-hypergeometric);

symbolic procedure fancy!-hypergeometric u;
  begin scalar a1,a2,a3;
   a1 :=cdr cadr u;
   a2 := cdr caddr u;
   a3 := cadddr u;
   fancy!-princ "{}";
   fancy!-print!-one!-index length a1;
   fancy!-princ "F";
   fancy!-print!-one!-index length a2;
   fancy!-princ "\left(\left.";
   fancy!-print!-indexlist1(a1,'!^,'!*comma!*);
   fancy!-print!-indexlist1(a2,'!_,'!*comma!*);
   fancy!-princ "\,\right|\,";
   fancy!-maprint(a3,0);
   fancy!-princ "\right)";
  end;
   
% hypergeometric({1,2,u/w,v},{5,6},sqrt x);

put('meijerg,'fancy!-prifn,'fancy!-meijerG);

symbolic procedure fancy!-meijerG u;
  begin scalar a1,a2,a3;
   integer n,m,p,q;
   a1 :=cdr cadr u;
   a2 := cdr caddr u;
   a3 := cadddr u;
   m:=length cdar a2;
   n:=length cdar a1;
   a1 := append(cdar a1 , cdr a1);
   a2 := append(cdar a2 , cdr a2);
   p:=length a1; q:=length a2;
   fancy!-princ "G";
   fancy!-print!-indexlist1({m,n},'!^,nil);
   fancy!-print!-indexlist1({p,q},'!_,nil);
   fancy!-princ "\left(";
   fancy!-maprint(a3,0);
   fancy!-princ "\left|";
   fancy!-print!-indexlist1(a1,'!^,'!*comma!*);
   fancy!-print!-indexlist1(a2,'!_,'!*comma!*);
   fancy!-princ "\right.\right)";
  end;

% meijerg({{},1},{{0}},x);
   
% Now a few things that can be useful for testing this code...

algebraic operator texsym, texbox, texfbox, texstring;

% texsym(!Longleftarrow) should generate \Longleftarrow (etc). This
% might plausibly be useful while checking that the interface can render
% all TeX built-in keywords properly. Furthermore I allow extra args, so
% that eg texsym(stackrel,f,texsym(longrightarrow)) turns into
%   \stackrel{f}{\longrightarrow}

put('texsym,'fancy!-prifn,'fancy!-texsym);

symbolic procedure fancy!-texsym u;
    begin
      if null u then return;
      fancy!-prin2 list!-to!-string ('!\ . explode2 cadr u);
      u := cddr u;
      while u do <<
         fancy!-line!* := "{" . fancy!-line!*;
         fancy!-maprint(car u, 0);
         fancy!-line!* := "}" . fancy!-line!*;
         u := cdr u >>
    end;

% texstring("arbitrary tex stuff",...)
% where atoms (eg strings and words) are just passed to tex but
% more complicated items go through fancy!-maprint.

put('texstring,'fancy!-prifn,'fancy!-texstring);

symbolic procedure fancy!-texstring u;
    for each s in cdr u do <<
      if not atom s then fancy!-maprint(s, 0)
      else <<
         if not stringp s then s := list!-to!-string explode2 s;
         fancy!-line!* := s . fancy!-line!* >> >>;

% texbox(h) is a box of given height (in points)
% texbox(h, d) is a box of given height and depth
%              height is amount above the reference line, depth is amount
%              below.
% textbox(h, d, c) is a box of given size with some specified content

% All these draw a frame around the space used so you can see what is
% goin on.

% The idea that this may be useful when checking how layouts cope with
% various sizes of content, eg big delimiters, square root signs etc. So I
% can test with "for i := 10:40 do write sqrt(texbox(i))" etc.
% to test sqrt with arguments of height 10, 11, ... to 40 points. Note that
% certainly with the CSL version the concept of a "point" is a bit vauge!
% However if I were to imagine that my screen was at 75 pixels per inch I
% could with SOME reason interpret point as meaning pixel, and that is
% what I will do. At present what I might do about hard-copy output is
% pretty uncertain. If height and depth are given as 0 and there is a
% content them the content will define the box size.

put('texbox,'fancy!-prifn,'fancy!-texbox);

symbolic procedure fancy!-texbox u;
    begin
      scalar height, depth, contents;
      contents := nil;
      u := cdr u;
      height := car u;
      u := cdr u;
      if u then <<
         depth := car u;
         u := cdr u;
         if u then contents := car u >>;
      if not numberp height then height:=0;
      if not numberp depth then depth:=0;
      if height=0 and depth=0 and null content then height:=10;
      fancy!-princ "\fbox{";
      if height neq 0 or depth neq 0 then << % insert a rule
         fancy!-line!* := "\rule" . fancy!-line!*;
         if depth neq 0 then <<
            fancy!-line!* := "[-" . fancy!-line!*;
            fancy!-line!* := depth . fancy!-line!*;
            fancy!-line!* := "pt]" . fancy!-line!* >>;
         fancy!-line!* := "{0pt}{" . fancy!-line!*;
         fancy!-line!* := (height+depth) . fancy!-line!*;
         fancy!-line!* := "pt}" . fancy!-line!* >>;
      if contents then fancy!-maprint(contents, 0)
      else fancy!-line!* := "\rule{10pt}{0pt}" . fancy!-line!*;
      fancy!-princ "}"
    end;

% texfbox is a simplified version of texbox, and just draws a box around the
% expression it is given.

put('texfbox,'fancy!-prifn,'fancy!-texfbox);

symbolic procedure fancy!-texfbox u;
    begin
      fancy!-princ "\fbox{";
      fancy!-maprint(cadr u, 0);
      fancy!-princ "}"
    end;



endmodule;

module promptcolor;
% Adapted from Prompt coloring for redfront.

global '(lispsystem!*);

fluid '(promptstring!* tm_switches!* tm_switches!-this!-sl!* lessspace!*);

fluid '(!*promptnumbers);
switch promptnumbers; 

!#if (member 'csl lispsystem!*)
% With CSL I want tmprint loaded all the time and so making this decision
% when texmacs is LOADED is not useful.
!#else
if texmacsp() then % We don't want prompt numbers in a Texmacs worksheet
   off1 'promptnumbers
else
   on1 'promptnumbers;
!#endif

tm_switches!* := {!*msg,!*output};

off1 'msg;
off1 'output;

procedure tm_bprompt();
   % Begin of prompt.
   {int2id 2,'c,'h,'a,'n,'n,'e,'l,'!:,'p,'r,'o,'m,'p,'t,int2id 5,
      int2id 2,'l,'a,'t,'e,'x,'!:,'!\,'b,'r,'o,'w,'n,'! ,
      '!R,'e,'d,'u,'c,'e};

procedure tm_eprompt();
   % End of prompt
   {'!\ ,int2id 5};

% This always gets a list of the characters that make up the prompt...
procedure tm_coloredp(ec);
      eqcar(ec, car tm_bprompt());

procedure tm_nconcn(l);
   % Taken from rltools.
   if cdr l then nconc(car l,tm_nconcn cdr l) else car l;

symbolic procedure tm_prunelhead(l, l1);
    if null l or null l1 then l else tm_prunelhead(cdr l, cdr l1);

procedure tm_pruneltail(l,l1);
   reversip tm_prunelhead(reversip l,l1);

procedure tm_pslp();
   'psl memq lispsystem!*;

if tm_pslp() then <<
   tm_switches!-this!-sl!* := {!*usermode};
   off1 'usermode
>>;

procedure tm_color(c);
   % Color prompt. This will handle EITHER an identifier OR a string, and
   % it returns the same sort of object. It wraps tm_bprompt() and
   % tm_eprompt() around the text it is passed.
   begin scalar ec, sf;
      if stringp c then <<
               ec := string!-to!-list c;
               sf := t >>
      else ec := explode2 c;   % Original code has explode not explode2 here.
      ec := '!  . ec; % add space
      if not !*promptnumbers then % strip numbers from prompt
               while memq(car ec,'(!  !0 !1 !2 !3 !4 !5 !6 !7 !8 !9)) do
            ec := cdr ec;
      ec := append(tm_bprompt(), append(ec, tm_eprompt()));
      ec := list!-to!-string ec;
      if sf then return ec
      else return intern ec
   end;
               
procedure tm_uncolor(c);
   % Uncolor prompt.
   begin scalar ec, sf;
      if stringp c then <<
           ec := string!-to!-list c;
           sf := t >>
       else ec := explode2 c;  % cf explode?
       if not tm_coloredp ec then return c;
       ec := tm_prunelhead(ec, tm_bprompt());
       if car ec eq '!  then ec := cdr ec; % strip space
       ec := tm_pruneltail(ec, tm_eprompt());
       ec := list!-to!-string ec;
       if sf then return ec
       else return intern ec
   end;

procedure tm_setpchar!-psl(c);
   begin scalar w;
      w := tm_setpchar!-orig c;
      promptstring!* := tm_color promptstring!*;
      return tm_uncolor w
   end;

!#if (memq 'csl lispsystem!*)

switch redfront_mode;

% I do not think there is any merit in even defining this if I am not
% using CSL.

procedure tm_setpchar!-csl(c);
% With CSL in many cases the system does prompt colouring at a lower level
% in the code, so the stuff here is not necessary. However if CSL is used
% with an external redfront of texmacs interface I will want to activate
% this special stuff. So I provide a switch redfront_mode that controls
% what I do. I expect to run with this module loaded almost all of the time
% which is why I want a control via switch rather than through just
% "load tmprint". I note that if CSL is loaded from a script that attaches it
% to redfront of som eother interface that the invocation can use
%      -D*redfront_mode
% to preset the switch, which ought to be a small enough burden to be
% tolerable!
   if !*redfront_mode or
      member('texmacs, lispsystem!*) then
      tm_uncolor tm_setpchar!-orig tm_color c
   else tm_setpchar!-orig c; 

!#endif

copyd('tm_setpchar!-orig,'setpchar);

if tm_pslp() then
   copyd('setpchar,'tm_setpchar!-psl)
else
   copyd('setpchar,'tm_setpchar!-csl);

procedure tm_yesp!-psl(u);
   begin scalar ifl,ofl,x,y;
      if ifl!* then <<
         ifl := ifl!* := {car ifl!*,cadr ifl!*,curline!*};
         rds nil
      >>;
      if ofl!* then <<
         ofl:= ofl!*;
          wrs nil
      >>;
      if null !*lessspace then
          terpri();
      if atom u then
          prin2 u
      else
          lpri u;
      if null !*lessspace then
          terpri();
      y := setpchar "?";
      x := yesp1();
      setpchar y;
      if ofl then wrs cdr ofl;
      if ifl then rds cadr ifl;
      cursym!* := '!*semicol!*;
      return x
   end;

if tm_pslp() then <<
   remflag('(yesp),'lose);
   copyd('tm_yesp!-orig,'yesp);
   copyd('yesp,'tm_yesp!-psl);
   flag('(yesp),'lose)
>>;

% Color PSL prompts, in case user falls through:

procedure tm_compute!-prompt!-string(count,level);
   tm_color tm_compute!-prompt!-string!-orig(count,level);

if tm_pslp() then <<
   copyd('tm_compute!-prompt!-string!-orig,'compute!-prompt!-string);
   copyd('compute!-prompt!-string,'tm_compute!-prompt!-string)
>>;
   
procedure tm_break_prompt();
   <<
      prin2 "break["; prin2 breaklevel!*; prin2 "]";
      promptstring!* := tm_color promptstring!*
   >>;

if tm_pslp() then <<
   remflag('(break_prompt),'lose);
   copyd('break_prompt,'tm_break_prompt);
   flag('(break_prompt),'lose);
>>;

if tm_pslp() then
   onoff('usermode,car tm_switches!-this!-sl!*);

onoff('msg,car tm_switches!*);
onoff('output,cadr tm_switches!*);

crbuf!* := nil;
inputbuflis!* := nil;
lessspace!* := t;
statcounter := 0;

endmodule;
    
end;
