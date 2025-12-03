#load("../../generic/support/common.sage")
def gen_tabi():
   print ("static const double tab_i[128][2] = {")
   for i in range(-127,128):
      x = 2^(i/128)
      h = RR(n(x,100))
      H = h.exact_rational()
      l = RR(n(x-H,200))
      print ("{ " + get_hex(h) + ", " + get_hex(l) + " }, /* " + str(i) + " */")
   print ("};")

def ph(h):
   h = h.exact_rational()
   p0 = 1
   p1 = RR("0x1.62e42fefa39efp-1",16).exact_rational()
   p1 += RR("0x1.b2ca0bb577094p-56",16).exact_rational()
   p2 = RR("0x1.ebfbdff82c58fp-3",16).exact_rational()
   p3 = RR("0x1.c6b08d70484c1p-5",16).exact_rational()
   p4 = RR("0x1.3b2ab6fb663a2p-7",16).exact_rational()
   p5 = RR("0x1.5d881a764d899p-10",16).exact_rational()
   p6 = RR("0x1.430bba9c70dddp-13",16).exact_rational()
   yh = p6
   yh = p5 + yh * h
   yh = p4 + yh * h
   yh = p3 + yh * h
   yh = p2 + yh * h
   yh = p1 + yh * h
   return yh

def check_fast_path(x,e,yh,yl):
   X = x.exact_rational()
   YH = yh.exact_rational()
   YL = yl.exact_rational()
   return n(exp(X)-2^e*(YH+YL))

# h=RR("0x1.e1af735b65cp-8",16) # x=0x1.011dd7222b8d2p+1
def check_accurate_poly(h):
   H = h.exact_rational()
   p0 = 1
   p1h = RR("0x1.62e42fefa39efp-1",16)
   p1l = RR("0x1.abc9e3b397ebp-56",16)
   p1 = p1h.exact_rational() + p1l.exact_rational()
   p2h = RR("0x1.ebfbdff82c58fp-3",16)
   p2l = RR("-0x1.5e43a5429b326p-57",16)
   p2 = p2h.exact_rational() + p2l.exact_rational()
   p3h = RR("0x1.c6b08d704a0cp-5",16)
   p3l = RR("-0x1.d331600cee073p-59",16)
   p3 = p3h.exact_rational() + p3l.exact_rational()
   p4h = RR("0x1.3b2ab6fba4e77p-7",16)
   p4l = RR("0x1.4fb30e5c2c8bcp-62",16)
   p4 = p4h.exact_rational() + p4l.exact_rational()
   p5 = RR("0x1.5d87fe78a6731p-10",16).exact_rational()
   p6 = RR("0x1.430912f86bfb8p-13",16).exact_rational()
   p7 = RR("0x1.ffcbfc58b51c9p-17",16).exact_rational()
   p8 = RR("0x1.62c034be4ffd9p-20",16).exact_rational()
   p9 = RR("0x1.b523023e3d552p-24",16).exact_rational()
   y = p8+H*p9
   y = p7+H*y
   y = p6+H*y
   y = p5+H*y
   y = p4+H*y
   y = p3+H*y
   y = p2+H*y
   y = p1+H*y
   y = p0+H*y
   e = n(2^H-y,200)
   return e, log(abs(e))/log(2.)

def gen_bacsel_aux(X0,X1,e,sign):
   scale = 2^(53-e)
   t0 = ZZ(X0.exact_rational()*scale)
   t1 = ZZ(X1.exact_rational()*scale)
   if sign==1:
      print ("./doit2.sh " + str(t0) + " " + str(t1) + " " + str(e))
   else:
      print ("./doit2.sh " + str(-t1+1) + " " + str(-t0+1) + " " + str(e))
   
def gen_bacsel(emin=0,emax=10,group=10,sign=1):
   assert sign in [1,-1]
   R = RealField(53,rnd='RNDZ')
   for e in [emin..emax]:
      x0 = R(2^(e-1))
      x1 = R(2^e)
      x10 = x1
      n = 0
      X0 = x0
      while true:
         x00 = x0
         if exp(sign*x0)>=2^1024.:
            break
         if exp(sign*x0)<2^-1075.:
            break
         while exp(x0).ulp() != exp(x1).ulp():
            x2 = (x0+x1)/2
            if x2 in [x0,x1]:
               break
            if exp(x2).ulp()==exp(x0).ulp():
               x0 = x2
            else:
               x1 = x2
         x0 = x00
         X1 = x1
         n += 1
         if n==group:
            gen_bacsel_aux(X0,X1,e,sign)
            X0 = X1
            n = 0
         if x1==x10:
            break
         x0 = x1
         x1 = x10
      if n>0:
         gen_bacsel_aux(X0,X1,e,sign)

def get_hl(x):
   X = x.exact_rational()
   h = RR(n(exp(X),200))
   H = h.exact_rational()
   l = RR(n(exp(X)-H,200))
   L = l.exact_rational()
   if abs(l)==h.ulp()/2 or l==0:
      if n(exp(X)-H-L,200)>0:
         l = l.nextabove()
      else:
         l = l.nextbelow()
   return h, l

def gen_exceptions_aux(x):
   h, l = get_hl (x)
   print ("      if (x == " + get_hex(x) + ")")
   if l > 0:
      print ("        return " + get_hex(h) + " + " + get_hex(l) + ";")
   else:
      s = get_hex(l)
      print ("        return " + get_hex(h) + " - " + s[1:] + ";")

# generate the code for exceptional values in l
# l=[RR("0x1.62f71c4656b61p-1",16),RR("0x1.333a83013057ep+2",16),RR("0x1.83d4bcdebb3f4p+2",16)]
# gen_exceptions(l)
def gen_exceptions(l):
   # first sort l by value of e
   T = dict()
   for x in l:
      n = asuint64(x)
      e = n % 64
      if not e in T.keys():
         T[e] = []
      T[e].append(x)
   # now generate code
   print ("  switch (e) {")
   for e in T.keys():
      le = T[e]
      print ("    case "+str(e)+":")
      for x in le:
         gen_exceptions_aux(x)
      print ("      break;")
   print ("  };")
   
# output parameters for bacsel for subnormal range 2^(e-1) <= exp(x) < 2^e
def check_subnormal(emin=-1073,emax=-1022,nthreads=64):
   for e in [emin..emax]:
      assert -1073 <= e <= -1022
      # 2^(e-1) <= exp(x) thus log(2^(e-1)) <= x
      R = RealField(53,rnd='RNDU')
      xmin = log(R(2^(e-1)))
      xmax = log(R(2^(e)))
      Xmin = xmin.exact_rational()
      Xmax = xmax.exact_rational()
      emin = 1+floor(log(abs(Xmin))/log(2))
      emax = 1+floor(log(abs(Xmin))/log(2))
      assert emin==emax, "emin==emax"
      t0 = 2^53*Xmin/2^emin
      assert t0 in ZZ, "t0 in ZZ"
      t0 = ZZ(t0)
      t1 = 2^53*Xmax/2^emax
      assert t1 in ZZ, "t1 in ZZ"
      t1 = ZZ(t1)
      nn = 1074+e
      # around t0,t1 we use d=0 to avoid failures in bacsel
      margin = 2^20
      t0a = min(t0+margin,t1)
      t1a = max(t0,t1-margin)
      if t0<t0a:
         print ("./bacsel -rnd_mode all -prec 128 -n 53 -nn " + str(nn) + " -m 44 -t 20 -t0 " + str(t0) + " -t1 " + str(t0a) + " -d 0 -alpha 1 -v -e_in " + str(emin) + " -nthreads " + str(nthreads))
      if t0a<t1a:
         print ("./bacsel -rnd_mode all -prec 128 -n 53 -nn " + str(nn) + " -m 44 -t 20 -t0 " + str(t0a) + " -t1 " + str(t1a) + " -d 2 -alpha 2 -v -e_in " + str(emin) + " -nthreads " + str(nthreads))
      if t1a<t1:
         print ("./bacsel -rnd_mode all -prec 128 -n 53 -nn " + str(nn) + " -m 44 -t 20 -t0 " + str(t1a) + " -t1 " + str(t1) + " -d 0 -alpha 1 -v -e_in " + str(emin) + " -nthreads " + str(nthreads))

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

from functools import cmp_to_key

# lpos,lneg = statall("/tmp/log")
# lpos = [((4503599627370496, -52), (6243314768165360, 10))]
# lneg = [((-6554261109157969, 10), (-4503599627370495, -54))]
def statall(f):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split(" ")
      assert len(s) == 3
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
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
         if t1old*2^e1old > t0*2^e:
            print ((t1old,e1old), (t0, e))
         assert (t1old-1)*2^e1old <= (t0-1)*2^e, "(t1old-1)*2^e1old <= (t0-1)*2^e"
         if (t1old-1)*2^e1old == (t0-1)*2^e:
            lneg2[-1] = (lneg2[-1][0],(t1,e))
         else:
            lneg2.append(((t0,e),(t1,e)))
   lneg = lneg2
   return lpos,lneg

def statall_denorm(f):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split(" ")
      assert len(s) == 4
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
      nn = ZZ(s[3])
      l.append((t0,t1,e,nn))
   f.close()
   # check each range
   for t0,t1,e,nn in l:
      # check 2^(-1074+nn-1) <= exp(t0*2^(e-53))
      assert 2^(-1074+nn-1) <= exp(t0*2^(e-53)), "assert 1"
      # check exp((t0-1)*2^(e-53)) < 2^(-1074+nn-1)
      assert exp((t0-1)*2^(e-53)) < 2^(-1074+nn-1), "assert 2"
      # check 2^(-1074+nn) <= exp(t1*2^(e-53))
      assert 2^(-1074+nn) <= exp(t1*2^(e-53)), "assert 3"
      # check exp((t1-1)*2^(e-53)) < 2^(-1074+nn)
      assert exp((t1-1)*2^(e-53)) < 2^(-1074+nn), "assert 4"
   # now check there is no hole
   l.sort(key=cmp_to_key(cmp))
   for i in range(len(l)-1):
      assert l[i][3] == i+1, "l[i][3] == i+1"
      assert l[i+1][3] == i+2, "l[i+1][3] == i+2"
      assert l[i][2] == 10, "l[i][2] == 10"
      assert l[i+1][2] == 10, "l[i+1][2] == 10"
      assert l[i][1] == l[i+1][0], "l[i][1] == l[i+1][0]"
   return [(l[0][0],l[-1][1],10)]
         
