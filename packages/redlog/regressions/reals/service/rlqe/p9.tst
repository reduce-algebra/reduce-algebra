% Testing rlqe

% Prolog III. Communications of the ACM. 33(7), 70-90, July 1990
% Description of the problem on p.79: Consider the infinite sequence
% of real numbers defined by x_{i+2}:=|x_{i+1}|-x_i where $x_1$ and
% $x_2$ are arbitrary numbers. Our aim is to show that this sequence
% is always periodic and that the period is 9, in other words that the
% sequences $x_1, x_2, \dots$ and $x_{1+9}, x_{2+9}, \dots$ are always
% identical.

off rlabout;

rlset reals;

p9 := rlall((for i:=1:9 mkand
   mkid(x,i+1)>=0 and mkid(x,i+2)=mkid(x,i+1)-mkid(x,i) or
   mkid(x,i+1)<0 and mkid(x,i+2)=-mkid(x,i+1)-mkid(x,i))
      impl x1=x10 and x2=x11)$

rlqe p9;

end;
