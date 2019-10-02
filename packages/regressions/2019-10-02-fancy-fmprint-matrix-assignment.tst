
Comment Problem reported on the reduce-algebra-developers mailing list by René Grognard:

The input 
 
 a := mat((a11,a12),(a21,a22))

does not produce output in fancy mode. After the next statement, the output is printed.

This tests the fmprint version instead of tmprint.

$

load_package fmprint;


on fancy,fancy_tex;

a := mat((a11,a12),(a21,a22));

x := y;

off fancy;
end;
