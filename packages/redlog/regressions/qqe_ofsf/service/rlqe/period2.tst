off rlabout;

rlset(qqe,ofsf);

% 2-periodic queue of odd length with prefix [0,0] and postfix [1,1]:
p2 := ex(qp,q == ladd(0,ladd(0,radd(1,radd(1,qp)))) and
ex({x,y},x <> y and ladd(y,ladd(x,qp)) == radd(y,radd(x,qp))))$

rlqe p2;

end;
