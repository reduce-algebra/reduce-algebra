%
% Problem reported in
%  https://sourceforge.net/p/reduce-algebra/discussion/899364/thread/5745ad48fe/?limit=25

% The following is positive for -1 < x < 0 and negative for 0 < x < 1
f := ((1+x)/(1-x))^(1/4)*(x^2-x);

% Should be -3^(1/4)/4
sub(x=1/2,f);

on rationalize;

% The following came out with sign reversed, because of a different branch of the root.
g := f;

% Used to print +3^(1/4)/4, is now correct
sub(x=1/2,g);

end;
