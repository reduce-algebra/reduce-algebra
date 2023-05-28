% This is a test file for use while working on "lambda" expressions in
% Reduce. At the time this is issues (May 2023) there are issues!
% (a) As per the Reduce manual, lambda expressions are only expected to
%     be fully supported in symbolic mode. I may hope that this test
%     file will encourage development until algebraic mode is also OK.
% (b) There is a new notation, as in "[x]E" as a synomyn for "lambda x;E".
%     This file illustrates it and may help with checks that this new
%     notation and the original one stay in step.
%
% I will put "@@@" markers here where there are pending issues!

on echo,defn;

% LAMBDA is not "supposed" to be used in algebraic mode, but I will
% try some cases anyway. First lambda expressions free-standing.

algebraic;

(lambda (); 12345);
(lambda x; x+1);
(lambda (x, y); x + y + 1);

% Then the same but applied to suitable arguments.
% @@@ various of these return structures in the style "(plus x 1)" rather
%     than properly simplified and formatted algebraic exressions. The
%     visible result may need to be passed through aeval.

(lambda (); 12345) ();
(lambda x; x+z) 4;
(lambda (x, y); x + y + z) (4, 5);

symbolic;
fluid '(v);
v := 17;

% Now the same cases but in symbolic mode.

(lambda (); 12345);
(lambda x; x+1);
(lambda (x, y); x + y + 1);

(lambda (); 12345) ();
(lambda x; x+v) 4;
(lambda (x, y); x + y + v) (4, 5);

% Now I will have just the same examples but expressed using the "[]"
% notation.

algebraic;

([] 12345);
([x] (x+1));
([x, y] (x + y + 1));

([] 12345) ();
([x] (x+y)) 4;
([x, y] (x + y + z)) (4, 5);

symbolic;

([] 12345);
([x] (x+1));
([x, y] (x + y + 1));

([] 12345) ();
([x] (x+v)) 4;
([x, y] (x + y + v)) (4, 5);

algebraic;

off defn;

% Now I will repeat the above but without "on defn".

algebraic;

(lambda (); 12345);
(lambda x; x+1);
(lambda (x, y); x + y + 1);

% Then the same but applied to suitable arguments.
% @@@ various of these return structures in the style "(plus x 1)" rather
%     than properly simplified and formatted algebraic exressions. The
%     visible result may need to be passed through aeval.

(lambda (); 12345) ();
(lambda x; x+z) 4;
(lambda (x, y); x + y + z) (4, 5);

symbolic;
fluid '(v);
v := 17;

% Now the same cases but in symbolic mode.

(lambda (); 12345);
(lambda x; x+1);
(lambda (x, y); x + y + 1);

(lambda (); 12345) ();
(lambda x; x+v) 4;
(lambda (x, y); x + y + v) (4, 5);

% Now I will have just the same examples but expressed using the "[]"
% notation.

algebraic;

([] 12345);
([x] (x+1));
([x, y] (x + y + 1));

([] 12345) ();
([x] (x+y)) 4;
([x, y] (x + y + z)) (4, 5);

symbolic;

([] 12345);
([x] (x+1));
([x, y] (x + y + 1));

([] 12345) ();
([x] (x+v)) 4;
([x, y] (x + y + v)) (4, 5);

algebraic;



% The next cases fail at present even though the right hand sides in these
% assignments behave a bit better when issued free-standing. I expect that
% this will be straightforward to fix!

off int;

p := (lambda (); 12345);
%p := (lambda x; (x+1));
%p := (lambda (x,y); (x + y + 1));
%p := ([] 12345);
%p := ([x] (x+1));
%p := ([x, y] (x + y + 1));

% End of tests

end;

