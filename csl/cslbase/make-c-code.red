% make-c-code.red                          Copyright (C) Codemist 2016-2021

%**************************************************************************
%* Copyright (C) 2021, Codemist.                         A C Norman       *
%*                                                                        *
%* Redistribution and use in source and binary forms, with or without     *
%* modification, are permitted provided that the following conditions are *
%* met:                                                                   *
%*                                                                        *
%*     * Redistributions of source code must retain the relevant          *
%*       copyright notice, this list of conditions and the following      *
%*       disclaimer.                                                      *
%*     * Redistributions in binary form must reproduce the above          *
%*       copyright notice, this list of conditions and the following      *
%*       disclaimer in the documentation and/or other materials provided  *
%*       with the distribution.                                           *
%*                                                                        *
%* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
%* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
%* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
%* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
%* COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
%* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
%* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
%* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
%* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
%* TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
%* THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
%* DAMAGE.                                                                *
%*************************************************************************/

% $Id$

on echo, backtrace;
off int;

% This file can be run to turn bits of the REDUCE source code
% into C so that this C can be compiled and linked in to make a
% customised CSL executable that will red REDUCE faster.
%
% Run this using bootstrapreduce.img to select code to compile into C.
% The functions to be compiled are extracted from a file "profile.dat"
% that was created by "profile.red".
%
% I will also allow for a file "unprofile.dat" that can be used to provide
% extra help with modules where the module maintainer is unable to provide
% test cases that generate reliable profile date.
%
% If full_c_code is defined then rather than paying much attention
% to profile.dat it attempts to compile everything into C! Note that
% this capability causes BUGS to surface at present (I will remove this
% comment when I believe I have got past that state!) so it is just
% for hackers and experimenters.

symbolic;

% If anything goes wrong here I want a backtrace so I can debug it,
% regardless of any errorsets etc.

enable!-errorset(3, 3);

% Three major parameters are available:
%
%   fnames       a list of files to create. Making the list longer (or
%                shorter) changes the amount of C that can be created.
%                The CSL source code has to know how many there are, and
%                its current default is for 12 files.
%
%   size_per_file
%                this guides the compiler about how much to put in each
%                generated file, where the value 7000 results in each
%                file of generated C being in the range 120 to 150 Kbytes.
%
%   force_count  indicates how many functions from alg.tst statistics should
%                be included before anything else. The idea for this is
%                rooted in old days when alg.tst was *THE* Reduce test and
%                overall performance was often judged solely on how well
%                it ran. I will now make the value of force_count rather
%                small so as not to perturb more globally rational profile-
%                based judgements! But in fact most of the things that are
%                heavily used in alg.tst are used elswehere. I suspect that
%                these days the only exceptions will be the high energy
%                physics stuff. 
%

%
% Also if "how_many" is set then this will limit the total number of
% functions that are compiled into C. Since I expect to pass that via a
% command line   "-dhow_many=362"  etc I allow for it being a string
% not a number to start with. In ordinary circumstances this will not be
% used, however it has proved INVALUABLE when tracking down cases where
% compilation into C causes changes in behaviour... how_many can be used
% with a binary-chop selection process to discover exactly which function
% causes upset when compiled into C.  Of course in release quality code I
% hope there are no such cases! I will also check an environment variable
% "HOW_MANY".

fluid '(fnames size_per_file force_count how_many everything cx);

if boundp 'full_c_code and eval 'full_c_code then everything := t
else everything := nil;

fnames := '(      "u01" "u02" "u03" "u04"
            "u05" "u06" "u07" "u08" "u09"
            "u10" "u11" "u12" "u13" "u14"
            "u15" "u16" "u17" "u18" "u19"
            "u20" "u21" "u22" "u23" "u24"
            "u25" "u26" "u27" "u28" "u29"
            "u30" "u31" "u32" "u33" "u34"
            "u35" "u36" "u37" "u38" "u39"
            "u40" "u41" "u42" "u43" "u44"
            "u45" "u46" "u47" "u48" "u49"
            "u50" "u51" "u52" "u53" "u54"
            "u55" "u56" "u57" "u58" "u59"
            "u60"
);

% As of mid 2021 a size_per_file of 74000 and a limit of 21000 functions
% to be converted allows all of Reduce to be mapped into C++ within the
% file u01.cppp to u60.cpp. Each of those source files can be up to 1.5
% megabytes, 60000 lines of generated C++. On one sample build this resulted
% in the Reduce executable being about 21 Mbytes. Which these days may even
% not count as being too bad!

if boundp 'size_per_file and
   numberp (cx := compress explodec size_per_file) and
   cx > 100 and cx < 200000 then size_per_file := cx
else if everything then size_per_file := 74000
else size_per_file := 7000;

<< terpri(); princ "size_per_file = "; print size_per_file; nil >>;

% At the time of writing these are the top 5 functions used by alg.tst
%
%  (noncomp 363494365036146324 11 285540)
%  (simpcar 1247942846384282646 7 167232)
%  (reval 607148151428708743 8 186615)
%  (terminalp 570814658694331872 12 229779)
%  (delcp 2216652391477548477 8 131682)

force_count := 5;

% You may well ask "what is it with the number 3500 here". Well that sets
% a default number of functions to be compiled into C that matches the
% number I used historically, and hence it provides a safe level of
% continuity. You may experiment with
%     make c-code how_many=nnnn
% and do so either to see how the speed/space tradeoff goes or because you
% are concerned about a possible bug in the Lisp to C compilation step. My
% current measurements suggest that 3500 gives reasonable trade off for
% build of the executable vs. performance. However for use with an embedded
% system with limited memory I might suggest say 500.

begin
  scalar e;
  e := getenv "HOW_MANY";
  if e then <<
    how_many := compress explodec e >>
end;

if not numberp how_many and not stringp how_many then <<
  if everything then how_many := 25000
  else how_many := 3500 >>
else <<
  how_many := compress explodec how_many;
  if not numberp how_many then how_many := 3500 >>;

<< terpri(); princ "how_many = "; print how_many; nil >>;

global '(omitted at_start at_end);

% At any stage there may be some things that I must not even try to compile
% into C because of bugs or limitations. I can list them here. This is very
% UGLY and delicate, and so ideally I will upgrade the compilation into C++
% to remove most of these limitations eventually.

% It is now some while since I checked all of these - I should review
% them soon!!!

omitted := '(
% The "bootstrapping issues" are eg cases where some function gets called
% from buildreduce.lsp at a stage before it has got as far as ensuring that
% the C++ code has been fully integrated into the Lisp world by scanning
% u*.lsp etc. I can potentially investigate and fix this... but it may
% be that each case has its own wrinkles.
    begin                   % bootstrapping issue
    module2!-to!-file       % ditto
    olderfaslp              % ditto
    package!-remake2        % ditto
    update!-fasl2           % ditto
    upd!-fasl1              % ditto
    update_prompt           % ditto
    prinl                   % ditto
    printl
    princl
    printcl
    s!:prinl0
    s!:prinl1
    s!:prinl2
    fluid                   % the env cells of these get out of step during..
    global                  % a bootstrap build if they are compiled here.
    aftergcsystemhook       % On slow machines the C code may not end up
                            % fully usable quite early enough?

% Some items in the CSL code use the Common Lisp &optional scheme and I
% have not arranged for the conversion into C++ to deal with that, I could
% but it would probably be more work than is justified.
    compile!-file!*         % &optional
    s!:compile!-file!*      % &optional
    fetch!-url              % &optional

% These ones maybe just need some debugging work to make them work!
    pasf_bapprox            % Unknown issue!
    divdm                   %
    gck2                    %
    !:recip                 %
    cr!:minus               %


% In my original scheme for compilation into C/C++ there were big problems
% if the code had multiple confliccting definitions and where it used
% putd/getd/copyd to move definitions from one place to another. There can
% still be problems but I hope that a newer (2021) scheme will make these
% less challenging and I will be able to remove some of these from the
% exclusion list.

%   linelength              % horrid use of copyd etc in tmprint.red
%   setpchar                % horrid use of copyd.. also in tmprint.red
%   unit                    % name conflict.
%   typerr                  % typerr and symerr are defined in makereduce.lsp
%   symerr                  % but there are different versions elsewhere.

% unwind-protect and catch could now almost certainly be supported by the
% compiler, and then the following become eligible for optimisation. The
% move from use of C to C++ simplifies this quite significantly.

    knowledge_about         % unwind-protect
    let00                   % ditto
    evalletsub2             % ditto
    clear                   % ditto
    reval!-without          % ditto
    subeval                 % ditto
    ezgcdf                  % ditto
    transcendentalcase      % ditto
    p_prinl0                % ditto
    s!:prinl0               % ditto
    prem                    % ditto
    taylorexpand            % ditto
    taylorexpand!-diff      % ditto

    errorset_with_timeout   % catch
    probably_zero           % ditto
    read_one_rubi_test      % ditto
    safe_evaluate           % ditto
    );

at_start := '(
    );

at_end := '(
    );

on comp;

load!-module 'remake;

fluid '(w_reduce requests);

w_reduce := requests := nil;

% I make a list of all the functions that profile data suggests that
% I should compile into C.  The master copy of the profile data is
% usually expected to be in "$destdir".

symbolic procedure read_profile_data file;
  begin
    scalar ee, w0, w1;
% The enable!-errorset is to do with controlling the visibility of
% error messages if the file containig profile data does not exist or
% if the data within it is corrupted. This is here because the code
% tries to scan a file "unprofile.dat" where people could have put
% manually selected entries. But in most cases that file will not be
% present. The use of "errorset(X,nil,nil)" would normally make
% errors silent, but for debugging reasons I may have overridden that
% gobally though this file. I want to restore the normal state just in
% this segment.
    ee := enable!-errorset(0, 3);
    if not errorp(w0 := errorset(list('open, file, ''input), nil, nil)) then <<
      w0 := rds car w0;
      while not errorp (w1 := errorset('(read), nil, nil)) and
            not eqcar(w1, !$eof!$) do <<
        requests := car w1 . requests;
        princ "Use data for "; print caar w1 >>;
% The data structure read in here will be of the form
%    ((module-name (f-name1 ..) (f_name2 ..) ...) (module-name ...) ...)
% where within each module the requested functions have been listed in
% order of priority.
      close rds w0 >>;
    enable!-errorset(car ee, cdr ee)
  end;

symbolic procedure do_partial();
begin
  scalar fg, !*echo;
  read_profile_data "$destdir/profile.dat";
  read_profile_data "$destdir/unprofile.dat";
% I will load source definitions of everything available. That will include
% much that is not actually needed, but will be simplest and safest.
  load!-source();
% First discard the modules names.
  requests := reverse for each x in requests collect cdr x$

% Now I will merge in suggestions from all packages in breadth-first
% order of priority
% Ie if I have modules A, B, C and D and each has in it functions a1, a2,
% a3 ... (in priority order) then I will make up a list like
%   a1 b1 c1 d2   a2 b2 c2 d2   a3 b3 c3 d3   a4 b4 c4 d4 ...
%
% so that all packages A, B, C and D will get about balanced treatment
% when I need to truncate the list at some stage. I do this except that
% if a function has already been picked I will ignore it and look for the
% next choice made by that module's test.
% The output from this will be built up (at first in reversed order)
% in w_reduce.
  fg := t;
  while fg do <<
    fg := nil;
    for each x on requests do <<
% Here x is of the form (((fname checksum size count) ...) ...)
% w_reduce will be just a list of names, but with no repeats.
% A feature of me doing things this way will be the if there are multiple
% versions of any single function and ONE of them gets picked for
% compilation into C++ I will treat them all that way.
% Start by skipping cases that have already been scheduled for compilation.
      while car x and member(caaar x, w_reduce) do
         rplaca(x, cdar x);
% Now compile the next function (if there is one).
      if car x then <<
% I will include things just once provided they have an associated saved
% definition and they are not on the exclusions list. Furthermore I do not
% need to worry about checksums from the profiling any more: if some function
% is names in ANY of the sections of the profile data I am going to turn
% all versions of that function into C++, and the scheme I now use arranges
% that doing so should not lead to complications.
        if get(caaar x, '!*savedefs) then <<
          if cdr get(caaar x, '!*savedefs) then <<
            if not zerop posn() then terpri();
            princ "+++ "; prin caaar x; printc " has multiple definitions" >>;
          w_reduce := caaar x . w_reduce >>;
        fg := t;
        rplaca(x, cdar x) >> >> >>;

% Compile some specific things first and others last. The ability to
% override the normal priority order may be useful when I want to
% force-compile some functions for testing purposes. When I have any
% such specially selected cases I will display their associated definitions
% here because I will probably be in a debugging context.

  for each x in append(at_start, at_end) do <<
    prin x; princ " "; print get(x, '!*savedefs) >>;

  w_reduce := append(at_start, append(reverse w_reduce, at_end));

end;

% This will set up to turn every function whose definition I can find
% (and that is not on the exclusions list) into C++.

symbolic procedure do_total();
<<load!-source();
  w_reduce := nil;
  for each x in oblist() do
    if get(x, '!*savedefs) then w_reduce := x . w_reduce;

  w_reduce := nreverse w_reduce$ % Now in alphabetic order, which seems neat.

% Put at_at_start and at_end items where they need to be.
  for each x in at_start do w_reduce := delete(x, w_reduce);
  for each x in at_end do w_reduce := delete(x, w_reduce);
  w_reduce := append(at_start, append(w_reduce, at_end)) >>;

symbolic procedure listsize(x, n);
   if null x then n
   else if atom x then n+1
   else listsize(cdr x, listsize(car x, n+1));

symbolic procedure generate_cpp();
  begin
    scalar total, bulk, count;
    count := 0;
    while fnames do
    begin
      scalar modname, defn;
      modname := car fnames;
      princ "About to create "; printc modname;
      c!:ccompilestart(modname, modname, "$destdir");
      bulk := 0;
      while bulk < size_per_file and w_reduce and how_many > 0 do
      begin
        scalar name, defns;
        name := car w_reduce;
        w_reduce := cdr w_reduce;
        if null (defns := get(name, '!*savedefs)) then <<
          princ "+++ "; prin name;
          printc ": no saved definition found";
          w_reduce := cdr w_reduce >>
        else if member(name, omitted) then <<
          princ "+++++ "; prin name;
          printc ": in list of special-case omissions";
          w_reduce := cdr w_reduce >>
        else <<
          bulk := listsize(defns, bulk);
          count := count+1;
          how_many := how_many - 1;
          for each defn in defns do <<
            princ count;
            princ ": ";
            c!:ccmpout1 ('de . name . cddr defn) >> >>
      end;
      eval '(c!-end);
      fnames := cdr fnames
    end;

    terpri();
    printc "*** End of compilation from REDUCE into C++ ***";
    terpri();

    total := count;
    bulk := 0;
% I list the next 50 functions that WOULD get selected - just for interest.
    if null w_reduce then printc "No more functions need compiling into C"
    else while bulk < 50 and w_reduce do
      begin
        scalar name, defns;
        name := car w_reduce;
        if null (defns := get(name, '!*savedefs)) then <<
          princ "+++ "; prin name; printc ": no saved definition found";
          w_reduce := cdr w_reduce >>
        else for each defn in defns do <<
          bulk := bulk+1;
          princ (count := count+1);
          princ ": ";
          print name;
          w_reduce := cdr w_reduce >> end;

    terpri();
    prin total; printc " functions compiled into C++"
  end;

symbolic procedure completion();
  begin
    scalar p;
    terpri();
    printc "Top 64 things to compile are...";
    p := w_reduce;
    for i := 1:64 do if p then <<
      prin car p;
      if remainder(i, 4) = 0 then terpri()
      else ttab(18*remainder(i, 4));
      p := cdr p >>;

    verbos nil;
    fluid '(rprifn!*);
    generate_cpp();
  end;


% I used to prefer speed to safety. For a while at least I will go the
% other way.

off fastfor, fastvector, unsafecar;

<<
  if everything then do_total()
  else do_partial();
  completion() >>;

quit;

