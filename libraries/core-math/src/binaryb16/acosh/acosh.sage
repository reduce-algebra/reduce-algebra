# check when acosh(x) rounds to the same value as log(x) + 0x1.62e43p-1
def check_large():
   x = R8(2^128)
   while true:
      x = x.nextbelow()
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         R24 = RealField(24,rnd='RND'+r)
         y = acosh(R(x))
         z = R(log(R24(x)) + R24("0x1.62e43p-1",16))
         if y!=z:
            return x

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
