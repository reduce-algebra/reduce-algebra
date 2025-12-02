def table1(out):
   f = open(out,"w")
   f.write ("static const b32u32_u T1[] = {\n")
   s = ""
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf
         if i1==2^10+(e<<5): # -Inf
            v1 = 0
         else:
            v1 = ((u1>>31)<<31) | ((224+e)<<23) | ((u1 % (2^10)) << 13)
         v = "{.u = " + hex(v1) + "}"
      else:
         x1 = R24(asfloat16(u1))
         y1 = exp(x1)
         if y1>=2^128.:
            y1 = R24(2^128).nextbelow()
         if y1<2^-149.:
            y1 = R24(2^-149)
         v = "{" + get_hex(y1) + "}"
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
   f.write ("static const b32u32_u T2[] = {\n")
   s = ""
   for i2 in range(2^11):
      h = i2 // (2^5)
      l = i2 % (2^5)
      u2 = h*2^10+l
      e = h % (2^5)
      if e==31: # NaN or Inf
         if i2==2^10+(e<<5): # -Inf
            v2 = 0
         else:
            v2 = ((u2>>31)<<31) | ((224+e)<<23) | ((u2 % (2^10)) << 13)
         v = "{.u = " + hex(v2) + "}"
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = exp(x2)
         # fix manually some values
         if i2 in [159,190,249,303,493]:
            y2 = y2.nextbelow()
         if y2>=2^128.:
            y2 = R24(2^128).nextbelow()
         if y2<2^-149.:
            y2 = R24(2^-149)
         v = "{" + get_hex(y2) + "}"
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
      
