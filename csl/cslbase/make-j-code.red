% make-j-code.red

%**************************************************************************
%* Copyright (C) 2022, Codemist.                         A C Norman       *
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

on echo;

% This file can be run to turn bits of the REDUCE source code
% into Java so that this Java can be compiled and linked in to make a
% customised Jlisp that will red REDUCE faster.
%
% Run this using bootstrapreduce.img to select code to compile into Java.
% The functions to be compiled are extracted from a file "profile.dat"
% that was created by "profile.red".
%
% I will also allow for a file "unprofile.dat" that can be used to provide
% extra help with modules where the module maintainer is unable to provide
% test cases that generate reliable profile date.
%

symbolic;

% Three major parameters are available:
%
%   fnames       a list of files to create. Making the list longer (or
%                shorter) changes the amount of Java that can be created.
%                The CSL source code has to know how many there are, and
%                its current default is for 12 files.
%
%   size_per_file
%                this guides the compiler about how much to put in each
%                generated file, where the value 7000 results in each
%                file of generated Java being in the range 120 to 150 Kbytes.
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
% functions that are compiled into Java. Since I expect to pass that via a
% command line   "-dhow_many=362"  etc I allow for it being a string
% not a number to start with. In ordinary circumstances this will not be
% used, however it has proved INVALUABLE when tracking down cases where
% compilation into Java causes changes in behaviour... how_many can be used
% with a binary-chop selection process to discover exactly which function
% causes upset when compiled into Java.  Of course in release quality code I
% hope there are no such cases!

global '(fnames size_per_file force_count how_many);


fnames := '(      "U01" "U02" "U03" "U04"
            "U05" "U06" "U07" "U08" "U09"
            "U10" "U11" "U12" "U13" "U14"
            "U15" "U16" "U17" "U18" "U19"
            "U20" "U21" "U22" "U23" "U24"
            "U25" "U26" "U27" "U28" "U29"
            "U30" "U31" "U32" "U33" "U34"
            "U35" "U36" "U37" "U38" "U39"
            "U40" "U41" "U42" "U43" "U44"
            "U45" "U46" "U47" "U48" "U49"
            "U50" "U51" "U52" "U53" "U54"
            "U55" "U56" "U57" "U58" "U59"
            "U60"
);

if boundp 'size_per_file and
   numberp (cx := compress explodec size_per_file) and
   cx > 100 and cx < 200000 then size_per_file := cx
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
% a default number of functions to be compiled into Java that matches the
% number I used historically, and hence it provides a safe level of
% continuity. You may experiment with
%     make c-code how_many=nnnn
% and do so either to see how the speed/space tradeoff goes or because you
% are ocncerned about a possible bug in the Lisp to Java compilation step. My
% current measurements suggest that 3500 gives reasonable trade off for
% build of the executable vs. performance. However for use with an embedded
% system with limited memort I might suggest say 500.

if not boundp 'how_many then how_many := 3500
else << how_many := compress explodec how_many;
        if not numberp how_many then how_many := 3500 >>;

<< terpri(); princ "how_many = "; print how_many; nil >>;

global '(omitted at_start at_end);

% At any stage there may be some things that I must not even try to compile
% into Java because of bugs or limitations. I can list them here. This is very
% UGLY and delicate, and so ideally I will upgrade the compilation into Java
% to remove most of these limitations eventually.

omitted := '(
    s!:prinl0               % uses unwind-protect
    prinl                   % Ha ha - this being turned into Java makes it seem
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
% stub gets compiled into Java so I will try to identify any such and mark
% them as unsuitable for compilation.

for each x in oblist() do
 if eqcar(d := getd(x), 'expr) and
    consp cdr d and consp cddr d and consp cdddr d then <<
   d := cadddr d;
   if eqcar(d, 'progn) and cdr d and eqcar(cadr d, 'load!-package) then <<
      princ "+++ "; prin x; printc " looks like an autoload stub. Omit here";
      omitted := x . omitted >> >>;
   
at_start := '(
    );

at_end := '(
    );


on comp;


load!-module 'remake;

% Here I need to consider the issue of patches.  First consider patches that
% had been in force when "profile.red" was run. In such cases a patched
% function f1 has an associated replacement f1_123456789 (the numeric suffix
% is a checksum on the new definition) and when the profile job was run
% this replacement will have had its definition copied to f1. The way in
% which CSL's mapstore function extracts counts will mean that the
% thing in profile.dat relate to f1_123456789.
% Usually things in profile.dat are in the form
%    (function_name . checksum_of_definition)
% but for these patched things I will instead record
%    (original_function_name package_involved)
% This can be distinguished because it has a symbol not a number as
% the second component. To make this possible each patch function
% f1_123456789 would have to have this information attached to it
% when the profiling job was run.
%
% But I suppose have now obtained a newer version of the patches file. So
% now the correct patch for f1 will be f1_abcdef. If f1 was in one of the
% REDUCE core packages (eg "alg") then both the functions f1_123456789 and
% f1_abcdef will be in memory now, but it will be the latter that will
% have been copied to plain old f1.  In other cases f1_123456789 will now
% have been totally lost and the definition of f1_abcdef will be in the
% patches module.  Furthermore the new patches file may patch another
% function f2 that had not previously been subject to patching, but
% that had been selected for compilation into Java. And in a truly bad
% case the complete REDUCE sources will contain several functions named
% f2 and of course the patches file identifies which one it is interested
% in by the name of the package it is in.
%
% The response to all this I will use here is intended to make life
% reasonably SIMPLE for me in a complicated situation. So I first
% collect the set of names that I think need compiling into Java. Then I
% grab a list of the names of things defined in the current patches file.
% If a function in the paches file has a name similar enough (!) to one that
% I have already decided to compile into Java then I will schedule it for
% compilation into Java too.  Because of the hash suffix added to names in the
% patches file defining a Java version having those things present in the Lisp
% kernel should never be a problem - after all the patches file itself is
% intended to be loaded all the time.  So the main down-side of this is
% that I will sometimes find that I have compiled into Java either patch
% versions of a function when it was another version of that code that was
% time-critical or that I have compiled into Java two generations of
% patch function. These waste opportunity and space by having some
% things compiled into Java that might not really justify that, but this
% seems a modest cost.

% Note that parts of the above may apply if the sources of REDUCE are
% changed in ANY manner (not just a special patches file) but the Java code
% is not re-created.

fluid '(w_reduce requests);

w_reduce := requests := nil;

% I make a list of all the functions that profile data suggests that
% I should compile into Java.  The master copy of the profile data is
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

% As a fairly shameless hack I am going to insist on compiling ALL the
% things that the "alg" test uses. That is because this one test
% file has been used for many years to give a single performance
% figure for REDUCE.  In fact it is not too bad to pay lots of
% attention to it since it exercises the basic core algebra and so what is
% good for it is good for quite a lot of everybody else. However by
% tuning this selection process you can adjust the way REDUCE balances
% its speed in different application areas.

w_reduce := assoc('alg, requests)$
requests := for each x in delete(w_reduce, requests) collect cdr x$
w_reduce := reverse cdr w_reduce$
d := length w_reduce - force_count;
if d > 0 then for i := 1:d do w_reduce := cdr w_reduce;

length w_reduce;

% Now I will merge in suggestions from all other modules in
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

symbolic procedure membercar(a, l);
  if null l then nil
  else if a = caar l then t
  else membercar(a, cdr l);

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
% selected REDUCE functions. The values put as load!-source properties
% are checksums of the recovered definitions that I would be prepared
% to accept.

for each n in w_reduce do put(car n, 'load!-source, cdr n);

w_reduce := for each n in w_reduce collect car n$

% Discard things that give trouble...
for each x in omitted do w_reduce := delete(x, w_reduce);

% Compile some specific things first and others last. The ability to
% override the normal priority order may be useful when I want to
% force-compile some functions for testing purposes.

for each x in append(at_start, at_end) do <<
   prin x; princ " "; print get(x, '!*savedef) >>;

w_reduce := append(at_start, append(nreverse w_reduce, at_end))$

for each m in library!-members() do load!-source m;

<<
printc "Top 20 things to compile are...";
p := w_reduce;
for i := 1:20 do if p then <<
   print car p;
   p := cdr p >>
>>;

verbos nil;
global '(rprifn!*);

on fastfor, fastvector, unsafecar;

symbolic procedure listsize(x, n);
   if null x then n
   else if atom x then n+1
   else listsize(cdr x, listsize(car x, n+1));

<<

count := 0; 

while fnames do begin
   scalar name, bulk;
   name := car fnames;
   princ "About to create "; printc name;
   j!:ccompilestart(name, name, "$destdir", nil);
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
            j!:ccmpout1 ('de . name . cdr defn);
            how_many := how_many - 1;
            w_reduce := cdr w_reduce >> >> end;
   eval '(j!-end);
   fnames := cdr fnames
   end;

terpri();
printc "*** End of compilation from REDUCE into Java ***";
terpri();

total := count;

bulk := 0;
% I list the next 50 functions that WOULD get selected - just for interest.
if null w_reduce then printc "No more functions need compiling into Java"
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
prin total; printc " functions compiled into Java";

nil >>;

quit;


