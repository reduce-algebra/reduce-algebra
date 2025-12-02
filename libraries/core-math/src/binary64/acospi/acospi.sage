#load("../../generic/support/common.sage")
from functools import cmp_to_key

# entries are (t0,t1,e)
def cmp(x,y):
   xmin = x[0]*2^x[2]
   xmax = x[1]*2^x[2]
   ymin = y[0]*2^y[2]
   ymax = y[1]*2^y[2]
   if xmax <= ymin:
      return int(-1)
   if ymax <= xmin:
      return int(1)
   if (xmin <= ymin and xmax < ymax):
      return int(-1)
   if (xmin < ymin and xmax <= ymax):
      return int(-1)
   if (ymin <= xmin and ymax < xmax):
      return int(1)
   if (ymin < xmin and ymax <= xmax):
      return int(1)
   return int(0)

# statall("out")
# [((-9007199254740991, -53), (-7074237752028440, -105)), ((7074237752028441, -106), (9007199254740992, -53))]
def statall(f):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split(" ")
      assert len(s) == 5
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
      n = ZZ(s[3])
      nn = ZZ(s[4])
      assert t0.nbits() == n, "t0.nbits() == n"
      assert (t1-1).nbits() == n, "(t1-1).nbits() == n"
      l.append((t0,t1,e-n))
   f.close()
   l.sort(key=cmp_to_key(cmp))
   l2 = []
   for t0,t1,e in l:
      if l2==[]:
         l2 = [((t0,e),(t1,e))]
      elif t0 > 0:
         t1old,e1old = l2[-1][1]
         if t1old*2^e1old > t0*2^e:
            print ((t1old,e1old), (t0, e))
         assert t1old*2^e1old <= t0*2^e, "t1old*2^e1old <= t0*2^e"
         if t1old*2^e1old == t0*2^e:
            l2[-1] = (l2[-1][0],(t1,e))
         else:
            l2.append(((t0,e),(t1,e)))
      else: # t0 < 0
         t1old,e1old = l2[-1][1]
         if (t1old-1).nbits() == t1old.nbits():
            next_x = t1old*2^e1old
         else:
            next_x = (2*t1old-1)*2^(e1old-1)
         if next_x > t0*2^e:
            print ((t1old,e1old), (t0, e))
         assert next_x <= t0*2^e, "next_x <= t0*2^e"
         if next_x == t0*2^e:
            l2[-1] = (l2[-1][0],(t1,e))
         else:
            l2.append(((t0,e),(t1,e)))
   l = l2
   return l

# from a list l of exceptional cases, print two tables:
# one with (x,h) where h is the rounding to nearest of f(x)
# one with a char l (-1,0,1) giving the direction of rounding
def format_exceptions(l):
   print ("static const double exceptions[EXCEPTIONS][2] = {")
   for x in l:
      X = x.exact_rational()
      h = RR(n(acospi(X),200))
      print ("    {" + get_hex(x) + ", " + get_hex(h) + "},")
   print ("  };")
   print ("static const char exceptions_rnd[EXCEPTIONS] = {")
   for x in l:
      X = x.exact_rational()
      h = RR(n(acospi(X),200))
      l = RR(n(acospi(X)-h.exact_rational(),200))
      if l==0:
         l=0
      elif l>0:
         l=1
      else:
         l=-1
      print ("    " + str(l) + ", /* " + get_hex(x) + " */")
   print ("  };")

# return the 'ulp' of the interval x i.e. max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# return p, xmid
def get_poly(i):
   assert 0<=i<256,"0<=i<256"
   R.<t> = RR[]
   s = _T[i].split(' ')
   if i<192:
      assert ZZ(s[8])==i, "ZZ(s[8])==i"
      p = add(RR(s[j],16)*t^j for j in range(7))
      xmid = RR(s[7],16)
   else:
      assert ZZ(s[7])==i, "ZZ(s[7])==i"
      p = add(RR(s[j],16)*t^j for j in range(6))
      xmid = RR(s[6],16)
   return p, xmid

# analyze rounding error of fast path in case |x| < 0.75
# if neg consider x < 0
# analyze_fast_1(190)
# (0.734477374409559, 1.14691787249575e-18)
# analyze_fast_1(190,neg=true)
# (2.41297231928447, 1.14691787249592e-18)
def analyze_fast_1(i,neg=false):
   assert 0<=i<192, "0<=i<192"
   s = _T[i].split(' ')
   err0 = 2^-RR(s[9])
   p, xmid = get_poly(i)
   x = RIF(i/2^8,(i+1)/2^8)
   # y = absx - p[7]
   y = x-xmid # exact
   # yy = y * y
   yy = y*y
   err_yy = RIFulp(yy)
   # p56 = __builtin_fma (p[6], y, p[5])
   p56 = p[6]*y + p[5]
   err_p56 = RIFulp(p56)
   # p34 = __builtin_fma (p[4], y, p[3])
   p34 = p[4]*y + p[3]
   err_p34 = RIFulp(p34)
   # zh = __builtin_fma (p56, yy, p34)
   zh = p56*yy+p34
   err_zh = RIFulp(zh)+err_p56*yy.abs().upper()+p56.abs().upper()*err_yy+err_p34
   # zh = __builtin_fma (zh, y, p[2])
   zh = zh*y+p[2]
   err_zh = RIFulp(zh)+err_zh*y.abs().upper() # no error on y nor p[2]
   # fast_two_sum (&zh, &zl, p[1], y * zh)
   t = y*zh
   err_t = RIFulp(t) + y.abs().upper()*err_zh # no error on y
   zh = p[1]+t
   u = RIFulp(zh)
   zl = RIF(-u,u)
   err_zl = 2^-105*zh.abs().upper() + err_t
   # fast_two_sum (&du, &dv, p[0], zh * y)
   t = zh * y
   err_t = RIFulp(t) + err_zh*y.abs().upper() # no error on y
   du = p[0]+t
   u = RIFulp(du)
   dv = RIF(-u,u)
   err_dv = 2^-105*du.abs().upper() + err_t
   # dv = __builtin_fma (zl, y, dv)
   dv = zl*y+dv
   err_dv = RIFulp(dv)+err_zl*y.abs().upper()+err_dv # no error on y
   if i==0:
      # dv += 0x4.6989e4b05fa3p-56
      dv += RR("0x4.6989e4b05fa3p-56",16)
      err_dv = RIFulp(dv) + err_dv
   if neg:
      # fast_two_sum (&du, &zl, pi_hi, -du)
      pi_hi = RR("0x1.921fb54442d18p1",16)
      pi_lo = RR("0x1.1a62633145c07p-53",16)
      err_pi = 2^-108.04 # error on pi_hi+pi_lo
      du = RIF(pi_hi) - du
      u = RIFulp(du)
      zl = RIF(-u,u)
      err_zl = 2^-105*du.abs().upper()
      # dv = pi_lo + zl - dv
      t = RIF(pi_lo) + zl
      err_t = RIFulp(t) + err_zl + err_pi
      dv = t - dv
      err_dv = err_t + err_dv
   err_dv += err0 # polynomial error
   return du.abs().upper(), err_dv

def dekker(a,b,use_fma=true):
   h = a*b
   if use_fma:
      l = fma(a,b,-h)
   else:
      MAGIC = RR(0x8000001)
      ah = a * MAGIC
      bh = b * MAGIC
      ah = (a - ah) + ah
      bh = (b - bh) + bh
      al = a - ah
      bl = b - bh
      l = (((ah * bh - h) + ah * bl) + al * bh) + al * bl
   return h, l

# return the maximum error observed for sqrt_dbl_dbl
# analyze_sqrt_dbl_dbl()
# x= 0x1.85ae55a988dd8p-1 err= -105.351977187127
# analyze_sqrt_dbl_dbl(use_fma=false)
# x= 0x1.c63df5ecc0146p-1 err= -105.723660042044
def analyze_sqrt_dbl_dbl(use_fma=true):
   maxerr = 0
   while true:
      x = RR.random_element(0.75,1)
      for r in 'NZUD':
         R = RealField(rnd='RND'+r)
         x = R(x)
         h = sqrt(x)
         if use_fma:
            e = -fma(h,h,-x)
         else:
            u, v = dekker (h, h, use_fma=use_fma)
            e = (x - u) - v
         l = e/(h+h)
         X = x.exact_rational()
         H = h.exact_rational()
         L = l.exact_rational()
         err = abs(n(H+L-sqrt(X),200))
         if err>maxerr:
            print ("x=", get_hex(x), "err=", log(err)/log(2.))
            maxerr = err

# analyze rounding error of fast path in case |x| >= 0.75
# analyze_fast_2(193)
# (0.716808611005890, 6.14879115175315e-20)
def analyze_fast_2(i,neg=false):
   assert 192<=i<256, "192<=i<256"
   R.<t> = RR[]
   s = _T[i].split(' ')
   err0 = 2^-RR(s[8])
   p, xmid = get_poly(i)
   x = RIF(i/2^8,(i+1)/2^8)
   # y = absx - p[6]
   y = x-xmid # exact
   # h1 = 1.0 - absx
   h1 = RIF(1.0) - x # exact, 0 <= h <= 0.25
   # h1 = sqrt_dbl_dbl (h1, &l1)
   t = h1
   h1 = sqrt(t)
   u = RIFulp(h1)
   l1 = RIF(-u,u)
   err_l1 = 2^-102.677 # maximal error for sqrt_dbl_dbl()
   # yy = y * y
   yy = y*y
   err_yy = RIFulp(y)
   # p45 = __builtin_fma (p[5], y, p[4])
   print ("p4=", get_hex(p[4]))
   print ("p5=", get_hex(p[5]))
   p45 = p[5]*y+p[4]
   err_p45 = RIFulp(p45)
   print ("err_p45=", err_p45)
   # p23 = __builtin_fma (p[3], y, p[2])
   print ("p2=", get_hex(p[2]))
   print ("p3=", get_hex(p[3]))
   p23 = p[3]*y+p[2]
   err_p23 = RIFulp(p23)
   print ("err_p23=", err_p23)
   # zh = __builtin_fma (p45, yy, p23)
   zh = p45 * yy + p23
   err_zh = RIFulp(zh)+err_p45*yy.abs().upper()+p45.abs().upper()*err_yy+err_p23
   print ("err_zh=", err_zh)
   # zh = __builtin_fma (zh, y, p[1])
   print ("p1=", get_hex(p[1]))
   zh = zh * y + p[1]
   err_zh = RIFulp(zh) + err_zh*y.abs().upper() # no error for y nor p[1]
   print ("err_zh=", err_zh)
   # fast_two_sum (&zh, &zl, p[0], zh * y)
   t = zh*y
   err_t = RIFulp(t)+err_zh*y.abs().upper() # y is exact
   print ("err_t=", err_t)
   print ("p0=", get_hex(p[0]))
   zh = p[0]+t
   u = RIFulp(zh)
   zl = RIF(-u,u)
   err_zl = 2^-105*zh.abs().upper() + err_t # zh is considered exact, the only error is in zl
   print ("err_zl=", err_zl)
   # l1zh = l1 * zh
   l1zh = l1 * zh
   err_l1zh = RIFulp(l1zh) + err_l1*zh.abs().upper() # zh is considered exact
   print ("err_l1zh=", err_l1zh)
   # h1zl = h1 * zl
   h1zl = h1 * zl
   err_h1zl = RIFulp(h1zl) + h1.abs().upper()*err_zl # h1 is considered exact
   print ("err_h1zl=", err_h1zl)
   # dekker (&du, &dv, h1, zh)
   du = h1*zh
   u = RIFulp(du)
   dv = RIF(-u,u)
   err_dv = 2^-104*du.abs().upper() # error from dekker(), h1 and zh are considered exact
   print ("err_dv=", err_dv)
   # dv += l1zh + h1zl
   t = l1zh + h1zl
   err_t = RIFulp(t) + err_l1zh + err_h1zl + l1.abs().upper()*zl.abs().upper()
   dv = dv + t
   err_dv = RIFulp(dv) + err_dv + err_t
   if neg:
      # fast_two_sum (&du, &zl, pi_hi, -du)
      pi_hi = RR("0x1.921fb54442d18p1",16)
      pi_lo = RR("0x1.1a62633145c07p-53",16)
      err_pi = 2^-108.04 # error on pi_hi+pi_lo
      du = RIF(pi_hi) - du
      u = RIFulp(du)
      zl = RIF(-u,u)
      err_zl = 2^-105*du.abs().upper()
      # dv = zl + pi_lo - dv
      t = zl + RIF(pi_lo)
      err_t = RIFulp(t) + err_zl + err_pi
      dv = t - dv
      err_dv = err_t + err_dv
   err_dv += err0 # polynomial error
   return du.abs().upper(), err_dv

# construct the table of error bounds for 0 <= i < 256
def get_max_err():
   R = RealField(9,rnd='RNDU')
   s = "static const double Err[256] = {"
   for i in range(256):
      if i < 192:
         _, e = analyze_fast_1(i)
         e = e * 2^-1.651 + 2^-108 + 2^-105 + 2^-101.83
      else:
         _, e = analyze_fast_2(i)
         e = e * 2^-1.651 + 2^-107 + 2^-105 + 2^-101.83
      s += get_hex(R(e))
      if i<255:
         s += ", "
   s += "};"
   print (s)

# return a minimax polynomial for acos(x0+x) over -h <= x <= h, of degree d
# with coefficients of degree 53
def sollya_approx1(x0,h,d):
   s = "./doit.sh"
   s += " " + get_hex(x0) + " " + get_hex(h) + " " + str(d)
   os.system (s)
   f = open("out","r")
   s = f.readline()
   R.<x> = RealField(107)[]
   p = R(s)
   s = f.readline()
   ret = RR(s[:-1])
   f.close()
   return p, ret

# return a degree-d minimax polynomial for acos(x)/sqrt(1-x)
# over -h <= x <= h, of degree d, with coefficients of degree 53
def sollya_approx2(x0,h,d):
   s = "./doit_sqrt.sh"
   s += " " + get_hex(x0) + " " + get_hex(h) + " " + str(d)
   os.system (s)
   f = open("out","r")
   s = f.readline()
   R.<x> = RealField(107)[]
   p = R(s)
   s = f.readline()
   ret = RR(s[:-1])
   f.close()
   return p, ret

def generate_T():
   mine = infinity
   print ("static const double T[256][8] = {")
   for i in range(192):
      p, xmid = get_poly(i)
      e = sollya_error(i,xmid,p)
      if e<mine:
         mine=e
         mini=i
      s = "  {"
      for j in [0..6]:
         s += get_hex(p[j]) + ", "
         if i==0 and j==0:
            s += "/*0x4.6989e4b05fa3p-56,*/ "
      s += get_hex(xmid) + "}, /* i=" + str(i) + " " + str(float(e)) + " */"
      print (s)
   for i in range(192,256):
      p, xmid = get_poly(i)
      e = sollya_error3(i,xmid,p)
      if e<mine:
         mine=e
         mini=i
      s = "  {"
      for j in [0..5]:
         s += get_hex(p[j]) + ", "
      s += get_hex(xmid) + "}, /* i=" + str(i) + " " + str(float(e)) + " */"
      print (s)
   print ("};")
   print ("mine=", mine, "for i=", mini)

# given a degree-6 polynomial p such that p(x-x0) approximates acos(x)
# for i/256 <= x <= (i+1)/256, with 0 <= i < 192,
# return the corresponding maximal absolute error
def sollya_error(i,x0,p):
   L = RR(i/256)-x0
   H = RR((i+1)/256)-x0
   if i==0: # special case
      s = "./doit2_0.sh"
   else:
      s = "./doit2.sh"
   s += " " + get_hex(x0) + " " + get_hex(L) + " " + get_hex(H)
   for j in [0..6]:
      s += " " + get_hex(p[j])
      if i==0 and j==0:
         s += " " + get_hex(RR("0x4.6989e4b05fa3p-56",16))
   os.system (s)
   f = open("out","r")
   s = f.readline()
   ret = RR(s[:-1])
   f.close()
   return ret

# given a degree-5 polynomial p such that sqrt(1-x)*p(x-x0)
# approximates acos(x) for i/256 <= x <= (i+1)/256, with 0 < i < 256,
# return the corresponding maximal absolute error
def sollya_error3(i,x0,p):
   assert 0<i<256, "0<i<256"
   L = RR(i/256)-x0
   H = RR((i+1)/256)-x0
   s = "./doit3.sh"
   s += " " + get_hex(x0) + " " + get_hex(L) + " " + get_hex(H)
   for j in [0..5]:
      s += " " + get_hex(p[j])
   os.system (s)
   f = open("out","r")
   s = f.readline()
   ret = RR(s[:-1])
   f.close()
   return ret

# generate a degree-6 Sollya polynomial p with 53-bit coefficients
# and a point x0 such that p(x-x0) approximates acos(x)
# for i/256 <= x0+x <= (i+1)/256, for 0 < i < 256,
# with absolute error < err_max
def gen_poly_1(i,err_max):
   lo = RR(i/256)
   hi = RR((i+1)/256)
   x0 = (lo+hi)/2
   x1 = x0.nextabove()
   while true:
      p, err = sollya_approx1(x0,max(x0-lo,hi-x0),6)
      if 2^-err < err_max:
         break
      x0 = x0.nextbelow()
      p, err = sollya_approx1(x1,max(x1-lo,hi-x1),6)
      if 2^-err < err_max:
         x0 = x1
         break
      x1 = x1.nextabove()
   return p, x0, err

# generate a degree-5 Sollya polynomial p with 53-bit coefficients
# and a point x0 such that sqrt(1-x)*p(x-x0) approximates acos(x)
# for i/256 <= x <= (i+1)/256, for 0 < i < 256,
# with absolute error < err_max
def gen_poly_2(i,err_max):
   lo = RR(i/256)
   hi = RR((i+1)/256)
   x0 = (lo+hi)/2
   x1 = x0.nextabove()
   while true:
      p, err = sollya_approx2(x0,max(x0-lo,hi-x0),5)
      if 2^-err < err_max:
         break
      x0 = x0.nextbelow()
      p, err = sollya_approx2(x1,max(x1-lo,hi-x1),5)
      if 2^-err < err_max:
         x0 = x1
         break
      x1 = x1.nextabove()
   return p, x0, err
      
_T=[
"0x1.921fb54442d18p+0 -0x1p+0 -0x1.c6c0b6834ba0ep-49 -0x1.555555551318ap-3 -0x1.d02e84f046fbp-28 -0x1.3330337ffdfc1p-4 -0x1.2e509a02e335bp-11 0x0p+0 0 72.838",
"0x1.909fb4b44253fp+0 -0x1.00012001e6037p+0 -0x1.8005100e28eb9p-9 -0x1.5562d594993b6p-3 -0x1.200a8c3965d9cp-9 -0x1.3355447aa843dp-4 -0x1.e026a0a5f0aefp-10 0x1.7fffffffebc6fp-8 1 64.518",
"0x1.8f9fb2a990bfbp+0 -0x1.0003200ea64c8p+0 -0x1.400bb85b9a23fp-8 -0x1.557ad73dabcdfp-3 -0x1.e030d6eae8d23p-9 -0x1.33914cbc551f1p-4 -0x1.9052bcaec1773p-9 0x1.400000000a072p-7 2 64.379",
"0x1.8e9fae1ec5e86p+0 -0x1.00062038483f3p+0 -0x1.c02029ec97416p-8 -0x1.559edca9aafc8p-3 -0x1.504305dafd9f7p-8 -0x1.33eb677d14e3dp-4 -0x1.186edf2c1538bp-8 0x1.c0000000173dcp-7 3 65.686",
"0x1.8d9fa613b89eap+0 -0x1.000a2099d022ap+0 -0x1.20222f613b541p-7 -0x1.55cee95daeca9p-3 -0x1.b08e7d9b5ed11p-8 -0x1.3463a5fffc8c4p-4 -0x1.68eb18bc28196p-8 0x1.1ffffffff1befp-6 4 66.481",
"0x1.8c9f99881e5bcp+0 -0x1.000f215747cefp+0 -0x1.603e6d387928ap-7 -0x1.560b020c3969bp-3 -0x1.088220a9b46c8p-7 -0x1.34fa1f513523fp-4 -0x1.b9aa6a457192fp-8 0x1.600000000e7b8p-6 5 65.068",
"0x1.8b9f877b8725bp+0 -0x1.0015229dc21c5p+0 -0x1.a0671142e6ff1p-7 -0x1.56532c961ca7bp-3 -0x1.38d6e3dc0130ep-7 -0x1.35aef04dfe9d2p-4 -0x1.05605e2f608a4p-7 0x1.9ffffffff24c1p-6 6 64.966",
"0x1.8a9f6eed4e15fp+0 -0x1.001c24a35f6c6p+0 -0x1.e09e5f7ed0f45p-7 -0x1.56a7700b9c222p-3 -0x1.694a48b8af916p-7 -0x1.36823bad3f08bp-4 -0x1.2e1d1964a6284p-7 0x1.e0000000026a6p-6 7 64.484",
"0x1.899f4edc9635ap+0 -0x1.002427a752d4cp+0 -0x1.10734eacbb336p-6 -0x1.5707d4adc6ep-3 -0x1.99e1157450dc9p-7 -0x1.37742a0b7a1e4p-4 -0x1.5714ee0467369p-7 0x1.0ffffffffef23p-5 8 64.459",
"0x1.889f26483e1ecp+0 -0x1.002d2bf1e8623p+0 -0x1.30a108f493ffap-6 -0x1.577463f00e4f7p-3 -0x1.caa01713d90bep-7 -0x1.3884e9f63c6e9p-4 -0x1.804e8b4c133f6p-7 0x1.2fffffffe7e71p-5 9 64.306",
"0x1.879ef42ed5a5bp+0 -0x1.003731d48c3fap+0 -0x1.50d983139a09ep-6 -0x1.57ed287a18a0ap-3 -0x1.fb8c225b0575ap-7 -0x1.39b4affcb63bp-4 -0x1.a9cfaddd34c0cp-7 0x1.4fffffffeed7dp-5 10 64.279",
"0x1.869eb78e991c6p+0 -0x1.004239a9d28aep+0 -0x1.711de29462b92p-6 -0x1.58722e29cc767p-3 -0x1.16550a5c8528dp-6 -0x1.3b03b6be3ce92p-4 -0x1.d3a6c22377945p-7 0x1.6ffffffff6f53p-5 11 64.782",
"0x1.859e6f6564ab3p+0 -0x1.004e43d5805a6p+0 -0x1.916f4e2d12b6fp-6 -0x1.590382159cab6p-3 -0x1.2eff6aa2b1545p-6 -0x1.3c723f003ff56p-4 -0x1.fdd714b7bc66cp-7 0x1.9000000003224p-5 12 64.33",
"0x1.849e1ab0aca76p+0 -0x1.005b50c4957e2p+0 -0x1.b1ceeddc970fep-6 -0x1.59a1328f0f4cap-3 -0x1.47c7aad7fcc87p-6 -0x1.3e008fbf7c925p-4 -0x1.1434d9c3786f8p-6 0x1.b000000004788p-5 13 64.655",
"0x1.839db86d7338ep+0 -0x1.006960ed574a5p+0 -0x1.d23deb0873651p-6 -0x1.5a4b4f25842f6p-3 -0x1.60b0499f2ca91p-6 -0x1.3faef648f515ap-4 -0x1.29b3d747278a6p-6 0x1.cffffffffd82bp-5 14 65.934",
"0x1.829d47983f084p+0 -0x1.007874cf5c462p+0 -0x1.f2bd709ab30f9p-6 -0x1.5b01e8a93a2d4p-3 -0x1.79bbcbe4fc61ep-6 -0x1.417dc652943adp-4 -0x1.3f6d27b2cbba7p-6 0x1.f00000000311ep-5 15 64.868",
"0x1.819cc72d142dbp+0 -0x1.00888cf398a56p+0 -0x1.09a7558fed732p-5 -0x1.5bc5112e92ac2p-3 -0x1.92ecbd6228734p-6 -0x1.436d5a16421b5p-4 -0x1.5562f384ef754p-6 0x1.07fffffff9c8fp-4 16 64.429",
"0x1.809c3627667cep+0 -0x1.0099a9ec6c1b3p+0 -0x1.19f9647301316p-5 -0x1.5c94dc119b20cp-3 -0x1.ac45b11c2bb6dp-6 -0x1.457e126dfa8e5p-4 -0x1.6b9c978907f68p-6 0x1.18000000005e6p-4 17 65.118",
"0x1.7f9b938215cf2p+0 -0x1.00abcc55b001dp+0 -0x1.2a557d0d7ef2dp-5 -0x1.5d715df9d13fp-3 -0x1.c5c941edcc181p-6 -0x1.47b056f437d6ep-4 -0x1.821e5ff7c96b4p-6 0x1.27fffffffc329p-4 18 65.39",
"0x1.7e9ade375e48ep+0 -0x1.00bef4d4c742ap+0 -0x1.3abc387636164p-5 -0x1.5e5aacde3426cp-3 -0x1.df7a130f072f6p-6 -0x1.4a049625c398ep-4 -0x1.98ec111d7ee37p-6 0x1.3800000005926p-4 19 64.94",
"0x1.7d9a1540d593ap+0 -0x1.00d32418ae534p+0 -0x1.4b2e30d33fc86p-5 -0x1.5f50e0098f737p-3 -0x1.f95ad09eb22e6p-6 -0x1.4c7b4585fc60fp-4 -0x1.b00ac8c965ef2p-6 0x1.47fffffff9be3p-4 20 64.892",
"0x1.7c99379758aa9p+0 -0x1.00e85ada0d548p+0 -0x1.5bac016a943fdp-5 -0x1.6054101f1a64ep-3 -0x1.09b71818f2959p-5 -0x1.4f14e1c4ac981p-4 -0x1.c77f8af2a9e24p-6 0x1.580000000393cp-4 21 67.748",
"0x1.7b9844330bddep+0 -0x1.00fe99db49c9ap+0 -0x1.6c3646b1ad2eep-5 -0x1.6164571f4d893p-3 -0x1.16db78b26044ep-5 -0x1.51d1eee6a4e68p-4 -0x1.df4d9ac4c196ap-6 0x1.68000000008bep-4 22 64.168",
"0x1.7a973a0b48f84p+0 -0x1.0115e1e89abf8p+0 -0x1.7ccd9e5e88401p-5 -0x1.6281d06d1305dp-3 -0x1.241bef36b774fp-5 -0x1.54b2f873a0e64p-4 -0x1.f77bf2f15ccebp-6 0x1.7800000001812p-4 23 65.506",
"0x1.79961816995f6p+0 -0x1.012e33d81d053p+0 -0x1.8d72a77823475p-5 -0x1.63ac98d33616bp-3 -0x1.3179e65b8e077p-5 -0x1.57b891a2a8474p-4 -0x1.080657ba24afap-5 0x1.880000000b248p-4 24 64.813",
"0x1.7894dd4aad755p+0 -0x1.01479089e89e7p+0 -0x1.9e26026766e75p-5 -0x1.64e4ce8a21824p-3 -0x1.3ef6cebbf9a88p-5 -0x1.5ae3558a8e26bp-4 -0x1.14855a81806f4p-5 0x1.9800000000ff4p-4 25 65.081",
"0x1.7793889c4dcbdp+0 -0x1.0161f8e827e39p+0 -0x1.aee85108bd609p-5 -0x1.662a913df44c8p-3 -0x1.4c941f2c51075p-5 -0x1.5e33e75926448p-4 -0x1.213b9f6f2e7e8p-5 0x1.a7fffffff17b3p-4 26 64.919",
"0x1.769218ff52aeap+0 -0x1.017d6de72f22bp+0 -0x1.bfba36bd89bdp-5 -0x1.677e0214e0178p-3 -0x1.5a535509624aep-5 -0x1.61aaf285d96ecp-4 -0x1.2e2b593a9222fp-5 0x1.b7fffffffb717p-4 27 64.544",
"0x1.75908d669e9ecp+0 -0x1.0199f08594facp+0 -0x1.d09c587db9e58p-5 -0x1.68df43b5d5b8dp-3 -0x1.6835f48bd262bp-5 -0x1.65492b0f68076p-4 -0x1.3b5973ea597abp-5 0x1.c800000003818p-4 28 64.249",
"0x1.748ee4c40f636p+0 -0x1.01b781cc4cd07p+0 -0x1.e18f5cea469d6p-5 -0x1.6a4e7a4f9311ep-3 -0x1.763d8920d31cdp-5 -0x1.690f4db6cd4p-4 -0x1.48c8796c0bac3p-5 0x1.d7fffffffdaabp-4 29 64.273",
"0x1.738d1e087244bp+0 -0x1.01d622cec2209p+0 -0x1.f293ec5fd42ddp-5 -0x1.6bcbcba005163p-3 -0x1.846ba5c215174p-5 -0x1.6cfe2040ea4a9p-4 -0x1.567b0b884be47p-5 0x1.e800000002cdp-4 30 64.306",
"0x1.728b38237fc97p+0 -0x1.01f5d4aaf412dp+0 -0x1.01d55884965c6p-4 -0x1.6d575efbf886p-3 -0x1.92c1e550e9df8p-5 -0x1.711671b94ba69p-4 -0x1.6473d3e183917p-5 0x1.f7ffffffed1edp-4 31 66.891",
"0x1.71893203c6f8fp+0 -0x1.0216988994331p+0 -0x1.0a6a2b7997277p-4 -0x1.6ef15d573fdc2p-3 -0x1.a141eaf52c28fp-5 -0x1.75591abb938bbp-4 -0x1.72b5160a4507bp-5 0x1.03fffffffc5c1p-3 32 64.333",
"0x1.70870a96adc0dp+0 -0x1.02386f9e23cdp+0 -0x1.1308c60fda193p-4 -0x1.7099f14d18a22p-3 -0x1.afed627bea996p-5 -0x1.79c6fdbcfdd48p-4 -0x1.81450b731a9e9p-5 0x1.0c00000009394p-3 33 64.578",
"0x1.6f84c0c86028fp+0 -0x1.025b5b271497p+0 -0x1.1bb1804d0488ep-4 -0x1.725147290d179p-3 -0x1.bec600bf2023cp-5 -0x1.7e61075b239fp-4 -0x1.902599f661ce5p-5 0x1.140000001afe2p-3 34 64.402",
"0x1.6e825383cd1afp+0 -0x1.027f5c6de8d69p+0 -0x1.2464b3456dc13p-4 -0x1.74178cf024fa7p-3 -0x1.cdcd840ab60ebp-5 -0x1.83282eb1ebe64p-4 -0x1.9f58b59a7499p-5 0x1.1bfffffff93efp-3 35 65.679",
"0x1.6d7fc1b280c44p+0 -0x1.02a474c7599bp+0 -0x1.2d22b9277965ep-4 -0x1.75ecf26abbb0ap-3 -0x1.dd05b48621b58p-5 -0x1.881d75af61cedp-4 -0x1.aee68b1af19f9p-5 0x1.240000000724p-3 36 64.691",
"0x1.6c7d0a3cc04edp+0 -0x1.02caa59375263p+0 -0x1.35ebed44f8951p-4 -0x1.77d1a92e4f5e1p-3 -0x1.ec7064a7101a2p-5 -0x1.8d41e972e5acp-4 -0x1.becc69d166a21p-5 0x1.2c0000000e626p-3 37 64.402",
"0x1.6b7a2c0965d62p+0 -0x1.02f1f03dc7808p+0 -0x1.3ec0ac1eecacp-4 -0x1.79c5e4a82f08bp-3 -0x1.fc0f719b5a977p-5 -0x1.9296a2aab38d5p-4 -0x1.cf139a963c96ep-5 0x1.340000000273p-3 38 65.241",
"0x1.6a7725fdd5bc9p+0 -0x1.031a563d81032p+0 -0x1.47a15370afc09p-4 -0x1.7bc9da28716bfp-3 -0x1.05f261e2d7b9fp-4 -0x1.981cc5fa65a18p-4 -0x1.dfbfbba77fdf6p-5 0x1.3bfffffff95dfp-3 39 64.887",
"0x1.6973f6fdf680fp+0 -0x1.0343d9159dd8dp+0 -0x1.508e423b48b34p-4 -0x1.7dddc0ed5d97ap-3 -0x1.0df9279aafcc4p-4 -0x1.9dd58465923cp-4 -0x1.f0d2ce03a9d87p-5 0x1.440000000f922p-3 40 64.431",
"0x1.68709dec32aa8p+0 -0x1.036e7a550d25cp+0 -0x1.5987d8d0a96fep-4 -0x1.8001d22f38134p-3 -0x1.161d0a111844cp-4 -0x1.a3c21bbece4cdp-4 -0x1.012818df20cc4p-4 0x1.4bfffffffaf31p-3 41 64.408",
"0x1.676d19a94e1bcp+0 -0x1.039a3b96e0e74p+0 -0x1.628e78e0bf137p-4 -0x1.8236492cecffap-3 -0x1.1e5f0fb7dd5ddp-4 -0x1.a9e3d71bc4af6p-4 -0x1.0a1f6dd2593c5p-4 0x1.53fffffffcdd9p-3 42 64.977",
"0x1.666969147661cp+0 -0x1.03c71e8275c5fp+0 -0x1.6ba28584c398ep-4 -0x1.847b6338c4131p-3 -0x1.26c0459a58df2p-4 -0x1.b03c0f5207f82p-4 -0x1.135226a841bfcp-4 0x1.5c00000000d8cp-3 43 64.394",
"0x1.65658b0b297aep+0 -0x1.03f524cba3263p+0 -0x1.74c4634c4bf68p-4 -0x1.86d15fc5f3d4p-3 -0x1.2f41bfa442c8ep-4 -0x1.b6cc2b758d196p-4 -0x1.1cc12f7dd6dbcp-4 0x1.6400000001feap-3 44 66.033",
"0x1.64617e692a3p+0 -0x1.04245032ea9fp+0 -0x1.7df4784a2f89bp-4 -0x1.89388076a72fap-3 -0x1.37e498e85441ep-4 -0x1.bd95a160f6a9dp-4 -0x1.26704ce77d56bp-4 0x1.6c00000003b2ap-3 45 64.887",
"0x1.635d420875812p+0 -0x1.0454a285a8d14p+0 -0x1.87332c21b99f1p-4 -0x1.8bb1092a9361dp-3 -0x1.40a9f3eceb242p-4 -0x1.c499f6433ff6p-4 -0x1.30627a5c5d56cp-4 0x1.74000000006bap-3 46 64.227",
"0x1.6258d4c132bacp+0 -0x1.04861d9e48dbdp+0 -0x1.9080e81462ee2p-4 -0x1.8e3b400e33532p-3 -0x1.4992fafb1c3e8p-4 -0x1.cbdabf336ef02p-4 -0x1.3a97b45c4c021p-4 0x1.7c00000001038p-3 47 64.794",
"0x1.61543569aaa93p+0 -0x1.04b8c364782cep+0 -0x1.99de170fa5909p-4 -0x1.90d76daa903edp-3 -0x1.52a0e06c1e2d6p-4 -0x1.d359a1cdc2e3ap-4 -0x1.4515a21e5983cp-4 0x1.83fffffffa6dfp-3 48 64.796",
"0x1.604f62d634e06p+0 -0x1.04ec95cd5deeep+0 -0x1.a34b25bb8a91fp-4 -0x1.9385dcf5c7ab9p-3 -0x1.5bd4df01d79e5p-4 -0x1.db1854d5fd617p-4 -0x1.4fdd284dce08ap-4 0x1.8bfffffff7cfbp-3 49 64.788",
"0x1.5f4a5bd92e0a3p+0 -0x1.052196dbd285ap+0 -0x1.acc8828947cc5p-4 -0x1.9646db6425e44p-3 -0x1.65303a3a304dbp-4 -0x1.e318a0e3e743ep-4 -0x1.5af453ba13ccdp-4 0x1.93fffffffbe95p-3 50 65.133",
"0x1.5e451f42e9f7cp+0 -0x1.0557c8a099a78p+0 -0x1.b6569dc26b1efp-4 -0x1.991ab8f9fc63ep-3 -0x1.6eb43eae7c501p-4 -0x1.eb5c6115dd46ap-4 -0x1.665b1206461b2p-4 0x1.9c000000021d2p-3 51 65.479",
"0x1.5d3fabe1a56dep+0 -0x1.058f2d3a9e659p+0 -0x1.bff5e99873377p-4 -0x1.9c01c85e31b78p-3 -0x1.7862426dfbd5p-4 -0x1.f3e583cf00be9p-4 -0x1.721512657c562p-4 0x1.a3ffffffffc15p-3 52 64.93",
"0x1.5c3a0081755adp+0 -0x1.05c7c6d731b24p+0 -0x1.c9a6da34f05bep-4 -0x1.9efc5eed99102p-3 -0x1.823ba560faea5p-4 -0x1.fcb60b7cd79eep-4 -0x1.7e27d5c87e887p-4 0x1.abfffffff7d41p-3 53 64.455",
"0x1.5b341bec33a5bp+0 -0x1.060197b24b7cap+0 -0x1.d369e5ca30f48p-4 -0x1.a20ad4cf19dedp-3 -0x1.8c41d1b19e43p-4 -0x1.02e807b367bf3p-3 -0x1.8a94b92c5f705p-4 0x1.b40000001f6b6p-3 54 66.67",
"0x1.5a2dfce98c38p+0 -0x1.063ca216c6ap+0 -0x1.dd3f84a331e7ep-4 -0x1.a52d8508456f8p-3 -0x1.96763c3284854p-4 -0x1.079ade441fa73p-3 -0x1.975f97a8dedd6p-4 0x1.bc0000000447cp-3 55 64.437",
"0x1.5927a23ebd7cdp+0 -0x1.0678e85eafecdp+0 -0x1.e7283136e849ep-4 -0x1.a864cd93ab3dcp-3 -0x1.a0da64cf7b789p-4 -0x1.0c74ab3abeb5dp-3 -0x1.a48e869e2cc49p-4 0x1.c400000007bbcp-3 56 65.395",
"0x1.58210aaebb6d3p+0 -0x1.06b66cf38158dp+0 -0x1.f12468385dc26p-4 -0x1.abb10f76e3e79p-3 -0x1.ab6fd7015f33ap-4 -0x1.11769c265227dp-3 -0x1.b2239b0d502c5p-4 0x1.cbffffffd5295p-3 57 64.89",
"0x1.571a34f9eb46ap+0 -0x1.06f5324e76f25p+0 -0x1.fb34a8ab3949bp-4 -0x1.af12aedac7ac9p-3 -0x1.b6382a459425bp-4 -0x1.16a1ead8db744p-3 -0x1.c023bcb6ff9fbp-4 0x1.d3fffffffd461p-3 58 65.186",
"0x1.56131fde742b5p+0 -0x1.07353af8c2f65p+0 -0x1.02acb9f993d2dp-3 -0x1.b28a1322b5d6dp-3 -0x1.c1350299056c3p-4 -0x1.1bf7ddea6a254p-3 -0x1.ce923cdd7680ap-4 0x1.dbffffff06263p-3 59 64.132",
"0x1.550bca175781dp+0 -0x1.0776898c0fbffp+0 -0x1.07c9a6f7ece28p-3 -0x1.b617a708ef53p-3 -0x1.cc681101b077fp-4 -0x1.2179c94852244p-3 -0x1.dd759c6cb4961p-4 0x1.e3fffffff8859p-3 60 65.073",
"0x1.5404325db6048p+0 -0x1.07b920b27c2f3p+0 -0x1.0cf15e820f1fap-3 -0x1.b9bbd8b49cc87p-3 -0x1.d7d3140bbb35p-4 -0x1.27290ec06b53bp-3 -0x1.eccf208ae3d17p-4 0x1.ebfffffffdd3bp-3 61 65.106",
"0x1.52fc576782753p+0 -0x1.07fd03273bf8ap+0 -0x1.1224251b8743bp-3 -0x1.bd7719d9aaaecp-3 -0x1.e377d85f7b4dp-4 -0x1.2d071ea0bc28p-3 -0x1.fca7b6a10ee9p-4 0x1.f3fffffffef73p-3 62 64.193",
"0x1.51f437e808d47p+0 -0x1.084233b6c7882p+0 -0x1.176240a1e16c7p-3 -0x1.c149dfd388dcep-3 -0x1.ef583954ae3fep-4 -0x1.33157855db36cp-3 -0x1.06810859b673ep-3 0x1.fc00000002ddep-3 63 64.885",
"0x1.50ebd28fc514dp+0 -0x1.0888b53f39c35p+0 -0x1.1cabf85842846p-3 -0x1.c534a3c36f248p-3 -0x1.fb76218aae08cp-4 -0x1.3955ab14fce1bp-3 -0x1.0ef1633e7f9a8p-3 0x1.01fffffff4107p-2 64 65.314",
"0x1.4fe3260c3d6b5p+0 -0x1.08d08ab0b0357p+0 -0x1.220194f34e30bp-3 -0x1.c937e2afda2dfp-3 -0x1.03e9c5c51c4aap-3 -0x1.3fc9568e0b9edp-3 -0x1.17a8afa5d2111p-3 0x1.05ffffffff725p-2 65 64.333",
"0x1.4eda3108130a3p+0 -0x1.0919b70d9f765p+0 -0x1.276360a45315cp-3 -0x1.cd541da480a52p-3 -0x1.0a3941367a796p-3 -0x1.46722ba5f211ep-3 -0x1.20ab45e9f1575p-3 0x1.09fffffffd495p-2 66 64.315",
"0x1.4dd0f22acc672p+0 -0x1.09643d6b3d714p+0 -0x1.2cd1a72642cb2p-3 -0x1.d189d9d4ada36p-3 -0x1.10aa9149f0c3fp-3 -0x1.4d51ed3deee2cp-3 -0x1.29f804434d1dbp-3 0x1.0e0000000112cp-2 67 64.77",
"0x1.4cc76818d8ee5p+0 -0x1.09b020f1df239p+0 -0x1.324cb5c9e7706p-3 -0x1.d5d9a0be2320cp-3 -0x1.173ecd2963eb1p-3 -0x1.546a70ffa9dbep-3 -0x1.339653d6fa362p-3 0x1.120000000088ep-2 68 64.803",
"0x1.4bbd917370a87p+0 -0x1.09fd64dd635e9p+0 -0x1.37d4db833e1cp-3 -0x1.da44004e00df3p-3 -0x1.1df7155e72fa4p-3 -0x1.5bbda0396b585p-3 -0x1.3d8759c330f31p-3 0x1.1600000005ee6p-2 69 64.301",
"0x1.4ab36cd88d8ebp+0 -0x1.0a4c0c7d99782p+0 -0x1.3d6a68f6b8571p-3 -0x1.dec98b06c8e66p-3 -0x1.24d49432dc563p-3 -0x1.634d78c1dca4cp-3 -0x1.47cf249275da4p-3 0x1.19fffffffdb0fp-2 70 67.408",
"0x1.49a8f8e2c6ba4p+0 -0x1.0a9c1b36b409cp+0 -0x1.430db08790d53p-3 -0x1.e36ad8287cc54p-3 -0x1.2bd87e1afd6b1p-3 -0x1.6b1c0dea2d531p-3 -0x1.527207e23aa89p-3 0x1.1dfffffff68b3p-2 71 66.785",
"0x1.489e342943062p+0 -0x1.0aed9481b8618p+0 -0x1.48bf06661bb6bp-3 -0x1.e82883da048a9p-3 -0x1.330412245786fp-3 -0x1.732b897c6a352p-3 -0x1.5d72844e36d23p-3 0x1.220000000594ep-2 72 64.49",
"0x1.47931d3fb83abp+0 -0x1.0b407beced595p+0 -0x1.4e7ec09e4c212p-3 -0x1.ed032f5415dc1p-3 -0x1.3a589a66554c8p-3 -0x1.7b7e2cc500cc4p-3 -0x1.68d5487421308p-3 0x1.25fffffff8c03p-2 73 65.058",
"0x1.4687b2b62a177p+0 -0x1.0b94d51c619ddp+0 -0x1.544d37281bf2fp-3 -0x1.f1fb810f16e64p-3 -0x1.41d76c7d01e02p-3 -0x1.841651af5c1bfp-3 -0x1.749e1e554d3dfp-3 0x1.29fffffffd8e9p-2 74 64.219",
"0x1.457bf318fe923p+0 -0x1.0beaa3ca5b872p+0 -0x1.5a2ac3f6a7b05p-3 -0x1.f71224f163cf1p-3 -0x1.4981ea04fd46p-3 -0x1.8cf66bebca0dep-3 -0x1.80d2053353325p-3 0x1.2dffffffff087p-2 75 66.309",
"0x1.446fdcf0ce1e2p+0 -0x1.0c41ebc7e1e01p+0 -0x1.6017c3094d859p-3 -0x1.fc47cc80cfe8ep-3 -0x1.51598120e84fep-3 -0x1.96210a2aa4326p-3 -0x1.8d7523d6b86b1p-3 0x1.3200000006796p-2 76 65.603",
"0x1.43636ec2c3571p+0 -0x1.0c9ab0fd19b47p+0 -0x1.6614927a30afcp-3 -0x1.00ce9789b7a8bp-2 -0x1.595facff1a806p-3 -0x1.9f98d76081dccp-3 -0x1.9a8d055319d59p-3 0x1.35fffffe76d7bp-2 77 64.358",
"0x1.4256a70e6ccc2p+0 -0x1.0cf4f76a81efdp+0 -0x1.6c21929bfa918p-3 -0x1.03898507d8162p-2 -0x1.6195f67b606d5p-3 -0x1.a9609c3586c74p-3 -0x1.a81e94a373c9ep-3 0x1.3a0000000337cp-2 78 65.294",
"0x1.41498451c1bcep+0 -0x1.0d50c3282299fp+0 -0x1.723f25f4ae6d5p-3 -0x1.0655108771d78p-2 -0x1.69fdf496eb48dp-3 -0x1.b37b404f12143p-3 -0x1.b62e271d35ca2p-3 0x1.3e0000000115ep-2 79 64.264",
"0x1.403c0504d76d7p+0 -0x1.0dae186785edcp+0 -0x1.786db168d3e7bp-3 -0x1.09319f167b9fcp-2 -0x1.72994d36fdbc2p-3 -0x1.bdebcbf69794ap-3 -0x1.c4c1d806d56dp-3 0x1.420000006679cp-2 80 64.14",
"0x1.3f2e279c592fep+0 -0x1.0e0cfb7372c78p+0 -0x1.7ead9c406de41p-3 -0x1.0c1f991bdc1d7p-2 -0x1.7b69b5b857503p-3 -0x1.c8b5699cc0d98p-3 -0x1.d3dfd4835731ap-3 0x1.4600000002574p-2 81 64.142",
"0x1.3e1fea87ffd4ap+0 -0x1.0e6d70b107882p+0 -0x1.84ff5043dd9a4p-3 -0x1.0f1f6a7af058ap-2 -0x1.8470f3aa40cf1p-3 -0x1.d3db6794922d7p-3 -0x1.e38d72b37534cp-3 0x1.49ffffffeec05p-2 82 64.938",
"0x1.3d114c3369c94p+0 -0x1.0ecf7ca00785cp+0 -0x1.8b6339cb91509p-3 -0x1.123182b2043ffp-2 -0x1.8db0dd7d1a891p-3 -0x1.df6139d137e46p-3 -0x1.f3d28fb118fe2p-3 0x1.4dfffffff79cbp-2 83 64.509",
"0x1.3c024b05a180cp+0 -0x1.0f3323dba2f4p+0 -0x1.91d9c7d83c7bep-3 -0x1.155654fddb76ep-2 -0x1.972b5b4893674p-3 -0x1.eb4a7bc91f9a9p-3 -0x1.0259d808701cap-2 0x1.5200000001d3cp-2 84 65.555",
"0x1.3af2e56101fd3p+0 -0x1.0f986b1b23d44p+0 -0x1.98636c29b9ad9p-3 -0x1.188e587dc68e6p-2 -0x1.a0e26792aa224p-3 -0x1.f79af2738ceecp-3 -0x1.0b1d5777050d6p-2 0x1.560000000a08cp-2 85 65.086",
"0x1.39e319a321df4p+0 -0x1.0fff57329df85p+0 -0x1.9f009b569cab6p-3 -0x1.1bda085940b12p-2 -0x1.aad810287bb5ep-3 -0x1.022b472f7b545p-2 -0x1.1435ef96e434ep-2 0x1.5a00000008332p-2 86 65.123",
"0x1.38d2e624afd24p+0 -0x1.1067ed13aa36ap+0 -0x1.a5b1cce501203p-3 -0x1.1f39e3e76b01bp-2 -0x1.b50e76f8cddb4p-3 -0x1.08c0b6f47dc69p-2 -0x1.1da96aed12d03p-2 0x1.5e00000007d28p-2 87 65.343",
"0x1.37c249396449fp+0 -0x1.10d231ce1f749p+0 -0x1.ac777b63c0966p-3 -0x1.22ae6ed80c896p-2 -0x1.bf87d30411346p-3 -0x1.0f8fefcb1bd4fp-2 -0x1.277a126d5f9d7p-2 0x1.61ffffffed243p-2 88 65.571",
"0x1.36b1412fbd2e5p+0 -0x1.113e2a90e6ebp+0 -0x1.b3522485f7625p-3 -0x1.2638315f1fd13p-2 -0x1.ca46714f80104p-3 -0x1.169b3245dce6fp-2 -0x1.31ad29d34356ep-2 0x1.6600000002ac4p-2 89 65.438",
"0x1.359fcc5120892p+0 -0x1.11abdcaaae8afp+0 -0x1.ba42493cfb90dp-3 -0x1.29d7b86107a8ap-2 -0x1.d54cb5e95867p-3 -0x1.1de4d9975a5e5p-2 -0x1.3c470512e036ap-2 0x1.6a00000001124p-2 90 65.237",
"0x1.348de8e17d2d3p+0 -0x1.121b4d8ad51a5p+0 -0x1.c1486dd6a1c34p-3 -0x1.2d8d95a27fce4p-2 -0x1.e09d1cfb45733p-3 -0x1.256f5cf59ba6fp-2 -0x1.474c7a7431a45p-2 0x1.6dfffffffc06dp-2 91 67.224",
"0x1.337b951f42c49p+0 -0x1.128c82c23b213p+0 -0x1.c8651a1a7104bp-3 -0x1.315a5ff99e66fp-2 -0x1.ec3a3be8cb2dbp-3 -0x1.2d3d51121fb54p-2 -0x1.52c2ecf9123bep-2 0x1.7200000003ce6p-2 92 64.554",
"0x1.3268cf4349b4ep+0 -0x1.12ff82042105cp+0 -0x1.cf98d96862018p-3 -0x1.353eb3814fca8p-2 -0x1.f826c27e70369p-3 -0x1.355169a81a5dfp-2 -0x1.5eaef9fcfef9dp-2 0x1.7600000000a3ep-2 93 66.13",
"0x1.3155958099f49p+0 -0x1.137451271a74fp+0 -0x1.d6e43ad9b226fp-3 -0x1.393b31cfb2e4ep-2 -0x1.0232be17d2803p-2 -0x1.3dae7b23a4bf5p-2 -0x1.6b16765251bc7p-2 0x1.7a00000006068p-2 94 65.48",
"0x1.3041e6045d564p+0 -0x1.13eaf625f791dp+0 -0x1.de47d161da6fep-3 -0x1.3d50822e6454ep-2 -0x1.087ca8b2e1f5fp-2 -0x1.46577c5f73208p-2 -0x1.77ffe9c0692e4p-2 0x1.7e00000000746p-2 95 64.757",
"0x1.2f2dbef5a889dp+0 -0x1.14637720c7a0cp+0 -0x1.e5c433f1f11a3p-3 -0x1.417f51d60d62dp-2 -0x1.0ef2a471e11a1p-2 -0x1.4f4f8880efc73p-2 -0x1.8570e39bf2ea9p-2 0x1.81fffffff9609p-2 96 65.939",
"0x1.2e191e755a64ep+0 -0x1.14ddda5ddae36p+0 -0x1.ed59fd9cdbd11p-3 -0x1.45c8542c7501bp-2 -0x1.1596449c8b189p-2 -0x1.5899e0ef6fc5p-2 -0x1.936fe2cf5d3d9p-2 0x1.860000000461ep-2 97 65.092",
"0x1.2d04029e0651p+0 -0x1.155a264ac80a8p+0 -0x1.f509cdbca63d1p-3 -0x1.4a2c430559a47p-2 -0x1.1c692d251d462p-2 -0x1.6239ef690335dp-2 -0x1.a203c2875c72cp-2 0x1.89ffffffff98fp-2 98 64.625",
"0x1.2bee6983af089p+0 -0x1.15d8617d9002dp+0 -0x1.fcd4481ab0fd1p-3 -0x1.4eabdee72c22bp-2 -0x1.236d1377c6341p-2 -0x1.6c33483a54b31p-2 -0x1.b134e21ccf818p-2 0x1.8e00000000968p-2 99 65.449",
"0x1.2ad85133b22p+0 -0x1.165892b5b5bc3p+0 -0x1.025d0a8c12fffp-2 -0x1.5347ef5258369p-2 -0x1.2aa3bf562ee5fp-2 -0x1.7689ac98de76fp-2 -0x1.c1099d7f5c6e9p-2 0x1.920000000880ap-2 100 64.53",
"0x1.29c1b7b49be5cp+0 -0x1.16dac0dd6a3c1p+0 -0x1.065df0ec608d6p-2 -0x1.5801430c669cep-2 -0x1.320f0bbc7c675p-2 -0x1.81410d219a2bap-2 -0x1.d18aa81433bfep-2 0x1.960000000bb24p-2 101 65.149",
"0x1.28aa9b05f6c7ap+0 -0x1.175ef30ac53c1p+0 -0x1.0a6d3037bfef1p-2 -0x1.5cd8b06ee35a2p-2 -0x1.39b0e7d663625p-2 -0x1.8c5d8c812c1efp-2 -0x1.e2bfb8598882ap-2 0x1.9a0000000555p-2 102 65.592",
"0x1.2792f920207e8p+0 -0x1.17e5308105f7ep+0 -0x1.0e8b240681cd5p-2 -0x1.61cf15ba106acp-2 -0x1.418b57febf13dp-2 -0x1.97e38245ee89bp-2 -0x1.f4b3a47454181p-2 0x1.9dfffffff1201p-2 103 64.584",
"0x1.267acff40ffabp+0 -0x1.186d80b1e69ccp+0 -0x1.12b82a982d31ep-2 -0x1.66e5596bfb06ap-2 -0x1.49a076d2711fep-2 -0x1.a3d77de13bbcfp-2 -0x1.03b6df60552f7p-1 0x1.a1fffffff82a1p-2 104 64.788",
"0x1.25621d6b45916p+0 -0x1.18f7eb3ee6efep+0 -0x1.16f4a4ec493a2p-2 -0x1.6c1c6a9b253cep-2 -0x1.51f2764b28cap-2 -0x1.b03e49d723d2bp-2 -0x1.0d7d73ef3cb3p-1 0x1.a5fffffffe61bp-2 105 64.232",
"0x1.2448df677b8b6p+0 -0x1.198477fac1edcp+0 -0x1.1b40f6dd2b4f5p-2 -0x1.71754156eb4dap-2 -0x1.5a83a0f42536fp-2 -0x1.bd1cef264c4ebp-2 -0x1.17b1b61e45dd5p-1 0x1.aa00000013c0ep-2 106 64.982",
"0x1.232f13c29537bp+0 -0x1.1a132eead180dp+0 -0x1.1f9d873af63c3p-2 -0x1.76f0df0b9d3d7p-2 -0x1.63565b27288b3p-2 -0x1.ca78b8e485663p-2 -0x1.2259b6c3db2c2p-1 0x1.adfffffffc103p-2 107 65.42",
"0x1.2214b84e34163p+0 -0x1.1aa41848ac9dcp+0 -0x1.240abfe92a40fp-2 -0x1.7c904eed73c69p-2 -0x1.6c6d24639e7b4p-2 -0x1.d857381ccedeep-2 -0x1.2d7bae4d28ae6p-1 0x1.b1fffffff8735p-2 108 65.706",
"0x1.20f9cad3b7ef8p+0 -0x1.1b373c839d872p+0 -0x1.28890dfbd04abp-2 -0x1.8254a666e78c8p-2 -0x1.75ca98b55c2e1p-2 -0x1.e6be47e7e06afp-2 -0x1.391d6b0b11108p-1 0x1.b60000000660ap-2 109 64.689",
"0x1.1fde4914008dfp+0 -0x1.1bcca4424573ep+0 -0x1.2d18e1d6e73b1p-2 -0x1.883f058df4344p-2 -0x1.7f717230a8529p-2 -0x1.f5b411ceb8b76p-2 -0x1.4545e915705dp-1 0x1.b9fffffffc357p-2 110 64.626",
"0x1.1ec230c71572p+0 -0x1.1c6458645d9e9p+0 -0x1.31baaf4fa24dfp-2 -0x1.8e5097a00885ep-2 -0x1.89648a871558p-2 -0x1.029f893b9a313p-1 -0x1.51fd4e6462ea2p-1 0x1.bdfffffffd2dbp-2 111 64.534",
"0x1.1da57f9c0822bp+0 -0x1.1cfe6204698ffp+0 -0x1.366eedce2cc0ap-2 -0x1.948a938338544p-2 -0x1.93a6dcb50442p-2 -0x1.0ab30f505570ap-1 -0x1.5f49c0f657e1ep-1 0x1.c20000001324p-2 112 64.231",
"0x1.1c883338c5f3dp+0 -0x1.1d9aca7981d9fp+0 -0x1.3b3618713344p-2 -0x1.9aee3c4e90854p-2 -0x1.9e3b86c3483a7p-2 -0x1.13183439d0bc3p-1 -0x1.6d33b550806ccp-1 0x1.c5fffffffe7c1p-2 113 65.107",
"0x1.1b6a4939a326cp+0 -0x1.1e399b5956faap+0 -0x1.4010ae343a4b5p-2 -0x1.a17ce1db4502bp-2 -0x1.a925cbac2667cp-2 -0x1.1bd2c29ab81bcp-1 -0x1.7bc3ae1a70122p-1 0x1.c9fffffffcca1p-2 114 64.366",
"0x1.1a4bbf3156ea1p+0 -0x1.1edade7a08c53p+0 -0x1.44ff3215c6209p-2 -0x1.a837e15b113ecp-2 -0x1.b46915572ada6p-2 -0x1.24e6b9abcbcbdp-1 -0x1.8b02e447251c1p-1 0x1.cdfffffff315dp-2 115 64.557",
"0x1.192c92a8929fep+0 -0x1.1f7e9df447dbep+0 -0x1.4a022b40fce76p-2 -0x1.af20a5f9057c8p-2 -0x1.c008f6b93552bp-2 -0x1.2e58507c00449p-1 -0x1.9afa7e2db939bp-1 0x1.d1fffffffa845p-2 116 64.297",
"0x1.180cc11ddad6ep+0 -0x1.2024e42566747p+0 -0x1.4f1a25380e848p-2 -0x1.b638a9817f9fcp-2 -0x1.cc092e11ac31ap-2 -0x1.382bf968ce08ep-1 -0x1.abb50f3b4eb5p-1 0x1.d5fffffffa417p-2 117 64.662",
"0x1.16ec48052a33bp+0 -0x1.20cdbbb19c57fp+0 -0x1.5447b001897e7p-2 -0x1.bd817514a2968p-2 -0x1.d86da74fe18ecp-2 -0x1.426665d5ca597p-1 -0x1.bd3d569f9c01ep-1 0x1.d9fffffffac51p-2 118 65.365",
"0x1.15cb24c7b45dep+0 -0x1.21792f864e7c8p+0 -0x1.598b60573c5bep-2 -0x1.c4fca1e1d7566p-2 -0x1.e53a7e9c2eb2cp-2 -0x1.4d0c8a26d84bdp-1 -0x1.cf9eb2e49e323p-1 0x1.ddfffffffeb9fp-2 119 65.316",
"0x1.14a954c3a1c3bp+0 -0x1.22274adc711fcp+0 -0x1.5ee5cfd76c7bfp-2 -0x1.ccabd9eddd7dbp-2 -0x1.f274030a3f916p-2 -0x1.5823a2029f70cp-1 -0x1.e2e5bd3fac846p-1 0x1.e1ffffffed671p-2 120 64.427",
"0x1.1386d54ba021ap+0 -0x1.22d8193b1bd46p+0 -0x1.64579d3932aecp-2 -0x1.d490d8e518293p-2 -0x1.000f5cbd53864p-1 -0x1.63b134e48c64fp-1 -0x1.f71f4ea30620dp-1 0x1.e60000000d03ep-2 121 64.194",
"0x1.1263a3a6de6f8p+0 -0x1.238ba679f577bp+0 -0x1.69e16c8150fa5p-2 -0x1.dcad6cf6bf31bp-2 -0x1.071fafd274794p-1 -0x1.6fbb1afed0ff4p-1 -0x1.062cd246e6acp+0 0x1.e9fffffff9237p-2 122 65.378",
"0x1.113fbd1058181p+0 -0x1.2441fec425bd9p+0 -0x1.6f83e73cf4c6dp-2 -0x1.e50377c16692ap-2 -0x1.0e6d77af50b36p-1 -0x1.7c47827f199fap-1 -0x1.11515efa000e9p+0 0x1.edfffffffeccdp-2 123 64.334",
"0x1.101b1eb6d081p+0 -0x1.24fb2e9af69e9p+0 -0x1.753fbcbbecd64p-2 -0x1.ed94ef4811f51p-2 -0x1.15fb51068e769p-1 -0x1.895cf52da6841p-1 -0x1.1d0587127d8ep+0 0x1.f2000000019d8p-2 124 64.443",
"0x1.0ef5c5bc514efp+0 -0x1.25b742d8df698p+0 -0x1.7b15a2502a722p-2 -0x1.f663def8f95d7p-2 -0x1.1dcbfa2dfb23bp-1 -0x1.97025e7c61abp-1 -0x1.295124f7c97ccp+0 0x1.f60000000fbd8p-2 125 64.871",
"0x1.0dcfaf35ef7afp+0 -0x1.267648b481c97p+0 -0x1.8106538efc8afp-2 -0x1.ff7268c174013p-2 -0x1.25e255143683cp-1 -0x1.a53f1205d88dcp-1 -0x1.363e049e0de42p+0 0x1.f9fffffff2eabp-2 126 64.459",
"0x1.0ca8d82b329d9p+0 -0x1.27384dc402fc9p+0 -0x1.871292977235bp-2 -0x1.0461631a75b32p-1 -0x1.2e41695e9c902p-1 -0x1.b41ad28de1093p-1 -0x1.43d523412b4f6p+0 0x1.fdfffffffda81p-2 127 64.991",
"0x1.0b813d95feb08p+0 -0x1.27fd600031d0cp+0 -0x1.8d3b285994611p-2 -0x1.092ba4e089d6ap-1 -0x1.36ec66a3deb39p-1 -0x1.c39dd98242b7cp-1 -0x1.5220c8aed571fp+0 0x1.01000000034e4p-1 128 64.932",
"0x1.0a58dc620307cp+0 -0x1.28c58dc81f30cp+0 -0x1.9380e4e3c5563p-2 -0x1.0e192ffc2b85dp-1 -0x1.3fe6a6d2db80dp-1 -0x1.d3d0df143b66dp-1 -0x1.612c29c4f4832p+0 0x1.0300000001efap-1 129 64.567",
"0x1.092fb16c4224cp+0 -0x1.2990e5e4ccab4p+0 -0x1.99e49fb391779p-2 -0x1.132b4877a78dp-1 -0x1.4933b0c34cf38p-1 -0x1.e4bd22f023ae7p-1 -0x1.71026c5d36295p+0 0x1.05000000210b2p-1 130 64.738",
"0x1.0805b9830e811p+0 -0x1.2a5f778cb0eccp+0 -0x1.a067380816973p-2 -0x1.186340d59d297p-1 -0x1.52d73aed40b89p-1 -0x1.f66c759a2a931p-1 -0x1.81b0dea82a6fbp+0 0x1.06fffffffe3e3p-1 131 65.907",
"0x1.06daf164d8746p+0 -0x1.2b31526835582p+0 -0x1.a709953f5b8e5p-2 -0x1.1dc27ad8b30b3p-1 -0x1.5cd52e5ee0211p-1 -0x1.0474a14c9c252p+0 -0x1.93441d35ee076p+0 0x1.08fffffffd12bp-1 132 65.617",
"0x1.05af55c07f3edp+0 -0x1.2c06869553dc3p+0 -0x1.adcca72feaa5bp-2 -0x1.234a6850a5147p-1 -0x1.6731a9d604eddp-1 -0x1.0e1f4daaad957p+0 -0x1.a5ca92f3e11c3p+0 0x1.0afffffff48e5p-1 133 64.537",
"0x1.0482e3345ce53p+0 -0x1.2cdf24ac42f69p+0 -0x1.b4b1668e7379cp-2 -0x1.28fc8bf9e2256p-1 -0x1.71f1051f5e46bp-1 -0x1.183c2173ed5aap+0 -0x1.b953da2657c35p+0 0x1.0d000000047d6p-1 134 64.161",
"0x1.0355964e22ff3p+0 -0x1.2dbb3dc3be91fp+0 -0x1.bbb8d55408e0bp-2 -0x1.2eda7a6735779p-1 -0x1.7d17d4ab8c8e3p-1 -0x1.22d15d681aac4p+0 -0x1.cdf0460a07ee5p+0 0x1.0efffffffd1cbp-1 135 64.043",
"0x1.02276b89f6e02p+0 -0x1.2e9ae3760d62ap+0 -0x1.c2e3ff2e59306p-2 -0x1.34e5dafdda504p-1 -0x1.88aaed6c6efa7p-1 -0x1.2de5a85dbb599p+0 -0x1.e3b13364fa1bap+0 0x1.110000000775ep-1 136 64.903",
"0x1.00f85f524826dp+0 -0x1.2f7e27e5b41cp+0 -0x1.ca33f9f187fc9p-2 -0x1.3b2068fdda27cp-1 -0x1.94af68f2bf43dp-1 -0x1.398016ae983e1p+0 -0x1.faa9b4611c082p+0 0x1.13000000082ecp-1 137 64.618",
"0x1.ff90dbfe1b273p-1 -0x1.30651dc2d07fbp+0 -0x1.d1a9e613ebe54p-2 -0x1.418bf49e69d5ep-1 -0x1.a12aa9df21479p-1 -0x1.45a83245eaf41p+0 -0x1.09773cb9a0206p+1 0x1.14ffffffff1bfp-1 138 65.699",
"0x1.fd2f27aa7a344p-1 -0x1.314fd85084a52p+0 -0x1.d946ef2f29ee4p-2 -0x1.482a643b6c4bdp-1 -0x1.ae2260a554cf6p-1 -0x1.5266035748ecap+0 -0x1.164a6e9adbc78p+1 0x1.16fffffff8e73p-1 139 64.983",
"0x1.facb9a0c7f1f9p-1 -0x1.323e6b6aa34b6p+0 -0x1.e10c4c88907e6p-2 -0x1.4efdb596a51b8p-1 -0x1.bb9c90a7f68bp-1 -0x1.5fc219cf7457ep+0 -0x1.23da3ebad7332p+1 0x1.18fffffffefa1p-1 140 64.822",
"0x1.f8662b5ec66acp-1 -0x1.3330eb8b9e115p+0 -0x1.e8fb41a113e7dp-2 -0x1.5607ff2dfd8b2p-1 -0x1.c99f95b853e27p-1 -0x1.6dc597904e504p+0 -0x1.323327695a533p+1 0x1.1affffffffdfdp-1 141 64.605",
"0x1.f5fed3b239292p-1 -0x1.34276dd2e0208p+0 -0x1.f1151eceb40d7p-2 -0x1.5d4b71a996f44p-1 -0x1.d8322a010da43p-1 -0x1.7c7a3b8ea772cp+0 -0x1.4162f93f2d7fep+1 0x1.1d0000000076ep-1 142 64.87",
"0x1.f3958aecdee06p-1 -0x1.3522080b5339ep+0 -0x1.f95b41dd8e655p-2 -0x1.64ca5961633c6p-1 -0x1.e75b6c64d7ba6p-1 -0x1.8bea6de0f203p+0 -0x1.51781037f109cp+1 0x1.1effffffff385p-1 143 65.216",
"0x1.f12a48c87c719p-1 -0x1.3620d0b246484p+0 -0x1.00e78b5d6cfcep-1 -0x1.6c871ffd95c1ap-1 -0x1.f722e7589c3a3p-1 -0x1.9c214cdb2ebd2p+0 -0x1.628281f5ebe8cp+1 0x1.20fffffff6fd7p-1 144 64.963",
"0x1.eebd04d10716bp-1 -0x1.3723defeb8854p+0 -0x1.05390c15332cep-1 -0x1.74844e33f62e5p-1 -0x1.03c84c256fd27p+0 -0x1.ad2abb5072b7bp+0 -0x1.7492fc525c9d4p+1 0x1.22fffffffa3afp-1 145 64.67",
"0x1.ec4db6635e82ap-1 -0x1.382b4ae8de57fp+0 -0x1.09a2e842dac87p-1 -0x1.7cc48da2d65fap-1 -0x1.0c567bccd8972p+0 -0x1.bf13701381eb3p+0 -0x1.87bc1a64a3032p+1 0x1.250000000731ap-1 146 64.379",
"0x1.e9dc54abd005p-1 -0x1.39372d321827bp+0 -0x1.0e25ed438dd44p-1 -0x1.854aaacd98fa9p-1 -0x1.154080976fdaep+0 -0x1.d1e906db3965bp+0 -0x1.9c1185c2b850bp+1 0x1.26fffffffd2ddp-1 147 64.919",
"0x1.e768d6a3f6aa7p-1 -0x1.3a479f6d917e1p+0 -0x1.12c2f111adae7p-1 -0x1.8e19973f0cf06p-1 -0x1.1e8b1ee701bcap+0 -0x1.e5ba12ae6d533p+0 -0x1.b1a8df3f6e3c9p+1 0x1.2900000009734p-1 148 65.602",
"0x1.e4f33311af921p-1 -0x1.3b5cbc08d1f65p+0 -0x1.177ad2b620b41p-1 -0x1.97346bce79372p-1 -0x1.283b668ee128p+0 -0x1.fa9631f3b636p+0 -0x1.c898a9ed2e92dp+1 0x1.2b00000023be6p-1 149 64.303",
"0x1.e27b6085689c7p-1 -0x1.3c769e5500aefp+0 -0x1.1c4e7ac1b3cc3p-1 -0x1.a09e6b104801ap-1 -0x1.3256b8403fecep+0 -0x1.0847122da6093p+1 -0x1.e0fb01c9aaec2p+1 0x1.2d00000004ca8p-1 150 64.45",
"0x1.e001555734d6bp-1 -0x1.3d9562912adadp+0 -0x1.213edbd060431p-1 -0x1.aa5b03f878ac9p-1 -0x1.3ce2cb72f8163p+0 -0x1.13d9f16dc4c1p+1 -0x1.faea329e25c5ap+1 0x1.2f0000000b0bp-1 151 64.97",
"0x1.dd8507a66ae67p-1 -0x1.3eb925f3e4a1cp+0 -0x1.264cf30f9734bp-1 -0x1.b46dd4a410de4p-1 -0x1.47e5b4bb39c98p+0 -0x1.200d5ce8c3c3bp+1 -0x1.0b4226cc2dbc7p+2 0x1.3100000000544p-1 152 64.552",
"0x1.db066d56827a9p-1 -0x1.3fe206b6a9169p+0 -0x1.2b79c8d285425p-1 -0x1.bedaad61d719p-1 -0x1.5365ecb80ae04p+0 -0x1.2cebb2d96224cp+1 -0x1.19f45d94fc17ep+2 0x1.330000000977p-1 153 64.377",
"0x1.d8857c0de3146p-1 -0x1.41102420e572bp+0 -0x1.30c6712ba9a45p-1 -0x1.c9a593ec95d5fp-1 -0x1.5f6a578b54c8bp+0 -0x1.3a8019331375bp+1 -0x1.299d36982ccd5p+2 0x1.34fffffff260dp-1 154 64.385",
"0x1.d6022932d59a5p-1 -0x1.42439e94764e5p+0 -0x1.36340c942832dp-1 -0x1.d4d2c6eb21436p-1 -0x1.6bfa4d00a99fcp+0 -0x1.48d68eda08746p+1 -0x1.3a4f93d334639p+2 0x1.36ffffffe695dp-1 155 64.399",
"0x1.d37c69e9de86fp-1 -0x1.437c979a1cb4ap+0 -0x1.3bc3c89ad679p-1 -0x1.e066c1adeb714p-1 -0x1.791da160c712bp+0 -0x1.57fbfe7fb537bp+1 -0x1.4c1fc0685f65fp+2 0x1.38fffffff4905p-1 156 64.453",
"0x1.d0f433136c977p-1 -0x1.44bb31eeeb01ep+0 -0x1.4176e0a017767p-1 -0x1.ec6640388cb3bp-1 -0x1.86dcaf0bdc21ap+0 -0x1.67fe535c4181dp+1 -0x1.5f245c59dbd0fp+2 0x1.3b00000006762p-1 157 64.434",
"0x1.ce6979492226ep-1 -0x1.45ff91929871bp+0 -0x1.474e9e9ef2f32p-1 -0x1.f8d6439ce453ap-1 -0x1.954060f1b1f3ep+0 -0x1.78ec8ff8dce62p+1 -0x1.7375783647c67p+2 0x1.3d00000014dc2p-1 158 64.663",
"0x1.cbdc30db7524cp-1 -0x1.4749dbd66b9a8p+0 -0x1.4d4c5c02bb463p-1 -0x1.02de0b55bb9c4p+0 -0x1.a4523df3bb35dp+0 -0x1.8ad6e73fe9a5ep+1 -0x1.892d6ae0c3ec3p+2 0x1.3efffffffdc7fp-1 159 64.674",
"0x1.c94c4dce4df36p-1 -0x1.489a376d74d4ap+0 -0x1.5371828d689f5p-1 -0x1.098ea983bc81ap+0 -0x1.b41c7553e44d5p+0 -0x1.9dced81db0ceep+1 -0x1.a069740e99d3ep+2 0x1.410000000ce3ap-1 160 64.598",
"0x1.c6b9c3d759d43p-1 -0x1.49f0cc7cc78dep+0 -0x1.59bf8d496e0a5p-1 -0x1.107ff34ca96bfp+0 -0x1.c4a9ec3cf085dp+0 -0x1.b1e74be94ad62p+1 -0x1.b948d6618c791p+2 0x1.43000000151bcp-1 161 63.983",
"0x1.c424865a5bd5dp-1 -0x1.4b4dc4ada2061p+0 -0x1.60380990fe788p-1 -0x1.17b50cbdf1819p+0 -0x1.d6064c91d451ep+0 -0x1.c734b800748d4p+1 -0x1.d3ee52516cd9p+2 0x1.4500000001db6p-1 162 63.759",
"0x1.c18c8865d29f2p-1 -0x1.4cb14b406a7c6p+0 -0x1.66dc9826c62f8p-1 -0x1.1f314a31c802cp+0 -0x1.e83e151fd238ep+0 -0x1.ddcd42e5abc65p+1 -0x1.f07f495df89f3p+2 0x1.47000000074aap-1 163 64.622",
"0x1.bef1bcb0844dcp-1 -0x1.4e1b8d203e315p+0 -0x1.6daeee5febdfep-1 -0x1.26f833c35e679p+0 -0x1.fb5eab4b68097p+0 -0x1.f5c8ed433da92p+1 -0x1.0792bdb9c7c98p+3 0x1.4900000003438p-1 164 64.232",
"0x1.bc541595689bfp-1 -0x1.4f8cb8f87e796p+0 -0x1.74b0d76767a38p-1 -0x1.2f0d891164b6bp+0 -0x1.07bb373dccfe2p+1 -0x1.07a0dfafbc8b7p+2 -0x1.180701b77937cp+3 0x1.4b0000000192ep-1 165 64.058",
"0x1.b9b3851047e91p-1 -0x1.5104ff4b34aa7p+0 -0x1.7be435969c538p-1 -0x1.3775454f57ccbp+0 -0x1.124a66ad0c529p+1 -0x1.1529fdba386dep+2 -0x1.29b552e764ac3p+3 0x1.4d0000001249ap-1 166 64.134",
"0x1.b70ffcba718dp-1 -0x1.52849288b1478p+0 -0x1.834b03e68a7c3p-1 -0x1.4033a3aee1a75p+0 -0x1.1d652e929d5p+1 -0x1.238f2ac46f226p+2 -0x1.3cb8ef8ce2264p+3 0x1.4effffffec6a9p-1 167 63.577",
"0x1.b4696dc562ff1p-1 -0x1.540ba729ba7f7p+0 -0x1.8ae75781e0de9p-1 -0x1.494d2431409b6p+0 -0x1.291479ae64e2dp+1 -0x1.32e118c645cb5p+2 -0x1.51300de69c5bdp+3 0x1.50fffffffae2dp-1 168 63.778",
"0x1.b1bfc8f8617fep-1 -0x1.559a73c98e71cp+0 -0x1.92bb616c4781bp-1 -0x1.52c690d9d9187p+0 -0x1.3561e0f2bb8eap+1 -0x1.4331f424c7693p+2 -0x1.673bbfd781335p+3 0x1.530000000592p-1 169 63.7",
"0x1.af12feab06f05p-1 -0x1.573131433bfe7p+0 -0x1.9ac970524071dp-1 -0x1.5ca503606ec3bp+0 -0x1.4257bb0d74299p+1 -0x1.54958a239b463p+2 -0x1.7f004d1546b9dp+3 0x1.55000000007aep-1 170 63.59",
"0x1.ac62fec0ab9e2p-1 -0x1.58d01ad03e283p+0 -0x1.a313f279a93c1p-1 -0x1.66edeb624a635p+0 -0x1.50012d81779ddp+1 -0x1.672173ba3a00dp+2 -0x1.98a626c721398p+3 0x1.57000000053aap-1 171 63.653",
"0x1.a9afb8a3e2ee7p-1 -0x1.5a776e28e8334p+0 -0x1.ab9d77d80360fp-1 -0x1.71a71521d762ep+0 -0x1.5e6a3f857f62p+1 -0x1.7aed456197ee8p+2 -0x1.b45987806e20ep+3 0x1.590000000ff9ep-1 172 63.694",
"0x1.a6f91b41789cp-1 -0x1.5c276ba71e8f6p+0 -0x1.b468b453b210dp-1 -0x1.7cd6b0e5a90ecp+0 -0x1.6d9feeda91a38p+1 -0x1.9012c482b3248p+2 -0x1.d24bc6968d188p+3 0x1.5affffffea651p-1 173 63.595",
"0x1.a43f1501e65f5p-1 -0x1.5de0566c31dap+0 -0x1.bd7882379e5c8p-1 -0x1.88835b0c4255ep+0 -0x1.7db046e1d4137p+1 -0x1.a6ae234cfb04cp+2 -0x1.f2b322298994ap+3 0x1.5d00000001344p-1 174 63.268",
"0x1.a18193c583136p-1 -0x1.5fa274875f554p+0 -0x1.c6cfe4cf9546ep-1 -0x1.94b424d56db05p+0 -0x1.8eaa7a180e8fbp+1 -0x1.bede43abf5cf8p+2 -0x1.0ae60d2a21c22p+4 0x1.5effffffffab9p-1 175 63.343",
"0x1.9ec084dcdb422p-1 -0x1.616e0f21419d9p+0 -0x1.d0720b478218p-1 -0x1.a1709e11597a6p+0 -0x1.a09efe6d8371ep+1 -0x1.d8c502895732bp+2 -0x1.1decc2bace9c4p+4 0x1.6100000001ffap-1 176 63.384",
"0x1.9bfbd5031708p-1 -0x1.634372a8b9516p+0 -0x1.da6253bf817d1p-1 -0x1.aec0dfb44f60cp+0 -0x1.b39facabde5ddp+1 -0x1.f4878c4aa495dp+2 -0x1.3292e501f59c9p+4 0x1.6300000004bcep-1 177 62.89",
"0x1.9933705713f5cp-1 -0x1.6522ef03a2634p+0 -0x1.e4a44ea599864p-1 -0x1.bcad977769f87p+0 -0x1.c7bfe362d33c3p+1 -0x1.09275df82f11dp+3 -0x1.4901f5629cae3p+4 0x1.650000000330ap-1 178 62.991",
"0x1.966742542cdc3p-1 -0x1.670cd7c2fc64fp+0 -0x1.ef3bc2586630cp-1 -0x1.cb40149fec3dbp+0 -0x1.dd14adc7aca04p+1 -0x1.1923c325c4eaap+3 -0x1.616805ebdf193p+4 0x1.6700000007a8ep-1 179 62.826",
"0x1.939735cae7ff7p-1 -0x1.6901845aa491p+0 -0x1.fa2caf19003b6p-1 -0x1.da82560d50653p+0 -0x1.f3b4ef03e4691p+1 -0x1.2a51b97f16d0ap+3 -0x1.7bf8a595e7c32p+4 0x1.6900000000caep-1 180 62.998",
"0x1.90c334d898904p-1 -0x1.6b01505d970f5p+0 -0x1.02bda9abdde68p+0 -0x1.ea7f19b8b70adp+0 -0x1.05dcc9488a31dp+2 -0x1.3ccc92a87a329p+3 -0x1.98ed63f054b21p+4 0x1.6b000000041fp-1 181 62.77",
"0x1.8deb28df47c47p-1 -0x1.6d0c9bbe240eap+0 -0x1.0896182fcc849p+0 -0x1.fb41edc94a51p+0 -0x1.129ee11f0fe07p+2 -0x1.50b27b8dfbdfp+3 -0x1.b886c8c4d5608p+4 0x1.6d00000004f16p-1 182 62.457",
"0x1.8b0efa7c611fap-1 -0x1.6f23cb13866d8p+0 -0x1.0ea207b824cf7p+0 -0x1.066ba1bb078c3p+1 -0x1.202f91571e00ap+2 -0x1.6624d4434b0c4p+3 -0x1.db0cf573fdcfep+4 0x1.6f0000000d3eap-1 183 62.484",
"0x1.882e917f7d5f5p-1 -0x1.714747e450ae1p+0 -0x1.14e403a64884bp+0 -0x1.0fa641f21ded8p+1 -0x1.2e9f0b90c751dp+2 -0x1.7d4893d5f97c9p+3 -0x1.00688b3928679p+5 0x1.70fffffffba87p-1 184 62.33",
"0x1.8549d4df7ed47p-1 -0x1.737780f775926p+0 -0x1.1b5ec1289036ap+0 -0x1.195813a5a6f16p+1 -0x1.3dff06ce8bed1p+2 -0x1.9646b9f33d3b1p+3 -0x1.151732ee4c78ep+5 0x1.7300000001896p-1 185 62.334",
"0x1.8260aab0a4d53p-1 -0x1.75b4eaaa78e78p+0 -0x1.2215228b4bd63p+0 -0x1.2388e74a721fep+1 -0x1.4e62ea3eb6f2cp+2 -0x1.b14cd06f5975fp+3 -0x1.2bc5c53ce5dep+5 0x1.7500000000ba8p-1 186 62.142",
"0x1.7f72f819da81ap-1 -0x1.77ffff4e90137p+0 -0x1.290a3adaa9d69p+0 -0x1.2e412fe94c73p+1 -0x1.5fdffd6c0343bp+2 -0x1.ce8d7f39676b3p+3 -0x1.44ae43cd8dadbp+5 0x1.76fffffefa109p-1 187 61.953",
"0x1.7c80a1413e209p-1 -0x1.7a593f93c2a1bp+0 -0x1.304151f251a6ep+0 -0x1.398a13124abaep+1 -0x1.728d9ed14eac2p+2 -0x1.ee41360544b04p+3 -0x1.60122bb27ff5dp+5 0x1.78ffffffee08bp-1 188 61.82",
"0x1.7989894d80aa7p-1 -0x1.7cc132eb4a884p+0 -0x1.37bde8bd19f81p+0 -0x1.456d7a4dd7912p+1 -0x1.868580fd6de2ep+2 -0x1.085376f69fa61p+4 -0x1.7e3bb49161a68p+5 0x1.7afffffffce25p-1 189 61.755",
"0x1.768d9249c5ce6p-1 -0x1.7f386809bc4fbp+0 -0x1.3f83be29922a7p+0 -0x1.51f62704542dap+1 -0x1.9be3f08a35933p+2 -0x1.1b0284955276ap+4 -0x1.9f7eed5208dcap+5 0x1.7d00000001c2cp-1 190 61.66",
"0x1.738c9d1d679cep-1 -0x1.81bf7562d8fefp+0 -0x1.4796d46955bap+0 -0x1.5f2fc86964e14p+1 -0x1.b2c822edad027p+2 -0x1.2f5529ded2291p+4 -0x1.c43b83d4762a9p+5 0x1.7efffffff90dbp-1 191 61.485",
"0x1.71f93c6d63c51p+0 -0x1.0fa989278b9e8p-3 0x1.12e5718944089p-5 -0x1.7279ee5dcae5bp-7 0x1.1e4f5193c9038p-8 -0x1.df9bd40debb84p-10 0x1.80fffffffc78bp-1 192 66.95",
"0x1.71d74fd079481p+0 -0x1.0f205bc1b6ea9p-3 0x1.11d06c3c0254p-5 -0x1.703fa55440ee2p-7 0x1.1bfae59d98d05p-8 -0x1.daad1b6208ad8p-10 0x1.83000000c4c04p-1 193 66.82",
"0x1.71b57450b185bp+0 -0x1.0e97b8744d4e9p-3 0x1.10bd10e8918b1p-5 -0x1.6e09fefffe701p-7 0x1.19ac9a3a4d121p-8 -0x1.d5ce14b42d997p-10 0x1.85000000081aep-1 194 67.683",
"0x1.7193a9dcb1183p+0 -0x1.0e0f9e6a97d75p-3 0x1.0fab5c184b761p-5 -0x1.6bd8ef30f0a88p-7 0x1.17645bed0ee29p-8 -0x1.d0fe85712628dp-10 0x1.86ffffffff97dp-1 195 66.726",
"0x1.7171f06367b2p+0 -0x1.0d880cd25cbc6p-3 0x1.0e9b4a5f2a742p-5 -0x1.69ac69e0dff6ep-7 0x1.1522178791ebcp-8 -0x1.cc3e3404d5cbdp-10 0x1.8900000004e0ep-1 196 66.731",
"0x1.715047d3d6663p+0 -0x1.0d0102daf2776p-3 0x1.0d8cd859d7a3fp-5 -0x1.6784632f1ad8cp-7 0x1.12e5ba1c65e02p-8 -0x1.c78ce7cc40d3bp-10 0x1.8afffffff68c1p-1 197 66.352",
"0x1.712eb01d12eabp+0 -0x1.0c7a7fb5498acp-3 0x1.0c8002adabadp-5 -0x1.6560cf60253d3p-7 0x1.10af310c6e4f7p-8 -0x1.c2ea691c94f3dp-10 0x1.8d00000004792p-1 198 66.218",
"0x1.710d292e52438p+0 -0x1.0bf4829413bf8p-3 0x1.0b74c608ea2edp-5 -0x1.6341a2dddfad5p-7 0x1.0e7e69f7eb7cfp-8 -0x1.be568130d1fbbp-10 0x1.8f0000000a53ep-1 199 67.838",
"0x1.70ebb2f6e1063p+0 -0x1.0b6f0aaba1958p-3 0x1.0a6b1f2269a99p-5 -0x1.6126d23682ca7p-7 0x1.0c5352c06ae07p-8 -0x1.b9d0fa3003b57p-10 0x1.910000000210ep-1 200 67.086",
"0x1.70ca4d66233aep+0 -0x1.0aea1731de627p-3 0x1.09630ab979518p-5 -0x1.5f10521c1b03p-7 0x1.0a2dd99306652p-8 -0x1.b5599f23eee8cp-10 0x1.9300000002ee8p-1 201 67.344",
"0x1.70a8f86b98b8p+0 -0x1.0a65a75e5e42fp-3 0x1.085c8595ea73cp-5 -0x1.5cfe17644d71p-7 0x1.080decd700a23p-8 -0x1.b0f03bf5ff7d7p-10 0x1.94fffffffb9a7p-1 202 66.677",
"0x1.7087b3f6d7d5p+0 -0x1.09e1ba6a459b4p-3 0x1.07578c87cdba6p-5 -0x1.5af0170783f1fp-7 0x1.05f37b3589c31p-8 -0x1.ac949d6dc2bc7p-10 0x1.970000000060ep-1 203 67.396",
"0x1.70667ff7922dcp+0 -0x1.095e4f9058abfp-3 0x1.06541c678040bp-5 -0x1.58e64620bc027p-7 0x1.03de739bfc68dp-8 -0x1.a8469126fb4afp-10 0x1.98fffffffef0bp-1 204 66.631",
"0x1.70455c5d9026ep+0 -0x1.08db660ce6793p-3 0x1.055232157043dp-5 -0x1.56e099ecc4d3fp-7 0x1.01cec52ee141ep-8 -0x1.a405e5924f077p-10 0x1.9b0000000043ep-1 205 67.752",
"0x1.70244918b34fcp+0 -0x1.0858fd1dcefa9p-3 0x1.0451ca7a1816cp-5 -0x1.54df07c9ec259p-7 0x1.ff88bea8b557fp-9 -0x1.9fd269eea7691p-10 0x1.9d00000000f12p-1 206 66.994",
"0x1.70034618f5379p+0 -0x1.07d714027b41cp-3 0x1.0352e285dd99p-5 -0x1.52e185377503bp-7 0x1.fb7e6360fe01ep-9 -0x1.9babee4b4029dp-10 0x1.9f000000002ep-1 207 67.239",
"0x1.6fe2534e65ee6p+0 -0x1.0755a9fbd46d7p-3 0x1.02557730efacbp-5 -0x1.50e807d50c06ap-7 0x1.f77e5841a33d9p-9 -0x1.9792437a8083ap-10 0x1.a1000000142p-1 208 66.531",
"0x1.6fc170a932b07p+0 -0x1.06d4be4c5ab01p-3 0x1.0159857b62acfp-5 -0x1.4ef28562ba57ap-7 0x1.f3887d73c6525p-9 -0x1.93853b12e12c9p-10 0x1.a2ffffffff323p-1 209 66.755",
"0x1.6fa09e1997e16p+0 -0x1.06545037eb32dp-3 0x1.005f0a6cae6adp-5 -0x1.4d00f3bf9e2edp-7 0x1.ef9cb3a43717p-9 -0x1.8f84a76f8707fp-10 0x1.a5000000073dep-1 210 66.42",
"0x1.6f7fdb8ff0e27p+0 -0x1.05d45f03fb1ddp-3 0x1.fecc062822f4p-6 -0x1.4b1348ea6d3e2p-7 0x1.ebbadbe1c07f7p-9 -0x1.8b905ba6835adp-10 0x1.a6fffffffc25bp-1 211 67.332",
"0x1.6f5f28fcab6a7p+0 -0x1.0554e9f762fdp-3 0x1.fcdcd910353a2p-6 -0x1.49297b0046b7cp-7 0x1.e7e2d7b06bab5p-9 -0x1.87a82b8778d77p-10 0x1.a8fffffffa327p-1 212 67.17",
"0x1.6f3e86504d97dp+0 -0x1.04d5f05a73871p-3 0x1.faf087cd83668p-6 -0x1.4743803ca3dap-7 0x1.e4148902cd102p-9 -0x1.83cbeb986ff65p-10 0x1.ab000000089e6p-1 213 67.462",
"0x1.6f1df37b7785fp+0 -0x1.04577176f8be7p-3 0x1.f9070caabc668p-6 -0x1.45614ef904aacp-7 0x1.e04fd2364b74dp-9 -0x1.7ffb7114af63dp-10 0x1.acfffffffda2fp-1 214 66.907",
"0x1.6efd706edaac7p+0 -0x1.03d96c98157d8p-3 0x1.f7206200a2bf4p-6 -0x1.4382ddac07b1dp-7 0x1.dc94960f33bdp-9 -0x1.7c3691e339aecp-10 0x1.af00000003316p-1 215 66.689",
"0x1.6edcfd1b440abp+0 -0x1.035be10a6812ap-3 0x1.f53c82367c3e9p-6 -0x1.41a822e999fbbp-7 0x1.d8e2b7c04364bp-9 -0x1.787d249add6d1p-10 0x1.b0fffffff4577p-1 216 66.811",
"0x1.6ebc9971913b1p+0 -0x1.02dece1bdd1p-3 0x1.f35b67c145f23p-6 -0x1.3fd11561f1845p-7 0x1.d53a1adf0498fp-9 -0x1.74cf007c9f96bp-10 0x1.b300000006976p-1 217 67.247",
"0x1.6e9c4562bce7ap+0 -0x1.0262331bdca46p-3 0x1.f17d0d2445aeap-6 -0x1.3dfdabe1dfd74p-7 0x1.d19aa36805fbap-9 -0x1.712bfd6c485d2p-10 0x1.b5000000028f8p-1 218 67.03",
"0x1.6e7c00dfd2646p+0 -0x1.01e60f5b17ea7p-3 0x1.efa16cf02a351p-6 -0x1.3c2ddd51bba8ap-7 0x1.ce0435b62894ep-9 -0x1.6d93f3f1f0543p-10 0x1.b7000000052p-1 219 67.149",
"0x1.6e5bcbd9f4eep+0 -0x1.016a622ba2236p-3 0x1.edc881c34feeep-6 -0x1.3a61a0b56a123p-7 0x1.ca76b68d0ce06p-9 -0x1.6a06bd3b3a14p-10 0x1.b90000000a39cp-1 220 67.338",
"0x1.6e3ba6425edefp+0 -0x1.00ef2ae0eae1p-3 0x1.ebf246498e5a4p-6 -0x1.3898ed2bf3c2ap-7 0x1.c6f20b0de6a64p-9 -0x1.6684330da1d9bp-10 0x1.bafffffff683bp-1 221 68.184",
"0x1.6e1b900a5a905p+0 -0x1.007468cfa00edp-3 0x1.ea1eb53baa2cep-6 -0x1.36d3b9eec2e4fp-7 0x1.c37618b84c80ap-9 -0x1.630c2fc9fc55p-10 0x1.bd00000006378p-1 222 69.345",
"0x1.6dfb89234e8ddp+0 -0x1.fff4369bb4117p-4 0x1.e84dc95fe24adp-6 -0x1.3511fe51f47fcp-7 0x1.c002c56995215p-9 -0x1.5f9e8e6e511ep-10 0x1.bf000000080d4p-1 223 67.658",
"0x1.6ddb917eb3508p+0 -0x1.ff008365e33e6p-4 0x1.e67f7d8934c9fp-6 -0x1.3353b1c36c67bp-7 0x1.bc97f75825b5cp-9 -0x1.5c3b2a877b81ep-10 0x1.c0fffffffe3c1p-1 224 68.43",
"0x1.6dbba90e13891p+0 -0x1.fe0db6aefd6a9p-4 0x1.e4b3cc973faa2p-6 -0x1.3198cbca81b7fp-7 0x1.b9359519013d6p-9 -0x1.58e1e0376e6cp-10 0x1.c300000017b4p-1 225 66.926",
"0x1.6d9bcfc31739cp+0 -0x1.fd1bcf2affcdap-4 0x1.e2eab176bcc6cp-6 -0x1.2fe14408413aap-7 0x1.b5db859b6eef1p-9 -0x1.55928c33413adp-10 0x1.c4fffffffb533p-1 226 67.063",
"0x1.6d7c058f6fabfp+0 -0x1.fc2acb901799p-4 0x1.e12427203e2ebp-6 -0x1.2e2d123601c35p-7 0x1.b289b01dad58p-9 -0x1.524d0bb7aa9b4p-10 0x1.c70000000725cp-1 227 69.83",
"0x1.6d5c4a64eb89bp+0 -0x1.fb3aaa9735b61p-4 0x1.df6028992c1e8p-6 -0x1.2c7c2e26255f4p-7 0x1.af3ffc3d936e3p-9 -0x1.4f113c93cd1f2p-10 0x1.c90000000afp-1 228 66.688",
"0x1.6d3c9e356adc1p+0 -0x1.fa4b6afbae969p-4 0x1.dd9eb0f2f62aap-6 -0x1.2ace8fc3200bdp-7 0x1.abfe51e903dep-9 -0x1.4bdefd185a769p-10 0x1.cb000000069d4p-1 229 66.781",
"0x1.6d1d00f2e3d2ap+0 -0x1.f95d0b7b5983ap-4 0x1.dbdfbb4b3590ep-6 -0x1.29242f0f670ccp-7 0x1.a8c49961d706dp-9 -0x1.48b62c1fbb358p-10 0x1.ccffffffdab99p-1 230 66.632",
"0x1.6cfd728f57671p+0 -0x1.f86f8ad63635fp-4 0x1.da2342caeb86dp-6 -0x1.277d0424876f2p-7 0x1.a592bb3bbc436p-9 -0x1.4596a9079e557p-10 0x1.cefffffffe2d1p-1 231 67.801",
"0x1.6cddf2fce8cddp+0 -0x1.f782e7cf189dap-4 0x1.d86942a7aaf4bp-6 -0x1.25d9073411a53p-7 0x1.a268a06075d58p-9 -0x1.428053afdd73p-10 0x1.d0ffffffffcb7p-1 232 66.661",
"0x1.6cbe822dc67a3p+0 -0x1.f697212af6f8ep-4 0x1.d6b1b622336bdp-6 -0x1.2438308615e39p-7 0x1.9f4632000f065p-9 -0x1.3f730c759eb2cp-10 0x1.d2fffffff8613p-1 233 68.561",
"0x1.6c9f201432a22p+0 -0x1.f5ac35b125683p-4 0x1.d4fc9886c99f3p-6 -0x1.229a78794a279p-7 0x1.9c2b59a1fbc59p-9 -0x1.3c6eb43676924p-10 0x1.d4fffffffe829p-1 234 67.111",
"0x1.6c7fcca286aafp+0 -0x1.f4c2242b6adccp-4 0x1.d349e52d4717ap-6 -0x1.20ffd782eafb8p-7 0x1.9918011615bc1p-9 -0x1.39732c46b55d7p-10 0x1.d6ffffffec17bp-1 235 67.524",
"0x1.6c6087cb29418p+0 -0x1.f3d8eb65b2754p-4 0x1.d19997787148ap-6 -0x1.1f68462dee925p-7 0x1.960c12776bf74p-9 -0x1.368056757a8e7p-10 0x1.d8fffffffdc37p-1 236 68.433",
"0x1.6c4151809b324p+0 -0x1.f2f08a2e66ea4p-4 0x1.cfebaad68cd8ap-6 -0x1.1dd3bd1b6361ep-7 0x1.9307783279516p-9 -0x1.3396150c35cep-10 0x1.dafffffffe8afp-1 237 67.074",
"0x1.6c2229b56bc1ep+0 -0x1.f208ff561717cp-4 0x1.ce401ac09dcb7p-6 -0x1.1c4235018f579p-7 0x1.900a1cf371299p-9 -0x1.30b44abfbe7b8p-10 0x1.dd00000004228p-1 238 67.507",
"0x1.6c03105c3fb8bp+0 -0x1.f12249afa616cp-4 0x1.cc96e2baaac6ap-6 -0x1.1ab3a6ac04284p-7 0x1.8d13ebb84516p-9 -0x1.2ddadac03227dp-10 0x1.defffffff9323p-1 239 67.417",
"0x1.6be40567cbc8bp+0 -0x1.f03c68101d418p-4 0x1.caeffe53529ep-6 -0x1.19280afb10e73p-7 0x1.8a24cfc32e37fp-9 -0x1.2b09a8a98a8d4p-10 0x1.e0fffffff7195p-1 240 69.163",
"0x1.6bc508cad8c84p+0 -0x1.ef57594ec74e8p-4 0x1.c94b6923e919ep-6 -0x1.179f5ae3b3467p-7 0x1.873cb49a058afp-9 -0x1.2840988971172p-10 0x1.e2fffffffe1d7p-1 241 67.258",
"0x1.6ba61a784300fp+0 -0x1.ee731c4526d7ap-4 0x1.c7a91ed050647p-6 -0x1.16198f6f4a30ap-7 0x1.845b860cef905p-9 -0x1.257f8ed783e0cp-10 0x1.e4fffffffe605p-1 242 67.616",
"0x1.6b873a62f7b52p+0 -0x1.ed8fafcedfd4fp-4 0x1.c6091b06bb024p-6 -0x1.1496a1bb335b5p-7 0x1.8181302adce42p-9 -0x1.22c670778b71cp-10 0x1.e6fffffffe98fp-1 243 68.171",
"0x1.6b68687df638fp+0 -0x1.ecad12c9bb975p-4 0x1.c46b597f9ec6ep-6 -0x1.13168af8974b9p-7 0x1.7ead9f49835ebp-9 -0x1.201522b5672afp-10 0x1.e900000007c9ep-1 244 72.216",
"0x1.6b49a4bc4fb6p+0 -0x1.ebcb4415a2f0cp-4 0x1.c2cfd5fd96014p-6 -0x1.1199446c255f4p-7 0x1.7be0c0028a30fp-9 -0x1.1d6b8b470eb93p-10 0x1.eb00000026f7cp-1 245 68.179",
"0x1.6b2aef112d00ep+0 -0x1.eaea4294c4d8ap-4 0x1.c1368c4d91cc1p-6 -0x1.101ec76e1b77p-7 0x1.791a7f2f3835ep-9 -0x1.1ac990460631fp-10 0x1.ed00000009a3p-1 246 69.91",
"0x1.6b0c476fbe603p+0 -0x1.ea0a0d2b1b796p-4 0x1.bf9f7845e6a74p-6 -0x1.0ea70d693e964p-7 0x1.765ac9e3dffd1p-9 -0x1.182f182c2427p-10 0x1.ef00000009eb2p-1 247 69.004",
"0x1.6aedadcb4d608p+0 -0x1.e92aa2beeaea9p-4 0x1.be0a95c71fc7ap-6 -0x1.0d320fdb78e7dp-7 0x1.73a18d7c2fff8p-9 -0x1.159c09dd51cedp-10 0x1.f1000000035e2p-1 248 68.261",
"0x1.6acf221732c71p+0 -0x1.e84c023873904p-4 0x1.bc77e0bb5eb3dp-6 -0x1.0bbfc85520676p-7 0x1.70eeb78ead8adp-9 -0x1.13104c96b09ccp-10 0x1.f2fffffff84fbp-1 249 68.02",
"0x1.6ab0a446d8578p+0 -0x1.e76e2a81fb3cfp-4 0x1.bae75516591d6p-6 -0x1.0a503078d0ap-7 0x1.6e4235ef1b0f1p-9 -0x1.108bc7f6b7ce9p-10 0x1.f4fffffff243dp-1 250 68.024",
"0x1.6a92344db8424p+0 -0x1.e6911a87c53d3p-4 0x1.b958eed537f21p-6 -0x1.08e341fb28929p-7 0x1.6b9bf6aaea58p-9 -0x1.0e0e63fb4c524p-10 0x1.f70000000970ap-1 251 68.899",
"0x1.6a73d21f61d8p+0 -0x1.e5b4d13830a31p-4 0x1.b7cca9febb7c7p-6 -0x1.0778f6a2c8577p-7 0x1.68fbe8132a293p-9 -0x1.0b9808f9b60c4p-10 0x1.f90000001379p-1 252 68.528",
"0x1.6a557daf74927p+0 -0x1.e4d94d8390583p-4 0x1.b64282a2e11b8p-6 -0x1.06114847db6b8p-7 0x1.6661f8a9de40fp-9 -0x1.09289fa315b09p-10 0x1.fafffffff4a35p-1 253 71.829",
"0x1.6a3736f19a9c5p+0 -0x1.e3fe8e5bfff7fp-4 0x1.b4ba74da84296p-6 -0x1.04ac30d39fd77p-7 0x1.63ce173306a02p-9 -0x1.06c01103127f8p-10 0x1.fcfffffffa751p-1 254 70.154",
"0x1.6a18fde8aede9p+0 -0x1.e32493228aa7ep-4 0x1.b3347d8a64a17p-6 -0x1.0349aaf167477p-7 0x1.614033ed086e9p-9 -0x1.045e47a89e4cp-10 0x1.fefffeffffb0fp-1 255 69.757",
]

