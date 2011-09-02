module linrel;

% Author: James H. Davenport.

symbolic procedure firstlinearrelation(m,n);
% Returns vector giving first linear relation between
% the rows of n*n matrix m.
begin
  scalar m1,u,uu,v,w,x,xx,i,j,isub1n,ans;
  isub1n:=isub1 n;
  m1:=mkvect(isub1n);
  for i:=0 step 1 until isub1n do
    putv(m1,i,copyvec(getv(m,i),isub1n));
  % m1 is a copy of m which we can afford to destroy.
  ans:=mkidenm isub1n;
  i:=0;
outerloop:
  u:=getv(m1,i);
  uu:=getv(ans,i);
  j:=0;
pivotsearch:
  if j iequal n
    then goto zerorow;
  v:=getv(u,j);
  if null numr v then << j:=iadd1 j; goto pivotsearch >>;
  % we now use the j-th element of row i to flatten the j-th
  % element of all later rows.
  if i iequal isub1n then return nil;
    %no further rows to flatten, so no relationships.
  v:=!*invsq negsq v;
  for k:=iadd1 i step 1 until isub1n do <<
    xx:=getv(ans,k);
    x:=getv(m1,k);
    w:=!*multsq(v,getv(x,j));
    for l:=0:isub1n do <<
      putv(x,l,!*addsq(getv(x,l),!*multsq(w,getv(u,l))));
      putv(xx,l,!*addsq(getv(xx,l),!*multsq(w,getv(uu,l)))) >> >>;
  i:=iadd1 i;
  if i < n then goto outerloop;
  % no zero rows found at all.
  return nil;
zerorow:
  % the i-t row is all zero, i.e. rows 1...i are dependent.
  return getv(ans,i)
  end;

endmodule;

end;
