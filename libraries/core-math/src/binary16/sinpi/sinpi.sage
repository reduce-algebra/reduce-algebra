def Sinpi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(sin(pi*X),100))

def Cospi(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(cos(pi*X),100))

def get_x1(i1):
   u1 = i1*2^5
   e = (u1>>10) % (2^5)
   assert e<31, "e<31"
   return R24(asfloat16(u1))

def get_x2(i2):
   h = i2 // (2^5)
   l = i2 % (2^5)
   u2 = h*2^10+l
   e = h % (2^5)
   assert e<31, "e<31"
   if e>0:
      x2 = R24(2^(e-25)*l)
   else:
      x2 = R24(2^(e-24)*l)
   if h>=2^5:
      x2 = -x2
   return x2

def table_mask():
   print ("static const uint16_t M[] = {")
   s = ""
   for i in range(10):
      x = R11(2^i)
      u = asuint16(x)
      e = u>>10
      # ulp(x) = 2^(i-10) thus the integer part starts at bit 10-i
      mask = 2^(10-i)-1
      s += " " + hex(mask) + ","
   print (s + "};")

def table1sin(out):
   f = open(out,"w")
   f.write ("static const b32u32_u S1[] = {\n")
   s = ""
   S1 = []
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf, sin(x) = NaN
         # for sNaN, we keep sNaN to raise invalid, otherwise we use qNaN
         m = u1 % (2^10) # low 10 bits
         if 0 < m < 2^9: # sNaN
            v1 = 0x7f800001
         else:
            v1 = 0x7fc00000
         y1 = asfloat(v1)
         v = "{.u = " + hex(v1) + "}"
      else:
         x1 = R24(asfloat16(u1))
         y1 = Sinpi(x1)
         # there is no underflow/overflow
         # fix manually some values
         if i1 in []:
            y1=y1.nextabove()
         if i1 in []:
            y1=y1.nextbelow()
         v = "{" + get_hex(y1) + "}"
      t = " " + v + ","
      S1.append(y1)
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return S1

def table1cos(out):
   f = open(out,"w")
   f.write ("static const b32u32_u C1[] = {\n")
   s = ""
   C1 = []
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf, cos(x) = NaN
         # for sNaN, we keep sNaN to raise invalid, otherwise we use qNaN
         m = u1 % (2^10) # low 10 bits
         if 0 < m < 2^9: # sNaN
            v1 = 0x7f800001
         else:
            v1 = 0x7fc00000
         y1 = asfloat(v1)
         v = "{.u = " + hex(v1) + "}"
      else:
         x1 = R24(asfloat16(u1))
         y1 = Cospi(x1)
         # there is no underflow/overflow
         # fix manually some values
         if i1 in []:
            y1=y1.nextbelow()
         if i1 in []:
            y1=y1.nextabove()
         v = "{" + get_hex(y1) + "}"
      t = " " + v + ","
      C1.append(y1)
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return C1

def table2sin(out):
   f = open(out,"w")
   f.write ("static const b32u32_u S2[] = {\n")
   s = ""
   S2 = []
   for i2 in range(2^11):
      h = i2 // (2^5)
      l = i2 % (2^5)
      u2 = h*2^10+l
      e = h % (2^5)
      if e==31: # NaN or Inf
         v2 = 0 # tables S1,C1 already generate sNaN/qNaN
         v = "{.u = " + hex(v2) + "}"
         y2 = asfloat(v2)
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = Sinpi(x2)
         # there is no underflow/overflow
         # fix manually some values
         if i2 in []:
            y2=y2.nextbelow()
         if i2 in []:
            y2=y2.nextabove()
         v = "{" + get_hex(y2) + "}"
      t = " " + v + ","
      S2.append(y2)
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return S2

def table2cos(out):
   f = open(out,"w")
   f.write ("static const b32u32_u C2[] = {\n")
   s = ""
   C2 = []
   for i2 in range(2^11):
      h = i2 // (2^5)
      l = i2 % (2^5)
      u2 = h*2^10+l
      e = h % (2^5)
      if e==31: # NaN or Inf
         v2 = 0 # tables S1,C1 already generate sNaN/qNaN
         v = "{.u = " + hex(v2) + "}"
         y2 = asfloat(v2)
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = Cospi(x2)
         if y2==0: # adjust sign
            X2 = x2.exact_rational()
            # x2 is half an integer
            assert 2*X2 in ZZ, "2*X2 in ZZ"
            t = ZZ(2*X2)
            if t % 4 == 3:
               y2 = -y2
         # there is no underflow/overflow
         v = "{" + get_hex(y2) + "}"
      t = " " + v + ","
      C2.append(y2)
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return C2

def get_i1i2(x):
   u = asuint16(x)
   i1 = u>>5
   i2 = ((u>>10)<<5) + (u % (2^5))
   return i1,i2

def is_subnormal(y):
   if y==0:
      return false
   s, m, e = y.sign_mantissa_exponent()
   while is_even(m):
      m = m//2
      e += 1
   return e < -24

def cos_subnormal(x,y,r):
   s, m, e = y.sign_mantissa_exponent()
   e = e + m.nbits()
   # 2^(e-1) <= |y| < 2^e
   p = e + 24
   assert p>=1, "p>=1"
   R = RealField(p, rnd='RND'+r)
   X = x.exact_rational()
   return R(n(cos(X),200))

def subnormalize(y,r):
   s, m, e = y.sign_mantissa_exponent()
   e = e + m.nbits()
   # 2^(e-1) <= |y| < 2^e
   p = e + 24
   assert p>=1, "p>=1"
   R = RealField(p, rnd='RND'+r)
   return R(y.exact_rational())

# return the number of failures for a given x
def number_failures_x(S1,C1,S2,C2,x,verbose=true):
   n = 0
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      i1,i2 = get_i1i2(x)
      y = Sinpi(R11(x))
      t = fma(R24(S1[i1]),R24(C2[i2]),R24(C1[i1])*R24(S2[i2]))
      z = R11(t)
      if y!=z:
         if verbose:
            print (r, get_hex(x), get_hex(y), get_hex(z))
         n += 1
   return n

# return the number of failures for a given i1
def number_failures_i1(S1,C1,S2,C2,i1):
   n = 0
   for k in range(2^5):
      u = (i1<<5)+k
      x = asfloat16(u)
      n += number_failures_x(S1,C1,S2,C2,x)
   return n

# return the number of failures for a given i2
def number_failures_i2(S1,C1,S2,C2,i2):
   n = 0
   for k in range(2^5):
      u = ((i2>>5)<<10)+(k<<5)+(i2%(2^5))
      x = asfloat16(u)
      n += number_failures_x(S1,C1,S2,C2,x)
   return n

# return x.nextbelow() if x <> 0
# return -0 if x=+0
# return "NaN" if x=-0
def below(x):
   if x!=0:
      return x.nextbelow()
   if x.sign_mantissa_exponent()[0]==1: # +0
      return -x
   return "NaN"

# return x.nextabove() if x <> 0
# return +0 if x=-0
# return "NaN" if x=+0
def above(x):
   if x!=0:
      return x.nextabove()
   if x.sign_mantissa_exponent()[0]==-1: # -0
      return -x
   return "NaN"

def optimize_i1(S1,C1,S2,C2,i1,verbose=false):
   n = number_failures_i1(S1,C1,S2,C2,i1)
   S1a = copy(S1)
   t = below(S1[i1])
   if t != "NaN":
      S1a[i1] = t
      m = number_failures_i1(S1a,C1,S2,C2,i1)
      if m<n:
         if verbose:
            print ("S1 changed from", get_hex(S1[i1]), "to", get_hex(S1a[i1]))
         S1[i1] = S1a[i1]
         return m
   t = above(S1[i1])
   if t != "NaN":
      S1a[i1] = t
      m = number_failures_i1(S1a,C1,S2,C2,i1)
      if m<n:
         if verbose:
            print ("S1 changed from", get_hex(S1[i1]), "to", get_hex(S1a[i1]))
         S1[i1] = S1a[i1]
         return m
   C1a = copy(C1)
   t = below(C1[i1])
   if t != "NaN":
      C1a[i1] = t
      m = number_failures_i1(S1,C1a,S2,C2,i1)
      if m<n:
         if verbose:
            print ("C1 changed from", get_hex(C1[i1]), "to", get_hex(C1a[i1]))
         C1[i1] = C1a[i1]
         return m
   t = above(C1[i1])
   if t != "NaN":
      m = number_failures_i1(S1,C1a,S2,C2,i1)
      if m<n:
         if verbose:
            print ("C1 changed from", get_hex(C1[i1]), "to", get_hex(C1a[i1]))
         C1[i1] = C1a[i1]
         return m
   return n

def optimize_i2(S1,C1,S2,C2,i2,verbose=false):
   n = number_failures_i2(S1,C1,S2,C2,i2)
   S2a = copy(S2)
   t = below(S2[i2])
   if t != "NaN":
      S2a[i2] = t
      m = number_failures_i2(S1,C1,S2a,C2,i2)
      if m<n:
         if verbose:
            print ("S2 changed from", get_hex(S2[i2]), "to", get_hex(S2a[i2]))
         S2[i2] = S2a[i2]
         return m
   t = above(S2[i2])
   if t != "NaN":
      S2a[i2] = t
      m = number_failures_i2(S1,C1,S2a,C2,i2)
      if m<n:
         if verbose:
            print ("S2 changed from", get_hex(S2[i2]), "to", get_hex(S2a[i2]))
         S2[i2] = S2a[i2]
         return m
   C2a = copy(C2)
   t = below(C2[i2])
   if t != "NaN":
      C2a[i2] = t
      m = number_failures_i2(S1,C1,S2,C2a,i2)
      if m<n:
         if verbose:
            print ("C2 changed from", get_hex(C2[i2]), "to", get_hex(C2a[i2]))
         C2[i2] = C2a[i2]
         return m
   t = above(C2[i2])
   if t != "NaN":
      C2a[i2] = t
      m = number_failures_i2(S1,C1,S2,C2a,i2)
      if m<n:
         if verbose:
            print ("C2 changed from", get_hex(C2[i2]), "to", get_hex(C2a[i2]))
         C2[i2] = C2a[i2]
         return m
   return n

def optimize(S1,C1,S2,C2,verbose=true):
   l = ["0x1.fdcp-1","-0x1.fdcp-1"]
   l2 = []
   for x in l:
      if not x in l2:
         l2.append(x)
   l = [R11(x,16) for x in l2]
   I1 = Set()
   I2 = Set()
   for x in l:
      i1,i2 = get_i1i2(x)
      I1 += Set({i1})
      I2 += Set({i2})
   changed = true
   while changed and (len(I1)>0 or len(I2)>0):
      changed = false
      for i1 in I1:
         n = number_failures_i1(S1,C1,S2,C2,i1)
         m = optimize_i1(S1,C1,S2,C2,i1)
         if m<n:
            changed = true
         if m==0:
            I1 -= Set({i1})
            print ("remove from I1:", i1, "remains", len(I1))
      for i2 in I2:
         n = number_failures_i2(S1,C1,S2,C2,i2)
         m = optimize_i2(S1,C1,S2,C2,i2)
         if m<n:
            changed = true
         if m==0:
            I2 -= Set({i2})
            print ("remove from I2:", i2, "remains", len(I2))
   print ("I1:", I1)
   print ("I2:", I2)
   return S1,C1,S2,C2

def Optimize(K):
   n = infinity
   for k in range(K):
      S1, C1, S2, C2, m = optimize(verbose=false)
      if m < n:
         S1best, C1best, S2best, C2best = S1, C1, S2, C2
         n = m
         print ("failures", n)
   return S1best, C1best, S2best, C2best
