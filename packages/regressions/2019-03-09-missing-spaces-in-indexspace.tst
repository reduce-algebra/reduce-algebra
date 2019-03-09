
% Protect against invalid input in cantens package
% (Missing spaces around .. operator)

load_package cantens;

off onespace;

define_spaces wholespace={6,signature=1,indexrange=0 .. 5};

% The following used to try cdr of an atom
define_spaces eucl={6,euclidian,indexrange=4..9};

end;
