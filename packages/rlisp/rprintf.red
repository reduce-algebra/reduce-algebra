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


% BEWARE - at this stage in the building process I can not use
% (memq 'psl lispsystem!*) because lispsystem!* may not be fully set up.

#if (not !*psl)

% PSL already has printf and bldmsg built into it. By putting these
% definitions here I perhaps make the functions more visible and more
% obviously globally available.


% The special sequences that can occur in format strings are as follows.
% I will make my tests for directives case insensitive, so for instance
% either %b or %B will be recognized.
%       %b    do that many spaces
%       %c    next arg is a character code. display character
%       %d    print an integer (equivalent to %w)
% *     %f    do a terpri() unless posn()=0
% @     %l    prin2 items from given list, blank separated
% *     %n    do a terpri()
%       %o    print in octal
%       %p    print using prin1
%       %r    As '%p'
%       %s    print as a string (equivalent to %w)
%       %t    move to given column, performing a terpri first
%             if currently beyond it.
%       %w    use prin2
%       %x    print in hexadecimal
% *     %%    print a '%' character
% All except those marked with "*" use an argument.
% The options marked with "@" may not be available in PSL.


symbolic macro procedure printf u;
   list('printf!-internal, cadr u, 'list . cddr u);

symbolic macro procedure bldmsg u;
  list('bldmsg!-internal, cadr u, 'list . cddr u);

symbolic procedure bldmsg!-internal(fmt, args);
  begin
% Use printf, but with output to be collected into a string.
    scalar r, dest, save;
% This uses a feature where output can be sent to a "stream" such that the
% characters sent can later bo retrieved as a string. The function names
% involved are taken from Common Lisp.
    dest := make!-string!-output!-stream();
    save := wrs dest;
    printf!-internal(fmt, args);
    r := get!-output!-stream!-string dest;
    close dest;
    wrs save;
    return r
  end;

symbolic procedure printf!-internal(fmt, args);
  begin
    scalar a, c;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if not (c = '!%) then princ c
      else <<
        c := car fmt;
        fmt := cdr fmt;
        if c = '!f then << if not zerop posn() then terpri() >>  
        else if c = '!n or c = '!N then terpri()
        else if c = '!% then princ c
        else <<
          if null args then a := nil
          else <<
            a := car args;
            args := cdr args >>;
          if (c = '!b or c = '!B) and fixp a  then for i := 1:a do princ " "
% "tyo" can take either an integer (in which case it treats that as a
% character code) or a symbol (in which case it uses its first charafter,
% or a not-quite-supported raw CSL character object.
          else if c = '!c or c = '!C then tyo a
          else if c = '!l or c = '!L then <<
            if not atom a then <<
              princ car a;
              for each x in cdr a do << princ " "; princ x >> >> >>
% PSL can print in octal by resetting an "output base" variable, but there
% is no expecxtation that the exact format used will match what CSL prints.
          else if c = '!o or c = '!O then prinoctal a
          else if c = '!p or c = '!P then prin a
          else if c = '!r or c = '!R then << princ "'"; prin a; princ "'" >>
          else if (c = '!t or c = '!T) and fixp a then <<
            if posn() > a then terpri();
            ttab a >>
% "%w", "%d" and "%s" here all just use princ. The original idea was that
% "%d" was for (decimal) integers and "%s" for strings, but there is no
% really useful optimisation to be had by trying to find type-specific
% print functions to call here.
          else if c = '!w or c = '!d or c = '!s or
                  c = '!W or c = '!D or c = '!S then princ a
% As with octal output, PSL can achieve this a diffenent way and will
% generate differently formatted output.
          else if c = '!x or c = '!X then prinhex a
% Rather than generating an error I will display %? (where ? is any
% unrecognized character) unchanged. 
          else << princ "%"; princ c >> >> >> >>
  end;

flag('(printf bldmsg), 'variadic);

#endif

endmodule;

end;

