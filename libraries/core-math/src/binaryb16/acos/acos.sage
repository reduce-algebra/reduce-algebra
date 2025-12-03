# determine the range for which o(acos(x)) = o(0x1.921fb6p+0)
# check_small()
# '0x1.fcp-12'
def check_small():
   x = R8(2^-133)
   while true:
      for r in 'NZUD':
         R = RealField(8,rnd='RND'+r)
         y = acos(R(x))
         z = R("0x1.921fb6p+0",16)
         if y!=z:
            return get_hex(x)
         y = acos(R(-x))
         z = R("0x1.921fb6p+0",16)
         if y!=z:
            return get_hex(x)
      if x<2^-126:
         x = x+2^-133
      else:
         x = x.nextabove()
