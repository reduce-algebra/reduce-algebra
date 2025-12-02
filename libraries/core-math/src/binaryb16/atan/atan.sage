# determine the range for which o(atan(x)) = o(0x1.921fb6p+0)
# check_large()
# 0x1.02p+11
def check_large():
   x = R8(2^128).nextbelow()
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         y = atan(R(x))
         z = R("0x1.921fb6p+0",16)
         if y!=z:
            return get_hex(x)
         y = atan(R(-x))
         z = R("-0x1.921fb6p+0",16)
         if y!=z:
            return get_hex(x)
      x = x.nextbelow()
