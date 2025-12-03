def Asinpi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(asin(X)/pi,100))

def Failures(x0,x1,l,poly,verbose=true,use_sqrt=false):
   assert poly in ['p0','p1'], "poly in ['p0','p1']"
   failures = []
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      INV_PI = R24("0x1.45f306p-2",16)
      p = [R24(x) for x in l]
      HALF_PI = p[4]
      x = R11(x0)
      while x < R11(x1):
         t = R24(x)
         if use_sqrt:
            t = sqrt((R24(1)-t)*R24(1/2))
         tt = t*t
         if poly=='p0':
            c5 = fma(p[3],tt,p[2])
            c3 = fma(c5,tt,p[1])
            y = fma(c3,tt*t,t)
         else:
            c5 = fma(p[3], tt, p[2])
            c1 = fma(p[1], tt, p[0])
            y = fma(c5, tt*tt, c1)
            y = t*y
         if use_sqrt:
            y = HALF_PI - 2 * y
         y = y*INV_PI
         if R11(y)!=Asinpi(x):
            if not x in failures:
               failures.append(x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(x), get_hex(Asinpi(x)), get_hex(R11(y)))
         t = R24(-x)
         if use_sqrt:
            t = -t
            t = sqrt((R24(1)-t)*R24(1/2))
         tt = t*t
         if poly=='p0':
            c5 = fma(p[3],tt,p[2])
            c3 = fma(c5,tt,p[1])
            y = fma(c3,tt*t,t)
         else:
            c5 = fma(p[3], tt, p[2])
            c1 = fma(p[1], tt, p[0])
            y = fma(c5, tt*tt, c1)
            y = t*y
         if use_sqrt:
            y = HALF_PI - 2 * y
            y = -y
         y = y*INV_PI
         if R11(y)!=Asinpi(-x):
            if not -x in failures:
               failures.append(-x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(-x), get_hex(Asinpi(-x)), get_hex(R11(y)))
         if x<R11(2^-14):
            x = x + R11(2^-24)
         else:
            x = x.nextabove()
   return len(failures)

# for x < 0.25
def optimize0(iter=100):
   l = ["0x1p0", "0x1.5555fp-3", "0x1.32b088p-4", "0x1.8baf46p-5"]
   p =  [R24(x,16) for x in l]
   n = Failures(2^-24,0.25,p,'p0',verbose=true)
   print ("initial failures:", n)
   # x0 = 2^-24
   x0 = 2^-3
   while iter > 0 and n > 0:
      iter -= 1
      perm = Permutations([0..3]).random_element()
      print (iter)
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,0.25,q,'p0',verbose=false)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,0.25,q,'p0',verbose=false)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0.25 <= x < 0.5
def optimize1(iter=100):
   l = ["0x1.000002p+0","0x1.55a7ep-3","0x1.258e54p-4","0x1.08e44p-4"]
   p =  [R24(x,16) for x in l]
   n = Failures(0.25,0.5,p,'p1',verbose=true)
   print ("initial failures:", n)
   while iter>0 and n>0:
      iter -= 1
      perm = Permutations([0..3]).random_element()
      print (iter)
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(0.25,0.5,q,'p1',verbose=false)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(0.25,0.5,q,'p1',verbose=false)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0.5 <= x < 0.875
def optimize2(iter=100):
   # in that case 0.25 <= sqrt((1-x)/2) < 0.5 thus we use the polynomial p1
   l = ["0x1.000006p+0","0x1.55a7c8p-3","0x1.258e38p-4","0x1.08e42ep-4", "0x1.921fb6p+0"]
   p =  [R24(x,16) for x in l]
   n = Failures(0.5,0.875,p,'p1',verbose=true,use_sqrt=true)
   print ("initial failures:", n)
   while iter>0 and n>0:
      iter -= 1
      perm = Permutations([0..4]).random_element()
      print (iter)
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(0.5,0.875,q,'p1',verbose=false,use_sqrt=true)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(0.5,0.875,q,'p1',verbose=false,use_sqrt=true)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n
