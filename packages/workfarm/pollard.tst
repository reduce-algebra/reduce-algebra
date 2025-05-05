% pollard.tst

% The Pollard Rho method seeks a factor of an integer in a way where the
% expected number of steps may be the square root of the smallest factor.
% It uses a pseudo-random sequence and looks for cycles in it. The time
% it takes to find a factor can be very variable depending on the exact
% starting point for that sequence. Here I set up a number of independent
% tasks each trying to find a factor, and close everything down as soon
% as the first one terminates.

% To illustrate this I will find factors of some values 2^K-1 where the
% cases I have picked have been carefully selected so that the factorization
% will complete in a tolerable but not tiny amount of time. I will report
% elapsed times.

lisp;
on time,comp,echo;

symbolic procedure report(finish, start);
  begin
    finish := 1000000*car finish + cdr finish;
    start  := 1000000*car start  + cdr start;
    optterpri();
    princ "Elapsed time ";
    prin ((finish-start)/1000);
    printc " milliseconds"
  end;

symbolic procedure pollard n;
  begin
    scalar x, b, y, d, start := timeofday();
    set!-small!-modulus n;
    repeat <<
% I start with an initial value of x that depends on the time of day
% with microsecond resolution, and so which is expected to behave
% differently on each call.
      x := modular!-number md60 timeofday();
      b := 1;
      y := x;
      d := 1;
      while d = 1 do <<
        for i := 1:100 do <<
          x := modular!-plus(modular!-times(x, x), b);
          y := modular!-plus(modular!-times(y, y), b);
          y := modular!-plus(modular!-times(y, y), b);
          d := modular!-times(d, abs(x - y)) >>;
      d := gcdn(d, n) >>;
    >> until d < n;
    report(timeofday(), start);
    return list(n, d)
  end;

symbolic procedure parapollard n;
  begin
    scalar nproc := cpu!-count(), tasks, r, start := timeofday();
    tasks := for i := 1:nproc collect open!-fork list('pollard, n);
% The time taken by pollard() can be variable - sometimes it might get
% lucky and find a factor early, on other times it may need a lot longer.
% Here I am only going to be interested in the first result returned.
    r := first!-fork tasks;
    r := get!-from!-fork r;
    for each tt in tasks do close!-fork tt;
    report(timeofday(), start);
    return r
  end;

% Here are some exponents K to use here that lead to fairly large
% smallest factors of 2^K-1 but not ones that are so large that finding
% them will take grotequely long using the method employed here:
%  67, 101, 103, 139, 199, 271

pollard(2^67-1);
pollard(2^101-1);
pollard(2^103-1);
pollard(2^139-1);
pollard(2^199-1);
pollard(2^271-1);

parapollard(2^67-1);
parapollard(2^101-1);
parapollard(2^103-1);
parapollard(2^139-1);
parapollard(2^199-1);
parapollard(2^271-1);

quit;

