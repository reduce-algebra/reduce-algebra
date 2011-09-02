module parray; % multidimensional arrays.

symbolic procedure mk!-p!-array3(nx,ny,nz);
  <<for i:=0:nx do iputv(w,i,mk!-p!-array2(ny,nz)); w>>
       where w=mkvect(nx#+1);

symbolic procedure mk!-p!-array2(ny,nz);
  <<for i:=0:ny do iputv(w,i,mkvect(nz#+1)); w>>
       where w=mkvect(ny#+1);

symbolic procedure p!-get3(v,i,j,k);
  igetv(igetv(igetv(v,i),j),k);

symbolic procedure p!-put3(v,i,j,k,w);
  iputv(igetv(igetv(v,i),j),k,w);

endmodule;

end;
