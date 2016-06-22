% ifdefs.red                                       Copyright A C Norman 2016


%/**************************************************************************
% * Copyright (C) 2016, Codemist.                         A C Norman       *
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
% * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE * POSSIBILITY OF SUCH *
% * DAMAGE.                                                                *
% *************************************************************************/

% $Id$

%
% This is a small file put here because it was where I was getting my
% thoughts clear on pre-processing. It may be of interest to anybody else
% who wishes to implement something like the C/C++ "#ifdef" scheme for
% conditional inclusion.


lisp;


% The preprocessor tokens I will notice are
%    iftrue
%    iffalse
%    else
%    eliftrue
%    eliffalse
%    endif
% and I will use (Lisp) "read" to read items here. In a real use
% I would use some read_token() function to get the symbols that I test
% for, and the single tokens like "iftrue" here would correspond to
% sequences like "#ifdef WORD" in the case that WORD did happen to be
% defined, while "iffalse" would stand for the case when it was not.
%
% The basic idea is that I support
%    if<bool>
%    ...
%    elif<bool>
%    ...
%    else
%    ...
%    endif
% and I provide a single function (here called next()) that will process
% the directives and return itms of the enclosed material "...".
%
% There are a few issues in this code that some may view as odd. The
% first is the treatment of "else", "elif" and "endif" when there has
% not been a preceeding "if". The behaviour here will be as if there
% had been an "iftrue" just before the start of the input. If one wanted
% to flag such cases as error tha would be fairly easy - one way would be
% to have a counter that was incremented by "if" and decremented by "endif"
% since that would make it trivial to detect the out of context directives.
% The second oddity is that "else" is handled here exactly as if it was
% "eliftrue". It is clear that one can have a sequence of "elif" sections
% and just the first where the condition is true leads to output. So in
%   iffalse
%   XXX
%   else
%   YYY
%   else
%   ZZZ
%   endif
% the material XXX is omitted becase of the "iffalse". Then YYY is included
% because of the "else", but then ZZZ is treated as a third possibility and
% so even though the second "else" is handled as "eliftrue" the text ZZZ
% ends up discarded.
% Then there is the issue of missing "endif"s at the end of file. The sort
% of counter that records "if" nesting could be used to police that issue
% reasonably easily.
% Here I have preferred the simplest code I can - and also if there were
% preprocessor error to be reported the form of the diagnostics to be
% generated would need to fit the application. 


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% the following two procedures skip input until they reach the
% symbol concerned. they match "if ... endif" groups along the way.

symbolic procedure skip_to_endif();
  begin
    scalar w;
    while (w := read()) neq 'endif do <<
      if w = 'iftrue or w = 'iffalse then skip_to_endif() >>;
    return t
  end;

symbolic procedure skip_to_else();    % or to "elif true"
  begin
    scalar w;
    while (w := read()) neq 'endif and
          w neq 'else and
          w neq 'eliftrue do <<
      if w = 'iftrue or w = 'iffalse then skip_to_endif() >>;
    return t
  end;

symbolic procedure process_directive w;
  if w = 'iftrue or w = 'endif then t
  else if w = 'iffalse then skip_to_else()
  else if w = 'else or w = 'eliftrue or w = 'eliffalse then skip_to_endif()
  else nil;

% next() is the main function that returns an item from the input,
% processing "if" and friends and discarding anything that is not wanted.
  
symbolic procedure next();
  begin
    scalar w;
    while process_directive (w := read()) do nil;
    return w
  end;

% For testing purposes I will display the parts of the input that survive
% in some test material.

symbolic procedure process();
  begin
    scalar w;
    while (w := next()) neq 'done do print w;
  end;

process();

% My test material uses a two-level nest of directives
%       if<bool>
%           if<bool>
%           elif<bool>
%           elif<bool>
%           endif
%       else
%           if<bool>
%           elif<bool>
%           elif<bool>
%           endif
%       endif
%
% There are examples of this intended to exercise all possible combinations
% of the boolean conditions. Between the directives I have put text that
% contains a marker showing where it is and a "yes" or "no" indicating
% whether I expect it to end up as part of the output. So the output is
% expected to be all the lines from here that have "yes" in them. And my
% hope is that testing with the level of nesting used here and with all
% these cases will count as complete coverage.

iftrue

(true)
  iftrue
  (iftrue truetruetrue 1 yes)
  eliftrue
  (iftrue truetruetrue 2 no)
  eliftrue
  (iftrue truetruetrue 3 no)
  endif

  iffalse
  (iftrue falsetruetrue 1 no)
  eliftrue
  (iftrue falsetruetrue 2 yes)
  eliftrue
  (iftrue falsetruetrue 3 no)
  endif

  iftrue
  (iftrue truefalsetrue 1 yes)
  eliffalse
  (iftrue truefalsetrue 2 no)
  eliftrue
  (iftrue truefalsetrue 3 no)
  endif

  iffalse
  (iftrue falsefalsetrue 1 no)
  eliffalse
  (iftrue falsefalsetrue 2 no)
  eliftrue
  (iftrue falsefalsetrue 3 yes)
  endif

  iftrue
  (iftrue truetruefalse 1 yes)
  eliftrue
  (iftrue truetruefalse 2 no)
  eliffalse
  (iftrue truetruefalse 3 no)
  endif

  iffalse
  (iftrue falsetruefalse 1 no)
  eliftrue
  (iftrue falsetruefalse 2 yes)
  eliffalse
  (iftrue falsetruefalse 3 no)
  endif

  iftrue
  (iftrue truefalsefalse 1 yes)
  eliffalse
  (iftrue truefalsefalse 2 no)
  eliffalse
  (iftrue truefalsefalse 3 no)
  endif

  iffalse
  (iftrue falsefalsefalse 1 no)
  eliffalse
  (iftrue falsefalsefalse 2 no)
  eliffalse
  (iftrue falsefalsefalse 3 no)
  endif

else
(false)

  iftrue
  (iftrue_else truetruetrue 1 no)
  eliftrue
  (iftrue_else truetruetrue 2 no)
  eliftrue
  (iftrue_else truetruetrue 3 no)
  endif

  iffalse
  (iftrue_else falsetruetrue 1 no)
  eliftrue
  (iftrue_else falsetruetrue 2 no)
  eliftrue
  (iftrue_else falsetruetrue 3 no)
  endif

  iftrue
  (iftrue_else truefalsetrue 1 no)
  eliffalse
  (iftrue_else truefalsetrue 2 no)
  eliftrue
  (iftrue_else truefalsetrue 3 no)
  endif

  iffalse
  (iftrue_else falsefalsetrue 1 no)
  eliffalse
  (iftrue_else falsefalsetrue 2 no)
  eliftrue
  (iftrue_else falsefalsetrue 3 no)
  endif

  iftrue
  (iftrue_else truetruefalse 1 no)
  eliftrue
  (iftrue_else truetruefalse 2 no)
  eliffalse
  (iftrue_else truetruefalse 3 no)
  endif

  iffalse
  (iftrue_else falsetruefalse 1 no)
  eliftrue
  (iftrue_else falsetruefalse 2 no)
  eliffalse
  (iftrue_else falsetruefalse 3 no)
  endif

  iftrue
  (iftrue_else truefalsefalse 1 no)
  eliffalse
  (iftrue_else truefalsefalse 2 no)
  eliffalse
  (iftrue_else truefalsefalse 3 no)
  endif

  iffalse
  (iftrue_else falsefalsefalse 1 no)
  eliffalse
  (iftrue_else falsefalsefalse 2 no)
  eliffalse
  (iftrue_else falsefalsefalse 3 no)
  endif


endif

iffalse
(false)
  iftrue
  (iffalse truetruetrue 1 no)
  eliftrue
  (iffalse truetruetrue 2 no)
  eliftrue
  (iffalse truetruetrue 3 no)
  endif

  iffalse
  (iffalse falsetruetrue 1 no)
  eliftrue
  (iffalse falsetruetrue 2 no)
  eliftrue
  (iffalse falsetruetrue 3 no)
  endif

  iftrue
  (iffalse truefalsetrue 1 no)
  eliffalse
  (iffalse truefalsetrue 2 no)
  eliftrue
  (iffalse truefalsetrue 3 no)
  endif

  iffalse
  (iffalse falsefalsetrue 1 no)
  eliffalse
  (iffalse falsefalsetrue 2 no)
  eliftrue
  (iffalse falsefalsetrue 3 no)
  endif

  iftrue
  (iffalse truetruefalse 1 no)
  eliftrue
  (iffalse truetruefalse 2 no)
  eliffalse
  (iffalse truetruefalse 3 no)
  endif

  iffalse
  (iffalse falsetruefalse 1 no)
  eliftrue
  (iffalse falsetruefalse 2 no)
  eliffalse
  (iffalse falsetruefalse 3 no)
  endif

  iftrue
  (iffalse truefalsefalse 1 no)
  eliffalse
  (iffalse truefalsefalse 2 no)
  eliffalse
  (iffalse truefalsefalse 3 no)
  endif

  iffalse
  (iffalse falsefalsefalse 1 no)
  eliffalse
  (iffalse falsefalsefalse 2 no)
  eliffalse
  (iffalse falsefalsefalse 3 no)
  endif

else
(true)

  iftrue
  (iffalse_else truetruetrue 1 yes)
  eliftrue
  (iffalse_else truetruetrue 2 no)
  eliftrue
  (iffalse_else truetruetrue 3 no)
  endif

  iffalse
  (iffalse_else falsetruetrue 1 no)
  eliftrue
  (iffalse_else falsetruetrue 2 yes)
  eliftrue
  (iffalse_else falsetruetrue 3 no)
  endif

  iftrue
  (iffalse_else truefalsetrue 1 yes)
  eliffalse
  (iffalse_else truefalsetrue 2 no)
  eliftrue
  (iffalse_else truefalsetrue 3 no)
  endif

  iffalse
  (iffalse_else falsefalsetrue 1 no)
  eliffalse
  (iffalse_else falsefalsetrue 2 no)
  eliftrue
  (iffalse_else falsefalsetrue 3 yes)
  endif

  iftrue
  (iffalse_else truetruefalse 1 yes)
  eliftrue
  (iffalse_else truetruefalse 2 no)
  eliffalse
  (iffalse_else truetruefalse 3 no)
  endif

  iffalse
  (iffalse_else falsetruefalse 1 no)
  eliftrue
  (iffalse_else falsetruefalse 2 yes)
  eliffalse
  (iffalse_else falsetruefalse 3 no)
  endif

  iftrue
  (iffalse_else truefalsefalse 1 yes)
  eliffalse
  (iffalse_else truefalsefalse 2 no)
  eliffalse
  (iffalse_else truefalsefalse 3 no)
  endif

  iffalse
  (iffalse_else falsefalsefalse 1 no)
  eliffalse
  (iffalse_else falsefalsefalse 2 no)
  eliffalse
  (iffalse_else falsefalsefalse 3 no)
  endif

endif

done

end;
% end of ifdefs.red
