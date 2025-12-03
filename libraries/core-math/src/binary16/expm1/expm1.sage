def Expm1(x):
   R = x.parent()
   X = x.exact_rational()
   return R(numerical_approx(exp(X)-1,100))

def table1(out):
   f = open(out,"w")
   f.write ("static const b32u32_u T1[] = {\n")
   s = ""
   T = []
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf
         if i1==2^10+(e<<5): # -Inf
            v1 = 0
         else:
            v1 = ((u1>>31)<<31) | ((224+e)<<23) | ((u1 % (2^10)) << 13)
         v = "{.u = " + hex(v1) + "}"
         y1 = R24(0)
      else:
         x1 = R24(asfloat16(u1))
         y1 = exp(x1)
         if y1>=2^128.:
            y1 = R24(2^128).nextbelow()
         if y1<2^-149.:
            y1 = R24(2^-149)
         if i1 in [141,240,284,287,298,309,1282,1285,1288,1290,1291,1301,1306,1310,1311,1334]:
            y1 = y1.nextabove()
         if i1 in [280,289,303,423,1296,1302]:
            y1 = y1.nextbelow()
         v = "{" + get_hex(y1) + "}"
      T.append(y1)
      t = " " + v + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return T

def table2(out):
   f = open(out,"w")
   f.write ("static const b32u32_u T2[] = {\n")
   s = ""
   T = []
   for i2 in range(2^11):
      h = i2 // (2^5)
      l = i2 % (2^5)
      u2 = h*2^10+l
      e = h % (2^5)
      if e==31: # NaN or Inf
         if i2==2^10+(e<<5): # -Inf
            v2 = 0
         else:
            v2 = ((u2>>31)<<31) | ((224+e)<<23) | ((u2 % (2^10)) << 13)
         v = "{.u = " + hex(v2) + "}"
         y2 = R24(0)
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = exp(x2)
         # fix manually some values
         if i2 in [236,293,1250,1264]:
            y2 = y2.nextabove()
         if i2 in [136,159,190,249,264,303,493]:
            y2 = y2.nextbelow()
         if y2>=2^128.:
            y2 = R24(2^128).nextbelow()
         if y2<2^-149.:
            y2 = R24(2^-149)
         v = "{" + get_hex(y2) + "}"
      T.append(y2)
      t = " " + v + ","
      if len(s)+len(t)>=79:
         f.write (s + "\n")
         s = t
      else:
         s += t
   if s!="":
      f.write (s + "\n")
   f.write ("};\n")
   f.close()
   return T
      
def get_i1i2(x):
   u = asuint16(x)
   i1 = u>>5
   i2 = ((u>>10)<<5) + (u % (2^5))
   return i1,i2

# return the number of failures for a given x
def number_failures_x(T1,T2,x,verbose=false):
   n = 0
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      i1,i2 = get_i1i2(x)
      y = Expm1(R11(x))
      z = R11(fma(R24(T1[i1]),R24(T2[i2]),R24(-1)))
      if y!=z:
         if verbose:
            print (r, get_hex(x), get_hex(y), get_hex(z))
         n += 1
   return n

# return the number of failures for a given i1
def number_failures_i1(T1,T2,i1):
   n = 0
   for k in range(2^5):
      u = (i1<<5)+k
      x = asfloat16(u)
      n += number_failures_x(T1,T2,x)
   return n

# return the number of failures for a given i2
def number_failures_i2(T1,T2,i2):
   n = 0
   for k in range(2^5):
      u = ((i2>>5)<<10)+(k<<5)+(i2%(2^5))
      x = asfloat16(u)
      n += number_failures_x(T1,T2,x)
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

def optimize_i1(T1,T2,i1,verbose=false):
   n = number_failures_i1(T1,T2,i1)
   T1a = copy(T1)
   t = below(T1[i1])
   if t != "NaN":
      T1a[i1] = t
      m = number_failures_i1(T1a,T2,i1)
      if m<n:
         if verbose:
            print ("T1 changed from", get_hex(T1[i1]), "to", get_hex(T1a[i1]))
         T1[i1] = T1a[i1]
         return m
   t = above(T1[i1])
   if t != "NaN":
      T1a[i1] = t
      m = number_failures_i1(T1a,T2,i1)
      if m<n:
         if verbose:
            print ("T1 changed from", get_hex(T1[i1]), "to", get_hex(T1a[i1]))
         T1[i1] = T1a[i1]
         return m
   return n

def optimize_i2(T1,T2,i2,verbose=false):
   n = number_failures_i2(T1,T2,i2)
   T2a = copy(T2)
   t = below(T2[i2])
   if t != "NaN":
      T2a[i2] = t
      m = number_failures_i2(T1,T2a,i2)
      if m<n:
         if verbose:
            print ("T2 changed from", get_hex(T2[i2]), "to", get_hex(T2a[i2]))
         T2[i2] = T2a[i2]
         return m
   t = above(T2[i2])
   if t != "NaN":
      T2a[i2] = t
      m = number_failures_i2(T1,T2a,i2)
      if m<n:
         if verbose:
            print ("T2 changed from", get_hex(T2[i2]), "to", get_hex(T2a[i2]))
         T2[i2] = T2a[i2]
         return m
   return n

def optimize(T1,T2,verbose=true):
   l = ["-0x1.b4p-6"]
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
         n = number_failures_i1(T1,T2,i1)
         m = optimize_i1(T1,T2,i1)
         if m<n:
            changed = true
         if m==0:
            I1 -= Set({i1})
            print ("remove from I1:", i1, "remains", len(I1))
      for i2 in I2:
         n = number_failures_i2(T1,T2,i2)
         m = optimize_i2(T1,T2,i2)
         if m<n:
            changed = true
         if m==0:
            I2 -= Set({i2})
            print ("remove from I2:", i2, "remains", len(I2))
   print ("I1:", I1)
   print ("I2:", I2)
   return T1,T2
