def Acospi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(acos(X)/pi,100))

def Failures(x0,x1,l,verbose=true,use_sqrt=false):
   failures = []
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      p = [R24(x) for x in l]
      x = R11(x0)
      while x < R11(x1):
         t = R24(x)
         tt = t*t
         c1 = fma(p[2],t,p[1])
         c3 = fma(p[4],t,p[3])
         y = fma(c3,tt,c1)
         y = fma(y,t,p[0])
         y = y * p[5]
         if use_sqrt:
            y = sqrt(1-t)*y
         if R11(y)!=Acospi(x):
            if not x in failures:
               failures.append(x)
            if verbose:
               print ("FAIL", get_hex(x), get_hex(Acospi(x)), get_hex(R11(y)))
         y = R24(1)-y
         if R11(y)!=Acospi(-x):
            if not -x in failures:
               failures.append(-x)
            if verbose:
               print ("FAIL", get_hex(-x), get_hex(Acospi(-x)), get_hex(R11(y)))
         if x<R11(2^-14):
            x = x + R11(2^-24)
         else:
            x = x.nextabove()
   return len(failures)

def optimize0():
   l = ["0x1.921fb4p0", "-0x1.fffb44p-1", "-0x1.25e6b8p-10", "-0x1.3cc114p-3", "-0x1.a85b22p-5","0x1.45f306p-2"]
   p =  [R24(x,16) for x in l]
   n = Failures(2^-24,0.25,p,verbose=false)
   print ("initial failures:", n)
   changed = true
   while changed and n > 0:
      changed = false
      perm = Permutations([0..5]).random_element()
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(2^-24,0.25,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", n)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            changed = true
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(2^-24,0.25,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", n)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            changed = true
            break
   return p, n

def optimize1():
   l = ["0x1.91b678p0","-0x1.f515cap-1","-0x1.bd043ap-4","0x1.7e2d5ap-4","-0x1.190806p-2","0x1.45f306p-2"]
   p =  [R24(x,16) for x in l]
   n = Failures(0.25,0.5,p,verbose=false)
   print ("initial failures:", n)
   changed = true
   while changed and n>0:
      changed = false
      for i in [0..4]:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(0.25,0.5,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
            n = m
            p = q
            changed = true
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(0.25,0.5,q,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
            n = m
            p = q
            changed = true
            break
   return p, n

def optimize2():
   l = ["0x1.91fa1cp0","-0x1.ae5c5ep-3","0x1.31640cp-4","-0x1.98038p-6","0x1.251b5p-8","0x1.45f306p-2"]
   p =  [R24(x,16) for x in l]
   n = Failures(0.5,1.0,p,verbose=false,use_sqrt=true)
   print ("initial failures:", n)
   changed = true
   while changed and n>0:
      changed = false
      perm = Permutations([0..5]).random_element()
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(0.5,1.0,q,verbose=false,use_sqrt=true)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
            n = m
            p = q
            changed = true
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(0.5,1.0,q,verbose=false,use_sqrt=true)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
            n = m
            p = q
            changed = true
            break
   return p, n
