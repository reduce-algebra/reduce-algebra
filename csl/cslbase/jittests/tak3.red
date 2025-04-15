
lisp;
on echo, pgwd;

symbolic procedure tak(x, y, z);
  if y < x then tak(tak(x-1, y, z),
                    tak(y-1, z, x),
                    tak(z-1, x, y))
  else z;

tak(3, 2, 1);

% This is intended to start off as exactly the byte-sequence that
% would arise using the ordinary compiler. But I will then be commenting
% of bits if it misbehaves. Note how ugly it is that I have to refer to
% the arguments x, y and z using their stack offsets and the function to
% call by its location in the literal vector.

bytecoded tak1(x, y, z);
   (tak1)
   (
       pushnil2
       push
       call3 0           % This will give stack overflow!!!
       loc2exit);

tak1(3, 2, 1);
jit!-tak1(3, 2, 1);

end;
