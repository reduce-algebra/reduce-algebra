module xvect; % Support for vectors with adaptive length.

% Author: Herbert Melenk, ZIB-Berlin.

% Note: CSL version uses 1024, PSL 128.

symbolic procedure mkxvect(); {mkvect(1024)};

symbolic procedure xputv(v,n,w);
  begin scalar i,j;
    i:=iquotient(n,1024); j:=iremainder(n,1024);
    while(i>0) do
    <<if null cdr v then cdr v:= mkxvect();
      v:=cdr v; i:=i #- 1>>;
    iputv(car v,j,w);
    return w;
  end;

symbolic procedure xgetv(v,n);
  begin scalar i,j,w;
    i:=iquotient(n,1024); j:=iremainder(n,1024);
    while(i>0 and v) do
    <<v:=cdr v; i:=i #- 1>>;
    w:=if v then igetv(car v,j);
    return w
  end;

endmodule;

end;
