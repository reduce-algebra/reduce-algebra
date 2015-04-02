% Seek cases where case sensitivity in Reduce would cause confusion!
% I have coded this so it will run using CSL without concern for CSLisms.
% I am certain it could be adapted to run under PSL too, but I do not at
% present view that as a high priority.

% This wants "files" and "outputfile" to have been defined via the command
% line as in
%    redcsl -Dfiles=... -Doutputfile=...


off echo;
lisp;
on backtrace;

filelist := nil;

begin
  scalar a, b, c;
  a := open(files, 'input);
  b := rds a;
  while (c := readline()) neq !$eof!$ do
    filelist := c . filelist;
  filelist := reverse filelist;
  rds b;
  close a;
  return list(length filelist, 'files)
end;

allnames := mkhash(1000, 3, 2.0)$
typenames := mkhash(1000, 3, 2.0)$

total := 0;

for each ff in filelist do begin
  scalar a, b, c, h, m, u, v, w, x, location, peekchar!*,
         !*echo, !*raise, !*lower, context, !*int;
  w := reverse explodec ff;
  while w and not eqcar(w, '!/) do <<
    v := car w . v;
    w := cdr w >>;
  if w then w := list2string v
  else w := ff;
  princ "+++ Start processing file "; print w;
  a := open(ff, 'input);
  b := rds a;
  cursym!* := '!*semicol!*;
  crchr!* := '! ;
  eof!* := 0;
% Note that for line counts to be updated !*int must be nil!
  location := curline!* := 1;
  context := 'general;
%
%                   declare
%    GENERAL    ---procedure---> PROCEDURE
%                   scalar
%
%    GENERAL    ----typedef----> TYPEDEF
%                   struct
%
%    GENERAL    -----other-----> GENERAL
%
%    PROCEDURE  -------:-------> ARGTYPE
%    PROCEDURE  -----(;|$)-----> GENERAL
%    PROCEDURE  -----other-----> PROCEDURE
%
%    ARGTYPE    ------,|)------> PROCEDURE
%    ARGTYPE    -----(;|$)-----> GENERAL
%    ARGTYPE    ----symbol*----> ARGTYPE
%    ARGTYPE    -----other-----> ARGTYPE
%
%    TYPEDEF    ----symbol*----> GENERAL
%    TYPEDEF    -----other-----> GENERAL
  while not errorp (c := errorset('(scan), nil, nil)) and
       (c := car c) neq !$eof!$ do <<
    if idp c and not curescaped!* then <<
      if context='argtype or context='typedef then <<
        h := typenames;
        m := 'typementions >>
      else <<
        h := allnames;
        m := 'mentions >>;
      total := total + 1;
      u := get(c, m);
% For each symbol I will note the first 10 places it is used.
      if length u < 10 then
        put(c, m, (ff . location) . u);
      u := intern list2string explode2lc c; % Lower case name
      v := gethash(u, h);
      x := assoc(c, v);
      if x then rplacd(x, add1 cdr x)
      else puthash(u, h, (c . 1) . v) >>;
    if not curescaped!* then <<
      if context='general and
         (c='declare or c='procedure or c='scalar) then context:='procedure
      else if context='general and
         (c='typedef or c='struct) then context:='typedef
      else if context='procedure and c='!*colon!* then context:='argtype
      else if context='procedure and c='!*semicol!* then context:='general
% The comma here should onnly be recognise3d if not nested within parens.
% So this will mis-handle
%    declare addf: (SF,SF) -> SF;
% for now. I will fix that in a bit!
      else if context='argtype and c='!*comma!* then context:='procedure
      else if context='argtype and c='!*rpar!* then context:='procedure
      else if context='argtype and c='!*colon!* then context:='argtype
      else if context='argtype and c='!*semicol!* then context:='general
      else if context='typedef then context:='general >>;
% Getting the line number that for a symbol is more of a delicate issue
% than I had perhaps expected!
    while crchar!* = '!  or crchar!* = !$eol!$ do crchar!*:=readch1();
    location := curline!* >>;
  cursym!* := '!*semicol!*;
  crchr!* := '! ;
  eof!* := 0;
  rds b;
  close a;
  princ "At end of ";
  princ w;
  princ " total token count = ";
  print total
  end;

dups := nil;

for each p in hashcontents allnames do <<
  if cdr p and cddr p then dups := sort(cdr p, 'orderp) . dups;
  nil >>;

dups := sort(dups, 'orderp)$

typedups := nil;

for each p in hashcontents typenames do <<
  if cdr p and cddr p then typedups := sort(cdr p, 'orderp) . typedups;
  nil >>;

typedups := sort(typedups, 'orderp)$

mentions := nil;
typementions := nil;

for each p in dups do
  for each x in p do
    for each y in get(car x, 'mentions) do
      mentions := y . mentions;

for each p in typedups do
  for each x in p do
    for each y in get(car x, 'typementions) do
      typementions := y . typementions;

fluid '(line typeline);
line := mkhash(1000, 3, 2.0)$
typeline := mkhash(1000, 3, 2.0)$

for each ff in filelist do begin
  scalar a, b, c, d, n, !*echo, !*raise, !*lower;
  a := open(ff, 'input);
  b := rds a;
  c := 1;
  n := 1;
  while (d := readline()) neq !$eof!$ do <<
    if member(ff . c, mentions) then puthash(ff . c, line, d);
    if member(ff . c, typementions) then puthash(ff . c, typeline, d);
    c := c + 1 >>;
  rds b;
  close a
  end;

symbolic procedure listmatch(u, v);
  if null u then t
  else if not eqcar(v, car u) then nil
  else listmatch(cdr u, cdr v);

symbolic procedure fileleaf u;
  begin
    scalar v;
    v := explodec u;
% I will look for "packages" in the string - if I do not find it
% I will return the whole string.
    while v and not listmatch('(p a c k a g e s), v) do v := cdr v;
    if null v then return u;
    v := cddddr cddddr v;
    if not (eqcar(v, '!/) or eqcar(v, '!\)) then return u;
    return list2string cdr v
  end;

symbolic procedure showmention x;
  begin
    princ fileleaf car x;
    princ " : ";
    print cdr x;
    printc gethash(x, line)
  end;

symbolic procedure showtypemention x;
  begin
    princ fileleaf car x;
    princ " : ";
    print cdr x;
    printc gethash(x, typeline)
  end;


begin
  scalar a, b;
  a := outputfile;
  terpri(); princ "Output will be in "; printc a;
  a := open(a, 'output);
  b := wrs a;
  linelength 250;
  printc "+++ Standard names +++";
  for each p in dups do <<
    for each x in p do <<
      if posn() > 40 then << terpri(); ttab 38 >>
      else if posn() > 0 then ttab 38;
      princ car x;
      princ ":";
      prin cdr x >>;
    terpri() >>;
  terpri(); prin length dups; printc " symbols involved";
  if typedups then <<
    terpri();
    printc "+++ Type names +++";
    for each p in typedups do <<
      for each x in p do <<
        if posn() > 40 then << terpri(); ttab 38 >>
        else if posn() > 0 then ttab 38;
        princ car x;
        princ ":";
        prin cdr x >>;
      terpri() >>;
    terpri(); prin length typedups; printc " type symbols involved" >>;
  terpri(); terpri();
  printc "+++ Detailed Report +++";
  terpri(); terpri();
  printc "+++ Standard names +++";
  for each p in dups do <<
    for each x in p do <<
      terpri();
      ttab 20;
      princ car x;
      princ ":";
      print cdr x;
      for each y in reverse get(car x, 'mentions) do showmention y >>
    >>;
  terpri(); prin length dups; printc " symbols involved";
  if typedups then <<
    terpri();
    printc "+++ Type names +++";
    for each p in typedups do <<
      for each x in p do <<
        terpri();
        ttab 20;
        princ car x;
        princ ":";
        print cdr x;
        for each y in reverse get(car x, 'typementions) do showtypemention y >>
      >>;
    terpri(); prin length typedups; printc " type symbols involved" >>;
  wrs b;
  close a;
  terpri(); prin length dups; printc " symbols involved";
  prin length typedups; printc " type symbols involved"
end;


quit;



