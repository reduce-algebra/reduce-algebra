% Seek cases where case sensitivity in Reduce would cause confusion!
% I have coded this so it will run using CSL without concern for CSLisms.
% I am certain it could be adapted to run under PSL too, but I do not at
% present view that as a high priority.

% This wants "files" and "outputfile" to have been defined via the command
% line as in
%    redcsl -Dfiles=... -Doutputfile=...


off echo;
lisp;

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
  scalar a, b, c, h, u, v, w, x, peekchar!*,
         !*echo, !*raise, !*lower, context;
  w := reverse explodec ff;
  while not eqcar(w, '!/) do <<
    v := car w . v;
    w := cdr w >>;
  w := list2string v;
  princ "+++ Start processing file "; print w;
  a := open(ff, 'input);
  b := rds a;
  cursym!* := '!*semicol!*;
  crchr!* := '! ;
  eof!* := 0;
  escaped!* := nil;
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
%    ARGTYPE    -------,-------> PROCEDURE
%    ARGTYPE    -----(;|$)-----> GENERAL
%    ARGTYPE    ----symbol*----> ARGTYPE
%    ARGTYPE    -----other-----> ARGTYPE
%
%    TYPEDEF    ----symbol*----> GENERAL
%    TYPEDEF    -----other-----> GENERAL
  while not errorp (c := errorset('(scan), nil, nil)) and
        (c := car c) neq !$eof!$ do <<
     if idp c and not escaped!* then <<
       if context='argtype or context='typedef then h := typenames
       else h := allnames;
       total := total + 1;
       u := intern list2string explode2lc c; % Lower case name
       v := gethash(u, h);
       x := assoc(c, v);
       if x then rplacd(x, add1 cdr x)
       else puthash(u, h, (c . 1) . v) >>;
     if not escaped!* then <<
       if context='general and
          (c='declare or c='procedure or c='scalar) then context:='procedure
       else if context='general and
          (c='typedef or c='struct) then context:='typedef
       else if context='procedure and c='!*colon!* then context:='argtype
       else if context='procedure and c='!*semicol!* then context:='general
       else if context='argtype and c='!*comma!* then context:='procedure
       else if context='argtype and c='!*semicol!* then context:='general
       else if context='typedef then context:='general >>;
     escaped!* := nil >>;
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

begin
  scalar a, b;
  a := outputfile;
  terpri(); princ "Output will be in "; printc a;
  a := open(a, 'output);
  b := wrs a;
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
  wrs b;
  close a;
  terpri(); prin length dups; printc " symbols involved";
  prin length typedups; printc " type symbols involved"
end;


quit;



