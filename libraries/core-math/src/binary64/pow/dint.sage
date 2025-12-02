#load("../../generic/support/common.sage")
def output_P2():
   R.<x> = RealField(128)[]
   # output of sollya approximations_r2.sollya
   p = 0.11111111440193536743553572726517231217258085962385 * x^9 + -0.1250000033535430800450119134814563892632577335462 * x^8 + 0.14285714285714281611742136612885900603941990993917 * x^7 + -0.166666666666666629184894062032373796000683796592057 * x^6 + 0.20000000000000000000000020129603055921737923827016 * x^5 + -0.25000000000000000000000015510400014308928494754947 * x^4 + 0.33333333333333333333333333333333302665175509692695 * x^3 + -0.49999999999999999999999999999999982688788569027877 * x^2 + x
   assert p[0]==0, "p[0]==0"
   n = p.degree()
   print ("static const dint64_t P_2[] = {")
   for i in range(n,0,-1):
      c = p[i]
      s,m,e = c.sign_mantissa_exponent()
      assert m.nbits()==128, "m.nbits()==128"
      h,l = divmod(m,2^64)
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1},")
   print ("};")

def output_Q2():
   R.<x> = RealField(128)[]
   # output of sollya approximations_r2.sollya
   q = 0.99999999999999999999999999999999999985894067790133 + x * (1.00000000000000000000000000000000000079933615855916 + x * (0.50000000000000000000000000015180407108488775474072 + x * (0.166666666666666666666666666462984783757729250893606 + x * (4.1666666666666666640690989617534789601904776645824e-2 + x * (8.3333333333333333455870766369455449051883988431655e-3 + x * (1.38888889032187945005324320769946044862308554002084e-3 + x * 1.9841269827308838347275481161797322515738528636575e-4))))))
   n = q.degree()
   print ("static const dint64_t Q_2[] = {")
   for i in range(n,-1,-1):
      c = q[i]
      s,m,e = c.sign_mantissa_exponent()
      assert m.nbits()==128, "m.nbits()==128"
      h,l = divmod(m,2^64)
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1},")
   print ("};")

# for 0 <= i < 64, T1_2[i] approximates 2^(i/64)
def output_T1_2():
   print ("static const dint64_t T1_2[] = {")
   R128 = RealField(128)
   for i in range(64):
      c = R128(n(2^(i/64),200))
      s,m,e = c.sign_mantissa_exponent()
      assert s==1, "s==1"
      assert m.nbits()==128, "m.nbits()==128"
      h,l = divmod(m,2^64)
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1},")
   print ("};")

# for 0 <= i < 64, T2_2[i] approximates 2^(i/2^12)
def output_T2_2():
   print ("static const dint64_t T2_2[] = {")
   R128 = RealField(128)
   for i in range(64):
      c = R128(n(2^(i/2^12),200))
      s,m,e = c.sign_mantissa_exponent()
      assert s==1, "s==1"
      assert m.nbits()==128, "m.nbits()==128"
      h,l = divmod(m,2^64)
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1},")
   print ("};")

def analyze_p2(neg=false):
   R64 = RealField(64)
   R128 = RealField(128)
   err = dict()
   z = R64(2^-13).nextbelow()
   if neg:
      z = -z
   P_2 = [0xe38e3954a09e560e/2^4, 0x800000399d09d767/2^3, 0x9249249249248676/2^3, 0xaaaaaaaaaaaa9fdd/2^3, (0xcccccccccccccccc+1)/2^3, (0x8000000000000000+1)/2^2, (0xaaaaaaaaaaaaaaaa+1)/2^2, (0xffffffffffffffff+1)/2^2, 0x8000000000000000]
   P_2 = [x/2^63 for x in P_2]
   # mul_dint_11 (r, z, &P_2[0])
   r0 = z*P_2[0]
   # add_dint_11 (r, &P_2[1], r)
   r = P_2[1]+r0
   err1a = 2*r.ulp() # rounding error of add_dint_11()
   err1b = R64(r0).ulp() # ignored low part of r0
   err[1] = (err1a + err1b)*abs(z)^7
   print ("err1=", log(err[1])/log(2.))
   for i in [2..3]:
      # mul_dint_11 (r, z, r)
      r0 = z*r
      # add_dint_11 (r, &P_2[i], r)
      r = P_2[i]+r0
      erra = 2*r.ulp() # rounding error of add_dint_11()
      errb = R64(r0).ulp() # ignored low part of r0
      err[i] = (erra + errb)*abs(z)^(8-i)
      print ("err"+str(i)+"=", log(err[i])/log(2.))
   # mul_dint_11 (r, z, r)
   r0 = R128(z*r)
   z = R128(z)
   # add_dint (r, &P_2[4], r)
   r = P_2[4]+r0
   erra = 2*r.ulp() # rounding error of add_dint()
   err[4] = erra*abs(z)^4
   print ("err4=", log(err[4])/log(2.))
   for i in [5..8]:
      # mul_dint_21 (r, r, z)
      r0 = z*r
      erra = 2*r0.ulp()
      # add_dint (r, &P_2[i], r)
      r = P_2[i]+r0
      errb = 2*r.ulp()
      err[i] = (erra + errb)*abs(z)^(8-i)
      print ("err"+str(i)+"=", log(err[i])/log(2.))
   abs_err = add(err[i] for i in [1..8])
   print ("abs_err=", log(abs_err)/log(2.))
   assert r > 1 - 2^-13.99, "r > 1 - 2^-13.99"
   rel_err = abs_err/(1 - 2^-8.99)
   print ("rel_err=", log(rel_err)/log(2.))
   # mul_dint_21 (r, r, z)
   r0 = z*r
   abs_err = 2*r0.ulp()+abs(z)*abs_err
   print ("abs_err=", log(abs_err)/log(2.))
   R200 = RealField(200)
   eps0 = R200(2^-128.316) # relative error on the Sollya polynomial
   eps1 = R200(rel_err)
   eps2 = R200(2*2^-127)
   rel_err = (1 + eps0) * (1 + eps1) * (1 + eps2) - 1
   print ("rel_err=", log(rel_err)/log(2.))

# return max(|r*t-1| for tmin <= t <= tmax
# used only internally to this file
def znorm(tmin,tmax,r):
   lo = r.exact_rational()*tmin.exact_rational()
   hi = r.exact_rational()*tmax.exact_rational()
   return max(abs(lo-1),abs(hi-1))

# find the best p-bit approximation r of 1/t over [tmin,tmax]
# that minimizes max(1-r*tmin,r*tmax-1)
# find_best_r(1.125,1.140625,6,53)
# used only internally to this file
def find_best_r(tmin,tmax,p,prec):
   if tmin==1 or tmax==1:
      r = RealField(p)(1)
      z = znorm(tmin,tmax,r)
   else:
      r = RealField(p)(2/(tmin+tmax))
      z = znorm(tmin,tmax,r)
      while znorm(tmin,tmax,r.nextbelow()) < z:
         r = r.nextbelow()
         z = znorm(tmin,tmax,r)
      while znorm(tmin,tmax,r.nextabove()) < z:
         r = r.nextabove()
         z = znorm(tmin,tmax,r)
   lo = r.exact_rational()*tmin.exact_rational()
   hi = r.exact_rational()*tmax.exact_rational()
   # evaluate the number of bits needed to get r*x-1 exactly
   # assuming x has at most prec significant bits
   R = RealField(prec)
   tmin = R(tmin)
   umin = R(lo).exact_rational()/(tmin.ulp()*r.ulp())
   tmax = R(tmax)
   umax = R(hi).exact_rational()/(tmax.ulp()*r.ulp())
   u = ZZ(max(abs(umin),abs(umax)))
   return r, lo, hi, u.nbits()

# two-step argument reduction:
# first step uses upper k1 bits of x, with precision p1
# second step uses upper k1+k2 bits of r[i]*x, with precision p2
# this routine is used to find the best values of k1,p1,k2,p2
# we want the smallest interval [LO,HI] so that z=r2*r1*x-1 fits into 64 bits
# two_step_arg_red(7,9,6,14)
# [90, 181] 92
# LO,HI= 0.9921875 1.0078125 62
# [8128, 8256] 129
# LO,HI= 0.9998779296875 1.0001220703125 76
# 64
def two_step_arg_red(k1,p1,k2,p2):
   R = RealField(53)
   xmin = R("0x1.6a09e667f3bcdp-1",16)
   xmax = R("0x1.6a09e667f3bccp+0",16)
   i1min = floor(xmin*2^k1)
   i1max = floor(xmax*2^k1)
   print ([i1min, i1max], i1max+1-i1min)
   LO = infinity
   HI = 0
   NB = 0
   l1 = []
   for i1 in [i1min..i1max]:
      tmin = R(i1/2^k1)
      tmax = R((i1+1)/2^k1)
      r, lo, hi, nb = find_best_r(tmin,tmax,p1,53)
      l1.append(r)
      LO = min(LO,lo)
      HI = max(HI,hi)
      NB = max(NB,nb)
   print ("LO,HI=", float(LO), float(HI), NB)
   x1min = R(LO)
   x1max = R(HI)
   i2min = floor(x1min*2^(k1+k2))
   i2max = floor(x1max*2^(k1+k2))
   print ([i2min, i2max], i2max+1-i2min)
   LO = infinity
   HI = 0
   NB2 = 0
   l2 = []
   for i2 in [i2min..i2max]:
      tmin = R(i2/2^(k1+k2))
      tmax = R((i2+1)/2^(k1+k2))
      r, lo, hi, nb = find_best_r(tmin,tmax,p2,NB)
      l2.append(r)
      LO = min(LO,lo)
      HI = max(HI,hi)
      NB2 = max(NB2,nb)
   print ("LO,HI=", float(LO), float(HI), NB2)
   # compute number of bits of r2*r1*z-1
   R=RealField(NB2)
   x=R(LO)
   m_lo=ZZ((1-x)/x.ulp())
   x=R(HI)
   m_hi=ZZ((x-1)/x.ulp())
   print ("maxbits(r2*r1*z-1):", max(m_lo,m_hi).nbits())
   return k1,l1,i1min,i1max,k2,l2,i2min,i2max

# k1,l1,i1min,i1max,k2,l2,i2min,i2max = two_step_arg_red(7,9,6,14)
# check_maxbits(k1,l1,i1min,i1max,k2,l2,i2min,i2max)
# 0x1.13ecb164cfae3p+0 62
def check_maxbits(k1,l1,i1min,i1max,k2,l2,i2min,i2max):
   maxbits = 0
   xmin = RR("0x1.6a09e667f3bcdp-1",16)
   xmax = RR("0x1.6a09e667f3bccp+0",16)
   while true:
      x = RR.random_element(xmin,xmax)
      X = x.exact_rational()
      i1 = floor(X*2^k1)
      assert i1min <= i1 <= i1max, "i1min <= i1 <= i1max"
      r1 = l1[i1-i1min]
      R1 = r1.exact_rational()
      i2 = floor(X*R1*2^(k1+k2))
      assert i2min <= i2 <= i2max, "i2min <= i2 <= i2max"
      r2 = l2[i2-i2min]
      R2 = r2.exact_rational()
      Z = X*R1*R2-1
      zbits = Z.numer().nbits()
      if zbits > maxbits:
         print (get_hex(x), zbits)
         maxbits = zbits

# output_inverse_2_1(7,9,90,181)
def output_inverse_2_1(k1,p1,imin,imax):
   Minz = infinity
   Maxz = 0
   print ("static const dint64_t _INVERSE_2_1[] = {")
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      s,m,e = r.sign_mantissa_exponent()
      assert m==0 or m.nbits()==p1, "m==0 or m.nbits()==p1"
      m = m*2^(128-p1)
      e -= 128-p1
      h,l = divmod(m,2^64)
      assert l==0, "l==0"
      print ("    {.hi = " + hex(h) + ", .lo = 0x0, .ex = " + str(e+127) + ", .sgn = 0x0}, /* i=" + str(i) + " */")
   print ("};")

# output_inverse_2_2(6,14,8128,8256,7,62)
def output_inverse_2_2(k2,p2,jmin,jmax,k1,NB):
   Minz = infinity
   Maxz = 0
   print ("static const dint64_t _INVERSE_2_2[] = {")
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      s,m,e = r.sign_mantissa_exponent()
      assert m==0 or m.nbits()==p2, "m==0 or m.nbits()==p2"
      m = m*2^(128-p2)
      e -= 128-p2
      h,l = divmod(m,2^64)
      assert l==0, "l==0"
      print ("    {.hi = " + hex(h) + ", .lo = 0x0, .ex = " + str(e+127) + ", .sgn = 0x0}, /* j=" + str(j) + " */")
   print ("};")

# output_log_inv_2_1(7,9,90,181)
def output_log_inv_2_1(k1,p1,imin,imax):
   print ("static const dint64_t _LOG_INV_2_1[] = {")
   R128 = RealField(128)
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      x = R128(n(log(r.exact_rational()),200))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==128, "m==0 or m.nbits()==128"
      h,l = divmod(m,2^64)
      # we store -log(x) thus we change signs
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1}, /* i=" + str(i) + " */")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0}, /* i=" + str(i) + " */")
   print ("};")

# l1=get_log_inv_2_1(7,9,90,181)
# this routine is only used internally to this file
def get_log_inv_2_1(k1,p1,imin,imax):
   L = []
   R128 = RealField(128)
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      x = R128(n(log(r.exact_rational()),200))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==128, "m==0 or m.nbits()==128"
      h,l = divmod(m,2^64)
      # we store -log(x) thus we change signs
      L.append(-s*(h+l/2^64)/2^63*2^(e+127))
   return L

# output_log_inv_2_2(6,14,8128,8256,7,62)
def output_log_inv_2_2(k2,p2,jmin,jmax,k1,NB):
   print ("static const dint64_t _LOG_INV_2_2[] = {")
   R128 = RealField(128)
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      x = R128(n(log(r.exact_rational()),200))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==128, "m==0 or m.nbits()==128"
      h,l = divmod(m,2^64)
      # we store -log(x) thus we change signs
      if s==1:
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x1}, /* j=" + str(j) + " */")
      else: # s=-1
         print ("    {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+127) + ", .sgn = 0x0}, /* j=" + str(j) + " */")
   print ("};")

# l2=get_log_inv_2_2(6,14,8128,8256,7,62)
# this routine is only used internally to this file
def get_log_inv_2_2(k2,p2,jmin,jmax,k1,NB):
   L = []
   R128 = RealField(128)
   maxerr = 0
   max_relerr = 0
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      x = R128(n(log(r.exact_rational()),200))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==128, "m==0 or m.nbits()==128"
      h,l = divmod(m,2^64)
      # we store -log(x) thus we change signs
      v = -s*(h+l/2^64)/2^63*2^(e+127)
      L.append(v)
      err = abs(n(-log(r.exact_rational())-v,200))
      if err>maxerr:
         maxerr = err
         print ("j=", j, "err=", err)
      if r==1:
         assert v==0,"v==0"
         continue
      relerr = abs(n(-1-v/log(r.exact_rational()),200))
      if relerr>max_relerr:
         max_relerr = relerr
         print ("j=", j, "relerr=", relerr)
   return L

# computes the maximal relative error in p_2() in the case E=0 and
# i <> {127,128}
# In this case the errors (a) and (e) are zero.
def max_rel_err_p2_case1():
   maxerr = 0
   l1 = get_log_inv_2_1(7,9,90,181)
   l2 = get_log_inv_2_2(6,14,8128,8256,7,62)
   R128 = RealField(128)
   RIF128 = RealIntervalField(128)
   for i in range(len(l1)):
      t1 = l1[i]
      if i+90 in [127,128]:
         assert t1==0, "t1==0"
         continue
      for j in range(len(l2)):
         t2 = l2[j]
         # p_2 (&p, &z)
         p0 = RIF128(-0.0001221,0.0001221)
         err = RIF128(2^-137.95) # error (b)
         err += 1/2*R128(t1).ulp() # error (c1)
         err += 1/2*R128(t2).ulp() # error (c2)
         # add_dint (&p, &_LOG_INV_2_2[j - 8128], &p)
         p1 = p0 + t2
         err += p1.abs().upper().ulp()*2 # error (d2) <= 2 ulps(p1)
         # add_dint (&p, &_LOG_INV_2_1[i - 90], &p)
         p2 = p1 + t1
         err += p2.abs().upper().ulp()*2 # error (d1) <= 2 ulps(p2)
         # convert to relative error
         err = (err/p2).abs().upper()
         if err>maxerr:
            print ("i=", 90+i, "j=", 8128+j, "err=", float(err), log(err)/log(2.))
            maxerr = err

# computes the maximal relative error in p_2() in the case E=0,
# i in {127,128}, and j <> {8191,8192}.
# In this case the errors (a), (c1), (d1), (e) are zero.
def max_rel_err_p2_case2():
   maxerr = 0
   l2 = get_log_inv_2_2(6,14,8128,8256,7,62)
   R128 = RealField(128)
   RIF128 = RealIntervalField(128)
   for j in range(len(l2)):
      t2 = l2[j]
      if 8128+j in [8191,8192]:
         assert t2==0, "t2==0"
         continue
      # p_2 (&p, &z)
      p0 = RIF128(-0.0001221,0.0001221)
      err = RIF128(2^-137.95) # error (b)
      err += 1/2*R128(t2).ulp() # error (c2)
      # add_dint (&p, &_LOG_INV_2_2[j - 8128], &p)
      p1 = p0 + t2
      err += p1.abs().upper().ulp()*2 # error (d2) <= 2 ulps(p1)
      # convert to relative error
      err = (err/p1).abs().upper()
      if err>maxerr:
         print ("j=", 8128+j, "err=", float(err), log(err)/log(2.))
         maxerr = err
