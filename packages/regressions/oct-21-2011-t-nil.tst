for all t,f,nt,nf let fun( t,f,nt,nf) =
fun_t * t + fun_f * f + fun_nt * nt + fun_nf * nf + fun_0
$

x := fun( 1,b,c,d) ;
y := fun( a,b,c,d) ;

share t;

symbolic procedure ws(u); u;

symbolic procedure nil(u); u;

algebraic procedure nil(u); u;

for all nil let fun(nil,nil) = nil;

showrules fun;

end; 
