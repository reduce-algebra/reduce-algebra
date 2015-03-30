nc_setup({k,n,nn,kk},{nn*n-n*nn=nn,kk*k-k*kk=kk},left);

 p1 := (n-k+1)*nn - (n+1);
 p2 := (k+1)*kk -(n-k);
 l_g:=nc_groebner ({p1,p2});

 nc_preduce(p1+p2,l_g);

 nc_divide  (k*p1+p2,p1);
 nc_divide  (k*p1+p2,2*p1);
 nc_divide  (2*k*k*p1 + k*p1 + p2,2*p1);
 
 nc_factorize (p1*p2);

nc_setup({k,n,nn,kk},{nn*n-n*nn=nn,kk*k-k*kk=kk},right);
nc_factorize (p1*p2);

% applications to shift operators

nc_setup({n,nn},{nn*n-n*nn=1},left);
n*nn;
nc_factorize(ws);
nc_setup({n,nn},{nn*n-n*nn=1},right);
n*nn;
nc_factorize(ws);
nc_setup({nn,n},{nn*n-n*nn=1},right);
n*nn;
nc_factorize(ws);
nc_setup({nn,n},{nn*n-n*nn=1},left);
n*nn;
nc_factorize(ws);

% Applications to partial differential equations

nc_setup({x,dx},{dx*x-x*dx=1});

p:= 2*dx^2 + x* dx^3 + 3*x*dx + x^2*dx^2 + 14 + 7*x*dx;
nc_factorize p;
right_factor(p,1); % no factor of degr 1
right_factor(p,2);
left_factor(p,2);

nc_setup({x,dx},{dx*x-x*dx=1});

q := x**2*dx**2 + 2*x**2*dx + x*dx**3 + 2*x*dx**2 
    + 8*x*dx + 16*x + 2*dx**2 + 4*dx$

nc_factorize q;
right_factor(q,1);
right_factor(q,1,{x});  % no such right factor
right_factor(q,1,{dx});

% looking for factor with degree bound for an individual variable

q := x**6*dx + x**5*dx**2 + 12*x**5 + 10*x**4*dx + 20*x**3 
+ x**2*dx**3 - x**2*dx**2 + x*dx**4 - x*dx**3 + 8*x*dx**2 
- 8*x*dx + 2*dx**3 - 2*dx**2$

right_factor(q,dx);
right_factor(q,dx^2);

% some coefficient sports
nc_setup({nn,n},{nn*n-n*nn=1},left);
q:=(n*nn)^2;
nc_factorize q;
nc_preduce(q,{c1+c2*n + c3*nn + c4*n*nn});
nc_divide(q,n);

nc_cleanup;

end;
