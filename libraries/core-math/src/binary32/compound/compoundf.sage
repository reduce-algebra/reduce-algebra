# compute the tables for log2 (fast and accurate path)
# log2_tables()
# -1/64 1/64
# (4.02886959854394e-17, 1.43610231315189e-33)
# thus r*x-1 is included in [-1/64,1/64]
# and the maximal absolute error between -log(r)/log(2) and h is
# less than 4.02886959854394e-17 < 2^-54.462
# and the maximal absolute error between -log(r)/log(2) and h+l is
# less than 1.43610231315189e-33 < 2^-109.101
def log2_tables():
   Zmin = 0
   Zmax = 0
   T = []
   U = []
   maxerr = maxerr2 = 0
   for i in range(46):
      a = 1/2+(i+13)/64
      b = 1/2+(i+14)/64
      c = (a+b)/2
      p = 53
      while true:
         R = RealField(p)
         if a==1 or b==1: # force r=1 near 1
            r = R(1)
         else:
            r = R(1/c)
         R = r.exact_rational()
         zmin = R*a-1
         zmax = R*b-1
         u = min(RR(a).ulp(),RR(b).ulp())
         u = u*r.ulp()
         # r*x-1 is an integer multiple of u
         kmin = abs(zmin/u)
         kmax = abs(zmax/u)
         if max(kmin,kmax)>2^53:
            p = p-1
            continue
         # print (i, get_hex(r))
         Zmin = min(Zmin,zmin)
         Zmax = max(Zmax,zmax)
         break
      T.append(r)
      h = RR(n(-log(R)/log(2),200))
      l = RR(n(-log(R)/log(2)-h.exact_rational(),200))
      U.append((h,l))
      err = abs(n(-log(R)/log(2)-h.exact_rational(),200))
      if err>maxerr:
         print (i, "err=", err)
         maxerr = err
      err2 = abs(n(-log(R)/log(2)-h.exact_rational()-l.exact_rational(),200))
      if err2>maxerr2:
         print (i, "err2=", err2)
         maxerr2 = err2
   print ("  static const double inv2[] = {")
   s = "   "
   for r in T:
      s = s + " " + get_hex(r) + ","
      if len(s)+11>=80:
         print (s)
         s = "   "
   if s!="   ":
      print (s)
   print ("  };")
   print ("  static const double log2inv2[][2] = {")
   for h,l in U:
      print ("    {" + get_hex(h) + "," + get_hex(l) + "},")
   print ("  };")
   print (Zmin, Zmax)
   print (RR(maxerr), RR(maxerr2))
   return T, U

# exp2_tables()
# 21 1.0410278456845496999236326786e-16
# 25 err2= 4.7172061428849980120374241673535457364810803525893497222708e-33
# |exp2_U[i][1]| <  1.04102784568456e-16
# thus the maximal absolute error between u[i][0] and 2^r[i] is
# 1.0410278456845496999236326786e-16 < 2^-53.092
# and the maximal absolute error between u[i][0]+u[i][1] and 2^r[i] is
# 4.7172061428849980120374241673535457364810803525893497222708e-33 < 2^-107.385
# and |exp2_U[i][1]| < 1.04102784568456e-16 < 2^-53.092
def exp2_tables():
   T = [RR((i-16)/2^5) for i in [0..32]]
   U = []
   for x in T:
      X = x.exact_rational()
      h = RR(n(2^X,200))
      l = RR(n(2^X-h.exact_rational(),200))
      U.append((h,l))
   print ("  static const double exp2_T[] = {")
   s = "   "
   for r in T:
      s = s + " " + get_hex(r) + ","
      if len(s)+10>=80:
         print (s)
         s = "   "
   if s!="   ":
      print (s)
   print ("  };")
   print ("  static const double exp2_U[][2] = {")
   Al = 0
   for h,l in U:
      print ("    {" + get_hex(h) + "," + get_hex(l) + "},")
      Al = max(Al,abs(l))
   print ("  };")
   maxerr = 0
   maxerr2 = 0
   for i in range(len(T)):
      x = T[i]
      X = x.exact_rational()
      err = abs(n(2^X-U[i][0].exact_rational(),100))
      if err>maxerr:
         print (i,"err=",err)
         maxerr = err
      err2 = abs(n(2^X-U[i][0].exact_rational()-U[i][1].exact_rational(),200))
      if err2>maxerr2:
         print (i,"err2=",err2)
         maxerr2 = err2
   print ("|exp2_U[i][1]| < ", Al)
   return maxerr, maxerr2, U

# return true if x-1 is exact
def x_minus_one_exact(x):
   if x != x: # x = NaN
      return false
   if abs(x) == R24("+Inf"):
      return false
   y = x-R24(1)
   return y.exact_rational() == x.exact_rational()-1

# return the 'ulp' of the interval x i.e. max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# analyze_p1()
# (1.13776403884686e-15, -0.0227200765000836, 0.0227200765000836)
def analyze_p1():
   z = RIF(-1/64,1/64)
   z2 = z*z
   err_z2 = RIFulp(z2)
   P = ["0x0p0", "0x1.71547652b82fep0", "-0x1.71547652b8d11p-1", "0x1.ec709dc3a5014p-2", "-0x1.715475b144983p-2", "0x1.2776c3fda300ep-2", "-0x1.ec990162358cep-3", "0x1.a645337c29e27p-3"]
   P = [RIF(RR(x,16)) for x in P]
   c5 = P[6]*z+P[5]
   err_c5 = RIFulp(c5)
   c3 = P[4]*z+P[3]
   err_c3 = RIFulp(c3)
   c1 = P[2]*z+P[1]
   err_c1 = RIFulp(c1)
   z4 = z2*z2
   err_z4 = RIFulp(z4)+2*z2.abs().upper()*err_z2
   c5 = P[7]*z2+c5
   err_c5 = P[7].abs().upper()*err_z2+err_c5+RIFulp(c5)
   c1 = c3*z2+c1
   err_c1 = err_c3*z2.abs().upper()+c3.abs().upper()*err_z2+err_c1+RIFulp(c1)
   c1 = c5*z4+c1
   err_c1 = err_c5*z4.abs().upper()+c5.abs().upper()*err_z4+err_c1+RIFulp(c1)
   relerr_c1 = err_c1/c1.abs().lower() # bound on relative error on c1
   res = z*c1
   # since c1 has relative error <= relerr_c1, the product z*c1 has
   # relative error < 2^-52, and the Sollya relative error is < 2^-50.98
   # the total relative error is bounded by
   # (1+relerr_c1)*(1+2^-52)*(1+2^-50.98)-1
   R = RealField(100)
   relerr = (1+R(relerr_c1))*(1+R(2^-52))*(1+R(2^-50.98))-1
   return RR(relerr), res.lower(), res.upper()

# return hi, lo and a bound on the dmul error
def analyze_dmul(ah,al,bh,bl):
   err = (al*bl).abs().upper() # ignored term
   hi = ah*bh
   u = RIFulp(hi)
   s = RIF(-u,u)
   t = al*bh+s
   err += RIFulp(t)
   lo = ah*bl+t
   err += RIFulp(lo)
   return hi, lo, err

# return hi, lo and a bound on the relative dmul error
# this is only called with (bh,bl)=(zh,zl), with |zl| < ulp(zh)
# thus |zl| < 2^-52 |zh|
def analyze_dmul_rel(ah,al,bh,bl):
   R = RealField(200)
   rel_a = R((al/ah).abs()) # bound on |al/ah|
   rel_b = R(2^-52)     # bound on |bl/bh|
   err = rel_a*rel_b # ignored term
   hi = ah*bh
   u = RIFulp(hi)
   s = RIF(-u,u) # |s| <= 2^-52 |hi|
   t = al*bh+s
   # |t| <= (rel_a+2^-52)*|hi|
   rel_t = rel_a+R(2^-52)
   k = log(rel_t)/log(2.)
   # if |t| <= 2^k*|hi| then ulp(t) <= 2^k ulp(hi) <= 2^(k-52) |hi|
   err = (1+err)*(1+R(2^ceil(k-52)))-1
   lo = ah*bl+t
   # |lo| <= (2^k+rel_b)*|hi|
   rel_lo = R(2^k)+rel_b
   k2 = log(rel_lo)/log(2.)
   err = (1+err)*(1+R(2^ceil(k2-52)))-1
   return hi, lo, RR(err)

sage.rings.real_mpfi.printing_style = 'brackets'

# analyze_p2()
# (3.52538243018662e-28,
#  [-0.022720076500083991 .. 0.022720076500083991],
# [-1.2398970949199793e-17 .. 1.2398970949199793e-17])
# thus the relative error is bounded by 3.52538243018662e-28 < 2^-91.196
# |h| <= 0.022720076500083991 < 2^-5.459
# |l| <= 1.2398970949199793e-17 < 2^56.162
# since |l/h| <= 1.7370008299703799e-16 < 2^-52.354 before the final mult,
# and |zl/zh| <= 2^-52, the variable s in d_mul is bounded by
# ulp(hi) <= 2^-52*|hi|, then |t| <= (2^-52.354+2^-52)*|hi|,
# and |lo| <= (2^-52+2^-52.354+2^-52)*|hi| < 2^-50.523*|hi|
def analyze_p2():
   R = RealField(200)
   zh = RIF(-1/64-2^-51.508,1/64+2^-51.508)
   zl = RIF(-2^-58,2^-58)
   z = zh+zl
   P2 = ["0x1.71547652b82fep+0", "0x1.777d0ffda0d8p-56", "-0x1.71547652b82fep-1", "-0x1.777d0fd20b49cp-57", "0x1.ec709dc3a03fdp-2", "0x1.d27f05171b74ap-56", "-0x1.71547652b82fep-2", "-0x1.7814e70b828bp-58", "0x1.2776c50ef9bfep-2", "0x1.e4f63e12bff83p-56", "-0x1.ec709dc3a03f4p-3", "0x1.a61762a7adeccp-3", "-0x1.71547652d8849p-3", "0x1.484b13d7e7029p-3", "-0x1.2776c1b2a40fdp-3", "0x1.0c9a80f9b7c1cp-3", "-0x1.ecc68011212p-4", "0x1.c6e4b91fd10e5p-4"]
   P2 = [RIF(RR(x,16)) for x in P2]
   h = P2[4+13]
   err = R(0)
   for i in range(12,7-1,-1):
      ignored = h*zl
      h = h*zh+P2[4+i]
      err = err*zh.abs().upper()+ignored.abs().upper()+RIFulp(h)
   # s_mul (h, l, *h, zh, zl)
   h_old = h
   h = h*z
   u = RIFulp(h)
   l = RIF(-u,u)
   err = err*z.abs().upper()+l.abs().upper().ulp()
   # fast_two_sum (h, &t, P2[10], *h)
   h = P2[10]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   # the fast_two_sum error is bounded by 2 u^2 ufp(h) by Theorem 6 from [1]
   # thus by u ulp(h)
   err += 2^-53*u
   # *l += t
   l += t
   err += RIFulp(l)
   for i in range(8, -1, -2):
      # d_mul (h, l, *h, *l, zh, zl)
      h, l, err_dmul = analyze_dmul(h, l, zh, zl)
      err = err*z.abs().upper() + err_dmul
      # fast_two_sum (h, &t, P2[i], *h)
      h = P2[i]+h
      u = RIFulp(h)
      t = RIF(-u,u)
      err += 2^-53*u
      # *l += t + P2[i+1]
      v = t+P2[i+1]
      err += RIFulp(v)
      l += v
      err += RIFulp(l)
   relerr = err/(h+l).abs().lower() # bound on relative error
   # d_mul (h, l, *h, *l, zh, zl)
   print ("|l/h|=", l/h)
   h, l, relerr_dmul = analyze_dmul_rel(h, l, zh, zl)
   relerr = (1+R(relerr))*(1+R(relerr_dmul))-1
   res = h+l
   # since h+l has relative error <= relerr, and the Sollya relative
   # error is < 2^-93.777, the total relative error is bounded by
   # (1+relerr)*(1+2^-93.777)-1
   relerr = (1+R(relerr))*(1+R(2^-93.777))-1
   return RR(relerr), h, l

# analyze the maximal relative error of _log2p1() for |x| >= 2^-29
# analyze_log2p1()
# e= 0 i= 20 relerr= 3.55975363703180e-15
# thus the maximal relative error is 3.55975363703180e-15 < 2^-47.997
def analyze_log2p1():
   R = RealField(100)
   err0 = R(2^-58.198) # additional relative error for x >= 2^53
   # p is the interval for p1()
   p = RIF(R(-2^-5.459), R(2^-5.459))
   inv, log2inv = log2_tables()
   log2inv = [x[0] for x in log2inv]
   n = len(log2inv)
   assert n==46, "n==46"
   relerr_p1 = R(2^-49.642)
   abserr_p1 = relerr_p1*p.abs().upper() # bound on absolute error for p1
   maxerr = 0
   for e in [-29..128]:
      for i in range(46):
         t = RIF(log2inv[i]) + p
         u = R(e) + t
         if log2inv[i]==0 and e==0:
            relerr_u = relerr_p1
         else:
            Ri = inv[i].exact_rational()
            err_log2inv = R(-log(Ri)/log(2)-log2inv[i].exact_rational())
            abserr_u = RIFulp(u) + RIFulp(t) + abserr_p1 + RR(err_log2inv)
            relerr_u = abserr_u/u.abs().lower()
         # for x >= 2^53, we have an additional relative error err0
         if e >= 53:
            relerr_u = (1+relerr_u)*(1+err0)-1
         if relerr_u>maxerr:
            print ("e=", e, "i=", i, "relerr=", relerr_u)
            maxerr = relerr_u

# analyze_log2p1_accurate()
# e= 0 i= 17 relerr= 6.99553129707774e-28
# e= 0 i= 20 |l/h|= 2.38612684958266e-15
# thus the maximal relative error is 6.99553129707774e-28 < 2^-90.207
# and |l/h| <= 2.38612684958266e-15 < 2^-48.574
def analyze_log2p1_accurate():
   R = RealField(200)
   err0 = R(2^-105) # additional relative error for |x|>=2^54
   # p is the interval for p2()
   p = RIF(R(-2^-5.459), R(2^-5.459))
   pl = RIF(-2^-56.162,2^-56.162)
   _, log2inv = log2_tables()
   n = len(log2inv)
   assert n==46, "n==46"
   relerr_p2 = R(2^-91.195)
   abserr_p2 = relerr_p2*p.abs().upper() # bound on absolute error for p2
   maxerr = 0
   max_l_over_h = 0
   for e in [-29..128]:
      for i in range(46):
         if log2inv[i][0]==0 and e==0:
            relerr = relerr_p2
            l_over_h = RR(2^-50.523)
         else:
            # fast_two_sum (h, l, (double) e, log2inv[i][0])
            h = RIF(e) + RIF(log2inv[i][0])
            u = RIFulp(h)
            l = RIF(-u,u)
            err = 2^-53*u # fast_two_sum error <= 2 u^2 ufp(h) = u ulp(h)
            # *l += log2inv[i][1]
            l += log2inv[i][1]
            err += RIFulp(l)
            # error on log2inv[i]
            err += R(2^-109.101)
            # fast_two_sum (h, &t, *h, ph)
            h = h+p
            u = RIFulp(h)
            t = RIF(-u,u)
            err += 2^-53*u # fast_two_sum error
            err += abserr_p2 # absolute error on p2()
            # *l += t + pl
            v = t + pl
            err += RIFulp(v)
            l += v
            err += RIFulp(l)
            relerr = err/(h+l).abs().lower()
            # for |x| >= 2^54, we get an additional relative error of 2^-105
            if e >= 54:
               relerr = (1+relerr)*(1+err0)-1
            if relerr>maxerr:
               print ("e=", e, "i=", i, "relerr=", relerr)
               maxerr = relerr
            l_over_h = l.abs().upper()/h.abs().lower()
         if l_over_h > max_l_over_h:
            print ("e=", e, "i=", i, "|l/h|=", l_over_h)
            max_l_over_h = l_over_h

# analyze_q1()
# (7.81483493906268e-14, 0.989110713948377, 1.01088928605163)
# thus the absolute error is bounded by 7.81483493906268e-14 < 2^-43.540
def analyze_q1():
   err0 = RR(2^-43.549) # Sollya error on q1
   z = RIF(-2^-6,2^-6)
   Q = ["1.0", "0x1.62e42fef6d01ap-1", "0x1.ebfbdff7feebap-3", "0x1.c6b167e579beep-5", "0x1.3b2b3428d06dep-7"]
   Q = [RIF(RR(x,16)) for x in Q]
   z2 = z*z
   err_z2 = RIFulp(z2)
   c3 = Q[4]*z+Q[3]
   err_c3 = RIFulp(c3)
   c0 = Q[1]*z+Q[0]
   err_c0 = RIFulp(c0)
   c2 = c3*z+Q[2]
   err_c2 = err_c3*z.abs().upper()+RIFulp(c2)
   res = c2*z2+c0
   err_res = err_c2*z2.abs().upper()+c2.abs().upper()*err_z2+err_c0+RIFulp(res)
   err_res += err0 # Sollya error
   return err_res, res.lower(), res.upper()

# analyze_q2()
# ([0.98911071394938065 .. 1.0108892860506194],
# [-2.2832336002932612e-16 .. 2.2832336002932612e-16],
#  2.23366555026200e-26)
# thus at output we have
# 0.989 < qh < 1.011, |ql| < 2^-51.959
# and the absolute error is bounded by 2.23366555026200e-26 < 2^-85.210
# analyze_q2(small=true)
# ([0.99999735584984983 .. 1.0000026441501502],
# [-2.2445038415509148e-16 .. 2.2445038415509148e-16],
# 4.85724568278807e-29)
# In this case the absolute error is bounded by 4.85724568278807e-29 <2^-94.055
def analyze_q2(small=false):
   R = RealField(200)
   if small:
      hmax = 2^-18
      err0 = R(2^-94.058) # Sollya error on q2 for |z| <= 2^-18
   else:
      hmax = 2^-6
      err0 = R(2^-85.218) # Sollya error on q2
   h = RIF(-hmax,hmax)
   l = RIF(-2^-58,2^-58)
   z = h+l
   Q2 = ["1.0","0x1.62e42fefa39efp-1","0x1.abc9d45534d06p-56","0x1.ebfbdff82c58fp-3","-0x1.5e4383cf9ddf7p-57","0x1.c6b08d704a0cp-5","-0x1.6cbc55586c8f1p-59","0x1.3b2ab6fba4e77p-7","0x1.5d87fe789aec5p-10","0x1.430912f879daap-13","0x1.ffcc774b2367ap-17","0x1.62c017b9bdfe6p-20"]
   Q2 = [RIF(R(x,16)) for x in Q2]
   h2 = h*h
   err_h2 = RIFulp(h2)
   c7 = Q2[11]*h+Q2[10]
   err_c7 = RIFulp(c7)+(Q2[11]*l).abs().upper()
   c5 = Q2[9]+h*Q2[8]
   err_c5 = RIFulp(c5)+(Q2[9]*l).abs().upper()
   c5 = c7*h2+c5
   err_c5 = err_c7*h2.abs().upper()+c7.abs().upper()*err_h2+err_c5+RIFulp(c5)
   err_c5 += (2*c7*h*l).abs().upper()
   qh = c5*h
   err = err_c5*h.abs().upper()+RIFulp(qh)+(c5*l).abs().upper()
   # fast_two_sum (qh, ql, Q2[7], *qh)
   qh = Q2[7]+qh
   u = RIFulp(qh)
   ql = RIF(-u,u)
   # by Theorem 6 from [1], the fast_two_sum error is bounded by 2 u^2 ufp(qh)
   # which is u ulp(qh)
   err += RIFulp(qh)*2^-53
   # d_mul (qh, ql, *qh, *ql, h, l)
   qh, ql, dmul_err = analyze_dmul(qh,ql,h,l)
   err = err*z.abs().upper()+dmul_err
   # fast_two_sum (qh, &t, Q2[5], *qh)
   qh = Q2[5]+qh
   u = RIFulp(qh)
   t = RIF(-u,u)
   err += RIFulp(qh)*2^-53
   # *ql += t + Q2[6]
   ql += t + Q2[6]
   err += RIFulp(t+Q2[6]) + RIFulp(ql)
   # d_mul (qh, ql, *qh, *ql, h, l)
   qh, ql, dmul_err = analyze_dmul(qh,ql,h,l)
   err = err*z.abs().upper()+dmul_err
   # fast_two_sum (qh, &t, Q2[3], *qh)
   qh = Q2[3]+qh
   u = RIFulp(qh)
   t = RIF(-u,u)
   err += RIFulp(qh)*2^-53
   # *ql += t + Q2[4]
   ql += t + Q2[4]
   err += RIFulp(t+Q2[4]) + RIFulp(ql)
   # d_mul (qh, ql, *qh, *ql, h, l)
   qh, ql, dmul_err = analyze_dmul(qh,ql,h,l)
   err = err*z.abs().upper()+dmul_err
   # fast_two_sum (qh, &t, Q2[1], *qh)
   qh = Q2[1]+qh
   u = RIFulp(qh)
   t = RIF(-u,u)
   err += RIFulp(qh)*2^-53
   # *ql += t + Q2[2]
   ql += t + Q2[2]
   err += RIFulp(t+Q2[2]) + RIFulp(ql)
   # d_mul (qh, ql, *qh, *ql, h, l)
   qh, ql, dmul_err = analyze_dmul(qh,ql,h,l)
   err = err*z.abs().upper()+dmul_err
   # fast_two_sum (qh, &t, Q2[0], *qh)
   qh = Q2[0]+qh
   u = RIFulp(qh)
   t = RIF(-u,u)
   err += RIFulp(qh)*2^-53
   # *ql += t
   ql += t
   err += RIFulp(ql)
   err += err0 # Sollya error
   return (qh, ql, err)

def scale_table():
   print ("  static const double scale[] = {")
   s = "   "
   for e in range(-29, 128+1):
      s += " " + get_hex (RR(2^-e)) + ","
      if len(s)+10>=80:
         print (s)
         s = "   "
   if s != "   ":
     print (s)
   print ("  };")

# compute the error bound for the accurate phase depending on k
def analyze_exp2_2(small=false):
   _, _, exp2_U = exp2_tables()
   K = []
   R9 = RealField(9,rnd='RNDU')
   for k in [0..150]:
      if small and k!=0:
         continue
      h = RIF(-2^-6,2^-6)
      u = RIFulp(h)
      l = RIF(-u,u)
      if not small:
         err_q2 = RR(2^-85.210)
      else:
         err_q2 = RR(2^-102.646)
      maxerr = 0
      for i in [0..32]:
         if small and i != 16:
            continue
         qh = RIF(0.989,1.011)
         ql = RIF(-2^-51.959,2^-51.959)
         qh_old = qh
         ql_old = ql
         qh = RIF(exp2_U[i][0])*qh_old
         T = RIFulp(qh) + (RIF(exp2_U[i][1])*qh_old).abs().upper()
         R = T + (RIF(exp2_U[i][0])*ql_old).abs().upper()
         ql = RIF(-R,R)
         # we use Lemma 1 from [2] for the d_mul() error
         err_dmul = T.ulp() + R.ulp() + (RIF(exp2_U[i][1])*ql_old).abs().upper()
         qh = qh+ql
         u = RIFulp(qh)
         ql = RIF(-u,u)
         err_fast_two_sum = 2^-53*RIFulp(qh) # Theorem 6 from [1]
         err0 = RR(2^-91.120) # input error |h + l - y*log2(1+x)| < err0*(h+l)
         err0 = min(150,k+1/2)*err0 # absolute error on h+l
         err1 = err_q2*exp2_U[i][0] # absolute error on q2
         err2 = err_dmul # absolute d_mul error
         err3 = err_fast_two_sum # absolute fast_two_sum error
         err = err0+err1+err2+err3
         if err>maxerr:
            maxerr = err
      K.append(R9(maxerr))
      print (k, log(maxerr)/log(2.))
   print ("  static const double Err[] = {")
   s = "   "
   for r in K:
      s = s + " " + get_hex(r) + ","
      if len(s)+11>=80:
         print (s)
         s = "   "
   if s!="   ":
      print (s)
   print ("  };")

# get_hex(underflow_threshold_neg(R24(-1).nextabove()))
# '0x1.8d5554p+2'
def underflow_threshold_neg(x):
   assert -1<x<0,"-1<x<0"
   R = RealField(200)
   a = R24(1)
   b = R24(2^128).nextbelow()
   t = R(2^-149)
   assert t<=(1+R(x))^R(a), "t<=(1+R(x))^R(a)"
   assert (1+R(x))^R(b)<t, "(1+R(x))^R(b)<t"
   while a.nextabove()<b:
      c = (a+b)/2
      if (1+R(x))^c<t:
         b = c
      else:
         a = c
   return a

# return the largest float x < 0 such that (1+x)^nextbelow(2^128) < 2^-149
# get_hex(init_underflow_threshold_neg())
# '-0x1.9d1da2p-122'
def init_underflow_threshold_neg():
   a = R24(-1).nextabove()
   b = R24(-2^-149)
   while a.nextabove()<b:
      c = (a+b)/2
      ok = true
      try:
         y = underflow_threshold_neg(c)
      except AssertionError:
         ok = false # c is too large (negative near 0)
      if ok:
         a = c
      else:
         b = c
   return a

# get_hex(underflow_threshold_pos(R24(1)))
# '-0x1.2ap+7'
def underflow_threshold_pos(x):
   assert 0<x, "0<x"
   R = RealField(200)
   a = R24(-2^128).nextabove()
   b = R24(1)
   t = R(2^-149)
   assert (1+R(x))^R(a)<t, "(1+R(x))^R(a)<t"
   assert t<=(1+R(x))^R(b), "t<=(1+R(x))^R(b)"
   while a.nextabove()<b:
      c = (a+b)/2
      if (1+R(x))^c<t:
         a = c
      else:
         b = c
   return b

# find the smallest float x > 0 such that (1+x)^-nextbelow(2^128) < 2^-149
# get_hex(init_underflow_threshold_pos())
# '0x1.9d1da2p-122'
def init_underflow_threshold_pos():
   a = R24(2^-149)
   b = R24(1)
   while a.nextabove()<b:
      c = (a+b)/2
      ok = true
      try:
         y = underflow_threshold_pos(c)
      except AssertionError:
         ok = false # c is too small (near 0)
      if ok:
         b = c
      else:
         a = c
   return b

# get_hex(overflow_threshold_neg(R24(-1).nextabove()))
# '-0x1.555554p+2'
def overflow_threshold_neg(x):
   assert -1<x<0,"-1<x<0"
   R = RealField(200)
   a = R24(-2^128).nextabove()
   b = R24(-1)
   t = R(2^128).nextbelow()
   assert t<=(1+R(x))^R(a), "t<=(1+R(x))^R(a)"
   assert (1+R(x))^R(b)<t, "(1+R(x))^R(b)<t"
   while a.nextabove()<b:
      c = (a+b)/2
      if (1+R(x))^c<t:
         b = c
      else:
         a = c
   return b

# return the largest float x < 0 such that (1+x)^nextabove(-2^128) > MAX_FLT
# get_hex(init_overflow_threshold_neg())
# '-0x1.62e432p-122'
def init_overflow_threshold_neg():
   a = R24(-1).nextabove()
   b = R24(-2^-149)
   while a.nextabove()<b:
      c = (a+b)/2
      ok = true
      try:
         y = overflow_threshold_neg(c)
      except AssertionError:
         ok = false # c is too large (negative near 0)
      if ok:
         a = c
      else:
         b = c
   return a

# get_hex(overflow_threshold_pos(R24(1)))
# '0x1.fffffep+6'
def overflow_threshold_pos(x):
   assert x>0,"x>0"
   R = RealField(200)
   a = R24(1)
   b = R24(2^128).nextbelow()
   t = R(2^128).nextbelow()
   assert (1+R(x))^R(a)<=t, "(1+R(x))^R(a)<=t"
   assert t<(1+R(x))^R(b), "t<(1+R(x))^R(b)"
   while a.nextabove()<b:
      c = (a+b)/2
      if (1+R(x))^c<t:
         a = c
      else:
         b = c
   return a

# return the smallest float x > 0 such that (1+x)^nextbelow(2^128) > MAX_FLT
# get_hex(init_overflow_threshold_pos())
# '0x1.62e432p-122'
def init_overflow_threshold_pos():
   a = R24(2^-149)
   b = R24(1)
   while a.nextabove()<b:
      c = (a+b)/2
      ok = true
      try:
         y = overflow_threshold_pos(c)
      except AssertionError:
         ok = false # c is too small
      if ok:
         b = c
      else:
         a = c
   return b
