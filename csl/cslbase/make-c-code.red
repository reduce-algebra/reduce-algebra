
on echo;

% This file can be run to turn bits of the REDUCE source code
% into C so that this C can be compiled and linked in to make a
% customised CSL executable that will red REDUCE faster.
%
% Run this using bootstrapreduce.img to select code to compile into C.
% The functions to be compiled are extracted from a file "profile.dat"
% that was created by "profile.red".
%

symbolic;

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
%                be included before anything else.
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
% hope there are no such cases!

global '(fnames size_per_file force_count how_many);

fnames := '("u01" "u02" "u03" "u04" "u05"
            "u06" "u07" "u08" "u09" "u10"
            "u11" "u12");

size_per_file := 7000;

force_count := 350;

if not boundp 'how_many then how_many := 1000000
else << how_many := compress explodec how_many;
        if not numberp how_many then how_many := 1000000 >>;



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
% that had been selected for compilation into C. And in a truly bad
% case the complete REDUCE sources will contain several functions named
% f2 and of course the patches file identifies which one it is interested
% in by the name of the package it is in.
%
% The response to all this I will use here is intended to make life
% reasonably SIMPLE for me in a complicated situation. So I first
% collect the set of names that I think need compiling into C. Then I
% grab a list of the names of things defined in the current patches file.
% If a function in the paches file has a name similar enough (!) to one that
% I have already decided to compile into C then I will schedule it for
% compilation into C too.  Because of the hash suffix added to names in the
% patches file defining a C version having those things present in the Lisp
% kernel should never be a problem - after all the patches file itself is
% intended to be loaded all the time.  So the main down-side of this is
% that I will sometimes find that I have compiled into C either patch
% versions of a function when it was another version of that code that was
% time-critical or that I have compiled into C two generations of
% patch function. These waste opportunity and space by having some
% things compiled into C that might not really justify that, but this
% seems a modest cost.

% Note that parts of the above may apply if the sources of REDUCE are
% changed inANY manner (not just a special patches file) but the C code
% is not re-created.

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
            not eqcar(w1, !$eof!$) do
        requests := car w1 . requests;
% The data structure read in here will be of the form
%    ((module-name f-name1 f_name2 ...) (module-name ...) ...)
% where within each module the requested functions have been listed in
% order of priority.
      close rds w0 >>
  end;


off echo;

read_profile_data "$destdir/profile.dat";

on echo;

% As a fairly shameless hack I am going to insist on compiling ALL the
% things that the "alg" test uses. That is because this one test
% fiel has been used for many years to give a single performance
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

for each m in library!-members() do load!-source m;

% Now deal with patches...

load!-source := t;
if modulep 'patches then patch!-functions := load!-source 'patches
else patch!-functions := nil;


% Some of the functions just collected are not patches for bits of REDUCE
% but are the code that installs the patches. I do not worry too much
% about that here.
% Now I will scan down w_reduce (the list of all things to be compiled into C)
% and if that contains an entry either f1 or f1_123456789 and there is
% an entry f2_abcdef in the list of patch-functions then I will
% insert f2_abcdef into the list of things to be compiled into C just
% next to plain f2 or f2_123456789.
%
% The way I do this will often set up a few false-matches but the cost of
% them is just that some unimportant things will get compiled into C.


global '(tag!-chars);

tag!-chars := explodec "0123456789abcdefghijklmnopqrstuvwxyz";

symbolic procedure trim!-suffix name;
  begin
    scalar w;
    w := reverse explode name;
    if eqcar(w, '!_) then w := cdr w;
    if null w or not member(car w, tag!-chars) then return nil;
    w := cdr w;
    while w and member(car w, tag!-chars) do w := cdr w;
    if not eqcar(w, '!_) then return nil;
    w := cdr w;
    if null w then return nil
    else return compress reverse w
  end;

w := w_reduce$
w_reduce := nil;

while w do <<
   w_reduce := car w . w_reduce;
   p := trim!-suffix car w;
   for each n in patch!-functions do
     if not (n = car w) and
        p and
        not (n member w_reduce) and
        p = trim!-suffix n then <<
           w_reduce := n . w_reduce;
           princ "+++ Also C-compile "; prin n; princ " as match for ";
           prin car w; princ ": root is "; print p >>;
   w := cdr w >>;


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
   c!:ccompilestart(name, name, "$destdir/generated-c", nil);
   bulk := 0;
   while bulk < size_per_file and w_reduce and how_many > 0 do begin
      scalar name, defn;
      name := car w_reduce;
      if null (defn := get(name, '!*savedef)) then <<
         princ "+++ "; prin name; printc ": no saved definition found";
         w_reduce := cdr w_reduce >>
      else <<
         bulk := listsize(defn, bulk);
         if bulk < size_per_file then <<
            c!:ccmpout1 ('de . name . cdr defn);
            how_many := how_many - 1;
            count := count + 1;
            w_reduce := cdr w_reduce >> >> end;
   eval '(c!-end);
   fnames := cdr fnames
   end;

terpri();
printc "*** End of compilation from REDUCE into C ***";
terpri();

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
        print name;
        w_reduce := cdr w_reduce >> end;

terpri();
prin count; printc " functions compiled into C";

nil >>;

quit;


