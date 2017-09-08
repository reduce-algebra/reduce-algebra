% make-c-code.red                          Copyright (C) Codemist 2016-2017

%**************************************************************************
%* Copyright (C) 2017, Codemist.                         A C Norman       *
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

if boundp 'full_c_code and full_c_code then everything := t
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

if boundp 'size_per_file and
   numberp (cx := compress explodec size_per_file) and
   cx > 100 and cx < 200000 then size_per_file := cx
else if everything then size_per_file := 60000
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
% are ocncerned about a possible bug in the Lisp to C compilation step. My
% current measurements suggest that 3500 gives reasonable trade off for
% build of the executable vs. performance. However for use with an embedded
% system with limited memort I might suggest say 500.

begin
  scalar e;
  e := getenv "HOW_MANY";
  if e then <<
    fluid '(how_many);
    how_many := compress explodec e >>
end;

if not boundp 'how_many then how_many := 3500
else << how_many := compress explodec how_many;
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
    s!:prinl0               % uses unwind-protect
    prinl                   % Ha ha - this being turned into C makes it seem
                            % available before it really is!

    compile!-file!*         % &optional
    s!:compile!-file!*      % &optional
    fetch!-url              % &optional

    begin                   % bootstrapping issue
    module2!-to!-file       % ditto
    olderfaslp              % ditto (some time I will investigate and
                            % maybe fix these "bootstrapping" issues...
    package!-remake2        % ditto
    update!-fasl2           % ditto
    upd!-fasl1              % ditto
    update_prompt           % ditto

    linelength              % horrid use of copyd etc in tmprint.red
    setpchar                % horrid use of copyd.. also in tmprint.red
    ordp                    % redefined in helphy/noncom2 and spde/spde
    unit                    % name conflict.

    pasf_bapprox            % Unknown issue!
    divdm                   %
    gck2                    %
    !:recip                 %
    cr!:minus               %

    typerr                  % typerr and symerr are defined in makereduce.lsp
    symerr                  % but there are different versions elsewhere.

    fluid                   % the env cells of these get out of step during..
    global                  % a bootstrap build if they are compiled here.

    aftergcsystemhook       % On slow machines the C code may not end up
                            % fully usable quite early enough?

    knowledge_about         % unwind-protect
    let00                   % ditto
    evalletsub2             % ditto
    clear                   % ditto
    reval!-without          % ditto
    subeval                 % ditto
    ezgcdf                  % ditto
    transcendentalcase      % ditto

    );

% There is a bit of a mess-up if something that has been given an autoload
% stub gets compiled into C so I will try to identify any such and mark
% them as unsuitable for compilation.

for each x in oblist() do
  begin
    scalar d;
    if eqcar(d := getd(x), 'expr) and
       consp cdr d and consp cddr d and consp cdddr d then <<
    d := cadddr d;
    if eqcar(d, 'do!-autoload) then <<
      princ "+++ "; prin x; printc " looks like an autoload stub. Omit here";
      omitted := x . omitted >> >>
  end;
   
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
    scalar w0, w1;
    if not errorp(w0 := errorset(list('open, file, ''input), nil, nil)) then <<
      w0 := rds car w0;
      while not errorp (w1 := errorset('(read), nil, nil)) and
            not eqcar(w1, !$eof!$) do <<
        requests := car w1 . requests;
        princ "Use data for "; print caar w1 >>;
% The data structure read in here will be of the form
%    ((module-name f-name1 f_name2 ...) (module-name ...) ...)
% where within each module the requested functions have been listed in
% order of priority.
      close rds w0 >>
  end;

off echo;

read_profile_data "$destdir/profile.dat";
read_profile_data "$destdir/unprofile.dat";

on echo;

symbolic procedure membercar(a, l);
  if null l then nil
  else if a = caar l then t
  else membercar(a, cdr l);

symbolic procedure do_partial();
begin
  scalar fg, k;
  requests := for each x in requests collect cdr x$

% Now I will merge in suggestions from all modules in
% breadth-first order of priority
% Ie if I have modules A, B, C and D (with A=alg) and each has in it
% functions a1, a2, a3 ... (in priority odder) then I will make up a list
% here that goes
%
%   a1 a2 a3 ... an b1 c1 d2 b2 c2 d2 b3 c3 d3 b4 c4 d4 ...
%
% so that the first n items from A get priority and after that B, C and D
% will get about balanced treatment if I have to truncate the list at
% some stage.

  fg := t;
  while fg do <<
    fg := nil;
    for each x on requests do
      if car x then <<
        if k := assoc(caaar x, w_reduce) then <<
          if not (cadr k = cadaar x) then <<
             prin caaar x; printc " has multiple definition";
             princ "   keep version with checksum: "; print cadr k;
             princ "   ignore: "; print cadaar x;
             terpri() >> >>
% ORDP is a special case because I have put a version of it into the
% CSL kernel by hand, and any redefinition here would be unfriendly and
% might clash with that.
        else if caaar x = 'ordp then printc "Ignoring ORDP (!)"	
        else w_reduce := caar x . w_reduce;
        fg := t;
        rplaca(x, cdar x) >> >>;


% Now I scan all pre-compiled modules to recover source versions of the
% selected REDUCE functions. The values put as load!-selected!-source
% properties are checksums of the recovered definitions that I would be
% prepared to accept.

  for each n in w_reduce do put(car n, 'load!-selected!-source, cadr n);

  w_reduce := for each n in w_reduce collect car n$

% Discard things that give trouble...
  for each x in omitted do w_reduce := delete(x, w_reduce);

% Compile some specific things first and others last. The ability to
% override the normal priority order may be useful when I want to
% force-compile some functions for testing purposes.

  for each x in append(at_start, at_end) do <<
    prin x; princ " "; print get(x, '!*savedef) >>;

  w_reduce := append(at_start, append(nreverse w_reduce, at_end))$

  load!-selected!-source()
end;

symbolic procedure do_total();
<<load!-source();

% Hah but I really want the core versions of anything that might get redefined
% to be the one left - so I will re-load all the core modules!
for each m in loaded!-modules!* do load!-source m;

  w_reduce := nil;

  for each x in oblist() do
    if get(x, '!*savedef) and not memq(x, omitted) then
      w_reduce := x . w_reduce;

  w_reduce := nreverse w_reduce$ % Now in alphabetic order, which seems neat.

  for each x in at_start do w_reduce := delete(x, w_reduce);
  for each x in at_end do w_reduce := delete(x, w_reduce);

  w_reduce := append(at_start, append(w_reduce, at_end)) >>;

symbolic procedure listsize(x, n);
   if null x then n
   else if atom x then n+1
   else listsize(cdr x, listsize(car x, n+1));

symbolic procedure generate_cpp();
  begin
    scalar count;
    count := 0;

    while fnames do begin
      scalar name, bulk, total, defn;
      name := car fnames;
      princ "About to create "; printc name;
      c!:ccompilestart(name, name, "$destdir", nil);
      bulk := 0;
      while bulk < size_per_file and w_reduce and how_many > 0 do begin
        scalar name, defn;
        name := car w_reduce;
        if null (defn := get(name, '!*savedef)) then <<
          princ "+++ "; prin name;
          printc ": no saved definition found";
          w_reduce := cdr w_reduce >>
        else <<
          bulk := listsize(defn, bulk);
          if bulk < size_per_file then <<
            count := count+1;
            princ count;
            princ ": ";
            c!:ccmpout1 ('de . name . cdr defn);
            how_many := how_many - 1;
            w_reduce := cdr w_reduce >> >> end;
      eval '(c!-end);
      fnames := cdr fnames
    end;

    terpri();
    printc "*** End of compilation from REDUCE into C ***";
    terpri();

    total := count;
    bulk := 0;
% I list the next 50 functions that WOULD get selected - just for interest.
    if null w_reduce then printc "No more functions need compiling into C"
    else while bulk < 50 and w_reduce do
      begin
        name := car w_reduce;
        if null (defn := get(name, '!*savedef)) then <<
          princ "+++ "; prin name; printc ": no saved definition found";
          w_reduce := cdr w_reduce >>
        else <<
          bulk := bulk+1;
          princ (count := count+1);
          princ ": ";
          print name;
          w_reduce := cdr w_reduce >> end;

    terpri();
    prin total; printc " functions compiled into C"
  end;

symbolic procedure completion();
  begin
    scalar p;
    terpri();
    printc "Top 20 things to compile are...";
    p := w_reduce;
    for i := 1:20 do if p then <<
      print car p;
      p := cdr p >>;

    verbos nil;
    fluid '(rprifn!*);
    generate_cpp();
  end;


on fastfor, fastvector, unsafecar;

<<
  if everything then do_total()
  else do_partial();
  completion() >>;

quit;


