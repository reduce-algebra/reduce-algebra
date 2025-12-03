#load("../../generic/support/common.sage")
# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

def expm1_fast_tiny(xmin=-0.125,xmax=0.125,verbose=false,rel=false):
   P = ["0x0","0x1p0","0x1p-1","0x1.5555555555555p-3","0x1.5555555555553p-5","0x1.1111111111bbcp-7","0x1.6c16c16c1f8a2p-10","0x1.a01a0183a908bp-13","0x1.a01a00383b80dp-16","0x1.71e02a5f3b87p-19","0x1.27fcd07571d4ep-22","0x1.969ce6c7ee119p-26"]
   P = [RR(x,16) for x in P]
   x = RIF(xmin,xmax)
   err0 = 2^-67.183*max(abs(expm1(xmin)),abs(expm1(xmax)))
   if verbose:
      print ("err0=", log(err0)/log(2.))
   # x2 = x * x
   x2 = x * x
   err_x2 = RIFulp(x2)
   # x4 = x2 * x2
   x4 = x2 * x2
   err_x4 = RIFulp(x4) + 2*err_x2*x2.abs().upper()
   # c10 = __builtin_fma (P[11], x, P[10])
   c10 = P[11]*x+P[10]
   err1 = RIFulp(c10)*x.abs().upper()^10
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # c8 = __builtin_fma (P[9], x, P[8])
   c8 = P[9]*x+P[8]
   err2 = RIFulp(c8)*x.abs().upper()^8
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # c6 = __builtin_fma (P[7], x, P[6])
   c6 = P[7]*x+P[6]
   err3 = RIFulp(c6)*x.abs().upper()^6
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # c4 = __builtin_fma (P[5], x, P[4])
   c4 = P[5]*x+P[4]
   err4 = RIFulp(c4)*x.abs().upper()^4
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # c8 = __builtin_fma (c10, x2, c8)
   c8 = c10*x2+c8
   err5 = (RIFulp(c8)+c10.abs().upper()*err_x2)*x.abs().upper()^8
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # c4 = __builtin_fma (c6, x2, c4)
   c4 = c6*x2+c4
   err6 = (RIFulp(c4)+c6.abs().upper()*err_x2)*x.abs().upper()^4
   if verbose:
      print ("err6=", log(err6)/log(2.))
   # c4 = __builtin_fma (c8, x4, c4)
   c4 = c8*x4+c4
   err7 = (RIFulp(c4)+c8.abs().upper()*err_x4)*x.abs().upper()^4
   if verbose:
      print ("err7=", log(err7)/log(2.))
   # a_mul (h, l, c4, x)
   h = c4*x
   u = RIFulp(h)
   l = RIF(-u,u)
   # fast_two_sum (h, &t, P[3], *h)
   h = P[3]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err8 = h.abs().upper()*2^-105*x.abs().upper()^3
   if verbose:
      print ("err8=", log(err8)/log(2.))
   # *l += t
   l += t
   err9 = RIFulp(l)*x.abs().upper()^3
   if verbose:
      print ("err9=", log(err9)/log(2.))
   # s_mul (h, l, x, *h, *l) decomposes into
   #    a_mul (h, t, *h, x)
   #    *l = __builtin_fma (*l, x, t)
   # a_mul (h, t, *h, x)
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   # *l = __builtin_fma (*l, x, t)
   l_in = l
   l = l*x+t
   err10 = (RIFulp(l_in*x)+RIFulp(l))*x.abs().upper()^2
   if verbose:
      print ("err10=", log(err10)/log(2.))
   # fast_two_sum (h, &t, P[2], *h)
   h = P[2]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err11 = h.abs().upper()*2^-105*x.abs().upper()^2
   if verbose:
      print ("err11=", log(err11)/log(2.))
   # *l += t
   l += t
   err12 = RIFulp(l)*x.abs().upper()^2
   if verbose:
      print ("err12=", log(err12)/log(2.))
   # s_mul (h, l, x, *h, *l) decomposes into:
   #   a_mul (h, t, *h, x)
   #   *l = __builtin_fma (*l, x, t)
   # a_mul (h, t, *h, x)
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   # *l = __builtin_fma (*l, x, t)
   l_in = l
   l = l*x+t
   err13 = (RIFulp(l_in*x)+RIFulp(l))*x.abs().upper()
   if verbose:
      print ("err13=", log(err13)/log(2.))
   # fast_two_sum (h, &t, P[1], *h)
   h = P[1]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err14 = h.abs().upper()*2^-105*x.abs().upper()
   if verbose:
      print ("err14=", log(err14)/log(2.))
   # *l += t
   l += t
   err15 = RIFulp(l)*x.abs().upper()
   if verbose:
      print ("err15=", log(err15)/log(2.))
   # s_mul (h, l, x, *h, *l) decomposes into:
   #   a_mul (h, t, *h, x)
   #   *l = __builtin_fma (*l, x, t)
   # a_mul (h, t, *h, x)
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   # *l = __builtin_fma (*l, x, t)
   l_in = l
   l = l*x+t
   err16 = RIFulp(l_in*x)+RIFulp(l)
   if verbose:
      print ("err16=", log(err16)/log(2.))
   err = err0+err1+err2+err3+err4+err5+err6+err7+err8+err9+err10+err11+err12+err13+err14+err15+err16
   if rel:
      err = err/(h+l).abs().lower()
   return err

# xmin=RR("0x1.6a09e667f3bccp-53",16)
# expm1_fast_tiny_all(xmin,0.125,2^-64.29)
# 4.43378275371923e-20 # -64.2900238149147
# expm1_fast_tiny_all(-0.125,-xmin,2^-64.13)
# 4.94311016020191e-20 # -64.1331428395791
def expm1_fast_tiny_all(xmin,xmax,bound):
   err = expm1_fast_tiny(xmin=xmin,xmax=xmax,rel=true)
   if err <= bound or xmin==xmax:
      return err
   xmid = (xmin+xmax)/2
   if xmid==xmax:
      xmid = xmin
   err1 = expm1_fast_tiny_all(xmin, xmid, bound)
   err2 = expm1_fast_tiny_all(xmid.nextabove(), xmax, bound)
   return max(err1,err2)
   
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

# statall("out3") # explor + nancy
# [((-5267796835639522, -47), (-6369051672525772, -105)), ((6369051672525772, -105), (6243314768165360, -43))]
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
      assert nn == 53, "nn == 53"
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

def expm1_accurate_tiny(xmin=-0.125,xmax=0.125,verbose=false,rel=false):
   Q = ["0x1p0","0x1p-1","0x1.5555555555555p-3","0x1.55555555554abp-57","0x1.5555555555555p-5","0x1.5555555529b52p-59","0x1.1111111111111p-7","0x1.111110fd7800cp-63","0x1.6c16c16c16c17p-10","-0x1.f49f228e81422p-65","0x1.a01a01a01a01ap-13","0x1.a1a3748b2ap-73","0x1.a01a01a01a01ap-16","0x1.71de3a556c733p-19","0x1.27e4fb7789f9fp-22","0x1.ae64567f5755ep-26","0x1.1eed8efedba9bp-29","0x1.612460b437492p-33","0x1.93976857d992ap-37","0x1.ae966f43fe1c7p-41","0x1.ac8bc1457bf6dp-45"]
   Q = [RR(x,16) for x in Q]
   x = RIF(xmin,xmax)
   err = dict()
   err[0] = 2^-109.536*max(abs(expm1(xmin)),abs(expm1(xmax)))
   if verbose:
      print ("err[0]=", log(err[0])/log(2.))
   # x2 = x * x
   x2 = x * x
   err_x2 = RIFulp(x2)
   # x4 = x2 * x2
   x4 = x2 * x2
   err_x4 = RIFulp(x4) + 2*err_x2*x2.abs().upper()
   # c15 = __builtin_fma (Q[20], x, Q[19])
   c15 = Q[20]*x+Q[19]
   err[1] = RIFulp(c15)*x.abs().upper()^15
   if verbose:
      print ("err[1]=", log(err[1])/log(2.))
   # c13 = __builtin_fma (Q[18], x, Q[17])
   c13 = Q[18]*x+Q[17]
   err[2] = RIFulp(c13)*x.abs().upper()^13
   if verbose:
      print ("err[2]=", log(err[2])/log(2.))
   # c11 = __builtin_fma (Q[16], x, Q[15])
   c11 = Q[16]*x+Q[15]
   err[3] = RIFulp(c11)*x.abs().upper()^11
   if verbose:
      print ("err[3]=", log(err[3])/log(2.))
   # c9 = __builtin_fma (Q[14], x, Q[13])
   c9 = Q[14]*x+Q[13]
   err[4] = RIFulp(c9)*x.abs().upper()^9
   if verbose:
      print ("err[4]=", log(err[4])/log(2.))
   # c13 = __builtin_fma (c15, x2, c13)
   c13 = c15*x2+c13
   err[5] = (RIFulp(c13)+c15.abs().upper()*err_x2)*x.abs().upper()^13
   if verbose:
      print ("err[5]=", log(err[5])/log(2.))
   # fast_two_sum (&h, &l, c9, c11 * x2 + c13 * x4)
   t1 = c11 * x2
   t2 = c13 * x4
   t3 = t1+t2
   h = c9+t3
   u = RIFulp(h)
   l = RIF(-u,u)
   err[6] = (RIFulp(t1)+RIFulp(t2)+RIFulp(t3)+h.abs().upper()*2^-105)*x.abs().upper()^9
   if verbose:
      print ("err[6]=", log(err[6])/log(2.))
   # s_mul (&h, &l, x, h, l)
   lin = l
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   l = lin*x+t
   err[7] = (RIFulp(lin*x)+RIFulp(l))*x.abs().upper()^8
   if verbose:
      print ("err[7]=", log(err[7])/log(2.))
   # fast_two_sum (&h, &t, Q[12], h)
   h = Q[12]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err[8] = h.abs().upper()*2^-105*x.abs().upper()^8
   if verbose:
      print ("err[8]=", log(err[8])/log(2.))
   # l += t + Q[11]
   t += l
   err[9] = RIFulp(t)*x.abs().upper()^8
   if verbose:
      print ("err[9]=", log(err[9])/log(2.))
   d = 7
   j = 10
   for i in range(10,1,-2):
      # multiply h+l by x and add Q[i]+Q[i+1]
      # s_mul (&h, &l, x, h, l)
      lin = l
      h = h*x
      u = RIFulp(h)
      t = RIF(-u,u)
      l = lin*x+t
      err[j] = (RIFulp(lin*x)+RIFulp(l))*x.abs().upper()^d
      if verbose:
         print ("err["+str(j)+"]=", log(err[j])/log(2.))
      j += 1
      # fast_two_sum (&h, &t, Q[i], h)
      h = Q[i]+h
      u = RIFulp(h)
      t = RIF(-u,u)
      err[j] = h.abs().upper()*2^-105*x.abs().upper()^d
      if verbose:
         print ("err["+str(j)+"]=", log(err[j])/log(2.))
      j += 1    
      # l += t + Q[i+1]
      l += t + Q[i+1]
      err[j] = (RIFulp(t+Q[i+1])+RIFulp(l))*x.abs().upper()^d
      if verbose:
         print ("err["+str(j)+"]=", log(err[j])/log(2.))
      j += 1
      d = d-1
   assert d == 2, "d == 2"
   # multiply h+l by x and add Q[1]
   # s_mul (&h, &l, x, h, l)
   lin = l
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   l = lin*x+t
   err[j] = (RIFulp(lin*x)+RIFulp(l))*x.abs().upper()^d
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1
   # fast_two_sum (&h, &t, Q[1], h)
   h = Q[1]+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err[j] = h.abs().upper()*2^-105*x.abs().upper()^d
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1    
   # l += t
   l += t
   err[j] = RIFulp(l)*x.abs().upper()^d
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1
   d = d-1
   assert d == 1, "d == 1"
   # multiply h+l by x
   # s_mul (&h, &l, x, h, l)
   lin = l
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   l = lin*x+t
   err[j] = (RIFulp(lin*x)+RIFulp(l))*x.abs().upper()^d
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1
   d = d-1
   assert d == 0, "d == 0"
   # multiply h+l by x
   # s_mul (&h, &l, x, h, l)
   lin = l
   h = h*x
   u = RIFulp(h)
   t = RIF(-u,u)
   l = lin*x+t
   err[j] = (RIFulp(lin*x)+RIFulp(l))*x.abs().upper()^d
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1
   d = d-1
   assert d==-1, "d==-1"
   # add Q[0]*x = x
   # fast_two_sum (&h, &t, x, h)
   h = x+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err[j] = h.abs().upper()*2^-105
   if verbose:
      print ("err["+str(j)+"]=", log(err[j])/log(2.))
   j += 1    
   # l += t
   err[j] = RIFulp(l)
   Err = 0
   for i in [0..j]:
      Err += err[i]
   if rel:
      Err = Err/x.abs().lower()
   if verbose:
      print ("Err=", log(Err)/log(2.))
