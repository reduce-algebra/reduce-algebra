R8=RealField(8)

def asbfloat16(n):
   assert n in ZZ and 0 <= n < 2^16, "n in ZZ and 0 <= n < 2^16"
   if n >= 2^15:
      s = -1
      n -= 2^15
   else:
      s = 1
   # now n < 2^15
   e = n >> 7
   if e==0: # subnormal number
      return R8(s*n*2^-133)
   n = 2^7 + (n % (2^7))
   return R8(s*n*2^(e-127-7))

# list exact/midpoint cases, except for x=0 and y=0
# l=exact()
# l=[(x,y) for x,y in l if x!=0 and y!=0]
# get_hex(min(abs(x) for x,y in l))
# '0x1p-8'
# get_hex(max(abs(x) for x,y in l))
# '0x1.fep+17'
def exact():
   l = []
   R9 = RealField(9)
   # (b) y integer, 1 <= y <= 5 (because 3^6 has 10 bits)
   for y in [1..5]:
      for v in [1..0x7f7f]:
         x = asbfloat16(v)
         X = x.exact_rational()
         Z = (1+X)^y
         if R9(Z).exact_rational()==Z:
            l.append((x,R8(y)))
   # (c) y<0: x=0 or (1+x=2^e and |y|=n*2^-k with 2^k dividing e) with 1 <= e <= 8
   for e in [1..8]:
      X = 2^e-1
      k = 0
      while e % (2^k) == 0:
         n = 1
         while true:
            y = -n*2^-k
            Z = (1+X)^y
            if R8(y).exact_rational()==y and R9(Z).exact_rational()==Z:
               l.append((R8(X),R8(y)))
               n += 1
            else:
               break
         k += 1
   # (d) y>0: y=n*2^f with -3 <= f <= -1 and 1 <= n <= 5
   for v in [0..0x7f7f]:
      x = asbfloat16(v)
      X = x.exact_rational()
      if not sqrt(1+X) in QQ:
         continue
      for f in [-3..-1]:
         for n in [1..5]:
            y = n*2^f
            Z = (1+X)^y
            if R9(Z).exact_rational()==Z:
               l.append((R8(x),R8(y)))
   return l
