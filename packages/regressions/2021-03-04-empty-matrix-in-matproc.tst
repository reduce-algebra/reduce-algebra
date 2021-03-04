comment Problem reported by Fausto Saporito on reduce-algebra-developers
        mailing list:
        If a matproc returns nil, the printing routines try to take car of nil;

procedure w(n);
  exp(2*pi*i/n);

matrixproc qft(n);
  begin matrix qf(n,n);
  for i:=1:(n-1) do
    for j:=1:(n-1) do
      <<qf(i+1,j+1):=w(n)^(i*j)>>;
  for i:=1:n do
    <<qf(1,i):=1; qf(i,1):=1>>;
  qf;
  end;

qft(2);

end;

