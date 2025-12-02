def Atanpi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(atan(X)/pi,200))

# determine the range for which o(atanpi(x)) = o(nextbelow(0.5))
# check_large()
# 0x1.44p+8
def check_large():
   x = R8(2^128).nextbelow()
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         y = Atanpi(R(x))
         z = R("0x1.fffffep-2",16)
         if y!=z:
            return get_hex(x)
         y = Atanpi(R(-x))
         z = R("-0x1.fffffep-2",16)
         if y!=z:
            return get_hex(x)
      x = x.nextbelow()

# determine the range for which o(atanpi(x)) = o(x*INV_PI)
# check_small()
# 0x1.6ep-7
def check_small():
   x = R8(2^-126)
   INV_PI = RR("0x1.45f306p-2",16)
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         R24 = RealField(24,rnd='RND'+r)
         y = Atanpi(R(x))
         z = R(R24(x)*R24(INV_PI))
         if y!=z:
            return get_hex(x)
         y = Atanpi(R(-x))
         z = R(R24(-x)*R24(INV_PI))
         if y!=z:
            return get_hex(x)
      x = x.nextabove()
