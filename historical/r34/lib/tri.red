off echo; symbolic;
% ======================================================================
%           T h e  T e X - R e d u c e - I n t e r f a c e
% ======================================================================
% (C) 1987/1988 by Rechenzentrum der Universitaet zu Koeln
%                  (University of Cologne Computer Center)
%                  Abt. Anwendungssoftware
%                  (Application Software Department)
%                  ATTN: Werner Antweiler
%                  Robert-Koch-Str. 10
%                  5000 Koeln 41
%                  Federal Republic of Germany
%                  E-Mail: reduce@rrz.Uni-Koeln.DE
% All rights reserved.  Permission to copy without fee all  or  part  of
% this  software  product is hereby granted provided that the copies are
% not made or distributed for direct commercial  advantage,  this  copy-
% right notice and its date appear,  and notice is given that copying is
% by permission of the authors.  To copy otherwise requires a fee and/or
% specific permission.  This  software  product  has  been  developed by
% WERNER ANTWEILER  at the  University of Cologne Computer Center,  West
% Germany. The TeX-Reduce-Interface  has been totally written in REDUCE-
% LISP and has been tested and implemented on following machines:
%             CYBER 962     (NOS/VE)
%             MicroVAX II   (Ultrix)
% ======================================================================
% Last Update: 05-Mar-90                                    Version 0.50
% ======================================================================
%
%                              Section Survey
% ----------------------------------------------------------------------
% Section Contents                                                  Page
% ----------------------------------------------------------------------
% 0       Main Procedure (and Interfacing)                             2
% 1       Creating a TeX item list                                     5
% 1.1     Operator Administration Routines                             5
% 1.2     Prefix to Infix Conversion                                   6
% 1.3     Making a TeX item                                            9
% 2       Inserting Glue Items                                        16
% 3       Line Breaking                                               18
% 3.1     Resolving Fraction Expressions                              20
% 3.2     Creating a Break List                                       21
% 3.3     Major Line Breaking Routine                                 23
% 4       TeX-Output Routines                                         28
% 5       User Interface                                              30
% ----------------------------------------------------------------------
% Note: page breaks (form feeds) are indicated by "%ff" lines
%ff
% ----------------------------------------------------------------------
% Section 0: Global Variables, Main Procedure and Interfacing
% ----------------------------------------------------------------------

% IMPORTANT NOTICE FOR REDUCE 3.2 USERS:
% This code was written to run under REDUCE 3.3.   Users  of  REDUCE 3.2
% therefore  have  to change two lines of this code before compiling it:
% 1) the line `switch ...;` must be deleted
% 2) the construct `FOR EACH ... IN ... JOIN ...` must be changed
%    to `FOR EACH ... IN ... CONC ...` because only the latter is
%    accepted by REDUCE 3.2.
% Furthermore,  the TRI supports features of REDUCE that are new in ver-
% sion 3.3. You cannot take advantage of them under version 3.2. In parti-
% cular,  some of the examples in the accompanying test file may fail.

global '(
% -----------------+---------------------------------------------------+
% GLOBAL VARIABLES | EXPLANATION                                       |
% -----------------+---------------------------------------------------+
  !*TeX            % flag to be switched ON and OFF (TeX Output Mode)
  !*TeXBreak       % flag to be switched ON and OFF (Break Facility)
  !*TeXIndent      % flag to be switched ON and OFF (Indentation Mode)
  TeXstack!*       % stack to save expressions for an unfilled line
  hsize!*          % total page width in scaled points (sp)
                   % note: 65536sp = 1pt = 1/72.27 inch
  hss!*            % total line stretchability/shrinkability (in sp)
  hww!*            % optimum page fit width (= 3/4 hsize)    (in sp)
  tolerance!*      % value within break points are considered to be
                   % feasible  (range: 0..10000)
  metricu!*        % ??
  indxl!*          % ??
% -----------------+---------------------------------------------------+
);

% declare switches:
switch TeX,TeXBreak,TeXIndent;

% declare switch dependencies:
put('TeXIndent,'simpfg,'((T (progn (setq !*TeX T)
                                   (setq !*TeXBreak T)))  ));
put('TeXBreak,'simpfg,'((T (setq !*TeX T)) ));
put('TeX,'simpfg,'((NIL (progn (setq !*TeXBreak NIL)
                               (setq !*TeXIndent NIL))) ));

symbolic procedure tri!-error(strlst,errclass);
<< for each x in strlst do prin2 x; terpri();
   if errclass='fatal then
      rederr "Aborting."
>>;
%ff
symbolic procedure varpri(u,v,w);
% parameters: u ..... expression to be printed
%             v ..... a list of expressions assigned to <u>
%             w ..... a flag (true if <u> is last in current set)
begin
   scalar x;
   if null u then u:=0; % allow for unset array elements
   if !*NERO and (u=0) then return;
   v:=setvars v;
   if !*TeX then return if (x := getrtype u) and get(x,'TeXprifn)
                           then apply3(get(x,'TeXprifn),u,v,w)
                         else TeXvarpri(u,v,w);
   if (x:=getrtype u) and flagp(x,'SPRIFN)
   then return if null v then apply1(get(get(x,'TAG),'PRIFN),u)
                         else maprin list('SETQ,car v,u);
   if w memq '(FIRST ONLY) then terpri!*(T);
   if !*FORT then return fvarpri(u,v,w);
   if v then u:='SETQ . ACONC(V,U);
   maprin u;
   if null w or (w eq 'FIRST) then return nil
   else if not !*NAT then prin2!*("$");
   terpri!*(not !*NAT); return(nil)
end;

symbolic procedure TeXvarpri(u,v,w); % same parameters as above
<< if w memq '(FIRST ONLY) then TeXStack!*:=nil; u:=makeprefix u;
   if v then for each x in reverse v do u:=list('SETQ,x,u);
   TeXStack!* := nconc(TeXStack!*,mktag(u,0,nil));
   if (w=T) or (w='ONLY) or (w='LAST) then
   << if !*TeXBreak then
      << TeXStack!* := insertglue(TeXStack!*);
         TeXStack!* := trybreak(TeXStack!*,breaklist(TeXStack!*))
      >>;
      TeXout(TeXStack!*,!*TeXBreak); TeXStack!*:=nil
   >>;
   if (null w) or (w eq 'FIRST) then
     TeXStack!* := nconc(TeXStack!*,list '!\!q!u!a!d! );
   nil
>>;
%ff
% The following procedure interfaces to E. Schruefer's EXCALC package.
% Courtesy: E. Schruefer.

put('form!-with!-free!-indices,'TeXprifn,'TeXindxpri);

symbolic procedure TeXindxpri(u,v,w);
   begin scalar metricu,il,dnlist,uplist,r,x,y,z;
     if v then go to a;
     metricu := metricu!*;
     metricu!* := nil;
     il := allind !*t2f lt numr simp0 u;
     for each j in il do
          if atom revalind j
             then uplist := j . uplist
           else dnlist := cadr j . dnlist;
         for each j in intersection(uplist,dnlist) do
             il := delete(j,delete(revalind
                                  lowerind j,il));
         metricu!* := metricu;
     y := flatindxl il;
     r := simp!* u;
     for each j in mkaindxc y do
       <<x := pair(y,j);
     z := exc!-mk!*sq2 multsq(subfindices(numr r,x),1 ./ denr r);
        if null(!*nero and (z = 0))
          then TeXvarpri(z,list subla(x,'ns . il),'only)>>;
     return u;
  a: v := car v;
     y := flatindxl allindk v;
     for each j in if flagp(car v,'antisymmetric) and
                      coposp cdr v then comb(indxl!*,length y)
                    else mkaindxc y do
       <<x := pair(y,j);
         z := aeval subla(x,v);
         if null(!*nero and (z = 0))
            then TeXvarpri(z,list subla(x,v),'only)>>;
      return u
    end;
%ff
% ----------------------------------------------------------------------
% Section 1: Creating a TeX item list
% ----------------------------------------------------------------------
%
% Linearization is performed by expanding REDUCE prefix expressions into
% a so called "TeX item list".  Any TeX item is a readable TeX primitive
% or macro (i.e. a LISP atom), with properties 'CLASS, 'TEXTAG, 'TEXNAME
% and eventually 'TEXPREC, 'TEXPATT and 'TEXUBY bound to them, depending
% on what kind of TeX item it actually is.  (See Section 1.3 for further
% information.)
%    A REDUCE expression is expanded using the two  functions  "mktag"
% and "makefunc". Function "mktag" identifies the operator and is able
% to put some brackets around the expression if necessary. "makefunc" is
% a pattern oriented 'unification' function, which matches the arguments
% of a REDUCE expression in order of appearance with so called 'unifica-
% tion tags',  as explained below.   "mktag" and "makefunc" are highly
% recursive functions.
%    The patterns mentioned above are lists (consisting of 'tags') asso-
% ciated with each REDUCE operator.   A tag is defined as either an atom
% declared  as  a  TeX item  or one of the following 'unification tags':
%    (F)  ............ insert operator
%    (X)  ............ insert non-associative argument
%    (Y)  ............ insert (left/right-) associative argument
%    (Z)  ............ insert superscript/subscript argument
%    (R)  ............ use tail recursion to unify remaining arguments
%                      (associativity depends on previous (X) or (Y) )
%    (L)  ............ insert a list of arguments (eat up all arguments)
%    (M)  ............ insert a matrix (and eat up all arguments)
%    (APPLY <fun>) ... apply function <fun> to remaining argument list
% ----------------------------------------------------------------------

symbolic procedure makeprefix(ex); % change to standard list notation
(lambda aexpr;                     % not tricky but time consuming
  (if atom aexpr then aexpr
   else if car(aexpr)='MAT
     then 'MAT . (for each column in cdr aexpr collect
                  for each row in column collect prepsq!* simp row)
   else if car(aexpr)='LIST
     then 'LIST . (for each item in cdr aexpr collect makeprefix item)
   else if car(aexpr)='EQUAL
     then 'EQUAL .(for each item in cdr aexpr collect makeprefix item)
     else prepsq!* simp aexpr))
 aeval ex;

% ----------------------------------------------------------------------
% Section 1.1: Operator Administration Routines
% ----------------------------------------------------------------------

symbolic procedure makeop(op,prec,patt,uby);
<< put(op,'TEXPREC,prec); put(op,'TEXPATT,patt);
   put(op,'TEXUBY,if uby then (car uby).(cadr uby) else nil.nil)
>>;

symbolic procedure makeops(l);
for each w in l do makeop(car w,cadr w,caddr w,cadddr w);
%ff
makeops('(
%-----------+----------+---------------------+-------------------------+
% Name      |Precedence|Expansion List       |Unary/Binary Interchange |
%-----------+----------+---------------------+-------------------------+
(SETQ             1     ((X) (F) !\![ (X) !\!]) NIL)
(EQUAL           50     ((X) (F) !\![ (X) !\!]) NIL)
(WEDGE          150     ((Y) (F) (R))           NIL)           % EXCALC
(PLUS           100     ((Y) (F) (R))           (MINUS DIFFERENCE))
(MINUS          600     ((F) (Y))               NIL)
(DIFFERENCE     100     ((Y) (F) (X))           NIL)
(TIMES          200     ((Y) (F) (R))           (RECIP QUOTIENT))
(RECIP          700     ((F) !1 !}!{ (Z) !})    NIL)
(QUOTIENT       200     ((F) (Z) !}!{ (Z) !})   NIL)
(EXPT           850     ((X) !^!{ (Z) !})       NIL)
(SQRT           800     ((F) !  !  !  (Z) !})   NIL)
(MAT            999     ((F) (M !\!c!r!  !&) !}) NIL)
(LIST           999     (!\!{ (L !\CO! ) !\!})  NIL)
(DF             999     ((APPLY makeDF))        NIL)
(INT            999     ((F) (Z) !\!, !d (Z))   NIL)
(SUM            999     ((F) !_!{ (Z) != (Z)
                         !}!^!{ (Z) !} (X))     NIL)
(PROD           999     ((F) !_!{ (Z) != (Z)
                         !}!^!{ (Z) !} (X))     NIL)
(PARTDF         999     ((F) (APPLY makePARTDF)) NIL)          % EXCALC
(D              999     (!\!d!  (X))            NIL)           % EXCALC
(INNERPROD      999     (!\!< (L !,) !\!>)      NIL)           % EXCALC
%-----------+----------+----------------------+------------------------+
));

% ----------------------------------------------------------------------
% Section 1.2 : Prefix to Infix Conversion
% ----------------------------------------------------------------------

symbolic procedure mktag(tag,prec,assf);
% analyze an operator and decide what to do
% parameters: tag ....... the term itself
%             prec ...... outer precedence
%             assf ...... outer associativity flag
if null tag then nil else
if atom tag then texexplode(tag) else
begin
  scalar tagprec,term;
  tagprec:=get(car tag,'TEXPREC) or 999; % get the operator's precedence
  term:=makefunc(car tag,cdr tag,tagprec); % expand expression and if it
  % is necessary, put a left and a right bracket around the expression.
  if (assf and (prec = tagprec)) or (tagprec < prec)
  then term:=nconc('!\!( . term , '!\!) . nil);
  return(term)
end;

symbolic procedure makearg(l,s);
% collect arguments from a list <l> and put seperators <s> between them
if null l then nil
else if null cdr l then mktag(car l,0,nil)
     else nconc(mktag(car l,0,nil), s . makearg(cdr l,s));

symbolic procedure makemat(m,v,h);
% make a matrix <m> and use  <h> as a horizontal seperator and <v> as
% a vertical terminator.
if null m then nil else nconc(makearg(car m,h), v . makemat(cdr m,v,h));
%ff
smacro procedure istag(v,w); car v=w;
smacro procedure unary(uby);  car uby;
smacro procedure binary(uby); cdr uby;
smacro procedure lcopy(a); for each x in a collect x;

symbolic procedure makefunc(op,arg,prec);
begin
  scalar term,tag,a,pattern,uby;
  term:=nil;
  pattern:=get(op,'TEXPATT)
           or ( if flagp(op,'INDEXVAR) then '((APPLY makeExcInx)) 
                                       else '( (F) !\!( (L !,) !\!) ));
  uby:=get(op,'TEXUBY);
  while pattern do
  << tag:=car pattern; pattern:=cdr pattern;
     if (atom tag) then a:=tag.nil
     else if (not atom car tag) then a:=nil
     else if istag(tag,'F) then
       % test for unary to binary operator interchange
       if (not atom car arg)and uby and (caar arg=unary(uby))
       then << a:=texexplode(binary(uby)); arg:=cadar arg.cdr arg >>
       else a:=texexplode(op)
     else if istag(tag,'APPLY)
          then << a:=apply3(cadr tag,op,arg,prec); arg:=nil >>
     else if null arg then a:=nil
     else if istag(tag,'X)
          then << a:=mktag(car arg,prec,nil); arg:=cdr arg >>
     else if istag(tag,'Y)
          then << a:=mktag(car arg,prec,T); arg:=cdr arg >>
     else if istag(tag,'Z)
          then << a:=mktag(car arg,0,nil); arg:=cdr arg >>
     else if istag(tag,'R) then
       if cdr arg % more than one argument ?
       then << pattern:=get(op,'TEXPATT); a:=nil >>
       else << a:=mktag(car arg,prec,nil); arg:=cdr arg >>
     else if istag(tag,'L)
          then << a:=makearg(arg,cadr tag); arg:=nil >>
     else if istag(tag,'M)
          then << a:=makemat(arg,cadr tag,caddr tag); arg:=nil >>
     else a:=nil;
     if a then term:=nconc(term,a)
  >>;
  return(term)
end;
%ff
symbolic procedure makeDF(op,arg,prec); % DF operators are tricky
begin
  scalar dfx,f,vvv; integer degree;
  dfx:=lcopy(f:=texexplode op); degree:=0;
  nconc(dfx,mktag(car arg,prec,nil)); dfx:=nconc(dfx,list '!}!{);
  for each item in cdr arg do
    if numberp(item) then
    << dfx:= nconc(dfx,'!^!{ .texexplode(item));
       dfx:= nconc(dfx,list '!});
       degree:=degree+item-1;
    >>
    else
    << dfx:= nconc(dfx,append(f,mktag(item,prec,nil))); degree:=degree+1
    >>;
  if degree>1 then
  << vvv:=nconc(texexplode(degree), '!} . cdr dfx);
     rplacd(dfx,'!^!{ . vvv)
  >>;
  return ('!\!f!r!a!c!{ . nconc(dfx, list '!}))
end;

symbolic procedure makePARTDF(op,arg,prec); % EXCALC extension
if cdr arg then
  ('!_!{ . nconc(makearg(cdr arg,'!,), '!} . mktag(car arg,prec,nil)))
else ('!_!{ . nconc(mktag(car arg,prec,nil), list '!}));

smacro procedure InxExtend(item,ld,rd);
  nconc(result,ld.nconc(texexplode(item),list rd));

symbolic procedure makeExcInx(op,arg,prec); % EXCALC extension
begin scalar result;
  result:=nconc('!{.nil,texexplode(op));
  for each item in arg do
    if numberp item then
       if minusp item then  InxExtend(-item,'!{!}!_!{,'!})
       else                 InxExtend(item ,'!{!}!^!{,'!}) else
    if atom item then       InxExtend(item ,'!{!}!^!{,'!}) else
    if car item='MINUS then InxExtend(cadr item ,'!{!}!_!{,'!})
    else                    InxExtend('! ,'!{!}!_!{,'!});
  return nconc(result,'!}.nil)
end;
%ff
% ----------------------------------------------------------------------
% Section 1.3 : Making a TeX Item
% ----------------------------------------------------------------------
% Properties of TeX items:
%   'CLASS ..... one of the following class specifiers
%      'ORD .... ordinary symbols
%      'LOP .... large operators
%      'BIN .... binary operators
%      'REL .... relational operators
%      'OPN .... opening symbols (left parenthesis)
%      'CLO .... closing symbols (right parenthesis)
%      'PCT .... punctuation symbols
%      'INN .... inner TeX group delimiters
%  'TEXTAG ..... one of the following lists or atoms
%      <kind> .. an atom describing an 'INN class group delimiter
%      (<w1> <w2> <w3>) ... where is
%                <w1> ..... width for text style        (cmmi10)
%                <w2> ..... width for scriptstyle       (cmmi8)
%                <w3> ..... width for scriptscriptstyle (cmmi5)
% The parital lists of the list which is passed to makeitems have the
% following general structure:
%  (<TeX-item> <class> <TeX-tag> <v1> <v2> ... )
%  where is
%      <TeX-item> .... the atom which actually is the TeX code
%      <class> ....... the 'CLASS property as explained above
%      <TeX-tag> ..... the 'TEXTAG property as explained above
%      <v1> etc. ..... atoms which will be bound to specific TeX items
%                      by its property 'TEXNAME
% ----------------------------------------------------------------------

smacro procedure triassert(name,item); put(name,'TEXNAME,item);
smacro procedure assertl(l); for each v in l do triassert(car v,cadr v);
smacro procedure retract(name); put(name,'TEXNAME,nil);
smacro procedure retractl(l); for each v in l do retract(car v);
smacro procedure gettexitem(a); get(a,'TEXNAME) or (get(a,'CLASS)and a);

put ('TeXitem,'STAT,'RLIS); % handle argument passing for func. TeXitem

symbolic procedure TeXitem(arglist);
begin scalar x,OK,item,class,tag;
  if not length(arglist)=3
  then rederr "Usage: TeXitem(item,class,width-list);";
  item:=first arglist; class:=second arglist; tag:=third arglist;
  OK:=memq(class,'(ORD BIN REL PCT OPN CLO LOP));
  if not OK then << prin2 "% illegal item class "; print class >>;
  if atom tag then OK:=nil else
  << if car(tag)='LIST then tag:=cdr tag; % accept algebraic lists
     for each x in tag do if not numberp x then OK:=nil
  >>;
  if not OK then << prin2 "% illegal width tag "; print tag >>;
  if OK then
  << item:=intern(item); put(item,'CLASS,class); put(item,'TEXTAG,tag)
  >>;
  prin2 "% Item "; prin2 item;
  if not OK then prin2 "not "; prin2 " added"; terpri();
  return nil
end;
%ff
symbolic procedure makeitems(l);
for each w in l do
  begin scalar iw;
   iw:=intern(car w);
   put(iw,'CLASS,cadr w); put(iw,'TEXTAG,caddr w);
   for each v in cdddr w do triassert(v,iw);
  end;

fluid '(TeXunknowncounter!*);
TeXunknowncounter!*:= 0;

symbolic procedure UnknownItem(a);
<< TeXunknowncounter!* := TeXunknowncounter!* +1;
   prin2 "% non-fatal error: unknown atom "; prin2 a;
   prin2 " replaced by ?_{"; prin2 TeXunknowncounter!*;
   prin2 "}"; terpri(); 
   '!? . '!_!{ . nconc(explode TeXunknowncounter!*, list '!})
>>;

symbolic procedure texexplode(a);
begin scalar b;
  b:=if a and (atom a) then
     (gettexitem(a)
      or if numberp(a) then texcollect(explode(a))
         else if stringp(a) then strcollect(explode2(a))
         else texexplist(texcollect(explode2(a))));
   b:=if null b then list '!  else if not atom b then b else list b;
   return b
end;

symbolic procedure texcollect(l);
  for each el in l join 
    if null gettexitem(el) then UnknownItem(el)
    else gettexitem(el).nil;

smacro procedure strtexitem(e);
  if e='!  then '!\! 
  else if liter(e) then e
       else gettexitem(e) or UnknownItem(e) or '! ;

symbolic procedure strcollect(l);
  for each el in l collect strtexitem el;

symbolic procedure texexplist(r);
begin scalar r,v;
  v:=nil;
  for each rl on r do
    if digit(car rl) and not v then v:=rl
    else if v and not digit(car rl) then v:=nil;
  if v then
  << rplacd(v,car v.cdr v); rplaca(v,'!_!{); nconc(r,'!}.nil) >>;
  return r
end;
%ff
makeitems('(
  (!                    INN     DMY)   % no nonsense dummy item
  (!{                   INN     BEG)   % begin of a TeX inner group
  (!^!{                 INN     SUP)   % superscript
  (!_!{                 INN     SUB)   % subscript nolimits
  (!{!}!^!{             INN     SUP)   % spread superscript
  (!{!}!_!{             INN     SUB)   % spread subscript
  (!}!{                 INN     SEP)   % general group seperator
  (!}!^!{               INN     ESP)   % end of group and superscript
  (!}!_!{               INN     ESB)   % end of group and subscript
  (!}                   INN     END)   % end of TeX inner group
  (!\!f!r!a!c!{         INN     FRC    RECIP QUOTIENT)  % fraction group
  (!\!s!q!r!t!{         INN     FRC    SQRT)            % square root
  (!\!p!m!a!t!r!i!x!{   INN     MAT    MAT)             % matrix group
  (!&                   INN     TAB)   % horizontal tabulation
  (!\!c!r!              INN     CR )   % vertical tabulation
  (!\!n!l!              INN     CR )   % vertical tabulation (special)
  (!\!(                 OPN     (327680 276707 241208)) % test value
  (!\!)                 CLO     (327680 276707 241208)) % ...
  (!\!{                 OPN     (327680 276707 241208)) % ...
  (!\!}                 CLO     (327680 276707 241208)) % ...
  (!\![                 OPN     (0))
  (!\!]                 CLO     (0))
  (!\!<                 OPN     (254863 212082 195700))
  (!\!>                 CLO     (254863 212082 195700))
  (!\!,                 ORD     (80960))
  (!\!q!u!a!d!          REL     (655360))
  (!                    ORD     (0)) % dummy item
  (!!                   ORD     (182045 148367 131984))
  (!?                   ORD     (309476 247127 211630))
  (!\!l!b!r!a!c!e!      ORD     (327681 268516 241211) !{)
  (!\!r!b!r!a!c!e!      ORD     (327681 268516 241211) !})
  (!\!l!b!r!a!c!k!      ORD     (182045 148367 131984) ![)
  (!\!r!b!r!a!c!k!      ORD     (182045 148367 131984) !])
  (!\!b!a!c!k!s!l!a!s!h!   ORD  (327681 268516 241211) !\)
  (!\!%                 ORD     (546135 430537 359544) !%)
  (!\!#                 ORD     (546135 430537 359544) !#)
  (!\!&                 ORD     (509726 402320 336788) !&)
  (!@                   ORD     (509726 402320 336788))
  (!\!_                 ORD     (235930) !_)
  (!\!$                 ORD     (327681 261235 223008) !$)
  (!;                   ORD     (182045 148367 131984))
  (!:                   ORD     (182045 148367 131984))
  (!.                   ORD     (182045 148367 131984))
  (!,                   ORD     (182045 148367 131984))
  (!|                   ORD     (182045 148367 131984))
  (!'                   ORD     (183865 177267))
  (!`                   ORD     (182045 148367 131984))
  (!\!                  ORD     (218453))
%ff
% Fonts  ammi10, ammi7, ammi5; ordered by index number
  (!\!G!a!m!m!a!        ORD     (394126 317121 266467))
  (!\!D!e!l!t!a!        ORD     (546133 451470 377742))
  (!\!T!h!e!t!a!        ORD     (481689 395400 331866))
  (!\!L!a!m!b!d!a!      ORD     (418702 346612 293546))
  (!\!X!i!              ORD     (447374 366819 309020))
  (!\!P!i!              ORD     (553870 446190 368185))
  (!\!S!i!g!m!a!        ORD     (511090 417791 348842))
  (!\!U!p!s!i!l!o!n!    ORD     (382293 320398 275342))
  (!\!P!h!i!            ORD     (436906 364088 309475))
  (!\!P!s!i!            ORD     (419430 354622 304150))
  (!\!O!m!e!g!a         ORD     (461596 382217 322806))
  (!\!a!l!p!h!a!        ORD     (419233 350253 299280))
  (!\!b!e!t!a!          ORD     (370688 303376 259231))
  (!\!g!a!m!m!a!        ORD     (353318 296277 256227))
  (!\!d!e!l!t!a!        ORD     (273066 229467 203070))
  (!\!e!p!s!i!l!o!n!    ORD     (266012 222822 197791))
  (!\!z!e!t!a!          ORD     (223686 195060 178221))
  (!\!e!t!a!            ORD     (352407 300373 261688))
  (!\!t!h!e!t!a!        ORD     (298553 247580 216177))
  (!\!i!o!t!a!          ORD     (231955 198883 180224))
  (!\!k!a!p!p!a!        ORD     (377590 315392 271246))
  (!\!l!a!m!b!d!a!      ORD     (382293 320398 275342))
  (!\!m!u!              ORD     (394885 326314 278528))
  (!\!n!u!              ORD     (341940 283534 244849))
  (!\!x!i!              ORD     (327680 276707 241208))
  (!\!p!i!              ORD     (370293 312456 270222))
  (!\!r!h!o!            ORD     (329728 269699 232379))
  (!\!s!i!g!m!a!        ORD     (361737 300646 258776))
  (!\!t!a!u!            ORD     (250083 220910 200430))
  (!\!u!p!s!i!l!o!n!    ORD     (354076 299008 259413))
  (!\!p!h!i!            ORD     (390485 322764 275888))
  (!\!c!h!i!            ORD     (410055 334506 283534))
  (!\!p!s!i!            ORD     (426894 357262 304924))
  (!\!o!m!e!g!a!        ORD     (407931 339968 290360))
  (!\!v!a!r!e!p!s!i!l!o!n!  ORD (312433 358776 225097))
  (!\!v!a!r!t!h!e!t!a!  ORD     (388513 326997 281713))
  (!\!v!a!r!p!i!        ORD     (504945 424800 359719))
  (!\!v!a!r!r!h!o!      ORD     (329728 369699 232379))
  (!\!v!a!r!s!i!g!m!a!  ORD     (312433 258776 225097))
  (!\!v!a!r!p!h!i!      ORD     (465123 383749 323675))
  % omitted: codes 40-47
  (!0   ORD     (327680 276707 241208))
  (!1   ORD     (327680 276707 241208))
  (!2   ORD     (327680 276707 241208))
  (!3   ORD     (327680 276707 241208))
  (!4   ORD     (327680 276707 241208))
  (!5   ORD     (327680 276707 241208))
  (!6   ORD     (327680 276707 241208))
  (!7   ORD     (327680 276707 241208))
  (!8   ORD     (327680 276707 241208))
  (!9   ORD     (327680 276707 241208))
  (!.   PCT     (182044 160198 150186) CONS)
  (!,   REL     (182044 160198 150186))
  (!\CO!  REL   (182044 160198 150186))
%ff
  % omitted: code 60
  (!/   BIN     (327680 262143 204800))
  % omitted : codes 62,63
  (!\!p!a!r!t!i!a!l!    ORD     (384341 314982 268105)  PARTDF DF)
  (!A   ORD     (491520 404866 339057))
  (!B   ORD     (497095 406550 339569))
  (!C   ORD     (542583 439273 363451))
  (!D   ORD     (542583 439273 363451))
  (!E   ORD     (468400 387026 326360))
  (!F   ORD     (412330 331684 277845))
  (!G   ORD     (515276 418884 348660))
  (!H   ORD     (544768 439409 363520))
  (!I   ORD     (288085 236475 204913))
  (!J   ORD     (371825 302512 257706))
  (!K   ORD     (556373 450104 371598))
  (!L   ORD     (446008 369914 312888))
  (!M   ORD     (635790 512227 420408))
  (!N   ORD     (526563 424846 352142))
  (!O   ORD     (499893 409964 343244))
  (!P   ORD     (420750 341242 286606))
  (!Q   ORD     (518098 424527 354622))
  (!R   ORD     (482417 399041 335644))
  (!S   ORD     (392760 323128 274887))
  (!T   ORD     (382976 318122 272270))
  (!U   ORD     (447465 366409 309179))
  (!V   ORD     (375011 304014 260266))
  (!W   ORD     (577991 469310 389973))
  (!X   ORD     (533845 433811 359651))
  (!Y   ORD     (388210 317485 270506))
  (!Z   ORD     (429170 352256 397642))
  % omitted: codes 91-96
  (!a   ORD     (346415 291999 253770))
  (!b   ORD     (281258 235383 207621))
  (!c   ORD     (283610 240571 212810))
  (!d   ORD     (341105 277890 242392))
  (!e   ORD     (283610 240571 212810))
  (!f   ORD     (320853 260778 224369))
  (!g   ORD     (300980 247580 215995))
  (!h   ORD     (377590 315392 271246))
  (!i   ORD     (231500 191601 174762))
  (!j   ORD     (238933 198883 177493))
  (!k   ORD     (341181 296265 248490))
  (!l   ORD     (195546 169756 157468))
  (!m   ORD     (575411 479687 402318))
  (!n   ORD     (393367 334051 288540))
  (!o   ORD     (317667 264510 230377))
  (!p   ORD     (329728 277435 242392))
  (!q   ORD     (292560 245577 215995))
  (!r   ORD     (277466 235292 208668))
  (!s   ORD     (307200 253041 219818))
  (!t   ORD     (234837 204799 186595))
  (!u   ORD     (375163 319487 277162))
  (!v   ORD     (317667 269881 236657))
  (!w   ORD     (463303 386389 327680))
  (!x   ORD     (361813 296732 253951))
  (!y   ORD     (321308 273066 239388))
  (!z   ORD     (304772 257137 225735))
  % omitted: codes 123-127
%ff
  % Fonts amsy10, amsy7, amsy5; not ordered.
  (!+           BIN     (509724 422343 354986)  PLUS)
  (!-           BIN     (509724 422343 354986)  DIFFERENCE MINUS)
  (!*           ORD     (509724 422343 354986))
  (!"           ORD     (509724 422343 354986))
  (!\!c!d!o!t!  BIN     (182044 160198 150186)  TIMES)
  (!=           REL     (509724 422343 354986)  EQ EQUAL)
  (!:!=         REL     (691771 550687 468772)  SETQ)
  (!\!s!u!m!    LOP     (1000000 700000 500000)  SUM)
  (!\!p!r!o!d!  LOP     (1000000 700000 500000)  PROD)
  (!\!i!n!t!    LOP     (1000000 700000 500000)  INT)
  (!\!l!i!m!    ORD     (910221 771866 678114)  LIM)
  (!\!s!i!n!    ORD     (804635 687398 612123)  SIN)
  (!\!c!o!s!    ORD     (877454 745653 657634)  COS)
  (!\!t!a!n!    ORD     (946630 800994 700869)  TAN)
  (!\!l!n!      ORD     (700000 600000 500000)  LOG)
  (!\!e!x!p!    ORD     (1001243 844685 735003)  EXP)
  (!\!a!r!c!t!a!n!  ORD (1824539 1543734 1356227)  ATAN)
  (!\!w!e!d!g!e!    ORD (436908 353167 309480) WEDGE)
  (!\!d!        ORD     (364090))
));
%ff
% ----------------------------------------------------------------------
% You  can  choose  to  have  some  default  TEXNAME properties for your
% variables.  Function "trimakeset" defines a set of such default names.
% If  you want to activate the set,  call "TeXassertset(<setname>)" , or
% if  you want to deactivate the set,  call "TeXretractset(<setname>)" .
% The current <setname>s available are:
%    *     GREEK    : lowercase greek letters
%    *     LOWERCASE: roman lowercase letters
% ----------------------------------------------------------------------
% handle argument passing
deflist( '((TeXassertset RLIS) (TeXretractset RLIS)), 'STAT);

symbolic procedure TeXassertset(arglist);
if not length(arglist)=1 then rederr "Usage: TeXassertset(setname);"
else begin scalar sym; sym:=first arglist;
  if get('TEXSYM,sym) then
  << assertl(get('TEXSYM,sym)); prin2 "% set ";
     prin2 sym; prin2 " asserted"; terpri()
  >> else << prin2 "% no such set"; terpri() >>
end;

symbolic procedure TeXretractset(arglist);
if not length(arglist)=1 then rederr "Usage: TeXretractset(setname);"
else begin scalar sym; sym:=first arglist;
  if get('TEXSYM,sym) then
  << retractl(get('TEXSYM,sym)); prin2 "% set ";
     prin2 sym; prin2 " retracted"; terpri()
  >> else << prin2 "% no such set"; terpri() >>
end;

symbolic procedure trimakeset(sym,a!_set);
   <<put('TEXSYM,sym,a!_set); nil>>;

trimakeset('GREEK,'(
  (ALPHA        !\!a!l!p!h!a!   )
  (BETA         !\!b!e!t!a!     )
  (GAMMA        !\!g!a!m!m!a!   )
  (DELTA        !\!d!e!l!t!a!   )
  (EPSILON      !\!e!p!s!i!l!o!n! )
  (ZETA         !\!z!e!t!a!     )
  (ETA          !\!e!t!a!       )
  (THETA        !\!t!h!e!t!a!   )
  (IOTA         !\!i!o!t!a!     )
  (KAPPA        !\!k!a!p!p!a!   )
  (LAMBDA       !\!l!a!m!b!d!a! )
  (MU           !\!m!u!         )
  (NU           !\!n!u!         )
  (XI           !\!x!i!         )
  (PI           !\!p!i!         )
  (RHO          !\!r!h!o!       )
  (SIGMA        !\!s!i!g!m!a!   )
  (TAU          !\!t!a!u!       )
  (UPSILON      !\!u!p!s!i!l!o!n! )
  (PHI          !\!p!h!i!       )
  (CHI          !\!c!h!i!       )
  (PSI          !\!p!s!i!       )
  (OMEGA        !\!o!m!e!g!a!   ) ));
trimakeset('LOWERCASE,'(
  (A !a) (B !b) (C !c) (D !d) (E !e) (F !f) (G !g) (H !h) (I !i) (J !j)
  (K !k) (L !l) (M !m) (N !n) (O !o) (P !p) (Q !q) (R !r) (S !s) (T !t)
  (U !u) (V !v) (W !w) (X !x) (Y !y) (Z !z) ));
%ff
% ----------------------------------------------------------------------
% Section 2: Inserting Glue into a TeX-Item-List
% ----------------------------------------------------------------------
%
% Glue Items to be inserted between consecutive TeX-Items (similar to
% what TeX does with its items, but this table is slightly modified.)
%
%    Class|ORD|LOP|BIN|REL|OPN|CLO|PCT|INN|
%    -----+---+---+---+---+---+---+---+---+
%    ORD  | 0 | 1 |(2)|(3)| 0 | 0 | 0 | 0 |
%    LOP  | 1 | 1 | * |(3)| 0 | 0 | 0 |(1)|
%    BIN  |(2)|(2)| * | * |(2)| * | * |(2)|
%    REL  |(3)|(3)| * | 0 |(3)| 0 | 0 |(3)|     columns: right items
%    OPN  | 0 | 0 | * | 0 | 0 | 0 | 0 | 0 |     lines:   left items
%    CLO  | 0 | 1 |(2)|(3)| 0 | 0 | 0 | 0 |
%    PCT  |(1)|(1)| * |(1)|(1)|(1)|(1)|(1)|
%    INN  | 0 | 1 |(2)|(3)|(1)| 0 |(1)| 0 |
%    -----+---+---+---+---+---+---+---+---+
%
% The glue items and its meanings:
%   0 ......... no space
%   1 (1) ..... thin space   (no space if sub-/superscript)
%   2 (2) ..... medium space (no space if sub-/superscript)
%   3 (3) ..... thick space  (no space if sub-/superscript)
%   * ......... this case never arises (really?)
% ----------------------------------------------------------------------

symbolic procedure makeglue(mx);
if null mx then nil else
begin
  scalar id1,id2,row,col;
  row:=cdr mx; id1:=car mx;
  while(row) do
  << id2:=car mx; col:=car row;
     while (col) do
     << put(car id1,car id2,car col);
        col:=cdr col; id2:=cdr id2
     >>;
     row:=cdr row; id1:=cdr id1
  >>
end;

makeglue('(
(ORD LOP BIN REL OPN CLO PCT INN)
( 0   1  -2  -3   0   0   0   0 )
( 1   1   0  -3   0   0   0  -1 )
(-2  -2   0   0  -2   0   0  -2 )
(-3  -3   0   0  -3   0   0  -3 )
( 0   0   0   0   0   0   0   0 )
( 0   1  -2  -3   0   0   0   0 )
(-1  -1   0  -1  -1  -1  -1  -1 )
( 0   1  -2  -3  -1   0  -1   0 )
));

smacro procedure kindof(item);  get(item,'TEXTAG);
smacro procedure classof(item); get(item,'CLASS);
%ff
smacro procedure groupbeg(kind); % beginning of a group
  memq(kind,'(BEG SUP SUB FRC MAT));
smacro procedure groupend(kind); (kind='END);
smacro procedure grouphs(kind);  (kind='TAB);
smacro procedure groupvs(kind); % vertical group seperator
  memq(kind,'(ESP ESB SEP CR));

symbolic procedure interglue(left,right,depth,nesting);
% compute the glue to be inserted between two TeX items
% parameters: left,right .......... left/right TeX item
%             depth ............... superscript/subscript level
%             nesting ............. depth of parenthesis level
% a glue item is a list consisting of two numbers, i.e.
%            (<width> <penalty>)
% where <width> is the width of the glue in scaled points and <penalty>
% is a negative numeric value indicating 'merits' for a breakpoint.
if (null left)or(null right)or(not atom left)or(not atom right) then nil
else begin
  scalar glue,lc,rc; % glue code and item classes
  lc:=classof(left); rc:=classof(right); glue:=get(lc,rc);
  if null(glue) then return nil;
  if (left='!\CO! ) then return(list(0,-10000));
  if glue<0 then if depth>0 then return nil else glue:=(-glue);
  if glue=1 then return(list(80960,nesting*10 +20))
  else if glue=2 then
  << if (left='!+ or left='!-) then return nil;
     if (right='!+) then return(list(163840,nesting*30-390));
     if (right='!- and (lc='ORD or lc='CLO))
     then return(list(163840,nesting*30-210));
     if (left='!\!c!d!o!t! ) then return(list(163840,nesting*10+50));
     if (right='!\!c!d!o!t! ) then return nil;
     return(list(163840,nesting*10))
  >>
  else if glue=3 then return(list(655360,nesting*10-50)) else return nil
end;

symbolic procedure insertglue(term);
% insert glue into a TeX-Item-List
begin
  scalar glueitem,succ,pred,prev,backup; integer depth,nesting;
  depth:=nesting:=0; succ:=nil; backup:=term;
  while term do
  << pred:=succ; succ:=car term;
     glueitem:=interglue(pred,succ,depth,nesting);
     if glueitem then rplacd(prev,glueitem.term);
     prev:=term; term:=cdr term;
     if classof(succ)='INN then
     << if (groupbeg kindof succ) and
           (not ((kindof(succ)='FRC) and (depth=0)))
        then depth:=depth+1
        else if (groupend kindof succ) and (depth>0) then depth:=depth-1
     >>
     else if classof(succ)='OPN then nesting:=nesting+1
     else if classof(succ)='CLO then nesting:=nesting-1
  >>;
  return(backup)
end;
%ff
% ----------------------------------------------------------------------
% Section 3 : Line Breaking
% ----------------------------------------------------------------------
%
%     How to break up a TeX item list into several independent lines
% ----------------------------------------------------------------------
% Setting break points requires "breaklists". A  breaklist is a sequence
% of passive and active nodes,  where each active node is followed by an
% pasive node and vice versa. Active nodes represent glue items. Passive
% nodes are integer atoms which represent the width of a sequence of or-
% dinary  TeX  items.   This sequence must not be interspersed with glue
% items.  Every breaklist consists of at least one passive node surroun-
% ded by delta nodes representing the beginning and ending of the list.
%     <breaklist>    ::= ( <delta-node> <passive-node> <active-node> ...
%                                       <passive-node> <active_node> ...
%                                       <passive-node> <delta-node>)
%     <active-node>  ::= ( <width> <penalty> <offset> )
%     <passive-node> ::= <width>
%     <delta-node>   ::= ( <width> <penalty> <offset> 
%                          <id-num> <ptr> <demerits> <indentation> )
% The breaklist will be created using the function "breaklist".  Setting
% the break points (i.e. break items) in the breaklist is done using the
% functions "trybreak".  During  this  phase, some active nodes are con-
% sidered to be "feasible" break points. Thus, they will be extended and
% named "delta nodes" furtheron. By default the first and last node in a
% breaklist are delta nodes.  When trybreak has finished, the <ptr>'s of
% the delta nodes recursively pointed to  from  the  last  delta  node's
% <ptr> represent the best path for breaking the whole breaklist.
% It is:
%   <width>      : width of item (including glue items)
%   <penalty>    : a numeric value which prohibits line breaking (if
%                  negative, line breaking will be merited)
%   <offset>     : distance to most previous opening bracket
%   <id-num>     : the identity number of the delta node {1,2,3,...}
%   <ptr>        : pointer to the best delta node to come from with
%                  respect to the minimal demerits path. note: a zero
%                  pointer indicates the very bottom of the stack
%   <demerits>   : total demerits distance to delta node which is
%                  pointed to by <ptr>
%   <indentation>: amount of indentation when breaking at this point
% ----------------------------------------------------------------------
%ff
symbolic procedure width(item,style);
begin scalar tag;
   tag:=get(item,'TEXTAG);
   if null tag then tri!-error(list("cannot find item ",item),'fatal);
   while (style>0)and(cdr tag) do << tag:=cdr tag; style:=style-1 >>;
   return car tag or 0
end;

smacro procedure sp2mm(x); (x/186468); % scaled points to millimeters

symbolic procedure settolerance(tol);
<< if tol<0 then tol:=0 else if tol>10000 then tol:=10000;
   prin2 "% \tolerance "; print tol; tolerance!*:=tol; nil
>>;
symbolic procedure setpagewidth(hsize);
% hsize can be given either in millimeters or scaled points.
<< if hsize>400 then hsize!*:=hsize else hsize!*:=hsize*186468;
   prin2 "% \hsize="; prin2 sp2mm(hsize!*); prin2 "mm"; terpri();
   hss!*:=float hsize!*/6;      % default stretch/shrink width
   hww!*:=float (3*hsize!*)/4;  % optimum line width
>>;
symbolic procedure setbreak(hsize,tol);
<< settolerance(tol); setpagewidth(hsize) >>;

smacro procedure badness(hlen,ibadness);
% The badness is 100*(hlen/hss)**3, corrected for indentation badness
begin
  real r;
  r:=abs(hlen-hww!*)/hss!*;
  return fix min(10000.0,r*r*r*100.0+ibadness)
end;

smacro procedure isglue(l);         (not atom l) and (numberp car l);
smacro procedure isactive(x);       not numberp x;
smacro procedure ispassive(x);      numberp x;
smacro procedure isdelta(x);        cdddr x;
smacro procedure addup(x);          if x then eval('PLUS.x) else 0;
smacro procedure tpush(stack,item); stack:=item.stack;

smacro procedure tpop(stack);
  if null stack then nil % Error
  else begin scalar z; z:=car stack; stack:=cdr stack; return(z) end;

smacro procedure poke(stack,ptr,val);
if null ptr then stack:=nconc(stack,val.nil)
else << if val>car(ptr) then rplaca(ptr,val); ptr:=cdr ptr >>;

smacro procedure concatenate(l);
begin scalar r;
  for each e in l do r:=nconc(r,explode e);
  return compress r
end;
%ff
% ----------------------------------------------------------------------
% Section 3.1:  Resolving Fraction Expressions
% ----------------------------------------------------------------------

symbolic procedure resolve(term);
% resolve a  \frac{...}{...}  sequence and transform it into a   .../...
% sequence, where any ... argument may become parenthesized depending on
% the question if there is any non-ORD-class item within this argument.
% Furthermore, resolve a \sqrt{...} expression to \(...\)^{\frac{1}{2}}.
begin
  scalar item,l,m,r,lflag,rflag;
  integer depth;
  l:=term;                            % save pointer to functor
  depth:=0; m:=r:=lflag:=rflag:=nil; item:=T;
  while term and item do
  << item:=car term;                  % take first item from list
     if classof(item)='INN then       % check inner class item
     << item:=kindof(item);
        if groupbeg(item) then depth:=depth+1
        else if groupend(item) then
          if depth=1 then             % outermost level ?
          << r:=term; item:=nil       % save pointer to right bracket
          >>                          % and quit using item as a flag
          else depth:=depth-1
        else if groupvs(item) then    % if outermost level then save
         if (depth=1) then m:=term    % pointer to intermediate brackets
     >>
     else if not(classof(item)='ORD) then % non-ORD-class item ?
     << if m then rflag:=T else lflag:=T
     >>;
     term:=cdr term                   % step ahead
  >>;
  if car l='!\!f!r!a!c!{ then
  << if lflag and rflag
       then item:=list('!/,list(655360,-10000))
       else item:=list('!/);
     if lflag then << rplaca(l,'!\!(); item:='!\!).item >>
     else rplaca(l,'! );
     if rflag then << rplaca(r,'!\!)); nconc(item,'!\!(.nil) >>
     else rplaca(r,'! );
     rplaca(m,car item); item:=cdr item;
     if item then rplacd(m,nconc(item,cdr m))
  >> else if car l='!\!s!q!r!t!{ then
  << rplaca(l,'!\!(); rplaca(r,'!\!));
     rplacd(r,'!^!{ .  '!1 . '!/ . '!2 . '!} . cdr r)
  >>;
  return(l)                           % return changed list pointer
end;
%ff
% ----------------------------------------------------------------------
% Section 3.2 : Create a Break List
% ----------------------------------------------------------------------

symbolic procedure breaklist(term);
begin
  scalar item,result,kind,vstack,hstack,fstack,pstack,p,flag,backup;
  integer depth,acc,aux,LOPw,total,indent;
  p:=result:=vstack:=hstack:=fstack:=nil; backup:=term;
  depth:=total:=acc:=LOPw:=indent:=0;
  while term do
  << item:=car term; flag:=T;              % get first item from term
     if null item
     then TRI!-error(list("found NIL in term : ",backup),'fatal);
     if (isglue(item)) then                % do we have glue ahead ?
       if (depth<1) then                   % are we on the top level ?
       << % insert a passive node followed by an active node, clear acc.
          total:=total+acc+car item; nconc(item,indent.nil);
          result:=nconc(result,acc.item.nil); acc:=0
       >>
       else acc:=acc+car item              % add up glue width
     else if (classof(item)='LOP) then LOPw:=width(item,depth)
     else if classof(item)='INN then
       << kind:=kindof(item);
          if kind='FRC then
          << tpush(fstack,term); tpush(fstack,depth)
          >>;
          if groupend(kind) then           % end of TeX group ?
          << depth:=depth-1;               % decrement term depth
             if acc>0                      % if <acc> hasn't been poked
             then poke(vstack,p,acc);      % yet, then poke it
             acc:=tpop(hstack);            % get old acc value
             aux:=addup(vstack);           % compute vstack width
             if fstack and (depth=car fstack) then
             << tpop(fstack);              % first waste depth info
                if aux>hww!* then          % check if it doesn't fit
                << term:=resolve tpop fstack;% resolve fraction
                   flag:=nil               % evaluate new list
                >>
                else                       % waste fraction term pointer
                << tpop(fstack); acc:=acc+aux
                >>
             >> else acc:=acc+aux;
             p:=tpop(hstack); vstack:=tpop(hstack) % reset old status
          >>
          else if groupbeg(kind) then      % begin of TeX group ?
          << depth:=depth+1;               % increment term depth
             tpush(hstack,vstack);         % save current <vstack> and
             tpush(hstack,p);              % current <p> as well as
             tpush(hstack,acc);            % current <acc> to <hstack>
             acc:=0; p:=vstack:=nil;       % clear vertical stack
             if LOPw>0 then poke(vstack,p,LOPw); LOPw:=0
          >>
          else if grouphs(kind) then       % horizontal separator ?
          << poke(vstack,p,acc); acc:=0    % poke <acc> to <vstack>
          >>
          else if groupvs(kind) then       % vertical separator ?
          << poke(vstack,p,acc); acc:=0; p:=vstack % reset
          >>
       >>
%ff
     else if depth<1 then
     << aux:=width(item,depth);            % add up item width
        if classof(item)='OPN then
        << tpush(pstack,indent); indent:=total+acc+aux
        >>;
        if classof(item)='CLO then indent:=tpop(pstack) or 0;
        acc:=acc+aux
     >>
     else acc:=acc+width(item,depth);      % add up item width
     if LOPw>0 then << acc:=acc+LOPw; LOPw:=0 >>;
     if flag then term:=cdr term
  >>;
  if acc then total:=total+acc;
  if (total<hsize!*) then return nil % need no breaking
  else return(list(0,0,0,0,0,0,0).nconc(result,acc.
        list(0,0,total,-1,0,2147483647,0).nil))     % return break list
end;

%ff
% ----------------------------------------------------------------------
% Section 3.3 : Major Line Breaking Routine
% ----------------------------------------------------------------------

smacro procedure widthof(deltanode);   car deltanode;
smacro procedure penaltyof(deltanode); cadr deltanode;
smacro procedure totalof(deltanode);   cadr deltanode;
smacro procedure offsetof(deltanode);  caddr deltanode;
smacro procedure idof(deltanode);      cadddr deltanode;
smacro procedure ptrof(deltanode);     car cddddr deltanode;
smacro procedure indentof(deltanode);  caddr cddddr deltanode;
smacro procedure tailof(deltanode);    cddddr deltanode;

symbolic procedure offsetitem(item);
  concatenate list('!\!o!f!f!{,item,'!} );

smacro procedure stepahead(ptr,val);
<< if ispassive car ptr then val:=val+car ptr else val:=val+caar ptr;
   ptr:=cdr ptr
>>;

smacro procedure findindent(offt,ptr);
if offt=lastoff and ptr=lastptr then lastindent else
begin % search the deltastack for previous indentation
  scalar node,p,stack; integer tot;
  stack:=deltastack; p:=lastptr:=ptr; lastoff:=offt;
  while stack do
  << if p=idof (node:=car stack) then
     << p:=ptrof node; tot:=totalof node;
        if tot<offt then stack:=nil
     >>;
     if stack then stack:=cdr stack;
  >>;
  return(lastindent:=offt-tot+indentof node)
end;
%ff
symbolic procedure trybreak(term,brkl);
% parameters: term .... TeX item list, as created by "interglue"
%             brkl .... the breaklist to be processed by this routine
begin
  scalar bottom,top,base,item,deltastack,pred;
  integer depth;               % depth of expression when rebuilding
  integer feasible,id;         % number of feasible delta node
  integer len,total;           % current and total length so far
  integer dm,basedm;           % current and base demerits
  integer bd;                  % current badness
  integer penalty;
  integer offset,baseoffset;   % current and base parenthesis offset
  integer baseptr;             % pointer to best way to come from
  integer indent,baseindent;   % current and base indentation
  integer lastoff,lastindent,lastptr; % temp. var. for speedup
  real indentbadness;          % correction for indentation badness
  if null brkl then goto retain;
  bottom:=brkl;
  lastoff:=lastptr:=lastindent:=feasible:=indent:=total:=0;
  while bottom do
  << top:=cdr bottom; base:=car bottom; pred:=tailof base;
     id:=idof base;            % id of current delta node
     if penaltyof base=-10000  % break item ?
     then rplaca(cdr pred,0);  % new line
     basedm:=cadr pred;        % demerits so far
     % save the delta node to the delta-stack. thus deltastack holds
     % all the feasible breakpoints in reverse order.
     deltastack:=base.deltastack;
     len:=baseindent:=indentof(base); % indentation for this line
     indentbadness:=2500.0*(float(baseindent)/float(hww!*));
     baseoffset:=offsetof base;% current offset amount
     baseptr:=car pred;        % pointer to best node to come from
     total:=total+widthof base;% correct total length
%--- debug ---
% prin2 "Base ["; prin2 id; prin2 "] basedm="; prin2 basedm;
% prin2 " ibd="; prin2 indentbadness;
% prin2 " indent="; prin2 baseindent; terpri();
%--- debug ---
%ff
     while top and len<hsize!* do % loop once thru a potential line
     % note that we use the local hsize instead of the full hsize
     << item:=car top;
        if ispassive(item) then len:=len+item else
        << bd:=badness(len,indentbadness);
           penalty:=penaltyof item;
           offset:=offsetof item;
           if (bd<tolerance!*)       % is the breakpoint feasible?
           or (bd+penalty<1)         % got a break bonus ?
           or (null cdr top) then    % or did we reach last delta node?
           << dm:=bd*bd+basedm+penalty*abs(penalty);
              if isdelta(item) then
              << pred:=tailof item;
                 if dm<cadr pred then % found a better path?
                 << % save the pointer to best breakpoint to come from
                    % and the minimum demerits to reach it
                    rplaca(pred,id); rplaca(cdr pred,dm);
                    if !*TeXIndent then % save the current indentation
                    << if offset>total
                       then indent:=offset-total+baseindent
                       else if offset<baseoffset
                         then indent:=findindent(offset,baseptr)
                         else indent:=baseindent;
                       rplaca(cddr pred,indent)
                    >>
                 >>
              >>
              else             % create a new delta node
              << feasible:=feasible+1;
                 if !*TeXIndent then
                   if offset>total
                   then indent:=offset-total+baseindent
                   else if offset<baseoffset
                     then indent:=findindent(offset,baseptr)
                     else indent:=baseindent
                 else indent:=0;
                 rplacd(cddr item,feasible.id.dm.indent.nil)
              >>;
%--- debug ---
% prin2 "-->["; prin2 idof item; prin2 "] dm="; prin2 dm;
% prin2 " bd="; prin2 bd; prin2 " p="; prin2 penalty;
% if !*TeXindent then << prin2 " ind="; prin2 indent >>; terpri();
%--- debug ---
              if penalty=-10000 then top:=nil
           >>;
           len:=len+car item   % count the length anyway
        >>;
        if top then top:=cdr top
     >>;
%ff
     rplaca(cdr base,total);   % replace penalty by total width so far
     bottom:=cdr bottom;       % depart from this delta node
     while bottom and (ispassive(car bottom) or not isdelta(car bottom))
     do stepahead(bottom,total); % move to next delta node in list
  >>;
  bottom:=deltastack; feasible:=-1; top:=nil;
  while bottom do              % loop thru the delta-node stack
  << id:=idof car bottom;      % id is the current id number
     if id=feasible then       % is this node the one pointed to?
     << feasible:=ptrof car bottom; % feasible is the new back-pointer
        top:=id.top;           % save the path element
     >>;
     bottom:=cdr bottom        % step ahead
  >>;                          % now deltastack contains the best path
  deltastack:=cdr top;         % in forward order
%--- debug ---
% print term; print deltastack;
%--- debug ---
  if car deltastack= -1 then
  << prin2 "% Warning:    no suitable way of breaking found"; terpri();
     prin2 "% ========    retry with a greater tolerance..."; terpri();
     prin2 "% (output will produce overfull box if printed)"; terpri()
  >>;
  brkl:=cdr brkl;              % strip the dummy node at the list's head
%ff
  % --------------------------------------------------------------------
  % now remove all glue items but retain all break items
  retain: % ------------------------------------------------------------
  offset:=depth:=0; bottom:=term;
  if brkl then brkl:=cdr brkl; % ensure first item is an active node
  while term and (cdr term) do
  << item:=car term;
     if isglue(item) then           % if this is a glue item
       if (depth=0) and brkl then   % and we are on the top level
       << top:=car brkl;
          if isdelta(top) then      % consider delta nodes only
          << if (idof top=car deltastack) then % break point?
             << deltastack:=cdr deltastack;
%--- debug ---
% prin2 "% ["; prin2 idof top; prin2 "] ";
% prin2 sp2mm(totalof(top)+indentof(top)-offset); terpri();
% offset:=totalof(top);
%--- debug ---
                if (len:=indentof top)>0
                then rplacd(pred,'!\!n!l! . offsetitem(len) . cdr term)
                else rplacd(pred,'!\!n!l! . cdr term)
             >>
             else rplacd(pred,cdr term)
          >>
          else rplacd(pred,cdr term);
          if brkl and (cdr brkl)    % check for next active node
          then brkl:=cddr brkl      % skip to next active node
       >>
       else rplacd(pred,cdr term)  % remove glue item
     else if classof(item)='INN then
     << if groupbeg(kindof(item)) then depth:=depth+1 else
        if groupend(kindof(item)) then depth:=depth-1
     >>;
     pred:=term; term:=cdr term
  >>;
%--- debug ---
% top:=car term; prin2 "% [-1] ";
% prin2 sp2mm(totalof(top)+indentof(top)-offset); terpri();
%--- debug ---
  return(bottom)
end;
%ff
% ----------------------------------------------------------------------
% Section 4 : Output of TeX-Code
% ----------------------------------------------------------------------

symbolic procedure TeXstrlen(s);
begin
  integer length;
  scalar flag;
  length:=0; flag:=nil;
  for each c in s do
    if not flag and c='!! then flag:=T
    else << length:=length+1; flag:=nil >>;
  return length
end;

smacro procedure newline();
  if nlflag then cc:=indent
  else if (cc>indent) then << terpri(); cc:=indent; nlflag:=T >>;

%ff
symbolic procedure TeXout(itemlist,flag);
if null itemlist then nil else
begin
   integer cc,len,indent,ccmax,lines;
   scalar item,class,tag,oldtag,lasttag,indentstack,ispd,nlflag;
   ccmax:=64; cc:=indent:=lines:=0;        % initializations
   tag:=ispd:=nlflag:=indentstack:=nil;    % initializations
   prin2('!$!$);                           % begin TeX math group
   if flag then prin2('!\!d!i!s!p!l!a!y!l!i!n!e!s!{!\!q!d!d);
   terpri();                               % start new line
   while itemlist do
   << item:=car itemlist; itemlist:=cdr itemlist;
      len:=TeXstrlen(explode(item)); oldtag:=nil; lasttag:=tag or class;
      class:=classof(item); tag:=(class='INN)and(kindof(item));
      %ispd:=(class='ORD)and itemlist and(classof(car itemlist)='OPN);
      if (tag='MAT)or(tag='FRC)or(class='OPN) %or ispd
      then newline();                      % start new line
      if (groupbeg(tag))or(class='OPN) then
      << tpush(indentstack,indent);        % push it to the stack
         tpush(indentstack,lasttag);       % the reason for pushing
         if (cc+cc < ccmax)                % within left half of page ?
         then if ((class='OPN)and(lasttag='ORD))or % predicate?
                 (groupbeg(tag)and not((tag='FRC)or(tag='MAT)))
           then indent:=cc+len             % take current position
           else indent:=indent+len         % compute new indentation
      >>
      else if (groupend(tag))or(class='CLO) then
      << oldtag:=tpop(indentstack); indent:=tpop(indentstack)
      >>;
      if (cc+len > ccmax) or      % beyond right margin ?
         (item='!+)or(item='!-)or(class='CLO) % important item?
      then newline();
      if nlflag then << nlflag:=nil; spaces(cc) >>;
      if tag='CR  then lines:=lines+1;
      if not(item='! ) then prin2(item);   % print the item and
      cc:=cc+len;                          % count the characters
      if groupvs(tag) or                   % vertical seperator ?
         (groupend(tag) and                % end of a large group,
          ((oldtag='FRC) or (oldtag='MAT)))% i.e. fraction, matrix ?
         or (class='CLO) or                % closing parenthesis ?
         (((class='REL)or(class='BIN))and  % binary/relational operator?
          (cc+cc+cc > ccmax+ccmax))        % within last third of page?
         or item='!,  or null class
      then newline()
   >>;
   newline();                              % start final line
   if flag then
     if lines=0 then prin2('!\!c!r!})
     else prin2('!\!N!l!});                % end multi-line output
   prin2('!$!$); terpri(); return(nil)     % end math group
end;
%ff
% ----------------------------------------------------------------------
% Section 5: User Interface
% ----------------------------------------------------------------------
% handle argument passing for following the functions, compelling that
% properties are used during compile time
deflist( '((TeXdisplay RLIS) (TeXlet RLIS)), 'STAT);

algebraic procedure TeXsetbreak(hsize,tol); lisp setbreak(hsize,tol);
algebraic procedure TeXtolerance(tol); lisp settolerance(tol);
algebraic procedure TeXpagewidth(hsize); lisp setpagewidth(hsize);

symbolic procedure TeXlet(arglist);
begin scalar class,sym,item;
  if not length(arglist)=2 then rederr "Usage: TeXlet(symbol,item);";
  sym:=first arglist; item:=intern second arglist; class:=classof(item);
  if null class then
  << prin2 "% No such TeX symbol available"; terpri()
  >>
  else if (class='INN) then % prevent from TeXequiv'ing inner symbols
  << prin2 "% cannot assign inner TeX symbols yet"; terpri()
  >>
  else triassert(sym,item);
  return nil
end;

symbolic procedure Texdisplay(arglist);
begin scalar item,tag,class;
  if not length(arglist)=1 then rederr "Usage: TeXdisplay(item);";
  item:=get(first arglist,'TEXNAME);
  if not item then
  << prin2 "% "; prin2 first arglist; prin2 " is not defined"; terpri()
  >>;
  if not item then return nil;
  tag:=get(item,'TEXTAG);  class:=get(item,'CLASS);
  prin2 "% TeX item "; prin2 item; prin2 " is of class "; prin2 class;
  prin2 " and has following widths: "; terpri(); prin2 "% ";
  for each w in tag do
  begin real v; v:=w/65536.0; prin2 v; prin2 "pt  " end;
  terpri(); return nil
end;

% ----------------------- share name between both modes ----------------

symbolic operator TeXlet;
symbolic operator TeXitem;
symbolic operator TeXdisplay;
symbolic operator TeXassertset;
symbolic operator TeXretractset;

% ------------------------ Default Initializations ---------------------

<< prin2 "% TeX-REDUCE-Interface 0.50"; terpri() >>;
TeXassertset(GREEK); TeXassertset(LOWERCASE);
TeXtolerance(10); TeXpagewidth(150);

% ***************   E N D   O F   S O U R C E   C O D E   **************
end;
