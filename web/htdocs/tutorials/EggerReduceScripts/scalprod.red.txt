procedure scalprod(a,b); begin;
scalar n; 
n:=first (length(a))-1;
result:=for i:=0:n sum a(i)*b(i);
return result;
end;
end;
