# return true of 1+x is exact as a float
def is_exact(x):
   x = R24(x)
   y = x+R24(1)
   return x.exact_rational()+1==y.exact_rational()

# determine the range where 1+x is exact for x >= -1
# range_exact()
# ('0x1.fep-17', '0x1p+24')
# range_exact(start=-1/2)
('-0x1.02p+24', '-0x1.fep-18')
def range_exact(start=1):
   x = R8(start)
   u = R8(2^-133)
   while true:
      if not is_exact(x):
         break
      if x.ulp()>=u:
         x = x.nextbelow()
      else:
         x = x-R8(2^-133)
   xmin = x
   x = R8(start)
   while true:
      if not is_exact(x):
         break
      x = x.nextabove()
   xmax = x
   return get_hex(xmin), get_hex(xmax)

def Log2p1(x):
   R = x.parent()
   X = x.exact_rational()
   return R(n(log(1+X)/log(2),200))

def Log2(x):
   R = x.parent()
   X = x.exact_rational()
   return R(n(log(X)/log(2),200))

# determine the range for which log2p1(x) rounds to the same value as log2(x)
# check_large() (unless x a power of two)
# '0x1.6ap+12'
def check_large():
   x = R8(2^128).nextbelow()
   while true:
      for r in 'NZUD':
         _, m, _ = x.sign_mantissa_exponent()
         if m == 128:
            continue
         R = RealField(8,rnd='RND'+r)
         if Log2(R(x))!=Log2p1(R(x)):
            return get_hex(x)
      x = x.nextbelow()

# determine the range for which log2p1(x) rounds to the same value as
# R8(log2p1_tiny(R24(x)))
# check_tiny()
# 0x1.86p-7
def check_tiny():
   x = u = R8(2^-133)
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         R24 = RealField(24,rnd='RND'+r)
         if Log2p1(R(x))!=R(log2p1_tiny(R24(x))):
            return get_hex(x)
         # also try with -x
         if Log2p1(R(-x))!=R(log2p1_tiny(R24(-x))):
            return get_hex(x)
      if x.ulp()<u:
         x = x+u
      else:
         x = x.nextabove()

def log2p1_tiny(x):
   R = x.parent()
   INVLOG2 = R("0x1.715476p+0",16)
   t = x*INVLOG2
   return fma(t,-x*R(1/2),t)

def log2p1_small(x):
   R = x.parent()
   INVLOG2 = R("0x1.715476p+0",16)
   ONE_THIRD = R("0x1.555556p-2",16)
   t = x*INVLOG2
   c2 = fma(x,ONE_THIRD,R(1/2))
   return fma(t,-x*c2,t)

# check all bf16 numbers in [x1,x2) such that
# fma(r,x,-1) is exact in binary32
def check(x1,x2,r,verbose=false):
   x = R8(x1)
   while x<x2:
      z = fma(R24(r),R24(x),R24(-1))
      Z = r.exact_rational()*x.exact_rational()-1
      if z.exact_rational()!=Z:
         if verbose:
            print (get_hex(x))
         return false
      x = x.nextabove()
   return true

def table0(out):
   f = open(out,"w")
   f.write ("static const float R0[] = {\n")
   s = ""
   for i in [119..139]:
      u = i<<23
      x = asfloat(u) # power of 2
      r = 1/x
      l = -Log2(R24(r))
      t = get_hex(l) + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()

# R approximates 1/x
def table1(out):
   f = open(out,"w")
   f.write ("static const float R[][2] = {\n")
   s = ""
   T = []
   maxd = 0
   for i in range(2^6):
      x1 = R24(1+i/2^6)
      x2 = R24(1+(i+1)/2^6).nextbelow()
      r1 = 1/x1
      r2 = 1/x2
      prec = 12
      while true:
         R = RealField(prec)
         bestd = infinity
         r = R(r2)
         while r<=R(r1):
            d = max(abs(fma(R24(r),x1,R24(-1))),abs(fma(R24(r),x2,R24(-1))))
            if d<bestd and check(x1,x2,r):
               bestd = d
               bestr = r
            r = r.nextabove()
         if bestd < infinity:
            break
         prec = prec-1
      print (i, prec, d)
      maxd = max(maxd,d)
      l = -Log2(R24(bestr))
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
   print ("maxd=", maxd)
   return T

# determine largest x for which log10p1_tiny
# generates a spurious underflows
# check_underflow()
# 0x1.84p-63
def check_underflow():
   u = R8(2^-133)
   x = u
   R = RealField(24)
   INVLOG2 = R("0x1.715476p+0",16)
   while true:
      underflow = false
      t = R(x)*INVLOG2
      if abs(t)<2^-126:
         underflow = true
      v = -R(x) * t
      if abs(v)<2^-126:
         underflow = true
      res = fma(t,v,t)
      spurious = underflow and abs(t)>=2^-126
      if spurious:
         print (get_hex(x))
      if not underflow:
         break
      if x.ulp()<u:
         x = x+u
      else:
         x = x.nextabove()
