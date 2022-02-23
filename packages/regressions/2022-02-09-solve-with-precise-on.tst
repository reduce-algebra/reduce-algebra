Comment

   Bug report  https://sourceforge.net/p/reduce-algebra/bugs/143/

   Infinite recursion in solve with off precise ;

solve(1.2*(1.087^t)=9.3*(0.984^t),t);

off precise;

solve(1.2*(1.087^t)=9.3*(0.984^t),t);

on rounded;

solve(1.2*(1.087^t)=9.3*(0.984^t),t);

end;
