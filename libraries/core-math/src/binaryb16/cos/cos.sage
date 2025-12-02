def tableS1(out):
   f = open(out,"w")
   f.write ("static const float S1[] = {\n")
   s = ""
   for i1 in range(2^8):
      u1 = 123*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = sin(x1)
      v = get_hex(y1)
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

def tableC1(out):
   f = open(out,"w")
   f.write ("static const float C1[] = {\n")
   s = ""
   for i1 in range(2^8):
      u1 = 123*2^7+i1*2^3
      x1 = R24(asbfloat16(u1))
      # if u1 = h*2^4+m, then ulp(x1) = 2^(h-16)
      y1 = cos(x1)
      v = get_hex(y1)
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

def tableS2(out):
   f = open(out,"w")
   f.write ("static const float S2[] = {\n")
   s = ""
   for i2 in range(2^7):
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-11)*l)
      y2 = sin(x2)
      v = get_hex(y2)
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

def tableC2(out):
   f = open(out,"w")
   f.write ("static const float C2[] = {\n")
   s = ""
   for i2 in range(2^7):
      h,l = divmod(i2,2^3)
      x2 = R24(2^(h-11)*l)
      y2 = cos(x2)
      v = get_hex(y2)
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
      
def tableS3(out):
   f = open(out,"w")
   f.write ("static const float S3[] = {\n")
   s = ""
   S = []
   for i in range(5,128):
      x = R24(2^i)
      y = sin(x)
      if i-5 in [26,33]:
         y = y.nextabove()
      S.append(y)
      v = get_hex(y)
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
   return S

def tableC3(out):
   f = open(out,"w")
   f.write ("static const float C3[] = {\n")
   s = ""
   C = []
   for i in range(5,128):
      x = R24(2^i)
      y = cos(x)
      if i-5 in []:
         y = y.nextabove()
      C.append(y)
      v = get_hex(y)
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
   return C

def cr_cos(S3,C3,x,R24):
   au = asuintbf16(x) & 0x7fff
   k = (au >> 7) - 0x8b
   s = R24(S3[k+7])
   c = R24(C3[k+7])
   for j in range(7):
      if au & (1<<j) != 0:
         t = fma(s, R24(C3[k+j]), c * R24(S3[k+j]))
         c = fma(c, R24(C3[k+j]), -s * R24(S3[k+j]))
         s = t
   return x.parent()(c)

def failures_x(S3,C3,x,verbose=true):
   l = []
   for r in 'NZUD':
      R = RealField(8,rnd='RND'+r)
      R24 = RealField(24,rnd='RND'+r)
      x = R(x)
      y = cos(x)
      z = cr_cos(S3,C3,x,R24)
      if y!=z:
         l = [x]
         if verbose:
            print ("FAIL RND"+r+" "+get_hex(x)+" "+get_hex(y)+" "+get_hex(z))
   return Set(l)

# return the number of failures for |x| >= 4096
# if not empty, s_in is the initial set of failures
def failures(S3,C3,s_in,verbose=true):
   if s_in!=[]:
      ok = false
      for x in s_in:
         if len(failures_x(S3,C3,x,verbose=verbose))==0:
            ok = true
            break
      if ok == false: # does not decrease on s_in
         return s_in
   R = RealField(8)
   x = R(4096)
   s = Set([])
   while x<2^128:
      s += failures_x(S3,C3,x,verbose=verbose)
      s += failures_x(S3,C3,-x,verbose=verbose)
      x = x.nextabove()
   return s

# return the list of indices in S3/C3 for numbers in s
def indices(s):
   l = []
   for x in s:
      au = asuintbf16(x) & 0x7fff
      k = (au >> 7) - 0x8b
      l.append(k+7)
      for j in range(7):
         if au & (1<<j) != 0:
            l.append(k+j)
   return Set(l)

def optimize(S3orig,C3orig):
   S3, C3 = copy(S3orig), copy(C3orig)
   s = failures(S3,C3,[],verbose=false)
   print ("initial failures:", len(s))
   li = indices(s)
   print ("li=", li)
   changed = true
   while changed==true:
      changed = false
      for i in li:
         print ("try i=", i)
         # try to decrease S3[i]
         saved = S3[i]
         S3[i] = S3[i].nextbelow()
         t = failures(S3,C3,s,verbose=false)
         changed_si = false
         if len(t)<len(s):
            print ("decrease to", len(t))
            s = t
            changed = changed_si = true
         else: # restore
            S3[i] = saved
         if changed_si == false:
            # try to increase S3[i]
            saved = S3[i]
            S3[i] = S3[i].nextabove()
            t = failures(S3,C3,s,verbose=false)
            if len(t)<len(s):
               print ("decrease to", len(t))
               s = t
               changed = true
            else: # restore
               S3[i] = saved
         # try to decrease C3[i]
         C3[i] = C3[i].nextbelow()
         t = failures(S3,C3,s,verbose=false)
         changed_ci = false
         if len(t)<len(s):
            print ("decrease to", len(t))
            s = t
            changed = changed_ci = true
         else: # restore
            C3[i] = C3[i].nextabove()
         if changed_ci == false:
            # try to increase C3[i]
            C3[i] = C3[i].nextabove()
            t = failures(S3,C3,s,verbose=false)
            if len(t)<len(s):
               print ("decrease to", len(t))
               s = t
               changed = true
            else: # restore
               C3[i] = C3[i].nextbelow()
   return S3, C3
