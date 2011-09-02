% Examples taken from G.B. Dantzig.

lll := {x1 >= 0,
        x1+2x2  <= 6,
        x1 + x2 >= 2,
        x1 - x2 >= 3,
             x2 >= 0,
      -2 x1 -x2 <= z };

sol := linineq(lll,{x1,x2,z=min});

sol := linineq(lll,{x1,x2,z=min},record=t);

linineq({z =  x1 + 2 x2 + 3 x3 + 4 x4,
         4 =  x1 +   x2 +   x3 +   x4,
        -2 =  x1 - 2 x2 + 3 x3 - 4 x4,
         x1>=0, x2>=0, x3>=0,x4>=0},  {z=min});

linineq({z =  x1 + 2 x2 + 3 x3 + 4 x4,
         4 =  x1 +   x2 +   x3 +   x4,
        -2 =  x1 - 2 x2 + 3 x3 - 4 x4,
         x1>=0, x2>=0, x3>=0,x4>=0},  {z=max});

linineq({ x1  +   x2 >= 1,
          x1  +   x2 <= 2,
          x1  -   x2 <= 1,
          x1  -   x2 >=-1,
                 -x2  =z } , {z=min});

linineq({ 5x1 - 4x2 + 13x3 - 2x4 +  x5 = 20,
           x1 -  x2 +  5x3 -  x4 +  x5 = 8,
           x1 + 6x2 -  7x3 +  x4 + 5x5 = z,
           x1>=0,x2>=0,x3>=0,x4>=0,x5>=0},  {z=min});


% Examples for integer and mixed integer linear programming
%   (Beightler, Phillips, Wilde,  pp. 142 ff)

linineq({z= 3x1  +   2x2,
           5x1   +   4x2  <= 23.7,
                    x1            >= 0,
                                  x2  >= 0},
                {z=max},
                int={x1,x2});

linineq({z=  x1  +    x2,
          -2x1   +   5x2  <= 8, 
                   6x1   +    x2  <= 30,
                    x1            >= 0,
                                  x2  >= 0},
                {z=max},
                int={x1,x2});

linineq({z=-7x1  + 106x2,
           -x1   +  15x2  <= 90,
                    x1   +   2x2  <= 35,
                  -3x1   +   4x2  <= 12,
                    x1            >= 0,
                                  x2  >= 0},
                {z=max},
                int={x1,x2});

linineq({z=9x1 + 6x2 + 5x3,
           2x1 + 3x2 + 7x3 <= 35/2,
                   4x1       + 9x3 <= 15,
                    x1             >= 0,
                        x2             >= 0,
                        x3             >= 0},
                {z=max},
                int={x1});

% a case where the extremum requirement cannot be resolved
sol := linineq(lll,{x1,x2,z=max});

% print the selection from the intervals:

on prlinineq;
sol := linineq(lll,{x1,x2,z=min});
sol := linineq(lll,{x1,x2,z=max});

% print the full elimination process

on trlinineq;
sol := linineq(lll,{x1,x2,z=min});

end;
