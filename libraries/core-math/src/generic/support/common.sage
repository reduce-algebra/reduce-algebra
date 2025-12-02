# SAGE file defining some common functions used elsewhere

# print like in C: 0x1.xxxp+e
# x must be a floating-point number
# get_hex(RR(pi))
# '0x1.921fb54442d18p+1'
def get_hex(x):
   if x < 0:
      return '-' + get_hex(-x)
   s = x.hex()
   if s[2] in ['0','1']:
      e = 0
   elif s[2] in ['2','3']:
      s = (x/2).hex()
      e = 1
   elif s[2] in ['4','5','6','7']:
      s = (x/4).hex()
      e = 2
   else:
      s = (x/8).hex()
      e = 3
   # add e to exponent
   s = s.split('p')
   e = ZZ(s[1])+e
   if e >= 0:
      s[1] = '+' + e.str()
   else:
      s[1] = e.str()
   return s[0] + 'p' + s[1]

# given x a binary64 number (from RR), returns its 64-bit encoding
# hex(asuint64(RR(pi)))
# '0x400921fb54442d18'
# FIXME: should also deal with RR("+Inf"), RR("-Inf"), and RR("NaN")
def asuint64(x):
   assert x in RR
   s,m,e = x.sign_mantissa_exponent()
   if s==1:
      s=0
   else:
      s=1
   if abs(x) >= 2^-1022: # normal number
      m = m-2^52 # remove implicit bit
      e = e+1023+52
      return s*2^63+e*2^52+m
   # now deal with subnormal number
   m = abs(x).exact_rational()/2^-1074
   assert m in ZZ and m < 2^52
   return s*2^63+m

# given n a 64-bit integer, return the corresponding binary64 number
# asfloat64(0x400921fb54442d18)
# 3.14159265358979
def asfloat64(n):
   assert n in ZZ and 0 <= n < 2^64
   if n >= 2^63:
      s = -1
      n -= 2^63
   else:
      s = 1
   # now n < 2^63
   e = n >> 52
   if e==0: # subnormal number
      return s*RR(n*2^-1074)
   e = e-1023
   n = 2^52 + (n % (2^52))
   return RR(s*n*2^(e-52))

R24 = RealField(24)

# same as asuint64, but for binary32 numbers
def asuint32(x):
   assert x in R24
   s,m,e = x.sign_mantissa_exponent()
   if s==1:
      s=0
   else:
      s=1
   if abs(x) >= 2^-126: # normal number
      m = m-2^23 # remove implicit bit
      e = e+127+23
      return s*2^31+e*2^23+m
   # now deal with subnormal number
   m = abs(x).exact_rational()/2^-149
   assert m in ZZ and m < 2^23
   return s*2^31+m

# same as asfloat64, but for binary32 numbers
def asfloat32(n):
   assert n in ZZ and 0 <= n < 2^32
   if n >= 2^31:
      s = -1
      n -= 2^31
   else:
      s = 1
   # now n < 2^31
   e = n >> 23
   if e==0: # subnormal number
      return R24(s*n*2^-149)
   e = e-127
   n = 2^23 + (n % (2^23))
   return R24(s*n*2^(e-23))

def fma(x,y,z):
   R = x.parent()
   assert y.parent() == R, "y.parent() == R"
   assert z.parent() == R, "z.parent() == R"
   return R(x.exact_rational()*y.exact_rational()+z.exact_rational())

exp2 = lambda x: 2^x
exp10 = lambda x: 10^x   
expm1 = lambda x: exp(x)-1
exp2m1 = lambda x: 2^x-1
exp10m1 = lambda x: 10^x-1
log10 = lambda x: log(x)/log(10)
log2 = lambda x: log(x)/log(2)
log1p = lambda x: log(1+x)
log2p1 = lambda x: log(1+x)/log(2)
log10p1 = lambda x: log(1+x)/log(10)
sinpi = lambda x: sin(pi*x)
cospi = lambda x: cos(pi*x)
tanpi = lambda x: tan(pi*x)
asinpi = lambda x: asin(x)/pi
acospi = lambda x: acos(x)/pi
atanpi = lambda x: atan(x)/pi
