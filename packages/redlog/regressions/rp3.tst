% Test rlqe (linear)
% Rectangle Problem with b normalized to 1

rlset reals;

rp3 := ex(x1,ex(x2,ex(x3,ex(y1,ex(y2,ex(y3,ex(d2,ex(d3,all(u,all(v,a -
d1 - x1 >= 0 and a - d2 - x2 >= 0 and a - d3 - x3 >= 0 and a > 0 and d1
- d2 < 0 and d1 + y1 - 1 <= 0 and d1 > 0 and d2 - d3 < 0 and d2 + y2 - 1
 <= 0 and d3 + y3 - 1 <= 0 and x1 >= 0 and x2 >= 0 and x3 >= 0 and y1 >=
 0 and y2 >= 0 and y3 >= 0 and not(d2 - x1 + x2 > 0 and d2 - y1 + y2 > 0
 and x1 - x2 >= 0 and y1 - y2 >= 0 or d1 - d2 + x1 - x2 < 0 and d1 + x1
- x2 >= 0 and d2 - y1 + y2 > 0 and y1 - y2 >= 0 or d1 - d2 + y1 - y2 < 0
 and d1 + y1 - y2 >= 0 and d2 - x1 + x2 > 0 and x1 - x2 >= 0 or d1 - d2
+ x1 - x2 < 0 and d1 - d2 + y1 - y2 < 0 and d1 + x1 - x2 >= 0 and d1 +
y1 - y2 >= 0 or d3 - x1 + x3 > 0 and d3 - y1 + y3 > 0 and x1 - x3 >= 0
and y1 - y3 >= 0 or d1 - d3 + x1 - x3 < 0 and d1 + x1 - x3 >= 0 and d3 -
 y1 + y3 > 0 and y1 - y3 >= 0 or d1 - d3 + y1 - y3 < 0 and d1 + y1 - y3
>= 0 and d3 - x1 + x3 > 0 and x1 - x3 >= 0 or d1 - d3 + x1 - x3 < 0 and
d1 - d3 + y1 - y3 < 0 and d1 + x1 - x3 >= 0 and d1 + y1 - y3 >= 0 or d1
+ x1 - x2 > 0 and d1 + y1 - y2 > 0 and x1 - x2 <= 0 and y1 - y2 <= 0 or
d1 - d2 + x1 - x2 > 0 and d1 + y1 - y2 > 0 and d2 - x1 + x2 >= 0 and y1
- y2 <= 0 or d1 - d2 + y1 - y2 > 0 and d1 + x1 - x2 > 0 and d2 - y1 + y2
 >= 0 and x1 - x2 <= 0 or d1 - d2 + x1 - x2 > 0 and d1 - d2 + y1 - y2 >
0 and d2 - x1 + x2 >= 0 and d2 - y1 + y2 >= 0 or d3 - x2 + x3 > 0 and d3
 - y2 + y3 > 0 and x2 - x3 >= 0 and y2 - y3 >= 0 or d2 - d3 + x2 - x3 <
0 and d2 + x2 - x3 >= 0 and d3 - y2 + y3 > 0 and y2 - y3 >= 0 or d2 - d3
 + y2 - y3 < 0 and d2 + y2 - y3 >= 0 and d3 - x2 + x3 > 0 and x2 - x3 >=
 0 or d2 - d3 + x2 - x3 < 0 and d2 - d3 + y2 - y3 < 0 and d2 + x2 - x3
>= 0 and d2 + y2 - y3 >= 0 or d1 + x1 - x3 > 0 and d1 + y1 - y3 > 0 and
x1 - x3 <= 0 and y1 - y3 <= 0 or d1 - d3 + x1 - x3 > 0 and d1 + y1 - y3
> 0 and d3 - x1 + x3 >= 0 and y1 - y3 <= 0 or d1 - d3 + y1 - y3 > 0 and
d1 + x1 - x3 > 0 and d3 - y1 + y3 >= 0 and x1 - x3 <= 0 or d1 - d3 + x1
- x3 > 0 and d1 - d3 + y1 - y3 > 0 and d3 - x1 + x3 >= 0 and d3 - y1 +
y3 >= 0 or d2 + x2 - x3 > 0 and d2 + y2 - y3 > 0 and x2 - x3 <= 0 and y2
 - y3 <= 0 or d2 - d3 + x2 - x3 > 0 and d2 + y2 - y3 > 0 and d3 - x2 +
x3 >= 0 and y2 - y3 <= 0 or d2 - d3 + y2 - y3 > 0 and d2 + x2 - x3 > 0
and d3 - y2 + y3 >= 0 and x2 - x3 <= 0 or d2 - d3 + x2 - x3 > 0 and d2 -
 d3 + y2 - y3 > 0 and d3 - x2 + x3 >= 0 and d3 - y2 + y3 >= 0) and (a -
u > 0 and u >= 0 and v - 1 < 0 and v >= 0 impl d1 - u + x1 > 0 and d1 -
v + y1 > 0 and u - x1 >= 0 and v - y1 >= 0 or d2 - u + x2 > 0 and d2 - v
+ y2 > 0 and u - x2 >= 0 and v - y2 >= 0 or d3 - u + x3 > 0 and d3 - v
+ y3 > 0 and u - x3 >= 0 and v - y3 >= 0)))))))))))$

rlqe rp3;

end;
