#load("../../generic/support/common.sage")
# T1()
# maxerr= 3.3447210326662894e-30
# (0.982666015625000, 1.01684570312500)
def T1(xmin=0.7109375,xmax=1.421874,p=6):
   Rp = RealField(p)
   Zmin = 1
   Zmax = 1
   imin = floor((xmin-1)*128)
   imax = floor((xmax-1)*64)
   print ("imin=", imin, "imax=", imax)
   Err = 0
   print ("static const double T1[64][3] = {")
   for i in [imin..imax]:
      if i >= 0:
         xmin = RR(1 + i/64)
         xmax = RR(1 + (i+1)/64)
      else:
         xmin = RR(1 + i/128)
         xmax = RR(1 + (i+1)/128)
      rmin = Rp(1/xmax.exact_rational())
      rmax = Rp(1/xmin.exact_rational())
      r = rmin
      zbest = infinity
      while r<=rmax:
         zmin = abs(RR(r)*xmin-1)
         zmax = abs(RR(r)*xmax-1)
         z = max(zmin,zmax) # maximal distance to 1
         if (z<zbest) or (z==zbest and r==1):
            zbest = z
            rbest = r
         r = r.nextabove()
      Zmin = min(Zmin,RR(rbest)*xmin)
      Zmax = max(Zmax,RR(rbest)*xmax)
      X = rbest.exact_rational()
      # we want h multiple of 2^-38 so that e+h is exact, where
      # -16445 <= e < 16384
      e = -log(X)/log(2)
      h = RR(round(e*2^38)/2^38)
      H = h.exact_rational()
      l = RR(n(e-H,200))
      L = l.exact_rational()
      err = abs(n(H+L-e,200))
      Err = max(Err,err)
      print ("   {" + get_hex(rbest) + ", " + get_hex(h) + ", " + get_hex(l) + "}, /* i=" + str(i) + " */")
   print ("};")
   print ("maxerr=", float(err))
   return Zmin, Zmax

# T2()
# maxerr= 4.057340372917331e-29
# (0.999755859375000, 1.00024402141571)
def T2(xmin=0.982666015625000,xmax=1.016845703125,p=21):
   R = RealField(p)
   Zmin = 1
   Zmax = 1
   imin = floor((xmin-1)*2^12)
   imax = floor((xmax-1)*2^11)
   print ("imin=", imin, "imax=", imax)
   Err = 0
   print ("static const double T2[" + str(imax-imin+1) + "][3] = {")
   for i in [imin..imax]:
      if i >= 0:
         xmin = RR(1 + i/2^11)
         xmax = RR(1 + (i+1)/2^11)
      else:
         xmin = RR(1 + i/2^12)
         xmax = RR(1 + (i+1)/2^12)
      # we want |r*xmin-1| = |r*xmax-1|
      # thus 1 - r*xmin = r*xmax - 1
      # thus r = 2/(xmax + xmin)
      r = R(2 / (xmax + xmin))
      Zmin = min(Zmin,RR(r)*xmin)
      Zmax = max(Zmax,RR(r)*xmax)
      X = r.exact_rational()
      # we want h multiple of 2^-38 so that e+h is exact, where
      # -16445 <= e < 16384
      e = -log(X)/log(2)
      h = RR(round(e*2^38)/2^38)
      H = h.exact_rational()
      l = RR(n(e-H,200))
      L = l.exact_rational()
      err = abs(n(H+L-e,200))
      Err = max(Err,err)
      print ("   {" + get_hex(r) + ", " + get_hex(h) + ", " + get_hex(l) + "}, /* i=" + str(i) + " */")
   print ("};")
   print ("maxerr=", float(err))
   return Zmin, Zmax

# T1T2(6,21)
# (0.999755859375000, 1.00024402141571, 53)
def T1T2(p1,p2):
   # xh is multiple of 2^-38
   xmin, xmax = T1(p=p1)
   # r1 is multiple of 2^-p1 thus r1*xh is multiple of 2^(-38-p1)
   xmin, xmax = T2(xmin=xmin, xmax=xmax, p=p2)
   # r2 is multiple of 2^-p2 thus r2*xh is multiple of 2^(-38-p1-p2)
   e = max(1-xmin,xmax-1)
   return xmin, xmax, ceil(log(e/2^(-38-p1-p2))/log(2))
   
# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

def a_mul_double(a,b):
   h = a*b
   u = RIFulp(h)
   l = RIF(-u,u)
   return h, l

# analyzeP()
# err1= -129.722454159758
# err2= -113.999693586040
# err3= -113.999968548661
# err4= -89.9994919427438
# err5= -89.9999998014668
# err6= -89.0559319350096
# err7= -126.678071905112
# err8= -116.471057498903
# err9= -114.999999999999
# err10= -113.651741433865
# err= -84.3929034798149
# lmax= 1.91630753487530e-19
def analyzeP():
   err0 = 2^-84.514 # absolute error of the minimax polynomial
   p1h = RR("0x1.71547652b82fep+0",16)
   p1l = RR("0x1.777d10fa9419cp-56",16)
   p2 = RR("-0x1.71547652b82fep-1",16)
   p3 = RR("0x1.ec709dc3a03fbp-2",16)
   p4 = RR("-0x1.71547661d011fp-2",16)
   p5 = RR("0x1.2776c56eb6ca2p-2",16)
   p6 = RR("-0x1.bd761baf2853cp-3",16)
   p7 = RR("0x1.24996255a29ecp-3",16)
   p8 = RR("-0x1.6c9c75469b616p17",16)
   xh = RIF(-0.000244140625,0.00024402141571)
   xl = RIF(-2^-64,2^-64)
   x = xh+xl
   # xx = xh * xh
   xx = xh^2
   err_xx = 2*xh*xl + xl^2
   # c7 = __builtin_fma (p[8], xh, p[7])
   c7 = p8*xh+p7
   err1 = (RIFulp(c7)+(p8*xl).abs().upper())*x.abs().upper()^7
   print ("err1=", log(err1)/log(2.))
   # c5 = __builtin_fma (p[6], xh, p[5])
   c5 = p6*xh+p5
   err2 = (RIFulp(c5)+(p6*xl).abs().upper())*x.abs().upper()^5
   print ("err2=", log(err2)/log(2.))
   # c5 = __builtin_fma (c7, xx, c5)
   c5 = c7*xx+c5
   err3 = (RIFulp(c5)+(c7*err_xx).abs().upper())*x.abs().upper()^5
   print ("err3=", log(err3)/log(2.))
   # c3 = __builtin_fma (p[4], xh, p[3])
   c3 = p4*xh+p3
   err4 = (RIFulp(c3)+(p4*xl).abs().upper())*x.abs().upper()^3
   print ("err4=", log(err4)/log(2.))
   # c3 = __builtin_fma (c5, xx, c3)
   c3 = c5*xx+c3
   err5 = (RIFulp(c3)+(c5*err_xx).abs().upper())*x.abs().upper()^3
   print ("err5=", log(err5)/log(2.))
   # fast_two_sum_double (h, l, p[2], c3*xh)
   h = p2+c3*xh
   u = RIFulp(h)
   l = RIF(-u,u)
   err6a = (c3*xl).abs().upper() # neglecting xl
   err6b = h.abs().upper()*2^-105 # fast_two_sum error
   err6 = (err6a+err6b)*x.abs().upper()^2
   print ("err6=", log(err6)/log(2.))
   # d_mul_double (h, l, *h, *l, xh, xl)
   #      a_mul_double (h, &s, h_in, xh) [exact]
   #      t = fma (l_in, xh, s)
   #      l = fma (h_in, xl, t)
   h_in = h
   l_in = l
   h, s = a_mul_double (h_in, xh)
   t = l_in*xh+s
   l = h_in*xl+t
   err7 = ((l_in*xl).abs().upper()+RIFulp(t)+RIFulp(l))*x.abs().upper()
   print ("err7=", log(err7)/log(2.))
   # fast_two_sum_double (h, &t, p[0], *h)
   h = p1h+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err8 = h.abs().upper()*2^-105*x.abs().upper()
   print ("err8=", log(err8)/log(2.))
   # *l += t + p[1]
   t += p1l
   l += t
   err9 = (RIFulp(t)+RIFulp(l))*x.abs().upper()
   print ("err9=", log(err9)/log(2.))
   # d_mul_double (h, l, *h, *l, xh, xl)
   #      a_mul_double (h, &s, h_in, xh) [exact]
   #      t = fma (l_in, xh, s)
   #      l = fma (h_in, xl, t)
   h_in = h
   l_in = l
   h, s = a_mul_double (h_in, xh)
   t = l_in*xh+s
   l = h_in*xl+t
   err10 = (l_in*xl).abs().upper()+RIFulp(t)+RIFulp(l)
   print ("err10=", log(err10)/log(2.))
   err = err0+err1+err2+err3+err4+err5+err6+err7+err8+err9+err10
   print ("err=", log(err)/log(2.))
   print ("lmax=", l.abs().upper())

# T1acc()
# (0.00775241851806640614, 0.992248535156250000, 1.00775241851806641)
def T1acc():
   print ("static const long double T1acc[64][3] = {")
   maxerr = 0
   Zmin = Zmax = 1
   for i in [-37..26]:
      if i >= 0:
         xmin = R64(1 + i/64)
         xmax = R64(1 + (i+1)/64).nextbelow()
      else:
         xmin = R64(1 + i/128)
         xmax = R64(1 + (i+1)/128).nextbelow()
      inv = R64(2)/(xmin+xmax)
      e = -17
      xl = R64(floor(inv/2^e)*2^e)
      xh = R64(ceil(inv/2^e)*2^e)
      zl = max(abs(xl*xmin-1),abs(xl*xmax-1))
      zh = max(abs(xh*xmin-1),abs(xh*xmax-1))
      if zl<zh:
         x = xl
      else:
         x = xh
      Zmin = min(Zmin,x*xmin)
      Zmax = max(Zmax,x*xmax)
      maxerr = max(maxerr, min(zl,zh))  
      X = x.exact_rational()
      h = R64(n(-log(X)/log(2),200))
      H = h.exact_rational()
      l = R64(n(-log(X)/log(2)-H,200))
      print ("   {" + get_hex(x) + ", " + get_hex(h) + "l, " + get_hex(l) + "l}, /* i=" + str(i) + " */")
   print ("};")
   return maxerr, Zmin, Zmax

def T2acc():
   print ("static const long double T2acc[64][3] = {")
   maxerr = 0
   Zmin = Zmax = 1
   for j in [-32..31]:
      xmin = R64(1 + j/2^12)
      xmax = R64(1 + (j+1)/2^12).nextbelow()
      inv = R64(2)/(xmin+xmax)
      e = -21
      xl = R64(floor(inv/2^e)*2^e)
      xh = R64(ceil(inv/2^e)*2^e)
      zl = max(abs(xl*xmin-1),abs(xl*xmax-1))
      zh = max(abs(xh*xmin-1),abs(xh*xmax-1))
      if zl<zh:
         x = xl
      else:
         x = xh
      Zmin = min(Zmin,x*xmin)
      Zmax = max(Zmax,x*xmax)
      maxerr = max(maxerr, min(zl,zh))  
      X = x.exact_rational()
      h = R64(n(-log(X)/log(2),200))
      H = h.exact_rational()
      l = R64(n(-log(X)/log(2)-H,200))
      print ("   {" + get_hex(x) + ", " + get_hex(h) + "l, " + get_hex(l) + "l}, /* j=" + str(j) + " */")
   print ("};")
   return maxerr, Zmin, Zmax

# split binade [2^(e-1),2^e) into k blocks
def doit_bacsel(e,k,t0=None,t1=None,neg=false):
   if t0==None:
      if neg:
         t0 = -2^64+1
      else:
         t0 = 2^63
   if t1==None:
      if neg:
         t1 = -2^63+1
      else:
         t1 = 2^64
   h = ceil((t1-t0)/k)
   for i in range(k):
      u0 = t0+h*i
      u1 = min(t0+h*(i+1),t1)
      print ("sbatch ./doit.sh " + str(u0) + " " + str(u1) + " 64 " + str(e) + " 64 24 64")

from functools import cmp_to_key

def cmp(x,y):
   if x[2] < y[2]:
      return int(-1)
   if x[2] > y[2]:
      return int(1)
   # now x[2] = y[2]
   if x[1] < y[1]:
      return int(-1)
   if x[1] > y[1]:
      return int(1)
   if x[0] < y[0]:
      return int(-1)
   if x[0] > y[0]:
      return int(1)
   return int(0)

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
   if x[1] < y[1]:
      return int(-1)
   if x[1] > y[1]:
      return int(1)
   return int(0)

# statall("/tmp/log")
def statall(f):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split(" ")
      assert len(s) == 5, "len(s) == 5"
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
      assert ZZ(s[3])==64, "s[3]==64"
      assert ZZ(s[4])==64, "s[4]==64"
      l.append((t0,t1,e))
   f.close()
   lpos = [x for x in l if x[0]>0]
   lneg = [x for x in l if x[0]<0]
   assert len(l) == len(lpos) + len(lneg)
   lpos.sort(key=cmp_to_key(cmp))
   lpos2 = []
   for t0,t1,e in lpos:
      if lpos2==[]:
         lpos2 = [((t0,e),(t1,e))]
      else:
         t1old,e1old = lpos2[-1][1]
         if t1old*2^e1old > t0*2^e:
            print ((t1old,e1old), (t0, e))
         assert t1old*2^e1old <= t0*2^e, "t1old*2^e1old <= t0*2^e"
         if t1old*2^e1old == t0*2^e:
            lpos2[-1] = (lpos2[-1][0],(t1,e))
         else:
            lpos2.append(((t0,e),(t1,e)))
   lpos = lpos2
   lneg.sort(key=cmp_to_key(cmpneg))
   lneg2 = []
   for t0,t1,e in lneg:
      if lneg2==[]:
         lneg2 = [((t0,e),(t1,e))]
      else:
         t1old,e1old = lneg2[-1][1]
         if (t1old-1)*2^e1old > (t0-1)*2^e:
            print ((t1old,e1old), (t0, e))
         assert (t1old-1)*2^e1old <= (t0-1)*2^e, "(t1old-1)*2^e1old <= (t0-1)*2^e"
         if (t1old-1)*2^e1old == (t0-1)*2^e:
            lneg2[-1] = (lneg2[-1][0],(t1,e))
         else:
            lneg2.append(((t0,e),(t1,e)))
   lneg = lneg2
   return lpos,lneg
