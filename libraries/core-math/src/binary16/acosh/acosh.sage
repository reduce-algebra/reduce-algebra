def output_poly(p):
   R.<x> = RealField(24)[]
   p = R(p)
   s = "  {"
   d = p.degree()
   for i in range(d):
      s += get_hex(p[i]) + ", "
   s += get_hex(p[d]) + "},"
   print (s)

# c is the origin of the Sollya polynomial
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
         c4 = fma(p[5],t,p[4])
         c2 = fma(p[3],t,p[2])
         c2 = fma(c4,tt,c2)
         c0 = fma(p[1],t,p[0])
         y = fma(c2,tt,c0)
         if use_sqrt:
            y = sqrt(t-1)*y
         if R11(y)!=acosh(x) and x not in failures:
            failures.append(x)
            if verbose:
               print ("FAIL", 'RND'+r, get_hex(x), get_hex(acosh(x)), get_hex(R11(y)))
         x = x.nextabove()
   return len(failures)

s0 = "0x1.919408p+0, -0x1.a1ee52p-3, 0x1.0dc64ap-4, -0x1.453108p-6, 0x1.040a46p-8, -0x1.803198p-12"
s1 = "0x1.8eb5fap+0, -0x1.6c52a2p-3, 0x1.4dddcp-5, -0x1.e9e95cp-8, 0x1.b697b2p-11, -0x1.5b2df4p-15"
s2 = "0x1.854f4ep+0, -0x1.11e11ep-3, 0x1.362616p-6, -0x1.fb2398p-10, 0x1.e2d052p-14, -0x1.8d21dcp-19"
s3 = "0x1.717322p+0, -0x1.608d74p-4, 0x1.c3ceb2p-8, -0x1.8859d4p-12, 0x1.828e08p-17, -0x1.44eab2p-23"
s4 = "0x1.52b1b4p+0, -0x1.8e60acp-5, 0x1.12e502p-9, -0x1.ee8866p-15, 0x1.f10d92p-21, -0x1.a71f3ep-28"
s5 = "0x1.1b4176p+1, 0x1.c58fdp-4, -0x1.3d491cp-9, 0x1.244e58p-15, -0x1.2b59e6p-22, 0x1.029682p-30"
s6 = "0x1.744536p+1, 0x1.c4d402p-5, -0x1.3c787ap-11, 0x1.235b58p-18, -0x1.2a375cp-26, 0x1.017ceap-35"
s7 = "0x1.cd16eap+1, 0x1.c490cp-6, -0x1.3c27dep-13, 0x1.22f70cp-21, -0x1.29b90ep-30, 0x1.00fd26p-40"
s8 = "0x1.12ec74p+2, 0x1.c475e4p-7, -0x1.3c05dap-15, 0x1.22cb2cp-24, -0x1.29804ap-34, 0x1.00c29ap-45"
s9 = "0x1.3f4c7ep+2, 0x1.c45ddap-8, -0x1.3be5p-17, 0x1.229e72p-27, -0x1.2943fp-38, 0x1.008224p-50"
s10 = "0x1.6baa5p+2, 0x1.c45576p-9, -0x1.3bd988p-19, 0x1.228f6ep-30, -0x1.29308ep-42, 0x1.006ddp-55"
s11 = "0x1.980882p+2, 0x1.c449a8p-10, -0x1.3bc944p-21, 0x1.2278ep-33, -0x1.2911bap-46, 0x1.004d3p-60"
s12 = "0x1.c46664p+2, 0x1.c44006p-11, -0x1.3bbbdp-23, 0x1.22665ep-36, -0x1.28f8a4p-50, 0x1.00326p-65"
s13 = "0x1.f0c4d6p+2, 0x1.c43246p-12, -0x1.3ba86ap-25, 0x1.224b62p-39, -0x1.28d39ep-54, 0x1.000a46p-70"
s14 = "0x1.0e912cp+3, 0x1.c42b4ep-13, -0x1.3b9eb4p-27, 0x1.223e1p-42, -0x1.28c1ap-58, 0x1.ffee3cp-76"
s15 = "0x1.24bfccp+3, 0x1.c4263p-14, -0x1.3b97b8p-29, 0x1.22347ap-45, -0x1.28b4c4p-62, 0x1.ffd2ecp-81"

def decode(s):
   s = s.split(",")
   return [R24(x,16) for x in s]

# s is the string for the polynomial p from Sollya
def optimize(s,x0,x1,use_sqrt=false,use_decode=false):
   if use_decode==false:
      R.<x> = R24[]
      p = R(s)
      p = [p[i] for i in [0..p.degree()]]
   else:
      p = decode(s)
   n = Failures(x0,x1,p,use_sqrt=use_sqrt,verbose=true)
   print ("initial failures:", n)
   changed = true
   while changed and n>0:
      changed = false
      perm = Permutations([0..5]).random_element()
      print (perm)
      for i in perm:
         q = copy(p)
         # try to decrease p[i]
         q[i] = p[i].nextbelow()
         m = Failures(x0,x1,q,use_sqrt=use_sqrt,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            changed = true
            break
         # try to increase p[i]
         q[i] = p[i].nextabove()
         m = Failures(x0,x1,q,use_sqrt=use_sqrt,verbose=false)
         print (m)
         if m<n or (m==n and ZZ.random_element(2)==1):
            if m<n:
               print ("decreased to", m)
               print ([get_hex(x) for x in q])
            n = m
            p = q
            changed = true
            break
   return p, n

