#load("../../generic/support/common.sage")
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

# l = statall("/tmp/log")
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
   l.sort(key=cmp_to_key(cmp))
   l2 = []
   for t0,t1,e in l:
      if l2==[]:
         l2 = [((t0,e),(t1,e))]
      else:
         t1old,e1old = l2[-1][1]
         if t1old*2^e1old > t0*2^e:
            print ((t1old,e1old), (t0, e))
         assert t1old*2^e1old <= t0*2^e, "t1old*2^e1old <= t0*2^e"
         if t1old*2^e1old == t0*2^e:
            l2[-1] = (l2[-1][0],(t1,e))
         else:
            l2.append(((t0,e),(t1,e)))
   l = l2
   return l

def fast_two_sum(a,b):
   x = a+b
   z = x-a
   y = b-z
   return x, y

def fast_two_sum_a(a,b):
   x = a+b
   z = x-a
   y = z-b
   return x, -y

# p=6 rnd='RNDU' a=0x1p+24 b=0x1p+5
# checkall2(8)
# 8 RNDU 0x1p+33 0x1p+7 0.495881782945736
# checkall2(9)
# 9 RNDU 0x1p+37 0x1p+8 0.497932879377432
def checkall(p,rnd='RNDN'):
   R = RealField(p,rnd=rnd)
   maxerr = 0
   u = RR(2^-p)
   for e in range(3*p+3):
      for A in range(2^(p-1),2^p):
         a = R(A*2^e)
         for B in range(2^(p-1),2^p):
            b = R(B)
            x, y = fast_two_sum(a,b)
            X = x.exact_rational()
            Y = y.exact_rational()
            if X+Y != A*2^e+B:
               err = abs((X+Y-(A*2^e+B))/X)
               # err = abs((X+Y-(A*2^e+B))/(A*2^e+B))
               if err > maxerr:
                  maxerr = err
                  print (p,rnd,get_hex(a),get_hex(b),err/(4*u^2))

def checkall2(p):
   for r in 'NZUD':
      checkall(p,'RND'+r)

# given a list l of worst cases for log, output the largest one such that
# log1p(x) rounds to a different value than log(x) for any rounding mode
def compare_log1p(l):
   xmax = -infinity
   for x in l:
      if x <= xmax:
         continue
      for r in 'NZUD':
         R = RealField(53,rnd='RND'+r)
         y = log(R(x))
         z = R(n(log(1+x.exact_rational()),200))
         if y!=z:
            xmax = x
            print (get_hex(x))
            break
