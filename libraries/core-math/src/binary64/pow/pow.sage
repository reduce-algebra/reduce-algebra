#load("../../generic/support/common.sage")
T1 = [("              0x1p+0", "               0x0.p+0"),    ("0x1.02c9a3e778061p+0", " -0x1.19083535b086p-56"),    ("0x1.059b0d3158574p+0", " 0x1.d73e2a475b464p-55"),    ("0x1.0874518759bc8p+0", "   0x1.186be4bb285p-57"),    ("0x1.0b5586cf9890fp+0", " 0x1.8a62e4adc610ap-54"),    ("0x1.0e3ec32d3d1a2p+0", "  0x1.03a1727c57b4p-59"),    ("0x1.11301d0125b51p+0", "-0x1.6c51039449b3ap-54"),    (" 0x1.1429aaea92dep+0", "-0x1.32fbf9af1369ep-54"),    ("0x1.172b83c7d517bp+0", "-0x1.19041b9d78a74p-55"),    ("0x1.1a35beb6fcb75p+0", " 0x1.e5b4c7b4968e4p-55"),    ("0x1.1d4873168b9aap+0", " 0x1.e016e00a2643cp-54"),    ("0x1.2063b88628cd6p+0", " 0x1.dc775814a8494p-55"),    ("0x1.2387a6e756238p+0", " 0x1.9b07eb6c70572p-54"),    ("0x1.26b4565e27cddp+0", " 0x1.2bd339940e9d8p-55"),    ("0x1.29e9df51fdee1p+0", " 0x1.612e8afad1254p-55"),    ("0x1.2d285a6e4030bp+0", " 0x1.0024754db41d4p-54"),    ("0x1.306fe0a31b715p+0", " 0x1.6f46ad23182e4p-55"),    ("0x1.33c08b26416ffp+0", " 0x1.32721843659a6p-54"),    ("0x1.371a7373aa9cbp+0", "-0x1.63aeabf42eae2p-54"),    ("0x1.3a7db34e59ff7p+0", " -0x1.5e436d661f5ep-56"),    ("0x1.3dea64c123422p+0", " 0x1.ada0911f09ebcp-55"),    ("0x1.4160a21f72e2ap+0", " -0x1.ef3691c30928p-58"),    ("0x1.44e086061892dp+0", "  0x1.89b7a04ef80cp-59"),    (" 0x1.486a2b5c13cdp+0", "  0x1.3c1a3b69062fp-56"),    ("0x1.4bfdad5362a27p+0", "  0x1.d4397afec42ep-56"),    ("0x1.4f9b2769d2ca7p+0", "-0x1.4b309d25957e4p-54"),    ("0x1.5342b569d4f82p+0", "-0x1.07abe1db13cacp-55"),    ("0x1.56f4736b527dap+0", " 0x1.9bb2c011d93acp-54"),    ("0x1.5ab07dd485429p+0", " 0x1.6324c054647acp-54"),    ("0x1.5e76f15ad2148p+0", " 0x1.ba6f93080e65ep-54"),    ("0x1.6247eb03a5585p+0", "-0x1.383c17e40b496p-54"),    ("0x1.6623882552225p+0", "-0x1.bb60987591c34p-54"),    ("0x1.6a09e667f3bcdp+0", "-0x1.bdd3413b26456p-54"),    ("0x1.6dfb23c651a2fp+0", " -0x1.bbe3a683c88bp-57"),    ("0x1.71f75e8ec5f74p+0", "-0x1.16e4786887a98p-55"),    ("0x1.75feb564267c9p+0", "-0x1.0245957316dd4p-54"),    ("0x1.7a11473eb0187p+0", " -0x1.41577ee04993p-55"),    ("0x1.7e2f336cf4e62p+0", "  0x1.05d02ba15798p-56"),    ("0x1.82589994cce13p+0", "-0x1.d4c1dd41532d8p-54"),    ("0x1.868d99b4492edp+0", "-0x1.fc6f89bd4f6bap-54"),    ("0x1.8ace5422aa0dbp+0", " 0x1.6e9f156864b26p-54"),    ("0x1.8f1ae99157736p+0", " 0x1.5cc13a2e3976cp-55"),    ("0x1.93737b0cdc5e5p+0", " -0x1.75fc781b57ecp-57"),    (" 0x1.97d829fde4e5p+0", " -0x1.d185b7c1b85dp-54"),    (" 0x1.9c49182a3f09p+0", "  0x1.c7c46b071f2cp-56"),    ("0x1.a0c667b5de565p+0", "-0x1.359495d1cd532p-54"),    ("0x1.a5503b23e255dp+0", "-0x1.d2f6edb8d41e2p-54"),    ("0x1.a9e6b5579fdbfp+0", " 0x1.0fac90ef7fd32p-54"),    ("0x1.ae89f995ad3adp+0", " 0x1.7a1cd345dcc82p-54"),    ("0x1.b33a2b84f15fbp+0", "  -0x1.2805e3084d7p-57"),    ("0x1.b7f76f2fb5e47p+0", "-0x1.5584f7e54ac38p-56"),    ("0x1.bcc1e904bc1d2p+0", " 0x1.23dd07a2d9e84p-55"),    ("0x1.c199bdd85529cp+0", " 0x1.11065895048dcp-55"),    ("0x1.c67f12e57d14bp+0", " 0x1.2884dff483cacp-54"),    ("0x1.cb720dcef9069p+0", " 0x1.503cbd1e949d8p-56"),    ("0x1.d072d4a07897cp+0", "-0x1.cbc3743797a9cp-54"),    ("0x1.d5818dcfba487p+0", " 0x1.2ed02d75b3708p-55"),    ("0x1.da9e603db3285p+0", " 0x1.c2300696db532p-54"),    ("0x1.dfc97337b9b5fp+0", "-0x1.1a5cd4f184b5cp-54"),    ("0x1.e502ee78b3ff6p+0", "  0x1.39e8980a9cc9p-55"),    ("0x1.ea4afa2a490dap+0", "-0x1.e9c23179c2894p-54"),    ("0x1.efa1bee615a27p+0", "  0x1.dc7f486a4b6bp-54"),    (" 0x1.f50765b6e454p+0", " 0x1.9d3e12dd8a18ap-54"),    ("0x1.fa7c1819e90d8p+0", "  0x1.74853f3a5932p-55")]

T2 = [("              0x1p+0", "               0x0.p+0"), ("0x1.000b175effdc7p+0", " 0x1.ae8e38c59c72ap-54"), ("0x1.00162f3904052p+0", "  -0x1.7b5d0d58ea9p-58"), ("0x1.0021478e11ce6p+0", " 0x1.4115cb6b16a8ep-54"), ("0x1.002c605e2e8cfp+0", " -0x1.d7c96f201bb3p-55"), ("0x1.003779a95f959p+0", "  0x1.84711d4c35eap-54"), ("0x1.0042936faa3d8p+0", "-0x1.0484245243778p-55"), (" 0x1.004dadb113dap+0", "-0x1.4b237da2025fap-54"), ("0x1.0058c86da1c0ap+0", " -0x1.5e00e62d6b31p-56"), ("0x1.0063e3a559473p+0", "  0x1.a1d6cedbb948p-54"), ("0x1.006eff583fc3dp+0", "-0x1.4acf197a00142p-54"), ("0x1.007a1b865a8cap+0", " -0x1.eaf2ea42391ap-57"), ("0x1.0085382faef83p+0", " 0x1.da93f90835f78p-56"), ("0x1.00905554425d4p+0", "-0x1.6a79084ab093cp-55"), ("0x1.009b72f41a12bp+0", " 0x1.86364f8fbe8f8p-54"), ("0x1.00a6910f3b6fdp+0", " -0x1.82e8e14e3111p-55"), ("0x1.00b1afa5abcbfp+0", " -0x1.4f6b2a7609f7p-55"), ("0x1.00bcceb7707ecp+0", "-0x1.e1a258ea8f718p-56"), ("0x1.00c7ee448ee02p+0", "  0x1.4362ca5bc26fp-56"), ("0x1.00d30e4d0c483p+0", " 0x1.095a56c919d02p-54"), ("0x1.00de2ed0ee0f5p+0", " -0x1.406ac4e81a64p-57"), (" 0x1.00e94fd0398ep+0", " 0x1.b5a6902767e08p-54"), ("0x1.00f4714af41d3p+0", " -0x1.91b206085932p-54"), ("0x1.00ff93412315cp+0", " 0x1.427068ab22304p-55"), ("0x1.010ab5b2cbd11p+0", " 0x1.c1d0660524e08p-54"), ("0x1.0115d89ff3a8bp+0", "-0x1.e7bdfb3204be8p-54"), ("0x1.0120fc089ff63p+0", " 0x1.843aa8b9cbbc8p-55"), ("0x1.012c1fecd613bp+0", "-0x1.34104ee7edae8p-56"), ("0x1.0137444c9b5b5p+0", " -0x1.2b6aeb617689p-56"), ("0x1.01426927f5278p+0", "  0x1.a8cd33b8a1bbp-56"), ("0x1.014d8e7ee8d2fp+0", " 0x1.2edc08e5da998p-56"), ("0x1.0158b4517bb88p+0", " 0x1.57ba2dc7e0c74p-55"), ("0x1.0163da9fb3335p+0", " 0x1.b61299ab8cdb8p-54"), ("0x1.016f0169949edp+0", "-0x1.90565902c5f44p-54"), ("0x1.017a28af25567p+0", " 0x1.70fc41c5c2d54p-55"), ("0x1.018550706ab62p+0", " 0x1.4b9a6e145d76cp-54"), ("0x1.019078ad6a19fp+0", "-0x1.008eff5142bf8p-56"), ("0x1.019ba16628de2p+0", "-0x1.77669f033c7dep-54"), ("0x1.01a6ca9aac5f3p+0", "-0x1.09bb78eeead0ap-54"), ("0x1.01b1f44af9f9ep+0", " 0x1.371231477ece6p-54"), ("0x1.01bd1e77170b4p+0", " 0x1.5e7626621eb58p-56"), ("0x1.01c8491f08f08p+0", "-0x1.bc72b100828a4p-54"), (" 0x1.01d37442d507p+0", " -0x1.ce39cbbab8bcp-57"), ("0x1.01de9fe280ac8p+0", " 0x1.16996709da2e4p-55"), ("0x1.01e9cbfe113efp+0", "-0x1.c11f5239bf534p-55"), ("0x1.01f4f8958c1c6p+0", " 0x1.e1d4eb5edc6b4p-55"), ("0x1.020025a8f6a35p+0", " -0x1.afb99946ee3fp-54"), ("0x1.020b533856324p+0", "-0x1.8f06d8a148a32p-54"), ("0x1.02168143b0281p+0", "-0x1.2bf310fc54eb4p-55"), ("0x1.0221afcb09e3ep+0", "-0x1.c95a035eb4176p-54"), ("0x1.022cdece68c4fp+0", "-0x1.491793e46834cp-54"), ("0x1.02380e4dd22adp+0", " -0x1.3e8d0d9c4909p-56"), ("0x1.02433e494b755p+0", "-0x1.314aa16278aa4p-54"), ("0x1.024e6ec0da046p+0", "  0x1.48daf888e965p-55"), ("0x1.02599fb483385p+0", " 0x1.56dc8046821f4p-55"), ("0x1.0264d1244c719p+0", " 0x1.45b42356b9d46p-54"), ("0x1.027003103b10ep+0", " -0x1.082ef51b61d8p-56"), ("0x1.027b357854772p+0", "  0x1.2106ed0920a3p-56"), ("0x1.0286685c9e059p+0", "-0x1.fd4cf26ea5d0ep-54"), ("0x1.02919bbd1d1d8p+0", "-0x1.09f8775e78084p-54"), ("0x1.029ccf99d720ap+0", "  0x1.64cbba902ca2p-58"), ("0x1.02a803f2d170dp+0", " 0x1.4383ef231d206p-54"), ("0x1.02b338c811703p+0", " 0x1.4a47a505b3a46p-54"), ("0x1.02be6e199c811p+0", "  0x1.e47120223468p-54")]

# checkT1()
# 25 1.2113322377334339885454122012995059581008511601280607487279e-32
def checkT1():
   maxerr = 0
   for i in range(64):
      h = RR(T1[i][0],16)
      l = RR(T1[i][1],16)
      H = h.exact_rational()
      L = l.exact_rational()
      # H+L should approximate 2^(i/64)
      err = abs(n(H+L-2^(i/64),200))
      if err > maxerr:
         maxerr = err
         print (i, err)

# checkT2()
# 62 1.2123388082524464936806590177610935509182076978346394103810e-32
def checkT2():
   maxerr = 0
   for i in range(64):
      h = RR(T2[i][0],16)
      l = RR(T2[i][1],16)
      H = h.exact_rational()
      L = l.exact_rational()
      # H+L should approximate 2^(i/2^12)
      err = abs(n(H+L-2^(i/2^12),200))
      if err > maxerr:
         maxerr = err
         print (i, err)

# maximum absolute error:
# 6.0530136768206226803797573412094978479948229368693466294990e-33
# since 1 <= h < 2, ulp(h) = 2^-52 thus |l| <= 1/2 ulp(h) = 2^-53
# and the error is bounded by 1/2 ulp(l) < 2^-107 ~ 6.163e-33
def generateT1():
   maxerr = 0
   maxl = 0
   print ("static const double T1[][2] = {")
   for i in range(64):
      s = "    {"
      h = RR(n(2^(i/64),200))
      t = get_hex(h)
      while len(t)<20:
         t = " "+t
      s += t + ", "
      l = RR(n(2^(i/64)-h.exact_rational(),200))
      maxl = max(maxl,abs(l))
      err = n(2^(i/64)-h.exact_rational()-l.exact_rational(),200)
      maxerr = max(maxerr,abs(err))
      if l >= 0:
         s += " "
      t = get_hex(l)
      while len(t)<21:
         t = " "+t
      s += t + "},"
      print (s)
   print ("};")
   return maxerr, get_hex(maxl)

# maximum absolute error:
# 6.0764756068910472676545783585552065755001483155154289227995e-33
# since 1 <= h < 2, ulp(h) = 2^-52 thus |l| <= 1/2 ulp(h) = 2^-53
# and the error is bounded by 1/2 ulp(l) < 2^-107 ~ 6.163e-33
def generateT2():
   maxerr = 0
   print ("static const double T2[][2] = {")
   for i in range(64):
      s = "    {"
      h = RR(n(2^(i/2^12),200))
      t = get_hex(h)
      while len(t)<20:
         t = " "+t
      s += t + ", "
      l = RR(n(2^(i/2^12)-h.exact_rational(),200))
      err = n(2^(i/2^12)-h.exact_rational()-l.exact_rational(),200)
      maxerr = max(maxerr,abs(err))
      if l >= 0:
         s += " "
      t = get_hex(l)
      while len(t)<21:
         t = " "+t
      s += t + "},"
      print (s)
   print ("};")
   print (maxerr)

# ensures x*inv-1 is an exact multiple of denom(inv)
def znorm(x,inv):
   z = x.exact_rational()*inv.exact_rational()-1
   w = 1/inv.exact_rational().denom()
   u = (x.ulp()*w).exact_rational()
   assert z/u in ZZ
   return ZZ(z/u)

# we should have 0 < z := r*y - 1 < 2^-6
# l=inverse(7)
# minz 128 0.000000000000000
# maxz 91 0.0135498046874998
# 91 xmax 31243722414882455 55
# l=inverse(8)
# 181 xmax 18647717207080597 55
# l=inverse(9)
# 508 xmax 13352469207711485 54
def inverse(k=7,verbose=false):
   R = RealField(9,rnd='RNDU')
   l = []
   minz = infinity
   maxz = 0
   x0 = RR("0x1.6a09e667f3bcdp-1",16)
   x1 = 2*x0
   imin = ZZ(floor(x0*2^k)) 
   imax = ZZ(floor(x1*2^k))
   maxznorm = 0
   for i in range(imin,imax+1):
      xmin = RR(i*2^-k)
      if xmin < x0:
         xmin = x0
      xmax = RR((i+1)*2^-k).nextbelow()
      if xmax >= x1:
         xmax = x1.nextbelow()
      inv = R(1/xmin.exact_rational())
      if verbose:
         print (i, get_hex(inv))
      z = xmin.exact_rational()*inv.exact_rational()-1
      u = abs(znorm(xmin, inv))
      if u>maxznorm:
         print (i, "xmin", u, u.nbits())
         maxznorm=u
      if z < minz:
         minz = z
         print ("minz", i, n(z))
      z = xmax.exact_rational()*inv.exact_rational()-1
      u = abs(znorm(xmax, inv))
      if u>maxznorm:
         print (i, "xmax", u, u.nbits())
         maxznorm=u
      if z > maxz:
         maxz = z
         print ("maxz", i, n(z))
      l.append(inv)
   return l

def output_inverse(l):
   print ("static const double _INVERSE[" + str(len(l)) + "]= {")
   s0 = "    "
   s = s0
   for i in range(len(l)):
      s += get_hex(l[i]) + ","
      if i % 7 == 6:
         print (s)
         s = s0
      else:
         s += " "
   if s != s0:
      print (s)
   print ("};")

def output_log_inv(L):
   print ("static const double _LOG_INV[" + str(len(L)) + "][2] = {")
   for i in range(len(L)):
      h, l = get_hl42 (L[i])
      s = "    {" + get_hex(h) + ", " + get_hex(l) + "},"
      print (s)
   print ("};")

def output_log2_inv(L):
   print ("static const double _LOG2_INV[" + str(len(L)) + "][2] = {")
   for i in range(len(L)):
      h, l = get_hl42_log2 (L[i])
      s = "    {" + get_hex(h) + ", " + get_hex(l) + "},"
      print (s)
   print ("};")

# return the minimal number of bits needed to represent exactly
# r*x-1 (using a fma) when xmin <= x <= xmax
# xmin=RR(199/256)
# xmax=RR(200/256).nextbelow()
# r=RR("0x1.48p+0",16)
# nbits_fma(xmin,xmax,r)
def nbits_fma(xmin,xmax,r):
   _,_,emin = xmin.sign_mantissa_exponent()
   _,_,emax = xmax.sign_mantissa_exponent()
   e = min(emin,emax)
   # x is integer multiple of 2^e
   u = 1/r.exact_rational().denom()
   # r is multiple of u
   t = 2^e*u
   # r*x is multiple of t, and thus r*x-1
   zmin = xmin.exact_rational()*r.exact_rational()-1
   zmax = xmax.exact_rational()*r.exact_rational()-1
   nmin = zmin/t
   nmax = zmax/t
   assert nmin in ZZ, "nmin in ZZ"
   assert nmax in ZZ, "nmax in ZZ"
   n = ZZ(max(abs(nmin),abs(nmax)))
   k = n.nbits()
   if is_power_of_two(n):
      k = k-1
   return k

# l=inverse_centered(k=7,prec=9)
# minz 101 -0.00750732421875000
# maxz 95 0.00781249999999985
# l=inverse_centered(k=8,prec=9)
# maxz 187 0.00402832031249985
# minz 199 -0.00402832031250000
# l=inverse_centered(k=9,prec=10)
# minz 387 -0.00202941894531250
# maxz 369 0.00212097167968735
def inverse_centered(k=7,prec=9,maxbits=53,verbose=false):
   R = RealField(prec,rnd='RNDU')
   l = []
   minz = infinity
   maxz = 0
   x0 = RR("0x1.6a09e667f3bcdp-1",16)
   x1 = 2*x0
   imin = ZZ(floor(x0*2^k))
   imax = ZZ(floor(x1*2^k))
   print ("imin=", imin, "imax=", imax)
   for i in range(imin,imax+1):
      xmin = RR(i*2^-k)
      if xmin < x0:
         xmin = x0
      xmax = RR((i+1)*2^-k).nextbelow()
      if xmax >= x1:
         xmax = x1.nextbelow()
      inv = R(1/xmin.exact_rational())
      u = infinity
      while true:
         a = znorm(xmin,inv)
         b = znorm(xmax,inv)
         v = max(abs(a),abs(b))
         vnbits = v.nbits()
         if is_power_of_two(v):
            vnbits -= 1
         if vnbits != nbits_fma(xmin,xmax,inv):
            print ("i=", i, "inv=", get_hex(inv))
            print ("v.nbits()=", vnbits)
            print ("nbits_fma=", nbits_fma(xmin,xmax,inv))
         assert vnbits == nbits_fma(xmin,xmax,inv), "vnbits == nbits_fma(xmin,xmax,inv)"
         if i in [2^k-1,2^k]:
            if inv==R(1):
               best = inv
               a = xmin.exact_rational()*inv.exact_rational()-1
               b = xmax.exact_rational()*inv.exact_rational()-1
               u = max(abs(a),abs(b))
         elif vnbits <= maxbits:
            a = xmin.exact_rational()*inv.exact_rational()-1
            b = xmax.exact_rational()*inv.exact_rational()-1
            v = max(abs(a),abs(b))
            if v < u:
               u = v
               best = inv
         if b<0:
            break
         inv = inv.nextbelow()
      if u==infinity:
         print ("no solution found for i=", i)
         raise ValueError
      inv = best
      if verbose:
         print (i, get_hex(inv))
      z = xmin.exact_rational()*inv.exact_rational()-1
      if z < minz:
         minz = z
         print ("minz", i, n(z))
      z = xmax.exact_rational()*inv.exact_rational()-1
      if z > maxz:
         maxz = z
         print ("maxz", i, n(z))
      l.append(inv)
   return l

def check_inverse():
   global _INVERSE
   ref = inverse()
   R = RealField(9)
   l = [R(_INVERSE[i],16) for i in range(92)]
   for i in range(92):
      a = ref[i].exact_rational()
      b = l[i].exact_rational()
      if a != b:
         print ("not optimal", i, a, b, b-a)

def get_hl(ri):
   if ri.parent() != QQ:
      ri = ri.exact_rational()
   h = RR(n(-log(ri),200))
   H = h.exact_rational()
   l = RR(n(-log(ri)-H,200))
   return h, l

# ensure h is an integer multiple of 2^-42
def get_hl42(ri):
   if ri.parent() != QQ:
      ri = ri.exact_rational()
   h = n(-log(ri)*2^42,200)
   H = ZZ(round(h))/2^42
   h = RR(H)
   l = RR(n(-log(ri)-H,200))
   return h, l

log2 = lambda x: log(x)/log(2)

# ensure h is an integer multiple of 2^-42
def get_hl42_log2(ri):
   if ri.parent() != QQ:
      ri = ri.exact_rational()
   h = n(-log2(ri)*2^42,200)
   H = ZZ(round(h))/2^42
   h = RR(H)
   l = RR(n(-log2(ri)-H,200))
   return h, l

# l = [RR(x,16) for x in _INVERSE]
# check_log_inv(l)
# i= 78 ulp difference 18.0000000000000
# i= 78 expected l 0x1.e0936abd4fa6ep-62 got 0x1.e0936abd4fa8p-62
def check_log_inv(L):
   global _LOG_INV
   for i in range(len(L)):
      h, l = get_hl(L[i])
      hh = RR(_LOG_INV[i][0],16)
      ll = RR(_LOG_INV[i][1],16)
      if h!=hh:
         print ("i=", i, "expected h", get_hex(h), "got", get_hex(hh))
         break
      if l!=ll:
         u = (ll-l)/l.ulp()
         print ("i=", i, "ulp difference", u)
         print ("i=", i, "expected l", get_hex(l), "got", get_hex(ll))
         # break

INVERSE = ["0x1.69p+0", "0x1.67p+0", "0x1.65p+0", "0x1.63p+0", "0x1.61p+0", "0x1.5fp+0", "0x1.5ep+0", "0x1.5cp+0", "0x1.5ap+0", "0x1.58p+0", "0x1.56p+0", "0x1.54p+0", "0x1.53p+0", "0x1.51p+0", "0x1.4fp+0", "0x1.4ep+0", "0x1.4cp+0", "0x1.4ap+0", "0x1.48p+0", "0x1.47p+0", "0x1.45p+0", "0x1.44p+0", "0x1.42p+0", "0x1.4p+0", "0x1.3fp+0", "0x1.3dp+0", "0x1.3cp+0", "0x1.3ap+0", "0x1.39p+0", "0x1.37p+0", "0x1.36p+0", "0x1.34p+0", "0x1.33p+0", "0x1.32p+0", "0x1.3p+0", "0x1.2fp+0", "0x1.2dp+0", "0x1.2cp+0", "0x1.2bp+0", "0x1.29p+0", "0x1.28p+0", "0x1.27p+0", "0x1.25p+0", "0x1.24p+0", "0x1.23p+0", "0x1.21p+0", "0x1.2p+0", "0x1.1fp+0", "0x1.1ep+0", "0x1.1cp+0", "0x1.1bp+0", "0x1.1ap+0", "0x1.19p+0", "0x1.17p+0", "0x1.16p+0", "0x1.15p+0", "0x1.14p+0", "0x1.13p+0", "0x1.12p+0", "0x1.1p+0", "0x1.0fp+0", "0x1.0ep+0", "0x1.0dp+0", "0x1.0cp+0", "0x1.0bp+0", "0x1.0ap+0", "0x1.09p+0", "0x1.08p+0", "0x1.07p+0", "0x1.06p+0", "0x1.05p+0", "0x1.04p+0", "0x1.03p+0", "0x1.02p+0", "0x1.01p+0", "0x1.ffp-1", "0x1.fdp-1", "0x1.fbp-1", "0x1.f9p-1", "0x1.f7p-1", "0x1.f5p-1", "0x1.f3p-1", "0x1.f1p-1", "0x1.fp-1", "0x1.eep-1", "0x1.ecp-1", "0x1.eap-1", "0x1.e8p-1", "0x1.e6p-1", "0x1.e5p-1", "0x1.e3p-1", "0x1.e1p-1", "0x1.dfp-1", "0x1.ddp-1", "0x1.dcp-1", "0x1.dap-1", "0x1.d8p-1", "0x1.d7p-1", "0x1.d5p-1", "0x1.d3p-1", "0x1.d2p-1", "0x1.dp-1", "0x1.cep-1", "0x1.cdp-1", "0x1.cbp-1", "0x1.c9p-1", "0x1.c8p-1", "0x1.c6p-1", "0x1.c5p-1", "0x1.c3p-1", "0x1.c2p-1", "0x1.cp-1", "0x1.bfp-1", "0x1.bdp-1", "0x1.bcp-1", "0x1.bap-1", "0x1.b9p-1", "0x1.b7p-1", "0x1.b6p-1", "0x1.b4p-1", "0x1.b3p-1", "0x1.b1p-1", "0x1.bp-1", "0x1.aep-1", "0x1.adp-1", "0x1.acp-1", "0x1.aap-1", "0x1.a9p-1", "0x1.a7p-1", "0x1.a6p-1", "0x1.a5p-1", "0x1.a3p-1", "0x1.a2p-1", "0x1.a1p-1", "0x1.9fp-1", "0x1.9ep-1", "0x1.9dp-1", "0x1.9cp-1", "0x1.9ap-1", "0x1.99p-1", "0x1.98p-1", "0x1.96p-1", "0x1.95p-1", "0x1.94p-1", "0x1.93p-1", "0x1.91p-1", "0x1.9p-1", "0x1.8fp-1", "0x1.8ep-1", "0x1.8dp-1", "0x1.8bp-1", "0x1.8ap-1", "0x1.89p-1", "0x1.88p-1", "0x1.87p-1", "0x1.86p-1", "0x1.84p-1", "0x1.83p-1", "0x1.82p-1", "0x1.81p-1", "0x1.8p-1", "0x1.7fp-1", "0x1.7ep-1", "0x1.7cp-1", "0x1.7bp-1", "0x1.7ap-1", "0x1.79p-1", "0x1.78p-1", "0x1.77p-1", "0x1.76p-1", "0x1.75p-1", "0x1.74p-1", "0x1.73p-1", "0x1.72p-1", "0x1.71p-1", "0x1.7p-1", "0x1.6fp-1", "0x1.6ep-1", "0x1.6dp-1", "0x1.6cp-1", "0x1.6bp-1", "0x1.6ap-1"]

# find smallest |z|
# 187 0x1.767dce434a9b1p-1 -0x1p-60
def find_smallest_z():
   zmin = infinity
   for i in [181..362]:
      r = RR(INVERSE[i-181],16)
      # z = r*t-1
      t = RR(1/r)
      while r.exact_rational()*t.exact_rational()>=1:
         t = t.nextbelow()
      z = fma(r,t,RR(-1))
      if z!=0 and abs(z)<zmin:
         zmin = abs(z)
         print (i, get_hex(t), get_hex(z))
      t = t.nextabove()
      z = fma(r,t,RR(-1))
      if z==0:
         t = t.nextabove()
         z = fma(r,t,RR(-1))
      assert z>0, "z>0"
      if z!=0 and abs(z)<zmin:
         zmin = abs(z)
         print (i, get_hex(t), get_hex(z))

# x="0x1.00d4p+0";lh="0x1.a7507p-9";ll="0x1.82c3280cf322cp-27"
# y="0x1.fffffffffffffp+16";rh="0x1.a7506ffffffffp+8";rl="0x1.82c3280cfe38ap-10"
# res_h="0x1.a458f382c0752p+0";res_l="-0x1.1c03b95011725p-45";ex="0x1p+610"
# check(x,y,lh,ll,rh,rl,res_h,res_l,ex)
def check(x,y,lh,ll,rh,rl,res_h,res_l,ex):
   x = RR(x,16)
   X=x.exact_rational()
   lh=RR(lh,16)
   Lh=lh.exact_rational()
   ll=RR(ll,16)
   Ll=ll.exact_rational()
   err_log_1=n(log(X)-Lh-Ll,200)
   print ("err_log_1=", err_log_1, log(abs(err_log_1))/log(2.))
   assert abs(err_log_1) < 2^-72.13, "abs(err_log_1) < 2^-72.13"
   # (rh,rl) = y*(lh,ll)
   y=RR(y,16)
   Y=y.exact_rational()
   Rh=RR(rh,16).exact_rational()
   Rl=RR(rl,16).exact_rational()
   err_rhl=n(Y*log(X)-Rh-Rl,200)
   print ("err_rhl=", err_rhl, log(abs(err_rhl))/log(2.))

# rh="0x1.a7506ffffffffp+8";rl="0x1.82c3280cfe38ap-10"
# res_h="0x1.a458f382c0752p+0";res_l="-0x1.1c03b95011725p-45";ex="0x1p+610"
# k="0x1.315b9p+21";kh="0x1.a750cbd9e7165p+8";kl="0x1.5d5004d73c845p-46"
# yh="0x1.35b8bb37e38ap-14";yl="-0x1.5d5004d73c845p-46"
# qh="0x1.0004d6eea2ae3p+0";ql="-0x1.5a52218b5351cp-46"
# check_exp_1(rh,rl,res_h,res_l,ex,k,kh,kl,yh,yl,qh,ql)
def check_exp_1(xh,xl,res_h,rel_l,ex,k,kh,kl,yh,yl,qh,ql):
   xh=RR(xh,16)
   Xh=xh.exact_rational()
   xl=RR(xl,16)
   Xl=xl.exact_rational()
   print ("xl/xh=", xl/xh, log(abs(xl/xh))/log(2.))
   assert abs(xl/xh)<2^-4.119,"abs(xl/xh)<2^-4.119"
   Res_h=RR(res_h,16).exact_rational()
   Res_l=RR(res_l,16).exact_rational()
   Ex=RR(ex,16).exact_rational()
   a=exp(Xh+Xl)
   b=Ex*(Res_h+Res_l)
   err_exp_1=n((b-a)/a,200)
   print ("rel err exp_1:", err_exp_1, log(abs(err_exp_1))/log(2.))
   K=RR(k,16).exact_rational()
   # check |k - (xh+xl)*2^12/log(2)| <= 1/2 + 2^-30.3
   err_k = n(K-(Xh+Xl)*2^12/log(2),200)
   print("err_k=", err_k)
   assert abs(err_k)<1/2+2^-30.3,"abs(err_k)<1/2+2^-30.3"
   # check |kh + kl - (xh+xl)| < 2^-13.5
   Kh=RR(kh,16).exact_rational()
   Kl=RR(kl,16).exact_rational()
   err2_k = n(Kh+Kl-(Xh+Xl),200)
   print("err2_k=", err2_k, log(abs(err2_k))/log(2.))
   assert abs(err2_k) < 2^-13.5, "abs(err2_k) < 2^-13.5"
   Yh=RR(yh,16).exact_rational()
   Yl=RR(yl,16).exact_rational()
   err_y = n(Yh+Yl-(Xh+Xl-(Kh+Kl)),200)
   print ("err_y", err_y, log(abs(err_y))/log(2.))
   _yh = n(Yh,200)
   print ("yh=", _yh, log(abs(_yh))/log(2.))
   assert abs(_yh) < 2^-13.5, "abs(yh) < 2^-13.5"
   check_q_1(yh,yl,qh,ql)

def fast_two_sum(a,b):
   hi = a + b
   e = hi - a
   lo = b-e
   return hi,lo

def a_mul(a,b):
   hi = a * b
   lo = fma (a, b, -hi)
   return hi,lo

def d_mul(ah,al,bh,bl):
   hi, s = a_mul (ah, bh)
   t = fma (al, bh, s)
   lo = fma (ah, bl, t)
   return hi,lo

def fast_sum(a,bh,bl):
   hi, lo = fast_two_sum (a, bh)
   lo += bl
   return hi,lo

# zh='0x1.35b8bb37e38ap-14'; zl='-0x1.5d5004d73c845p-46'
# hi='0x1.0004d6eea2ae3p+0'; lo='-0x1.5a4ed44554a2ap-46'
# check_q_1(zh,zl,hi,lo,rnd='RNDZ')
def check_q_1(zh,zl,hi,lo,rnd='RNDN'):
   Yh=RR(zh,16).exact_rational()
   Yl=RR(zl,16).exact_rational()
   Z=Yh+Yl
   assert n(Z)<2^-13.52, "n(Z)<2^-13.52"
   Qh=RR(hi,16).exact_rational()
   Ql=RR(lo,16).exact_rational()
   err_q = n(Qh+Ql-exp(Z),200)
   print ("err_q=", err_q, log(abs(err_q))/log(2.))
   # mimic the C code
   R=RealField(53,rnd=rnd)
   q4 = R("0x1.5555555693f4p-5",16)
   q3 = R("0x1.555555572084bp-3",16)
   q2 = R("0x1p-1",16)
   q1 = R("0x1p0",16)
   q0 = R("0x1p0",16)
   Q4 = q4.exact_rational()
   Q3 = q3.exact_rational()
   Q2 = q2.exact_rational()
   Q1 = q1.exact_rational()
   Q0 = q0.exact_rational()
   exact_q = Q0+Z*(Q1+Z*(Q2+Z*(Q3+Z*Q4)))
   err_exact_q = n(exact_q-exp(Z),200)
   print ("err_exact_q=", err_exact_q, log(abs(err_exact_q))/log(2.))
   zh = R(zh,16)
   zl = R(zl,16)
   Q = q4.exact_rational()*zh.exact_rational()+q3.exact_rational()
   q = fma(q4,zh,q3)
   err1 = n(q.exact_rational()-Q,200)*zh^3
   print ("err1=", err1, log(abs(err1))/log(2.))
   Q = q.exact_rational()*zh.exact_rational()+q2.exact_rational()
   q = fma (q,zh,q2)
   err2 = n(q.exact_rational()-Q,200)*zh^2
   print ("err2=", err2, log(abs(err2))/log(2.))
   HL = q1.exact_rational()+q.exact_rational()*zh.exact_rational()
   hi,lo = fast_two_sum (q1, q*zh)
   err3 = n(hi.exact_rational()+lo.exact_rational()-HL,200)*(zh+zl)
   print ("err3=", err3, log(abs(err3))/log(2.))
   HL = (zh.exact_rational()+zl.exact_rational())*(hi.exact_rational()+lo.exact_rational())
   hi,lo = d_mul (zh, zl, hi, lo)
   err4 = n(hi.exact_rational()+lo.exact_rational()-HL,200)
   print ("err4=", err4, log(abs(err4))/log(2.))
   HL = q0.exact_rational()+hi.exact_rational()+lo.exact_rational()
   hi, lo = fast_sum(q0,hi,lo)   
   err5 = n(hi.exact_rational()+lo.exact_rational()-HL,200)
   print ("err5=", err5, log(abs(err5))/log(2.))
   assert hi.exact_rational()==Qh, "hi.exact_rational()==Qh"
   assert lo.exact_rational()==Ql, "lo.exact_rational()==Ql"

# try to find inputs that trigger double-rounding in the subnormal range
def check_double_rounding(K=100):
   for k in range(K):
      x = RR.random_element(0,1)
      X = x.exact_rational()
      # we want x^y near some (m+1/2)*2^-1074 for 1 <= m < 2^52
      m = ZZ.random_element(1,2^52)*2^-1074
      y = RR(n(log(m)/log(X),200))
      print (get_hex(x) + "," + get_hex(y))

def dist(x,y):
   R54 = RealField(54)
   z = R54(x)^R54(y)
   Z = z.exact_rational()
   X = x.exact_rational()
   Y = y.exact_rational()
   return abs(n(X^Y-Z,200))/z

def is_in_S(x,y):
   s,n,F = y.sign_mantissa_exponent()
   if s!=1:
      return 0
   while n % 2 == 0:
      n = n//2
      F += 1
   if F >= 0:
      return 2 <= y <= 35
   else:
      # return x.is_integer() and is_odd(ZZ(x)) and -5 <= F < 0 and 3 <= n <= 35
      return -5 <= F < 0 and 3 <= n <= 35

# https://www.vinc17.net/research/testlibm/hrcases/hrcases-powint.xz
# p: x^n
# r: x^(1/n)
# q: x^(-n)
# s: x^(-1/n)
# l1=read_hrcases_powint("hrcases-powint")
# l2=read_hrcases_powint("myreadres.out")
def read_hrcases_powint(f,reduce=false):
   f = open(f,"r")
   l = []
   while true:
      s = f.readline()
      if s=='':
         break
      s = s.split()
      c = s[1][0]
      n = ZZ(s[1][1:])
      if c=='p':
         y=RR(n)
      elif c=='q':
         y=RR(-n)
      elif c=='r' and is_power_of_two(n):
         y=RR(1/n)
      elif c=='s' and is_power_of_two(n):
         y=RR(-1/n)
      else:
         y = None
      if y != None:
         x = RR(s[2],2)
         if reduce: # also add (x/2,y)
            l.append((x/2,y))
         l.append((x,y))
   f.close()
   return l

# generate exact cases with y < 0
def check_exact(file=None):
   nsols = 0
   if file!=None:
      file = open(file,"w")
   for k in [1..10]:
      tmin = ceil(-1074/2^k)
      tmax = floor(1023/2^k)
      for t in [tmin..tmax]:
         if t==0:
            continue # case x = 1
         e = t*2^k
         x = RR(2^e)
         y0 = RR(-2^-k)
         # x^y0 = 2^(-e*2^-k) = 2^(-t)
         # if y=n*y0, x^y = 2^(-n*t)
         if t<0:
            nmin = ceil(-1074/-t)
            nmax = floor(1023/-t)
         else:
            nmin = ceil(1023/-t)
            nmax = floor(-1074/-t)
         # we want y < 0
         nmin = max(1,nmin)
         for n in [nmin..nmax]:
            y = n*y0
            if file==None:
               print (get_hex(x), get_hex(y))
            else:
               file.write(get_hex(x) + "," + get_hex(y) + "\n")
            nsols += 1
   if file!=None:
      file.close()
   return nsols

def print_xy(out,x,y):
   if abs(x) >= RR(2^1024) or abs(x) < RR(2^-1074):
      return
   s = get_hex(x) + "," + get_hex(y)
   if out==None:
      print (s)
   else:
      out.write(s + "\n")

# check exact values for x=2^n and y=m/2^k with m odd, k >= 6
def check_pow2(out=None):
   if out != None:
      out = open(out,"w")
   # if x = 2^n, then x^y = 2^(n*m/2^k) thus n should be multiple of 2^k
   for k in range(6,1075):
      # positive n
      for n in range(2^k,1075,2^k):
         assert n%(2^k)==0, "n%(2^k)==0"
         e = n//(2^k)
         # x^y = 2^(e*m)
         for m in range(1,floor(1074/e)+1,2):
            x = RR(2^n)
            y = RR(m/2^k)
            print_xy(out,x,y)
            print_xy(out,1/x,-y)
      # negative n
      for n in range(-2^k,-1075,-2^k):
         assert n%(2^k)==0, "n%(2^k)==0"
         e = n//(2^k)
         # x^y = 2^(e*m)
         for m in range(1,floor(1074/abs(e))+1,2):
            x = RR(2^n)
            y = RR(m/2^k)
            print_xy(out,x,y)
            print_xy(out,1/x,-y)
   if out != None:
      out.close()

# search K inputs x,y such that x^y rounds to 2^-1022 for RNDU
# but there is underflow
def corner_rndu(K,f):
   f = open(f,"w")
   Ru = RealField(53,rnd='RNDU')
   Rd = RealField(53,rnd='RNDD')
   threshold1 = 2^-1022-2^-1074 # nextbelow(2^-1022) in binary64
   threshold2 = 2^-1022-2^-1075 # nextbelow(2^-1022) with unbounded exponent
   # for threshold1 < x^y <= threshold2, x^y rounds upwards to threshold2
   # with unbounded exponent range, but to 2^-1022 in binary64
   while K>0:
      x = Ru.random_element(0,1)
      X = x.exact_rational()
      # we want x^y below threshold2
      y = Ru(n(log(threshold2)/log(X),200))
      Y = y.exact_rational()
      z = n(X^Y,200)
      assert z<=threshold2, "z<=threshold2"
      y1 = y.nextbelow()
      Y1 = y1.exact_rational()
      z1 = n(X^Y1,200)
      assert z1>threshold2, "z1>threshold2"
      if threshold1 < z:
         f.write (get_hex(x)+","+get_hex(y)+"\n")
         f.write (get_hex(x)+","+get_hex(y1)+"\n")
         K -= 1
   f.close()

# search K inputs x,y such that x^y rounds to 2^-1022 for RNDN
# but there is underflow
def corner_rndn(K,f):
   f = open(f,"w")
   Ru = RealField(53,rnd='RNDU')
   Rd = RealField(53,rnd='RNDD')
   threshold1 = 2^-1022-2^-1075-2^-1076
   threshold2 = 2^-1022-2^-1075+2^-1076
   # for threshold1 < x^y < threshold2, x^y rounds to nearest to 2^-1022-2^-1075
   # with unbounded exponent range, but to 2^-1022 in binary64
   while K>0:
      x = Ru.random_element(0,1)
      X = x.exact_rational()
      # we want x^y below threshold2
      y = Ru(n(log(threshold2)/log(X),200))
      Y = y.exact_rational()
      z = n(X^Y,200)
      assert z<=threshold2, "z<=threshold2"
      y1 = y.nextbelow()
      Y1 = y1.exact_rational()
      z1 = n(X^Y1,200)
      assert z1>threshold2, "z1>threshold2"
      if threshold1 < z:
         f.write (get_hex(x)+","+get_hex(y)+"\n")
         f.write (get_hex(x)+","+get_hex(y1)+"\n")
         K -= 1
         print ("remains ", K)
   f.close()
