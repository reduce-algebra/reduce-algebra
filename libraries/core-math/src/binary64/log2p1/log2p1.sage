#load("../../generic/support/common.sage")
def doit_bacsel_subnormal():
   for e in [-1073..-1022]:
      nn = 1074 + e # number of bits of output
      # deal with |log2p1(x)| in [2^(e-1),2^e)
      # only deal with positive values (quasi symmetry)
      a = RR(2^-1074)
      b = RR(1)
      while a.nextabove()!=b:
         c = (a+b)/2
         if n(c/log(2)) < 2^(e-1):
            a = c
         else:
            b = c
      x0 = b
      a = b
      b = RR(1)
      while a.nextabove()!=b:
         c = (a+b)/2
         if n(c/log(2)) < 2^e:
            a = c
         else:
            b = c
      x1 = b
      t0, e0, n0 = t_exp (x0)
      t1, e1, n1 = t_exp (x1)
      print_bacsel_pos (t0, e0, n0, t1, e1, n1, nn)

def print_bacsel_pos (t0, e0, n0, t1, e1, n1, nn):
   assert n0<=n1, "n0<=n1"
   if n0<n1:
      print_bacsel_pos (t0, e0, n0, 2^n0, e0, n0, nn)
      print_bacsel_pos (2^n0, e0+1, n0+1, t1, e1, n1, nn)
   else:
      assert e0<=e1, "e0<=e1"
      if e0<e1:
         print_bacsel_pos (t0, e0, n0, 2^n0, e0, n0, nn)
         print_bacsel_pos (2^(n0-1), e0+1, n0, t1, e1, n1, nn)
      elif t0<t1:
         print ("./doit1.sh " + str(t0) + " " + str(t1) + " " + str(n0) + " " + str(e0) + " 64 10 " + str(nn))

def t_exp(x):
   if abs(x)<2^-1022:
      m = ceil(x.exact_rational()*2^1074)
      n = m.nbits()
      assert n<=52, "n<=52"
      return m, -1074+n, n
   else:
      s,m,e = x.sign_mantissa_exponent()
      assert m.nbits()==53, "m.nbits()==53"
      return s*m, e+53, 53

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
# [((-9007199254740991, -53), (-4503599627370495, -158)), ((4503599627370496, -158), (9007199254740992, 971))]
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
      h = RR(n(log(1+X)/log(2),200))
      print ("    {" + get_hex(x) + ", " + get_hex(h) + "},")
   print ("  };")
   print ("static const char exceptions_rnd[EXCEPTIONS] = {")
   for x in l:
      X = x.exact_rational()
      h = RR(n(log(1+X)/log(2),200))
      l = RR(n(log(1+X)/log(2)-h.exact_rational(),200))
      if l==0:
         l=0
      elif l>0:
         l=1
      else:
         l=-1
      print ("    " + str(l) + ", /* " + get_hex(x) + " */")
   print ("  };")
