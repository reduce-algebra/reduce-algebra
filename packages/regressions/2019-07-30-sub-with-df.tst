
Comment Test of various substitutions in df expressions;

operator f,g;

% should be returned unchanged
sub(y=x,df(f(x-y),x));

% should be returned unchanged
sub(y=g(x),df(f(x-y),x));

% should return df(f(x-y),x)
sub(z=x,df(f(x-y),x));

% should return df(f(x-g(u),x)
sub(y=g(u),df(f(x-y),x));

depend u,x;

% should be returned unchanged
sub(y=g(u),df(f(x-y),x));

end;
