def print_dd(x):
  y = RR(x)
  z = RR(x - y.exact_rational())
  return get_hex(y) + ", " + get_hex(z)

# compute a double-double approximation h+l of -log2(minimizer)
def get_hl(minimizer):
   prec = 200
   h = RR(n(-log2(minimizer),prec))
   H = h.exact_rational()
   l = RR(n(-log2(minimizer) - H,prec))
   L = l.exact_rational()
   err = n(-log2(minimizer) - H - L,prec)
   if h==0:
      assert err==0, "err=0"
   else:
      err = abs(err/h)
   return h, l, err

# see comments in powl_tables.h
# get_coarsetbl()
# 0x1p-7 -107.225895411898 0.496174262004249
# m is the number of bits of r1[i]
# L is the length of the table
def get_coarsetbl(m = 9, L = 7, verbose=true):
	Rm = RealField(m)
	R  = RealField(106)
	T = dict()
	maxmin = -1
	maxerr = 0 # maximal absolute error
	maxhl = 0  # maximal value of |h+l|
	if verbose:
	   print("static const _Alignas(16)")
	   print("lut_t coarse[" + str(2**L) + "] = {")
	for i in range(2**L):
		# x is in range 1 + i/2**L, 1 + (i+1)/2**L
		# we want to minimise |xr - 1| on that interval
		z = 0
		nh = 1 + (i + 1)/2**L # largest x in interval
		nl = 1 + i/2**L       # smallest x in interval
		rl = Rm(RealField(m, rnd='RNDD')(1/nh)) # lower bound for r
		rh = Rm(RealField(m, rnd='RNDU')(1/nl)) # upper bound for r
		minr = 20
		minimizer = 0
		r = rl
		while(r <= rh):
			valr = max(
				R(abs(r.exact_rational()*nl - 1)),
				R(abs(r.exact_rational()*nh - 1)))
			if(valr < minr):
				minr = valr
				minimizer = r.exact_rational()
			r = r.nextabove()
		if(minimizer <= 2**(-.5)): # r <= 1/sqrt(2) thus x >= sqrt(2)
			z = 1 # add a 1/2 prefactor
    # around 1 and 2, fix r to 1 and .5 respectively
		if(rl <= 1 and 1 <= rh):
			minimizer = 1
			minr = max(R(abs(nl - 1)),R(abs(nh - 1)))
		if(rl <= 2 and 2 <= rh):
			minimizer = 1/2
			minr = max(R(abs(nl - 1)),R(abs(nh - 1)))
		maxmin = max(maxmin, minr)
		h, l, err = get_hl (minimizer*2**z) # we have z+h+l ~= -log2(minimizer)
		maxhl = max(maxhl, abs(h+l))
		maxerr = max(maxerr, err)
		T[i] = (h, l, minimizer)
		if verbose:
		   print ("{" + get_hex(Rm(minimizer)) + ", "
				+ get_hex(h) + ", " + get_hex(l) + ","
				+ str(z) + "},//" + get_hex(R(minr)))
	if verbose:
	   print("};")
	   print(get_hex(maxmin), log(maxerr)/log(2.), maxhl)
	return T

# m is the number of bits of r2[i]
# L is the length of the table
# get_finetbl()
# 0x1p-12 -107.270397599854 0.0112272554232541
def get_finetbl(m = 13, L = 7, verbose=true):
	Rm = RealField(m)
	R  = RealField(106)
	T = dict()
	maxmin = -1
	if verbose:
	   print("static const _Alignas(16)")
	   print("lut_t fine[" + str(2**L) + "] = {")
	maxerr = 0
	maxhl = 0
	for i in range(2^L):
		# if i < 2^L-1 then x is in range 1 + i/2^(5+L), 1 + (i+1)/2^(5+L)
		# else x is in range 1 - 1/2^7 + (i-2^(L-1))/2^(6+L),
		# 1 - 1/2^7 + (i+1-2^(L-1))/2^(6+L)
		if(i < 2^(L-1)):
			nh = 1 + (i + 1)/2^(5+L)
			nl = 1 + i/2^(5+L)
		else:
			nh = 1 - 1/2^7 + (i - 2^(L-1) + 1)/2^(6+L)
			nl = 1 - 1/2^7 + (i - 2^(L-1))/2^(6+L)
		rl = Rm(RealField(m, rnd='RNDD')(1/nh))
		rh = Rm(RealField(m, rnd='RNDU')(1/nl))
		minr = 20
		minimizer = 0
		r = rl
		while(r <= rh):
			valr = max(
				R(abs(r.exact_rational()*nl - 1)),
				R(abs(r.exact_rational()*nh - 1))) 
			if(valr < minr):
				minr = valr
				minimizer = r.exact_rational()
			r = r.nextabove()
		if(rl <= 1 and 1 <= rh):
			minimizer = 1 
			minr = max(R(abs(nl - 1)),R(abs(nh - 1)))
		minlog = R(-log2(minimizer))
		z = 0
		maxmin = max(maxmin, minr)
		h, l, err = get_hl (minimizer)
		T[i] = (h,l, minimizer)
		maxerr = max(maxerr, err)
		if i // 2**(L-2) == 1: # unused entries
		   if verbose:
		      print("{0,0,0,0}, // unused")
		else:
			maxhl = max(maxhl, abs(h+l))
			if verbose:
			   print ("{" + get_hex(Rm(minimizer))
				+ ", " + get_hex(h) + ", " + get_hex(l) + ", "
					+ str(z) + "}, //" + get_hex(R(nl)) +","+ get_hex(R(nh)) + "(" + hex(i) + ")")
	if verbose:
	   print("};")
	   print(get_hex(maxmin), log(maxerr)/log(2.), maxhl)
	return T

def fast_two_sum(a,b):
   assert a==0 or a.ulp()>=b.ulp(), "a==0 or a.ulp()>=b.ulp()"
   rh = a + b
   e = rh - a
   rl = b - e
   return rh, rl

# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# return the results of high_sum and the maximal absolute error
def high_sum(a,bh,bl):
   rh, e = fast_two_sum (a, bh)
   rl = bl + e
   return rh, rl

# analyse_first_high_sum()
# extra_int= 2048.00000000000 r= RNDU i1= 51 err= -105.003076194750
def analyse_first_high_sum():
   T1 = get_coarsetbl()
   maxerr = 0
   for extra_int in range(-16382,16384):
      for r in 'NZUD':
         R = RealField(53,rnd='RND'+r)
         extra_int = R(extra_int)
         for i1 in range(128):
            mlogr1h = R(T1[i1][0])
            mlogr1l = R(T1[i1][1])
            mlogrh, mlogrl = high_sum (extra_int, mlogr1h, mlogr1l)
            a = mlogrh.exact_rational() + mlogrl.exact_rational()
            b = mlogr1h.exact_rational() + mlogr1l.exact_rational()
            b += extra_int.exact_rational()
            err = abs(a-b)/mlogrh
            if err>maxerr:
               maxerr = err
               print ("extra_int=", extra_int, "r=", 'RND'+r, "i1=", i1, "err=", log(err)/log(2.))

def analyse_second_high_sum(extra_int_min=-16382):
   T1 = get_coarsetbl()
   T2 = get_finetbl()
   maxerr = 0
   maxratio = 0
   for extra_int in range(extra_int_min,16384):
      for r in 'NZUD':
         R = RealField(53,rnd='RND'+r)
         extra_int = R(extra_int)
         for i1 in range(128):
            mlogr1h = R(T1[i1][0])
            mlogr1l = R(T1[i1][1])
            mlogrh, mlogrl = high_sum (extra_int, mlogr1h, mlogr1l)
            for i2 in range(128):
               if 32 <= i2 < 64: # unused values
                  continue
               mlogr2h = R(T2[i2][0])
               mlogr2l = R(T2[i2][1])
               b = mlogr2h.exact_rational() + mlogr1l.exact_rational()
               # print ("extra_int=", extra_int, "r=", 'RND'+r, "i1=", i1, "i2=", i2)
               # print ("mlogrh=", get_hex(mlogrh), "mlogr2h=", get_hex(mlogr2h), "mlogr2l=", get_hex(mlogr2l))
               rh, t = fast_two_sum (mlogrh, mlogr2h)
               assert abs(mlogr2l) <= 2^-53*abs(mlogr2h), "abs(mlogr2l) <= 2^-53*abs(mlogr2h)"
               ratio = abs(mlogr2h/rh)
               if ratio>maxratio:
                  maxratio = ratio
                  print ("extra_int=", extra_int, "r=", 'RND'+r, "i1=", i1, "i2=", i2, "ratio=", ratio)
               mlogr2h, mlogr2l = high_sum (mlogrh, mlogr2h, mlogr2l)
               mlogr2l += mlogrl
               a = mlogr2h.exact_rational() + mlogr2l.exact_rational()
               b += mlogr1h.exact_rational() + mlogr1l.exact_rational()
               b += extra_int.exact_rational()
               err = abs(a-b)/mlogr2h
               if err>maxerr:
                  maxerr = err
                  print ("extra_int=", extra_int, "r=", 'RND'+r, "i1=", i1, "i2=", i2, "err=", log(err)/log(2.))

# For each member of L, print its -log2(minimizer) as a qint64.
# extracted from binary64/pow/qint.sage
def accurate_logs(L):
	R64 = RealField(64)
	R = RealField(256)
	for i in range(len(L)):
		(a,b,r) = L[i]
		x = R(n(log2(r), 300))
		s,m,e = x.sign_mantissa_exponent()
		assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
		l = (2^256+m).digits(2^64)
		if(l[1] == 0): # Ensure 0 gets exponent 0
			e = -255
		# we store -log2(x) thus we change signs
		if s==1:
			print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) +
		            ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) +
		            ", .ex = " + str(e+255) + ", .sgn = 0x1},")
		else: # s=-1
			print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) +
		            ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) +
		            ", .ex = " + str(e+255) + ", .sgn = 0x0},")

def format_sollya_poly(s):
	R256 = RealField(256)
	R.<x> = R256[]
	p = R(s)
	n = p.degree()
	print(n)
	for i in range(n, -1, -1):
		c = p[i]
		s,m,e = c.sign_mantissa_exponent()
		while m.nbits()<256:
			m = 2*m
			e = e-1
		assert m.nbits()==256, "m.nbits()==256"
		l = m.digits(2^64)
		if s==1:
			print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " +
		hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) +
		", .sgn = 0x0}, /* degree " + str(i) + " */")
		else: # s=-1
			print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " +
		hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) +
		", .sgn = 0x1}, /* degree " + str(i) + " */")
	return [get_hex(p[n - i]) for i in range(n+1)]

# for i in range(4):
#    T=corr_tk(k=i)
#    print(max(abs(T[i][0]) for i in range(32)))
# Error -294.064083110299
# 1652397245814591285
# Error -294.003441498186
# 1433175892871988186
# Error -294.051553075173
# 1596739555728066819
# Error -294.057449864016
# 1119274665622562301
def corr_tk(k=0):
   maxerr = 0
   R = RealField(53)
   T = dict()
   print("static const corr_t t"+str(k)+"_corr[32] = {")
   for i in range(2^5):
      x = n(2^(i/2^(20-5*k)), 400)
      h = R(x)
      l = R(x-h.exact_rational())
      t = h.exact_rational() + l.exact_rational()
      e = n(n(log(t),600)/n(log(2),600) - n(i/2^(20-5*k),600), 600)
      corrhi  = floor(n(e * 2^167, 600))
      corrloh = floor(n((e * 2^167 - corrhi)*2^62, 600))
      corrlol = round(n(((e * 2^167 - corrhi)*2^62 - corrloh)*2^64, 600))
      assert abs(corrhi)  < 2^61, "abs(corrhi) < 2^61"
      assert abs(corrloh) < 2^62, "abs(corrloh) < 2^62"
      print("   {.h=" + str(corrhi) + "L,.lh=" + str(corrloh) +
                                      "UL,.ll=" + str(corrlol) + "UL},")
      err_acc = abs(corrhi/2^167 + corrloh/2^(167+62) + corrlol/2^(167+62+64)-e)
      maxerr = max(maxerr, err_acc)
      T[i] = (corrhi, corrloh, corrlol)
   print ("};")
   print ("Error " + str(log(maxerr)/log(2.)))
   return T

def check_trivialzeroes():
   T0 = corr_tk(0)
   T1 = corr_tk(1)
   T2 = corr_tk(2)
   T3 = corr_tk(3)
   for i in range(2^5):
      for j in range(2^5):
         for k in range(2^5):
            for l in range(2^5):
               h0,lh0,ll0= T0[i]
               h1,lh1,ll1 = T1[j]
               h2,lh2,ll2 = T2[k]
               h3,lh3,ll3 = T3[l]
               corrl0 = lh0*2^64+ll0
               corrl1 = lh1*2^64+ll1
               corrl2 = lh2*2^64+ll2
               corrl3 = lh3*2^64+ll3
               corrl = corrl0 + corrl1 + corrl2 + corrl3
               corrl = (4*corrl) % (2^128)
               if(h0+h1+h2+h3 == 0):
                  assert i == 0 and j == 0 and k == 0 and l == 0, "Failure!"
               if corrl == 0:
                  assert i == 0 and j == 0 and k == 0 and l == 0, "Failure!"
   print ("Success")

def print_bacsel_command(out,y,e,m,t,t0,t1,d,alpha,nthreads):
   y = R64(y)
   command = "./bacsel -rnd_mode all -prec 256 -n 64 -nn 64 -m "
   command += str(m) + " -t " + str(t) + " -t0 " + str(t0)
   command += " -t1 " + str(t1) + " -y " + get_hex(y) + " -e_in " + str(e)
   command += " -d " + str(d) + " -alpha " + str(alpha)
   command += " -nthreads " + str(nthreads) + " -v"
   if out==None:
      print (command)
   else:
      out.write(command + "\n")

# generates a set of bacsel commands to check worst-cases in the set S
# defined as follows:
# (a) x,y with y integer in [2,41]
#     (41 is the largest integer n such that 3^n fits in 65 bits)
# (b) x,y with y of the form n/2^F with 3 <= n <= 41, n odd, 1 <= F <= 5
#     (F <= 5 because starting from an odd integer of at most 65 bits,
#      you can take at most 5 square roots while keeping an integer)
# check_S(out="/tmp/in",width=2^30,m=55) # with t0=2^63+2^62
# *** x,y=0xc.000000000000001p-4,0x2p+0, distance is: 5.421010862e-20 (-m 64)
# check_S(out="/tmp/in",width=2^41,m=64)
# real 19m8.149s, user 1108m52.587s on tartine (64 cores)
# check_S(out="/tmp/in",width=2^42,m=64)
# real 27m38.904s, user 1617m43.970s on tartine (64 cores)
# check_S(out="/tmp/in",width=2^42,m=165,t=22)
# real 23m9.451s, user 1349m14.649s on tartine (64 cores)
# check_S(out="/tmp/in",width=2^42,m=165,t=22,d=3)
# real 13m20.221s, user 759m31.122s on tartine (64 cores)
# check_S(out="/tmp/in",width=2^45,m=165,t=29,d=4) ***
# real 7m23.300s, user 411m14.889s
# check_S(out="/tmp/in",width=2^45,m=165,t=30,d=4)
# real 7m58.439s, user 445m35.797s
# check_S(out="/tmp/in",width=2^44,m=165,t=28,d=5)
# real 6m15.299s, user 343m11.966s
# check_S(out="/tmp/in",width=2^44,m=169,t=28,d=5)
# real 6m13.275s, user 340m13.569s
# check_S(out="/tmp/in",width=2^45,m=169,t=28,d=5)
# real 8m33.740s, user 494m6.814s
# check_S(out="/tmp/in",width=2^45,m=169,t=29,d=5)
# real 7m31.157s, user 429m57.373s
# check_S(out="/tmp/in",width=2^46,m=169,t=30,d=5)
# real 10m2.100s, user 586m17.811s
# check_S(out="/tmp/in",width=2^47,m=169,t=30,d=5) ***
# real 20m42.155, user 1206m57.888s
# check_S(out="/tmp/in",width=2^47,m=169,t=30,d=6)
# real 20m13.461s, user 1207m2.257
def check_S(m=55,t=20,width=2^63,d=2,alpha=2,nthreads=64,out=None):
   if out != None:
      out = open(out,"w")
   R64 = RealField(64)
   if width == 2^63:
      t0 = 2^63
   else:
      t0 = 2^63 + ZZ.random_element(2^63-width)
   t1 = t0 + width
   for n in range(2,41+1):
      y = R64(n)
      print_bacsel_command(out,y,0,m,t,t0,t1,d,alpha,nthreads)
   for F in range(1,5+1):
      for n in range(3,41+1,2):
         y = R64(n/2^F)
         # we need to check 2^F binades
         for e in range(2^F):
            print_bacsel_command(out,y,e,m,t,t0,t1,d,alpha,nthreads)
   if out != None:
      out.close()

# nancy+explor
# return list of (t0,t1,e,y) for all bacsel runs
def statall(f):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s[:-1] # skip final \n
      s = s.split(" ")
      assert len(s) == 6, "len(s) == 6" # t0 t1 e nn m y
      t0 = ZZ(s[0])
      t1 = ZZ(s[1])
      e = ZZ(s[2])
      nn = ZZ(s[3])
      assert nn==64, "nn==64"
      m = ZZ(s[4])
      assert m==169, "m==169"
      y = R64(s[5],16)
      l.append((t0,t1,e,y))
   f.close()
   return l

# check if l contains all required checks for y
# l = statall("/tmp/out")
# check_complete_y(l,R64("0x1.8p-4",16),None)
def check_complete_y(l,y,out):
   Y = y.exact_rational()
   emax = QQ(Y).denom()
   # l should contain (2^63,2^64,e,y) for 0 <= e < emax
   t0 = 2^63
   t1 = 2^64
   for e in range(emax):
      le = [x for x in l if x[3]==y and x[2]==e]
      le = merge(le)
      if le != [(t0,t1,e,y)]:
         # print ("missing", (t0,t1,e,get_hex(y)))
         print ("le",le)
         print_bacsel_command(out,y,e,169,29,t0,t1,4,2,64)

from functools import cmp_to_key

# sort by increasing increasing t0, then by decreasing t1
def cmp(x,y):
   if x[0] < y[0]:
      return int(-1)
   if x[0] > y[0]:
      return int(1)
   if x[1] > y[1]:
      return int(-1)
   if x[1] < y[1]:
      return int(1)
   return int(0)

# merge list of (t0,t1,e,y) with same e and y
def merge(l):
   l.sort(key=cmp_to_key(cmp))
   newl = []
   for (t0,t1,e,y) in l:
      if newl==[]:
         newl.append((t0,t1,e,y))
      elif t1<=newl[-1][1]: # range (t0,t1) already included in newl
         pass
      elif t0<=newl[-1][1] and t1>newl[-1][1]: # t0 included, t1 larger
         newl[-1] = (newl[-1][0],t1,e,y)
      else: # hole
         newl.append((t0,t1,e,y))
   return newl

# l = statall("/tmp/out")
# check_complete_all(l,"/tmp/missing")
def check_complete_all(l,out=None):
   if out != None:
      out = open(out,"w")
   S = get_S()
   for y in S:
      check_complete_y(l,y,out)
   if out != None:
      out.close()

# return the values of y that appear in S
def get_S():
   S = []
   for n in range(2,41+1):
      y = R64(n)
      S.append(y)
   for F in range(1,5+1):
      for n in range(3,41+1,2):
         y = R64(n/2^F)
         S.append(y)
   return S

def print_xy(out,x,y):
   if abs(x) >= RR(2^16384) or abs(x) < RR(2^-16445):
      return 0
   s = get_hex(x) + "," + get_hex(y)
   if out==None:
      print (s)
   else:
      out.write(s + "\n")
   return 1

# check exact values for x=2^n and y=m/2^k with m odd, k >= 6
# this gives 988254 (x,y) pairs to check
def check_pow2(out=None):
   if out != None:
      out = open(out,"w")
   # if x = 2^n, then x^y = 2^(n*m/2^k) thus n should be multiple of 2^k
   nsols = 0
   for k in range(6,16446):
      # positive n
      for n in range(2^k,16446,2^k):
         assert n%(2^k)==0, "n%(2^k)==0"
         e = n//(2^k)
         # x^y = 2^(e*m)
         for m in range(1,floor(16445/e)+1,2):
            x = RR(2^n)
            y = RR(m/2^k)
            nsols += print_xy(out,x,y)
            nsols += print_xy(out,1/x,-y)
      # negative n
      for n in range(-2^k,-16446,-2^k):
         assert n%(2^k)==0, "n%(2^k)==0"
         e = n//(2^k)
         # x^y = 2^(e*m)
         for m in range(1,floor(16445/abs(e))+1,2):
            x = RR(2^n)
            y = RR(m/2^k)
            nsols += print_xy(out,x,y)
            nsols += print_xy(out,1/x,-y)
   if out != None:
      out.close()
   return nsols

# split binade [2^(e-1),2^e) into k blocks for y
def doit_bacsel(y,e,k,t0=None,t1=None,neg=false):
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
      print ("./doit.sh " + str(u0) + " " + str(u1) + " 64 " + str(e) + " 64 24 64 " + y)

def a_mul(a,b):
   rh = a*b
   rl = fma(a,b,-rh)
   return rh, rl

def d_mul(ah,al,bh,bl):
   rh, p = a_mul(ah,bh)
   q = fma(al,bh,p)
   rl = fma(ah,bl,q)
   return rh, rl

# return the results of high_sum and the maximal absolute error
def high_sum_RIF(a,bh,bl):
   # rh, e = fast_two_sum (a, bh)
   rh = a + bh
   u = RIFulp(rh)
   e = RIF(-u,u)
   err1 = 2^-105*rh.abs().upper()
   rl = bl + e
   err2 = RIFulp(rl)
   return rh, rl, err1+err2

# return bound on absolute error
def d_mul_RIF(ah,al,bh,bl):
   # rh, p = a_mul(ah,bh)
   rh = ah*bh
   u = RIFulp(rh)
   p = RIF(-u,u)
   # q = fma(al,bh,p)
   q = al*bh+p
   # rl = fma(ah,bl,q)
   rl = ah*bl+q
   return rh, rl, RIFulp(q)+RIFulp(rl)+(al*bl).abs().upper()

# return bound on relative error in terms of |ah|
# assuming |al| <= scalea*|ah|, |bl| <= scaleb*|bh|
def d_mul_RIF_rel(ah,al,scalea,bh,bl):
   # rh, p = a_mul(ah,bh)
   rh = ah*bh
   u = RIFulp(rh)
   p = RIF(-u,u) # |p| <= 2^-52 |ah*bh|
   # q = fma(al,bh,p)
   q = al*bh+p
   qmax = (scalea+2^-52)*bh.abs().upper() # |q| <= qmax*|ah|
   err_q = 2^-52*qmax # err(q) <= err_q*|ah|
   # rl = fma(ah,bl,q)
   rl = ah*bl+RIF(q)
   rlmax = bl.abs().upper() + qmax
   err_rl = rlmax*2^-52  # err(rl) <= err_rl*|ah|
   return rh, rl, err_q+err_rl

def analyse_polyeval():
   R200 = RealField(200)
   err = dict()
   xh = RIF(-2^-11.999,2^-11.999)
   xl = RIF(-2^-64,2^-64)
   x = xh+xl
   ln2invh = RIF(RR("0x1.71547652b82fep+0",16))
   ln2invl = RIF(RR("0x1.777d0ffda0d24p-56",16))
   ln2inv = ln2invh+ln2invl
   # d_mul(&scaleh, &scalel, ln2invh, ln2invl, xh, xl)
   #    a_mul(scaleh, p, ln2invh, xh)
   #    q = fma(ln2invl, xh, p)
   #    scalel = fma(ln2invh, xl, q)
   scaleh = ln2invh*xh
   u = RIFulp(scaleh)
   p = RIF(-u,u) # |p| < ulp(scaleh)
   # a_mul is exact
   q = (ln2invl/ln2invh).upper()+2^-52 # in terms of scaleh
   e1 = 2^-52*q # maximal error for the 1st fma in terms of scaleh
   print ("   e1=", log(e1)/log(2.))
   scalel = RIF(2^-52+q) # |xl| <= 2^-52 |xl|
   e2 = 2^-52*scalel.abs().upper()
   print ("   e2=", log(e2)/log(2.))
   e3 = (ln2invl/ln2invh).upper()*2^-52 # error neglecting scalel*xl
   print ("   e3=", log(e3)/log(2.))
   e_scale = (1+R200(e1))*(1+R200(e2))*(1+R200(e3))-1
   print ("e_scale=", log(e_scale)/log(2.))
   # ord01h = -xh/2; ord01l = -xl/2;
   ord01h = -xh/2
   ord01l = -xl/2
   # high_sum(&ord01h, &ord01l, 1.0, ord01h, ord01l)
   ord01h, ord01l, err01 = high_sum_RIF(RIF(1.0), ord01h, ord01l)
   print ("err01=", log(err01)/log(2.))
   # ord23h = -xh/4
   ord23h = -xh/4
   # ord23l = __builtin_fma(-xl, 1./4, 0x1.55555a5b705aap-56)
   ord23l = -xl*1/4+RIF(RR("0x1.55555a5b705aap-56",16))
   # high_sum(&ord23h, &ord23l, 0x1.5555555555555p-2, ord23h, ord23l)
   c2h = RIF(RR("0x1.5555555555555p-2",16))
   ord23l_old = ord23l
   ord23h, ord23l, err23 = high_sum_RIF(c2h, ord23h, ord23l)
   err23 += RIFulp(ord23l_old) # error of the fma()
   print ("err23=", log(err23)/log(2.))
   # d_mul(&xsqh, &xsql, xh, xl, xh, xl)
   xsqh, xsql, err_xsq = d_mul_RIF(xh, xl, xh, xl)
   print ("err_xsq=", log(err_xsq)/log(2.))
   # d_mul(&ord23h, &ord23l, ord23h, ord23l, xsqh, xsql)
   ord23 = ord23h + ord23l
   ord23h, ord23l, err_23 = d_mul_RIF(ord23h, ord23l, xsqh, xsql)
   # add error on xsq
   err_23 += (ord23*RIF(err_xsq)).abs().upper()
   # add error on ord23
   err_23 += (RIF(err23)*(xsqh+xsql)).abs().upper()
   # add product of errors
   err_23 += err23*err_xsq
   print ("err_23=", log(err_23)/log(2.))
   # x4 = xsqh*xsqh
   x4 = xsqh*xsqh
   err_x4 = RIFulp(x4)
   # neglected terms
   err_x4 += (2*xsqh*xsql+xsql^2).abs().upper()
   # difference between xsq and x^2
   err_x4 += (2*RIF(err_xsq)*x+RIF(err_xsq)^2).abs().upper()
   print ("err_x4=", log(err_x4)/log(2.))
   # acc = fma(xh, -0x1.555555555554dp-3, 0x1.999999999998ap-3)
   c5 = RIF(RR("-0x1.555555555554dp-3",16))
   c4 = RIF(RR("0x1.999999999998ap-3",16))
   acc = xh*c5+c4
   err_acc = RIFulp(acc)
   # neglect xl
   err_acc += (xl*c5).abs().upper()
   print ("err_acc=", log(err_acc)/log(2.))
   # bcc = fma(xh, -0x1.0000014f8ec21p-3, 0x1.24924ad7557bep-3)
   c7 = RIF(RR("-0x1.0000014f8ec21p-3",16))
   c6 = RIF(RR("0x1.24924ad7557bep-3",16))
   bcc = xh*c7+c6
   err_bcc = RIFulp(bcc)
   # neglect xl
   err_bcc += (xl*c7).abs().upper()
   print ("err_bcc=", log(err_bcc)/log(2.))
   # acc = __builtin_fma(xsqh, bcc, acc)
   acc = xsqh*bcc+acc
   err_acc2 = RIFulp(acc)
   # error term (xsqh-x^2)*bcc
   err_acc2 += ((xsql+RIF(err_xsq))*bcc).abs().upper()
   # error on previous acc
   err_acc2 += err_acc
   print ("err_acc2=", log(err_acc2)/log(2.))
   # ord01l = __builtin_fma(x4, acc, ord01l)
   ord01l = x4*acc+ord01l
   err_ord01l = RIFulp(ord01l)
   err_ord01l += 2^-103.414 # error on ord01h + ord01l_old
   # error on acc2
   err_ord01l += (x4*RIF(err_acc2)).abs().upper()
   # error on x4
   err_ord01l += (RIF(err_x4)*acc).abs().upper()
   # combined errors
   err_ord01l += err_x4*err_acc2
   print ("err_ord01l=", log(err_ord01l)/log(2.))
   # high_sum(&ord23h, &ord23l, ord01h, ord23h, ord23l)
   ord23h, ord23l, err_23a = high_sum_RIF(ord01h, ord23h, ord23l)
   err_23a += err_ord01l # error from ord01l (including that on ord01h + ord01l_old)
   err_23a += err_23 # error on ord23
   # ord23l += ord01l
   ord23l += ord01l
   err_23a += RIFulp(ord23l)
   print ("err_23a=", log(err_23a)/log(2.))
   zmin = log(1+x.lower())/log(2.)/(RR(ln2inv)*x.lower())
   zmax = log(1+x.upper())/log(2.)/(RR(ln2inv)*x.upper())
   z = min(zmin,zmax)
   err_23a_rel = err_23a/z
   print ("err_23a_rel=", log(err_23a_rel)/log(2.))
   # take into account the Sollya error
   err_23b = (1 + R200(err_23a_rel))*(1+R200(2^-105.879))-1
   print ("err_23b=", log(err_23b)/log(2.))
   # d_mul(rh, rl, scaleh, scalel, ord23h, ord23l)
   rh, rl, err_r = d_mul_RIF_rel(scaleh, scalel, 2^-50.954, ord23h, ord23l)
   print ("err_r=", log(err_r)/log(2.))

# return possible combinations of i1 and i2
# possible=possible_i1_i2()
# len(possible)
# 4357 # over 128*96, i.e., about 35%
def possible_i1_i2(verbose=true):
   T1 = get_coarsetbl(verbose=false)
   T2 = get_finetbl(verbose=false)
   possible = []
   for i1 in range(128):
      xmin = 1 + i1/2^7
      xmax = 1 + (i1+1)/2^7
      r1 = T1[i1][2]
      r1xmin = r1*xmin
      r1xmax = r1*xmax
      for i2 in range(128):
         if 32 <= i2 < 64:
            continue # unused entry
         if i2 < 32:
            ymin = 1 + i2*2^-12
            ymax = 1 + (i2+1)*2^-12
         else:
            ymin = 1 - 2^-7 + (i2-64)*2^-13
            ymax = 1 - 2^-7 + (i2+1-64)*2^-13
         if ymax <= r1xmin or r1xmax <= ymin:
            if verbose:
               print ("not possible: i1=", i1, "i2=", i2)
         else:
            possible.append((i1,i2))
   return possible

# return interval corresponding to i1,i2
# get_interval(127,125)
# (8189/4096, 4095/2048)
def get_interval(i1,i2,T1=None,T2=None):
   assert 0 <= i1 < 128, "0 <= i1 < 128"
   assert 0 <= i2 < 32 or 64 <= i2 < 128, "0 <= i2 < 32 or 64 <= i2 < 128"
   if T1==None:
      T1 = get_coarsetbl(verbose=false)
   if T2==None:
      T2 = get_finetbl(verbose=false)
   xmin = 1 + i1/2^7
   xmax = 1 + (i1+1)/2^7
   r1 = T1[i1][2]
   if i2 < 32:
      ymin = 1 + i2*2^-12
      ymax = 1 + (i2+1)*2^-12
   else:
      ymin = 1 - 2^-7 + (i2-64)*2^-13
      ymax = 1 - 2^-7 + (i2+1-64)*2^-13
   ymin = max(ymin, r1*xmin)
   ymax = min(ymax, r1*xmax)
   # go back to x
   return ymin/r1, ymax/r1

# compute maximal value of |rh|/|mlogr12h+rh| for given i1,i2
# (when mlogr12h != 0)
# max_rh_over_rh_prime(127,125)
# 1.00183310592127
# With mlogr12=true, compute maximal value of |mlogr12h/(mlogr12h+rh)| instead
def max_rh_over_rh_prime(i1,i2,T1=None,T2=None,mlogr12=false):
   if T1==None:
      T1 = get_coarsetbl(verbose=false)
   if T2==None:
      T2 = get_finetbl(verbose=false)
   r1 = T1[i1][2]
   r2 = T2[i2][2]
   xmin, xmax = get_interval(i1,i2,T1=T1,T2=T2)
   xredmin = r1*r2*xmin
   xredmax = r1*r2*xmax
   rhmin = n(log(xredmin)/log(2))
   rhmax = n(log(xredmax)/log(2))
   rh = max(abs(rhmin),abs(rhmax))
   mlogr12h = n(-log(r1)/log(2)-log(r2)/log(2))
   mlogr12h = abs(mlogr12h - round(mlogr12h)) # compute centered fraction
   if mlogr12h == 0:
      return 1
   assert rh < mlogr12h, "rh < mlogr12h"
   rh_prime = mlogr12h - rh
   if mlogr12==false:
      return abs(rh/rh_prime)
   else:
      return abs(mlogr12h/rh_prime)

# compute maximal value of |rh/rh'| for all i1,i2 values
# max_rh_over_rh_prime_all()
# 0 0 1
# 127 125 1.00183310592127
# With mlogr12=true, compute maximal value of |mlogr12h/rh'| instead
# max_rh_over_rh_prime_all(mlogr12=true)
# 0 0 1
# 0 1 1.50045785683029
# 127 125 2.00183310592127
def max_rh_over_rh_prime_all(mlogr12=false):
   maxratio = 0
   S = possible_i1_i2(verbose=false)
   T1 = get_coarsetbl(verbose=false)
   T2 = get_finetbl(verbose=false)
   for i1,i2 in S:
      ratio = max_rh_over_rh_prime(i1,i2,T1=T1,T2=T2,mlogr12=mlogr12)
      if ratio > maxratio:
         print (i1, i2, ratio)
         maxratio = ratio

# compute maximal value of |mlogr12h|/|mlogr12h+rh| for given i1,i2
# (when mlogr12h != 0)
# max_mlogr12h_over_rh_prime(127,125)
# 2.00183310592127
def max_mlogr12h_over_rh_prime(i1,i2,T1=None,T2=None):
   if T1==None:
      T1 = get_coarsetbl(verbose=false)
   if T2==None:
      T2 = get_finetbl(verbose=false)
   r1 = T1[i1][2]
   r2 = T2[i2][2]
   xmin, xmax = get_interval(i1,i2,T1=T1,T2=T2)
   xredmin = r1*r2*xmin
   xredmax = r1*r2*xmax
   rhmin = n(log(xredmin)/log(2))
   rhmax = n(log(xredmax)/log(2))
   rh = max(abs(rhmin),abs(rhmax))
   mlogr12h = n(-log(r1)/log(2)-log(r2)/log(2))
   mlogr12h = abs(mlogr12h - round(mlogr12h)) # compute centered fraction
   if mlogr12h == 0:
      return 1
   assert rh < mlogr12h, "rh < mlogr12h"
   rh_prime = mlogr12h - rh
   return mlogr12h/rh_prime

# compute maximal value of |mlogr12h/rh'| for all i1,i2 values
# max_mlogr12h_over_rh_prime_all()
# 0 0 1
# 0 1 1.50045785683029
# 127 125 2.00183310592127
def max_mlogr12h_over_rh_prime_all():
   maxratio = 0
   S = possible_i1_i2(verbose=false)
   T1 = get_coarsetbl(verbose=false)
   T2 = get_finetbl(verbose=false)
   for i1,i2 in S:
      ratio = max_mlogr12h_over_rh_prime(i1,i2,T1=T1,T2=T2)
      if ratio > maxratio:
         print (i1, i2, ratio)
         maxratio = ratio

def print_out(out,s):
   if out==None:
      print (s)
   else:
      out.write(s + "\n")

def print_qint(x):
   R256 = RealField(256)
   t = R256(n(x,400))
   s, m, e = t.sign_mantissa_exponent()
   assert (m==0 or m.nbits()==256), "m==0 or m.nbits()==256"
   m = (2^256+m).digits(2^64) # add 2^256 to ensure it works for m=0 too
   hh = m[3]
   hl = m[2]
   lh = m[1]
   ll = m[0]
   if t != 0:
      e += 255
   if s==1:
      s = 0
   else:
      s = 1
   print ("    {.hh = " + hex(hh) + ", .hl = " + hex(hl) + ", .lh = " + hex(lh) + ", .ll = " + hex(ll) + ", .ex = " + str(e) + ", .sgn = " + hex(s) + "},")

def get_acc_coarsetbl(out=None):
   if out!=None:
      out = open(out,"w")
   T1 = get_coarsetbl(verbose=false)
   R256 = RealField(256)
   print_out (out, "static const qint64_t acc_coarsetbl[128] = {")
   for i in range(128):
      r = T1[i][2]
      z = 0
      if r <= 2**(-.5):
         z = 1
      t = R256(n(-log(r*2^z)/log(2),400))
      s, m, e = t.sign_mantissa_exponent()
      if m != 0:
         while m < 2^255:
            m = 2*m
            e = e-1
      m = (2^256+m).digits(2^64) # add 2^256 to ensure it works for m=0 too
      hh = m[3]
      assert (t==0 or hh.nbits()==64), "t==0 or hh.nbits()==64"
      hl = m[2]
      lh = m[1]
      ll = m[0]
      if t != 0:
         e += 255
      if s==1:
         s = 0
      else:
         s = 1
      print_out (out, "    {.hh = " + hex(hh) + ", .hl = " + hex(hl) + ", .lh = " + hex(lh) + ", .ll = " + hex(ll) + ", .ex = " + str(e) + ", .sgn = " + hex(s) + "},")
   print_out (out, "};")

def get_acc_finetbl(out=None):
   if out!=None:
      out = open(out,"w")
   T2 = get_finetbl(verbose=false)
   R256 = RealField(256)
   print_out (out, "static const qint64_t acc_finetbl[128] = {")
   for i in range(128):
      r = T2[i][2]
      t = R256(n(-log(r)/log(2),400))
      s, m, e = t.sign_mantissa_exponent()
      if 32 <= i < 64:
         t = m = e = 0
      if m != 0:
         while m < 2^255:
            m = 2*m
            e = e-1
      m = (2^256+m).digits(2^64) # add 2^256 to ensure it works for m=0 too
      hh = m[3]
      hl = m[2]
      lh = m[1]
      ll = m[0]
      if t != 0:
         e += 255
      if s==1:
         s = 0
      else:
         s = 1
      print_out (out, "    {.hh = " + hex(hh) + ", .hl = " + hex(hl) + ", .lh = " + hex(lh) + ", .ll = " + hex(ll) + ", .ex = " + str(e) + ", .sgn = " + hex(s) + "},")
   print_out (out, "};")

# p is the output from "sollya accurate_log2.sollya"
def output_logpoly(p):
   R.<x> = RealField(256)[]
   p = R(p)
   for d in range(18,-1,-1):
      print_qint (p[d].exact_rational())

# q is the output from "sollya accurate_exp2.sollya"
def output_exppoly(q):
   R.<x> = RealField(256)[]
   q = R(q)
   for d in range(10,-1,-1):
      print_qint (q[d].exact_rational())
