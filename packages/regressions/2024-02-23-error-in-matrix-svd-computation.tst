load_package linalg,sparse;

on backtrace;

on rounded;
print_precision 6;

matrix tmp1,tmp2;

listproc compare_sparse(spsvdlis,svdlis);
begin scalar z;
   z := {};
   tmp1 := third spsvdlis; tmp2:= third svdlis;
   z := 
      (for i:=1:first length tmp2 collect
	 for j:=1:second length tmp2 collect
	    tmp1(i,j) - tmp2(i,j)) . z;
   tmp1 := second spsvdlis; tmp2:= second svdlis;
   z := 
      (for i:=1:first length tmp2 collect
	 for j:=1:second length tmp2 collect
	    tmp1(i,j) - tmp2(i,j)) . z;
   tmp1 := first spsvdlis; tmp2:= first svdlis;
   z := 
      (for i:=1:first length tmp2 collect
	 for j:=1:second length tmp2 collect
	    tmp1(i,j) - tmp2(i,j)) . z;
   return z;
end;

mata := mat((-2,3),(5,7));
matb := mata/3;
matc := mata/2;

svda := svd(mata);
svdb := svd(matb);
svdc := svd(matc);
  
mat01 := mat((12,1,0,0,0),
   (1,9,1,0,0),
   (0,1,6,1,0),
   (0,0,1,3,1),
   (0,0,0,1,0));

svd01 := svd(mat01);

first(svd01)*second(svd01)*tp third(svd01);
ws-mat01;

sparse spmat01(5,5);
for i:=1:first length mat01 do
   for j:=1:second length mat01 do
      if mat01(i,j) neq 0 then spmat01(i,j) := mat01(i,j);

%spsvd01 := spsvd(spmat01);

%compare_sparse(spsvd01,svd01);


mat02 := mat((3,2,2),(2,3,-2));

svd02 := svd(mat02);

first(svd02)*second(svd02)*tp third(svd02);
ws-mat02;

sparse spmat02(2,3);
for i:=1:first length mat02 do
   for j:=1:second length mat02 do
      if mat02(i,j) neq 0 then spmat02(i,j) := mat02(i,j);

%spsvd02 := spsvd(spmat02);

%compare_sparse(spsvd02,svd02);


mat03 := mat((-3,1),(6,-2),(6,-2));

svd03 := svd(mat03);

first(svd03)*second(svd03)*tp third(svd03);
ws-mat03;

sparse spmat03(3,2);
for i:=1:first length mat03 do
   for j:=1:second length mat03 do
      if mat03(i,j) neq 0 then spmat03(i,j) := mat03(i,j);

%spsvd03 := spsvd(spmat03);

%compare_sparse(spsvd02,svd02);


mat04 := mat((3,4),(0,5));

svd04 := svd(mat04);

first(svd04)*second(svd04)*tp third(svd04);
ws-mat04;

sparse spmat04(2,2);
for i:=1:first length mat04 do
   for j:=1:second length mat04 do
      if mat04(i,j) neq 0 then spmat04(i,j) := mat04(i,j);

%spsvd04 := spsvd(spmat04);

%compare_sparse(spsvd02,svd02);


mat05 := mat((1,0,-1),(0,1,0));

svd05 := svd(mat05);

first(svd05)*second(svd05)*tp third(svd05);
ws-mat05;

sparse spmat05(2,3);
for i:=1:first length mat05 do
   for j:=1:second length mat05 do
      if mat05(i,j) neq 0 then spmat05(i,j) := mat05(i,j);

%spsvd05 := spsvd(spmat05);

%compare_sparse(spsvd02,svd02);


mat06 := mat((3,0),(4,5));

svd06 := svd(mat06);

first(svd06)*second(svd06)*tp third(svd06);
ws-mat06;

sparse spmat06(2,2);
for i:=1:first length mat06 do
   for j:=1:second length mat06 do
      if mat06(i,j) neq 0 then spmat06(i,j) := mat06(i,j);

%spsvd06 := spsvd(spmat06);

%compare_sparse(spsvd02,svd02);


mat07 := mat((0,1,0,0),(0,0,2,0),(0,0,0,3),(0,0,0,0));

svd07 := svd(mat07);

first(svd07)*second(svd07)*tp third(svd07);
ws-mat07;

sparse spmat07(4,4);
for i:=1:first length mat07 do
   for j:=1:second length mat07 do
      if mat07(i,j) neq 0 then spmat07(i,j) := mat07(i,j);

%spsvd07 := spsvd(spmat07);

%compare_sparse(spsvd02,svd02);


mat08 := mat((0,1,0,0),(0,0,2,0),(0,0,0,3),(1/60000,0,0,0));

svd08 := svd(mat08);

first(svd08)*second(svd08)*tp third(svd08);
ws-mat08;

sparse spmat08(4,4);
for i:=1:first length mat08 do
   for j:=1:second length mat08 do
      if mat08(i,j) neq 0 then spmat08(i,j) := mat08(i,j);

%spsvd08 := spsvd(spmat08);

%compare_sparse(spsvd02,svd02);


mat09 := mat((1,0,0,0,2),
   (0,0,3,0,0),
   (0,0,0,0,0),
   (0,4,0,0,0));

svd09 := svd(mat09);

first(svd09)*second(svd09)*tp third(svd09);
ws-mat09;

sparse spmat09(4,5);
for i:=1:first length mat09 do
   for j:=1:second length mat09 do
      if mat09(i,j) neq 0 then spmat09(i,j) := mat09(i,j);

%spsvd09 := spsvd(spmat09);

%compare_sparse(spsvd02,svd02);


end;

