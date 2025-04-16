lisp;
on echo;

bytecoded eek(a, b, c);
   (eek here is some stuff)
   (loadlit 1
    loadlit 3
    jump_l exitlabel
    loadlit 1
    nilexit
!:exitlabel
    swop
    exit
    loc1exit
    loc2exit
    exit);

eek('x, 'y, 'z);
jit!-eek('x, 'y, 'z);
jit!-eek('x, 'y, 'z);
jit!-eek('x, 'y, 'z);


end;

