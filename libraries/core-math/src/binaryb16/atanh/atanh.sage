# generate table for 0.5 <= |x| <= 1
def table1(out):
   f = open(out,"w")
   f.write ("static const float T1[] = {\n")
   s = ""
   for i in range(2^7):
      x = R24(1/2+i/2^8)
      y = atanh(x)
      t = " " + get_hex(y) + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
