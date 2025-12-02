def output_poly(p):
   R.<x> = RealField(24)[]
   p = R(p)
   s = "  {"
   d = p.degree()
   for i in range(d):
      s += get_hex(p[i]) + ", "
   s += get_hex(p[d]) + "},"
   print (s)

# l = decode("0x1.5ed2bep+0, 0x1.0d3bp-2, -0x1.d55ab8p-7, 0x1.20902cp-11, -0x1.bd0e6ap-17, 0x1.82e9d2p-23, -0x1.214f5cp-30")
def Failures(x0,x1,l,verbose=true):
   failures = []
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      p = [R24(x) for x in l]
      x = R11(x0)
      while x < R11(x1):
         t = R24(x)
         tt = t*t
         if x1<=2^-2:
            c5 = fma(p[3],tt,p[2])
            c1 = fma(p[1],tt,p[0])
            c1 = fma(c5,tt*tt,c1)
            y = t*c1
         else:
            c4 = fma(p[5], t, p[4])
            c2 = fma(p[3], t, p[2])
            c0 = fma(p[1], t, p[0])
            c4 = fma(p[6], tt, c4)
            c0 = fma(c2, tt, c0)
            y = fma(c4, tt*tt, c0)
         if R11(y)!=asinh(x) and x not in failures:
            failures.append(x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(x), get_hex(asinh(x)), get_hex(R11(y)))
         # check -x
         t = R24(-x)
         tt = t*t
         if x1<=2^-2:
            c5 = fma(p[3],tt,p[2])
            c1 = fma(p[1],tt,p[0])
            c1 = fma(c5,tt*tt,c1)
            y = t*c1
         else:
            t = -t
            c4 = fma(p[5], t, p[4])
            c2 = fma(p[3], t, p[2])
            c0 = fma(p[1], t, p[0])
            c4 = fma(p[6], tt, c4)
            c0 = fma(c2, tt, c0)
            y = fma(c4, tt*tt, c0)
            y = -y
         if R11(y)!=asinh(-x) and -x not in failures:
            failures.append(-x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(-x), get_hex(asinh(-x)), get_hex(R11(y)))
         x = x.nextabove()
   return len(failures)

sm3 = "0x1p+0, -0x1.5554d6p-3, 0x1.32c4a4p-4, -0x1.5336f2p-5"
sm1 = "0x1.2c297p-10, 0x1.f9d56ap-1, 0x1.b8aab8p-5, -0x1.30b6a4p-2, 0x1.73af8ap-3, -0x1.a1564ep-5, 0x1.6908p-8"
s0 = "-0x1.171622p-6, 0x1.1382e4p+0, -0x1.f8ac18p-4, -0x1.c6795cp-4, 0x1.2d2ep-4, -0x1.38f624p-6, 0x1.f9d716p-10"
s3 = "0x1.6f7ec4p-1, 0x1.05fe12p-1, -0x1.c290eap-5, 0x1.12d0bep-8, -0x1.a5b282p-13, 0x1.6d57cp-18, -0x1.108528p-24"
s4 = "0x1.5ed2bep+0, 0x1.0d3bp-2, -0x1.d55ab8p-7, 0x1.20902cp-11, -0x1.bd0e6ap-17, 0x1.82e9d2p-23, -0x1.214f5cp-30"
s5 = "0x1.06cee2p+1, 0x1.0f17cp-3, -0x1.da366cp-9, 0x1.242296p-14, -0x1.c327d6p-21, 0x1.889372p-28, -0x1.25be4cp-36"
s6 = "0x1.5f39b8p+1, 0x1.0f8076p-4, -0x1.db39e6p-11, 0x1.24d724p-17, -0x1.c44a94p-25, 0x1.899116p-33, -0x1.26784p-42"
s7 = "0x1.b7e21p+1, 0x1.0f9492p-5, -0x1.db65a6p-13, 0x1.24f0f8p-20, -0x1.c46c0ep-29, 0x1.89a692p-38, -0x1.2681d4p-48"
s8 = "0x1.084d12p+2, 0x1.0f923p-6, -0x1.db5616p-15, 0x1.24df02p-23, -0x1.c4422p-33, 0x1.89751cp-43, -0x1.2653cp-54"
s9 = "0x1.34afcep+2, 0x1.0f76f6p-7, -0x1.daf3c8p-17, 0x1.24818cp-26, -0x1.c37d7ep-37, 0x1.889b7ep-48, -0x1.258ca6p-60"
s11 = "0x1.8d6aa4p+2, 0x1.0f6f2ap-9, -0x1.dad87p-21, 0x1.24687cp-32, -0x1.c34a9ep-45, 0x1.886548p-58, -0x1.255d2ep-72"
s15 = "0x1.1f707ep+3, 0x1.0f5d12p-13, -0x1.da990ap-29, 0x1.242df4p-44, -0x1.c2d272p-61, 0x1.87e32ep-78, -0x1.24e916p-96"

def decode(s):
   s = s.split(",")
   return [R24(x,16) for x in s]

# s is the string for the polynomial p from Sollya
# optimize(sm3,739/16384,2^-2,use_decode=true)
def optimize(s,x0,x1,use_decode=false,iter=100):
   if use_decode==false:
      R.<x> = R24[]
      p = R(s)
      p = [p[i] for i in [0..p.degree()]]
   else:
      p = decode(s)
   n = Failures(x0,x1,p,verbose=true)
   print ("initial failures:", n)
   changed = true
   while iter>0 and n>0:
      perm = Permutations([0..6]).random_element()
      print (iter)
      iter -= 1
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,verbose=false)
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
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            break
   return p, n

