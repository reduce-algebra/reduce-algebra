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

first(svda) * second(svda) * tp(third(svda));

spmata := mata$ transmat spmata;
spmatb := matb$ transmat spmatb;
spmatc := matc$ transmat spmatc;

spsvda := spsvd(spmata);
spsvdb := spsvd(spmatb);
spsvdc := spsvd(spmatc);

first(spsvda) * second(spsvda) * tp(third(spsvda));
first(spsvdb) * second(spsvdb) * tp(third(spsvdb));
first(spsvdc) * second(spsvdc) * tp(third(spsvdc));

det(mata) - det(spmata);
det(matb) - det(spmatb);
det(matc) - det(spmatc);

mat01 := mat((12,1,0,0,0),
   (1,9,1,0,0),
   (0,1,6,1,0),
   (0,0,1,3,1),
   (0,0,0,1,0));

svd01 := svd(mat01);

first(svd01)*second(svd01)*tp third(svd01);
ws-mat01;

spmat01 := mat01$ transmat spmat01;

spsvd01 := spsvd(spmat01);

first(spsvd01)*second(spsvd01)*tp third(spsvd01);
ws-spmat01;

compare_sparse(spsvd01,svd01);

det(mat01) - det(spmat01);


mat02 := mat((3,2,2),(2,3,-2));

svd02 := svd(mat02);

first(svd02)*second(svd02)*tp third(svd02);
ws-mat02;

spmat02 := mat02$ transmat spmat02;

spsvd02 := spsvd(spmat02);

compare_sparse(spsvd02,svd02);


mat03 := mat((-3,1),(6,-2),(6,-2));

svd03 := svd(mat03);

first(svd03)*second(svd03)*tp third(svd03);
ws-mat03;

spmat03 := mat03$ transmat spmat03;

spsvd03 := spsvd(spmat03);

compare_sparse(spsvd02,svd02);


mat04 := mat((3,4),(0,5));

svd04 := svd(mat04);

first(svd04)*second(svd04)*tp third(svd04);
ws-mat04;

spmat04 := mat04$ transmat spmat04;

spsvd04 := spsvd(spmat04);

compare_sparse(spsvd02,svd02);

det(mat04) - det(spmat04);


mat05 := mat((1,0,-1),(0,1,0));

svd05 := svd(mat05);

first(svd05)*second(svd05)*tp third(svd05);
ws-mat05;

spmat05 := mat05$ transmat spmat05;

spsvd05 := spsvd(spmat05);

compare_sparse(spsvd02,svd02);


mat06 := mat((3,0),(4,5));

svd06 := svd(mat06);

first(svd06)*second(svd06)*tp third(svd06);
ws-mat06;

spmat06 := mat06$ transmat spmat06;

spsvd06 := spsvd(spmat06);

compare_sparse(spsvd02,svd02);

det(mat06) - det(spmat06);


mat07 := mat((0,1,0,0),(0,0,2,0),(0,0,0,3),(0,0,0,0));

svd07 := svd(mat07);

first(svd07)*second(svd07)*tp third(svd07);
ws-mat07;

spmat07 := mat07$ transmat spmat07;

spsvd07 := spsvd(spmat07);

compare_sparse(spsvd02,svd02);

det(mat07) - det(spmat07);


mat08 := mat((0,1,0,0),(0,0,2,0),(0,0,0,3),(1/60000,0,0,0));

svd08 := svd(mat08);

first(svd08)*second(svd08)*tp third(svd08);
ws-mat08;

spmat08 := mat08$ transmat spmat08;

spsvd08 := spsvd(spmat08);

compare_sparse(spsvd02,svd02);

det(mat08) - det(spmat08);


mat09 := mat((1,0,0,0,2),
   (0,0,3,0,0),
   (0,0,0,0,0),
   (0,4,0,0,0));

svd09 := svd(mat09);

first(svd09)*second(svd09)*tp third(svd09);
ws-mat09;

spmat09 := mat09$ transmat spmat09;

spsvd09 := spsvd(spmat09);

compare_sparse(spsvd02,svd02);


end;

