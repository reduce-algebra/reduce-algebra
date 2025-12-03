# print_t3()
# Fastpath error -107.221481931184
# Accurate path error -169.024006269572
def print_t3():
   print ("static const double t3[32][2] = {")
   R = RealField(53)
   maxerr = 0
   maxerr_acc = 0
   for i in range(2^5):
      x = n(2^(i/2^5), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      print ("   {" + get_hex(h) + ", " + get_hex(l) + "},")
      maxerr = max(maxerr,abs(x-h.exact_rational()-l.exact_rational()))
   print ("};")
   print("static const int64_t t3_corr[32] = {")
   for i in range(2^5):
      x = n(2^(i/2^5), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      t = h.exact_rational() + l.exact_rational()
      e = n(log(t) - i/2^5*log(2),400)
      c = round(e * 2^168)
      assert abs(c) < 2^61, "abs(c) < 2^61"
      print("   " + str(c) + "L,")
      err_acc = abs(c/2^168-e)
      maxerr_acc = max(maxerr_acc, err_acc)
   print ("};")
   print ("Fastpath error " + str(log(maxerr)/log(2.)))
   print ("Accurate path error " + str(log(maxerr_acc)/log(2.)))

# print_t2()
# Fastpath error -107.036364808372
# Accurate path error -169.031435947121
def print_t2():
   print ("static const double t2[32][2] = {")
   R = RealField(53)
   maxerr = 0
   maxerr_acc = 0
   for i in range(2^5):
      x = n(2^(i/2^10), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      print ("   {" + get_hex(h) + ", " + get_hex(l) + "},")
      maxerr = max(maxerr,abs(x-h.exact_rational()-l.exact_rational()))
   print ("};")
   print("static const int64_t t2_corr[32] = {")
   for i in range(2^5):
      x = n(2^(i/2^10), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      t = h.exact_rational() + l.exact_rational()
      e = n(log(t) - i/2^10*log(2), 400)
      c = round(e * 2^168)
      assert abs(c) < 2^61, "abs(c) < 2^61"
      print("   " + str(c) + "L,")
      err_acc = abs(c/2^168-e)
      maxerr_acc = max(maxerr_acc, err_acc)
   print ("};")
   print ("Fastpath error " + str(log(maxerr)/log(2.)))
   print ("Accurate path error " + str(log(maxerr_acc)/log(2.)))

# print_t1()
# Fastpath error -107.213929456011
# Accurate path error -169.049206062779
def print_t1():
   print ("static const double t1[32][2] = {")
   R = RealField(53)
   maxerr = 0
   maxerr_acc = 0
   for i in range(2^5):
      x = n(2^(i/2^15), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      print ("   {" + get_hex(h) + ", " + get_hex(l) + "},")
      maxerr = max(maxerr,abs(x-h.exact_rational()-l.exact_rational()))
   print ("};")
   print("static const int64_t t1_corr[32] = {")
   for i in range(2^5):
      x = n(2^(i/2^15), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      t = h.exact_rational() + l.exact_rational()
      e = n(log(t) - i/2^15*log(2), 400)
      c = round(e * 2^168)
      assert abs(c) < 2^61, "abs(c) < 2^61"
      print("   " + str(c) + "L,")
      err_acc = abs(c/2^168-e)
      maxerr_acc = max(maxerr_acc, err_acc)
   print ("};")
   print ("Fastpath error " + str(log(maxerr)/log(2.)))
   print ("Accurate path error " + str(log(maxerr_acc)/log(2.)))

# print_t0()
# Fastpath error -107.009481984509
# Accurate path error -169.005342637465
def print_t0():
   print ("static const double t0[32][2] = {")
   R = RealField(53)
   maxerr = 0
   maxerr_acc = 0
   for i in range(2^5):
      x = n(2^(i/2^20), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      print ("   {" + get_hex(h) + ", " + get_hex(l) + "},")
      maxerr = max(maxerr,abs(x-h.exact_rational()-l.exact_rational()))
   print ("};")
   print("static const int64_t t0_corr[32] = {")
   for i in range(2^5):
      x = n(2^(i/2^20), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      t = h.exact_rational() + l.exact_rational()
      e = n(log(t) - i/2^20*log(2), 400)
      c = round(e * 2^168)
      assert abs(c) < 2^61, "abs(c) < 2^61"
      print("   " + str(c) + "L,")
      err_acc = abs(c/2^168-e)
      maxerr_acc = max(maxerr_acc, err_acc)
   print ("};")
   print ("Fastpath error " + str(log(maxerr)/log(2.)))
   print ("Accurate path error " + str(log(maxerr_acc)/log(2.)))

def print_tables():
   print_t0()
   print_t1()
   print_t2()
   print_t3()

def log2_estimates():
	R = RealField(53)
	RE = RealField(200)
	x   = n(ln(2), 400)
	f   = R(x)
	h   = R(x - f.exact_rational())
	l   = R(x - f.exact_rational() - h.exact_rational())
	print("logeff2 = " + get_hex(f))
	print("deltah  = " + get_hex(h))
	print("deltal  = " + get_hex(l))
	print("logeff2_acc = " + get_tint(RE(x)))

def two_sum_double(a,b):
   s = a + b
   ap = s - b
   bp = s - ap
   t = (a - ap) + (b - bp)
   return s, t

# return the error of two_sum_double, divided by |s|
def error_two_sum_double(a,b):
   s, t = two_sum_double (a, b)
   u = a.exact_rational() + b.exact_rational()
   v = s.exact_rational() + t.exact_rational()
   err = abs(u-v)
   if s==0:
      if err!=0:
         print ("Error for a=", get_hex(a), "b=", get_hex(b))
      return 0
   return abs(u-v)/abs(s)

# checkall_two_sum_double(2)
# (-6.0, '0x1.8p+4', '0x1.8p+0', 'D')
# checkall_two_sum_double(3)
# (-4.0, '0x1p+5', '0x1.4p+0', 'D')
# checkall_two_sum_double(4)
# (-6.5, '0x1p+7', '0x1.2p+0', 'D')
# checkall_two_sum_double(5)
# (-8.5, '0x1p+9', '0x1.1p+0', 'D')
# checkall_two_sum_double(6)
# (-10.75, '0x1p+11', '0x1.08p+0', 'D')
# checkall_two_sum_double(7)
# (-12.875, '0x1p+13', '0x1.04p+0', 'D')
# checkall_two_sum_double(8)
# (-14.875, '0x1p+15', '0x1.02p+0', 'D')
# checkall_two_sum_double(9)
# (-16.9375, '0x1p+17', '0x1.01p+0', 'D')
# checkall_two_sum_double(10)
# (-18.96875, '0x1p+19', '0x1.008p+0', 'D')
def checkall_two_sum_double(p,maxe=None,rnd='NZUD'):
   if maxe==None:
      maxe = 2*p
   maxerr = -1
   for r in rnd:
      R = RealField(p,rnd='RND'+r)
      for e in range(0,maxe+1):
         for ma in range(2^(p-1),2^p):
            a = R(ma/2^(p-1)*2^e)
            for mb in range(2^(p-1),2^p):
               b = R(mb/2^(p-1))
               err = error_two_sum_double(a,b)
               if err>maxerr:
                  maxerr,maxa,maxb,maxr = err,a,b,r
   return float(log(maxerr)/log(2.)),get_hex(maxa),get_hex(maxb),r

def a_mul (a, b):
   hi = a*b
   lo = fma(a, b, -hi)
   return hi, lo

# get_xs(R64("0x1.62e42fefa39fp-20",16),rnd='RNDN')
# '0x1p-19'
# get_xs(R64("0x1.62e42fefa39fp-20",16),rnd='RNDZ')
# '0x1p-19'
# get_xs(R64("0x1.62e42fefa39fp-20",16),rnd='RNDU')
# '0x1.8p-19'
# get_xs(R64("0x1.62e42fefa39fp-20",16),rnd='RNDD')
# '0x1p-19'
def get_xs(x,rnd='RNDN'):
   R64 = RealField(64,rnd=rnd)
   x = R64(x)
   R53 = RealField(53,rnd=rnd)
   ln2inv = R53("0x1.71547652b82fep+0",16)
   C = R53("0x1.8p+32",16)
   y = ln2inv*R53(x) + C
   xs = y - C
   return xs

# find by dichotomy the smallest x (binary80) such that xs >= k*2^-20
# sage: get_hex(find_dichot(k=3,rnd='RNDN'))
# '0x1.bb9d3beb8c86b8p-20'
# sage: get_hex(find_dichot(k=3,rnd='RNDZ'))
# '0x1.0a2b23f3bab74p-19'
# sage: get_hex(find_dichot(k=3,rnd='RNDU'))
# '0x1.62e42fefa39ef002p-20'
# sage: get_hex(find_dichot(k=3,rnd='RNDD'))
# '0x1.0a2b23f3bab74p-19'
def find_dichot(k=1,rnd='RNDN'):
   R64 = RealField(64,rnd=rnd)
   a = R64(2^-100)
   b = 2*a
   while get_xs(b,rnd=rnd)<k*2^-20:
      a, b = b, 2*b
   while a.nextabove() < b:
      c = (a+b)/2
      if get_xs(c,rnd=rnd)<k*2^-20:
         a = c
      else:
         b = c
   return b

# check_x0_x1(rnd='RNDN')
# x= 0x1.62e42fefa39ef002p-20
def check_x0_x1(rnd='RNDN'):
   R64 = RealField(64,rnd=rnd)
   R53 = RealField(53,rnd=rnd)
   logeff2h = R53("0x1.62e42fefa39efp-1",16)
   logeff2l = R53("0x1.abc9e3b39803fp-56",16)
   x0 = R64("0x1.62e42fefa39efp-21",16)
   x1 = R64("0x1.62e42fefa39fp-20",16)
   x = 2*x0
   x = x.nextabove()
   while x < x1:
      xh = R53(x)
      xl = x - R64(xh)
      xs = get_xs(x,rnd=rnd)
      reductedh, reductedl = a_mul (xs, logeff2h)
      a = reductedh.exact_rational() + reductedl.exact_rational()
      b = xs.exact_rational() * logeff2h.exact_rational()
      assert a==b, "a==b (1)"
      xh1 = xh - reductedh
      a = xh1.exact_rational()
      b = xh.exact_rational() - reductedh.exact_rational()
      assert a==b, "a==b (2)"
      xl1 = xl - reductedl
      a = xl1.exact_rational()
      b = xl.exact_rational() - reductedl.exact_rational()
      assert a==b, "a==b (3)"
      t = fma(-logeff2l, xs, xl1)
      a = t.exact_rational()
      b = -logeff2l.exact_rational() * xs.exact_rational() + xl1.exact_rational()
      # assert a==b, "a==b (4)"
      a = xh1.exact_rational()
      b = t.exact_rational()
      assert (a*a == 0 or a*a >= b*b), "|a|>=|b|"
      xh, xl = two_sum_double (xh1, t)
      a = xh.exact_rational() + xl.exact_rational()
      b = xh1.exact_rational() + t.exact_rational()
      # assert a==b, "a==b (5)"
      x = x.nextabove()

# check whether we can find a value of xs multiple of 2^-20,
# with 0 < xs < 2^24/log(2), such that xh - reductedh is small
# and non-zero
def find_xsxh_hardpairs(rnd='RNDN'):
   R53 = RealField(53, rnd=rnd)
   nmax = ceil(2^14/log(2))*2^20
   maxu = 5 # try 5 floating-point numbers below and above reductedh
   for n in range(1, nmax+1) :
      xs = R53(n) / 2^20	
      logeff2h = R53("0x1.62e42fefa39efp-1",16)
      logeff2l = R53("0x1.abc9e3b39803fp-56",16)
      reductedh, reductedl = a_mul(xs, logeff2h)
      xh = reductedh
      for i in range(maxu):
         xh = xh.nextabove()
         xsp = get_xs(xh, rnd) # only depends on xh
         if(xsp == xh):
            print("Hardpair (xs = " + get_hex(xs) + ", xh = " +get_hex(xh)+")")
      xh = reductedh
      for i in range(maxu):
         xh = xh.nextbelow()
         xsp = get_xs(xh, rnd) # only depends on xh
         if(xsp == xh):
            print("Hardpair (xs = " + get_hex(xs) + ", xh = " +get_hex(xh)+")")
      if n % 2^16 == 0:
         print ("n = " + str(n))

# split binade [2^(e-1),2^e) into k blocks
def doit_bacsel(e,k,t0=2^63,t1=2^64,t=20,command='./doit.sh'):
   h = ceil((t1-t0)/k)
   for i in range(k):
      u0 = t0+h*i
      u1 = min(t0+h*(i+1),t1)
      print (command + " " + str(u0) + " " + str(u1) + " 64 " + str(e) + " 64 " + str(t) + " 64")

from functools import cmp_to_key

# sort by increasing exponent, then by increasing t0, then by decreasing t1
# (so that larger intervals come first)
def cmp(x,y):
   if x[2] < y[2]:
      return int(-1)
   if x[2] > y[2]:
      return int(1)
   # now x[2] = y[2]
   if x[0] < y[0]:
      return int(-1)
   if x[0] > y[0]:
      return int(1)
   if x[1] > y[1]:
      return int(-1)
   if x[1] < y[1]:
      return int(1)
   return int(0)

# sort by decreasing exponent, then by increasing t0, then by decreasing t1
# (so that larger intervals come first)
def cmpneg(x,y):
   if x[2] > y[2]:
      return int(-1)
   if x[2] < y[2]:
      return int(1)
   # now x[2] = y[2]
   if x[0] < y[0]:
      return int(-1)
   if x[0] > y[0]:
      return int(1)
   if x[1] > y[1]:
      return int(-1)
   if x[1] < y[1]:
      return int(1)
   return int(0)

# statall("/tmp/log") # nancy+explor
#([((9223372036854775808, -64), (12786308645202655660, 14))],
# [((-12784747816510614319, 14), (-9223372036854775807, -64))])
def statall(f,m=[55,100,102]):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split(" ")
      assert len(s) == 6, "len(s) == 6" # t0 t1 e n nn m
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
      assert ZZ(s[3])==64, "s[3]==64"
      if ZZ(s[4])!=64: # deal separately with subnormal output
         continue
      assert ZZ(s[5]) in [55,100,102], "ZZ(s[5]) in [55,100,102]"
      if ZZ(s[5]) in m:
        l.append((t0,t1,e,ZZ(s[5])))
   f.close()
   lpos = [x for x in l if x[0]>0]
   lneg = [x for x in l if x[0]<0]
   assert len(l) == len(lpos) + len(lneg)
   lpos.sort(key=cmp_to_key(cmp))
   lpos2 = []
   for t0,t1,e,m in lpos:
      # if m==55, check 2^-65 <= x < 0x1.484p+9
      if m==55:
         if not (2^-65 <= t0/2^64*2^e) and (t1/2^64*2^e <= RR("0x1.484p+9",16)):
            print ("for m=55, x>0 outside range", (t0,t1,e,m))
            continue
      # if m==100 or 102, check x >= 0x1.484p+9
      if m in [100,102]:
         if not RR("0x1.484p+9",16) <= t0/2^64*2^e:
            print ("for m=100/102, x>0 outside range", (t0,t1,e,m))
            continue
      if lpos2==[]:
         lpos2 = [((t0,e),(t1,e))]
      else:
         t0old,e0old = lpos2[-1][0]
         t1old,e1old = lpos2[-1][1]
         if t1old*2^e1old > t0*2^e:
            if t1old*2^e1old >= t1*2^e:
               print ("interval ", (t0,e,t1,e), "included in", (t0old,e0old,t1old,e1old))
               continue
            else:
               print ("interval ", (t0,e,t1,e), "partially overlaps", (t0old,e0old,t1old,e1old))
         assert t1old*2^e1old <= t0*2^e, "t1old*2^e1old <= t0*2^e"
         if t1old*2^e1old == t0*2^e:
            lpos2[-1] = (lpos2[-1][0],(t1,e))
         else:
            lpos2.append(((t0,e),(t1,e)))
   lpos = lpos2
   lneg.sort(key=cmp_to_key(cmpneg))
   lneg2 = []
   for t0,t1,e,m in lneg:
      # if m==55, check -2^4 < x <= 2^-65
      if m==55:
         if not (-2^4 < t0/2^64*2^e and (t1-1)/2^64*2^e <= -2^-65):
            print ("for m=55, x<0 outside range", (t0,t1,e,m))
            continue
      # if m==100 or 102, check x <= -2^4
      if m in [100,102]:
         if not (t1-1)/2^64*2^e <= -2^4:
            print ("for m=100/102, x<0 outside range", (t0,t1,e,m))
            continue
      if lneg2==[]:
         lneg2 = [((t0,e),(t1,e))]
      else:
         t0old,e0old = lneg2[-1][0]
         t1old,e1old = lneg2[-1][1]
         if (t1old-1)*2^e1old > (t0-1)*2^e:
            if (t1old-1)*2^e1old >= (t1-1)*2^e:
               print ("interval ", (t0,e,t1,e), "included in", (t0old,e0old,t1old,e1old))
               continue
            else:
               print ("interval ", (t0,e,t1,e), "partially overlaps", (t0old,e0old,t1old,e1old))
         assert (t1old-1)*2^e1old <= (t0-1)*2^e, "(t1old-1)*2^e1old <= (t0-1)*2^e"
         if (t1old-1)*2^e1old == (t0-1)*2^e:
            lneg2[-1] = (lneg2[-1][0],(t1,e))
         else:
            lneg2.append(((t0,e),(t1,e)))
   lneg = lneg2
   return lpos,lneg

def d_mul(ah,al,bh,bl):
   hi, s = a_mul (ah, bh)
   t = fma (al, bh, s)
   lo = fma (ah, bl, t)
   return hi, lo

# check that t3[i3]*t2[i2]*t1[i1]*t0[i0] remains < 2
# we take the largest entry of each table with rounding upwards
# this gives an upper bound on xs_pow2_h + xs_pow2_l
def check_t3t2t1t0():
   R = RealField (53, rnd='RNDU')
   # largest entry t0[31]
   t0h = R("0x1.000157cdf54c2p+0", 16)
   t0l = R("-0x1.ad2ff3ac0a8b3p-56", 16)
   # largest entry t1[31]
   t1h = R("0x1.002afd3d6ff51p+0", 16)
   t1l = R("-0x1.13c6aeb99597p-54", 16)
   # largest entry t2[31]
   t2h = R("0x1.056dbbebb786bp+0", 16)
   t2l = R("0x1.06c87433776c9p-55", 16)
   # largest entry t3[31]
   t3h = R("0x1.f50765b6e454p+0", 16)
   t3l = R("0x1.9d3e12dd8a18bp-54", 16)
   frcp_acc0_h, frcp_acc0_l = d_mul (t0h, t0l, t1h, t1l)
   print (get_hex (frcp_acc0_h), get_hex (frcp_acc0_l))
   frcp_acc2_h, frcp_acc2_l = d_mul (t2h, t2l, t3h, t3l)
   print (get_hex (frcp_acc2_h), get_hex (frcp_acc2_l))
   xs_pow2_h, xs_pow2_l = d_mul (frcp_acc0_h, frcp_acc0_l, frcp_acc2_h, frcp_acc2_l)
   return get_hex (xs_pow2_h), get_hex (xs_pow2_l)

# try to find a large value of xl when do_red is false
# check_xl_for_not_do_red(rnd='RNDZ')
# x= 0x1.5e9c5d6af90c4feep-21 xl= 0x1.47a6c4c495968p-72
def check_xl_for_not_do_red(rnd='RNDN'):
   R64 = RealField(64,rnd=rnd)
   R53 = RealField(53,rnd=rnd)
   ln2invh = R53("0x1.71547652b82fep+0",16)
   ln2invl = R53("0x1.777d0ffda0d24p-56",16)
   t0 = R64("0x1.62e42fefa39fp-21",16)
   xlmax = 0
   while true:
      x = R64.random_element(0,t0)
      xh0 = R53(x)
      xl0 = R53(x - R64(xh0))
      xh, xl = d_mul (ln2invh, ln2invl, xh0, xl0)
      assert abs(xh) < 2^-20, "abs(xh) < 2^-20"
      if abs(xl) > xlmax:
         xlmax = abs(xl)
         print ("x=", get_hex(x), "xl=", get_hex(xl))

# try to find a value of x such that remaining = xh - r is inexact
# check_remaining_inexact(rnd='RNDU')
# x= 0x1.6b33450236459554p-32 -73.0014095702547
# x= 0x1.28910ce3f6949ebp-33 -73.0003522634716
def check_remaining_inexact(rnd='RNDN'):
   R64 = RealField(64,rnd=rnd)
   R53 = RealField(53,rnd=rnd)
   ln2invh = R53("0x1.71547652b82fep+0",16)
   ln2invl = R53("0x1.777d0ffda0d24p-56",16)
   C = R53("0x1.8p+32", 16)
   t0 = R64("0x1.62e42fefa39fp-21",16)
   xlmax = 0
   maxerr = 0
   while true:
      x = R64.random_element(0,t0)
      xh0 = R53(x)
      xl0 = R53(x - R64(xh0))
      y = fma (xh0, ln2invh, C)
      r = y - C
      assert r.exact_rational() == y.exact_rational() - C.exact_rational(), "1"
      xh, xl = d_mul (ln2invh, ln2invl, xh0, xl0)
      assert abs(xh) < 2^-20, "abs(xh) < 2^-20"
      remaining = xh - r
      err = abs(remaining.exact_rational() - (xh.exact_rational() - r.exact_rational()))
      if err > maxerr:
         print ("x=", get_hex(x), log(err*1.0)/log(2.))
         maxerr = err
   
   
# Takes a list of hard cases as input, splits them into those
# above their rounded value and those below their rounded value (to nearest)
def splithc(l):
	R = RealField(1024)
	R64 = RealField(64)
	ldwn = []
	lup = []
	for x in l:
		y = R(exp(x.exact_rational()))
		yr = R64(y) # round to nearest
		e = R(y - yr.exact_rational())
		if(e <= 0):
			ldwn.append((x,yr))
		else:
			lup.append((x,yr))

	print("#define UPPER_EXCEPT " + str(len(lup)))
	print("static const long double upper_except[UPPER_EXCEPT][2] = {")
	for x,y in lup:
				print("{" + get_hex(x) + "L," + get_hex(y) + "L},")
	print("};")
	print("#define LOWER_EXCEPT " + str(len(ldwn)))
	print("static const long double lower_except[LOWER_EXCEPT][2] = {")
	for x,y in ldwn:
				print("{" + get_hex(x) + "L," + get_hex(y) + "L},")
	print("};")

# Take as input a filename for a file containing exceptions and prints
# the exception tables
def gen_excepts(s):
	splithc(read_file(s, "hexa", 16, 64))

# binade [2^(e-1),2^e) for -16444 <= e <= -16382
def doit_bacsel_subnormal(e):
   nn = e-1 + 16382 + 64
   assert 1 <= nn <= 63, "1 <= nn <= 63"
   y0 = R64(2^(e-1))
   y0 = log(y0)
   while exp(y0.exact_rational())>=2^(e-1):
      y0 = y0.nextbelow()
   while exp(y0.exact_rational())<2^(e-1):
      y0 = y0.nextabove()
   y1 = R64(2^e)
   y1 = log(y1)
   while exp(y1.exact_rational())>=2^e:
      y1 = y1.nextbelow()
   while exp(y1.exact_rational())<2^e:
      y1 = y1.nextabove()
   t0 = y0.exact_rational()/2^14*2^64
   t1 = y1.exact_rational()/2^14*2^64
   assert t0 in ZZ, "t0 in ZZ"
   t0 = ZZ(t0)
   assert t1 in ZZ, "t1 in ZZ"
   t1 = ZZ(t1)
   assert t0.nbits() == 64, "t0.nbits() == 64"
   assert t1.nbits() == 64, "t1.nbits() == 64"
   assert t0 < t1, "t0 < t1"
   print ("sbatch ./doit_subnormal.sh " + str(t0) + " " + str(t1) + " 64 " + str(14) + " 64 22 " + str(nn))
