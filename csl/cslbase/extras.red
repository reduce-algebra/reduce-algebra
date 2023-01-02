% extras.red                               Copyright (C) Codemist 2004-2023
%
% Additional useful functions to have in a Lisp environment.
%

%
%
%/**************************************************************************
% * Copyright (C) 2022, Codemist.                         A C Norman       *
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
%
%

% $Id$

% CSL does not support user-defined special forms! So
%    (df name (u) body)
% will get mapped to a macro as roughly
%    (dm name (g)
%       `(let* ((u '@(cdr g)))
%           (progn @,body)))
%
% For example      (df quote (u) (car u))
% map map onto something such that macroexpanding (quote XX) gives
%                  (let* ((g '(XX)))
%                        (car g))       [g is a fresh gensym]

symbolic macro procedure df(u, !&optional, env);
  begin
    scalar g, w;
    g := gensym();
    w := list('list,
              ''let!*,
              list('list, list('list,
                               mkquote caaddr u,
                               list('mkquote, list('cdr, g)))), 
              list('cons, ''progn, mkquote cdddr u));
    return list('dm, cadr u, list(g, '!&optional, gensym()), w);
  end;

flag('(copyd), 'lose); % Now build into the CSL core

% The following small function is just used for testing the CSL OEM
% interface code...

symbolic procedure oem!-supervisor();
   print eval read();

%
% If you go (setq !*break!-loop!* 'break!-loop) then errors will get this
% function called - and it is rather desirable that it does not itself fail.
% The argument is what was passed to (ERROR ...) if the Lisp-level error
% function was called. When this function exits the system will unwind back
% to the next enclosing ERRORSET. (enable!-backtrace <fg>) can be used to
% switch backtrace display on or off.
%

symbolic procedure break!-loop a;
  begin
    scalar prompt, ifile, ofile, u, v;
% I use wrs/rds so I am compatible between Standard and Common Lisp here
    ifile := rds !*debug!-io!*;
    ofile := wrs !*debug!-io!*;
    prompt := setpchar "Break loop (:X exits)> ";
top:u := read();
    if u = '!:x then go to exit
    else if u = '!:q then <<
       enable!-backtrace nil;
       princ "Backtrace now disabled";
       terpri() >>
    else if u = '!:v then <<
       enable!-backtrace t;
       princ "Backtrace now enabled";
       terpri() >>
    else <<
       if null u then v := nil
       else v := errorset(u, nil, nil);
       if atom v then <<
          princ ":Q   quietens backtrace"; terpri();
          princ ":V   enables backtrace"; terpri();
          princ ":X   exits from break loop"; terpri();
          princ "else form for evaluation"; terpri();
         >>
       else <<
          prin "=> ";
          prinl car v;
          terpri() >> >>;
    go to top;
exit:
    rds ifile;
    wrs ofile;
    setpchar prompt;
    return nil
  end;

% hashtagged!-name(base, value) manufactures a name based on the
% base together with a hash-value computed from the "value". This
% is expected to be a reliable signature (but clashes are of course
% possible).  Eg base may be the name of a function and value its
% definition, then this will invent a name suitable for a parallel
% version of the function where the new name ought not to conflict with
% ones used later if this function gets defined with a different
% definition.

symbolic procedure hashtagged!-name(base, value);
   intern list2string 
      append(explodec base, '!_ . explodehex md60 value);

%
% Sorting
%

remflag('(sort sortip), 'lose);

symbolic procedure sort(l, pred);
% Sort the list l according to the given predicate.  If l is a list
% of numbers then the predicate "lessp" will sort the list into
% ascending order.  The predicate should be a strict inequality, i.e.
% it should return NIL if the two items compared are equal.
% As implemented here SORT just calls STABLE-SORT, but as a matter of
% style any use where the ordering of incomparable items in the output
% matters ought to use STABLE!-SORT directly, thereby allowing the
% replacement of this code with a faster non-stable method.
% (Note: the previous REDUCE sort function also happened to be stable, so
%        this code should give exactly the same results for all calls where
%        the predicate is self-consistent and never has both pred(a,b) and
%        pred(b,a) true.  A previous CSL sort was not stable, but was perhaps
%        very slightly faster than this)
  stable!-sortip(append(l, nil), pred);

symbolic procedure stable!-sort(l, pred);
% Sorts a list, as SORT, but if two items x and y in the input list
% satisfy neither pred(x,y) nor pred(y,x) [i.e. they are equal so far
% as the given ordering predicate is concerned] this function guarantees
% that they will appear in the output list in the same order that they
% were in the input.
   stable!-sortip(append(l, nil), pred);

symbolic procedure sortip(l, pred);
   stable!-sortip(l, pred);

symbolic procedure stable!-sortip(l, pred);
% As stable!-sort, but over-writes the input list to make the output.
% It is not intended that people should call this function directly: it
% is present just as the implementation of the main sort procedures defined
% above.
  begin
    scalar l1, l2, w;
    if null l then return l;    % Input list of length 0
    l1 := l;
    l2 := cdr l;
    if null l2 then return l;   % Input list of length 1
% Now I have dealt with the essential special cases of lists of length 0
% and 1 (which do not need sorting at all).  Since it possibly speeds things
% up just a little I will now have some fairly ugly code that makes special
% cases of lists of length 2.  I could easily have special code for length
% 3 lists here (and include it, but commented out), but at present my
% measurements suggest that the speed improvement that it gives is minimal
% and the increase in code bulk is large enough to give some pain.  
    l := cdr l2;
    if null l then <<           % Input list of length 2
       if apply2(pred, car l2, car l1) then <<
          l := car l1;
          rplaca(l1, car l2);
          rplaca(l2, l) >>;
       return l1 >>;
% Now I will check to see if the list is in fact in order already
% Doing so will have a cost - but sometimes that cost will be repaid
% when I am able to exit especially early.  The result of all this
% is that I will have a best case behaviour with linear cost growth for
% inputs that are initially in the correct order, while my average and
% worst-case costs will increase by a constant factor.
    l := l1;
    while l2 and not apply2(pred, car l2, car l) do <<
% In the input list is NOT already in order then I expect that this
% loop will exit fairly early, and so will not contribute much to the
% total cost.  If it exits very late then probably in the next recursion
% down the first half of the list will be found to be already sorted, and
% again I have a chance to win.
       l := l2; l2 := cdr l2 >>;
    if null l2 then return l1;
    l2 := l1;
    l := cddr l2;
    while l and cdr l do << l2 := cdr l2; l := cddr l >>;
    l := l2;
    l2 := cdr l2;
    rplacd(l, nil);
% The two sub-lists are then sorted.
    l1 := stable!-sortip(l1, pred);
    l2 := stable!-sortip(l2, pred);
% Now I merge the sorted fragments, giving priority to item from the
% earlier part of the original list.
    l := w := list nil;
    while l1 and l2 do <<
       if apply2(pred, car l2, car l1) then <<
          rplacd(w, l2); w := l2; l2 := cdr l2 >>
       else << rplacd(w, l1); w := l1; l1 := cdr l1 >> >>;
    if l1 then l2 := l1;
    rplacd(w, l2);
    return cdr l
  end;

%
% Code to print potentially re-entrant lists
%

fluid '(!*prinl!-visited!-nodes!* !*prinl!-index!* 
        !*prinl!-fn!* !*print!-array!*
        !*print!-length!* !*print!-level!*);

!*print!-length!* := !*print!-level!* := nil;

!*prinl!-visited!-nodes!* := mkhash(10, 0, 1.5)$

symbolic procedure s!:prinl0(x,!*prinl!-fn!*);
% print x even if it has loops in it
  begin
    scalar !*prinl!-index!*;
    !*prinl!-index!*:=0;
    clrhash !*prinl!-visited!-nodes!*;
    s!:prinl1(x, 0);
    s!:prinl2(x, 0);
    clrhash !*prinl!-visited!-nodes!*;
    return x
  end;

symbolic procedure s!:prinl1(x, depth);
% Find all the nodes in x and record them in the hash table.
% The first time a node is met it is inserted with associated value 0.
% If a node is met a second time then it is assigned an unique positive
% integer code that will later be used in its label.
  begin
    scalar w, length;
    if fixp !*print!-level!* and depth > !*print!-level!* then return nil;
    length := 0;
 top:
    if atom x and not simple!-vector!-p x and not gensymp x then return nil
    else if w := gethash(x,!*prinl!-visited!-nodes!*) then <<
       if w = 0 then <<
         !*prinl!-index!* := !*prinl!-index!* + 1;
         puthash(x,!*prinl!-visited!-nodes!*, !*prinl!-index!*) >>;
       return nil >>
    else <<
      puthash(x, !*prinl!-visited!-nodes!*, 0);
      if simple!-vector!-p x then <<
        if !*print!-array!* then <<
          length := upbv x;
          if fixp !*print!-length!* and !*print!-length!* < length then
              length := !*print!-length!*;
          for i:=0:length do s!:prinl1(getv(x,i), depth+1) >> >>
      else if not atom x then <<
          s!:prinl1(car x, depth+1);
          if fixp !*print!-length!* and
             (length := length+1) > !*print!-length!* then return nil;
          x := cdr x;
          go to top >> >>
  end;

symbolic procedure s!:prinl2(x, depth);
% Scan a structure that was previously processed by s!:prinl1. Thus all
% nodes in x are already in the hash table. Those with value zero
% are only present once in x, while those with strictly positive values
% occur at least twice.  After printing a label for such value this resets the
% value negative so that the printing can tell when the visit is for
% a second rather than first time.  The output format is intended to
% bear some resemblance to the expectations of Common Lisp.
    if fixp !*print!-level!* and depth > !*print!-level!* then
       princ "#"
    else if atom x and not simple!-vector!-p x and not gensymp x then <<
!#if common!-lisp!-mode       
       if complex!-arrayp x and not !*print!-array!* then princ "[Array]"
       else if structp x and not !*print!-array!* then princ "[Struct]"
       else
!#endif
       funcall(!*prinl!-fn!*, x) >>
    else begin scalar w, length;
      w := gethash(x,!*prinl!-visited!-nodes!*);
% w has better be a number here, following s!:prinl1
      if not zerop w then <<
        if w < 0 then <<
          princ "#";
          princ (-w);
          princ "#";
          return nil >>
        else <<
          puthash(x,!*prinl!-visited!-nodes!*, -w);
          princ "#";
          princ w;
          princ "=" >> >>;
      if simple!-vector!-p x then <<
         princ "%(";
         if !*print!-array!* then <<
           length := upbv x;
           if fixp !*print!-length!* and !*print!-length!* < length then
               length := !*print!-length!*;
           for i:=0:length do << s!:prinl2(getv(x,i), depth+1);
                                 if not (i=upbv x) then princ " " >> >>
         else princ "...";
         princ ")";
         return nil >>
      else if atom x then return funcall(!*prinl!-fn!*, x);
      princ "(";
      length := 0;
  loop:
      s!:prinl2(car x, depth+1);
      x:=cdr x;
      if atom x then <<
          if simple!-vector!-p x then <<
              princ " . %(";
              if !*print!-array!* then <<
                length := upbv x;
                if fixp !*print!-length!* and !*print!-length!* < length then
                    length := !*print!-length!*;
                for i:=0:length do <<s!:prinl2(getv(x,i), depth+1);
                                     if not (i=upbv x) then princ " ">> >>
              else princ "...";
              princ ")" >>
          else if x then <<
              princ " . ";
              funcall(!*prinl!-fn!*, x) >>;
          return princ ")" >>;
      if fixp !*print!-length!* and
         (length := length + 1) > !*print!-length!* then
             return princ " ...)";
      w := gethash(x, !*prinl!-visited!-nodes!*);
      if not (w = 0) then if w < 0 then <<
          princ " . #";
          princ (-w);
          return princ "#)" >>
        else <<
          princ " . ";
          s!:prinl2(x, depth+1);        % This will set the label
          return princ ")" >>
      else princ " ";
      go to loop
    end;


symbolic procedure printl x;
 << prinl x;
    terpri();
    x >>;

symbolic procedure printcl x;
 << princl x;
    terpri();
    x >>;

symbolic procedure princl x;
    s!:prinl0(x,function princ);

symbolic procedure prinl x;
    s!:prinl0(x,function prin);

%
% A small subset of the facilities of the unreasonably baroque Common
% Lisp FORMAT function may be useful.
%

!#if (not common!-lisp!-mode)

% If I am in COMMON Lisp mode then a more complete version of this
% will be installed from elsewhere.


symbolic procedure s!:format(dest, fmt, args);
  begin
    scalar len, c, a, res, o;
    if not null dest then <<
       if dest = 't then o := wrs nil
       else o := wrs dest >>;
    len := upbv fmt;
    for i := 0:len do <<
       c := schar(fmt, i);
       if c = '!~ then <<
          i := i + 1;
          c := char!-downcase schar(fmt, i);
          if c = '!% then
             if null dest then res := !$eol!$ . res
             else terpri()
          else if c = '!~ then
             if null dest then res := '!~ . res
             else princ '!~
          else <<
             if null args then a := nil
             else <<
                a := car args;
                args := cdr args >>;
             if c = '!a then
                if null dest then for each k in explode2 a do res := k . res
                else princ a
             else if c = '!s then
                if null dest then for each k in explode a do res := k . res
                else prin a
             else
                if null dest then for each k in explode a do res := k . res
                else prin list('!?!?!?, c, a) >> >>
       else <<
          if null dest then res := c . res
          else princ c >> >>;
    if null dest then return list2string reversip res
    else << wrs o; return nil >>
  end;

symbolic macro procedure format(u, !&optional, env);
   list('s!:format, cadr u, caddr u, 'list . cdddr u);

!#endif

fluid '(s!:bn
        s!:bufferi
        s!:buffero
        s!:indblanks
        s!:indentlevel
        s!:initialblanks
        s!:lmar
        s!:pendingrpars
        s!:rmar
        s!:rparcount
        s!:stack);

global '(!*quotes !*pretty!-symmetric thin!*);

!*pretty!-symmetric := t;
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

remflag('(superprinm superprintm prettyprint tprettyprint), 'lose);

symbolic procedure prettyprint x;
 << superprinm(x,posn()); % What REDUCE seems to want. Looks a bit odd to me!
    terpri();
    nil>>;

symbolic procedure tprettyprint x;
 << if posn() > 6 then terpri();
    prettyprint x >>;

symbolic procedure superprintm(x,s!:lmar);
  << superprinm(x,s!:lmar); terpri(); x >>;


% From here down the functions are not intended for direct use.

symbolic procedure superprinm(x,s!:lmar);
  begin
    scalar s!:stack,s!:bufferi,s!:buffero,s!:bn,s!:initialblanks,s!:rmar,
           s!:pendingrpars,s!:indentlevel,s!:indblanks,s!:rparcount,w;
    s!:bufferi:=s!:buffero:=list nil; %fifo buffer.
    s!:initialblanks:=0;
    s!:rparcount:=0;
    s!:indblanks:=0;
    s!:rmar:=linelength(nil); % right margin.
    linelength 500;        % To try to be extra cautious
    if s!:rmar<25 then error(0,list(s!:rmar,
        "Linelength too short for superprinting"));
    s!:bn:=0; %characters in buffer.
    s!:indentlevel:=0; %no indentation needed, yet.
    if s!:lmar+20>=s!:rmar then s!:lmar:=s!:rmar - 21; %no room for specified margin
    w:=posn();
    if w>s!:lmar then << terpri(); w:=0 >>;
    if w<s!:lmar then s!:initialblanks:=s!:lmar - w;
    s!:prindent(x,s!:lmar+2); %main recursive print routine.
% traverse routine finished - now tidy up buffers.
    s!:overflow 'none; %flush out the buffer.
    linelength s!:rmar;
    return x
  end;

flag('(superprinm superprintm prettyprint tprettyprint), 'lose);

% Access functions for a stack entry.


symbolic macro procedure s!:top(u,!&optional,v);
   '(car s!:stack);

symbolic macro procedure s!:depth(u,!&optional,v);
   list('car, cadr u);

symbolic macro procedure s!:indenting(u,!&optional,v);
   list('cadr, cadr u);

symbolic macro procedure s!:blankcount(u,!&optional,v);
   list('caddr, cadr u);

symbolic macro procedure s!:blanklist(u,!&optional,v);
   list('cdddr, cadr u);

symbolic macro procedure s!:setindenting(u,!&optional,v);
   list('rplaca, list('cdr, cadr u), caddr u);

symbolic macro procedure s!:setblankcount(u,!&optional,v);
   list('rplaca, list('cddr, cadr u), caddr u);

symbolic macro procedure s!:setblanklist(u,!&optional,v);
   list('rplacd, list('cddr, cadr u), caddr u);

symbolic macro procedure s!:newframe(u,!&optional,v);
   list('list, cadr u, nil, 0);

symbolic macro procedure s!:blankp(u,!&optional,v);
   list('numberp, list('car, cadr u));


symbolic procedure s!:prindent(x,n);
% Print list x with indentation level n.
    if atom x then if simple!-vector!-p x then s!:prvector(x,n)
        else for each c in 
          (if !*pretty!-symmetric
             then if stringp x then s!:explodes x else explode x
            else explode2 x) do s!:putch c
    else if s!:quotep x then <<
        s!:putch '!';
        s!:prindent(cadr x,n+1) >>
    else begin
        scalar cx;
        if 4*n>3*s!:rmar then << %list is too deep for sanity.
            s!:overflow 'all;
            n:=truncate(n, 8);
            if s!:initialblanks>n then <<
                s!:lmar:=s!:lmar - s!:initialblanks+n;
                s!:initialblanks:=n >> >>;
        s!:stack := (s!:newframe n) . s!:stack;
        s!:putch ('lpar . s!:top());
        cx:=car x;
        s!:prindent(cx,n+1);
        if idp cx and not atom cdr x then 
            cx:=get(cx,'s!:ppformat) else cx:=nil;
        if cx=2 and atom cddr x then cx:=nil;
        if cx='prog then <<
            s!:putch '! ;
            s!:prindent(car (x:=cdr x),n+2) >>;
% CX now controls the formatting of what follows:
%    nil      default action
%    <number> first few blanks are non-indenting
%    prog     display atoms as labels.
         x:=cdr x;

   scan: if atom x then go to outt;
         s!:finishpending(); %about to print a blank.
         if cx='prog then <<
             s!:putblank();
             s!:overflow s!:bufferi; %force format for prog.
             if atom car x then << % a label.
                 s!:lmar:=s!:initialblanks:=max(s!:lmar - 6,0);
                 s!:prindent(car x,n - 2); % print the label.
                 x:=cdr x;
                 if not atom x and atom car x then go to scan;
                 if s!:lmar+s!:bn>n then s!:putblank()
                 else for i:=s!:lmar+s!:bn:n - 1 do s!:putch '! ;
                 if atom x then go to outt>> >>
         else if numberp cx then <<
             cx:=cx - 1;
             if cx=0 then cx:=nil;
             s!:putch '!  >>
         else s!:putblank();
         s!:prindent(car x,n+2);
         x:=cdr x;
         go to scan;

   outt: if not null x then <<
            s!:finishpending();
            s!:putblank();
            s!:putch '!.;
            s!:putch '! ;
            s!:prindent(x,n+5) >>;
        s!:putch ('rpar . (n - 2));
        if s!:indenting s!:top()='indent and not null s!:blanklist s!:top() then
               s!:overflow car s!:blanklist s!:top()
        else s!:endlist s!:top();
        s!:stack:=cdr s!:stack
      end;

symbolic procedure s!:explodes x;
   %dummy function just in case another format is needed.
   explode x;

symbolic procedure s!:prvector(x,n);
  begin
    scalar bound;
    bound:=upbv x; % length of the vector.
    s!:stack:=(s!:newframe n) . s!:stack;
    s!:putch ('lsquare . s!:top());
    s!:prindent(getv(x,0),n+2);
    for i:=1:bound do <<
        s!:putch '!,;
        s!:putblank();
        s!:prindent(getv(x,i),n+2) >>;
    s!:putch('rsquare . (n - 2));
    s!:endlist s!:top();
    s!:stack:=cdr s!:stack
  end;

symbolic procedure s!:putblank();
  begin
    s!:putch s!:top(); %represents a blank character.
    s!:setblankcount(s!:top(),s!:blankcount s!:top()+1);
    s!:setblanklist(s!:top(),s!:bufferi . s!:blanklist s!:top());
         %remember where I was.
    s!:indblanks:=s!:indblanks+1
  end;




symbolic procedure s!:endlist l;
%Fix up the blanks in a complete list so that they
%will not be turned into indentations.
     s!:pendingrpars:=l . s!:pendingrpars;

% When I have printed a ')' I want to mark all of the blanks
% within the parentheses as being unindented, ordinary blank
% characters. It is however possible that I may get a buffer
% overflow while printing a string of )))))))))), and so this
% marking should be delayed until I get round to printing
% a further blank (which will be a candidate for a place to
% split lines). This delay is dealt with by the list
% s!:pendingrpars which holds a list of levels that, when
% convenient, can be tidied up and closed out.

symbolic procedure s!:finishpending();
 << for each stackframe in s!:pendingrpars do <<
        if s!:indenting stackframe neq 'indent then
            for each b in s!:blanklist stackframe do
              << rplaca(b,'! ); s!:indblanks:=s!:indblanks - 1>>;
% s!:blanklist of stackframe must be non-nil so that overflow
% will not treat the '(' specially.
        s!:setblanklist(stackframe,t) >>;
    s!:pendingrpars:=nil >>;



symbolic procedure s!:quotep x;
    !*quotes and
    not atom x and
    car x='quote and
    not atom cdr x and
    null cddr x;






% property s!:ppformat drives the prettyprinter -
% prog     : special for prog only
% 1        :    (fn a1
%                  a2
%                  ... )
% 2        :    (fn a1 a2
%                  a3
%                  ... )     ;

put('prog,'s!:ppformat,'prog);
put('lambda,'s!:ppformat,1);
put('lambdaq,'s!:ppformat,1);
put('setq,'s!:ppformat,1);
put('set,'s!:ppformat,1);
put('while,'s!:ppformat,1);
put('t,'s!:ppformat,1);
put('de,'s!:ppformat,2);
put('df,'s!:ppformat,2);
put('dm,'s!:ppformat,2);
put('defun,'s!:ppformat,2);
put('defmacro,'s!:ppformat,2);
put('foreach,'s!:ppformat,4); % (foreach x in y do ...) etc.


% Now for the routines that buffer things on a character by character
% basis, and deal with buffer overflow.


symbolic procedure s!:putch c;
  begin
    if atom c then s!:rparcount:=0
    else if s!:blankp c then << s!:rparcount:=0; go to nocheck >>
    else if car c='rpar then <<
        s!:rparcount:=s!:rparcount+1;
% format for a long string of rpars is:
%    )))) ))) ))) ))) )))   ;
        if s!:rparcount>4 then << s!:putch '! ; s!:rparcount:=2 >> >>
    else s!:rparcount:=0;
    while s!:lmar+s!:bn>=s!:rmar do s!:overflow 'more;
nocheck:
    s!:bufferi:=cdr rplacd(s!:bufferi,list c);
    s!:bn:=s!:bn+1 
  end;

symbolic procedure s!:overflow flg;
  begin
    scalar c,blankstoskip;
% The current buffer holds so much information that it will
% not all fit on a line. try to do something about it.
%    flg is one of:
%      'none       do not force more indentation
%      'more       force one level more indentation
%      <a pointer into the buffer>
%                  prints up to and including that character, which
%                  should be a blank.
    if s!:indblanks=0 and s!:initialblanks>2 and flg='more then <<
        s!:initialblanks:=s!:initialblanks - 2;
        s!:lmar:=s!:lmar - 2;
        return 'moved!-left >>;
fblank:
    if s!:bn=0 then <<
% No blank found - can do no more for now.
% If flg='more I am in trouble and so have to print
% a continuation mark. in the other cases I can just exit.
        if not(flg = 'more) then return 'empty;
        if atom car s!:buffero then
% continuation mark not needed if last char printed was
% special (e.g. lpar or rpar).
            prin2 "%+"; %continuation marker.
        terpri();
        s!:lmar:=0;
        return 'continued >>
    else <<
        spaces s!:initialblanks;
        s!:initialblanks:=0 >>;
    s!:buffero:=cdr s!:buffero;
    s!:bn:=s!:bn - 1;
    s!:lmar:=s!:lmar+1;
    c:=car s!:buffero;
    if atom c then <<
       prin2 c;
       go to fblank >>
    else if s!:blankp c then if not atom blankstoskip then <<
        prin2 '! ;
        s!:indblanks:=s!:indblanks - 1;
% blankstoskip = (stack-frame . skip-count).
        if c eq car blankstoskip then <<
            rplacd(blankstoskip,cdr blankstoskip - 1);
            if cdr blankstoskip=0 then blankstoskip:=t >>;
        go to fblank >>
      else go to blankfound
    else if car c='lpar or car c='lsquare then <<
        prin2 get(car c,'s!:ppchar);
        if flg='none then go to fblank;
% now I want to flag this level for indentation.
        c:=cdr c; %the stack frame.
        if not null s!:blanklist c then go to fblank;
        if s!:depth c>s!:indentlevel then << %new indentation.
% this level has not emitted any blanks yet.
            s!:indentlevel:=s!:depth c;
            s!:setindenting(c,'indent) >>;
        go to fblank >>
    else if car c='rpar or car c='rsquare then <<
        if cdr c<s!:indentlevel then s!:indentlevel:=cdr c;
        prin2 get(car c,'s!:ppchar);
        go to fblank >>
    else error(0,list(c,"UNKNOWN TAG IN OVERFLOW"));
blankfound:
    if eqcar(s!:blanklist c,s!:buffero) then
        s!:setblanklist(c,nil);
% at least one entry on blanklist ought to be valid, so if I
% print the last blank I must kill blanklist totally.
    s!:indblanks:=s!:indblanks - 1;
% check if next level represents new indentation.
    if s!:depth c>s!:indentlevel then <<
        if flg='none then << %just print an ordinary blank.
            prin2 '! ;
            go to fblank >>;
% here I increase the indentation level by one.
        if blankstoskip then blankstoskip:=nil
        else <<
            s!:indentlevel:=s!:depth c;
            s!:setindenting(c,'indent) >> >>;
%otherwise I was indenting at that level anyway.
    if s!:blankcount c>(thin!* - 1) then << %long thin list fix-up here.
        blankstoskip:=c . ((s!:blankcount c) - 2);
        s!:setindenting(c,'thin);
        s!:setblankcount(c,1);
        s!:indentlevel:=(s!:depth c) - 1;
        prin2 '! ;
        go to fblank >>;
    s!:setblankcount(c,(s!:blankcount c) - 1);
    terpri();
    s!:lmar:=s!:initialblanks:=s!:depth c;
    if s!:buffero eq flg then return 'to!-flg;
    if blankstoskip or not (flg='more) then go to fblank;
% keep going unless call was of type 'more'.
    return 'more; %try some more.
  end;

put('lpar,'s!:ppchar,'!();
put('lsquare,'s!:ppchar,'![);
put('rpar,'s!:ppchar,'!));
put('rsquare,'s!:ppchar,'!]);

% Now some (experimental) support for network access

symbolic procedure fetch!-url(url, !&optional, dest);
  begin
    scalar a, b, c, d, e, w;
    a := open!-url url;
    if null a then return nil;
    if dest then <<
        d := open(dest, 'output);
        if null d then <<
            close a;
            return error(0, "unable to open destination file") >>;
        d := wrs d >>;
    b := rds a;
    w := linelength 500;
    while not ((c := readch()) = !$eof!$) do princ c;
    linelength e;
    rds b;
    close a;
    if dest then close wrs d
  end;

% I need at least a minimal version of bldmsg to tide me over until the
% full version in rlisp/rprint.red gets processed.

symbolic procedure bldmsg_temp_internal(fmt, args);
  begin
    scalar r, a;
    fmt := explodec fmt;
    while fmt do <<
      if eqcar(fmt, '!%) then <<
        fmt := cdr fmt;
        a := car args;
        args := cdr args;
% Here I will make %p display using "prin" and %x for any other x use
% "princ". This is a bit minimalist and does not cope well with
% some options that the full version supports, but is about as concise
% as I can make things here.
        if eqcar(fmt, '!p) or eqcar(fmt, '!P) then a := explode a
        else a := explodec a;
        for each c in a do r := c . r >>
      else r := car fmt . r ;
      fmt := cdr fmt >>;
    return list2string reversip r
  end;

symbolic macro procedure bldmsg u;
  list('bldmsg_temp_internal, cadr u, 'list . cddr u);

flag('(bldmsg), 'variadic);

end;

% end of extras.red
