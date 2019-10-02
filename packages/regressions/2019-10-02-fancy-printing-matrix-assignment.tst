
Comment Problem reported on the reduce-algebra-developers mailing list by René Grognard:

The input 
 
 a := mat((a11,a12),(a21,a22))

does not produce output in fancy mode. After the next statement, the output is printed.

$

#if (and (not (member 'tmprint loaded!-packages!*)) (not (getd 'linelength!-orig)))
%#if (not (member 'tmprint loaded!-packages!*))
load_package tmprint$
linelength 5000$
#endif

on fancy;

a := mat((a11,a12),(a21,a22));

x := y;

off fancy;
end;
