def table1(out):
   f = open(out,"w")
   f.write ("static const float T1[] = {\n")
   s = ""
   for i1 in range(2^9):
      sgn, j1 = divmod(i1, 2^8)
      u1 = 118*2^7+j1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = exp2((-1)^sgn*x1)
      if y1>=2^128: # values larger than MAX_FLT are capped to MAX_FLT
         y1 = R24(2^128).nextbelow()
      v = get_hex(y1)
      t = " " + v + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()

def table2(out):
   f = open(out,"w")
   f.write ("static const float T2[] = {\n")
   s = ""
   for i2 in range(2^8):
      sgn, j2 = divmod(i2, 2^7)
      h,l = divmod(j2,2^3)
      x2 = R24(2^(h-16)*l)
      y2 = exp2((-1)^sgn*x2)
      v = get_hex(y2)
      t = " " + v + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
      
