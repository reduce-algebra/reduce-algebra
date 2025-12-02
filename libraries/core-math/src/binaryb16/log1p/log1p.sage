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

def Log1p(x):
   R = x.parent()
   X = x.exact_rational()
   return R(n(log(1+X),200))

# determine the range for which log1p(x) rounds to the same value as log(x)
# check_large()
# 0x1.5ep+11
def check_large():
   x = R8(2^128).nextbelow()
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         if log(R(x))!=Log1p(R(x)):
            return get_hex(x)
      x = x.nextbelow()

# determine the range for which log1p(x) rounds to the same value as R8(fma(x,-x/2,x))
# where x is cast in float in the fma
# check_small()
# '0x1.6ap-8'
def check_small():
   x = u = R8(2^-133)
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         R24 = RealField(24,rnd='RND'+r)
         y = R24(x)
         if Log1p(R(x))!=R(fma(y,-y/2,y)):
            return get_hex(x)
         # also try with -x
         y = R24(-x)
         if Log1p(R(-x))!=R(fma(y,-y/2,y)):
            return get_hex(x)
      if x.ulp()<u:
         x = x+u
      else:
         x = x.nextabove()
