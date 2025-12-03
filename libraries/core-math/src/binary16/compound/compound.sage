# list exact/midpoint cases, except for x=0 and y=0
# l=exact()
# l=[(x,y) for x,y in l if x!=0 and y!=0]
# get_hex(min(abs(x) for x,y in l))
# '0x1p-11'
# get_hex(max(abs(x) for x,y in l))
# '0x1.fcp+15'
def exact():
   l = []
   R11 = RealField(11) # exact
   R12 = RealField(12) # midpoint
   # (b) y integer, 1 <= y <= 7
   for y in [1..7]:
      for v in [1..0x7bff]:
         x = asfloat16(v)
         X = x.exact_rational()
         Z = (1+X)^y
         if R12(Z).exact_rational()==Z:
            l.append((x,R11(y)))
   # (c) y<0: x=0 or (1+x=2^e and |y|=n*2^-k with 2^k dividing e) with 1 <= e <= 8
   for e in [1..11]:
      X = 2^e-1
      k = 0
      while e % (2^k) == 0:
         n = 1
         while true:
            y = -n*2^-k
            Z = (1+X)^y
            # (1+x)^y = 2^(n*e/2^k)
            ez = n*e/2^k
            if R11(y).exact_rational()==y and R12(Z).exact_rational()==Z and -24 <= ez <= 15:
               l.append((R11(X),R11(y)))
               n += 1
            else:
               break
         k += 1
   # (d) y>0: y=n*2^f with -3 <= f <= -1 and 1 <= n <= 7
   for v in [0..0x7bff]:
      x = asfloat16(v)
      X = x.exact_rational()
      if not sqrt(1+X) in QQ:
         continue
      for f in [-3..-1]:
         for n in [1..7]:
            y = n*2^f
            Z = (1+X)^y
            if R12(Z).exact_rational()==Z:
               l.append((R11(x),R11(y)))
   return l
