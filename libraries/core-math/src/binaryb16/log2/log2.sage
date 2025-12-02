def Log2(x):
   assert x in R24
   X = x.exact_rational()
   return R24(n(log(X)/log(2),100))

# let x = x1*x2 where x1 is the exponent part, and x2 the significant part
# this routine computes the table T1 which corresponds to x1
def table1(out):
   f = open(out,"w")
   f.write ("static const float T1[] = {\n")
   s = ""
   for i1 in range(2^8): # we only deal with positive numbers
      u = i1<<7
      e = i1
      if e in [0,255]:  # these cases will be treated by another table
         v = "0" # this case will be treated by another table
      else:
         x1 = R24(asbfloat16(u))
         y1 = Log2(x1)
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

# let x = x1*x2 where x1 is the exponent part, and x2 the significant part
# this routine computes the table T2 which corresponds to x2
def table2(out):
   f = open(out,"w")
   f.write ("static const float T2[] = {\n")
   s = ""
   for i2 in range(2^7):
      u = 0x3f80 + i2 # 0x3f80 encodes 1
      x = asbfloat16(u)
      x2 = R24(x)
      y2 = Log2(x2)
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

# this routine computes the table T3 for subnormal numbers
def table3(out):
   f = open(out,"w")
   f.write ("static const b32u32_u T3[] = {\n")
   s = ""
   for u in range(2^7):
      x3 = R24(asbfloat16(u))
      if x3 == 0:
         v = 0xff800000 # -Inf
         v = "{.u = " + hex(v) + "}"
      else:
         y3 = Log2(x3)
         v = "{" + get_hex(y3) + "}"
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
