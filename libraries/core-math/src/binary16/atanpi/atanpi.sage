def Atanpi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(atan(X)/pi,200))

def output_poly(p):
   R.<x> = RealField(24)[]
   p = R(p)
   s = "  {"
   d = p.degree()
   for i in range(d):
      s += get_hex(p[i]) + ", "
   s += get_hex(p[d]) + "},"
   print (s)

def cr_atanpi(x,p,R24):
   R11 = x.parent()
   t = R24(x)
   s = sign(t)
   t = t*s
   reduce = false
   if t>1:
      reduce = true
      t = R24(1)/t
   tt = t*t
   if t<=2^-10:
      c1 = fma(p[1],t,p[0])
      return R11(s*t*c1)
   HALF_PI = p[5]
   INV_PI = p[6]
   if t<0.25:
      c5 = fma(p[3],tt,p[2])
      c1 = fma(p[1],tt,p[0])
      c1 = fma(c5,tt*tt,c1)
      y = t*c1
   else:
      c3 = fma(p[4],t,p[3])
      c2 = fma(c3,t,p[2])
      y = fma(p[1],t,p[0])
      y = fma(c2,tt,y)
   if reduce:
      y = HALF_PI-y
   y = s*y
   return R11(y*INV_PI)

def Failures(x0,x1,l,verbose=true):
   failures = []
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      p = [R24(x) for x in l]
      x = R11(x0)
      while x < R11(x1):
         y = cr_atanpi(x,p,R24)
         if R11(y)!=Atanpi(x) and x not in failures:
            failures.append(x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(x), get_hex(Atanpi(x)), get_hex(R11(y)))
         # check -x
         y = cr_atanpi(-x,p,R24)
         if R11(y)!=Atanpi(-x) and -x not in failures:
            failures.append(-x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(-x), get_hex(Atanpi(-x)), get_hex(R11(y)))
         x = x.nextabove()
   return len(failures)

def decode(s):
   s = s.split(",")
   return [R24(x,16) for x in s]

# for 0 <= |x| < 2^-10
def optimize0a(iter=100):
   s = "0x1.45f308p-2, -0x1.cb4bcep-14"
   p = decode(s)
   x0,x1 = 2^-16,2^-10 # direct call to 0
   n = Failures(x0,x1,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..1]).random_element()
      print (iter, perm)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0 <= |x| <= 0.25
def optimize0(iter=100):
   s = "0x1.fffffcp-1, -0x1.55546cp-2, 0x1.98d0ep-3, -0x1.0c7c54p-3, 0, 0x1.921fb6p+0, 0x1.45f306p-2"
   p = decode(s)
   x0,x1 = 2^-16,2^-2 # direct call to 0
   x0a,x1a = 2^2,2^16 # reduction by x -> 1/x
   n = Failures(x0,x1,p,verbose=true)+Failures(x0a,x1a,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..5]).random_element()
      print (iter, perm)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0.25 <= |x| <= 0.5
def optimize1(iter=100):
   s = "0x1.411612p-14, 0x1.ff076ep-1, 0x1.1ee64cp-6, -0x1.a6fc96p-2, 0x1.81dd3ep-3, 0x1.921fb6p+0, 0x1.45f306p-2"
   p = decode(s)
   x0,x1 = 2^-2,2^-1 # direct use of p1
   x0a,x1a = 2^1,2^2 # through reduction x -> 1/x
   n = Failures(x0,x1,p,verbose=true)+Failures(x0a,x1a,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..5]).random_element()
      print (iter, perm)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0.5 <= |x| < 0.75
def optimize2(iter=100):
   s = "-0x1.95964cp-8, 0x1.0bad74p+0, -0x1.e652e2p-4, -0x1.e70ab4p-3, 0x1.a5eb88p-4, 0x1.921fb6p+0, 0x1.45f306p-2"
   p = decode(s)
   x0,x1 = 1/2,3/4 # direct use of p2
   x0a,x1a = 4/3,2 # through reduction x -> x/1
   n = Failures(x0,x1,p,verbose=true)+Failures(x0a,x1a,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..6]).random_element()
      print (iter, perm)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,verbose=false)+Failures(x0a,x1a,p,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

# for 0.75 <= |x| < 1
def optimize3(iter=100):
   s = "-0x1.f75b16p-6, 0x1.2d3d1p+0, -0x1.882376p-2, 0x1.d18c96p-13, 0x1.6aa268p-6, 0x1.921fb6p+0, 0x1.45f306p-2"
   p = decode(s)
   x0,x1 = 3/4,4/3
   n = Failures(x0,x1,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..4]).random_element()
      print (iter, perm)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

