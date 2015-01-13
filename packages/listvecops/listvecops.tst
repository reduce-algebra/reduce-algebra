load_package listvecops;

a := {a1,a2,a3,a4};

b := {b1,b2,b3,b4};

a + b;

a - b;
 
-a;

3*x*a +7*y*b;

{a,b} + {b,a};

{a,b} - {b,a};

a*b;

{a*b,{x,y}}*{{1,1,1,1},{3,5}};

a/b + b/a;

3*a/{1,2,3,4} + {x,y,z,u}*5;

1/a;

a^3;

a^b;

x^a + b;

a^b;

a *. b;

{a,{3,5,7,9}} *. {{2,4,6,8},b};

a *. log b;

df({sin x*y,x^3*cos y},x,2,y);

int({sin x,cos x},x);

% Example of a list-valued procedure.

listproc spat3(u,v,w);
   begin scalar x,y;
     x := u *. w;
     y := u *. v;
     return v*x - w*y
   end;

u := {ux,uy,uz};
v := {vx,vy,vz};
w := {wx,wy,wz};

z := spat3(u,v,w) - 3*spat3(v,u,w);
 
spat3(u,v,w)+spat3(u,w,v);

% Accesing list elements

l := {1,{2,3},4};

lnth(l,3);

% or alternatively with the infix operator _ .

l _2*3;

l _2 _2;

% Changing list elements.

l _ 2 _ 2 := three;

l;

lnth(l,3) := {5,6};

l;

end;



