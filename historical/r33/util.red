module cedit; % REDUCE input string editor.

% Author: Anthony C. Hearn;

fluid '(!*mode);

global '(!$eol!$
         !*blanknotok!*
         !*eagain
         !*full
         crbuf!*
         crbuf1!*
         crbuflis!*
         esc!*
         inputbuflis!*
         rprifn!*
         rterfn!*
         statcounter);


%esc!* := intern ascii 125;   %this is system dependent and defines
                              %a terminator for strings.

symbolic procedure rplacw(u,v);
   if atom u or atom v then errach list('rplacw,u,v)
    else rplacd(rplaca(u,car v),cdr v);

symbolic procedure cedit n;
   begin scalar x,ochan;
      if null terminalp() then rederr "Edit must be from a terminal";
      ochan := wrs nil;
      if n eq 'fn then x := reversip crbuf!*
       else if null n
        then if null crbuflis!*
               then <<statcounter := statcounter-1;
                      rederr "No previous entry">>
              else x := cdar crbuflis!*
       else if (x := assoc(car n,crbuflis!*))
        then x := cedit0(cdr x,car n)
       else <<statcounter := statcounter-1;
              rederr list("Entry",car n,"not found")>>;
      crbuf!* := nil;
      x := for each j in x collect j;   %to make a copy.
      terpri();
      editp x;
      terpri();
      x := cedit1 x;
      wrs ochan;
      if x eq 'failed then nil else crbuf1!* := x
   end;

symbolic procedure cedit0(u,n);
   % Returns input string augmented by appropriate mode.
   begin scalar x;
      if not(x := assoc(n,inputbuflis!*)) or ((x := cddr x) eq !*mode)
        then return u
       else return append(explode x,append(cdr explode '! ,u))
   end;

symbolic procedure cedit1 u;
   begin scalar x,y,z;
      z := setpchar '!>;
      if not !*eagain
        then <<prin2t "For help, type ?"; !*eagain := t>>;
      while u and (car u eq !$eol!$) do u := cdr u;
      u := append(u,list '! );   %to avoid 'last char' problem.
      if !*full then editp u;
    top:
      x := u;   %current pointer position.
    a:
      y := readch();   %current command.
      if y eq 'p or y eq '!p then editp x
       else if y eq 'i or y eq '!i then editi x
       else if y eq 'c or y eq '!c then editc x
       else if y eq 'd or y eq '!d then editd x
       else if y eq 'f or y eq '!f then x := editf(x,nil)
       else if y eq 'e or y eq '!e
        then <<terpri(); editp1 u; setpchar z; return u>>
       else if y eq 'q or y eq '!q then <<setpchar z; return 'failed>>
       else if y eq '!? then edith()
       else if y eq 'b or y eq '!b then go to top
       else if y eq 'k or y eq '!k then editf(x,t)
       else if y eq 's or y eq '!s then x := edits x
       else if y eq '!  and not !*blanknotok!* or y eq 'x or y eq '!x
        then x := editn x
       else if y eq '!  and !*blanknotok!* then go to a
       else if y eq !$eol!$ then go to a
       else lprim!* list(y,"Invalid editor character");
      go to a
   end;

symbolic procedure editc x;
   if null cdr x then lprim!* "No more characters"
    else rplaca(x,readch());

symbolic procedure editd x;
   if null cdr x then lprim!* "No more characters"
    else rplacw(x,cadr x . cddr x);

symbolic procedure editf(x,bool);
   begin scalar y,z;
      y := cdr x;
      z := readch();
      if null y then return <<lprim!* list(z,"Not found"); x>>;
      while cdr y and not z eq car y do y := cdr y;
      return if null cdr y then <<lprim!* list(z,"Not found"); x>>
                else if bool then rplacw(x,car y . cdr y)
                else y
   end;

symbolic procedure edith;
   <<prin2t "THE FOLLOWING COMMANDS ARE SUPPORTED:";
     prin2t "   B              move pointer to beginning";
     prin2t "   C<character>   replace next character by <character>";
     prin2t "   D              delete next character";
     prin2t "   E              end editing and reread text";
     prin2t
    "   F<character>   move pointer to next occurrence of <character>";
     prin2t
       "   I<string><escape>   insert <string> in front of pointer";
     prin2t "   K<character>   delete all chars until <character>";
     prin2t "   P              print string from current pointer";
     prin2t "   Q              give up with error exit";
     prin2t
       "   S<string><escape> search for first occurrence of <string>";
     prin2t "                      positioning pointer just before it";
     prin2t "   <space> or X   move pointer right one character";
     terpri();
     prin2t
       "ALL COMMAND SEQUENCES SHOULD BE FOLLOWED BY A CARRIAGE RETURN";
     prin2t "    TO BECOME EFFECTIVE">>;

symbolic procedure editi x;
   begin scalar y,z;
      while (y := readch()) neq esc!* do z := y . z;
      rplacw(x,nconc(reversip z,car x . cdr x))
   end;

symbolic procedure editn x;
   if null cdr x then lprim!* "NO MORE CHARACTERS"
    else cdr x;

symbolic procedure editp u;
   <<editp1 u; terpri()>>;

symbolic procedure editp1 u;
   for each x in u do if x eq !$eol!$ then terpri() else prin2 x;

symbolic procedure edits u;
   begin scalar x,y,z;
      x := u;
      while (y := readch()) neq esc!* do z := y . z;
      z := reversip z;
  a:  if null x then return <<lprim!* "not found"; u>>
       else if edmatch(z,x) then return x;
      x := cdr x;
      go to a
   end;

symbolic procedure edmatch(u,v);
   % Matches list of characters U against V. Returns rest of V if
   % match occurs or NIL otherwise.
   if null u then v
    else if null v then nil
    else if car u=car v then edmatch(cdr u,cdr v)
    else nil;

symbolic procedure lprim!* u; <<lprim u; terpri()>>;

comment Editing Function Definitions;

remprop('editdef,'stat);

symbolic procedure editdef u; editdef1 car u;

symbolic procedure editdef1 u;
   begin scalar type,x;
      if null(x := getd u) then return lprim list(u,"not defined")
       else if codep cdr x or not eqcar(cdr x,'lambda)
        then return lprim list(u,"cannot be edited");
      type := car x;
      x := cdr x;
      if type eq 'expr then x := 'de . u . cdr x
       else if type eq 'fexpr then x := 'df . u . cdr x
       else if type eq 'macro then x := 'dm . u . cdr x
       else rederr list("strange function type",type);
      rprifn!* := 'add2buf;
      rterfn!* := 'addter2buf;
      crbuf!* := nil;
      x := errorset(list('rprint,mkquote x),t,nil);
      rprifn!* := nil;
      rterfn!* := nil;
      if errorp x then return (crbuf!* := nil);
      crbuf!* := cedit 'fn;
      return nil
   end;

symbolic procedure add2buf u; crbuf!* := u . crbuf!*;

symbolic procedure addter2buf; crbuf!* := !$eol!$ . crbuf!*;

put('editdef,'stat,'rlis);

comment Displaying past input expressions;

put('display,'stat,'rlis);

symbolic procedure display u;
   % Displays input stack in reverse order.
   % Modification to reverse list added by F. Kako.
  begin scalar x,w;
      u := car u;
      x := crbuflis!*;
      terpri();
      if not numberp u then u := length x;
      while u>0 and x do
       <<w := car x . w; x := cdr x; u := u - 1>>;
      for each j in w do
       <<prin2 car j; prin2 ": "; editp cdr j; terpri()>>
  end;

endmodule;


module pretty;  % Print list structures in an indented format.

% Author: A. C. Norman, July 1978.

fluid '(bn
        bufferi
        buffero
        indblanks
        indentlevel
        initialblanks
        lmar
        pendingrpars
        rmar
        rparcount
        stack);

global '(!*quotes !*symmetric thin!*);

!*symmetric := t;
!*quotes := t;
thin!* := 5;

% This package prints list structures in an indented format that
% is intended to make them legible. There are a number of special
% cases recognized, but in general the intent of the algorithm
% is that given a list (R1 R2 R3 ...), SUPERPRINT checks if
% the list will fit directly on the current line and if so
% prints it as:
%        (R1 R2 R3 ...)
% if not it prints it as:
%        (R1
%           R2
%           R3
%           ... )
% where each sublist is similarly treated.
%


% Functions:
%   SUPERPRINTM(X,M)   print expression X with left margin M
%   PRETTYPRINT(X)     = <<superprintm(x,posn()); terpri(); terpri()>>;
%
% Flag:
%   !*SYMMETRIC        If TRUE, print with escape characters,
%                      otherwise do not (as PRIN1/PRIN2
%                      distinction). defaults to TRUE;
%   !*QUOTES           If TRUE, (QUOTE x) gets displayed as 'x.
%                      default is TRUE;
%
% Variable:
%   THIN!*             if THIN!* expressions can be fitted onto
%                      a single line they will be printed that way.
%                      this is a parameter used to control the
%                      formatting of long thin lists. default 
%                      value is 5;


symbolic procedure prettyprint x;
 << superprinm(x,posn()); %WHAT REDUCE DOES NOW;
    terpri();
    terpri();
    nil>>;

symbolic procedure superprintm(x,lmar);
  << superprinm(x,lmar); terpri(); x >>;


% From here down the functions are not intended for direct use.

% The following functions are defined here in case this package
% is called from LISP rather than REDUCE.

symbolic procedure eqcar(a,b);
    pairp a and car a eq b;

symbolic procedure spaces n;
    for i:=1:n do prin2 '! ;

% End of compatibility section.

symbolic procedure superprinm(x,lmar);
  begin
    scalar stack,bufferi,buffero,bn,initialblanks,rmar,
           pendingrpars,indentlevel,indblanks,rparcount,w;
    bufferi:=buffero:=list nil; %fifo buffer.
    initialblanks:=0;
    rparcount:=0;
    indblanks:=0;
    rmar:=linelength(nil)-3; %right margin.
    if rmar<25 then error(0,list(rmar+3,
        "Linelength too short for superprinting"));
    bn:=0; %characters in buffer.
    indentlevel:=0; %no indentation needed, yet.
    if lmar+20>=rmar then lmar:=rmar-21; %no room for specified margin.
    w:=posn();
    if w>lmar then << terpri(); w:=0 >>;
    if w<lmar then initialblanks:=lmar-w;
    prindent(x,lmar+3); %main recursive print routine.
% traverse routine finished - now tidy up buffers.
    overflow 'none; %flush out the buffer.
    return x
  end;


% Access functions for a stack entry.


smacro procedure top; car stack;
smacro procedure depth frm; car frm;
smacro procedure indenting frm; cadr frm;
smacro procedure blankcount frm; caddr frm;
smacro procedure blanklist frm; cdddr frm;
smacro procedure setindenting(frm,val); rplaca(cdr frm,val);
smacro procedure setblankcount(frm,val); rplaca(cddr frm,val);
smacro procedure setblanklist(frm,val); rplacd(cddr frm,val);
smacro procedure newframe n; list(n,nil,0);
smacro procedure blankp char; numberp car char;





symbolic procedure prindent(x,n);
% Print list x with indentation level n.
    if atom x then if vectorp x then prvector(x,n)
        else for each c in 
          (if !*symmetric
             then if stringp x then explodes x else explode x
            else explode2 x) do putch c
    else if quotep x then <<
        putch '!';
        prindent(cadr x,n+1) >>
    else begin
        scalar cx;
        if 4*n>3*rmar then << %list is too deep for sanity.
            overflow 'all;
            n:=n/8;
            if initialblanks>n then <<
                lmar:=lmar-initialblanks+n;
                initialblanks:=n >> >>;
        stack := (newframe n) . stack;
        putch ('lpar . top());
        cx:=car x;
        prindent(cx,n+1);
        if idp cx and not atom cdr x then 
            cx:=get(cx,'ppformat) else cx:=nil;
        if cx=2 and atom cddr x then cx:=nil;
        if cx='prog then <<
            putch '! ;
            prindent(car (x:=cdr x),n+3) >>;
% CX now controls the formatting of what follows:
%    nil      default action
%    <number> first few blanks are non-indenting
%    prog     display atoms as labels.
         x:=cdr x;

   scan: if atom x then go to outt;
         finishpending(); %about to print a blank.
         if cx='prog then <<
             putblank();
             overflow bufferi; %force format for prog.
             if atom car x then << % a label.
                 lmar:=initialblanks:=max(lmar-6,0);
                 prindent(car x,n-3); % print the label.
                 x:=cdr x;
                 if not atom x and atom car x then go to scan;
                 if lmar+bn>n then putblank()
                 else for i:=lmar+bn:n-1 do putch '! ;
                 if atom x then go to outt>> >>
         else if numberp cx then <<
             cx:=cx-1;
             if cx=0 then cx:=nil;
             putch '!  >>
         else putblank();
         prindent(car x,n+3);
         x:=cdr x;
         go to scan;

   outt: if not null x then <<
            finishpending();
            putblank();
            putch '!.;
            putch '! ;
            prindent(x,n+5) >>;
        putch ('rpar . (n-3));
        if indenting top()='indent and not null blanklist top() then
               overflow car blanklist top()
        else endlist top();
        stack:=cdr stack
      end;

symbolic procedure explodes x;
   %dummy function just in case another format is needed.
   explode x;

symbolic procedure prvector(x,n);
  begin
    scalar bound;
    bound:=upbv x; % length of the vector.
    stack:=(newframe n) . stack;
    putch ('lsquare . top());
    prindent(getv(x,0),n+3);
    for i:=1:bound do <<
        putch '!,;
        putblank();
        prindent(getv(x,i),n+3) >>;
    putch('rsquare . (n-3));
    endlist top();
    stack:=cdr stack
  end;

symbolic procedure putblank();
  begin
    putch top(); %represents a blank character.
    setblankcount(top(),blankcount top()+1);
    setblanklist(top(),bufferi . blanklist top());
         %remember where I was.
    indblanks:=indblanks+1
  end;




symbolic procedure endlist l;
%Fix up the blanks in a complete list so that they
%will not be turned into indentations.
     pendingrpars:=l . pendingrpars;

% When I have printed a ')' I want to mark all of the blanks
% within the parentheses as being unindented, ordinary blank
% characters. It is however possible that I may get a buffer
% overflow while printing a string of )))))))))), and so this
% marking should be delayed until I get round to printing
% a further blank (which will be a candidate for a place to
% split lines). This delay is dealt with by the list
% pendingrpars which holds a list of levels that, when
% convenient, can be tidied up and closed out.

symbolic procedure finishpending();
 << for each stackframe in pendingrpars do <<
        if indenting stackframe neq 'indent then
            for each b in blanklist stackframe do
              << rplaca(b,'! ); indblanks:=indblanks-1 >>;
% blanklist of stackframe must be non-nil so that overflow
% will not treat the '(' specially.
        setblanklist(stackframe,t) >>;
    pendingrpars:=nil >>;



symbolic procedure quotep x;
    !*quotes and
    not atom x and
    car x='quote and
    not atom cdr x and
    null cddr x;






% property ppformat drives the prettyprinter -
% prog     : special for prog only
% 1        :    (fn a1
%                  a2
%                  ... )
% 2        :    (fn a1 a2
%                  a3
%                  ... )     ;

put('prog,'ppformat,'prog);
put('lambda,'ppformat,1);
put('lambdaq,'ppformat,1);
put('setq,'ppformat,1);
put('set,'ppformat,1);
put('while,'ppformat,1);
put('t,'ppformat,1);
put('de,'ppformat,2);
put('df,'ppformat,2);
put('dm,'ppformat,2);
put('foreach,'ppformat,4); % (foreach x in y do ...) etc.


% Now for the routines that buffer things on a character by character
% basis, and deal with buffer overflow.


symbolic procedure putch c;
  begin
    if atom c then rparcount:=0
    else if blankp c then << rparcount:=0; go to nocheck >>
    else if car c='rpar then <<
        rparcount:=rparcount+1;
% format for a long string of rpars is:
%    )))) ))) ))) ))) )))   ;
        if rparcount>4 then << putch '! ; rparcount:=2 >> >>
    else rparcount:=0;
    while lmar+bn>=rmar do overflow 'more;
nocheck:
    bufferi:=cdr rplacd(bufferi,list c);
    bn:=bn+1 
  end;

symbolic procedure overflow flg;
  begin
    scalar c,blankstoskip;
%the current buffer holds so much information that it will
%not all fit on a line. try to do something about it.
% flg is one of:
%  'none       do not force more indentation
%  'more       force one level more indentation
% <a pointer into the buffer>
%               prints up to and including that character, which
%               should be a blank.
    if indblanks=0 and initialblanks>3 and flg='more then <<
        initialblanks:=initialblanks-3;
        lmar:=lmar-3;
        return 'moved!-left >>;
fblank:
    if bn=0 then <<
% No blank found - can do no more for now.
% If flg='more I am in trouble and so have to print
% a continuation mark. in the other cases I can just exit.
        if not(flg = 'more) then return 'empty;
        if atom car buffero then
% continuation mark not needed if last char printed was
% special (e.g. lpar or rpar).
            prin2 "%+"; %continuation marker.
        terpri();
        lmar:=0;
        return 'continued >>
    else <<
        spaces initialblanks;
        initialblanks:=0 >>;
    buffero:=cdr buffero;
    bn:=bn-1;
    lmar:=lmar+1;
    c:=car buffero;
    if atom c then << prin2 c; go to fblank >>
    else if blankp c then if not atom blankstoskip then <<
        prin2 '! ;
        indblanks:=indblanks-1;
% blankstoskip = (stack-frame . skip-count).
        if c eq car blankstoskip then <<
            rplacd(blankstoskip,cdr blankstoskip-1);
            if cdr blankstoskip=0 then blankstoskip:=t >>;
        go to fblank >>
      else go to blankfound
    else if car c='lpar or car c='lsquare then <<
        prin2 get(car c,'ppchar);
        if flg='none then go to fblank;
% now I want to flag this level for indentation.
        c:=cdr c; %the stack frame.
        if not null blanklist c then go to fblank;
        if depth c>indentlevel then << %new indentation.
% this level has not emitted any blanks yet.
            indentlevel:=depth c;
            setindenting(c,'indent) >>;
        go to fblank >>
    else if car c='rpar or car c='rsquare then <<
        if cdr c<indentlevel then indentlevel:=cdr c;
        prin2 get(car c,'ppchar);
        go to fblank >>
    else error(0,list(c,"UNKNOWN TAG IN OVERFLOW"));
blankfound:
    if eqcar(blanklist c,buffero) then
        setblanklist(c,nil);
% at least one entry on blanklist ought to be valid, so if I
% print the last blank I must kill blanklist totally.
    indblanks:=indblanks-1;
% check if next level represents new indentation.
    if depth c>indentlevel then <<
        if flg='none then << %just print an ordinary blank.
            prin2 '! ;
            go to fblank >>;
% here I increase the indentation level by one.
        if blankstoskip then blankstoskip:=nil
        else <<
            indentlevel:=depth c;
            setindenting(c,'indent) >> >>;
%otherwise I was indenting at that level anyway.
    if blankcount c>(thin!*-1) then << %long thin list fix-up here.
        blankstoskip:=c . ((blankcount c) - 2);
        setindenting(c,'thin);
        setblankcount(c,1);
        indentlevel:=(depth c)-1;
        prin2 '! ;
        go to fblank >>;
    setblankcount(c,(blankcount c)-1);
    terpri();
    lmar:=initialblanks:=depth c;
    if buffero eq flg then return 'to!-flg;
    if blankstoskip or not (flg='more) then go to fblank;
% keep going unless call was of type 'more'.
    return 'more; %try some more.
  end;

put('lpar,'ppchar,'!();
put('lsquare,'ppchar,'![);
put('rpar,'ppchar,'!));
put('rsquare,'ppchar,'!]);

endmodule;


module rprint;  % The Standard LISP to REDUCE pretty-printer.

% Author: Anthony C. Hearn.

fluid '(!*n buffp combuff curmark curpos orig pretop pretoprinf rmar);

global '(rprifn!* rterfn!*);

comment RPRIFN!* allows output from RPRINT to be handled differently,
        RTERFN!* allows end of lines to be handled differently;

pretop := 'op; pretoprinf := 'oprinf;

symbolic procedure rprint u;
   begin integer !*n; scalar buff,buffp,curmark,rmar,x;
      curmark := 0;
      buff := buffp := list list(0,0);
      rmar := linelength nil;
      x := get('!*semicol!*,pretop);
      !*n := 0;
      mprino1(u,list(caar x,cadar x));
      prin2ox ";";
      omarko curmark;
      prinos buff
   end;

symbolic procedure rprin1 u;
   begin scalar buff,buffp,curmark,x;
      curmark := 0;
      buff := buffp := list list(0,0);
      x := get('!*semicol!*,pretop);
      mprino1(u,list(caar x,cadar x));
      omarko curmark;
      prinos buff
   end;

symbolic procedure mprino u; mprino1(u,list(0,0));

symbolic procedure mprino1(u,v);
   begin scalar x;
        if x := atsoc(u,combuff)
          then <<for each y in cdr x do comprox y;
                 combuff := delete(x,combuff)>>;
      if numberp u and u<0 and (x := get('difference,pretop))
        then return begin scalar p;
        x := car x;
        p := (not car x>cadr v) or (not cadr x>car v);
        if p then prin2ox "(";
        prinox u;
        if p then prinox ")"
       end
       else if atom u then return prinox u
      else if not atom car u 
           then <<curmark := curmark+1;
          prin2ox "("; mprino car u; prin2ox ")";
          omark list(curmark,3); curmark := curmark-1>>
       else if x := get(car u,pretoprinf)
        then return begin scalar p;
           p := car v>0
                 and not car u
                          memq '(block procedure prog quote string);
           if p then prin2ox "(";
           apply(x,list cdr u);
           if p then prin2ox ")"
         end
       else if x := get(car u,pretop)
        then return if car x then inprinox(u,car x,v)
                     else if cddr u then rederr "Syntax error"
                     else if null cadr x then inprinox(u,list(100,1),v)
                     else inprinox(u,list(100,cadr x),v)
       else prinox car u;
      if rlistatp car u then return rlpri cdr u;
      u := cdr u;
      if null u then prin2ox "()"
      else mprargs(u,v)
   end;

symbolic procedure mprargs(u,v);
   if null cdr u then <<prin2ox " "; mprino1(car u,list(100,100))>>
   else inprinox('!*comma!* . u,list(0,0),v);

symbolic procedure inprinox(u,x,v);
   begin scalar p;
      p := (not car x>cadr v) or (not cadr x>car v);
      if p then prin2ox "("; omark '(m u);
      inprino(car u,x,cdr u);
      if p then prin2ox ")"; omark '(m d)
   end;

symbolic procedure inprino(opr,v,l);
   begin scalar flg,x;
      curmark := curmark+2;
      x := get(opr,pretop);
      if x and car x
        then <<mprino1(car l,list(car v,0)); l := cdr l; flg := t>>;
      while l do
        <<if opr eq '!*comma!* then <<prin2ox ","; omarko curmark>>
           else if opr eq 'setq
            then <<prin2ox " := "; omark list(curmark,1)>>
        else if atom car l or not opr eq get!*(caar l,'alt)
        then <<omark list(curmark,1); oprino(opr,flg); flg := t>>;
      mprino1(car l,list(if null cdr l then 0 else car v,
                          if null flg then 0 else cadr v));
         l := cdr l>>;
      curmark := curmark-2
   end;

symbolic procedure oprino(opr,b);
   (lambda x; if null x
                 then <<if b then prin2ox " "; prinox opr; prin2ox " ">>
               else prin2ox x)
   get(opr,'prtch);

symbolic procedure prin2ox u;
   <<rplacd(buffp,explode2 u);
     while cdr buffp do buffp := cdr buffp>>;

symbolic procedure explode2 u;
   % "explodes" atom U without including escape characters;
   if numberp u then explode u
    else if stringp u then reversip cdr reversip cdr explode u
    else explode21 explode u;

symbolic procedure explode21 u;
   if null u then nil
    else if car u eq '!! then cadr u . explode21 cddr u
    else car u . explode21 cdr u;

symbolic procedure prinox u;
   <<rplacd(buffp,explode u);
     while cdr buffp do buffp := cdr buffp>>;

symbolic procedure omark u;
   <<rplacd(buffp,list u); buffp := cdr buffp>>;

symbolic procedure omarko u; omark list(u,0);

symbolic procedure comprox u;
   begin scalar x;
        if car buffp = '(0 0)
          then return <<for each j in u do prin2ox j;
                        omark '(0 0)>>;
        x := car buffp;
        rplaca(buffp,list(curmark+1,3));
        for each j in u do prin2ox j;
        omark x
   end;

symbolic procedure rlistatp u;
   get(u,'stat) member '(endstat rlis);

symbolic procedure rlpri u;
   if null u then nil
    else begin
      prin2ox " ";
      omark '(m u);
      inprino('!*comma!*,list(0,0),u);
      omark '(m d)
   end;

symbolic procedure condox u;
   begin scalar x;
      omark '(m u);
      curmark := curmark+2;
      while u do
        <<prin2ox "IF "; mprino caar u; omark list(curmark,1);
          prin2ox " THEN ";
          if cdr u and eqcar(cadar u,'cond)
                 and not eqcar(car reverse cadar u,'t)
           then <<x := t; prin2ox "(">>;
          mprino cadar u;
          if x then prin2ox ")";
          u := cdr u;
          if u then <<omarko(curmark-1); prin2ox " ELSE ">>;
          if u and null cdr u and caar u eq 't
            then <<mprino cadar u; u := nil>>>>;
      curmark := curmark-2;
      omark '(m d)
   end;

put('cond,pretoprinf,'condox);

symbolic procedure blockox u;
   begin
      omark '(m u);
      curmark := curmark+2;
      prin2ox "BEGIN ";
      if car u then varprx car u;
      u := labchk cdr u;
      omark list(curmark,if eqcar(car u,'!*label) then 1 else 3);
      while u do
        <<mprino car u;
        if not eqcar(car u,'!*label) and cdr u then prin2ox "; ";
        u := cdr u;
        if u
          then omark list(curmark,
                          if eqcar(car u,'!*label) then 1 else 3)>>;
      omark list(curmark-1,-1);
      prin2ox " END";
      curmark := curmark-2;
      omark '(m d)
   end;

symbolic procedure retox u;
   begin
      omark '(m u);
      curmark := curmark+2;
      prin2ox "RETURN ";
      omark '(m u);
      mprino car u;
      curmark := curmark-2;
      omark '(m d);
      omark '(m d)
   end;

put('return,pretoprinf,'retox);

%  symbolic procedure varprx u;
%        mapc(cdr u,function (lambda j;
%                          <<prin2ox car j;
%                          prin2ox " ";
%                          inprino('!*comma!*,list(0,0),cdr j);
%                          prin2ox "; ";
%                          omark list(curmark,6)>>));

comment a version for the old parser;

symbolic procedure varprx u;
   begin scalar typ;
      u := reverse u;
       while u do
        <<if cdar u eq typ
            then <<prin2ox ","; omarko(curmark+1); prinox caar u>>
           else <<if typ then <<prin2ox "; "; omark '(m d)>>;
                prinox (typ := cdar u);
                  prin2ox " "; omark '(m u); prinox caar u>>;
           u := cdr u>>;
      prin2ox "; ";
      omark '(m d)
   end;

put('block,pretoprinf,'blockox);

symbolic procedure progox u;
   blockox(mapcar(reverse car u,function (lambda j; j . 'scalar)) 
        . cdr u);

symbolic procedure labchk u;
   begin scalar x;
      for each z in u do if atom z
        then x := list('!*label,z) . x else x := z . x;
       return reversip x
   end;

put('prog,pretoprinf,'progox);

symbolic procedure gox u;
   <<prin2ox "GO TO "; prinox car u>>;

put('go,pretoprinf,'gox);

symbolic procedure labox u;
   <<prinox car u; prin2ox ": ">>;

put('!*label,pretoprinf,'labox);

symbolic procedure quotox u;
   if stringp u then prinox u else <<prin2ox "'"; prinsox car u>>;

symbolic procedure prinsox u;
   if atom u then prinox u
    else <<prin2ox "(";
           omark '(m u);
           curmark := curmark+1;
        while u do <<prinsox car u;
                        u := cdr u;
                        if u then <<omark list(curmark,-1);
                        if atom u
                          then <<prin2ox " . "; prinsox u; u := nil>>
                         else prin2ox " ">>>>;
           curmark := curmark-1;
           omark '(m d);
        prin2ox ")">>;

put('quote,pretoprinf,'quotox);

symbolic procedure prognox u;
   begin
      curmark := curmark+1;
      prin2ox "<<";
      omark '(m u);
      while u do <<mprino car u; u := cdr u;
                if u then <<prin2ox "; "; omarko curmark>>>>;
      omark '(m d);
      prin2ox ">>";
      curmark := curmark-1
   end;

put('prog2,pretoprinf,'prognox);

put('progn,pretoprinf,'prognox);

symbolic procedure repeatox u;
   begin
      curmark := curmark+1;
      omark '(m u);
      prin2ox "REPEAT ";
      mprino car u;
      prin2ox " UNTIL ";
      omark list(curmark,3);
      mprino cadr u;
      omark '(m d);
      curmark := curmark-1
   end;

put('repeat,pretoprinf,'repeatox);

symbolic procedure whileox u;
   begin
      curmark := curmark+1;
     omark '(m u);
      prin2ox "WHILE ";
      mprino car u;
      prin2ox " DO ";
      omark list(curmark,3);
      mprino cadr u;
      omark '(m d);
      curmark := curmark-1
   end;

put('while,pretoprinf,'whileox);

symbolic procedure procox u;
   begin
      omark '(m u);
      curmark := curmark+1;
      if cadddr cdr u then <<mprino cadddr cdr u; prin2ox " ">>;
      prin2ox "PROCEDURE ";
      procox1(car u,cadr u,caddr u)
   end;

symbolic procedure procox1(u,v,w);
   begin
      prinox u;
      if v then mprargs(v,list(0,0));
      prin2ox "; ";
      omark list(curmark,3);
      mprino w;
      curmark := curmark-1;
      omark '(m d)
   end;

put('proc,pretoprinf,'procox);

symbolic procedure proceox u;
   begin
      omark '(m u);
      curmark := curmark+1;
      if cadr u then <<mprino cadr u; prin2ox " ">>;
      if not caddr u eq 'expr then <<mprino caddr u; prin2ox " ">>;
      prin2ox "PROCEDURE ";
      proceox1(car u,cadddr u,car cddddr u)
   end;

symbolic procedure proceox1(u,v,w);
   begin
      prinox u;
      if v
        then <<if not atom car v then v:= for each j in v collect car j;
               %allows for typing to be included with proc arguments;
               mprargs(v,list(0,0))>>;
      prin2ox "; ";
      omark list(curmark,3);
      mprino w;
      curmark := curmark -1;
      omark '(m d)
   end;

put('procedure,pretoprinf,'proceox);

symbolic procedure proceox0(u,v,w,x);
   proceox list(u,'symbolic,v,
                mapcar(w,function (lambda j; j . 'symbolic)),x);

symbolic procedure deox u;
   proceox0(car u,'expr,cadr u,caddr u);

put('de,pretoprinf,'deox);

symbolic procedure dfox u;
   proceox0(car u,'fexpr,cadr u,caddr u);

%put('df,pretoprinf,'dfox);   %commented out because of confusion with
                              %differentiation;

symbolic procedure stringox u;
   <<prin2ox '!"; prin2ox car u; prin2ox '!">>;

put('string,pretoprinf,'stringox);

symbolic procedure lambdox u;
   begin
      omark '(m u);
      curmark := curmark+1;
      procox1('lambda,car u,cadr u)
   end;

put('lambda,pretoprinf,'lambdox);

symbolic procedure eachox u;
   <<prin2ox "FOR EACH ";
     while cdr u do <<mprino car u; prin2ox " "; u := cdr u>>;
     mprino car u>>;

put('foreach,pretoprinf,'eachox);

symbolic procedure forox u;
   begin
      curmark := curmark+1;
      omark '(m u);
      prin2ox "FOR ";
      mprino car u;
      prin2ox " := ";
      mprino caadr u;
      if cadr cadr u neq 1
        then <<prin2ox " STEP "; mprino cadr cadr u; prin2ox " UNTIL ">>
       else prin2ox ":";
      mprino caddr cadr u;
      prin2ox " ";
      mprino caddr u;
      prin2ox " ";
      omark list(curmark,3);
      mprino cadddr u;
      omark '(m d);
      curmark := curmark-1
   end;

put('for,pretoprinf,'forox);

symbolic procedure forallox u;
   begin
      curmark := curmark+1;
      omark '(m u);
      prin2ox "FOR ALL ";
      inprino('!*comma!*,list(0,0),car u);
      if cadr u
        then <<omark list(curmark,3);
               prin2ox " SUCH THAT ";
               mprino cadr u>>;
      prin2ox " ";
      omark list(curmark,3);
      mprino caddr u;
      omark '(m d);
      curmark := curmark-1
   end;

put('forall,pretoprinf,'forallox);


comment Declarations needed by old parser;

if null get('!*semicol!*,'op)
  then <<put('!*semicol!*,'op,'((-1 0)));
         put('!*comma!*,'op,'((5 6)))>>;


comment RPRINT MODULE, Part 2;

fluid '(orig curpos);

symbolic procedure prinos u;
   begin integer curpos;
        scalar orig;
      orig := list posn();
      curpos := car orig;
      prinoy(u,0);
      terpri0x()
   end;

symbolic procedure prinoy(u,n);
   begin scalar x;
      if car(x := spaceleft(u,n)) then return prinom(u,n)
       else if null cdr x then return if car orig<10 then prinom(u,n)
       else <<orig := 9 . cdr orig;
                terpri0x();
                spaces20x(curpos := 9+cadar u);
                prinoy(u,n)>>
      else begin
        a: u := prinoy(u,n+1);
           if null cdr u or caar u<=n then return;
           terpri0x();
           spaces20x(curpos := car orig+cadar u);
           go to a end;
      return u
   end;

symbolic procedure spaceleft(u,mark);
   %U is an expanded buffer of characters delimited by non-atom marks
   %of the form: '(M ...) or '(INT INT))
   %MARK is an integer;
   begin integer n; scalar flg,mflg;
      n := rmar - curpos;
      u := cdr u;   %move over the first mark;
      while u and not flg and n>=0 do
        <<if atom car u then n := n-1
           else if caar u eq 'm then nil
           else if mark>=caar u then <<flg := t; u := nil . u>>
           else mflg := t;
          u := cdr u>>;
      return ((n>=0) . mflg)
   end;

symbolic procedure prinom(u,mark);
   begin integer n; scalar flg,x;
      n := curpos;
      u := cdr u;
      while u and not flg do
        <<if atom car u then <<x := prin20x car u; n := n+1>>
          else if caar u eq 'm
           then if cadar u eq 'u then orig := n . orig
                 else orig := cdr orig
           else if mark>=caar u
             and not(x='!, and rmar-n-6>charspace(u,x,mark))
            then <<flg := t; u := nil . u>>;
          u := cdr u>>;
      curpos := n;
        if mark=0 and cdr u
          then <<terpri0x();
                 terpri0x();
                 orig := list 0; curpos := 0; prinoy(u,mark)>>;
          %must be a top level constant;
      return u
   end;

symbolic procedure charspace(u,char,mark);
   %determines if there is space until the next character CHAR;
   begin integer n;
      n := 0;
      while u do
        <<if car u = char then u := list nil
           else if atom car u then n := n+1
           else if car u='(m u) then <<n := 1000; u := list nil>>
           else if numberp caar u and caar u<mark then u := list nil;
          u := cdr u>>;
      return n
   end;

symbolic procedure spaces20x n;
   %for i := 1:n do prin20x '! ;
   while n>0 do <<prin20x '! ; n := n-1>>;

symbolic procedure prin2rox u;
   begin integer m,n; scalar x,y;
      m := rmar-12;
      n := rmar-1;
      while u do
        if car u eq '!"
          then <<if not stringspace(cdr u,n-!*n)
                   then <<terpri0x(); !*n := 0>>
                  else nil;
                 prin20x '!";
                 u := cdr u;
                 while not car u eq '!" do
                   <<prin20x car u; u := cdr u; !*n := !*n+1>>;
                 prin20x '!";
                 u := cdr u;
                 !*n := !*n+2;
                 x := y := nil>>
         else if atom car u and not(car u eq '!  and (!*n=0 or null x
               or cdr u and breakp cadr u or breakp x and not y eq '!!))
          then <<y := x; prin20x(x := car u); !*n := !*n+1;
         u := cdr u;
         if !*n=n or !*n>m and not breakp car u and nospace(u,n-!*n)
          then <<terpri0x(); x := y := nil>> else nil>>
         else u := cdr u
   end;

symbolic procedure nospace(u,n);
   if n<1 then t
    else if null u then nil
    else if not atom car u then nospace(cdr u,n)
    else if not car u eq '!! and (cadr u eq '!  or breakp cadr u)
     then nil
    else nospace(cdr u,n-1);

symbolic procedure breakp u;
   u member '(!< !> !; !: != !) !+ !- !, !' !");

symbolic procedure stringspace(u,n);
   if n<1 then nil else if car u eq '!" then t
    else stringspace(cdr u,n-1);


comment Some interfaces needed;

symbolic procedure prin20x u;
   if rprifn!* then apply(rprifn!*,list u) else prin2 u;

symbolic procedure terpri0x;
   if rterfn!* then apply(rterfn!*,nil) else terpri();

endmodule;


end;
