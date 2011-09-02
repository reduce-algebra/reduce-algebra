module groebspa;
 
% % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
% manipulation of subspaces.
% A subspace among the variables is described by an exponent vector
%  with only zeroes and ones. It terminates with the last
% one. It may be null (nil);

expr procedure vevUnion(e1,e2);
    begin scalar x,y;
       y := vevUnion1(e1,e2);
       x := reverse y;
       if car x = 1 then return y;
       while x and car x = 0 do x := cdr x;
       return reversip x;
    end;

expr procedure vevUnion1(e1,e2);
    if vdpSubspacep(e1,e2) then e2
       else
    if vdpSubspacep(e2,e1) then e1
       else
    if car e1 neq 0 or car e2 neq 0 then 1 . vevUnion1(cdr e1,cdr e2)
       else
          0 . vevUnion1(cdr e1,cdr e2);
           
expr procedure vdpSubspacep(e1,e2);     
% test if e1 describes a subspace from e2
    if null e1 then t
      else
    if null e2 then vdpSpacenullp(e1)
      else
    if car e1 > car e2 then nil
      else
    if e1 = e2 then t
      else
         vdpSubspacep(cdr e1,cdr e2);
          
expr procedure vdpOrthSpacep(e1,e2);  
% test if e1 and e2 describe orthogonal spaces(no intersection);
    if null e1 or null e2 then t
       else
    if car e2 = 0 or car e1 = 0
          then vdpOrthSpacep(cdr e1,cdr e2)
       else nil;

                 
expr procedure vdpSpacenullp(e1);
% test if e1 describes an null space
     if null e1 then t
        else
     if car e1 = 0 then vdpSpacenullp(cdr e1)
        else nil;
 

expr procedure vdpSpace(p);
  % determine the variables of the polynomial.
    begin scalar x,y;
        if vdpzero!? p then return nil;
        x := vdpGetProp(p,'SUBROOM);
        if x then return x;
        x := vevUnion(nil,vdpevlmon p);
        y := vdpred p;
        while not vdpzero!? y do
         <<x := vevUnion(x,vdpevlmon y);
           y := vdpred y>>;
        vdpPutProp (p,'SUBROOM,x);
        return x;
    end;

symbolic procedure vdpUnivariate!?(p);
    if vdpGetProp(p,'UNIVARIATE) then t
     else begin scalar ev; integer n;
         ev := vdpevlmon p;
         for each x in ev do 
           if not(x=0) then n := n#+1;
         if not(n=1) then return nil;
         ev := vdpSpace(p);
         for each x in ev do 
           if not(x=0) then n := n#+1; 
         if not(n=1) then return nil; 
         vdpPutProp(p,'UNIVARIATE,t);
         return t;
     end;
         
endmodule;

end;
