#load("../../generic/support/common.sage")
def fast_two_sum(a,b):
   hi = a+b
   e = hi-a
   lo = b-e
   return hi, lo

def two_sum(a,b):
   s = a+b
   ap = s-b
   bp = s-ap
   da = a-ap
   db = b-bp
   t = da+db
   return s,t

# 1 mul, 1 fma
def a_mul(a,b):
   hi = a*b
   lo = fma(a,b,-hi)
   return hi, lo

# 1 mul, 3 fma
def d_mul(ah,al,bh,bl):
   hi, s = a_mul (ah, bh)
   t = fma (al, bh, s)
   lo = fma (ah, bl, t)
   return hi, lo

def d_mul_acc2(ah,al,bh,bl):
   hi, cl1 = a_mul(ah,bh)
   tl = ah * bl
   cl2 = fma(al, bh, tl)
   cl3 = cl1 + cl2
   return fast_two_sum (hi, cl3)

# 1 div, 2 fma, 1 mul
def d_inv(bh,bl):
   R = bh.parent()
   hi = R(1) / bh
   e = fma (-hi, bh, R(1))
   e = fma (-hi, bl, e)
   lo = hi*e
   return hi, lo

# 1 div, 5 fma, 2 mul
def d_div(ah,al,bh,bl):
   hi, lo = d_inv (bh, bl)
   return d_mul (ah, al, hi, lo)

# using Karp-Markstein's trick
# 1 div, 2 mul, 2 fma, 1 add
def d_div_km(ah,al,bh,bl):
   R = ah.parent()
   yh = R(1) / bh
   zh = ah*yh
   # Newton's iteration for the inverse is y = y + y*(1-b*y)
   # Karp-Markstein's trick is z = z + y*(a-b*z)
   eh = fma(bh,-zh,ah)
   el = fma(bl,-zh,al)
x   zl = yh*(eh+el)
   return zh, zl

def s_mul_acc1(a,bh,bl):
   hi, cl1 = a_mul (a, bh)
   cl2 = a * bl
   hi, lo = fast_two_sum (hi, cl2)
   tl2 = lo + cl1
   return fast_two_sum (hi, tl2)

def s_mul_acc3(a,bh,bl):
   hi, cl1 = a_mul(a,bh)
   cl3 = fma(a,bl,cl1)
   return fast_two_sum (hi, cl3)

def d_div_acc1(xh,xl,yh,yl):
   th = xh / yh
   rh, rl = s_mul_acc1 (th, yh, yl)
   pih, pil = two_sum (xh, -rh)
   delta_h = pil - rl
   delta_l = delta_h + xl
   delta = pih + delta_l
   tl = delta / yh
   return fast_two_sum (th, tl)

def d_div_acc2(xh,xl,yh,yl):
   th = xh / yh
   rh, rl = s_mul_acc1 (th, yh, yl)
   pih = xh - rh
   delta_l = xl - rl
   delta = pih + delta_l
   tl = delta / yh
   return fast_two_sum (th, tl)

def fast_sum_acc(a,bh,bl):
   sh, sl = two_sum(bh,a)
   v = bl+sl
   return fast_two_sum (sh, v)

def d_div_acc3(xh,xl,yh,yl):
   R = xh.parent()
   th = R(1)/yh
   rh = fma(-yh,th,R(1))
   rl = -yl * th
   eh, el = fast_two_sum (rh, rl)
   delta_h, delta_l = s_mul_acc3 (th, eh, el)
   mh, ml = fast_sum_acc (th, delta_h, delta_l)
   return d_mul_acc2 (xh, xl, mh, ml)

# check_d_div(K=10^3,algo=d_div)
# (7.53428059629510, '0x1.0edf470f8b83ap-1', '0x1.9e9b29954926ap-55', '0x1.58a5a5e6b7712p-1', '-0x1.e45428392cc88p-55')
# check_d_div(K=10^3,algo=d_div_km)
# (9.69034290379382, '0x1.20dd93867d2cap-1', '0x1p-54', '0x1.a3f6e77b9009bp-1', '-0x1p-54')
# check_d_div(K=10^6,algo=d_div_acc1) # claimed 15u^2
# (7.42804911615377, '0x1.135fab4fd00c3p-1', '-0x1.f0ab7bcb3731ep-55', '0x1.094707cfda765p-1', '0x1.e1b46b8494984p-55')
# check_d_div(K=10^6,algo=d_div_acc2) # claimed 15u^2
# (8.22879495090911, '0x1.00b919d04d85ep-1', '-0x1.947c0b3767baep-55', '0x1.00663cc3de7a6p-1', '0x1.fe3641bcf83a8p-55')
# check_d_div(K=10^7,algo=d_div_acc3) # claimed 9.8u^2
# (6.14445119186478, '0x1.0fa02facd65b7p-1', '0x1.f3c804abc91e4p-55', '0x1.f7287d4eeff91p-1', '0x1.be362fd31dc42p-55')
def check_d_div(K=10^6,rnd='RNDN',algo=d_div,worst=false,amin=1/2,amax=1,bmin=1/2,bmax=1):
   maxerr = max_ah = max_al = max_bh = max_bl = 0
   R = RealField(53,rnd=rnd)
   amin,amax,bmin,bmax = RR(amin),RR(amax),RR(bmin),RR(bmax)
   wa = width(amin,amax)
   wb = width(bmin,bmax)
   if wa*wb<=K: # exhaustive search
      ah = amin
      al = get_low(ah,worst)
      for i in range(wa):
         bh = bmin
         for j in range(wb):
            bl = get_low(bh,worst)
            err = get_div_err(ah,al,bh,bl,algo)
            if err>maxerr:
               maxerr,max_ah,max_al,max_bh,max_bl = err,ah,al,bh,bl
            bh = bh.nextabove()
         ah = ah.nextabove()
         al = get_low(ah,worst)
      return maxerr,get_hex(max_ah),get_hex(max_al),get_hex(max_bh),get_hex(max_bl)
   for k in range(K): # random search
      ah = R.random_element(amin,amax)
      al = get_low(ah,worst,k//2)
      bh = R.random_element(bmin,bmax)
      bl = get_low(bh,worst,(k//4)+(k%2))
      err = get_div_err(ah,al,bh,bl,algo)
      if err>maxerr:
         maxerr,max_ah,max_al,max_bh,max_bl = err,ah,al,bh,bl
   return maxerr,get_hex(max_ah),get_hex(max_al),get_hex(max_bh),get_hex(max_bl)

def width(amin,amax):
   return ZZ((amax-amin)/amin.ulp())

# for worst=false:
# if ind=0, generate -ah.ulp()/2
# if ind=1, generate +ah.ulp()/2
# otherwise generate random number
def get_low(ah,worst,ind=2):
   R = ah.parent()
   if worst==false:
      if ind==0:
         al = -ah.ulp()/2
      elif ind==1:
         al = ah.ulp()/2
      else:
         al = R.random_element()*ah.ulp()/2
   else:
      if abs(ah.exact_rational().numer()) < 2^52:
         al = ah.ulp()/2
      else:
         al = (ah.ulp()/2).nextbelow()
      if randint(0,1)==1:
         al = -al
   return al

def cmp_err(a,b):
   if a[0]>b[0]:
      return int(-1)
   else:
      return int(1)

# check_sample(K=10^3,algo=d_div)
# (7.89381229048650, '0x1.151bc17debf99p-1', '-0x1.e7743a7f635f2p-55', '0x1.ffcdd1b14cc2ap-1', '0x1.ffa244763324ap-55')
# check_sample(K=10^5,algo=d_div_km)
# (9.69535480980671, '0x1.0367eb6da3d3ap-1', '0x1.e1b93ac80f2fcp-55', '0x1.035d0b42545c3p-1', '-0x1.fbb057cf474cap-55')
# check_sample(K=10^3,algo=d_div_acc1)
# (7.34857497724341, '0x1.0fb3501b33a74p-1', '0x1.fb43080f5c5b2p-55', '0x1.05ab719e40ef7p-1', '-0x1.d4a50d17c7dacp-55')
# check_sample(K=10^3,algo=d_div_acc2)
# (6.78734053466836, '0x1.20e3c993988d9p-1', '-0x1.7333d5916b282p-55', '0x1.082fbaacc10d9p-1', '0x1.c8970b8375c9ep-55')
# check_sample(K=10^5,algo=d_div_acc3)
# (6.77733714740326, '0x1.008e43ff0b527p-1', '-0x1.d2535fa3356e6p-55', '0x1.fe3e7a576f00dp-1', '-0x1.ff617c0ea825ep-55')
def check_sample(K=10^6,rnd='RNDN',algo=d_div,worst=false,samples=20):
   R = RealField(53,rnd=rnd)
   best = 0,0,0,0,0
   amin = bmin = R(1/2)
   amax = bmax = R(1)
   L = [(0,amin,amax,bmin,bmax)]
   w = width(amin,amax)*width(bmin,bmax)
   while w>K:
      newL = []
      for _,amin,amax,bmin,bmax in L:
         amid = (amin+amax)/2
         bmid = (bmin+bmax)/2
         for [a0,a1,b0,b1] in [(amin,amid,bmin,bmid),(amin,amid,bmid,bmax),(amid,amax,bmin,bmid),(amid,amax,bmid,bmax)]:
            err = check_d_div(K=K,rnd=rnd,algo=algo,worst=worst,amin=a0,amax=a1,bmin=b0,bmax=b1)
            if err[0]>best[0]:
               best = err
            newL.append((err[0],a0,a1,b0,b1))
      L = newL
      L.sort(key=cmp_to_key(cmp_err))
      if len(L)>samples:
         L = L[:samples]
      # print ([x[0] for x in L])
      w = ceil(w/4)
      print (best)
   print(best)

def get_div_err(ah,al,bh,bl,algo):
   u = 2^-53.
   hi, lo = algo(ah,al,bh,bl)
   a = ah.exact_rational()+al.exact_rational()
   b = bh.exact_rational()+bl.exact_rational()
   r = a/b
   err = n((hi.exact_rational()+lo.exact_rational())/r-1,200)
   return abs(err)/u^2
         
# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

def analyze_eval_T(wmin,wmax,rel=false,verbose=false):
   w = RIF(wmin,wmax)
   if rel==false:
      err0 = 2^-80.528
   else: # |tanh(x)/x| < 1
      err0 = 2^-71.98*w.abs().upper()
   T = ["0x1p0","-0x1.5555555555553p-2","0x1.111111103f43cp-3","-0x1.ba18e77264096p-5"]
   T = [RR(x,16) for x in T]
   # z = w * w
   z = w*w
   errz = RIFulp(z)
   # *h = __builtin_fma (TT[3], z, TT[2])
   h = T[3]*z+T[2]
   err1 = (RIFulp(h)+T[3]*errz)*w.abs().upper()^5
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # *h = __builtin_fma (*h, z, TT[1])
   hin = h
   h = hin*z+T[1]
   err2 = (RIFulp(h)+hin.abs().upper()*errz)*w.abs().upper()^3
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # *h = *h * z
   hin = h
   h = h*z
   err3 = (RIFulp(h)+hin.abs().upper()*errz)*w.abs().upper()
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # fast_two_sum (h, l, w, *h * w)
   h = w + h*w
   err4 = 2^-105*h.abs().upper()
   if verbose:
      print ("err4=", log(err4)/log(2.))
   err = err0+err1+err2+err3+err4
   if rel:
      err = err/h.abs().lower()
   if verbose:
      print ("err=", log(err)/log(2.))
   return err

# analyze_eval_T_all()
# 2.47926464106338e-23
# analyze_eval_T_all(rel=true)
# 9.35004837242004e-21
def analyze_eval_T_all(rel=false):
   maxerr = 0
   e = 0
   while true:
      wmax = 0.00543*2^e
      wmin = wmax/2
      err = analyze_eval_T(wmin,wmax,rel=rel)
      if err>maxerr:
         print ("e=", e, "err=", err)
         maxerr = err
      err = analyze_eval_T(-wmax,-wmin,rel=rel)
      if err>maxerr:
         print ("e=", e, "err=", err)
         maxerr = err
      if wmin<2^-1074:
         break
      e = e-1
   return maxerr

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
# [((8183583624766079, -79), (5365348628892106, -48))]
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
