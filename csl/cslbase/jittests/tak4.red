
lisp;
on echo, pgwd;


bytecoded tak1(x, y, z);
   (tak1)
   (
       jumpnil label
    !:label
       exit
       loc2exit % never reached I hope!
   );

tak1(3, 2, 1);
jit!-tak1(3, 2, 1);

bytecoded tak2(x, y, z);
   (tak2)
   (
       jumpt label
    !:label
       exit
       loc2exit % never reached I hope!
   );

tak2(3, 2, 1);
jit!-tak2(3, 2, 1);

end;
