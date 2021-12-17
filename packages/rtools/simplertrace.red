module simplertrace; % Crude tracing but with output compatible across Lisps

% Author: Arthur Norman.

% Copyright (c) 2021 Arthur Norman.  All rights reserved.

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

% $Id$

% The intent of simple!-trace is that the ouput that it leads to should
% match as between CSL, PSL and other Lisp systems, while the native trace
% facilities may be better in various ways but could be harder to use
% with file-comprisons on log files. The output may in fact not be
% independent of the Lisp. One particular issue is that when a function
% is recursive the calls to itself may go via the mechanism that lets this
% code intercept them, it may take shortcuts, or the recursion may have been
% mapped onto iteration.
%
% I do not provide a simple!-untrace function, and I do not protect against
% multiple calls to simple!-trace that will confuse things if any function
% is selected for tracing multiple times. Also attempts to trace any of the
% functions used here (except getd and putd which I take special care with)
% could lead to disaster.
%
% I am tolerably comfortable with these restrictions because this code is
% intended for use while debugging rather than in production use, so those
% have find any of its limitations awkwards are qualified to upgrade it.
%
% I can imagine some people wanting to install features that limit the depth
% to which functions are traced, or set start and end count limits for
% tracing, and may come back when I find myself wanting any such.

copyd('!~!~saved_getd, 'getd);
copyd('!~!~saved_putd, 'putd);

% I will need to know how many arguments the function I am going to trace
% has, and I will not be able to cope with FEXPRS or &opt or &rest, and
% with CSL I will not manage to extract that information in the case of
% some built-in functions that take 4 or more arguments.

#if (memq 'psl lispsystem!*)

symbolic procedure s!:argcount fn;
  begin
    scalar n;
    if fixp (n := get(fn, 'number!-of!-args)) then return n;
    n := getd fn;
    if not eqcar(n, 'expr) then return nil;
    n := cdr n;
    if codep n then return code!-number!-of!-arguments n
    else if eqcar(n, 'lambda) then return length cadr n
    else return nil
  end;

#else

symbolic procedure s!:argcount fn;
  begin
    scalar n;
    if (n := get(fn, number!-of!-args)) then return n
    else if (n := symbol!-argcount fn) then return n
    else return nil
  end;

#endif

symbolic procedure s!:traced!-version(fn, nargs, newfn);
  begin
    scalar r := gensym(), k := 0, v := for i := 1:nargs collect gensym(), p;
    p := list('prog, list r,
            '(cond ((null (zerop (posn))) (terpri))),
            list('prin2, "Entering "),
            list('print, mkquote fn),
            'progn . for each x in v collect
                list('progn, list('prin2, "Arg"),
                             list('prin2, k := k+1),
                             list('prin2, ": "),
                             list('print, x)),
            list('setq, r, newfn . v),
            '(cond ((null (zerop (posn))) (terpri))),
            list('prin1, mkquote fn),
            list('prin2, " = "),
            list('print, r),
            list('return, r));
    return list('lambda, v, p)
  end;
   
symbolic procedure s!:trace fn;
  begin
    scalar d := !~!~saved_getd fn, nargs, !*redefmsg,
           g := intern list2string append(explode2 "~saved_", explode2 fn),
           !*comp := t, !*pwrds := nil;
    if not eqcar(d, 'expr) or
       null (nargs := s!:argcount fn) then <<
       if not zerop posn() then terpri();
       prin2 "+++ ";
       prin1 fn;
       prin2 " not traceable";
       return terpri() >>;
    !~!~saved_putd(g, car d, cdr d);
    !~!~saved_putd(fn, 'expr,
       s!:traced!-version(fn, nargs, g));
  end;

symbolic procedure simple!-trace l;
  for each x in l do s!:trace x;

endmodule;

end;
