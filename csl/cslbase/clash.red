% Identify clashes between function definitions...

symbolic;

% for each n in oblist() do put(n, 'load!-source, t);

load!-source := t;

for each m in library!-members() do load!-source m;

linelength 100;

<< terpri();
  for each n in oblist() do <<
    z := get(n, 'load!-source);
    if not atom z and not atom cdr z and cddr z then <<
      prin n; ttab 30; princ " defined in";
      for each z1 in cdr z do <<
        princ " "; princ z1>>;
      terpri() >> >> >>;


quit;

