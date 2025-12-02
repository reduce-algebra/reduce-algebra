#load("../../generic/support/common.sage")
def print_tint(x):
   s,m,e = x.sign_mantissa_exponent()
   assert m.nbits()==192, "m.nbits()==192"
   if s==1:
      s=0
   else:
      s=1
   h = m//2^128
   m = m % 2^128
   l = m % 2^64
   m = m//2^64
   
   print ("   {.h=" + hex(h) + ", .m=" + hex(m) + ", .l=" + hex(l) + ", .ex=" + str(e+192) + ", .sgn=" + str(s) + "},")

# accuracy(2^-11.2,2^-9.6,15)
# 193.749000000000
def accuracy(x0,x1,d):
   s = "./doit.sh " + get_hex(x0) + " " + get_hex(x1) + " " + str(d)
   os.system(s)
   fp = open("/tmp/temp.out","r")
   s = fp.readline() # The precision has been set to 256 bits.
   s = fp.readline()
   return RR(s[:-1])

# with rminimax
# accuracy2(2^-11.2,2^-9.6,7)
# 195.058433640002
def accuracy2(x0,x1,d):
   assert d>=1, "d>=1"
   degrees = "1,x"
   for i in [2..d]:
      degrees += ",x^" + str(i)
   s = "./doit2.sh " + get_hex(x0) + " " + get_hex(x1) + " " + degrees
   os.system(s)
   fp = open("/tmp/rminimax.log","r")
   t = "fpminimax approximation error"
   while true:
      s = fp.readline()
      if s=='':
         print ("fpminimax approximation error not found")
         raise ValueError
      if s[:len(t)]==t:
         s = s.split()
         return -log(RR(s[-1]))/log(2.)

# search largest interval [x0,x1] on which a degree-15 polynomial has
# relative accuracy 2^-192 (cf atan2_temp.sollya)
# search_x1(2^-11.2,15)
# 0.00135533694704144
def search_x1(x0,d):
   a = x0
   b = 2*x0
   while accuracy(x0,b,d)>=192:
      b = 2*b
   for i in range(10):
      c = (a+b)/2
      e = accuracy(x0,c,d)
      if e>=192:
         a=c
      else:
         b=c
   return a

# with rminimax
def search2_x1(x0,d):
   a = x0
   b = 2*x0
   while accuracy2(x0,b,d)>=192:
      b = 2*b
   for i in range(10):
      c = (a+b)/2
      e = accuracy2(x0,c,d)
      if e>=192:
         a=c
      else:
         b=c
   return a

# cover the range [2^-11.2,1] with degree-d polynomials of relative accuracy
# at least 192 bits
# fill(15)
# 1 0.000425073517234436 0.00135533694704144 0.000930263429807002
# ...
# 1040 0.995134493842856 0.996106304871999 0.000971811029143455
# 1041 0.996106304871999 0.998051824998702 0.00194552012670313
# 1042 0.998051824998702 1.00000114496940 0.00194931997070058
# 1042*16=16672 coefficients
# fill(16)
# 573 0.999936298429129 1.00188929901200 0.00195300058286940
# 9741
# fill(17)
# 350 0.997969055670158 1.00089279313794 0.00292373746778363
# 6300
# fill(18)
# 231 0.997791634940196 1.00266366440768 0.00487202946748155
# 4389
# fill(19)
# 163 0.997811504728983 1.00658133240727 0.00876982767828194
# 3260
# fill(20)
# 118 0.997744765699094 1.00846272704938 0.0107179613502832
# 2478
# fill(21)
# 88 0.998413382105832 1.01303857813277 0.0146251960269410
# 1936
# fill(22)
# 67 0.985795615552796 1.00504943616906 0.0192538206162656
# 1541
def fill(d):
   x0 = 2^-11.2
   nranges = 0
   while true:
      x1 = search_x1(x0,d)
      nranges += 1
      print (nranges, x0, x1, x1-x0)
      if x1>=1:
         break
      x0 = x1
   # each polynomial of degree d has d+1 coefficients
   return nranges*(d+1)

# cover the range [2^-11.2,1] with degree-d polynomials of relative accuracy
# at least 192 bits
# fill2(6)
# 1 0.000425073517234436 0.000674140031238988 0.000249066514004552
# 2 0.000674140031238988 0.000922992503708068 0.000248852472469080
def fill2(d):
   x0 = 2^-11.2
   nranges = 0
   while true:
      x1 = search2_x1(x0,d)
      nranges += 1
      print (nranges, x0, x1, x1-x0)
      if x1>=1:
         break
      x0 = x1
   # each fraction of degree d has 2*(d+1) coefficients
   return nranges*(2*d+2)

# s = '{.h=0xb95481a447f30e0e, .m=0xb18f0f6f0f46479, .l=0xcc3f7d21bfeb9594, .ex=-3, .sgn=0x0}'
def parse_tint(s):
   s=s.split()
   h=ZZ(s[0][4:-1])
   m=ZZ(s[1][3:-1])
   l=ZZ(s[2][3:-1])
   ex=ZZ(s[3][4:-1])
   sgn=ZZ(s[4][5:-1])
   return (h/2^64+m/2^128+l/2^192)*2^ex*(-1)^sgn

R192=RealField(192)
P=[
"0x2.09c0fe2d4c44bb29c73989e7519ea91406726ca119adbfp-12",
"0xb.3cf74b427d53e03ee590b839e751890f2570b12bcb2381ap-12",
"0x2.c21262c5ee230e68478de0875e1363e89e56c52e12e75e3p-8",
"0x7.ea5d53dda9586c1d92a12df585026e1c90046cfd9a5b47f8p-8",
"0x1.2ca8329170bf670dc1702b59c84b50b37d942f8d3769ef4p-4",
"0x2.5aaa9752ebff1643c8f6de0edb933954b15381534eda7df8p-4",
"0x4.1e6a0dafd431588d6c7ceb71f5cec19a77a386c00fd01e5p-4",
"0x6.5de3ba90cbe60835e3367d9f6f7d371ab4597cf27f5c488p-4",
"0x8.cf8f7c585767042cd92a5b9ac13d8c8043bd4a023dbe04dp-4",
"0xa.fdc36d6b36139bf11df63474e3859d442b30b2c089a2b6cp-4",
"0xc.6f8fb14638225192f9f04cf55c103771c44675c6d483606p-4",
"0xc.ce79f10f754e31591ce47edcbc8a4eeb2a6f721ac656b42p-4",
"0xc.090384dbd77132e1dfb4d9a1d595de7e506ca899a394f7p-4",
"0xa.556ac9eee25e867d84dafa25141d203f1c7c2a5156b3ec3p-4",
"0x8.1bd2677ddfcbc381df33f27dbb60939cb4c2c73286a6c29p-4",
"0x5.cf6890b4eb9746ce40ecaee7789e113cba5cabcb5c9e199p-4",
"0x3.cb7db6a1d6d99beb0a774e9a709d31960ee49825db23c314p-4",
"0x2.40b4d3536e443b61bcfb377f5abc2a7e3a5435f9c2a3a6c8p-4",
"0x1.35df4832c39c240f59a062ecccea6ea27d5e854a7f98ca68p-4",
"0x9.5db9977c5e6e26385367a63fab8a720fc2b63bd115998d8p-8",
"0x4.0be5b6c11b6afa6b863c0af94484ecd862a74b8aae890acp-8",
"0x1.8bdd8845186a4130f13cad7c3bdd36cf744b7b5025259982p-8",
"0x8.40c38ccfcb5dc64b55a44095bf7f3126668b8792d4ecd08p-12",
"0x2.5c1d2bdeca1ac67b082ab087cc4c3c74da7a7f6f75214a28p-12",
"0x9.054011c32d4b7a5c68d3c5d525f4af4eeb3c98615dee188p-16",
"0x1.bbb6945d5565762aea6ec351e1d3551a7e40c419a7c0eb76p-16",
"0x4.077cd0d9f2cd5f28c7357f0328fefa4e8e0194f353816ce8p-20",
"0x6.50b6ea4e69842a65d6c651bca00813e0fe3fa3cc2a4378bp-24",
"0x5.05d00dc3a15d400f36e0a54a8b6bf820fa981ec3c482e978p-28",
"-0x1.38088112d9cca2b819e68e1f4fe2158753b900d05822353ap-60"
]
P=[R192(x,16) for x in P]

Q=[
"0x2.09c0fe2d4c44bb29c73989e7519ea91406726ca119adbfp-12",
"0xb.3cf74b427d53e03ee590b839e751890f2570b12bcb238cfp-12",
"0x2.ccf112bc350f27a3d109be11851c076e5e7927716e161108p-8",
"0x8.264d256f0bf4d61ee21431cc0f29764ce0cc1b593ac9952p-8",
"0x1.3b2f8928ed0f65ddde810f893bbca452e8578dc057f6dbfp-4",
"0x2.83e22371eaae527bd88fc66b104f6c8e151d128593dc3b34p-4",
"0x4.7ece38b955841470d4fb97d6d7e1efdd7cb50c07514b8bcp-4",
"0x7.1c0b45bc528f70ab02523c0ae4048f5cfd5521189747598p-4",
"0xa.164ccdbb65ee133e623433c5e086402cb228afd335a245fp-4",
"0xc.ed0c0cbe44fac2fd7c2adfc7c5dda9ea22b4a311cf5a5b1p-4",
"0xf.0e6660438c903713dca1a0f58f0d9438a92b9de68c4488cp-4",
"0x1p+0",
"0xf.8ea68f9ad849103b257e4bfc606967f818fa2816928c4aap-4",
"0xd.dc64eeee350623447a33ea40a2b22e4a6a2c129ace2470ap-4",
"0xb.52ddfba2d37c8e224551a9b19fa064a3d78c68b54bc385p-4",
"0x8.7ac113d26b683a14e97756c38785b0bf75f0a4506931ba8p-4",
"0x5.d0328385c8079eaf24ec7cf91c78f75b402ea46b3f8ee6c8p-4",
"0x3.a40b4a92ff0891065173f9b20e96e0a1467aed15fe33328p-4",
"0x2.1390172457ddda6c3eabcd30f14774e6a5fe82ba64e0b24cp-4",
"0x1.12db48d8fcd9d767c15f816db67b77ea0c399fedcf1dffe8p-4",
"0x8.01a0c1a0dfefc92f8e0a97902e08d4781898e0b7d8ef0bcp-8",
"0x3.56742224c37c1f6ea32c00086127eebfe033246a82f77e24p-8",
"0x1.3b6ad4d3096ee4639ef840e9c09012b2662dd954d548c09cp-8",
"0x6.5ba286ceb1697344bc3da132cbbe8025d30ae77005420eb8p-12",
"0x1.c254a5c056c9647d2f92273519dae2d8e142ed5a56be2da4p-12",
"0x6.82bdb6848076986af025d8bf5c3cd2f11f689adb05f5038p-16",
"0x1.363e39445fdef5ca334d0fe1480e7ddc0b5399791828af16p-16",
"0x2.bae9c43c14eab0ecc3a975bec45bddd62a6f3fbd5a63e3c4p-20",
"0x4.25cd6d03b66803e89f2a803039fbb58a67a12ccb411479fp-24",
"0x3.3292e4119e1a4df48cf079a47049f07fd24f82de8f791668p-28"
]
Q=[R192(x,16) for x in Q]

# evaluate P from degree i0
def evalP(z,i0=0):
   global P
   R = P[0].parent()
   Z = R(z).exact_rational()
   return add(P[i]*Z^(i-i0) for i in [i0..29])

# evaluate Q from degree i0
def evalQ(z,i0=0):
   global Q
   R = Q[0].parent()
   Z = R(z).exact_rational()
   return add(Q[i]*Z^(i-i0) for i in [i0..29])

# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

# bound the relative error of evaluating Psmall for 2^(e-1) <= z < 2^e
# errPsmall(-11)
# (7.24310309188909e-52, -169.883653024657)
def errPsmall(e):
   Psmall=["1","-0x1.5555555555555555555555555555555555555555569de77ep-2","0x1.9999999999999999999999999999999999be8f1d48d2355cp-3","-0x1.2492492492492492492492492492c75ep-3","0x1.c71c71c71c71c71c71c71dbb1af83beap-4","-0x1.745d1745d1745d18p-4","0x1.3b13b13b13d919bap-4","-0x1.1111103a0ee2178ep-4"]
   R = RealField(192)
   Psmall = [R(x,16) for x in Psmall]
   RI = RealIntervalField(192)
   z = RI(2^(e-1),2^e)
   # mul_tint (z2, z, z)
   z2 = z*z
   err_z2 = 2^-184.37*z2.abs().upper()
   # cp_tint (p, Psmall+7)
   p = RI(Psmall[7])
   err = dict()
   err[0] = R(2^-192.031) # relative
   for i in range(6,-1,-1):
      # mul_tint (p, p, z2)
      p = p*z2
      err[i] = RIFulp(p)*10+p.abs().upper()*err_z2
      # add_tint (p, p, Psmall+i)
      err[i] += RIFulp(p)*2
      err[i] *= z.abs().upper()^(2*i+1)
      print ("i=", i, "err=", err[i])
   # mul_tint (p, p, z)
   p = p*z
   err[-1] = RIFulp(p)*2
   print ("i=", -1, "err=", err[-1])
   err[0] *= p.abs().upper() # convert into absolute error
   print ("err0=", err[0])
   abserr = add(err[i] for i in [-1..6])
   # convert into relative error
   relerr = abserr/p.abs().lower()
   return relerr, log(relerr)/log(2.)

# bound the relative error of evaluating P for z0 <= z < z1
def errP(z0,z1,verbose=false):
   global P
   R = P[0].parent()
   RI = RealIntervalField(192)
   z = RI(z0,z1)
   # cp_tint (p, P + 29)
   p = RI(P[29])
   err = dict()
   for i in range(28,-1,-1):
      # mul_tint (p, p, z)
      p = p*z
      err[i] = RIFulp(p)*10
      # add_tint (p, p, P + i)
      p += RI(P[i])
      err[i] += RIFulp(p)*2
      err[i] *= z.abs().upper()^(i+1)
      if verbose:
         print ("i=", i, "err=", err[i])
   # mul_tint (p, p, z)
   p = p*z
   err[-1] = RIFulp(p)*10
   abserr = add(err[i] for i in [-1..28])
   # convert into relative error
   relerr = abserr/p.abs().lower()
   if verbose:
      print (p.lower(), p.upper())
   return relerr, log(relerr)/log(2.)

# split [2^(e-1),2^e] into 2^K subintervals
# for e in [-11..0]: print (e, errPsplit(e,13))
# -11 -187.417359243749
# -10 -187.415230859039
# -9 -187.411001862242
# -8 -187.402507687235
# -7 -187.385876690941
# -6 -187.353608725411
# -5 -187.292626399476
# -4 -187.182885883121
# -3 -186.669487256092
# -2 -186.181016333870
# -1 -185.192629736073
# 0 -184.140838521233
def errPsplit(e,K=0):
   maxerr = 0
   z0 = RR(2^(e-1))
   z1 = RR(2^e)
   h = (z1-z0)/2^K
   for k in range(2^K):
      err, _ = errP(z0+k*h,z0+(k+1)*h)
      if err > maxerr:
         maxerr = err
         # print (e, k, log(err)/log(2.))
   return log(maxerr)/log(2.)

# bound the relative error of evaluating Q for z0 <= z < z1
def errQ(z0,z1,verbose=false):
   global Q
   R = Q[0].parent()
   RI = RealIntervalField(192)
   z = RI(z0,z1)
   # cp_tint (q, Q + 29)
   q = RI(Q[29])
   err = dict()
   for i in range(28,-1,-1):
      # mul_tint (q, q, z)
      q = q*z
      err[i] = RIFulp(q)*10
      # add_tint (q, q, Q + i)
      q += RI(Q[i])
      err[i] += RIFulp(q)*2
      err[i] *= z.abs().upper()^i
      if verbose:
         print ("i=", i, "err=", err[i])
   abserr = add(err[i] for i in [0..28])
   # convert into relative error
   relerr = abserr/q.abs().lower()
   if verbose:
      print (q.lower(), q.upper())
   return relerr, log(relerr)/log(2.)

# for e in [-11..0]: print (e, errQsplit(e,12))
# -11 -190.013965443819
# -10 -190.000838306720
# -9 -189.974973182012
# -8 -189.924734778852
# -7 -189.829748268406
# -6 -189.658588949034
# -5 -189.373533856930
# -4 -188.949869141158
# -3 -187.568331977945
# -2 -186.574207403120
# -1 -185.445470981270
# 0 -184.190050548305
def errQsplit(e,K=0):
   maxerr = 0
   z0 = RR(2^(e-1))
   z1 = RR(2^e)
   h = (z1-z0)/2^K
   for k in range(2^K):
      err, _ = errQ(z0+k*h,z0+(k+1)*h)
      if err > maxerr:
         maxerr = err
   return log(maxerr)/log(2.)

Pfast = [
"0x2.ae5a542b4fc84761ccdddcd356p-4",
"0x5.75b9e83dbf59bf47d948af9204p-4",
"0xa.9899bac8e07e97245c7c222e5cp-4",
"0xc.b5c2d1a4b9b89237f25f712358p-4",
"0xc.b4cf18dd31adb7d5de087a75bp-4",
"0x9.79c4fa35e708959b7e80c80c6p-4",
"0x5.89a3b3083dbf433e3452b55accp-4",
"0x2.5c5cdf41251f9606caab295e94p-4",
"0xa.d9bbdab41ed6945f16809d73ep-8",
"0x1.9b473aa37aa8e3687efb36beb7p-8",
]

Qfast = [
"0x2.ae5a542b4fc84763316f8984ap-4",
"0x5.75b9e83dbf59b99b1d0c71f39cp-4",
"0xb.7d628181fb1a7fc446566ce398p-4",
"0xe.87ab7463f87e010c30c8db073p-4",
"0x1p+0",
"0xd.3a1d36d05637131307707bdda8p-4",
"0x8.f4bf094a385162d821aa2685cp-4",
"0x4.a4cf05dc964786993c42800224p-4",
"0x1.ce97fd0d9ddc264487eb1ba6ab8p-4",
"0x7.8d43a9af10bb8e06e9e18cc4dep-8",
"0x1.05f0a6795af0298b0ab08fa18bp-8",
]

R106 = RealField(106)
Pfast = [R106(x,16) for x in Pfast]
Qfast = [R106(x,16) for x in Qfast]

# output_fast(Pfast)
# output_fast(Qfast)
def output_fast(p):
   global R106
   for x in p:
      h = RR(x)
      l = RR(x - R106(h))
      assert x.exact_rational() == h.exact_rational() + l.exact_rational()
      print ("   {" + get_hex(h) + ", " + get_hex(l) + "},")

# return Sollya approximation polynomial for atan(x) for x0-h <= x <= x0+h
# sollya_approx(0.25,0.25,10,5)
# use precision 107 up to degree i
def sollya_approx(x0,h,d,i):
   s = "./doit.sh"
   s += " " + get_hex(x0) + " " + get_hex(h) + " " + str(d)
   s += " '107"
   for j in range(i):
      s += ",107"
   s += ",53...'"
   os.system (s)
   f = open("out","r")
   s = f.readline()
   R.<x> = RealField(107)[]
   p = R(s)
   s = f.readline()
   ret = RR(s[:-1])
   f.close()
   return p, ret

# cut (0,1) into k subintervals, excluding first interval near 0
# and adding an extra interval (1,1+1/k)
# Sollya_approx(64,5,5)
# 46.9760000000000
# Sollya_approx(64,6,6)
# 52.3720000000000
# Sollya_approx(64,7,7)
# 62.9780000000000
# Sollya_approx(64,7,1)
# 62.9760000000000
def Sollya_approx(k,d,i0,verbose=false):
   h = 1.0/k
   minerr = infinity
   for i in range(1,k+1):
      x0 = (i+1/2)*h
      p, err = sollya_approx(x0,h/2,d,i0)
      # check_poly(p,h/2)
      err1 = err_poly(p,i,x0-h/2,x0+h/2,0)
      print (i, log(err1)/log(2.))
      if verbose:
         print_poly(p,i0,err,i)
      minerr = min(minerr,err)
   return minerr

def print_poly(p,i0,err,j):
   s = "  {"
   R107 = RealField(107)
   for i in [0..i0]:
      h = RR(p[i])
      l = RR(p[i]-R107(h))
      assert p[i].exact_rational()==h.exact_rational()+l.exact_rational()
      s += get_hex(h) + ", " + get_hex(l) + ", "
   for i in [i0+1..p.degree()]:
      h = RR(p[i])
      assert p[i].exact_rational()==h.exact_rational()
      s += get_hex(h)
      if i<p.degree():
         s += ", "
   s += "}, /* i=" + str(j) + " " + str(float(err)) + " */"
   print (s)

# check if when evaluating p(x) for |x| <= h with Horner's rule,
# the coefficient p[i] is always larger in absolute value than
# p[i+1]*x + p[i+2]*x^2 + ...
def check_poly(p,h):
   p = p.change_ring(RR)
   d = p.degree()
   h = RIF(h)
   q = RIF(p[d])
   for i in range(d-1,-1,-1):
      q = h*q
      if abs(p[i])<q.abs().upper():
         print ("check_poly failed for p=", p, "at i=", i)
         raise ValueError
      q = RIF(p[i])+q

# return the 'ulp' of the interval x, i.e., max(ulp(t)) for t in x
# this internal routine is used below
def RIFulp(x):
   return max(x.lower().ulp(),x.upper().ulp())

def table_err_poly():
   s = "0x1.adp-65" # bound for i=0 (special case)
   R = RealField(9,rnd='RNDU')
   for i in range(1,65):
      p, err = sollya_approx((i+0.5)/64,1/128.,7,1)
      err = err_poly(p,i,-1./128,1./128,err)
      err = err + 2^-101.604
      err = R(err)
      s += ", " + get_hex(err)
   print (s)

# max_l()
# 3.41711218583539e-17 # value for i=0
def max_l():
   maxl = 2^(-6-48.7) # |l| < 2^(e-48.7) for i=0 with 2^(e-1) < z < 2^e
   for i in range(1,64):
      p, err = sollya_approx((i+0.5)/64,1/128.,7,1)
      l = err_poly(p,i,-1./128,1./128,err,bound_l=true)
      l = max(maxl,l)
   return maxl

# same as err_poly() but for i=0
def err_poly0(x0,x1,err0,verbose=false):
   p = ["0x0", "0x1p0", "0x0", "-0x1.5555555555555p-2", "0x0", "0x1.9999999999922p-4", "0x0", "-0x1.249247c670632p-3", "0x0", "0x1.c6e5d41706f0dp-4"]
   R.<x> = RR[]
   p = add(RR(p[i],16)*x^i for i in [0..9])
   return err_poly(p,0,x0,x1,err0,verbose=verbose)

# split each binade [2^(e-1),2^e] for e0 <= e <= e1 into 2^K subintervals
# Err_poly0(71.798,e0=-34,K=8)
# 4.55142303056794?e-20
def Err_poly0(err0,K=0,e0=-1073,e1=-6,verbose=false):
   maxerr = 0
   for e in [e0..e1]:
      X0 = RR(2^(e-1))
      X1 = RR(2^e)
      h = (X1-X0)/2^K
      for k in range(2^K):
         x0 = X0+k*h
         x1 = x0+h
         err = err_poly0(x0,x1,err0,verbose=verbose)
         if err>maxerr:
            if verbose:
               print ("e=", e, "k=", k, "err=", log(err)/log(2.))
            maxerr = err
   return maxerr

# compute the maximal relative error when evaluating p(x) for x0 <= x <= x1
# with Horner's rule, where err0 is the relative error from Sollya
# if bound_l=true, return a bound on the final value l
# p, err = sollya_approx(1.5/64,1/128.,7,1)
# err_poly(p,1,-1./128,1./128,err)
# 2.37954235609872e-19
# err_poly(p,1,-1./128,1./128,err,bound_l=true)
# 1.78253939491364e-15
def err_poly(p,i,x0,x1,err0,verbose=false,bound_l=false):
   R = p.parent()
   zh = RIF(x0,x1)
   zl = RIF(2^-48.999)
   p = p.change_ring(RIF)
   R = RealField(107)
   d = p.degree()
   err = dict()
   # z = zh + zl
   z = zh+zl
   if i==0:
      assert d==9, "d==9"
   else:
      assert d==7, "d==7"
   # h = (i == 0) ? __builtin_fma (P9, z * z, p[9]) ? p[9]
   if i==0:
      z2 = z*z
      t = p[9]*z2
      h = t+p[7]
      err[7] = (RIFulp(h)+RIFulp(t)+p[9]*RIFulp(z2))*z.abs().upper()^7
   else:
      h = p[7]
      err[7] = 0
   errz = RIFulp(z)
   for j in range(6,1,-1):
      # *h = __builtin_fma (*h, zh, p[2+j])
      hold = h
      h = h*z+p[j]
      # the term hold*errz comes from the rounding error in z = zh+zl
      err[j] = (RIFulp(h)+(hold*RIF(errz)).abs().upper())*z.abs().upper()^j
      if verbose:
         print ("j=", j, "err=", log(err[j])/log(2.))
   p2 = RR(p[1].upper())
   p3 = RR(p[1].upper()-R(p2))
   # s_mul (h, l, *h, zh, zl)
   #   a_mul(h, l, h_old, zh)
   #   l = fma(h_old, zl, l)
   h_old = h
   h = h_old*zh
   u = RIFulp(h)
   l = RIF(-u,u)
   err[1] = RIFulp(l) # error on a_mul
   l += h_old*zl
   err[1] += RIFulp(l) # error on fma
   # fast_two_sum (h, t, p[2], *h)
   h = RIF(p2)+h
   u = RIFulp(h)
   t = RIF(-u,u)
   err[1] += h.abs().upper()*2^-105 # error on fast_two_sum
   # *l += t + p[3]
   t = t+RIF(p3)
   err[1] += RIFulp(t) # error on t+p3
   l += t
   err[1] += RIFulp(l) # error on l += ...
   err[1] *= z.abs().upper()
   if verbose:
      print ("j=", 1, "err=", log(err[1])/log(2.))
   p0 = RR(p[0].upper())
   p1 = RR(p[0].upper()-R(p0))
   # d_mul (h, l, *h, *l, zh, zl)
   #   a_mul(h, s, h_old, zh)
   #   t = __builtin_fma(l, zh, s)
   #   l = fma(h_old, zl, t)
   h_old = h
   h = h_old*zh
   u = RIFulp(h)
   s = RIF(-u,u)
   err[0] = RIFulp(s) # error on a_mul
   t = l*zh+s
   err[0] += RIFulp(t)
   l = h_old*zl+t
   err[0] += RIFulp(l)
   # fast_two_sum (h, t, p[0], *h)
   h = h+RIF(p0)
   u = RIFulp(h)
   t = RIF(-u,u)
   if p[0]!=0:
      err[0] += h.abs().upper()*2^-105 # error on fast_two_sum
   # *l += t + p[1]
   t = t+RIF(p1)
   if p[0]!=0:
      err[0] += RIFulp(t) # error on t+p1
   l += t
   if bound_l:
      return l.abs().upper()
   if p[0]!=0:
      err[0] += RIFulp(l) # error on l += ...
   if verbose:
      print ("j=", 0, "err=", log(err[0])/log(2.))
   tot_err = add(err[i] for i in [0..7])
   # add err0
   res = h+l
   if verbose:
      print ("h+l:", res.lower(), res.upper())
   tot_err += 2^-err0*res.abs().upper()
   rel_err = tot_err/res.abs().lower()
   return rel_err

def fast_div1(bh,ah):
   y = 1.0 / ah
   h = bh * y
   eh = fma(ah,-h,bh)
   l = y*eh
   return h,l

# check in the case bh<ah
# bh= 0x1.4635784480293p-2 ah= 0x1.fcff153004559p+0 err= -103.783510920775
# bh= 0x1.f82e017456211p+0 ah= 0x1.fb1609f351d64p+0 l= -52.4453569676213
def check_fast_div1(K,rnd='RNDN'):
   R = RealField(53,rnd=rnd)
   maxerr = 0
   maxl = 0
   for k in range(K):
      ah = R.random_element(1,2)
      bh = R.random_element(0,ah)
      h, l = fast_div1(bh,ah)
      y = bh.exact_rational()/ah.exact_rational()
      z = h.exact_rational()+l.exact_rational()
      err = float(abs(z-y)/y)
      if err>maxerr:
         maxerr = err
         print ("bh=", get_hex(bh), "ah=", get_hex(ah), "err=", log(err)/log(2.))
      if abs(l)>maxl:
         maxl = abs(l)
         print ("bh=", get_hex(bh), "ah=", get_hex(ah), "l=", log(maxl)/log(2.))
