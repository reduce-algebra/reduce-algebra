%
% This is used with CSL only, and builds a structure needed by the HELP
% sub-system.
%                                      A C Norman, Codemist, April 1994
%

module makehelp;

symbolic procedure read_help_data filename;
% This rather sordid code parses a HELP file.  The expected format is
% a series of sections, with each section of the form:
%    \item[sectionheading]
%    ...
%    \endsection
% Things introduced by \xitem[topic] are "under construction" and will be
% omitted from the output.  The result is handed back as an association list
% linking topics to texts (both represented as strings).
  begin
    scalar a, s, c, k, w, m, i, r, x;
    a := open(filename, 'input);
    if null a then return nil;
    terpri(); princ "About to read "; print filename;
    s := rds a;
    r := list(!*raise, !*lower, !*echo);
    !*raise := !*lower := !*echo := nil;
get_next_line:
% Here the next line ouught to be \item[...]
    w := nil;
    while (c := readch()) neq !$eol!$ and c neq !$eof!$ do w := c . w;
    if c = !$eof!$ then go to end_of_file;
% I trim leading and trailing blanks and look for \item[...]
    while eqcar(w, '! ) do w := cdr w;
    if not eqcar(w, '!]) then go to get_next_line;
    w := cdr w;
    while eqcar(w, '! ) do w := cdr w;
    w := reverse w;
    while eqcar(w, '! ) do w := cdr w;
    if not eqcar(w, '!\) then go to get_next_line;
    w := cdr w;
    if eqcar(w, '!x) then << i := t; w := cdr w >>
    else i := nil;
    if eqcar(w, '!i) then w := cdr w else go to get_next_line;
    if eqcar(w, '!t) then w := cdr w else go to get_next_line;
    if eqcar(w, '!e) then w := cdr w else go to get_next_line;
    if eqcar(w, '!m) then w := cdr w else go to get_next_line;
    if eqcar(w, '![) then w := cdr w else go to get_next_line;
    while eqcar(w, '! ) do w := cdr w;
% Keywords are all mapped onto lower case here. I am not (in the long
% term) sure that this is good, but while I have case-insensitive searches
% I should fold case early (in particular before any sorting happens)
    k := list!-to!-string for each c in w collect char!-downcase c;
    x := nil;
get_text:
% Here I am reading the body of some text. The terminator will be wither $eof$
% or the string "\endsection".  I lose any trailing blanks, but otherwise just
% collect all the characters I see (including newlines) to make a string.
    w := nil;
    while (c := readch()) neq !$eol!$ and c neq !$eof!$ do w := c . w;
    while eqcar(w, '! ) do w := cdr w;
    w := reverse w;
    if w = '(!\ !e !n !d !s !e !c !t !i !o !n) then go to add_section;
    for each g in w do x := g . x;
    x := !$eol!$ . x;
    if c neq !$eof!$ then go to get_text;
add_section:
% i was set if this was an \xitem not an \item, so I should ignore it.
    if not i then <<
       princ k;
       if posn() > 60 then terpri() else princ " ";
% I put a null character on the end of the string as a terminator.
       m := (k . list!-to!-string reverse (0 . x)) . m >>;
    if c neq !$eof!$ then go to get_next_line;
end_of_file:
    rds s;
    close a;
    !*raise := car r; !*lower := cadr r; !*echo := caddr r;
    terpri();
    return m
  end;

% The compression strategy I use here assumes that the raw input text is
% in a character set that only uses codes less than 128.  It then assigns
% codes from 128 to 255 to stand for common pairs of characters.  Only
% using 128 such combinations means that I do not get leading-edge
% compression.  But the table I need to hep me decode is only 256 bytes
% long, and the decoder is very compact and efficient.

symbolic procedure insert_pair(c, h);
  begin
    scalar w;
    w := gethash(c, h, 0);
    puthash(c, h, w+1);
% On a machine with PAGE_BITS=16 the largest hash table I can support
% has around 5000 entries.  This may be a limit that I need to extend
% sometime, but meanwhile when I get a table that is almost that full
% I will chuck away half of the entries therein.
    if getv(h, 1) > 5000 then begin
       scalar pair_frequencies;
       terpri(); printc "hash loading reached 5000: resetting";
       pair_frequencies := sort(hashcontents h,
                                function (lambda (u, v); cdr u < cdr v));
       for i := 1:2500 do pair_frequencies := cdr pair_frequencies;
       clrhash h;
       for each p in pair_frequencies do puthash(car p, h, cdr p) end
  end;

symbolic procedure get_compression_table a;
% This is liable to be a pretty painfully slow process, since I
% will use somewhat crummy algorithms - but since this is only
% executed at system-build time I am not so very worried.
  begin
    scalar c, h, h1, w, p, xx, busy, pair_frequencies, r, s, n, original_size;
    printc "About to create compression table";
% h will be a table in which I collect the frequency of occurrence of
% pairs of characters. h1 is a table that shows how I will compact some
% of the more common of these pairs into single bytes.
    h := mkhash(5002, 2, 1.5);
    h1 := mkhash(128, 2, 1.5);
% Because multiple blanks are such a very important case I will
% pre-load my tables with codes that stand for various blocks of
% blanks.
    puthash('(32 . 32), h1, 128);   r := '(32 . 32) . r;
    puthash('(128 . 128), h1, 129); r := '(128 . 128) . r;
    puthash('(129 . 129), h1, 130); r := '(129 . 129) . r;
    puthash('(130 . 130), h1, 131); r := '(130 . 130) . r;
    busy := 4;
    for pass := 1:5 do <<
       princ "Pass "; print pass;
       clrhash h;
       s := n := 0;
       for each x in a do <<
         princ car x; if posn() > 60 then terpri() else princ " ";
% The 0 stuck on the end is a null used as a terminator for the help text
% in the internal help file.
         xx := upbv cdr x;
         p := nil;
         for i := 0:xx do <<
% I consolidate any pairs of characters that have already been selected for
% coding as single bytes.
            c := byte!-getv(cdr x, i);
            n := n + 1;
            while p and (w := gethash(car p . c, h1)) do <<
               s := s + 1; c := w; p := cdr p >>;
% Now (after applying the compression that has already been decided on) I
% gather counts of how many times each pair of characters occurs.
            if pass < 5 and p then insert_pair(car p . c, h);
            p := c . p >>;
         rplacd(x, list!-to!-string reverse p) >>;
       terpri(); princ "Hash occupancy = "; print getv(h, 1);
       if pass = 1 then original_size := n;
       princ "Saved "; prin s; princ " out of "; prin n;
       princ " (originally "; prin original_size; printc ") chars";
       if pass < 5 then <<
% Sort it so that the most common pairs come first.
          pair_frequencies := sort(hashcontents h,
                                function (lambda (u, v); cdr u > cdr v));
% On each of the 4 passes I will allocate 32 codes. The first 32 codes will
% always be for just pairs of natural characters, while on subsequent
% passes I can get pairs of extended characters (themselves representing
% pairs of chars) in an expansion.
          while pair_frequencies and busy<(32*pass) do <<
             p := gethash(caar pair_frequencies, h1);
             if null p then <<
                puthash(caar pair_frequencies, h1, busy+128);
                princ caar pair_frequencies; princ " => "; prin (busy+128);
                ttab 30; print cdar pair_frequencies;
                r := caar pair_frequencies . r;
                busy := busy+1 >>;
             pair_frequencies := cdr pair_frequencies >> >>;
       terpri() >>;
    return reverse r
  end;

symbolic procedure make_help_1 filename;
  begin
    scalar a, b;
    a := read_help_data filename;
    a := sort(a, function (lambda(a, b); orderp(car a, car b)));
    b := get_compression_table a;
% The makes the structures needed by the CSL help-builder interface
% function...
    return list('write!-help!-module, mkquote a, mkquote b)
  end;

symbolic macro procedure make_help body;
   make_help_1 cadr body;

endmodule;

end;

