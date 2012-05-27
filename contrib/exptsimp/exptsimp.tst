comment Test file for exptsimp.red...load this first;

pp := b^(2/3) * b^(7/9);

exptsimp pp;

exptsimp ((5 + 2 * sqrt(6)) / (sqrt(3) + sqrt(2)));

comment Some examples from the book by Davenport, Tournier & Tournier,
        page 77;

exptsimp ((x+sqrt(x^2-1))/(sqrt((x+1)/2)  + sqrt((x-1)/2)));

z := 112 + 70 * sqrt 2 + sqrt 5 * (46 + 34 sqrt 2);

n := 5 + 4 * sqrt 2 + sqrt (5) * (3 + sqrt 2);

exptsimp (z/n);

z1 := (32/5)^(1/5) - (27/5)^(1/5) ;

n1 := (1/25)^(1/5) + (3/25)^(1/5) - (9/25)^(1/5);

exptsimp (z1/n1);

exptsimp (ws/n1);

exptsimp (e**(x**2/2) / e**(x**2/3));

end;
