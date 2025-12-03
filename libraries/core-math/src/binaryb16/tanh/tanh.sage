def tableS1(out):
   f = open(out,"w")
   f.write ("static const float S1[] = {\n")
   s = ""
   for i1 in [0..91]:
      u1 = 123*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = sinh(x1)
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

def tableC1(out):
   f = open(out,"w")
   f.write ("static const float C1[] = {\n")
   s = ""
   for i1 in [0..91]:
      u1 = 123*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = cosh(x1)
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

def tableS2(out):
   f = open(out,"w")
   f.write ("static const float S2[] = {\n")
   s = ""
   for i2 in [0..47]:
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-11)*l)
      y2 = sinh(x2)
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

def tableC2(out):
   f = open(out,"w")
   f.write ("static const float C2[] = {\n")
   s = ""
   for i2 in [0..47]:
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-11)*l)
      y2 = cosh(x2)
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
