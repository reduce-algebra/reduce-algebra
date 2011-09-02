
plot(sin x,x=(-3 .. 3));
plot(s=sin phi,phi=(-3 .. 3));
plot(sin phi,cos phi,phi=(-3 .. 3));
plot(sin(1/x),x=(-1 .. 1),y=(-3 .. 3));
plot(sin(1/x),x=(-10 .. 10));
plot(y=tan x,y=(-10 .. 10));


plot (cos sqrt(x**2 + y**2),x=(-3 .. 3),y=(-3 .. 3));
plot (cos sqrt(x**2 + y**2),x=(-3 .. 3),y=(-3 .. 3),hidden3d);
plot(x*y, x=(0 .. 2), y=(0 .. 2));
plot(x*y, x=(-2 .. 2), y=(-2 .. 2));
plot(x+y, x=(0 .. 2), y=(0 .. 2));
plot(1/(x**2+y**2),x=(-0.5 .. 0.5),y=(-0.5 .. 0.5));
plot(1/(x**2+y**2),x=(-0.5 .. 0.5),y=(-0.5 .. 0.5),hidden3d);
plot(1/(x**2+y**2),x=(0.1 .. 5),y=(0.1 .. 5),size="0.7,1");
plot(1/(x**2+y**2),x=(0.1 .. 5),y=(0.1 .. 5),view="30,89");
plot(1/(x**2+y**2),x=(-0.5 .. 0.5),y=(-0.5 .. 0.5),
      hidden3d,contour,view="70,20");

plot(sinh(x*y)/sinh(2*x*y),hidden3d);

% general curves and surfaces computed as lists of data points

plot {{0,0},{0,1},{1,1},{0,0},{1,0},{0,1},{0.5,1.5},{1,1},{1,0}};
on rounded;
w:=for j:=1:200 collect {1/j*sin j,1/j*cos j,j/200}$
plot w;

w:= {for j:=1 step 0.1 until 20 collect
         {1/j*sin j,1/j*cos j,j},
     for j:=1 step 0.1 until 20 collect
         {(0.1+1/j)*sin j,(0.1+1/j)*cos j,j}
     }$
plot w;

dd:=pi/15;

w:=for u:=dd step dd until pi-dd collect
    for v:=0 step dd until 2pi collect
      {sin(u)*cos(v), sin(u)*sin(v), cos(u)}$

plot w;

end;
