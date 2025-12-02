def Sinpi(x):
   R = x.parent()
   p = x.prec()
   X = x.exact_rational()
   return R(numerical_approx(sin(pi*X),2*p+100))

def Cospi(x):
   R = x.parent()
   p = x.prec()
   X = x.exact_rational()
   return R(numerical_approx(cos(pi*X),2*p+100))

def Tanpi(x):
   R = x.parent()
   p = x.prec()
   X = x.exact_rational()
   return R(numerical_approx(tan(pi*X),2*p+100))

def tableS1(out):
   f = open(out,"w")
   f.write ("static const float S1[] = {\n")
   s = ""
   for i1 in range(240):
      u1 = 118*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = Sinpi(x1)
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
   for i1 in range(240):
      u1 = 118*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = Cospi(x1)
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
   for i2 in range(120):
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-16)*l)
      y2 = Sinpi(x2)
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
   for i2 in range(120):
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-16)*l)
      y2 = Cospi(x2)
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
