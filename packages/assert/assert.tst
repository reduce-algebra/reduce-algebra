on assertcheck;

symbolic;

typedef any;
typedef number checked by numberp;
typedef sf checked by sfpx;
typedef sq checked by sqp;

procedure hugo(x1,x2);
   x2;

assert hugo: (number,any) -> number;

hugo(0,0);
hugo('x,0);
hugo(0,'x);

assert addf: (sf,sf) -> sf;
assert addsq: (sq,sq) -> sq;

addsq(simp 'x,numr simp 'x);

algebraic;

assert_analyze();

end;
