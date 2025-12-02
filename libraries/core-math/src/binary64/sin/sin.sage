#load("../../generic/support/common.sage")
# compute table for 1/(2pi)
def computeT():
   x = n(1/(2*pi),2000)
   m = ZZ(floor(x.exact_rational()*2^1280))
   l = m.digits(2^64)
   print ("static const uint64_t T[" + str(len(l)) + "] = {")
   for i in range(len(l)-1,-1,-1):
      print ("   " + hex(l[i]) + ",")
   print ("};")

# given x a 128-bit float, print it
def out_dint(x):
   s, m, e = x.sign_mantissa_exponent()
   while m!=0 and m.nbits()<128:
      m *= 2
      e -= 1
   h, l = divmod(m,2^64)
   print ("  {.hi = " + hex(h) + ", .lo = " + hex(l) + ", .ex = " + str(e+128) + ", .sgn=" + str((1-s)/2) + "},")

# compute table of sin(2*pi*i/2^11) for 0 <= i < 256
def computeS(out=true):
   R = RealField(128)
   if out:
      print ("static const dint64_t S[256] = {")
   S = []
   for i in range(256):
      s = n(sin(2*pi*i/2^11), 512)
      s = R(s)
      if out:
         out_dint(s)
      S.append(s)
   if out:
      print ("};")
   return S

# compute table of cos(2*pi*i/2^11) for 0 <= i < 256
def computeC(out=true):
   R = RealField(128)
   if out:
      print ("static const dint64_t C[256] = {")
   C = []
   for i in range(256):
      s = n(cos(2*pi*i/2^11), 512)
      s = R(s)
      if out:
         out_dint (s)
      C.append(s)
   if out:
      print ("};")
   return C

# implement Algorithm 2.1 from https://www.vinc17.net/research/papers/these.pdf
# finds the smallest distance between y=a*x-b and integers, 0 <= x < N
# return d the smallest distance, and x the corresponding value
def AlgoLefevre(a,b,N):
   x = frac(a)
   y = 1-frac(a)
   d = frac(b)
   u = v = 1
   j = 0
   # invariant: d = j*frac(a) - frac(b) mod 1
   while true:
      if d<x:
         while x<y:
            if u+v>=N:
               break
            y = y-x
            u = u+v
         if u+v>=N:
            break
         x = x-y
         v = v+u
      else:
         d = d-x
         j += v
         while y<x:
            if u+v>=N:
               break
            x = x-y
            v = v+u
         if u+v>=N:
            break
         y = y-x
         u = u+v
      if u+v>=N:
         break
   return d, j

# return x with smallest value of |x/(2pi) cmod 1| for 2^(e-1) <= x < 2^e
def search(e):
   R = RealField(e+200)
   N = 2^52
   b = R(2^(e-1)/(2*pi))
   b = frac(-b)
   if b < 0:
     b = 1+b
   assert b > 0, "b > 0"
   a = R(2^(e-53)/(2*pi))
   a = frac(a)
   assert a > 0, "a > 0"
   oldx = -1
   d, x = AlgoLefevre(a,b,N)
   d, x = AlgoLefevre(a,b+R(d),N)
   x = RR(2^(e-1)+x*2^(e-53))
   return x

def search_naive(e):
   x0 = RR(2^(e-1))
   x1 = RR(2^e)
   k0 = floor(x0/(2*pi))
   k1 = ceil(x1/(2*pi))
   k = max(1,k0)
   mindiff = 1
   best = None
   while k<=k1:
      x = RR(n(k*2*pi,200))
      X = x.exact_rational()
      diff = abs(n(X/(2*pi)-k,200))
      if diff<mindiff:
         best = x
         mindiff = diff
      k += 1
   return best, mindiff

def search_all():
   for e in range(1024,1,-1):
      x = search(e)
      print (get_hex(x) + ' # ' + str(e))

def search2_naive(e):
   x0 = RR(2^(e-1))
   x1 = RR(2^e)
   k0 = floor(x0/pi)
   k1 = ceil(x1/pi)
   k = max(1,k0)
   mindiff = 1
   best = None
   while k<=k1:
      x = RR(n(k*pi,200))
      X = x.exact_rational()
      diff = abs(n(X/pi-k,200))
      if diff<mindiff:
         best = x
         mindiff = diff
      k += 1
   return best, mindiff

# return x with smallest value of |x/pi cmod 1| for 2^(e-1) <= x < 2^e
def search2(e):
   R = RealField(e+200)
   N = 2^52
   b = R(2^(e-1)/pi)
   b = frac(-b)
   if b < 0:
     b = 1+b
   assert b > 0, "b > 0"
   a = R(2^(e-53)/pi)
   a = frac(a)
   assert a > 0, "a > 0"
   oldx = -1
   d, x = AlgoLefevre(a,b,N)
   d, x = AlgoLefevre(a,b+R(d),N)
   x = RR(2^(e-1)+x*2^(e-53))
   return x

def search2_all():
   for e in range(1024,1,-1):
      x = search2(e)
      print (get_hex(x) + ' # ' + str(e))

def out_str(s,out):
   if out==None:
      print(s)
   else:
      out.write(s + '\n')

# for 2^(e-1) <= x < 2^e
# sin(x) is monotonous between (k-1/2)*pi and (k+1/2)*pi
# also avoid roots at k*pi
def doit_bacsel(e,i0=0,i1=infinity,margin=2*10^7,out=None):
   if out != None:
      out = open(out,"w")
   x0 = 2^(e-1)
   k0 = ceil(x0/(pi/2))
   x1 = 2^e
   k1 = floor(x1/(pi/2))
   t1 = RR(n(k0*pi/2,200))
   t1 = ZZ(t1.exact_rational()*2^(53-e))-margin
   i = 0
   if 2^52<t1:
      if i0 <= i < i1:
         out_str ("./doit.sh 4503599627370496 " + str(t1) + " 53 " + str(e) + " 64 20", out)
      i += 1
   else:
      t1 = 2^52
   for k in range(k0+1,k1+2):
      t0 = t1
      t1 = min(t0 + 2*margin,2^53)
      if i0 <= i < i1:
         out_str ("./doit0.sh " + str(t0) + " " + str(t1) + " 53 " + str(e) + " 64 20", out)
      i += 1
      if k==k1+1:
         break
      t0 = t1
      t1 = RR(n(k*pi/2,200))
      t1 = ZZ(t1.exact_rational()*2^(53-e))-margin
      if t0<t1:
         if i0 <= i < i1:
            out_str ("./doit.sh " + str(t0) + " " + str(t1) + " 53 " + str(e) + " 64 20", out)
         i += 1
      else:
         t1 = t0
   t0 = t1
   if t0<2^53:
      if i0 <= i < i1:
         out_str ("./doit.sh " + str(t0) + " 9007199254740992 53 " + str(e) + " 64 20", out)
      i += 1
   if out != None:
      out.close()
   
# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# error analysis of evalPC()
# evalPC()
# (1.00000?, 1.1755288837865430349512422633250043508e-38)
def evalPC(verbose=false):
   RIF128 = RealIntervalField(128)
   X = RIF128(0,2^-11)
   # mul_dint (X2, X, X)
   X2 = X*X
   errX2 = 6*RIFulp(X2)
   PC = [(0x8000000000000000, 0x0, 1, 0),
         (0x9de9e64df22ef2d2, 0x56e26cd9808c1949, 5, 1),
         (0x81e0f840dad61d9a, 0x9980f00630cb655e, 7, 0),
         (0xaae9e3f1e5ffcfe2, 0xa508509534006249, 7, 1),
         (0xf0fa83448dd1e094, 0xe0603ce7044eeba, 6, 0),
	 (0xd368f6f4207cfe49, 0xec63157807ebffa, 5, 1)]
   PC = [2^x[2]*(x[0]/2^64+x[1]/2^128)*(-1)^x[3] for x in PC]
   PC = [RIF128(x) for x in PC]
   # mul_dint_21 (Y, X2, PC+5)
   Y = X2*PC[5]
   err1 = (2*RIFulp(Y)+errX2*PC[5].abs().upper())*X2.abs().upper()^4
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # add_dint (Y, Y, PC+4)
   Y = Y+PC[4]
   err2 = 2*RIFulp(Y)*X2.abs().upper()^4
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err3 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X2.abs().upper()^3
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # add_dint (Y, Y, PC+3)
   Y = Y+PC[3]
   err4 = 2*RIFulp(Y)*X2.abs().upper()^3
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err5 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X2.abs().upper()^2
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # add_dint (Y, Y, PC+2)
   Y = Y+PC[2]
   err6 = 2*RIFulp(Y)*X2.abs().upper()^2
   if verbose:
      print ("err6=", log(err6)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err7 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X2.abs().upper()
   if verbose:
      print ("err7=", log(err7)/log(2.))
   # add_dint (Y, Y, PC+1)
   Y = Y+PC[1]
   err8 = 2*RIFulp(Y)*X2.abs().upper()
   if verbose:
      print ("err8=", log(err8)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err9 = 6*RIFulp(Y)+Yin.abs().upper()*errX2
   if verbose:
      print ("err9=", log(err9)/log(2.))
   # add_dint (Y, Y, PC+0)
   Y = Y+PC[0]
   err10 = 2*RIFulp(Y)
   if verbose:
      print ("err10=", log(err10)/log(2.))
   err = err1+err2+err3+err4+err5+err6+err7+err8+err9+err10
   if verbose:
      print ("abs err=", log(err)/log(2.))
   return Y, err

# error analysis of evalPS()
# evalPS()
# (0.01?, 9.1838643693027966097514749319048050847e-41)
def evalPS(verbose=false,xmin=0,xmax=2^-11,rel=false):
   RIF128 = RealIntervalField(128)
   X = RIF128(xmin,xmax)
   # mul_dint (X2, X, X)
   X2 = X*X
   errX2 = 6*RIFulp(X2)
   PS = [(0xc90fdaa22168c234, 0xc4c6628b80dc1cd1, 3, 0),
         (0xa55de7312df295f5, 0x5dc72f712aa57db4, 6, 1),
	 (0xa335e33bad570e92, 0x3f33be0021aa54d2, 7, 0),
	 (0x9969667315ec2d9d, 0xe59d6ab8509a2025, 7, 1),
	 (0xa83c1a43bf1c6485, 0x7d5f8f76fa7d74ed, 6, 0),
	 (0xf16ab2898eae62f9, 0xa7f0339113b8b3c5, 4, 1)]
   PS = [2^x[2]*(x[0]/2^64+x[1]/2^128)*(-1)^x[3] for x in PS]
   PS = [RIF128(x) for x in PS]
   # mul_dint_21 (Y, X2, PS+5)
   Y = X2*PS[5]
   err1 = (2*RIFulp(Y)+errX2*PS[5].abs().upper())*X.abs().upper()^9
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # add_dint (Y, Y, PS+4)
   Y = Y+PS[4]
   err2 = 2*RIFulp(Y)*X.abs().upper()^9
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err3 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X.abs().upper()^7
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # add_dint (Y, Y, PS+3)
   Y = Y+PS[3]
   err4 = 2*RIFulp(Y)*X.abs().upper()^7
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err5 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X.abs().upper()^5
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # add_dint (Y, Y, PS+2)
   Y = Y+PS[2]
   err6 = 2*RIFulp(Y)*X.abs().upper()^5
   if verbose:
      print ("err6=", log(err6)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err7 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X.abs().upper()^3
   if verbose:
      print ("err7=", log(err7)/log(2.))
   # add_dint (Y, Y, PS+1)
   Y = Y+PS[1]
   err8 = 2*RIFulp(Y)*X.abs().upper()^3
   if verbose:
      print ("err8=", log(err8)/log(2.))
   # mul_dint (Y, Y, X2)
   Yin = Y
   Y = Y*X2
   err9 = (6*RIFulp(Y)+Yin.abs().upper()*errX2)*X.abs().upper()
   if verbose:
      print ("err9=", log(err9)/log(2.))
   # add_dint (Y, Y, PS+0)
   Y = Y+PS[0]
   err10 = 2*RIFulp(Y)*X.abs().upper()
   if verbose:
      print ("err10=", log(err10)/log(2.))
   # mul_dint (Y, Y, X)
   Yin = Y
   Y = Y*X
   err11 = 6*RIFulp(Y)
   if verbose:
      print ("err11=", log(err11)/log(2.))
   err = err1+err2+err3+err4+err5+err6+err7+err8+err9+err10+err11
   if verbose:
      print ("abs err=", log(err)/log(2.))
      print ("Y=", Y.lower(), Y.upper())
   if rel: # convert to relative error
      err = err/Y.abs().lower()
   if verbose:
      print ("rel err=", log(err)/log(2.))
   return Y, err

# relative error for evalPS
# evalPSrel()
# e= -1073 err= 5.9867435683188998247557269010591102197e-38
# evalPSrel(K=1)
# e= -1073 k= 1 err= 3.9911623788792665498371512673727401464e-38
# evalPSrel(K=2)
# e= -1073 k= 3 err= 3.4209963247536570427175582291766344112e-38
# evalPSrel(K=8)
# e= -1073 k= 255 err= 2.9992296545785486401907359817438986619e-38
def evalPSrel(K=0):
   maxerr = 0
   for e in range(-11,-1074,-1):
      # subdivide [2^(e-1),2^e] into 2^K subintervals
      for k in range(2^K):
         _, err = evalPS(xmin=2^(e-1)+k*2^(e-1-K),xmax=2^(e-1)+(k+1)*2^(e-1-K),rel=true)
      if err>maxerr:
         print ("e=", e, "k=", k, "err=", err)
   return maxerr

# analyze the rounding error when is_sin=1
# analyze_sin_case1()
# i= 255 err= 3.4878355837391092918018785682632564712e-38
# analyze_sin_case1(rel=true)
# i= 1 err= 1.0823752525137881722193875252693985550e-37 U= (0.0030679423245659126978045966430539338192, 0.0061359039003258701610125534976731766997)
def analyze_sin_case1(rel=false):
   maxerr = 0
   S = computeS(out=false)
   C = computeC(out=false)
   RIF128 = RealIntervalField(128)
   for i in range(1,256):
      U, errU = evalPC()
      V, errV = evalPS()
      # also consider relative error bound of 2^-124.648 from evalPSrel(K=8)
      print (i, errV, 2^-124.648*V.abs().upper())
      errV = min(errV, 2^-124.648*V.abs().upper())
      # mul_dint (U, S+i, U)
      Si = RIF128(S[i])
      Uin = U
      U = Si*U
      err1 = 6*RIFulp(U)+Si.abs().upper()*errU+RIFulp(Si)*Uin.abs().upper()
      # mul_dint (V, C+i, V)
      Ci = RIF128(C[i])
      Vin = V
      V = Ci*V
      err2 = 6*RIFulp(V)+Ci.abs().upper()*errV+RIFulp(Ci)*Vin.abs().upper()
      # add_dint (U, U, V)
      U = U+V
      err3 = 2*RIFulp(U)
      err = err1+err2+err3
      if rel: # convert to relative error
         err = err/U.abs().lower()
      if err>maxerr:
         maxerr = err
         print ("i=", i, "err=", err, "U=", (U.lower(), U.upper()))

# analyze the rounding error when is_sin=0
# analyze_sin_case2()
# i= 0 err= 6.4652534624868368208105566808251099011e-38 U= (0.99999529380588479549473818088006979171, 1.0000000000000000000000000000000000000)
# analyze_sin_case2(rel=true)
# i= 0 err= 6.4652838893678300901881719744254043831e-38 U= (0.99999529380588479549473818088006979171, 1.0000000000000000000000000000000000000)
def analyze_sin_case2(rel=false):
   maxerr = 0
   S = computeS(out=false)
   C = computeC(out=false)
   RIF128 = RealIntervalField(128)
   for i in range(0,256):
      U, errU = evalPC()
      V, errV = evalPS()
      # also consider relative error bound of 2^-124.648 from evalPSrel
      errV = min(errV, 2^-124.648*V.abs().upper())
      # mul_dint (U, C+i, U)
      Ci = RIF128(C[i])
      Uin = U
      U = Ci*U
      err1 = 6*RIFulp(U)+Ci.abs().upper()*errU+RIFulp(Ci)*Uin.abs().upper()
      # mul_dint (V, S+i, V)
      Si = RIF128(S[i])
      Vin = V
      V = Si*V
      err2 = 6*RIFulp(V)+Si.abs().upper()*errV+RIFulp(Si)*Vin.abs().upper()
      # add_dint (U, U, V)
      U = U+V
      err3 = 2*RIFulp(U)
      err = err1+err2+err3
      if rel: # convert to relative error
         err = err/U.abs().lower()
      if err>maxerr:
         maxerr = err
         print ("i=", i, "err=", err, "U=", (U.lower(), U.upper()))
      
def repair():
   f = open("torepair","r")
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split()
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      n = ZZ(s[2])
      assert n == 53
      e = ZZ(s[3])
      nthreads = ZZ(s[4])
      assert nthreads == 64
      t = ZZ(s[5])
      assert t == 20
      # find root of sin(x)
      x0 = t0/2^53*2^e
      x1 = t1/2^53*2^e
      k0 = ceil(x0/pi)
      k1 = floor(x1/pi)
      assert k0==k1, "k0==k1"
      tm = round(k0*pi*2^53/2^e)
      print ("./doit.sh " + str(t0) + " " + str(tm-10^7) + " 53 " + str(e) + " 64 20")
      print ("./doit0.sh " + str(tm-10^7) + " " + str(tm+10^7) + " 53 " + str(e) + " 64 20")
      print ("./doit.sh " + str(tm+10^7) + " " + str(t1) + " 53 " + str(e) + " 64 20")
   f.close()

def a_mul(a,b):
   hi = a*b
   u = RIFulp(hi)
   lo = RIF(-u,u)
   return hi,lo

def s_mul(a,bh,bl):
   hi, lo = a_mul(a,bh)
   lo = a*bl+lo
   return hi, lo

def d_mul(ah,al,bh,bl):
   hi, s = a_mul(ah,bh)
   t = al*bh+s
   lo = ah*bl+t
   return hi,lo, (RIFulp(t)+RIFulp(lo)+RIF(al)*RIF(bl)).abs().upper()

# analyze the absolute error of evalPSfast
# evalPSfast()
# (6.1802126185954?e-24, 0.00?, 0.?e-14)
def evalPSfast(verbose=false,xh=None,xl=None):
   P7 = RR("-0x1.33155a7aff959p6",16)
   P5 = RR("0x1.466bc678d8e3fp6", 16)
   P3 = RR("-0x1.4abbce625be53p5", 16)
   P1h = RR("0x1.921fb54442d18p+2", 16)
   P1l = RR("0x1.1a62645458ee1p-52", 16)
   err0 = 2^-77.306
   if xh==None:
      xh = RIF(-2^-24,2^-11+2^-24)
   if xl==None:
      xl = 2^-52.36
      xl = RIF(-xl,xl)
   # a_mul (&uh, &ul, xh, xh)
   uh = xh*xh
   err_uh = RIFulp(uh)
   ul = RIF(-err_uh,err_uh)
   # ul = __builtin_fma (xh + xh, xl, ul)
   ul = (xh+xh)*xl+ul
   # *h = PSfast[4]
   h = RIF(P7)
   # *h = __builtin_fma (*h, uh, PSfast[3])
   hin = h
   h = hin*uh+RIF(P5)
   err1 = (RIFulp(h)+hin*err_uh)*xh.abs().upper()^5
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # *h = __builtin_fma (*h, uh, PSfast[2])
   hin = h
   h = hin*uh+RIF(P3)
   err2 = (RIFulp(h)+hin*err_uh)*xh.abs().upper()^3
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # s_mul (h, l, *h, uh, ul)
   h, l = s_mul (h, uh, ul)
   err3 = RIFulp(l)*xh.abs().upper()
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # fast_two_sum (h, &t, PSfast[0], *h)
   h = P1h + h
   u = RIFulp(h)
   t = RIF(-u,u)
   err4 = h.abs().upper()*2^-105*xh.abs().upper()
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # *l += PSfast[1] + t
   tmp = P1l + t
   l = l + tmp
   err5 = (RIFulp(tmp)+RIFulp(l))*xh.abs().upper()
   if verbose:
      print ("err5=", log(err5)/log(2.))
   # d_mul (h, l, *h, *l, xh, xl)
   h, l, err6 = d_mul(h,l,xh,xl)
   if verbose:
      print ("err6=", log(err6)/log(2.))
   err = err0+err1+err2+err3+err4+err5+err6
   if verbose:
      print ("err=", log(err)/log(2.))
   return err, h, l

# return relative error bound for evalPSfast
def evalPSfast_rel():
   maxerr = 0
   xh = 2^-11+2^-24
   e = 0
   while xh > 2^-20:
      # positive values
      t = RIF(xh/2,xh)
      err, sh, sl = evalPSfast(xh=t)
      # convert to relative error
      err = err/t.lower().abs()
      if err > maxerr:
         maxerr = err
         print ("+ e=", e, "relerr=", err)
      # negative values
      t = RIF(-xh,-xh/2)
      err, sh, sl = evalPSfast(xh=t)
      # convert to relative error
      err = err/t.lower().abs()
      if err > maxerr:
         maxerr = err
         print ("- e=", e, "relerr=", err)
      xh = xh/2
      e += 1
   return maxerr

# return relative error bound for evalPSfast
# 0x1.7137449123ef6p-26 < x < +Inf
# 0x1.d619ab67d1407p-29 < x/(2pi)
# e= -28 i= 0 err= -77.0995535331724?
def evalPSfast_all():
   maxerr = 0
   for e in [-28..0]:
      # 2^(e-1) <= x < 2^e
      x = RIF(2^(e-1),2^e)
      imin = floor(x.lower()*2^11)
      imax = floor(x.upper()*2^11)
      for i in [imin..imax]:
         # write x as i/2^11 + h + l
         h = RIF(max(0,x.lower()-i*2^-11),min(2^-11,x.upper()-i*2^-11))
         l = x.upper()*2^-51.64 # the 2^-51.64 bound comes from reduce_fast()
         err,sh,sl = evalPSfast(xh=h,xl=l)
         # convert to relative error
         err = err/(sh+sl).abs().lower()
         if err>maxerr:
            maxerr = err
            print ("e=", e, "i=", i, "err=", log(err)/log(2.))

# analyze the absolute error of	evalPCfast
# evalPCfast(rel=true)
# (8.70477132605?e-22, 1.00000?, 0.?e-15)
def evalPCfast(verbose=false,xh=None,xl=None,rel=false):
   P6 = RR("-0x1.55a5c19e443dcp6",16)
   P4 = RR("0x1.03c1f080ad7f9p6", 16)
   P2 = RR("-0x1.3bd3cc9be45dep4", 16)
   P0h = RR("0x1p+0", 16)
   P0l = RR("-0x1.9249c1ep-77", 16)
   err0 = 2^-75.188
   if xh==None:
      xh = RIF(-2^-24,2^-11+2^-24)
   if xl==None:
      xl = 2^-52.36
      xl = RIF(-xl,xl)
   # a_mul (&uh, &ul, xh, xh)
   uh = xh*xh
   err_uh = RIFulp(uh)
   ul = RIF(-err_uh,err_uh)
   # ul = __builtin_fma (xh + xh, xl, ul)
   ul = (xh+xh)*xl+ul
   # *h = PCfast[4]
   h = RIF(P6)
   # *h = __builtin_fma (*h, uh, PCfast[3])
   hin = h
   h = hin*uh+RIF(P4)
   err1 = (RIFulp(h)+hin*err_uh)*xh.abs().upper()^4
   if verbose:
      print ("err1=", log(err1)/log(2.))
   # *h = __builtin_fma (*h, uh, PCfast[2])
   hin = h
   h = hin*uh+RIF(P2)
   err2 = (RIFulp(h)+hin*err_uh)*xh.abs().upper()^2
   if verbose:
      print ("err2=", log(err2)/log(2.))
   # s_mul (h, l, *h, uh, ul)
   h, l = s_mul (h, uh, ul)
   err3 = RIFulp(l)*xh.abs().upper()
   if verbose:
      print ("err3=", log(err3)/log(2.))
   # fast_two_sum (h, &t, PCfast[0], *h)
   h = P0h + h
   u = RIFulp(h)
   t = RIF(-u,u)
   err4 = h.abs().upper()*2^-105
   if verbose:
      print ("err4=", log(err4)/log(2.))
   # *l += PCfast[1] + t
   tmp = P0l + t
   l = l + tmp
   err5 = (RIFulp(tmp)+RIFulp(l))*xh.abs().upper()
   if verbose:
      print ("err5=", log(err5)/log(2.))
   err = err0+err1+err2+err3+err4+err5
   if verbose:
      print ("err=", log(err)/log(2.))
   if rel:
      # convert to relative error
      err = err/(h+l).abs().lower()
   return err, h, l

SC=[
   ("0x0p+0", "0x0p+0", "0x1p+0"),
   ("-0x1.c0f6cp-35", "0x1.921f892b900fep-9", "0x1.ffff621623fap-1"),
   ("-0x1.9c7935ep-35", "0x1.921f0ea27ce01p-8", "0x1.fffd8858eca2ep-1"),
   ("-0x1.d14d1acp-34", "0x1.2d96af779b0bbp-7", "0x1.fffa72c986392p-1"),
   ("-0x1.dba8f6a8p-33", "0x1.921d1ce2d0a1cp-7", "0x1.fff62169dddaap-1"),
   ("0x1.a6b7cdfp-32", "0x1.f6a29bdb7377p-7", "0x1.fff0943c02419p-1"),
   ("0x1.b49618dp-33", "0x1.2d936d1506f3dp-6", "0x1.ffe9cb44829cp-1"),
   ("-0x1.398d6fcp-35", "0x1.5fd4d1e21de6dp-6", "0x1.ffe1c687174b1p-1"),
   ("-0x1.e9e9a8c8p-31", "0x1.9215597791e0ap-6", "0x1.ffd886097afcfp-1"),
   ("-0x1.34e844cp-32", "0x1.c454f2e9480c7p-6", "0x1.ffce09ce95933p-1"),
   ("-0x1.989a8a4p-32", "0x1.f693709b94f92p-6", "0x1.ffc251dfbac0cp-1"),
   ("0x1.04a9b99p-30", "0x1.146860e69a571p-5", "0x1.ffb55e40a5c43p-1"),
   ("-0x1.56947cp-36", "0x1.2d865748774adp-5", "0x1.ffa72efff95d1p-1"),
   ("-0x1.c348768p-35", "0x1.46a396d34121ap-5", "0x1.ff97c420a8451p-1"),
   ("0x1.9e80552p-32", "0x1.5fc00e6e4c65cp-5", "0x1.ff871dacd8761p-1"),
   ("0x1.3f11d74p-34", "0x1.78dbaa97099ebp-5", "0x1.ff753bb18af95p-1"),
   ("0x1.c039af4p-33", "0x1.91f65fc0abc0ap-5", "0x1.ff621e370ca7ap-1"),
   ("0x1.53e1f8p-35", "0x1.ab101bf74ac2ep-5", "0x1.ff4dc54b00181p-1"),
   ("0x1.114a649p-29", "0x1.c428d7de920e9p-5", "0x1.ff3830f2e9043p-1"),
   ("0x1.adf0ef4p-31", "0x1.dd40723a3cdfbp-5", "0x1.ff21614b9d9adp-1"),
   ("-0x1.d21f5918p-30", "0x1.f656e1e9e59cdp-5", "0x1.ff09565e83d77p-1"),
   ("-0x1.4f54d708p-30", "0x1.07b612d6be078p-4", "0x1.fef0102c634e3p-1"),
   ("-0x1.1efec9ap-30", "0x1.1440118ba7bdp-4", "0x1.fed58ecf342dap-1"),
   ("0x1.cc17ba88p-29", "0x1.20c96cf0a7eedp-4", "0x1.feb9d24646fa6p-1"),
   ("0x1.121dbe4p-33", "0x1.2d5209628edfp-4", "0x1.fe9cdacf99cffp-1"),
   ("-0x1.9ecf61p-34", "0x1.39d9f103bf7f7p-4", "0x1.fe7ea854e6b08p-1"),
   ("-0x1.04ede8ep-31", "0x1.466116c629e5cp-4", "0x1.fe5f3af4ee201p-1"),
   ("-0x1.1821cecp-31", "0x1.52e773c9920c7p-4", "0x1.fe3e92c0e4108p-1"),
   ("0x1.cdec726p-31", "0x1.5f6d02131f0b2p-4", "0x1.fe1cafc7f1a24p-1"),
   ("-0x1.edece4dp-31", "0x1.6bf1b2653648cp-4", "0x1.fdf99233c230cp-1"),
   ("-0x1.2aa4d1cp-31", "0x1.787585bc45f0fp-4", "0x1.fdd53a01d11d9p-1"),
   ("0x1.d461592p-32", "0x1.84f871e32cf68p-4", "0x1.fdafa74f16482p-1"),
   ("0x1.f0cbd728p-29", "0x1.917a71d3d2956p-4", "0x1.fd88da29f302ep-1"),
   ("-0x1.583247p-30", "0x1.9dfb6c9865b06p-4", "0x1.fd60d2e14a6b1p-1"),
   ("-0x1.2e81bf4p-30", "0x1.aa7b706bfdbbap-4", "0x1.fd3791484ff5p-1"),
   ("-0x1.13941418p-28", "0x1.b6fa680a05c27p-4", "0x1.fd0d15a4b8471p-1"),
   ("0x1.71098ffp-30", "0x1.c3785eba12b42p-4", "0x1.fce15fceddccfp-1"),
   ("-0x1.c3519e8p-32", "0x1.cff53302f059p-4", "0x1.fcb4703b969e1p-1"),
   ("0x1.2f522a5p-27", "0x1.dc70fb84af16ep-4", "0x1.fc8646987fc1dp-1"),
   ("-0x1.ae9bed8p-33", "0x1.e8eb7f8a589e2p-4", "0x1.fc56e3b91ca3ap-1"),
   ("0x1.f8868b2p-30", "0x1.f564e87d2330fp-4", "0x1.fc264701f9a09p-1"),
   ("-0x1.b07985f8p-29", "0x1.00ee8835051f4p-3", "0x1.fbf47105f7439p-1"),
   ("0x1.cbdaa94p-30", "0x1.072a05e1d4d8ep-3", "0x1.fbc16172a9e36p-1"),
   ("0x1.37c5b908p-28", "0x1.0d64df9619f0dp-3", "0x1.fb8d18b635327p-1"),
   ("-0x1.068b5fc8p-28", "0x1.139f09bc617f5p-3", "0x1.fb5797351da85p-1"),
   ("-0x1.8ea66818p-29", "0x1.19d8919fa4ec8p-3", "0x1.fb20dc7da8affp-1"),
   ("0x1.6278ceb8p-28", "0x1.2011719d50b87p-3", "0x1.fae8e8bd4427fp-1"),
   ("-0x1.096df84p-29", "0x1.264993433763ap-3", "0x1.faafbcbfca356p-1"),
   ("0x1.9b2534fp-29", "0x1.2c810967bbf7p-3", "0x1.fa7557d8d987ep-1"),
   ("0x1.215b4ep-34", "0x1.32b7bfa25c91bp-3", "0x1.fa39bac71954bp-1"),
   ("-0x1.94db891p-30", "0x1.38edb9d29b39dp-3", "0x1.f9fce56700a6dp-1"),
   ("0x1.7727f7b8p-29", "0x1.3f22f7c3cce3ap-3", "0x1.f9bed7b8c8d8cp-1"),
   ("-0x1.0cb33038p-29", "0x1.45576971dd53p-3", "0x1.f97f925d53c83p-1"),
   ("-0x1.9071106p-31", "0x1.4b8b175c71e22p-3", "0x1.f93f14feb8022p-1"),
   ("0x1.62741e78p-29", "0x1.51bdfa7ea30d5p-3", "0x1.f8fd5fe3efac8p-1"),
   ("0x1.f8e16d0cp-28", "0x1.57f00e80e6e12p-3", "0x1.f8ba733a1ceb1p-1"),
   ("-0x1.76acbcap-31", "0x1.5e2143b7bc1c2p-3", "0x1.f8764fad5e9bfp-1"),
   ("-0x1.0a0f73ap-30", "0x1.6451a76411746p-3", "0x1.f830f4ad232d8p-1"),
   ("0x1.ca11d1bcp-28", "0x1.6a8135d7bd143p-3", "0x1.f7ea625eb5af7p-1"),
   ("-0x1.02f23628p-29", "0x1.70afd74071191p-3", "0x1.f7a299d3f182ap-1"),
   ("0x1.b34dcb8p-29", "0x1.76dda08544b5cp-3", "0x1.f7599a1ac7ecdp-1"),
   ("0x1.161ff4p-32", "0x1.7d0a7bf2d4abap-3", "0x1.f70f64322da74p-1"),
   ("-0x1.c49b8b4p-31", "0x1.83366ddb3de23p-3", "0x1.f6c3f7e7c2707p-1"),
   ("0x1.21da851p-29", "0x1.8961743b1429p-3", "0x1.f6775552a6ba2p-1"),
   ("0x1.ac63edap-30", "0x1.8f8b851098588p-3", "0x1.f6297cef0cdd6p-1"),
   ("0x1.27ef489cp-27", "0x1.95b4a5b9f2cebp-3", "0x1.f5da6e7820551p-1"),
   ("0x1.ae8937p-30", "0x1.9bdcc07900146p-3", "0x1.f58a2b0689c82p-1"),
   ("0x1.eb48c7ep-29", "0x1.a203e4a4f950ep-3", "0x1.f538b1d392049p-1"),
   ("-0x1.bfd282fp-29", "0x1.a829ffaad0d79p-3", "0x1.f4e603d51f1aap-1"),
   ("0x1.7ccf638p-29", "0x1.ae4f1fa80e1b5p-3", "0x1.f492204c5ef9ep-1"),
   ("-0x1.2435c578p-28", "0x1.b4732b72ebc86p-3", "0x1.f43d0890e1e72p-1"),
   ("0x1.0293fecp-30", "0x1.ba9634155f866p-3", "0x1.f3e6bbb6c2ea4p-1"),
   ("-0x1.7bb1f92p-29", "0x1.c0b82461f65ep-3", "0x1.f38f3ae6f9afcp-1"),
   ("0x1.27aaebcp-29", "0x1.c6d906faacf65p-3", "0x1.f3368589e17a2p-1"),
   ("-0x1.2e2bcd5p-27", "0x1.ccf8c3f74a6c9p-3", "0x1.f2dc9cfb5fa74p-1"),
   ("-0x1.6f070acp-30", "0x1.d31773ba218a8p-3", "0x1.f2817fd4d045bp-1"),
   ("0x1.469adfcp-29", "0x1.d935004779e57p-3", "0x1.f2252f59c122dp-1"),
   ("0x1.4f51c18p-32", "0x1.df5164301377ap-3", "0x1.f1c7abdeaa3efp-1"),
   ("0x1.78e44dap-29", "0x1.e56ca4202807cp-3", "0x1.f168f51c5d5d5p-1"),
   ("0x1.49bb5f8p-32", "0x1.eb86b4a1b7e9bp-3", "0x1.f1090bc4b68p-1"),
   ("-0x1.67ba541p-28", "0x1.f19f9369d5e93p-3", "0x1.f0a7effdc937fp-1"),
   ("0x1.c0cab95p-29", "0x1.f7b74ab7219d2p-3", "0x1.f045a1219e594p-1"),
   ("-0x1.2b77e32p-30", "0x1.fdcdc0ca3288dp-3", "0x1.efe220cf5c751p-1"),
   ("-0x1.e0d8cbp-33", "0x1.01f18054c8362p-2", "0x1.ef7d6e54c347dp-1"),
   ("-0x1.ecd5b9cp-29", "0x1.04fb7f6d35d68p-2", "0x1.ef178a6f9a987p-1"),
   ("0x1.eb24de5p-29", "0x1.0804e1d369ff2p-2", "0x1.eeb074934fdfp-1"),
   ("0x1.4a897c4p-30", "0x1.0b0d9d7b0d042p-2", "0x1.ee482e14bcdep-1"),
   ("0x1.336c376p-30", "0x1.0e15b555e7becp-2", "0x1.eddeb6908ca8cp-1"),
   ("-0x1.3952d9p-31", "0x1.111d25efd48b8p-2", "0x1.ed740e7eb8dd6p-1"),
   ("0x1.fc2a5d4p-31", "0x1.1423ef5c7e1bdp-2", "0x1.ed0835dc24e89p-1"),
   ("0x1.a88ed37p-29", "0x1.172a0eb8361dap-2", "0x1.ec9b2d0ec8288p-1"),
   ("-0x1.8ca4cb94p-27", "0x1.1a2f7b10b6d7p-2", "0x1.ec2cf55d6117cp-1"),
   ("0x1.0144524p-27", "0x1.1d3446fd0cd3fp-2", "0x1.ebbd8c1d62f96p-1"),
   ("-0x1.abf810cp-28", "0x1.203855b85f89ap-2", "0x1.eb4cf57454132p-1"),
   ("0x1.5d4c5d58p-28", "0x1.233bbcca40561p-2", "0x1.eadb2e40746cap-1"),
   ("-0x1.a1b0c58p-29", "0x1.263e685b1d714p-2", "0x1.ea68396d87754p-1"),
   ("-0x1.77c8dacp-29", "0x1.294061d2eb611p-2", "0x1.e9f41597393c8p-1"),
   ("0x1.915540ep-30", "0x1.2c41a580014cfp-2", "0x1.e97ec348fb87fp-1"),
   ("-0x1.abb6d9bp-28", "0x1.2f422b2d0990cp-2", "0x1.e90843c55b996p-1"),
   ("-0x1.b8ee5d58p-28", "0x1.3241f8cea2836p-2", "0x1.e890962268c49p-1"),
   ("-0x1.1cd29828p-28", "0x1.35410a8396266p-2", "0x1.e817baf85c094p-1"),
   ("-0x1.e216afp-32", "0x1.383f5e08283e2p-2", "0x1.e79db2a188b0ap-1"),
   ("-0x1.24afc3p-31", "0x1.3b3cef6993c0bp-2", "0x1.e7227dbf82004p-1"),
   ("-0x1.aa1657cp-31", "0x1.3e39be4767224p-2", "0x1.e6a61c62d5274p-1"),
   ("-0x1.c5b65fap-30", "0x1.4135c898485bbp-2", "0x1.e6288ee07fea5p-1"),
   ("0x1.23e8978p-32", "0x1.44310de3c284bp-2", "0x1.e5a9d54bbd26cp-1"),
   ("-0x1.2b1d77ap-29", "0x1.472b8976d498dp-2", "0x1.e529f06cb187dp-1"),
   ("-0x1.daaa348p-31", "0x1.4a253cb97efd1p-2", "0x1.e4a8e007231a2p-1"),
   ("-0x1.322f5708p-28", "0x1.4d1e2260c3422p-2", "0x1.e426a500f6e33p-1"),
   ("0x1.64758e8p-29", "0x1.50163eca0b337p-2", "0x1.e3a33e996b722p-1"),
   ("0x1.12486278p-28", "0x1.530d89a17e007p-2", "0x1.e31eae3fb917bp-1"),
   ("-0x1.6c3416ccp-27", "0x1.5603fcf8cd8a3p-2", "0x1.e298f502a579bp-1"),
   ("0x1.ab481ffp-29", "0x1.58f9a896aa209p-2", "0x1.e2121016e14fcp-1"),
   ("-0x1.6eb838bp-29", "0x1.5bee77aaf890bp-2", "0x1.e18a032eb4df5p-1"),
   ("-0x1.d159b8p-32", "0x1.5ee2734efeef5p-2", "0x1.e100ccaa6bd78p-1"),
   ("-0x1.a42e4ap-34", "0x1.61d595bedeabcp-2", "0x1.e0766d944915ep-1"),
   ("-0x1.43d0dcp-30", "0x1.64c7dd5cc0cd1p-2", "0x1.dfeae63903034p-1"),
   ("-0x1.8c7bdb7p-27", "0x1.67b9453ca2122p-2", "0x1.df5e378482eaep-1"),
   ("0x1.1c0ead6p-30", "0x1.6aa9d844c980ap-2", "0x1.ded05f6a23a52p-1"),
   ("0x1.7d526p-31", "0x1.6d99867e90d92p-2", "0x1.de4160e97b2e2p-1"),
   ("0x1.924e0368p-28", "0x1.7088555d3c816p-2", "0x1.ddb13afb14e37p-1"),
   ("-0x1.74b7c3ep-30", "0x1.73763c09fba09p-2", "0x1.dd1fef5335416p-1"),
   ("-0x1.7943adp-30", "0x1.766340685c982p-2", "0x1.dc8d7ccf2567ap-1"),
   ("0x1.79dd614p-29", "0x1.794f5f7522b88p-2", "0x1.dbf9e402aa5c3p-1"),
   ("0x1.7b64f32p-30", "0x1.7c3a939c32d81p-2", "0x1.db652607e0db1p-1"),
   ("-0x1.2bea5ce8p-28", "0x1.7f24db825141cp-2", "0x1.dacf43268b5bp-1"),
   ("0x1.733c024p-30", "0x1.820e3b8bf15ap-2", "0x1.da383a7aed887p-1"),
   ("-0x1.eac0fc94p-27", "0x1.84f6a51d077b3p-2", "0x1.d9a00efd84537p-1"),
   ("0x1.aca37338p-27", "0x1.87de2f4704f98p-2", "0x1.d906bbf17f4dap-1"),
   ("-0x1.910c4fp-30", "0x1.8ac4b7dc0d986p-2", "0x1.d86c4862b5d6ep-1"),
   ("-0x1.33bb86p-31", "0x1.8daa52b4dc041p-2", "0x1.d7d0b0374a559p-1"),
   ("-0x1.69e1507p-27", "0x1.908ef408ad22p-2", "0x1.d733f5e71c3bcp-1"),
   ("0x1.cffacf08p-27", "0x1.9372ab7784d36p-2", "0x1.d696161d786c9p-1"),
   ("-0x1.8629d9fp-26", "0x1.965552b0849abp-2", "0x1.d5f7190eeae23p-1"),
   ("0x1.415p-30", "0x1.99371687c64f3p-2", "0x1.d556f5155d9ddp-1"),
   ("-0x1.bd37aad8p-27", "0x1.9c17cf40715cbp-2", "0x1.d4b5b2caf8386p-1"),
   ("0x1.d02cde7p-26", "0x1.9ef79ea4d995dp-2", "0x1.d4134ac5eb246p-1"),
   ("-0x1.10547acp-30", "0x1.a1d653d9adf5ep-2", "0x1.d36fc7d291602p-1"),
   ("-0x1.01a1a228p-27", "0x1.a4b40f9c0120bp-2", "0x1.d2cb22b45236bp-1"),
   ("0x1.3ce2bacp-29", "0x1.a790ce2056b9ap-2", "0x1.d2255c3ae11a5p-1"),
   ("-0x1.ccb4a6p-32", "0x1.aa6c828db4ea8p-2", "0x1.d17e774d4e3e2p-1"),
   ("0x1.5db4bp-29", "0x1.ad47321f29847p-2", "0x1.d0d672bc0b122p-1"),
   ("0x1.32f6a6ep-29", "0x1.b020d7a285e23p-2", "0x1.d02d4fb84d334p-1"),
   ("0x1.cf8e39bcp-26", "0x1.b2f97c27f7494p-2", "0x1.cf830c2248c5ep-1"),
   ("0x1.8927bbp-30", "0x1.b5d10129a750ap-2", "0x1.ced7af22cb105p-1"),
   ("-0x1.3dec3c1p-28", "0x1.b8a77f8d0bbc5p-2", "0x1.ce2b32e50d6cdp-1"),
   ("-0x1.26ba536p-28", "0x1.bb7cf08f0290dp-2", "0x1.cd7d98fcf3b1ep-1"),
   ("0x1.23c568ep-29", "0x1.be51524e3aa53p-2", "0x1.cccee1da3d56ep-1"),
   ("-0x1.f3b3afp-29", "0x1.c1249c1f5f2f6p-2", "0x1.cc1f0f95e1e24p-1"),
   ("-0x1.1286a47p-28", "0x1.c3f6d2ef7054bp-2", "0x1.cb6e20ff37e81p-1"),
   ("0x1.641214ep-29", "0x1.c6c7f594003d9p-2", "0x1.cabc165bf1b6p-1"),
   ("0x1.0cda7c9p-27", "0x1.c997ff2bffccbp-2", "0x1.ca08f0dee434cp-1"),
   ("-0x1.5557ac9p-28", "0x1.cc66e7b42e8f1p-2", "0x1.c954b28bca62ep-1"),
   ("0x1.555eb62p-28", "0x1.cf34bccc567a1p-2", "0x1.c89f57f6e20f3p-1"),
   ("-0x1.4e0e361p-28", "0x1.d2016cbb5e39ap-2", "0x1.c7e8e59999e1fp-1"),
   ("0x1.446da1ep-29", "0x1.d4cd039d0ed05p-2", "0x1.c731585f970ebp-1"),
   ("0x1.103d328p-29", "0x1.d797767638decp-2", "0x1.c678b3174afe1p-1"),
   ("0x1.5814d6p-28", "0x1.da60c7ae9dc22p-2", "0x1.c5bef522be6fbp-1"),
   ("-0x1.5e2321ep-29", "0x1.dd28f054cbb3fp-2", "0x1.c5042052c8c42p-1"),
   ("-0x1.a259ffep-29", "0x1.dfeff54854631p-2", "0x1.c44833611bc7dp-1"),
   ("-0x1.4f28d8p-31", "0x1.e2b5d34665b35p-2", "0x1.c38b2f278ea7ep-1"),
   ("-0x1.de571p-36", "0x1.e57a86d137f2p-2", "0x1.c2cd1493d05c2p-1"),
   ("0x1.e0d8d14p-29", "0x1.e83e0ffb7bfb4p-2", "0x1.c20de3a08ea07p-1"),
   ("-0x1.12a858ep-28", "0x1.eb0067e48baf4p-2", "0x1.c14d9e2bd511ep-1"),
   ("0x1.9a17403p-27", "0x1.edc19997a4431p-2", "0x1.c08c413089b2ep-1"),
   ("0x1.68c8636p-29", "0x1.f0819163d1bcp-2", "0x1.bfc9d21568f32p-1"),
   ("0x1.4cc5eb8p-29", "0x1.f3405a482e11dp-2", "0x1.bf064dd580fc9p-1"),
   ("-0x1.fce7cd8p-27", "0x1.f5fde8f3f11d4p-2", "0x1.be41b798f6b97p-1"),
   ("-0x1.af8169p-29", "0x1.f8ba4c98a9816p-2", "0x1.bd7c0b1a7f14bp-1"),
   ("0x1.6e39e2p-33", "0x1.fb7575d1ea75p-2", "0x1.bcb54cac5dde5p-1"),
   ("0x1.30f9256p-28", "0x1.fe2f665dcd168p-2", "0x1.bbed7bd1e17bp-1"),
   ("0x1.626de2p-31", "0x1.00740ca0d5fbbp-1", "0x1.bb2499f9fe7a3p-1"),
   ("0x1.5cc703p-30", "0x1.01cfc8afeea0ep-1", "0x1.ba5aa650dd495p-1"),
   ("-0x1.6191e6p-32", "0x1.032ae54fe4057p-1", "0x1.b98fa2065a5e6p-1"),
   ("-0x1.6b1485p-31", "0x1.0485624c328c8p-1", "0x1.b8c38d39737bcp-1"),
   ("-0x1.11fbc3ap-29", "0x1.05df3e66a716dp-1", "0x1.b7f668a580fdp-1"),
   ("-0x1.0eca7fp-27", "0x1.07387825589ecp-1", "0x1.b728352c44517p-1"),
   ("-0x1.8073bc9ep-25", "0x1.089109ef1284dp-1", "0x1.b658f630112edp-1"),
   ("-0x1.9dcf0adp-27", "0x1.09e9051603e29p-1", "0x1.b588a13ab750fp-1"),
   ("-0x1.06ea9fp-29", "0x1.0b405820e78e7p-1", "0x1.b4b740d3cc07bp-1"),
   ("-0x1.36a8d0cp-30", "0x1.0c9704a1ea4e5p-1", "0x1.b3e4d40f5524dp-1"),
   ("0x1.63d1f3p-30", "0x1.0ded0bc01a533p-1", "0x1.b3115a3a628afp-1"),
   ("0x1.f3181f14p-26", "0x1.0f4270e4787bfp-1", "0x1.b23cd1314c779p-1"),
   ("-0x1.f269b78p-29", "0x1.109723e75c5cfp-1", "0x1.b167430cfebdbp-1"),
   ("0x1.1d84dc08p-27", "0x1.11eb36bc9db52p-1", "0x1.b090a4915ee88p-1"),
   ("-0x1.08e60068p-27", "0x1.133e9ba0061d8p-1", "0x1.afb8fe69a6527p-1"),
   ("0x1.cda72abp-27", "0x1.14915d557a7c9p-1", "0x1.aee049bc0aeep-1"),
   ("-0x1.f32f95p-30", "0x1.15e36dfb6bb55p-1", "0x1.ae068f6991699p-1"),
   ("0x1.138092dp-28", "0x1.1734d6f34d7fp-1", "0x1.ad2bc96c1e1f5p-1"),
   ("0x1.6b382dd4p-26", "0x1.188595ae376a5p-1", "0x1.ac4ff962bdb6dp-1"),
   ("-0x1.f12fafap-28", "0x1.19d59f592a587p-1", "0x1.ab7326685eb57p-1"),
   ("-0x1.2909e5ap-28", "0x1.1b2500aed7ac6p-1", "0x1.aa954823cf815p-1"),
   ("-0x1.d66a8978p-25", "0x1.1c73aa0150cf9p-1", "0x1.a9b668fb0503fp-1"),
   ("0x1.311ea86p-27", "0x1.1dc1b7db74db1p-1", "0x1.a8d675d9c6cc8p-1"),
   ("-0x1.41c02b8p-31", "0x1.1f0f08a1a06a4p-1", "0x1.a7f5853bb4309p-1"),
   ("-0x1.ca1f4edp-26", "0x1.205ba57211271p-1", "0x1.a71391146958fp-1"),
   ("-0x1.910ce77p-28", "0x1.21a7988f8326bp-1", "0x1.a63092626202fp-1"),
   ("0x1.2bfadbeep-25", "0x1.22f2dc71afab6p-1", "0x1.a54c8cd9fd0d9p-1"),
   ("-0x1.5f1c02a8p-27", "0x1.243d5df4afb93p-1", "0x1.a4678dbbe5e73p-1"),
   ("-0x1.db12b9p-30", "0x1.2587347f493a4p-1", "0x1.a38184db0df23p-1"),
   ("-0x1.7b29ep-30", "0x1.26d05490f2f61p-1", "0x1.a29a7a2f40b49p-1"),
   ("-0x1.b3ddca4p-29", "0x1.2818be6930629p-1", "0x1.a1b26d8f070d7p-1"),
   ("0x1.e112744p-29", "0x1.2960730ff2bcdp-1", "0x1.a0c95e3df5e0ep-1"),
   ("-0x1.5269766p-28", "0x1.2aa76dafcbbf4p-1", "0x1.9fdf4fae1df6fp-1"),
   ("-0x1.09777e1p-28", "0x1.2bedb1b6b4e15p-1", "0x1.9ef43f6cbe162p-1"),
   ("0x1.ae2051fp-28", "0x1.2d333e4617f25p-1", "0x1.9e082e148680ep-1"),
   ("-0x1.36f6ced8p-27", "0x1.2e780cb47180ep-1", "0x1.9d1b207f383c3p-1"),
   ("-0x1.23fdc6bp-28", "0x1.2fbc23fba2f44p-1", "0x1.9c2d1197130a7p-1"),
   ("0x1.bc540ep-33", "0x1.30ff7fd6d967dp-1", "0x1.9b3e0478b961bp-1"),
   ("-0x1.cfb4ed7p-28", "0x1.32421da0bf0e9p-1", "0x1.9a4dfb1c89326p-1"),
   ("0x1.55802aecp-26", "0x1.3384042a92b1dp-1", "0x1.995cf06920d11p-1"),
   ("0x1.60719e4p-28", "0x1.34c52608e3a92p-1", "0x1.986aee6d6837ep-1"),
   ("-0x1.cbf2e48p-30", "0x1.36058ac8863b6p-1", "0x1.9777ef832c986p-1"),
   ("0x1.9061c32p-27", "0x1.374533ab707dp-1", "0x1.9683f2ad7e2ecp-1"),
   ("-0x1.da84dfep-27", "0x1.3884160f9488fp-1", "0x1.958f000fdd50ap-1"),
   ("0x1.92e8a74p-29", "0x1.39c23eba6b22ap-1", "0x1.94990dd9cee51p-1"),
   ("-0x1.bff5d9ap-29", "0x1.3affa20756bddp-1", "0x1.93a225056084ap-1"),
   ("0x1.4c462p-36", "0x1.3c3c4498e98ebp-1", "0x1.92aa41fbb951cp-1"),
   ("-0x1.e4613e9p-28", "0x1.3d782261dff62p-1", "0x1.91b167e92d706p-1"),
   ("0x1.0eb2964p-30", "0x1.3eb33ed579bbep-1", "0x1.90b794146043cp-1"),
   ("-0x1.60abec2p-29", "0x1.3fed94c834d8ap-1", "0x1.8fbcca9583479p-1"),
   ("0x1.6954977p-27", "0x1.4127281ddac03p-1", "0x1.8ec1085083553p-1"),
   ("0x1.a16fec2p-29", "0x1.425ff1f841235p-1", "0x1.8dc452ca328d3p-1"),
   ("-0x1.27bcdd3p-27", "0x1.4397f44aa44f2p-1", "0x1.8cc6a8771e165p-1"),
   ("-0x1.60dded4p-28", "0x1.44cf317a563dbp-1", "0x1.8bc8076122736p-1"),
   ("-0x1.9a8f405cp-26", "0x1.4605a2b02d705p-1", "0x1.8ac875232f3efp-1"),
   ("0x1.32777dcp-27", "0x1.473b532bc5a67p-1", "0x1.89c7e8713120cp-1"),
   ("-0x1.1418a7bp-26", "0x1.4870306ca20e2p-1", "0x1.88c670a0ea774p-1"),
   ("-0x1.fed182ep-28", "0x1.49a44886b534p-1", "0x1.87c401fdf05e5p-1"),
   ("0x1.86144d8p-27", "0x1.4ad796ea1410cp-1", "0x1.86c0a04dbacc5p-1"),
   ("0x1.1bc2e6p-33", "0x1.4c0a14640d2afp-1", "0x1.85bc51aa114c2p-1"),
   ("-0x1.f53d2fep-28", "0x1.4d3bc5aaa8cd5p-1", "0x1.84b7121b30a13p-1"),
   ("-0x1.2e100ap-30", "0x1.4e6cab91556bep-1", "0x1.83b0e0e6b6cccp-1"),
   ("-0x1.fa58c62p-29", "0x1.4f9cc1c69fddep-1", "0x1.82a9c1c1ab463p-1"),
   ("0x1.bb491ep-33", "0x1.50cc09fdcbd92p-1", "0x1.81a1b3342f858p-1"),
   ("0x1.a11541p-28", "0x1.51fa82c3aa029p-1", "0x1.8098b67ea8509p-1"),
   ("0x1.ab0a5d3p-27", "0x1.53282b20b96b6p-1", "0x1.7f8ecc791953p-1"),
   ("-0x1.cba0438p-28", "0x1.5454fe43a7d7cp-1", "0x1.7e83f96af78ap-1"),
   ("-0x1.0dd83a4p-29", "0x1.5581033a81573p-1", "0x1.7d783712e20ecp-1"),
   ("-0x1.e9a8299p-28", "0x1.56ac33fbb8253p-1", "0x1.7c6b8acf90fa6p-1"),
   ("0x1.225c4aap-29", "0x1.57d6939d4b513p-1", "0x1.7b5df1da18065p-1"),
   ("-0x1.82e66ep-27", "0x1.59001b9e64d79p-1", "0x1.7a4f72157cfdfp-1"),
   ("0x1.51a6a354p-26", "0x1.5a28d5b36d597p-1", "0x1.794002a7c9023p-1"),
   ("0x1.13917f4p-26", "0x1.5b50b4e10bec1p-1", "0x1.782faf6dc7ba2p-1"),
   ("0x1.49310ccp-30", "0x1.5c77bc15ab4efp-1", "0x1.771e75c43942ep-1"),
   ("0x1.24d493cp-30", "0x1.5d9dee9de49dbp-1", "0x1.760c529bc17bp-1"),
   ("-0x1.04638f7p-26", "0x1.5ec347044e0f4p-1", "0x1.74f94b0af972p-1"),
   ("-0x1.3f41b28p-29", "0x1.5fe7cb834600cp-1", "0x1.73e55936a516p-1"),
   ("-0x1.a5f6f5cp-30", "0x1.610b7515d1562p-1", "0x1.72d083b8214ebp-1"),
   ("0x1.19fb2ep-28", "0x1.622e459eafbc1p-1", "0x1.71bac8c7b0592p-1"),
   ("-0x1.56d2c2bp-28", "0x1.6350396fe4e62p-1", "0x1.70a42bec51665p-1"),
   ("-0x1.3c156c2p-28", "0x1.64715385bed93p-1", "0x1.6f8caa4969708p-1"),
   ("-0x1.f23e576p-29", "0x1.659191d2fd57fp-1", "0x1.6e7445d74f711p-1"),
   ("0x1.1e4be38p-30", "0x1.66b0f41d484c4p-1", "0x1.6d5afecd4938dp-1"),
   ("-0x1.397cc8d8p-27", "0x1.67cf76eac73dfp-1", "0x1.6c40d89625f63p-1"),
   ("-0x1.202f686p-28", "0x1.68ed1e0990551p-1", "0x1.6b25cf728c35p-1"),
]

# global_error(is_sin=true,rel=false)
# maxl= 1.27708212795389e-15
# i= 255 err= -68.5886973253303
# global_error(is_sin=true,rel=true)
# i= 2 err= -67.295631377593?
# global_error(is_sin=false,rel=false)
# i= 6 err= -68.4141910865950
# maxl= 1.14933194355319e-15
# global_error(is_sin=false,rel=true)
# i= 253 err= -68.0711056124201
def global_error(is_sin=true,rel=false):
   global SC
   maxerr = 0
   maxl = 0
   SC = [(RR(x[0],16),RR(x[1],16),RR(x[2],16)) for x in SC]
   # check SC[i][0] is integer multiple of 2^-62, and |SC[i][0]| < 2^-24
   for i in range(256):
      x = SC[i][0]
      X = x.exact_rational()
      assert X/2^-62 in ZZ, "X/2^-62 in ZZ"
      assert abs(X)<2^-24, "abs(X)<2^-24"
   if is_sin:
      for i in range(256):
         errs, sh, sl = evalPSfast ()
         # | sh + sh - sin(h+l) | < errs
         errc, ch, cl = evalPCfast ()
         # | ch + cl - cos(h+l) | < errc
         xi = i/2^11+SC[i][0].exact_rational()
         Si = SC[i][1]
         errSi = abs(n(sin(2*pi*xi)-Si.exact_rational(),200))
         Ci = SC[i][2]
         errCi = abs(n(cos(2*pi*xi)-Ci.exact_rational(),200))
         # s_mul (&sh, &sl, SC[i][2], sh, sl)
         sh_in = sh+sl
         sh, sl = s_mul(Ci, sh, sl)
         err1 = RIFulp(sl)+errCi*sh_in.abs().upper()+Ci*errs
         # s_mul (&ch, &cl, SC[i][1], ch, cl)
         ch_in = ch+cl
         ch, cl = s_mul(Si, ch, cl)
         err2 = RIFulp(cl)+errSi*ch_in.abs().upper()+Si*errc
         # fast_two_sum (h, l, ch, sh)
         h = ch+sh
         u = RIFulp(h)
         l = RIF(-u,u)
         err3 = h.abs().upper()*2^-105
         # *l += sl + cl
         tmp = sl+cl
         l = l+tmp
         err4 = RIFulp(tmp)+RIFulp(l)
         err = err1+err2+err3+err4
         if rel: # convert to relative error
            err = err/(h+l).abs().lower()
         err = err.abs().upper()
         if err>maxerr:
            maxerr = err
            print ("i=", i, "err=", log(err)/log(2.))
         if l.abs().upper() > maxl:
            maxl = l.abs().upper()
            print ("maxl=", maxl)
   else:
      for i in range(256):
         errs, sh, sl = evalPSfast ()
         errc, ch, cl = evalPCfast ()
         xi = i/2^11+SC[i][0].exact_rational()
         Si = SC[i][1]
         errSi = abs(n(sin(2*pi*xi)-Si.exact_rational(),200))
         Ci = SC[i][2]
         errCi = abs(n(cos(2*pi*xi)-Ci.exact_rational(),200))
         # s_mul (&ch, &cl, SC[i][2], ch, cl)
         ch_in = ch+cl
         ch, cl = s_mul(Ci, ch, cl)
         err1 = RIFulp(cl)+errCi*ch_in.abs().upper()+Ci*errc
         # s_mul (&sh, &sl, SC[i][1], sh, sl
         sh_in = sh+sl
         sh, sl = s_mul(Si, sh, sl)
         err2 = RIFulp(sl)+errSi*sh_in.abs().upper()+Si*errs
         # fast_two_sum (h, l, ch, -sh)
         h = ch-sh
         u = RIFulp(h)
         l = RIF(-u,u)
         err3 = h.abs().upper()*2^-105
         # *l += cl - sl
         tmp = cl - sl
         l = l+tmp
         err4 = RIFulp(tmp)+RIFulp(l)
         err = err1+err2+err3+err4
         if rel: # convert to relative error
            err =err/(h+l).abs().lower()
         err = err.abs().upper()
         if err>maxerr:
            maxerr = err
            print ("i=", i, "err=", log(err)/log(2.))
         if l.abs().upper() > maxl:
            maxl = l.abs().upper()
            print ("maxl=", maxl)

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

# sage: statall("out")
# [((6495314627411702, -78), (9007199254740992, -42))]
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

# return x in (2^(e-1),2^e) such that is closest to a multiple of pi/2
# if parity="even", x should be an even multiple of pi/2 (sin(x) near 0)
# if parity="odd", x should be an odd multiple of pi/2 (sin(x) near 1)
def wc(e,parity="any"):
   x = n(2^(e-53)/(pi/2),e+200)
   l = continued_fraction(x)
   bestq = None
   for pq in l.convergents():
      p = pq.numer()
      q = pq.denom()
      # 2^(e-53)/(pi/2) ~ p/q
      # thus q*2^(e-53) ~ p*pi/2
      while q<2^52:
         p = p*2
         q = q*2
      if parity=="even" and is_odd(p):
         continue
      if parity=="odd" and is_even(p):
         continue
      if q<2^53:
         bestq = q
   if bestq==None:
      return RR(0)
   q = bestq
   x = RR(q*2^(e-53))
   return x
