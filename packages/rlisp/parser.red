module parser;  % Functions for parsing RLISP expressions.

% Author: Anthony C. Hearn.

% Copyright (c) 1991 The RAND Corporation.  All rights reserved.

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

% $Id: $

fluid '(!*backtrace);

global '(cursym!*);

% With the exception of assignment statements, which are handled by
% XREAD, statements in REDUCE are introduced by a key-word, which
% initiates a reading process peculiar to that statement.  The key-word
% is recognized (in XREAD1) by the indicator STAT on its property list.
% The corresponding property is the name of the function (of no
% arguments) which carries out the reading sequence.

% ***** COMMENTS *****

symbolic procedure comm1 u;
   begin scalar bool;
      if u = 'end then scan();
      while not
         (cursym!* = '!*semicol!* or
          (u = 'end and
           cursym!* memq '(end else then until !*rpar!* !*rsqbkt!*))) do <<
         if u = 'end and null bool then <<
            lprim list("END-COMMENT NO LONGER SUPPORTED");
            bool := t >>;
         scan() >>
   end;


% ***** CONDITIONAL STATEMENT *****

symbolic procedure ifstat;
   begin scalar condx,condit;
    a:  condx := xread t;
        if not(cursym!* = 'then) then symerr('if,t);
        condit := aconc!*(condit,list(condx,xread t));
        if not(cursym!* = 'else) then nil
         else if scan() = 'if then go to a
         else condit := aconc!*(condit,list(t,xread1 t));
        return ('cond . condit)
   end;

put('if,'stat,'ifstat);

flag ('(then else),'delim);


% ***** FUNCTION STATEMENT *****

symbolic procedure functionstat;
   begin scalar x;
      x := scan();
      return list('function,
                  if x = '!*lpar!* then xread1 t
                  else if idp x and null(x = 'lambda) then << scan(); x >>
                  else symerr("Function", t))
   end;

put('function,'stat,'functionstat);


% ***** LAMBDA STATEMENT *****

symbolic procedure lamstat;
   begin scalar x,y;
        x:= xread 'lambda;
        if x then x := remcomma x;
        y := list('lambda,x,xread t);
        return y
   end;

put ('lambda,'stat,'lamstat);


% ***** GROUP STATEMENT *****

symbolic procedure readprogn;
   %Expects a list of statements terminated by a >>;
   begin scalar lst;
      lst := list xread 'group;
      while not (cursym!* = '!*rsqbkt!*) do
         lst := aconc!*(lst,xread 'group);
      scan();
      return ('progn . lst)
   end;

put('!*lsqbkt!*,'stat,'readprogn);

flag ('(!*lsqbkt!*),'go);

flag('(!*rsqbkt!*),'delim);

flag('(!*rsqbkt!*),'nodel);

% ***** END STATEMENT *****

symbolic procedure endstat;
  %This procedure can also be used for any key-words  which  take  no
  %arguments;
  begin
    scalar x;
    x := cursym!*;
    comm1 'end;
    return list x
  end;

put('end,'stat,'endstat);

put('endmodule,'stat,'endstat);

put('bye,'stat,'endstat);

put('quit,'stat,'endstat);

flag('(bye quit),'eval);

symbolic procedure endstat1;
  % A keyword that can optionally be followed with a string.
  begin
    scalar x, optarg;
    x := cursym!*;
    scan();
    if stringp cursym!* then optarg := cursym!*;
    while not (cursym!* = '!*semicol!*) and
% The next line is to allow for an ENDSTAT1 to omit the semicolon that
% would normally come after it if what happens next is a word like
% ">>" or "else"...
          not (idp cursym!* and flagp(cursym!*, 'delim)) do scan();
    return list(x, optarg)
   end;

put('showtime,'stat,'endstat1);
% showtime, showtime1, showtime2 and showtime3 will just be independent
% timing statements so that one can be used without interfering with
% any of the others.
put('showtime1,'stat,'endstat1);
put('showtime2,'stat,'endstat1);
put('showtime3,'stat,'endstat1);

% "resettime" re-bases the counter but does not print anything.
put('resettime,'stat,'endstat);
put('resettime1,'stat,'endstat);
put('resettime2,'stat,'endstat);
put('resettime3,'stat,'endstat);

endmodule;

end;
