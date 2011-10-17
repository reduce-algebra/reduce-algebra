%
% Compiler from Lisp into C.            Copyright (C) 1994, Codemist Ltd
%
% This code hooks into the end of the Codemist Lisp bytecode compiler.
%

global '(s!:c_name s!:c_file s!:lisp_name s!:lisp_file);

symbolic macro procedure c!:printf u;
% inspired by the C printf function, but much less general.
% This macro is to provide the illusion that printf can take an
% arbitrary number of arguments.
  list('c!:printf1, cadr u, 'list . cddr u);

symbolic procedure c!:printf1(fmt, args);
% this is the inner works of print formatting.
% the special sequences that can occur in format strings are
%               %s       use princ (to print a name?)
%               %d       use princ (to print a number?)
%               %a       use prin
%               %t       do a ttab()
%               %v       print a variable.... magic for this compiler
%               \n       do a terpri()
%               \q       princ '!" to display quote marks
  begin
    scalar a, c;
    fmt := explode2 fmt;
    while fmt do <<
      c := car fmt;
      fmt := cdr fmt;
      if c = '!\ and car fmt = '!n then <<
         terpri();
         fmt := cdr fmt >>
      else if c = '!\ and car fmt = '!q then <<
         princ '!";
         fmt := cdr fmt >>
      else if c = '!% then <<
         c := car fmt;
         fmt := cdr fmt;
         a := car args;
         args := cdr args;
         if c = '!v then
            if flagp(a, 'c!:live_across_call) then <<
               princ "stack[";
               princ(-get(a, 'c!:location));
               princ "]" >>
            else princ a
         else if c = '!a then prin a
         else if c = '!t then ttab a
         else princ a >>
      else princ c >>
  end;


symbolic procedure open_output name;
!#if common!-lisp!-mode
    open(name, !:direction, !:output);
!#else
    open(name, 'output);
!#endif

symbolic procedure s!:cstart module_name;
  begin
    scalar w;
    verbos nil;    % Do not want garbage collection messages mixing in.
    princ "Start of compilation into C for "; prin module_name; terpri();
    w := '!" . explodec module_name;
    s!:c_name := compress append(w, '(!. !c !"));
    s!:lisp_name := compress append(w, '(!. !l !s !p !"));
    s!:c_file := open_output s!:c_name;
    s!:lisp_file := open_output s!:lisp_name;
    if s!:c_file and s!:lisp_file then return t;
    if s!:c_file then close s!:c_file;
    if s!:lisp_file then close s!:lisp_file;
    return nil
  end;

symbolic procedure s!:cinit u;
  begin
    scalar o;
    o := wrs s!:lisp_file;
    princ "Initform: "; prinl u; terpri();
    wrs o
  end;

symbolic procedure s!:cend();
  begin
    close s!:c_file;    s!:c_file := nil;
    close s!:lisp_file; s!:lisp_file := nil;
    return nil
  end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

symbolic procedure s!:cgen(name, nargs, body, env);
  begin
    scalar w, fgg;
    princ "Cgen:  "; prin name; terpri();
    princ "nargs: "; prin nargs; terpri();
    if nargs > 10 then <<
       terpri();
       princ "++++++ Functions with > 10 args or &optional, &rest"; terpri();
       princ "       arge can not be compiled into C"; terpri();
       return 'failed >>;
    for each l in reverse body do <<
       prin car l; princ ": ";
       w := reverse cdddr l;
% The very first block may have an arg-count byte on the front, which I want
% to get rid on.
       if not fgg and nargs > 3 then w := cddr w;
       fgg := t;
       for each x in w do << princ " "; prin x >>;
       princ "  ";
       prin cadr l;
       terpri() >>
  end;


end;
