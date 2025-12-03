# for 0 <= i < 2^6, T1[i] approximates log(1+i/2^6)
def table1(out):
   f = open(out,"w")
   f.write ("static const float T1[] = {\n")
   s = ""
   for i in range(2^6):
      x = R24(1+i/2^6)
      y = log(x)
      v = get_hex(y)
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

# for 0 <= i < 2^6, T2[i] approximates 1/(1+i/2^6)
def table2(out):
   f = open(out,"w")
   f.write ("static const float T2[] = {\n")
   s = ""
   for i in range(2^6):
      x = 1+i/2^6
      y = R24(1/x)
      v = get_hex(y)
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
