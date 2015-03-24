% Seek cases where case sensitivity in Reduce would cause confusion!
% I have coded this so it will run using CSL without concern for CSLisms.
% I am certain it could be adapted to run under PSL too, but I do not at
% present view that as a high priority.

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

total := 0;

for each ff in filelist do begin
  scalar a, b, c, u, v, w, peekchar!*, !*echo, !*raise, !*lower;
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
  while not errorp (c := errorset('(scan), nil, nil)) and
        (c := car c) neq !$eof!$ do <<
     if idp c and not escaped!* then <<
       total := total + 1;
       u := intern list2string explode2lc c; % Lower case name
       v := gethash(u, allnames);
       if not member(c, v) then puthash(u, allnames, c . v) >>;
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

<<
  for each p in dups do <<
    for each x in p do << princ x; princ "   " >>;
    terpri() >>;
  prin length dups; printc " symbols involved";
  nil >>;


quit;



