% Identify clashes between function definitions...

symbolic;

load!-source := t;
for each m in library!-members() do load!-source m;

linelength 100;

symbolic procedure remdups z;
  if null z then z
  else if member(car z, cdr z) then remdups cdr z
  else car z . remdups cdr z;

<< terpri();
  for each n in oblist() do <<
    z := get(n, 'load!-source);
    z := remdups z;
% I know that fmprint and tmprint are near duplicates and so I will not
% mention clashes that only involve exactly those two.
    if not atom z and not atom cdr z and cddr z and
      not (cdr z = '("fmprint" "tmprint")) then <<
      prin n; ttab 30; princ " defined in      ";
      for each z1 in cdr z do <<
        princ " "; princ z1>>;
      terpri() >> >> >>;


quit;

