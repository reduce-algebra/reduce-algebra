
#if (and (not (member 'tmprint loaded!-packages!*)) (not (getd 'linelength!-orig)))
load_package tmprint$
linelength 5000$
#endif

on fancy;

exp(a)*exp(b);
off pri;
ws;

off fancy;

end;
