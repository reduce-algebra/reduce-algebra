#load("../../generic/support/common.sage")
# check if log1p(x) rounds identically to log(x) for all rounding modes
def compare_log(x,verbose=false):
   X = x.exact_rational()
   prec = 200
   for r in ['RNDN','RNDZ','RNDU','RNDD']:
      R = RealField(53,rnd=r)
      y = R(n(log(X),prec))
      z = R(n(log(1+X),prec))
      if y!=z:
         if verbose:
            print (get_hex(x),r)
         return false
   return true

def fast_two_sum (a,b):
   hi = a + b
   e = hi - a
   lo = b - e
   return hi,lo

# check if fast_two_sum(x,1) is exact when |x| < 1
# fails with 2^-54 and rounding to nearest
def check_fast_two_sum(e):
   while true:
      x = RR.random_element()*2^e
      hi, lo = fast_two_sum(x,1)
      a = 1 + x.exact_rational()
      b = hi.exact_rational() + lo.exact_rational()
      if a!=b:
         print ("x=", get_hex(x))
         raise ValueError

# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# compute the maximal absolute rounding error for p_1() over [zmin,zmax]
# if rel=true, takes into account the relative error for the Sollya polynomial
# analyze_p1(RR(2^-1000),RR(2^-999),rel=true,verbose=true)
# (1.14506750044579e-322, -1.?e-602)
# Xmax=0.00212097167968735
# analyze_p1(Xmax/2,Xmax,rel=true,verbose=true)
# (2.76450182935071e-24, 1.?e-6)
def analyze_p1(zmin,zmax,rel=true,verbose=false):
   P = ["0x1p0","-0x1p-1","0x1.555555555555p-2","-0x1.fffffffff572dp-3","0x1.999999a2d7868p-3","-0x1.5555c0d31b08ep-3","0x1.2476b9058e396p-3"]
   assert -0.00212097167968735 <= zmin, "-0.00212097167968735 <= zmin"
   assert zmax <= 0.00212097167968735, "zmax <= 0.00212097167968735"
   P = [RR(x,16) for x in P]
   z = RIF(zmin,zmax)
   if rel==false:
      err0 = 2^-79.592 # absolute error from Sollya polynomial
   else:
      err0 = 2^-70.467 # relative error from Sollya polynomial
      # for |x| < 0.00212097167968735, we have |log(1+x)/x| < 1.0011
      err0 = err0*1.0011*z.abs().upper()
   if verbose:
      print ("err0=", log(err0)/log(2.))
   # a_mul (&z2h, &z2l, z, z)
   z2h = z*z
   u = RIFulp(z2h)
   z2l = RIF(-u,u)
   err_z2h = RIFulp(z2h)
   # p56 = __builtin_fma (P[6], z, P[5])
   p56 = P[6]*z+P[5]
   err1 = RIFulp(p56)*z.abs().upper()^6
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # p34 = __builtin_fma (P[4], z, P[3])
   p34 = P[4]*z+P[3]
   err2 = RIFulp(p34)*z.abs().upper()^4
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # ph = __builtin_fma (p56, z2h, p34)
   ph = p56*z2h+p34
   err3 = (RIFulp(ph)+p56.abs().upper()*err_z2h)*z.abs().upper()^4
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # ph = __builtin_fma (ph, z, P[2])
   ph_in = ph
   ph = ph*z+P[2]
   err4 = RIFulp(ph)*z.abs().upper()*z.abs().upper()^3
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # ph *= z2h
   ph_in = ph
   ph = ph*z2h
   err5 = (RIFulp(ph)+ph_in.abs().upper()*err_z2h)*z.abs().upper()
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # fast_two_sum (h, l, -0.5 * z2h, ph * z)
   t = ph*z
   h = RIF(-0.5)*z2h+t
   u = RIFulp(h)
   l = RIF(-u,u)
   err6 = RIFulp(t)+h.abs().upper()*2^-105   
   if verbose:
      print ("err6=", log(err6)/log(2.))
   # *l += -0.5 * z2l
   l = l+RIF(-0.5)*z2l
   err7 = RIFulp(l)
   if verbose:
      print ("err7=", log(err7)/log(2.))
   err = err0+err1+err2+err3+err4+err5+err6+err7
   if verbose:
      print ("err=", log(err)/log(2.))
   return err, h, l

# analyze_p1a(-0.03125,0.03125)
# (6.11549265612888e-21, 0.000?, 0.?e-18)
def analyze_p1a(zmin,zmax,rel=true,verbose=false):
   P = ["0x1p0","-0x1p-1","0x1.5555555555555p-2","-0x1.ffffffffffe5fp-3","0x1.999999999aa82p-3","-0x1.555555583a8c8p-3","0x1.2492491c359e6p-3","-0x1.ffffc728edeeap-4","0x1.c71c961f3498p-4","-0x1.9a82ac77c05f4p-4","0x1.74b40dd1707d3p-4"]
   assert -0.03125 <= zmin, "-0.03125 <= zmin"
   assert zmax <= 0.03125, "zmax <= 0.03125"
   P = [RR(x,16) for x in P]
   z = RIF(zmin,zmax)
   if rel==false:
      err0 = 2^-73.441 # absolute error from Sollya polynomial
   else:
      err0 = 2^-67.088 # relative error from Sollya polynomial
      # transform the relative error into absolute error
      # for |x| < 0.03125, we have |log(1+x)/x| < 1.016
      err0 = err0*1.0161*z.abs().upper()
   if verbose:
      print ("err0=", log(err0)/log(2.))
   # a_mul (&z2h, &z2l, z, z)
   z2h = z*z
   u = RIFulp(z2h)
   z2l = RIF(-u,u)
   err_z2h = RIFulp(z2h)
   # z4h = z2h * z2h
   z4h = z2h*z2h
   u = RIFulp(z4h)
   err_z4h = RIFulp(z4h)+2*z2h.abs().upper()*err_z2h
   # p910 = __builtin_fma (Pa[10], z, Pa[9])
   p910 = P[10]*z+P[9]
   err1 = RIFulp(p910)*z.abs().upper()^10
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # p78 = __builtin_fma (Pa[8], z, Pa[7])
   p78 = P[8]*z+P[7]
   err2 = RIFulp(p78)*z.abs().upper()^8
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # p56 = __builtin_fma (Pa[6], z, Pa[5])
   p56 = P[6]*z+P[5]
   err3 = RIFulp(p56)*z.abs().upper()^6
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # p34 = __builtin_fma (Pa[4], z, Pa[3])
   p34 = P[4]*z+P[3]
   err4 = RIFulp(p34)*z.abs().upper()^4
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # p710 = __builtin_fma (p910, z4h, p78)
   p710 = p910*z4h+p78
   err5 = (RIFulp(p710)+p910.abs().upper()*err_z4h)*z.abs().upper()^8
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # p36 = __builtin_fma (p56, z2h, p34)
   p36 = p56*z2h+p34
   err6 = (RIFulp(p36)+p56.abs().upper()*err_z2h)*z.abs().upper()^4
   if verbose:
      print ("err6=", log(err6)/log(2.))
   # ph = __builtin_fma (p710, z2h, p36)
   ph = p710*z2h+p36
   err7 = (RIFulp(ph)+p710.abs().upper()*err_z2h)*z.abs().upper()^4
   if verbose:
      print ("err7=", log(err7)/log(2.))
   # ph = __builtin_fma (ph, z, P[2])
   ph_in = ph
   ph = ph*z+P[2]
   err8 = RIFulp(ph)*z.abs().upper()*z.abs().upper()^3
   if verbose:
      print ("err8=", log(err8)/log(2.))
   # ph *= z2h
   ph_in = ph
   ph = ph*z2h
   err9 = (RIFulp(ph)+ph_in.abs().upper()*err_z2h)*z.abs().upper()
   if verbose:
      print ("err9=", log(err9)/log(2.))
   # fast_two_sum (h, l, -0.5 * z2h, ph * z)
   t = ph*z
   h = RIF(-0.5)*z2h+t
   u = RIFulp(h)
   l = RIF(-u,u)
   err10 = RIFulp(t)+h.abs().upper()*2^-105   
   if verbose:
      print ("err10=", log(err10)/log(2.))
   # *l += -0.5 * z2l
   l = l+RIF(-0.5)*z2l
   err11 = RIFulp(l)
   if verbose:
      print ("err11=", log(err11)/log(2.))
   err = err0+err1+err2+err3+err4+err5+err6+err7+err8+err9+err10+err11
   if verbose:
      print ("err=", log(err)/log(2.))
   return err, h, l

# analyse the error of cr_log1p_fast() for |x| < 0.03125
# analyze_x_plus_p1a()
# e= 0 err= -67.1776809892189
# analyze_x_plus_p1(rel=true)
# e= 0 err= -68.3751331997836
def analyze_x_plus_p1a(rel=false,verbose_e=[],Xmax=0.03125):
   maxerr = maxratio = 0
   assert 0<Xmax<=1, "0<Xmax<=1"
   for e in range(0,-1075,-1):
      # consider 2^e*[Xmax/2,Xmax]
      xmin = Xmax*2^(e-1)
      xmax = Xmax*2^e
      if xmin<0.0159692259365418<xmax:
         print ("###### e=", e)
      if xmax<2^-1074:
         break
      # p_1 (h, &lo, x)
      if e in verbose_e:
         err1, h, lo = analyze_p1a(xmin,xmax,rel=rel,verbose=true)
         print ("err1=", log(err1)/log(2.))
      else:
         err1, h, lo = analyze_p1a(xmin,xmax,rel=rel)
      x = RIF(xmin,xmax)
      # fast_two_sum (h, l, x, *h)
      h = x + h
      u = RIFulp(h)
      l = RIF(-u,u)
      err2 = h.abs().upper()*2^-105
      if e in verbose_e:
         print ("err2=", log(err2)/log(2.))
      # *l += lo
      l += lo
      err3 = RIFulp(l)
      err = err1+err2+err3
      if rel:
         err = err/h.abs().lower()
      if err>maxerr:
         print ("e=", e, "err=", log(err)/log(2.))
         maxerr = err
      # same for negative values
      xmin,xmax = -xmax,-xmin
      # p_1 (h, &lo, x)
      if e in verbose_e:
         err1, h, lo = analyze_p1a(xmin,xmax,rel=rel,verbose=true)
         print ("err1=", log(err1)/log(2.))
      else:
         err1, h, lo = analyze_p1a(xmin,xmax,rel=rel)
      x = RIF(xmin,xmax)
      # fast_two_sum (h, l, x, *h)
      h = x + h
      u = RIFulp(h)
      l = RIF(-u,u)
      err2 = h.abs().upper()*2^-105
      if e in verbose_e:
         print ("err2=", log(err2)/log(2.))
      # *l += lo
      l += lo
      err3 = RIFulp(l)
      err = err1+err2+err3
      if rel:
         err = err/h.abs().lower()
      if err>maxerr:
         print ("e=", e, "err=", log(err)/log(2.))
         maxerr = err
      ratio = l.abs().upper()/h.abs().lower()
      if ratio > maxratio:
         print ("e=", e, "ratio=", ratio)
         maxratio = ratio

# print bacsel command line to find potential values of x
# such that log1p(x) does not round to the same value as log(x)
# in the binade 2^(e-1) <= x < 2^e
def compare_log(e,nthreads=64):
   # log(x+1) = log(x) + log(1+1/x)
   # thus |log(x+1) - log(x)| <= |log(1+1/x)| < 1/x <= 1/2^(e-1)
   # if log(x+1) and log(x) do not round to the same value,
   # then log(x) is at distance < 1/2^(e-1) from a rounding boundary
   x = RR(2^(e-1))
   y = log(x)
   t = RR(1/2^(e-1))/y.ulp()
   m = floor(-log(t)/log(2.))
   prec = max(128,53 + m)
   # bacsel should be compiled with -DLOG
   # print ("./bacsel -rnd_mode all -prec " + str(prec) + " -n 53 -nn 53 -m " + str(m) + " -t 30 -t0 4503599627370496 -t1 9007199254740992 -d 2 -alpha 2 -e_in " + str(e) + " -nthreads " + str(nthreads))
   print ("./compare_log.sh " + str(prec) + " " + str(m) + " " + str(e))

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
# [((-9007199254740991, -53), (-6369051672525772, -105)), ((6369051672525773, -105), (6374827554248054, 49))]
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
