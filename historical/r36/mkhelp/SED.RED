%
% This program makes some systematic edits, and some that are clearly
% ad hoc. The syematic changes include expanding tabs and cleaning up
% trailing whitespace, plus processing of some escapes that "info" format
% uses. The ad hoc ones appear to relate to "words" that have embedded
% apostrophes.
%
% It replaces a sequence of Unix-specific commands, which included use of
% expand to dispose of tabs and several uses of sed to perform the other
% transformations.
% It transforms from redhelp.x into redhelp.y
% It will also be MUCH slower than direct use of Unix utilities, in part
% because it has been coded here with simplicity, portability and clarity
% as objectives above speed. After all the help file is not re-created
% by end-users and not altered very often anyway.
%
%                                        A C Norman.        December 1995

symbolic;
on comp;

fluid '(edits n_edits);

edits := for each p in '(
   ("Euler's"            . "Euler")
   ("EULER'S"            . "EULER")
   ("Euler constant can" . "Euler's constant can")
   ("Catalan's"          . "Catalan")
   ("CATALAN'S"          . "CATALAN")
   ("Khinchin's"         . "Khinchin")
   ("KHINCHIN'S"         . "KHINCHIN")
   ("Khinchin book"      . "Khinchin's book")
   ("Jacobi's"           . "Jacobi")
   ("@$"                 . "$")
   ("@key"               . "(Key)")
   ("@%"                 . "%")
   ("@_"                 . "_")
         ) collect (explode2 car p . explode2 cdr p);



symbolic procedure matches(x, p);
   if null p then list x
   else if null x then nil
   else if car x eq car p then matches(cdr x, cdr p)
   else nil;

symbolic procedure make_edits();
  begin
    scalar fi, fo, c, line, n, p, w, t0, n_edits,
           !*echo, !*raise, !*lower;
    t0 := time();
    fi := open("redhelp.x", 'input);
    if null fi then error(0, "Input file not available");
    fo := open("redhelp.y", 'output);
    if null fo then error(0, "Output file not available");
    fi := rds fi;
    fo := wrs fo;
    linelength 1000; % Output must never wrap.
    n_edits := 0;
    c := !$eol!$;
    while not (c = !$eof!$) do <<
       line := nil;
       n := 0;
% While reading a line in I will process tabs, counting a tab as at least
% one blank and then enough to pad out to the next multiple of 8.
       while not ((c := readch()) = !$eol!$ or c = !$eof!$) do <<
          if c = tab!* then <<
             repeat << line := '!  . line;
                       n := n + 1 >> until zerop remainder(n, 8) >>
          else << line := c . line; n := n + 1 >> >>;
% Next I act on 's/  *$//g', which discards trailing blanks.
       while eqcar(line, '!  ) do line := cdr line;
       line := reversip line;
       while line do <<
          for each p in edits do
             if (w := matches(line, car p)) then <<
                 n_edits := n_edits + 1;
                 line := append(cdr p, car w) >>;
          prin2 car line;
          line := cdr line >>;
       terpri() >>;
    rds fi;
    wrs fo;
    close fi;
    close fo;
    prin2 n_edits; prin2t " edits performed";
    return (time() - t0)/1000.0
  end;

make_edits();

quit;


