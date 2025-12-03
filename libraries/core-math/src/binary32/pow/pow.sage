#load("../../generic/support/common.sage")
# generate exact cases with y < 0
def check_exact(file=None):
   emin = -149
   emax = 127
   nsols = 0
   if file!=None:
      file = open(file,"w")
   for k in [1..10]:
      tmin = ceil(emin/2^k)
      tmax = floor(emax/2^k)
      for t in [tmin..tmax]:
         if t==0:
            continue # case x = 1
         e = t*2^k
         x = RR(2^e)
         y0 = RR(-2^-k)
         # x^y0 = 2^(-e*2^-k) = 2^(-t)
         # if y=n*y0, x^y = 2^(-n*t)
         if t<0:
            nmin = ceil(emin/-t)
            nmax = floor(emax/-t)
         else:
            nmin = ceil(emax/-t)
            nmax = floor(emin/-t)
         # we want y < 0
         nmin = max(1,nmin)
         for n in [nmin..nmax]:
            y = n*y0
            if file==None:
               print (get_hex(x), get_hex(y))
            else:
               file.write(get_hex(x) + "," + get_hex(y) + "\n")
            nsols += 1
   if file!=None:
      file.close()
   return nsols

def output(x,y,f):
   if f==None:
      print (get_hex(x)+","+get_hex(y))
   else:
      f.write (get_hex(x)+","+get_hex(y)+"\n")

# search K inputs x,y such that x^y rounds to 2^-126 for RNDU
# but there is underflow
def corner_rndu(f=None):
   if f!=None:
      f = open(f,"w")
   Ru = RealField(24,rnd='RNDU')
   Rd = RealField(24,rnd='RNDD')
   threshold1 = 2^-126-2^-149 # nextbelow(2^-126) in binary32
   threshold2 = 2^-126-2^-150 # nextbelow(2^-126) with unbounded exponent
   # for threshold1 < x^y <= threshold2, x^y rounds upwards to threshold2
   # with unbounded exponent range, but to 2^-126 in binary32
   x = Ru(1/2)
   count = ok = 0
   while x<1:
      X = x.exact_rational()
      # we want x^y below threshold2
      y = Ru(n(log(threshold2)/log(X),200))
      Y = y.exact_rational()
      z = n(X^Y,100)
      # assert z<=threshold2, "z<=threshold2"
      count += 1
      if threshold1 < z:
         ok += 1
         output(x,y,f)
         output(x,y.nextbelow(),f)
      x = x.nextabove()
      if count % 10000 == 0:
         print (count, ok, get_hex(x))
   if f!=None:
      f.close()

# search K inputs x,y such that x^y rounds to 2^-126 for RNDN
# but there is underflow
def corner_rndu(f=None):
   if f!=None:
      f = open(f,"w")
   Ru = RealField(24,rnd='RNDU')
   Rd = RealField(24,rnd='RNDD')
   threshold1 = 2^-126-2^-150-2^-151
   threshold2 = 2^-126-2^-150+2^-151
   # for threshold1 < x^y < threshold2, x^y rounds to nearest to 2^-126-2^-150
   # with unbounded exponent range, but to 2^-126 in binary32
   x = Ru(1/2)
   count = ok = 0
   while x<1:
      X = x.exact_rational()
      # we want x^y below threshold2
      y = Ru(n(log(threshold2)/log(X),200))
      Y = y.exact_rational()
      z = n(X^Y,100)
      # assert z<=threshold2, "z<=threshold2"
      count += 1
      if threshold1 < z:
         ok += 1
         output(x,y,f)
         output(x,y.nextbelow(),f)
      x = x.nextabove()
      if count % 10000 == 0:
         print (count, ok, get_hex(x))
   if f!=None:
      f.close()
