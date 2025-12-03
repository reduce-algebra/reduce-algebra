# check 1+x is always representable as float
def check():
   x = R11(0)
   count = 0
   while x<2^16:
      count += 1
      check_aux(x)
      check_aux(-x)
      if x<2^-14:
         x = x+R11(2^-24)
      else:
         x = x.nextabove()
   return count

def check_aux(x):
   X = x.exact_rational()
   y = R24(1)+R24(x)
   if y.exact_rational() != 1+X:
      print ("fail", get_hex(x))

# R approximates 1/x
def table1(out):
   f = open(out,"w")
   f.write ("static const float R[][2] = {\n")
   maxd = 0
   s = ""
   T = []
   for i in range(32,2^8):
      prec = 24
      while true:
         R = RealField(prec)
         u = i<<7
         x1 = R(asfloat16(u))
         x2 = R(asfloat16(u+2^7-1))
         assert x1.ulp()==x2.ulp(), "x1.ulp()==x2.ulp()"
         r1 = 1/x1
         r2 = 1/x2
         if r2.ulp()*x2.ulp()>=2^-28:
            break
         prec = prec-1
      bestr = r2
      bestd = max(abs(fma(r2,x1,R(-1))),abs(fma(r2,x2,R(-1))))
      r = r2
      while r<=r1:
         d = max(abs(fma(r,x1,R(-1))),abs(fma(r,x2,R(-1))))
         if d<bestd:
            bestr = r
            bestd = d
         r = r.nextabove()
      if bestd>maxd:
         print (i, get_hex(bestr), get_hex(bestd))
         maxd = bestd
      l = -log(R24(bestr))
      # optimize manually some values
      if i-32 in [166,203]:
         l = l.nextbelow()
      if i-32 in [88]:
         l += 4*l.ulp()
      t = " {" + get_hex(bestr) + "," + get_hex(l) + "},"
      T.append([bestr,l])
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t      
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   print ("maxd=", get_hex(maxd)) # 0x1.de58p-5
   return T

def geti(x):
   v = R24(x)+1
   u = asuint(v)>>20
   return u-928

def log1p_small(x):
   R = x.parent()
   c3 = fma(x,R("-0x1p-2",16),R("0x1.555556p-2",16))
   c2 = fma(x,c3,R("-0.5"))
   return fma(x,x*c2,x)

def check_x(x,i,r,logr):
   assert abs(x)>=2^-5, "abs(x)>=2^-5"
   for rnd in 'NZUD':
      R11 = RealField(11,rnd='RND'+rnd)
      R24 = RealField(24,rnd='RND'+rnd)
      v = R24(x)+1
      u = asuint(v)>>20
      assert u-928==i, "u-928==i"
      z = fma(R24(r),v,R24(-1))
      l = log1p_small(z)
      z24 = R24(logr) + l
      z = R11(z24)
      X = x.exact_rational()
      y = R11(n(log(1+X),100))
      if y!=z:
         print ("FAIL", r, get_hex(x), get_hex(y), get_hex(z24), get_hex(z))

# print all inputs giving i
# checki(88,r=R24("0x1.e218p-1",16),logr=R24("0x1.ed0b48p-5",16))
def checki(i,r=None,logr=None):
   T = table1("/tmp/R.h")
   u = (i+928)<<20
   v = asfloat(u)
   v = v-1
   x0 = R11(v)
   if x0<2^-5:
      x0 = R11(2^-5)
   while geti(x0)<i:
      x0 = x0.nextabove()
   x = x0
   if r==None:
      r = T[i][0]
   if logr==None:
      logr = T[i][1]
   print ("Using r=", get_hex(r), "logr=", get_hex(logr))
   while geti(x)==i:
      check_x(x,i,r,logr)
      x = x.nextabove()
   return get_hex(x0), get_hex(x)
