module ldb;   % A bit of a debugger

% Author: Arthur Norman

% Copyright (c) 2024 Arthur Norman.

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

% $Id: ldb.red 6859 2024-08-11 15:41:48Z arthurcnorman $


fluid '(!*ldb !*ldbdepth !*ldbname !*ldbcount !*ldbstart);
!*ldb := nil;
!*ldbdepth := 0;
!*ldbname := 'unnamed;
!*ldbcount := 0;
!*ldbstart := nil;

% If !*ldbstart is nil then a message is printed for every 1000 uses of
% ldb!-callback, in the form
%    ~~~~~ !*ldbcount = NNNNN
% but nothing more. If !*ldbstart is a number then tracing of all
% functions where ldbtrace has enabled it starts after that many steps.
% The intended use is that you first run with !*ldbstart=nil and observe
% the last reported count before you see something go wrong. And then
% re-run with that count value set up to be when tracing begins. It will
% be within 1000 of where the problem arises. This can avoid the generation
% of truly huge amounts of trace output. Obviously it is not going to be
% a recipe fror helping everybody, but it may be good for some people!

switch ldb;
off ldb;

fluid '(print!-limit);

% If I generate a many trace records it can be really bad if each is
% individually bulky. So here I have a version of prin1 that truncates
% its output so you get the start of something but never too much.

symbolic procedure prinn u;
  begin
    scalar print!-limit := 15;
    prinn1 u
  end;

symbolic procedure prinn1 u;
  if print!-limit > 0 then <<
    print!-limit := print!-limit-1;
    if vectorp u then begin
      scalar i, n;
      n := upbv u;
      if n = 0 then <<
        prin2 "[]";
        return nil >>;
      prin2 "[";
      prinn1 elt(u, 0);
      i := 1;
      while i<=n and print!-limit > 0 do <<
        prin2 " ";
        prinn elt(u, i);
        i := i+1 >>;
      if print!-limit <= 0 then princ "..";
      prin2 "]";
    end
    else if atom u then prin1 u
    else <<
      prin2 "(";
      prinn1 car u;
      while not atom (u := cdr u) and print!-limit > 0 do <<
        prin2 " ";
        prinn car u >>;
      if u and atom u then <<
        prin2 " . ";
        prin1 u >>;
      if print!-limit <= 0 then princ "..";
      prin2 ")" >> >>;

fluid '(!*ldbbreak !*ldbignore);

% This is at present a stub of what could possibly become a Lisp debugger
% capable of providing breakpoints and single stepping. As is common for
% such debuggers, the code that is to be handled needs to be compiled with
% special options for this to be possible. Here the requirement is that the
% switch "ldb" is set when code is read in. The code is then processed by
% "form" as always, and at that stage extra function calls are injected.
% These calls to ldb!-callback specify an "action" which can be 'enter,
% 'step or 'return. They provide the name of the function involved, and
% an integer that combines the depth of nesting of function calls with
% a sequence number that identified individual steps within the function.
% There is then a list of the names of all local variables and finally
% a list of their values.
% For CSL it may be useful to set the "savedef" switch as well, because then
% the function definition before compilation is preserved under the !*savedef
% property (of course if the function is not compiled its definition is
% available via getd). Also if (with bootstrapreduce) functions had been
% defined earlier and may be in loadable modules then load!-source() recovers
% the associated saved definitions.

% So the concept here is that ldb!-callback gets control very frequently
% and has access to information that allows it to respond when some
% particular function is called or when that function returns a value (it
% does not get to see if the function exits because of an error or a throw).
% It is also woken up each time a step is taken within a prog or progn, so
% it could merely return until it reached a point that it wanted to inform
% the user of. It is a bit messy but it can tie exactly where it is to
% (the Lisp form) of the function being investigated. To do this it recovers
% the Lisp definition (using !*savedef or getd). For 'enter or 'return that
% is it. For 'step it can scan the definition to find the embedded call to
% ldb!-callback that cites the sequence number it was provided with. It
% would also be possible to transform the definition to remove all these
% instrumenting calls and get back to a version at least close to the one
% the user had provided, and that could be used when presenting reports.
% The recursion depth information could be used to allow ldb!-callback to
% ignore all activity at deeper levels, thereby supporting a "take one
% evaluation step at this level". My hope is that the majority of the
% breaking, stepping and displaying actions expected in a typical debugger
% could be supported. The biggest limitation is that the code that is
% to be debugged is what comes out of the rlisp parser as adapted by "form",
% so for instance "for" and "for each" statements have been expanded into
% loops that mechanise them. This is also only intended for use in symbolic
% mode because it is working at quite low level of abstraction.

% I somewhat hope that somebody will see all this and pick up a project
% of making a debugger out of this. If that happens it may make sense to
% migrate the current CSL-only "savedef" scheme so that preserving definitions
% is done by the Reduce parser (and I am confident that would be pretty
% simple).

% For now and mainly as a test and demonstration of this I have here a
% rather crude scheme that causes it to trace execution but in a way
% that differs from "trace/tr" and "traceset" by reporting on steps
% within a function. Following "ldbtrace '(fff);" all calls to
% ldb!-callback from within fff will display the information that they
% have. 


symbolic procedure ldbtrace ll;
  flag(ll, 'ldbtrace);

% Because this is a placeholder I am not going to bother with ldbuntrace
% even though its definition would be shorter than this comment.

symbolic procedure ldb!-callback(action, fname, depth, names, vals);
  begin

    !*ldbcount := add1 !*ldbcount;
    if remainder(!*ldbcount, 1000) = 0 then <<
      princ "~~~~~ !*ldbcount = ";
      print !*ldbcount >>;
    if null !*ldbstart or
       !*ldbcount < !*ldbstart then return nil;

% The code here is more or less deliberately very naive!

    if flagp(fname, 'ldbtrace) and action='enter then <<
      optterpri();
      prin2 "Calling ";
      prinn fname;
      prin2 " level ";
      prinn depth;
      for each v in pair(names, vals) do <<
        prin2 " ";
        prinn car v;
        prin2 "=";
        prinn cdr v >>;
      terpri();
      return nil >>;

    if flagp(fname, 'ldbtrace) and action='return then <<
      optterpri();
      prin2 "Value of ";
      prinn fname;
      prin2 " level ";
      prinn depth;
      prin2 " = ";
      prinn car vals;
      terpri();
      return nil >>;

    if flagp(fname, 'ldbtrace) and action='step then <<
      optterpri();
      prin2 "Step within ";
      prinn fname;
      prin2 " level ";
      prinn remainder(depth, 1000000);
      prin2 " step ";
      prin1 (depth/1000000);
      for each v in pair(names, vals) do <<
        prin2 " ";
        prinn car v;
        prin2 "=";
        prinn cdr v >>;
      terpri();
      return nil >>;

    return nil;
  end;

endmodule;

end;
