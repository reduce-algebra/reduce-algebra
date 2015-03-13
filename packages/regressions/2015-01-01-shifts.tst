lisp;

off echo;
on comp;

write "OMIT";

% Firsly lshift and ashift seem unavailable unless compiled...
symbolic procedure lshh(a, b); lshift(a, b);
symbolic procedure ashh(a, b); ashift(a, b);

write "TIMO";

<<
prin2 "lshh( 511, -3)                  ";   print (lshh( 511, -3));
prin2 "lshh( 511 + 2^40, -3) - 2^37    ";   print (lshh( 511 + 2^40, -3) - 2^37);
prin2 "lshh( 511 - 2^40, -3) + 2^37    ";   print (lshh( 511 - 2^40, -3) + 2^37);

prin2 "lshh(-511, -3)                  ";   print (lshh(-511, -3));
prin2 "lshh(-511 + 2^40, -3) - 2^37    ";   print (lshh(-511 + 2^40, -3) - 2^37);
prin2 "lshh(-511 - 2^40, -3) + 2^37    ";   print (lshh(-511 - 2^40, -3) + 2^37);

prin2 "ashh( 511, -3)                  ";   print (ashh( 511, -3));
prin2 "ashh( 511 + 2^40, -3) - 2^37    ";   print (ashh( 511 + 2^40, -3) - 2^37);
prin2 "ashh( 511 - 2^40, -3) + 2^37    ";   print (ashh( 511 - 2^40, -3) + 2^37); 

prin2 "ashh(-511, -3)                  ";   print (ashh(-511, -3));
prin2 "ashh(-511 + 2^40, -3) - 2^37    ";   print (ashh(-511 + 2^40, -3) - 2^37);
prin2 "ashh(-511 - 2^40, -3) + 2^37    ";   print (ashh(-511 - 2^40, -3) + 2^37); 
nil>>;

end;
