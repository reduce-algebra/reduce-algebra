#load("../../generic/support/common.sage")
# print bacsel command for 2^(e-1) <= x < 2^e
def bacsel_doit(e):
   assert -1073 <= e, "-1073 <= e"
   # first check if we are in the subnormal input range
   if e > -1022:
      n = 53
   else:
      n = e+1074
   # check if we are in the subnormal output range
   R = RealField(n)
   Rz = RealField(53,rnd='RNDZ')
   x0 = R(2^(e-1))
   x1 = R(2^e)
   y0 = numerical_approx(asin(x0.exact_rational())/pi,200)
   y1 = numerical_approx(asin(R(x1).nextbelow().exact_rational())/pi,200)
   if y1<2^-1022: # all output in subnormal range
      x2 = x1
   elif y0<2^-1022: # only part of the output in subnormal range
      a = x0
      b = x1
      while a.nextabove()!=b:
         c = (a+b)/2
         y = Rz(numerical_approx(asin(c.exact_rational())/pi,200))
         if y<2^-1022:
            a = c
         else:
            b = c
      x1, x2 = b, x1
      # subnormal in x0,x1, normal in x1,x2
   else:
      x1,x2 = x0,x1 # normal output in x1,x2
   if x0<x1: # subnormal output in x0,x1
      y0 = Rz(numerical_approx(asin(x0.exact_rational())/pi,200))
      y1 = Rz(numerical_approx(asin(x1.nextbelow().exact_rational())/pi,200))
      if y0.ulp()!=y1.ulp():
         a = x0
         b = x1
         while a.nextabove()!=b:
            c = (a+b)/2
            y = Rz(numerical_approx(asin(c.exact_rational())/pi,200))
            if y.ulp()==y0.ulp():
               a = c
            else:
               b = c
         xm = b
      else:
         xm = x1
      # process [x0,xm)
      xm = xm.nextbelow()
      ym = Rz(numerical_approx(asin(xm.exact_rational())/pi,200))
      u0 = floor(y0*2^1074)
      um = floor(ym*2^1074)
      nn = u0.nbits()
      assert um.nbits()==nn, "um.nbits()==nn"
      if n<53:
         t0 = ceil(x0*2^1074)
         tm = floor(xm*2^1074)
      else:
         t0 = ceil(x0*2^(53-e))
         tm = floor(xm*2^(53-e))
      assert t0.nbits() == n, "t0.nbits() == n (1)"
      assert tm.nbits() == n, "tm.nbits() == n"
      doit (t0, tm+1, n, nn, e)
      # process [xm,x1)
      xm = xm.nextabove()
      if xm<x1:
         ym = Rz(numerical_approx(asin(xm.exact_rational())/pi,200))
         x1 = x1.nextbelow()
         y1 = Rz(numerical_approx(asin(x1.exact_rational())/pi,200))
         um = floor(ym*2^1074)
         u1 = floor(y1*2^1074)
         nn = um.nbits()
         assert u1.nbits()==nn, "u1.nbits()==nn"
         if n<53:
            tm = ceil(xm*2^1074)
            t1 = floor(x1*2^1074)
         else:
            tm = ceil(xm*2^(53-e))
            t1 = floor(x1*2^(53-e))
         assert tm.nbits() == n, "tm.nbits() == n"
         assert t1.nbits() == n, "t1.nbits() == n"
         doit (tm, t1+1, n, nn, e)
         x1 = x1.nextabove()
   if x1<x2: # normal output in x1,x2
      x2 = x2.nextbelow()
      t0 = ceil(x1*2^(53-e))
      t1 = floor(x2*2^(53-e))
      assert t0.nbits() == n, "t0.nbits() == n (2)"
      assert t1.nbits() == n, "t1.nbits() == n"
      doit (t0, t1+1, n, 53, e)
      
def doit(t0,t1,n,nn,e):
   if t0<t1:
      print ("./doit.sh " + str(t0) + " " + str(t1) + " " + str(n) + " " + str(e) + " 64 20 " + str(nn))

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
# [((4, -1074), (9007199254740992, -1073)), ((4503599627370496, -105), (9007199254740992, -53))]
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
