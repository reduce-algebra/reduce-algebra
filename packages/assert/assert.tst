symbolic;

on1 'assert;

struct tag;
struct posnumber asserted by posnumberp;

procedure posnumberp(s);
   numberp s and s > 0;

asserted procedure hugo(x1: number, x2: posnumber, x3: tag): dottedpair;
   x3 . (x1 + x2);

hugo(1, 1, 'y);
hugo(1, -1, 'y);

assert_install hugo;

hugo(1, 1, 'y);
hugo(1, -1, 'y);

assert_uninstall hugo;

declare addf: (sf, sf) -> sf;
declare addsq: (sq, sq) -> sq;

assert_install addf, addsq;

addsq(simp 'x, numr simp 'x);

algebraic;

assert_analyze();

assert_uninstall_all;

end;
