
load_package linalg;

x := mat((a),(b))$

y := mat((c),(d))$

tp band_matrix({a,b,c},4);

tp block_matrix(1,2,{x,y});

tp char_matrix(mat((a,b),(c,d)),z);

tp first cholesky(mat((1,1,0),(1,3,1),(0,1,1)));

tp companion(u^4+17*u^3-9*u^2+11,u);

tp copy_into(x,y,1,1);

tp diagonal({2,3});

tp hermitian_tp x;

tp hessian(u*v*w+u^2,{q,u,v,w});

tp hilbert(3,u+v);

tp mat_jacobian({u^4,u*v^2,u*v*w^3},{q,u,v,w});

tp jordan_block(u,5);

tp make_identity(4);

tp matrix_augment(x,y);

tp matrix_stack(x,y);

tp minor(mat((1,3),(-4,3)),1,1);

tp pivot(x,1,1);

tp rows_pivot(x,1,1,{1});    

tp pseudo_inverse mat ((1,2),(3,4));

tp random_matrix(3,3,10);

tp remove_columns(random_matrix(3,3,10),2);

tp remove_rows(random_matrix(3,3,10),2);

tp toeplitz({u,v,w});

tp vandermonde({u,2*v,3*w});


rank matrix_augment (x,y);

end;


