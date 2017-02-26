module rprintf; % formatted printing

% Note that I must not call this just "printf" because PSL has that as
% an existing module name.

% Author: Arthur Norman.

% Copyright (c) 2016 Arthur Norman.  All rights reserved.

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

% I will support bldmsg by having versions of the print primitives that
% dump characters in a list...

fluid '(bldmsg_chars!* !*ll!*);
bldmsg_chars!* := nil;

symbolic procedure p_princ(u, blankfirst);
  begin
    scalar w;
% With CSL if u is a string or a symbol with a print representation that
% contains characters outside the Basic Latin unicode block then the
% list w will contain a single item for each wide character. If you try the
% same in PSL then you may or may not survive...
    w := explode2 u;
    if bldmsg_chars!* then <<
      if blankfirst then bldmsg_chars!* := '!  . bldmsg_chars!*;
      for each c in w do bldmsg_chars!* := c . bldmsg_chars!* >>
    else <<
      if blankfirst then <<
         if posn() + length w  + 1 > !*ll!* then terpri();
         prin2 " " >>
      else if posn() + length w > !*ll!* then terpri();
      prin2 u >>
  end;

symbolic procedure p_prin(u, blankfirst);
  begin
    scalar w;
    w := explode u;
% At the time I implemented this PSL explodes the symbol with name "_a"
% as just (_ a) rather than as (! _ a). That would mean that the result
% would not read back into Reduce properly - so I stick in the extra
% escape character.
    if eqcar(w, '!_) then w := '!! . w;
    if bldmsg_chars!* then <<
      if blankfirst then bldmsg_chars!* := '!  . bldmsg_chars!*;
      for each c in w do bldmsg_chars!* := c . bldmsg_chars!* >>
    else <<
      if blankfirst then <<
        if posn() + length w + 1 > !*ll!* then terpri();
        prin2 " " >>
      else if posn() + length w > !*ll!* then terpri();
      for each c in w do prin2 c >>
  end;

%
% Code to print potentially re-entrant lists
%

fluid '(!*print!-array!*
        !*print!-length!*
        !*print!-level!*);

!*print!-array!* := t;        % Display contents if vectors if true
!*print!-length!* := nil;     % Limit length of lists printed if an integer
!*print!-level!* := nil;      % Limit depth of nesting if an integer.

fluid '(!*prinl_visited_nodes!* !*prinl_index!* );

!*prinl_visited_nodes!* := mkhash(10, 0, 1.5)$

symbolic procedure p_prinl0(x, escaped);
% print x even if it has loops in it. If escaped is true then printing
% is in the style of prin1, otherwise prin2.
  begin
    scalar !*prinl_index!*;
    !*prinl_index!*:=0;
% Clear the hash table AFTER use, so that the junk that goes into it does
% not gobble memory between calls to prinl. This relies on unwind!-protect
% to make sure that it is indeed always cleared. Errors (eg ^C) during the
% clean-up operation could lead to curious displays in the next use of
% prinl.
    unwind!-protect(<< p_prinl1(x, 0); p_prinl2(x, 0, escaped, nil) >>,
                    clrhash !*prinl_visited_nodes!*);
    return x
  end;

symbolic procedure p_prinl1(x, depth);
% Find all the nodes in x and record them in the hash table.
% The first time a node is met it is inserted with associated value 0.
% If a node is met a second time then it is assigned an unique positive
% integer code that will later be used in its label.
  begin
    scalar w, length;
    if fixp !*print!-level!* and depth > !*print!-level!* then return nil;
    length := 0;
 top:
    if atom x and not vectorp x and not gensymp x then return nil
    else if w := gethash(x,!*prinl_visited_nodes!*) then <<
       if w = 0 then <<
         !*prinl_index!* := !*prinl_index!* + 1;
         puthash(x,!*prinl_visited_nodes!*, !*prinl_index!*) >>;
       return nil >>
    else <<
      puthash(x, !*prinl_visited_nodes!*, 0);
      if vectorp x then <<
        if !*print!-array!* then <<
          length := upbv x;
          if fixp !*print!-length!* and !*print!-length!* < length then
              length := !*print!-length!*;
          for i:=0:length do p_prinl1(getv(x,i), depth+1) >> >>
      else if not atom x then <<
          p_prinl1(car x, depth+1);
          if fixp !*print!-length!* and
             (length := length+1) > !*print!-length!* then return nil;
          x := cdr x;
          go to top >> >>
  end;

symbolic procedure p_printref(w, blankfirst, ch);
% This prints "#NN#" possibly with a blank in front of it and
% perhaps splitting the line. Well it can also do "#NN=".
  begin
    scalar len;
    len := length explode w;
    if blankfirst then len := len + 1;
% Here I will break the line unless I can fit on "#nn#" or " #nn#" as
% relevant.
    if not bldmsg_chars!* and
       posn() + 2 + len > !*ll!* then <<
      blankfirst := nil;
      terpri() >>;
    p_princ("#", blankfirst);
    p_princ(w, nil);
    p_princ(ch, nil)
  end;

symbolic procedure p_prinl2(x, depth, escaped, blankfirst);
% Scan a structure that was previously processed by p_prinl1. Thus all
% nodes in x are already in the hash table. Those with value zero
% are only present once in x, while those with strictly positive values
% occur at least twice.  After printing a label for such value this resets the
% value negative so that the printing can tell when the visit is for
% a second rather than first time.  The output format is intended to
% bear some resemblance to the expectations of Common Lisp.
%
% Note that if the hash table is in fact empty then this will just print
% what "ordinary" prin/princ would.
    if fixp !*print!-level!* and depth > !*print!-level!* then
       p_princ("#", blankfirst)
    else if atom x and not vectorp x and not gensymp x then <<
       if escaped then p_prin(x, blankfirst)
       else p_princ(x, blankfirst) >>
    else begin scalar w, length;
      w := gethash(x,!*prinl_visited_nodes!*);
      if w and not zerop w then <<
        if w < 0 then <<
          p_printref(-w, blankfirst, "#");
          return nil >>
        else <<
          puthash(x,!*prinl_visited_nodes!*, -w);
          p_printref(w, blankfirst, "=");
          blankfirst := nil >> >>;
      if vectorp x then <<
         p_princ("%(", blankfirst);
         if !*print!-array!* then <<
           length := upbv x;
           if fixp !*print!-length!* and !*print!-length!* < length then
               length := !*print!-length!*;
           for i:=0:length do
             p_prinl2(getv(x,i), depth+1, escaped, i neq 0) >>
         else p_princ("...", nil);
         p_princ(")", nil);
         return nil >>
      else if atom x then <<
        if escaped then p_prin(x, blankfirst)
        else p_princ(x, blankfirst);
        return nil >>;
      p_princ("(", blankfirst);
      p_prinl2(car x, depth+1, escaped, nil);
      x:=cdr x;
      length := 0;
  loop:
      if atom x then <<
        if x neq nil then <<
          p_princ(".", t);
          p_prinl2(x, depth, escaped, t) >>;
        return p_princ(")", nil) >>;
      if fixp !*print!-length!* and
         (length := length + 1) > !*print!-length!* then <<
             p_princ("...", t);
             return p_princ(")", nil) >>;
      w := gethash(x, !*prinl_visited_nodes!*);
      if w and not zerop w then <<
        if w < 0 then <<
          p_princ(".", t);
          p_printref(-w, t, "#");
          return p_princ(")", nil) >>
        else <<
          p_princ(".", t);
          p_prinl2(x, depth+1, escaped, t);
          return p_princ(")", nil) >> >>;
      p_prinl2(car x, depth+1, escaped, t);
      x:=cdr x;
      go to loop
    end;

symbolic procedure rlisp_printl x;
 << rplisp_prinl x;
    terpri();
    x >>;

symbolic procedure rlisp_printcl x;
 << rlisp_princl x;
    terpri();
    x >>;

symbolic procedure rlisp_princl x;
  begin
    scalar !*ll!*;
    !*ll!* := linelength nil - 2;
    p_prinl0(x, nil);
    return x;
  end;

symbolic procedure rlisp_prinl x;
  begin
    scalar !*ll!*;
    !*ll!* := linelength nil - 2;
    p_prinl0(x, t);
    return x;
  end;

symbolic procedure portable_print x;
 << portable_prin x;
    terpri();
    x >>;

symbolic procedure portable_printc x;
 << portable_princ x;
    terpri();
    x >>;

symbolic procedure portable_princ x;
  begin
    scalar !*ll!*;
    !*ll!* := linelength nil - 2;
    p_prinl2(x, 0, nil, nil);
    return x;
  end;

symbolic procedure portable_prin x;
  begin
    scalar !*ll!*;
    !*ll!* := linelength nil - 2;
    p_prinl2(x, 0, t, nil);
    return x;
  end;

% The following will print a prefix expression. It will use infix
% notation and understand precedence for expt, times, quotient, plus,
% difference and minus -- all other operators are treated as general
% function applications. If !*SQ is encountered within the formula it
% will be expanded out using prepsq.

% The output from prepf does not use DIFFERENCE as an operator, but in
% case one is fed in from some other odd source I will normalise things
% here.

symbolic procedure p_minus u;
  if eqcar(u, 'minus) then cadr u
  else if eqcar(u, 'plus) then
    'plus . for each v in cdr u collect p_minus v
  else if eqcar(u, 'difference) then
    'plus . p_minus cadr u . cddr u
  else list('minus, u);

symbolic procedure p_diff2minus u;
  begin
    scalar r;
    r := car u;
    while u := cdr u do r := p_minus car u . r;
    return 'plus . reverse r
  end;

symbolic procedure p_prefix(u, prec);
  if atom u then p_princ(u, nil)
  else if eqcar(u, '!*sq) then p_prefix(prepsq cadr u, prec)
  else
    begin
      scalar op, p1;
      op := car u;
% I will have a crude code-based (rather than table-driven) treatment of the
% small number of special cases of infix operators that I support here...
      if op ='expt then <<
        if prec > 3 then p_princ("(", nil);
        p_prefix(cadr u, 4);
        p_princ("^", nil);
        p_prefix(caddr u, 3);
        if prec > 3 then p_princ(")", nil);
        return nil >>
      else if op = 'times or op = 'quotient then <<
        if prec > 2 then p_princ("(", nil);
        p_prefix(car (u := cdr u), 2);
        if op = 'times then << p1 := 2; op := "*" >>
        else << p1 := 3; op := "/" >>;
% If I have (quotient a (times b c)) I must parenthesize the use of "times",
% but if I had (times a (quotient b c)) I need not parenthesize the quotient
% because (a*(b/c)) has the same value as (a*b)/c so can be displated as
% just a*b/c safely.
        while not atom (u := cdr u) do <<
          p_princ(op, nil);
          p_prefix(car u, p1) >>;
        if prec > 2 then p_princ(")", nil);
        return nil >>;
      if op = 'difference then return p_prefix(p_diff2minus cdr u, prec)
      else if op = 'plus then <<
        if prec > 1 then p_princ("(", nil);
        p_prefix(car (u := cdr u), 1);
        while not atom (u := cdr u) do <<
          p1 := car u;
          if eqcar(p1, 'minus) then <<
            p1 := cadr p1;
            p_princ(" - ", nil) >>
          else p_princ(" + ", nil);
          p_prefix(p1, 1) >>;
        if prec > 1 then p_princ(")", nil);
        return nil >>
      else if op = 'minus then <<
        p_princ("-", nil);
        if prec < 2 then prec := 2;
        return p_prefix(cadr u, prec) >>;
% Here I have something I will display as a raw function application. I will
% take special action if the "function" part is complicated!
      if (not atom op) or (numberp op and minusp op) then <<
        p_princ("(", nil);
        p_prefix(op, 0);
        p_princ(")", nil) >>
      else p_princ(op, nil);
      op := "(";
% A function with no args needs "()" after it.
      if atom (u := cdr u) then p_princ("(", nil)
      else for each x in u do <<
        p_princ(op, nil);
        op := ",";
        p_prefix(x, 0) >>;
      return p_princ(")", nil)
    end;

% Sometimes I want to print a Lisp expression starting at the current
% column and with confidence that My Lisp system will keep output within
% consistent line-length limits. Here I provide functions to do that which
% might lead to a display of the style:    (here is where I start an if
%                                          something is not going to fit
%                                          on the line I wrap to the
%                                          starting column. If
%                      someextraordinaryilylongstmbolisincludedthatcannot
%                                          cope with the given width I
%                                          will right-align it as shown.
%

symbolic procedure prin_with_margin u;
   print_with_margin_sub(u, posn(), linelength nil-2, function explode);

symbolic procedure princ_with_margin u;
   print_with_margin_sub(u, posn(), linelength nil-2, function explode2);

symbolic procedure print_with_margin u;
 << prin_with_margin u;
    terpri();
    u >>;

symbolic procedure printc_with_margin u;
 << princ_with_margin u;
    terpri();
    u >>;

% I will cope with symbols, numbers, strings and lists. Vectors and other
% objects will be rendered cryptically at best.

symbolic procedure print_with_margin_sub(u, left, right, explfn);
  begin
    scalar v;
% Override pathologically narrow cases.
    if right < 10 then right := 10;
    if left > right-10 then left := right-10;
    v := u;
% Cope with lists.
    if not atom v then <<
      if posn() >= right then << terpri(); ttab left >>;
      prin2 "(";
      print_with_margin_sub(car v, left, right, explfn);
      while not atom (v := cdr v) do <<
        if posn() >= right then << terpri(); ttab left >>
        else prin2 " ";
        print_with_margin_sub(car v, left, right, explfn) >>;
      if not null v then <<
        if posn() >= right-1 then << terpri(); ttab left; prin2 ". " >>
        else prin2 " .";
        print_with_margin_sub(v, left, right, explfn) >>;
        if posn() >= right then << terpri(); ttab left >>;
        prin2 ")";
      return u >>;
% Here I have something atomic. Use the explode operator I was handed
% to see how long its printed representation would be.
    v := apply(explfn, list u);
% In the case of unreasonably long atoms I will need to split things
% across lines, and I come back to here when I have made at least some
% headway.
verylong:
    if posn() + length v < right then <<
      for each c in v do prin2 c;
      return u >>
    else if length v <= right-left then <<
      terpri();
      ttab left;
      for each c in v do prin2 c;
      return u >>
    else if length v < right then <<
      terpri();
      ttab(right - length v);
      for each c in v do prin2 c;
      return u >>
    else <<
      if posn() >= right-5 then << terpri(); ttab left >>;
      while posn() < right-1 do <<
        prin2 car v;
        v := cdr v >>;
      prin2 "\";
      terpri();
      go to verylong >>
  end;


% Now for printf...

% The special sequences that can occur in format strings are as follows.
% I will make my tests for directives case insensitive, so for instance
% either %b or %B will be recognized.
%       %b    do that many spaces
%       %c    next arg is a character code. display character
%       %d    print an integer (equivalent to %w)
% *     %f    do a terpri() unless posn()=0
%       %l    prin2 items from given list, blank separated
% *     %n    do a terpri()
%       %o    print in octal
%       %q    print as with prin1 but such that looped structures are OK
%       %p    print using prin1
%       %r    As '%q'
%       %s    print as a string (equivalent to %w)
%       %t    move to given column, performing a terpri first
%             if currently beyond it.
%       %w    use prin2
%       %x    print in hexadecimal
% *     %%    print a '%' character
%       %@f   print as standard form
%       %@q   print as standard quotient
%       %@p   print as prefix form
% All except those marked with "*" use an argument.


symbolic procedure bldmsg_internal(fmt, args);
  begin
    scalar bldmsg_chars!*, u, v;
    bldmsg_chars!* := t;
    printf_internal(fmt, args);
    while not atom bldmsg_chars!* do <<
      u := cdr bldmsg_chars!*;
      rplacd(bldmsg_chars!*, v);
      v := bldmsg_chars!*;
      bldmsg_chars!* := u >>;
    return list2widestring v
  end;

symbolic procedure p_posn();
  if bldmsg_chars!* then
  begin
    scalar w, n;
    n := 0;
    w := bldmsg_chars!*;
    while not atom w and not (car w = !$eol!$) do <<
      n := n + 1;
      w := cdr w >>;
    return n
  end
  else posn();

% I want octal and hex printing. For portability I implement my own.

global '(p_hexdigits!*);

<< p_hexdigits!* := mkvect 15;
   putv(p_hexdigits!*, 0, '!0);
   putv(p_hexdigits!*, 1, '!1);
   putv(p_hexdigits!*, 2, '!2);
   putv(p_hexdigits!*, 3, '!3);
   putv(p_hexdigits!*, 4, '!4);
   putv(p_hexdigits!*, 5, '!5);
   putv(p_hexdigits!*, 6, '!6);
   putv(p_hexdigits!*, 7, '!7);
   putv(p_hexdigits!*, 8, '!8);
   putv(p_hexdigits!*, 9, '!9);
   putv(p_hexdigits!*, 10, '!a);
   putv(p_hexdigits!*, 11, '!b);
   putv(p_hexdigits!*, 12, '!c);
   putv(p_hexdigits!*, 13, '!d);
   putv(p_hexdigits!*, 14, '!e);
   putv(p_hexdigits!*, 15, '!f) >>;

symbolic procedure p_prinhex n;
  if not fixp n then p_princ("<not-a-number>", nil)
  else begin
    scalar b, w;
    if n >= 0 then <<
      while n >= 16 do <<
        b := getv(p_hexdigits!*, w := mod(n, 16)) . b;
        n := (n - w)/16 >>;
      b := getv(p_hexdigits!*, mod(n, 16)) . b >>
    else <<
      while n < -1 do <<
        b := getv(p_hexdigits!*, w := mod(n, 16)) . b;
        n := (n - w)/16 >>;
      b := '!~ . getv(p_hexdigits!*, mod(n, 16)) . b >>;
    if null bldmsg_chars!* and (posn() + length b) > !*ll!* then terpri();
    for each c in b do p_princ(c, nil)
  end;

symbolic procedure p_prinoctal n;
  if not fixp n then p_princ("<not-a-number>", nil)
  else begin
    scalar b, w;
    if n >= 0 then <<
      while n >= 8 do <<
        b := (w := mod(n, 8)) . b;
        n := (n - w)/8 >>;
      b := mod(n, 8) . b >>
    else <<
      while n < -1 do <<
        b := (w := mod(n, 8)) . b;
        n := (n - w)/8 >>;
      b := '!~ . mod(n, 8) . b >>;
    if null bldmsg_chars!* and (posn() + length b) > !*ll!* then terpri();
    for each c in b do p_princ(c, nil)
  end;

symbolic procedure printf_internal(fmt, args);
  begin
    scalar a, c, !*ll!*;
    !*ll!* := linelength nil - 2;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if c neq '!% then p_princ(c, nil)
      else <<
        c := car fmt;
        fmt := cdr fmt;
        if c = '!f then << if not bldmsg_chars!* and
                              not zerop posn() then terpri() >>  
        else if c = '!n or c = '!N then p_princ(!$eol!$, nil)
        else if c = '!% then p_princ(c, nil)
        else <<
          if null args then a := nil
          else <<
            a := car args;
            args := cdr args >>;
          if (c = '!b or c = '!B) and fixp a then
            for i := 1:a do p_princ(" ", nil)
          else if c = '!c or c = '!C then <<
% "%c" will accept either an integer or a symbol that should be a single
% character.
             if fixp a then p_princ(list2widestring list a, nil)
             else p_princ(a, nil) >> 
          else if c = '!l or c = '!L then <<
            if not atom a then <<
              portable_princ car a;
              for each x in cdr a do <<
                p_princ(" ", nil);
                portable_princ x >> >> >>
          else if c = '!o or c = '!O then p_prinoctal a
          else if c = '!p or c = '!P then portable_prin a
          else if c = '!q or c = '!Q then rlisp_prinl a
          else if c = '!r or c = '!R then <<
            p_princ("'", nil); rlisp_prinl a; p_princ("'", nil) >>
          else if (c = '!t or c = '!T) and fixp a then <<
            if p_posn() > a then p_princ(!$eol!$, nil);
            while p_posn() < a do p_princ(" ", nil) >>
% "%w", "%d" and "%s" here all just use princ. The original idea was that
% "%d" was for (decimal) integers and "%s" for strings, but there is no
% really useful optimisation to be had by trying to find type-specific
% print functions to call here.
          else if c = '!w or c = '!d or c = '!s or
                  c = '!W or c = '!D or c = '!S then portable_princ a
% As with octal output, PSL can achieve this a diffenent way and will
% generate differently formatted output.
          else if c = '!x or c = '!X then p_prinhex a
          else if c = '!@ then <<
            c := car fmt;
            fmt := cdr fmt;
            if c = '!f or c = '!F then p_prefix(prepf a, 0)
            else if c = '!q or c = '!Q then p_prefix(prepsq a, 0)
            else if c = '!p or c = '!P then p_prefix(a, 0)
            else << p_princ("%@", nil); p_princ(c, nil) >> >>
% Rather than generating an error I will display %? (where ? is any
% unrecognized character) unchanged.
          else << p_princ("%", nil); p_princ(c, nil) >> >> >> >>
  end;

symbolic macro procedure rlisp_printf u;
   list('printf_internal, cadr u, 'list . cddr u);

symbolic macro procedure rlisp_bldmsg u;
  list('bldmsg_internal, cadr u, 'list . cddr u);

flag('(rlisp_printf rlisp_bldmsg), 'variadic);


% There is a significant issue here. PSL has functions printf and
% bldmsg built in to its kernel. They are defined as regular functions
% that take an indefinite number of arguments., and it looks to me
% If I overwrite those definitions with the macro that I use here
% the result is disaster.instead I define my macros with the private
% names rlisp_printf and rlisp_bldmsg then get rlisp to map the names
% printf and bldmsg onto those. 
% I follow this path on both CSL and PSL even though there are no terrible
% clashes with CSL.

put('printf, 'newnam, 'rlisp_printf);
put('bldmsg, 'newnam, 'rlisp_bldmsg);
put('prinl,  'newnam, 'rlisp_prinl);

endmodule;

end;
