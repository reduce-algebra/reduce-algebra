# generate table for 0.5 <= |x| <= 1
def table1(out):
   f = open(out,"w")
   f.write ("static const float T1[] = {\n")
   s = ""
   for i in range(2^10):
      x = R24(1/2+i/2^11)
      y = atanh(x)
      t = " " + get_hex(y) + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()

# for 0 < x < 1/2
def cr_atanh(x,p,R24):
   R11 = x.parent()
   t = R24(x)
   s = sign(t)
   t = t*s
   tt = t*t
   c9 = fma(p[5],tt,p[4])
   c5 = fma(p[3],tt,p[2])
   c1 = fma(p[1],tt,p[0])
   c5 = fma(c9,tt*tt,c5)
   c1 = fma(c5,tt*tt,c1)
   y = t*c1
   y = s*y
   return R11(y)

def Failures(x0,x1,l,verbose=true):
   failures = []
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      p = [R24(x) for x in l]
      x = R11(x0)
      while x < R11(x1):
         y = cr_atanh(x,p,R24)
         if R11(y)!=atanh(x) and x not in failures:
            failures.append(x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(x), get_hex(atanh(x)), get_hex(R11(y)))
         # check -x
         y = cr_atanh(-x,p,R24)
         if R11(y)!=atanh(-x) and -x not in failures:
            failures.append(-x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(-x), get_hex(atanh(-x)), get_hex(R11(y)))
         x = x.nextabove()
   return len(failures)

def decode(s):
   s = s.split(",")
   return [R24(x,16) for x in s]

# for 0 <= |x| <= 0.5 (except the region where atanh(x) rounds to x)
def optimize0(iter=100):
   s = "0x1.000004p+0, 0x1.55558ep-2, 0x1.997ceep-3, 0x1.2785fcp-3, 0x1.871ffp-4, 0x1.43b244p-3"
   p = decode(s)
   x0 = 1861/65536
   x1 = 1/2
   n = Failures(x0,x1,p,verbose=true)
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
