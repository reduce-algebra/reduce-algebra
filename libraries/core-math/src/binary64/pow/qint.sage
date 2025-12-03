#load("../../generic/support/common.sage")
# internal routine
def get_qint(hh,hl,lh,ll,ex):
   return 2^ex*(hh/2^63+hl/2^127+lh/2^191+ll/2^255)

# return max(|r*t-1| for tmin <= t <= tmax
# used only internally to this file
def znorm(tmin,tmax,r):
   lo = r.exact_rational()*tmin.exact_rational()
   hi = r.exact_rational()*tmax.exact_rational()
   return max(abs(lo-1),abs(hi-1))

# find the best p-bit approximation r of 1/t over [tmin,tmax]
# that minimizes max(1-r*tmin,r*tmax-1)
# find_best_r(1.125,1.140625,6,53)
# used only internally to this file
def find_best_r(tmin,tmax,p,prec):
   if tmin==1 or tmax==1:
      r = RealField(p)(1)
      z = znorm(tmin,tmax,r)
   else:
      r = RealField(p)(2/(tmin+tmax))
      z = znorm(tmin,tmax,r)
      while znorm(tmin,tmax,r.nextbelow()) < z:
         r = r.nextbelow()
         z = znorm(tmin,tmax,r)
      while znorm(tmin,tmax,r.nextabove()) < z:
         r = r.nextabove()
         z = znorm(tmin,tmax,r)
   lo = r.exact_rational()*tmin.exact_rational()
   hi = r.exact_rational()*tmax.exact_rational()
   # evaluate the number of bits needed to get r*x-1 exactly
   # assuming x has at most prec significant bits
   R = RealField(prec)
   tmin = R(tmin)
   umin = R(lo).exact_rational()/(tmin.ulp()*r.ulp())
   tmax = R(tmax)
   umax = R(hi).exact_rational()/(tmax.ulp()*r.ulp())
   u = ZZ(max(abs(umin),abs(umax)))
   return r, lo, hi, u.nbits()

# output_inverse_3_1(7,9,90,181)
def output_inverse_3_1(k1,p1,imin,imax):
   Minz = infinity
   Maxz = 0
   print ("static const qint64_t _INVERSE_3_1[] = {")
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      s,m,e = r.sign_mantissa_exponent()
      assert m==0 or m.nbits()==p1, "m==0 or m.nbits()==p1"
      m = m*2^(128-p1)
      e -= 128-p1
      h,l = divmod(m,2^64)
      assert l==0, "l==0"
      print ("    {.hh = " + hex(h) + ", .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = " + str(e+127) + ", .sgn = 0x0}, /* i=" + str(i) + " */")
   print ("};")

# output_inverse_3_2(6,14,8128,8256,7,62)
def output_inverse_3_2(k2,p2,jmin,jmax,k1,NB):
   Minz = infinity
   Maxz = 0
   print ("static const qint64_t _INVERSE_3_2[] = {")
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      s,m,e = r.sign_mantissa_exponent()
      assert m==0 or m.nbits()==p2, "m==0 or m.nbits()==p2"
      m = m*2^(128-p2)
      e -= 128-p2
      h,l = divmod(m,2^64)
      assert l==0, "l==0"
      print ("    {.hh = " + hex(h) + ", .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = " + str(e+127) + ", .sgn = 0x0}, /* j=" + str(j) + " */")
   print ("};")

# output_log_inv_3_1(7,9,90,181)
def output_log_inv_3_1(k1,p1,imin,imax):
   print ("static const qint64_t _LOG_INV_3_1[] = {")
   R256 = RealField(256)
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      x = R256(n(log(r.exact_rational()),300))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
      l = (2^256+m).digits(2^64)
      # we store -log(x) thus we change signs
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1}, /* i=" + str(i) + " */")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0}, /* i=" + str(i) + " */")
   print ("};")

# l1=get_log_inv_3_1(7,9,90,181)
# this routine is only used internally to this file
def get_log_inv_3_1(k1,p1,imin,imax):
   L = []
   R256 = RealField(256)
   for i in [imin..imax]:
      tmin = RR(i/2^k1)
      tmax = RR((i+1)/2^k1)
      r, _, _, _ = find_best_r(tmin,tmax,p1,53)
      x = R256(n(log(r.exact_rational()),300))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
      # we store -log(x) thus we change signs
      L.append(-s*m*2^e)
   return L

# output_log_inv_3_2(6,14,8128,8256,7,62)
def output_log_inv_3_2(k2,p2,jmin,jmax,k1,NB):
   print ("static const qint64_t _LOG_INV_3_2[] = {")
   R256 = RealField(256)
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      x = R256(n(log(r.exact_rational()),300))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
      l = (2^256+m).digits(2^64)
      # we store -log(x) thus we change signs
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1}, /* j=" + str(j) + " */")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = "+ hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0}, /* j=" + str(j) + " */")
   print ("};")

# l2=get_log_inv_3_2(6,14,8128,8256,7,62)
def get_log_inv_3_2(k2,p2,jmin,jmax,k1,NB):
   L = []
   R256 = RealField(256)
   for j in [jmin..jmax]:
      tmin = RR(j/2^(k1+k2))
      tmax = RR((j+1)/2^(k1+k2))
      r, _, _, _ = find_best_r(tmin,tmax,p2,NB)
      x = R256(n(log(r.exact_rational()),300))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
      # we store -log(x) thus we change signs
      L.append(-s*m*2^e)
   return L

def output_log_inv_3():
   print ("static const qint64_t _LOG_INV_3[] = {")
   R128 = RealField(256)
   for i in [90..181]:
      if i in [127,128]: # force r=1
         m = 2^63
         e = 0
      elif i < 127:
         m = round(2^7/(i+1/2)*2^63)
         e = 0
      else:
         m = round(2^7/(i+1/2)*2^64)
         e = -1
      x = R128(n(log(m*2^e/2^63),300))
      s,m,e = x.sign_mantissa_exponent()
      assert m==0 or m.nbits()==256, "m==0 or m.nbits()==256"
      l = (2^256+m).digits(2^64)
      # we store -log(x) thus we change signs
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1}, /* i=" + str(i) + " */")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0}, /* i=" + str(i) + " */")

def output_P3():
   R256 = RealField(256)
   R.<x> = R256[]
   # output of sollya approximations_r3.sollya
   p =  R("-5.555555906272284098743898493599768784179104841314256191253662109375e-2 * x^18 + 5.8823532917917394263975148700907350330053732836922043394191065508141313863456285491535121233430682963216895586811006069183349609375e-2 * x^17 + -6.249999999999989654256813521459686262324526806355281709022135762728717823659759584954491960784306314735658816061913967132568359375e-2 * x^16 + 6.66666666666665695223341708760305478361148209667839057469086008292511005955219431897882352566764296852852567099034786224365234375e-2 * x^15 + -7.14285714285714285714302380193983005878261653154572749218955197807766281047523143458988226228711937437765300273895263671875e-2 * x^14 + 7.692307692307692307692452448448882138096346263749879949522793909757101543332621656722772503222973483616442536003887653350830078125e-2 * x^13 + -8.33333333333333333333333333333174066541686955692495556619959453258362546096523175369438947435174469546836917288601398468017578125e-2 * x^12 + 9.0909090909090909090909090909078390608651921811728802759441375572746403650799874409976948641531890871192445047199726104736328125e-2 * x^11 + -0.100000000000000000000000000000000000000091789351433644462353893751323059937934828057976105457963529578497441513491351425113002855545608402924376765180161085 * x^10 + 0.1111111111111111111111111111111111111111742475480409697174219002953444485425885671942645683861814041395094876945504330252173901128448175293036303680425916 * x^9 + -0.12499999999999999999999999999999999999999999999969010875389749094308170427232811946917050690678336148672754853717306890449939545843253357891257566869232473 * x^8 + 0.1428571428571428571428571428571428571428571428569664565901281511297879812187821127440995763379820972441968914183074760248510185423157948059855851124131637 * x^7 + -0.16666666666666666666666666666666666666666666666666666666723141225321042295380616240450081798638042444318808566738101491956735827512630509212539536222375087 * x^6 + 0.20000000000000000000000000000000000000000000000000000000023895987519549719028096345990632310755382303156767548350461538961248758041186689566200585722488422 * x^5 + -0.24999999999999999999999999999999999999999999999999999999999999999953416322330578742329668263936422057130104775725565713230670081021064197113334346834483604 * x^4 + 0.33333333333333333333333333333333333333333333333333333333333333333322206008568576399421218354853896095758818720748512353589116516195989931512958364799944215 * x^3 + -0.50000000000000000000000000000000000000000000000000000000000000000000000000011227019121622778013002257421640519442450800473767165800530814511219169344111155 * x^2 + x")
   assert p[0]==0, "p[0]==0"
   n = p.degree()
   print ("static const qint64_t P_3[] = {")
   for i in range(n,0,-1):
      c = p[i]
      assert c.parent()==R256, "c.parent()==R256"
      s,m,e = c.sign_mantissa_exponent()
      while m.nbits()<256:
         m = 2*m
         e = e-1
      assert m.nbits()==256, "m.nbits()==256"
      l = m.digits(2^64)
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0}, /* degree " + str(i) + " */")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1}, /* degree " + str(i) + " */")
   print ("};")

def output_q3():
   R.<x> = RealField(256)[]
   # output of sollya approximations_r3.sollya, with 0.5 changed to 1/2
   # (see https://trac.sagemath.org/ticket/34832)
   p = 1 + 1.14707456033884501464502240155935718422778812571917461671233695597038604319095611572265625e-11 * x^14 + 1.60590438450343225348045440836287896901096098993544369903929691645316779613494873046875e-10 * x^13 + 2.087675698786809897648673000068314296853400092296262404443557108851932163332045914727628376367493628801047696186277136121134390123188495635986328125e-9 * x^12 + 2.5052108385441718771524077635450824304401207266418658242911475423608435081454157580403128651692743164331074467998661248202552087604999542236328125e-8 * x^11 + 2.7557319223985890652557319224667837567702097336236101534158424005645325480807460974553033382967681089344147427055986554478295147418975830078125e-7 * x^10 + 2.7557319223985890652557319224757712880792848254514957135753712524323073434890839822071274361654238081731360665571628487668931484222412109375e-6 * x^9 + 2.480158730158730158730158730158730158720734886771981928625254511907170291007923470166123139647967703325104338318851660005748271942138671875e-5 * x^8 + 1.9841269841269841269841269841269841269750844149206115685392078534661193783774721146156832696573641572683814116288829840987113126581045958707404958456830274e-4 * x^7 + 1.3888888888888888888888888888888888888888888888895882003999389131877528671533610177057207989095285218343414504514755765619543262906018199006320126690956409e-3 * x^6 + 8.333333333333333333333333333333333333333333333338771667251264985244762928614836125785024922779447921609045764015330218620182343148075591774672846140076723e-3 * x^5 + 4.166666666666666666666666666666666666666666666666666666666419936332430712503002221666045187038591592959946781819015356963198802363205767803881047313652543e-2 * x^4 + 0.1666666666666666666666666666666666666666666666666666666666522456178451425891554214844796386835892041978942776205951415747656078406991593343027886021728467 * x^3 + 0.5000000000000000000000000000000000000000000000000000000000000000000029379365226132165389768149660265102724212345097055085926051877589655869731481998536653 * x^2 + 1.0000000000000000000000000000000000000000000000000000000000000000000110625379888835114871227743631934420731735595816022530576762676740758778297045596103137 * x
   n = p.degree()
   print ("static const qint64_t Q_3[] = {")
   for i in range(n,-1,-1):
      c = p[i]
      s,m,e = c.sign_mantissa_exponent()
      while m.nbits()<256:
         m = 2*m
         e = e-1
      assert m.nbits()==256, "m.nbits()==256"
      l = m.digits(2^64)
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0}, /* degree " + str(i) + " */")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1}, /* degree " + str(i) + " */")
   print ("};")

def analyze_p3(neg=false):
   R64 = RealField(64)
   R128 = RealField(128)
   R192 = RealField(192)
   R256 = RealField(256)
   z = R64(2^-13)
   if neg:
      z = -z
   P_3 = [0xe38e39d490f62b2f/2^5,(0xf0f0f1e1e1d4e1cf+1)/2^5,(0xffffffffffff88b8+1)/2^5,(0x8888888888885088+1)/2^4,(0x9249249249249249+1)/2^4,(0x9d89d89d89d89d89+1)/2^4,(0xaaaaaaaaaaaaaaaa+1)/2^4,(0xba2e8ba2e8ba2e8b+1)/2^4,(0xcccccccccccccccc+1)/2^4,(0xe38e38e38e38e38e+1)/2^4,(0xffffffffffffffff+1)/2^4,(0x9249249249249249+1)/2^3,(0xaaaaaaaaaaaaaaaa+1)/2^3,(0xcccccccccccccccc+1)/2^3,(0xffffffffffffffff+1)/2^3,(0xaaaaaaaaaaaaaaaa+1)/2^2,(0x8000000000000000+1)/2^1,0x8000000000000000]
   assert len(P_3)==18, "len(P_3)==18"
   P_3 = [x/2^63 for x in P_3]
   # mul_qint_11 (r, &P_3[0], z)
   r0 = P_3[0]*z
   # add_qint_22 (r, &P_3[1], r)
   r = P_3[1] + R128(r0)
   assert r.prec()==128, "r.prec()==128"
   erra = 2*r.ulp()
   err = dict()
   err[1] = erra*abs(z)^16
   print ("err1=", log(err[1])/log(2.))
   for k in range(2,4):
      # mul_qint_11 (r, r, z)
      r0 = r*z
      erra = R64(r).ulp()*abs(z) # ignored part low(r)*z
      # add_qint_22 (r, &P_3[k], r)
      r = P_3[k] + R128(r0)
      assert r.prec()==128, "r.prec()==128"
      errb = 2*r.ulp()
      err[k] = (erra + errb)*abs(z)^(17-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   r = R128(r)
   z = R128(z)
   for k in range(4,8):
      # mul_qint_21 (r, r, z);
      r0 = r*z
      erra = r0.ulp() # ignored part of r in add_qint_22() below
      # add_qint_22 (r, &P_3[k], r)
      r = P_3[k] + r0
      assert r.prec()==128, "r.prec()==128"
      errb = 2*r.ulp()
      err[k] = (erra + errb)*abs(z)^(17-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   z = R256(z)
   r = R256(r)
   for k in range(8,14):
      # mul_qint_31 (r, r, z);
      r0 = r*z
      if k==8:
         erra = 0
      else:
         erra = R192(r).ulp()*abs(z) # ignored low part of r
      # add_qint (r, &P_3[k], r)
      r = P_3[k] + r0
      errb = 2*r.ulp()
      err[k] = (erra + errb)*abs(z)^(17-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   for k in range(14,18):
      # mul_qint_41 (r, r, z);
      r0 = r*z
      erra = 2*r0.ulp() # error in mul_qint_41()
      # add_qint (r, &P_3[k], r)
      r = P_3[k] + r0
      errb = 2*r.ulp()
      err[k] = (erra + errb)*abs(z)^(17-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   abs_err = add(err[i] for i in [1..17])
   print ("before final multiplication:")
   print ("r=", r)
   print ("abs_err=", log(abs_err)/log(2.))
   assert r > 1 - 2^-13.99, "r > 1 - 2^-13.99"
   rel_err = abs_err/(1 - 2^-13.99)
   print ("rel_err=", log(rel_err)/log(2.))
   print ("after final multiplication:")
   # mul_qint_41 (r, r, z)
   r0 = z*r
   print ("r=", r0)
   abs_err_sollya = 2^-268.1653
   abs_err = 2*r0.ulp()+abs(z)*abs_err+abs_err_sollya
   print ("abs_err=", log(abs_err)/log(2.))
   R300 = RealField(300)
   eps0 = R300(2^-255.0786) # relative error on the Sollya polynomial
   eps1 = R300(rel_err)
   eps2 = R300(2*2^-255)
   rel_err = (1 + eps0) * (1 + eps1) * (1 + eps2) - 1
   print ("rel_err=", log(rel_err)/log(2.))

# sage: analyze_q3()
# err0= -242.181000000000
# err1= -275.216701351610
# err2= -305.344703716495
# err3= -289.815958802105
# err4= -273.287242478882
# err5= -257.758504343014
# err6= -242.229763119186
# err7= -306.110482663898
# err8= -290.581753797034
# err9= -275.153789783471
# err10= -259.820343908711
# err11= -245.142727953527
# err12= -280.057145913549
# err13= -266.528110782589
# err14= -253.998767754756
# abs_err= -241.113755308768
# r= 1.000169244320204241329102406399139374133119302940200092684913359794867195847
# sage: analyze_q3(neg=true)
# err0= -242.181000000000
# err1= -275.216701351610
# err2= -305.344703716678
# err3= -289.815958802426
# err4= -273.287242479143
# err5= -257.758504343405
# err6= -242.229763119725
# err7= -306.110511944696
# err8= -290.581786737930
# err9= -275.153825107356
# err10= -259.820379297200
# err11= -245.142775831431
# err12= -281.056837819362
# err13= -267.527494791529
# err14= -254.997536561107
# abs_err= -241.113853540651
# r= 0.9998307843185887270192692250567026160687280948980569625374695582795594508997
def analyze_q3(neg=false):
   R64 = RealField(64)
   R128 = RealField(128)
   R192 = RealField(192)
   R256 = RealField(256)
   y = R64(0.00016923)
   if neg:
      y = -y
   Q_3 = [0xc9cba547af749429/2^37,0xb092309ec73dd7db/2^33,(0x8f76c77fc6c4bda8+1)/2^29,(0xd7322b3faa271c7d+1)/2^26,(0x93f27dbbc4fae397+1)/2^22,(0xb8ef1d2ab6399c7d+1)/2^19,(0xd00d00d00d00d00d+1)/2^16,(0xd00d00d00d00d00d+1)/2^13,(0xb60b60b60b60b60b+1)/2^10,(0x8888888888888888+1)/2^7,(0xaaaaaaaaaaaaaaaa+1)/2^5,(0xaaaaaaaaaaaaaaaa+1)/2^3,(0x8000000000000000+1)/2^1,0x8000000000000000+1,0x8000000000000000]
   assert len(Q_3)==15, "len(Q_3)==15"
   Q_3 = [x/2^63 for x in Q_3]
   err = dict()
   err[0] = 2^-242.181 # absolute error bound of Sollya polynomial
   print ("err0=", log(err[0])/log(2.))
   # mul_qint_11 (r, y, &Q_3[0])
   r0 = y*Q_3[0]
   erra = y.ulp()*Q_3[0] # ignored low part of y
   # add_qint_22 (r, &Q_3[1], r)
   r = Q_3[1] + R128(r0)
   assert r.prec()==128, "r.prec()==128"
   errb = 2*r.ulp()
   errc = R128(r0).ulp()
   err[1] = (erra + errb + errc)*abs(y)^13
   print ("err1=", log(err[1])/log(2.))
   r = R128(r)
   y = R128(y)
   for k in range(2,7):
      # mul_qint_22 (r, y, r)
      r0 = y*r
      erra = abs(y)*r.ulp() # ignored part of r multiplied by y
      errb = y.ulp()*r      # ignored part of y multiplied by r
      # add_qint_22 (r, &Q_3[k], r)
      r = Q_3[k]+r0
      assert r.prec()==128, "r.prec()==128"
      # warning: since we used add_qint_22, the error is in ulp_128 here
      errc = r.ulp()*2       # rounding error in add_qint_22
      errd = r0.ulp()        # ignored low 128 bits from r_in
      err[k] = (erra + errb + errc + errd)*abs(y)^(14-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   r = R192(r)
   y = R192(y)
   for k in range(7,12):
      # mul_qint_33 (r, y, r)
      r0 = y*r
      erra = R256(r0).ulp()*6 # rounding error in mul_qint_33()
      errb = abs(y)*r.ulp()   # ignored part of r multiplied by y
      errc = y.ulp()*r        # ignored part of y multiplied by r
      # add_qint (r, &Q_3[k], r)
      r = Q_3[k]+r0
      errd = R256(r).ulp()*2 # rounding error in add_qint
      err[k] = (erra + errb + errc + errd)*abs(y)^(14-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   r = R256(r)
   y = R256(y)
   for k in range(12,15):
      # mul_qint (r, y, r)
      r0 = y*r
      erra = r0.ulp()*14     # rounding error in mul_qint()
      # add_qint (r, &Q_3[k], r)
      r = Q_3[k]+r0
      errb = r.ulp()*2       # rounding error in add_qint
      err[k] = (erra + errb)*abs(y)^(14-k)
      print ("err"+str(k)+"=", log(err[k])/log(2.))
   abs_err = add(err[i] for i in [0..14])
   print ("abs_err=", log(abs_err)/log(2.))
   print ("r=", r)
   assert r > 0.99983, "r > 0.99983"

# for 0 <= i < 64, T1_3[i] approximates 2^(i/64)
def output_T1_3():
   print ("static const dint64_t T1_3[] = {")
   R256 = RealField(256)
   for i in range(64):
      c = R256(n(2^(i/64),300))
      s,m,e = c.sign_mantissa_exponent()
      assert s==1, "s==1"
      assert m.nbits()==256, "m.nbits()==256"
      l = m.digits(2^64)
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1},")
   print ("};")

# for 0 <= i < 64, T2_3[i] approximates 2^(i/2^12)
def output_T2_3():
   print ("static const dint64_t T2_3[] = {")
   R256 = RealField(256)
   for i in range(64):
      c = R256(n(2^(i/2^12),300))
      s,m,e = c.sign_mantissa_exponent()
      assert s==1, "s==1"
      assert m.nbits()==256, "m.nbits()==256"
      l = m.digits(2^64)
      if s==1:
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x0},")
      else: # s=-1
         print ("    {.hh = " + hex(l[3]) + ", .hl = " + hex(l[2]) + ", .lh = " + hex(l[1]) + ", .ll = " + hex(l[0]) + ", .ex = " + str(e+255) + ", .sgn = 0x1},")
   print ("};")

# computes the maximal relative error in p_3() in the case E=0 and
# i <> {127,128}
# In this case the errors (a) and (e) are zero.
def max_rel_err_p3_case1():
   maxerr = 0
   l1 = get_log_inv_3_1(7,9,90,181)
   l2 = get_log_inv_3_2(6,14,8128,8256,7,62)
   R256 = RealField(256)
   RIF256 = RealIntervalField(256)
   for i in range(len(l1)):
      t1 = l1[i]
      if i+90 in [127,128]:
         assert t1==0, "t1==0"
         continue
      for j in range(len(l2)):
         t2 = l2[j]
         # p_3 (&p, &z)
         p0 = RIF256(-0.0001221,0.0001221)
         err = RIF256(2^-265.67) # error (b)
         err += 1/2*R256(t1).ulp() # error (c1)
         err += 1/2*R256(t2).ulp() # error (c2)
         # add_qint (&p, &_LOG_INV_3_2[j - 8128], &p)
         p1 = p0 + t2
         err += p1.abs().upper().ulp()*2 # error (d2) <= 2 ulps(p1)
         # add_dint (&p, &_LOG_INV_3_1[i - 90], &p)
         p2 = p1 + t1
         err += p2.abs().upper().ulp()*2 # error (d1) <= 2 ulps(p2)
         # convert to relative error
         err = (err/p2).abs().upper()
         if err>maxerr:
            print ("i=", 90+i, "j=", 8128+j, "err=", float(err), log(err)/log(2.))
            maxerr = err

# computes the maximal relative error in p_3() in the case E=0,
# i in {127,128}, and j <> {8191,8192}.
# In this case the errors (a), (c1), (d1), (e) are zero.
def max_rel_err_p3_case2():
   maxerr = 0
   l2 = get_log_inv_3_2(6,14,8128,8256,7,62)
   R256 = RealField(256)
   RIF256 = RealIntervalField(256)
   for j in range(len(l2)):
      t2 = l2[j]
      if 8128+j in [8191,8192]:
         assert t2==0, "t2==0"
         continue
      # p_3 (&p, &z)
      p0 = RIF256(-0.0001221,0.0001221)
      err = RIF256(2^-265.67) # error (b)
      err += 1/2*R256(t2).ulp() # error (c2)
      # add_qint (&p, &_LOG_INV_3_2[j - 8128], &p)
      p1 = p0 + t2
      err += p1.abs().upper().ulp()*2 # error (d2) <= 2 ulps(p1)
      # convert to relative error
      err = (err/p1).abs().upper()
      if err>maxerr:
         print ("j=", 8128+j, "err=", float(err), log(err)/log(2.))
         maxerr = err
