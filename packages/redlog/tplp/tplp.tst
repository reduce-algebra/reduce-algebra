% ----------------------------------------------------------------------
% $Id: tplp.tst,v 1.2 2007/10/03 11:29:52 sturm Exp $
% ----------------------------------------------------------------------
% Copyright (c) 2007 by T. Sturm
% ----------------------------------------------------------------------
load redlog;

rlset(tplp,{{o,0},{s,3}},{{r,4},{p,0}});

o := 3;

hu := r(o,o,o);

wa := p();

prop 'hu;

prop 'wa;

f := ex(x,r(s(x,x,x),o,s(o,x,y)) and p() and (not r(o,o,x) or hu or wa));

y := s(a,b,c);

f;

rlkapur f;

% Sokrates

rlset(tplp,{{sokrates,0}},{{m,1},{s,1}});

sok := (all(x,m(x) impl s(x)) and m(sokrates)) impl s(sokrates);

end;
