symbolic;

typedef any;
typedef number checked by numberp;
typedef sf checked by sfpx;
typedef sq checked by sqp;

procedure hugo(x1,x2);
   x2;

assert hugo: (number,any) -> number;

assert_install hugo;

hugo(0,0);
hugo('x,0);
hugo(0,'x);

assert addf: (sf,sf) -> sf;
assert addsq: (sq,sq) -> sq;

assert_install addf,addsq;

addsq(simp 'x,numr simp 'x);

algebraic;

assert_analyze();

assert_uninstall_all;

end;
