symbolic;

struct Tag;
struct PosNumber asserted by PosNumberP;

procedure PosNumberP(s);
   numberp s and s > 0;

asserted procedure hugo(x1: Number, x2: PosNumber, x3: Tag): DottedPair;
   x3 . (x1 + x2);

hugo(1, 1, 'y);
hugo(1, -1, 'y);

assert_install hugo;

hugo(1, 1, 'y);
hugo(1, -1, 'y);

assert_uninstall hugo;

declare addf: (SF, SF) -> SF;
declare addsq: (SQ, SQ) -> SQ;

assert_install addf, addsq;

addsq(simp 'x, numr simp 'x);

algebraic;

assert_analyze();

assert_uninstall_all;

end;
