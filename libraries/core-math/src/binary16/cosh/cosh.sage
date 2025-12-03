def table1sinh(out):
   f = open(out,"w")
   f.write ("static const b32u32_u S1[] = {\n")
   s = ""
   S1 = []
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf
         # for sNaN, we keep sNaN to raise invalid, otherwise we use qNaN
         m = u1 % (2^10) # low 10 bits
         if m==0: # Inf
            v1 = ((i1>>10)<<31) + 0x7f800000
         elif 0 < m < 2^9: # sNaN
            v1 = 0x7f800001
         else: # qNaN
            v1 = 0x7fc00000
         v = "{.u = " + hex(v1) + "}"
      else:
         x1 = R24(asfloat16(u1))
         y1 = sinh(x1)
         # there is no underflow
         # fix manually some values
         if x1==0 and u1>=2^10: # ensure sinh(-0) = -0
            y1 = -y1
         if x1!=0 and y1==x1:
            if x1>0:
               y1=y1.nextabove()
            else:
               y1=y1.nextbelow()
         if abs(y1)>=2^128:
            y1 = R24(2^128).nextbelow()
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

def table1cosh(out):
   f = open(out,"w")
   f.write ("static const b32u32_u C1[] = {\n")
   s = ""
   C1 = []
   for i1 in range(2^11):
      u1 = i1*2^5
      e = (u1>>10) % (2^5)
      if e==31: # NaN or Inf
         # for sNaN, we keep sNaN to raise invalid, otherwise we use qNaN
         m = u1 % (2^10) # low 10 bits
         if m==0: # Inf
            v1 = 0x7f800000
         elif 0 < m < 2^9: # sNaN
            v1 = 0x7f800001
         else:
            v1 = 0x7fc00000
         v = "{.u = " + hex(v1) + "}"
      else:
         x1 = R24(asfloat16(u1))
         y1 = cosh(x1)
         # there is no underflow
         if abs(y1)>=2^128:
            y1 = R24(2^128).nextbelow()
         # fix manually some values
         # when y1=1 we raise to nextabove(1)
         if y1==1:
            y1=y1.nextabove()
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

def table2sinh(out):
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
         m = u2 % (2^10) # low 10 bits
         if m==0: # Inf
            v2 = ((i1>>10)<<31) + 0x7f800000
         elif 0 < m < 2^9: # sNaN
            v2 = 0x7f800001
         else: # qNaN
            v2 = 0x7fc00000
         v = "{.u = " + hex(v2) + "}"
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = sinh(x2)
         # there is no underflow
         if abs(y2)>=2^128:
            y2 = R24(2^128).nextbelow()
         # fix manually some values
         if x2!=0 and y2==x2:
            if x2>0:
               y2=y2.nextabove()
            else:
               y2=y2.nextbelow()
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

def table2cosh(out):
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
         m = u2 % (2^10) # low 10 bits
         if m==0: # Inf
            v2 = 0x7f800000
         elif 0 < m < 2^9: # sNaN
            v2 = 0x7f800001
         else: # qNaN
            v2 = 0x7fc00000
         v = "{.u = " + hex(v2) + "}"
      else:
         if e>0:
            x2 = R24(2^(e-25)*l)
         else:
            x2 = R24(2^(e-24)*l)
         if h>=2^5:
            x2 = -x2
         y2 = cosh(x2)
         if abs(y2)>=2^128:
            y2 = R24(2^128).nextbelow()
         # when y2=1 we raise to nextabove(1)
         if y2==1:
            y2=y2.nextabove()
         # there is no underflow
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

# return the number of failures
def number_failures(l,S1,C1,S2,C2):
   n = 0
   for r in 'NZUD':
      R11r = RealField(11,rnd='RND'+r)
      R24r = RealField(24,rnd='RND'+r)
      for x in l:
         i1,i2 = get_i1i2(x)
         y = cosh(R11r(x))
         z = R11r(fma(R24r(C1[i1]),R24r(C2[i2]),R24r(S1[i1])*R24r(S2[i2])))
         if y!=z:
            # print (get_hex(x))
            n += 1
   return n

# check one of the 8th neighbours depending on k, 0 <= k < 8
def opt_aux(l,S1,C1,S2,C2,i1,i2,n,k):
   if k==0:
      S1a = copy(S1)
      S1a[i1] = S1[i1].nextbelow()
      m = number_failures(l,S1a,C1,S2,C2)
      if m<n:
         S1[i1] = S1a[i1]
      return min(m,n)
   if k==1:
      S1a = copy(S1)
      S1a[i1] = S1[i1].nextabove()
      m = number_failures(l,S1a,C1,S2,C2)
      if m<n:
         S1[i1] = S1a[i1]
      return min(m,n)
   if k==2:
      C1a = copy(C1)
      C1a[i1] = C1[i1].nextbelow()
      m = number_failures(l,S1,C1a,S2,C2)
      if m<n:
         C1[i1] = C1a[i1]
      return min(m,n)
   if k==3:
      C1a = copy(C1)
      C1a[i1] = C1[i1].nextabove()
      m = number_failures(l,S1,C1a,S2,C2)
      if m<n:
         C1[i1] = C1a[i1]
      return min(m,n)
   if k==4:
      S2a = copy(S2)
      S2a[i2] = S2[i2].nextbelow()
      m = number_failures(l,S1,C1,S2a,C2)
      if m<n:
         S2[i2] = S2a[i2]
      return min(m,n)
   if k==5:
      S2a = copy(S2)
      S2a[i2] = S2[i2].nextabove()
      m = number_failures(l,S1,C1,S2a,C2)
      if m<n:
         S2[i2] = S2a[i2]
      return min(m,n)
   if k==6:
      C2a = copy(C2)
      C2a[i2] = C2[i2].nextbelow()
      m = number_failures(l,S1,C1,S2,C2a)
      if m<n:
         C2[i2] = C2a[i2]
      return min(m,n)
   if k==7:
      C2a = copy(C2)
      C2a[i2] = C2[i2].nextabove()
      m = number_failures(l,S1,C1,S2,C2a)
      if m<n:
         C2[i2] = C2a[i2]
      return min(m,n)

# return the number of failures for a given x
def number_failures_x(S1,C1,S2,C2,x,verbose=false):
   n = 0
   for r in 'NZUD':
      R11 = RealField(11,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      i1,i2 = get_i1i2(x)
      y = cosh(R11(x))
      z = R11(fma(R24(C1[i1]),R24(C2[i2]),R24(S1[i1])*R24(S2[i2])))
      if y!=z:
         if verbose:
            print (r, get_hex(x))
         n += 1
   return n

# return the number of failures for a given i1
def number_failures_i1(S1,C1,S2,C2,i1,verbose=false):
   n = 0
   for k in range(2^5):
      u = (i1<<5)+k
      x = asfloat16(u)
      n += number_failures_x(S1,C1,S2,C2,x,verbose=verbose)
   return n

# return the number of failures for a given i2
def number_failures_i2(S1,C1,S2,C2,i2,verbose=false):
   n = 0
   for k in range(2^5):
      u = ((i2>>5)<<10)+(k<<5)+(i2%(2^5))
      x = asfloat16(u)
      n += number_failures_x(S1,C1,S2,C2,x,verbose=verbose)
   return n

def optimize_i1(S1,C1,S2,C2,i1,verbose=false):
   n = number_failures_i1(S1,C1,S2,C2,i1)
   S1a = copy(S1)
   S1a[i1] = S1[i1].nextbelow()
   m = number_failures_i1(S1a,C1,S2,C2,i1)
   if m<n:
      if verbose:
         print ("S1 changed from", get_hex(S1[i1]), "to", get_hex(S1a[i1]))
      S1[i1] = S1a[i1]
      return m
   S1a[i1] = S1[i1].nextabove()
   m = number_failures_i1(S1a,C1,S2,C2,i1)
   if m<n:
      if verbose:
         print ("S1 changed from", get_hex(S1[i1]), "to", get_hex(S1a[i1]))
      S1[i1] = S1a[i1]
      return m
   C1a = copy(C1)
   C1a[i1] = C1[i1].nextbelow()
   m = number_failures_i1(S1,C1a,S2,C2,i1)
   if m<n:
      if verbose:
         print ("C1 changed from", get_hex(C1[i1]), "to", get_hex(C1a[i1]))
      C1[i1] = C1a[i1]
      return m
   C1a[i1] = C1[i1].nextabove()
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
   S2a[i2] = S2[i2].nextbelow()
   m = number_failures_i2(S1,C1,S2a,C2,i2)
   if m<n:
      if verbose:
         print ("S2 changed from", get_hex(S2[i2]), "to", get_hex(S2a[i2]))
      S2[i2] = S2a[i2]
      return m
   S2a[i2] = S2[i2].nextabove()
   m = number_failures_i2(S1,C1,S2a,C2,i2)
   if m<n:
      if verbose:
         print ("S2 changed from", get_hex(S2[i2]), "to", get_hex(S2a[i2]))
      S2[i2] = S2a[i2]
      return m
   C2a = copy(C2)
   C2a[i2] = C2[i2].nextbelow()
   m = number_failures_i2(S1,C1,S2,C2a,i2)
   if m<n:
      if verbose:
         print ("C2 changed from", get_hex(C2[i2]), "to", get_hex(C2a[i2]))
      C2[i2] = C2a[i2]
      return m
   C2a[i2] = C2[i2].nextabove()
   m = number_failures_i2(S1,C1,S2,C2a,i2)
   if m<n:
      if verbose:
         print ("C2 changed from", get_hex(C2[i2]), "to", get_hex(C2a[i2]))
      C2[i2] = C2a[i2]
      return m
   return n

def optimize(verbose=true):
   l = ["0x1.6ap-5"]
   l2 = []
   for x in l:
      if not x in l2:
         l2.append(x)
   l = [R11(x,16) for x in l2]
   S1 = table1sinh("/tmp/tmp")
   C1 = table1cosh("/tmp/tmp")
   S2 = table2sinh("/tmp/tmp")
   C2 = table2cosh("/tmp/tmp")
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
         print ("i1=", i1, n)
         m = optimize_i1(S1,C1,S2,C2,i1)
         print ("m=", m)
         if m<n:
            changed = true
         if m==0:
            I1 -= Set({i1})
            print ("remove from I1:", i1, "remains", len(I1))
      for i2 in I2:
         n = number_failures_i2(S1,C1,S2,C2,i2)
         print ("i2=", i2, n)
         m = optimize_i2(S1,C1,S2,C2,i2)
         print ("m=", m)
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
