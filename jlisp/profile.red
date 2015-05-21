% Collect profile information about all REDUCE modules that have
% associated test scripts.  The information is put in "profile.dat"
% in the current directory but you then probably want to move it up
% to the place it really lives. This step is not automated here at
% present.

symbolic;

if boundp 'cpulimit and
   numberp (cpulimit := compress explodec cpulimit) and
   cpulimit > 0 then !*cpulimit := cpulimit;

if boundp 'conslimit and
   numberp (conslimit := compress explodec conslimit) and
   conslimit > 0 then !*conslimit := conslimit;


load!-module 'remake;

get_configuration_data();

delete!-file "profile.dat";
delete!-file "buildlogs/flaguse.log";

% I do not think that profiling the regresison tests is a useful idea.

for each x in reduce_regression_tests do
   reduce_test_cases := delete(x, reduce_test_cases);

on backtrace;
enable!-errorset(3,3);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
off comp;

symbolic procedure profile_a_package names;
  begin
    scalar packge, oll, w, w1, w2, quitfn, !*errcont, rr;
    if not boundp 'cpulimit or
       not fixp (cpulimit := compress explodec cpulimit) or
       cpulimit < 1 then
       cpulimit := if memq('jlisp, lispsystem!*) then 1000 else 180;
    if not boundp 'conslimit or
       not fixp (conslimit := compress explodec conslimit) or
       conslimit < 1 then
       conslimit := 2000;
    princ "PROFILING: "; print car names;
    !*backtrace := nil;
    !*errcont := t;
    !*int := nil;
    packge := car names;
    verbos nil;
    get_configuration_data();
    if not memq(packge, reduce_regression_tests) then <<
       load!-package packge;
       if get(packge,'folder) then packge := get(packge,'folder);
       testdirectory := concat("$reduce/packages/", packge);
       packge := concat("$reduce/packages/",
                   concat(packge,
                     concat("/",
                       concat(car names,".tst"))));
       oll := linelength 80;
       !*mode := 'algebraic;
       window!-heading list!-to!-string append(explodec "[Profile] ",
                                               explodec car names);
       quitfn := getd 'quit;
       remd 'quit;
       putd('quit, 'expr, 'posn);
print "a";
       mapstore 4;  % reset counts;
print "b";
       !*errcont := t;
% I try hard to arrange that even if the test fails I can continue and that
% input & output file selection is not messed up for me.
       w := wrs nil;
       w1 := rds nil;
       wrs w;
       rds w1;
print "c";
       rr := resource!-limit(list('errorset,
                                  mkquote list('in_list1, mkquote packge, t),
                                  nil, nil),
                             cpulimit,
                             conslimit,
                             10000,% allow ten megabytes of I/O
                             -1);  % Do not limit Lisp-level errors at all
print "d";
       wrs w;
       rds w1;
print "e";
       erfg!* := nil;
       terpri();
print list('quitfn, quitfn);
       putd('quit, car quitfn, cdr quitfn);
       w := sort(print mapstore 2, function profile_compare_fn);
terpri(); princ "@@@ "; print w;
       begin
          scalar oo;
print "f";
          oo := wrs open("buildlogs/flaguse.log", 'append);
          bytecounts t;
          close wrs oo;
       End;
       w1 := nil;
       while w do <<
           w2 := get(caar w, '!*savedef);
%       if eqcar(w2, 'lambda) then <<
%           princ "md60: "; print (caar w . cdr w2);
%           princ "= "; print md60 (caar w . cdr w2) >>;
           if eqcar(w2, 'lambda) then w1 := (caar w . md60 (caar w . cdr w2) .
                                             cadar w . caddar w) . w1;
           w := cdr w >>;
       w := w1;
print w;
print "g";

       % I collect the top 350 functions as used by each test, not because all
       % that many will be wanted but because I might as well record plenty
       % of information here and discard unwanted parts later on.
       for i := 1:349 do if w1 then w1 := cdr w1;
print "h";
       if w1 then rplacd(w1, nil);
       % princ "MODULE "; prin car names; princ " suggests ";
       % print for each z in w collect car z;
       w1 := open("profile.dat", 'append);
       w1 := wrs w1;
       linelength 80;
       if atom rr then printc "% +++++ Error: Resource limit exceeded";
       princ "% @@@@@ Resources used: "; print !*resources!*;
       princ "("; prin car names; terpri();
       for each n in w do <<
           princ "  ("; prin car n; princ " ";
           if posn() > 30 then << terpri(); ttab 30 >>;
           prin cadr n;
           % I also display the counts just to help me debug & for interest.
           princ " "; prin caddr n; princ " "; princ cdddr n;
           printc ")" >>;
       printc "  )";
       terpri();
       close wrs w1;
       linelength oll >>;
    names := cdr names;
    if null names then <<
        w1 := open("buildlogs/flaguse.log", 'input);
        w1 := rds w1;
        w := nil;
        while (w2 := read()) neq !$eof!$ do
            w := sort(w2, 'orderp) . w;
        close rds w1;
        rr := '((symbol!-make!-fastget 'lose 1)
                (symbol!-make!-fastget 'noncom 0));
        flag('(lose noncom), 'processed);
        oll := 2;
        while w do <<
           w1 := nil;
           for each x in w do <<
               if x and
                  not flagp(cadar x, 'processed) and
                  oll < 63 then <<
                   rr :=
                       list('symbol!-make!-fastget, mkquote cadar x, oll) . rr;
                   flag(list cadar x, 'processed);
                   oll := oll + 1 >>;
               if cdr x then w1 := cdr x . w1 >>;
           w := reverse w1 >>;
        w := open("buildlogs/fastgets.lsp", 'output);
        w := wrs w;
        printc "% fastgets.lsp generated by profiling";
        terpri();
        prettyprint ('progn . reverse rr);
        terpri();
        printc "% end of fastgets.lsp";
        close wrs w;
        printc "Profiling complete";
        window!-heading "Profiling complete";
        restart!-csl t >>
    else restart!-csl('(remake profile_a_package), names)
  end;


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%profile_a_package reduce_test_cases;
profile_a_package '(alg);

bye;



