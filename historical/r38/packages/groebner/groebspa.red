module groebspa;
 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% Manipulation of subspaces .
% A subspace among the variables is described by an exponent vector
% with only zeroes and ones . It terminates with the last
% one . It may be null(nil).

symbolic procedure vevunion(e1,e2);
begin scalar x,y;y:=vevunion1(e1,e2);
 x:=reverse y;if car x = 1 then return y;
 while x and car x = 0 do x:=cdr x;return reversip x end;

symbolic procedure vevunion1(e1,e2);
 if vdpsubspacep(e1,e2)then e2 else
 if vdpsubspacep(e2,e1)then e1 else
 if car e1 neq 0 or car e2 neq 0 then 1 . vevunion1(cdr e1,cdr e2)else
  0 . vevunion1(cdr e1,cdr e2);
           
symbolic procedure vdpsubspacep(e1,e2);  
% Test if e1 describes a subspace from e2 .
 if null e1 then t else
 if null e2 then vdpspacenullp e1 else
 if car e1 > car e2 then nil else
 if e1 = e2 then t else vdpsubspacep(cdr e1,cdr e2);
          
symbolic procedure vdporthspacep(e1,e2);
% Test if e1 and e2 describe orthogonal spaces(no intersection).
 if null e1 or null e2 then t else
 if car e2 = 0 or car e1 = 0 then vdporthspacep(cdr e1,cdr e2)else nil;

symbolic procedure vdpspacenullp e1;
% Test if e1 describes an null space .
 if null e1 then t else
 if car e1 = 0 then vdpspacenullp cdr e1 else nil;

symbolic procedure vdpspace p;
% Determine the variables of the polynomial .
begin scalar x,y;
 if vdpzero!? p then return nil;
 x:=vdpgetprop(p,'subroom);
 if x then return x;
 x:=vevunion(nil,vdpevlmon p);
 y:=vdpred p;
 while not vdpzero!? y do
 <<x:=vevunion(x,vdpevlmon y);y:=vdpred y>>;
 vdpputprop(p,'subroom,x);
 return x end;

symbolic procedure vdpunivariate!? p;
 if vdpgetprop(p,'univariate)then t
  else begin scalar ev;integer n;
   ev:=vdpevlmon p;
   for each x in ev do 
    if not(x = 0)then n:=n #+ 1;
    if not(n = 1)then return nil;
    ev:=vdpspace p;
    for each x in ev do 
     if not(x = 0)then n:=n #+ 1;
     if not(n = 1)then return nil;
     vdpputprop(p,'univariate,t);
     return t end;
         
endmodule;;end;
