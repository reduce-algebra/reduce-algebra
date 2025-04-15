
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
   (   pushnil2
% now we have
%       0   w1
%       1   w2
%       2   z
%       3   y
%       4   x
    !:G0001
       loadloc 3
       loadloc 4
       lessp
       jumpnil G0002
       loadloc 4
       sub1
       push
       loadloc 4
       loadloc 3
       call3 0
       storeloc 1
       loadloc 3
       sub1
       push
       loadloc 3
       loadloc 5
       call3 0
       storeloc 0
       loadloc 2
       sub1
       push
       loadloc 5
       loadloc 4
       call3 0
       storeloc 2
       loadloc 0
       storeloc 3
       loadloc 1
       storeloc 4
       jump_b G0001
    !:G0002
       loc2exit);

tak1(3, 2, 1);
jit!-tak1(3, 2, 1);

end;

