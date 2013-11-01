% Information Flow Control

rlset z;

sec := (a < b and cong(a+b,0,2) and 2*n = a+b and
      (a < b and b-a = n or a >= b and a-b = n)) or
   (a < b and ncong(a+b,0,2) and 2*n = a+b+1 and
      (a < b and b-a = n or a >= b and a-b = n))$

rlqe rlex sec;

end;
