# based on ../../binary64/pow/qint.sage
# q is the polynomial string output by "sollya accurate_exp2.sollya"
# analyze_exp2poly(q)
# err[-1]=  -261.066000000000
# err[0]=  -290.069724844166
# err[1]=  -328.756371037638
# err[2]=  -304.859494179307
# err[3]=  -281.671700703331
# err[4]=  -257.902813711393
# err[5]=  -360.995874962087
# err[6]=  -337.996874962087
# err[7]=  -315.997874962087
# err[8]=  -293.998874962087
# err[9]=  -271.999874962087
# err[10]=  -254.000000000000
# abs. error =  -253.896573138428
# rel. error =  -253.896572184093
def analyze_exp2poly(q):
	# since all coefficients of Q are positive, we can get an upper
	# bound of each variable by taking y positive and rounding upwards
	R64  = RealField(64,  rnd="RNDU")
	R128 = RealField(128, rnd="RNDU")
	R192 = RealField(192, rnd="RNDU")
	R256 = RealField(256, rnd="RNDU")
	y = R64(2^-19.999)
	R.<x> = RealField(256)[]
	Q = R(q)
	Q = [Q[10-i] for i in [0..10]]
	assert len(Q) == 11, "len(Q)==11"
	for i in [0..10]:
	    assert Q[i]>=0, "Q[i]>=0"
	err = dict()
	err[-1] = 2^-261.066 # polynomial error given by Sollya
	# mul_qint_11(r, &Q[0], x)
	r = y*Q[0]
	err[0] = y.ulp()*Q[0] # ignored low part of y
	err[0] *= y^9         # r has degree 1 now, and degree 10 at the end
	r = R128(r)
	y = R128(y)
	for i in range(1,4+1):
		# check Q[i] is exact representable on 128 bits
		assert R128(Q[i]) == Q[i], "R128(Q[i]) == Q[i]"
		# add_qint_22(r, &Q[i], r)
		r = Q[i] + r
		# Warning: the error of add_qint_22 is bounded by 2 ulp_128(r)
		# not 2 ulp_256(r)
		erra = R128(r).ulp()*2 # rounding error in the addition
                # r has degree i now
		erra *= y^(10-i)
		# mul_qint_22(r, r, x)
		r_in = r
		r = r*y
		errc = r_in.ulp()*y # ignored low part of the product
		errd = r_in*y.ulp() # ignored low part of the product
                # r has degree i+1 now
		errcd = (errc+errd)*y^(10-(i+1))
		err[i] = erra+errcd
	r = R256(r)
	y = R256(y)
	for i in range(5, 9+1):
		# add_qint(r, &Q[i], r)
		r = Q[i] + r
		erra = R256(r).ulp()*2 # rounding error in the addition	
		erra *= y^(10-i)
		# mul_qint(r, r, x)
		r = r*y
		errb = r.ulp() * 14 # rounding error of the product
		errb *= y^(10-(i+1))
		err[i] = erra+errb
	# add_qint(r, &Q[10], r)
	r = Q[10] + r
	err[10] = r.ulp()*2
	for i in range(-1, 10 + 1):
		print("err["+str(i)+"]= ", log(err[i])/log(2.))
	tot = add(err[i] for i in [-1..10])
	print("abs. error = ", log(tot)/log(2.))
	# since |y| <= 2^-19.999, |2^y| >= 2^(-2^-19.999)
	# thus the relative error is bounded by tot/2^(-2^-19.999)
	rel = tot/2^(-y)
	print("rel. error = ", log(rel)/log(2.))

# based on ../../binary64/qint.h
# p is the polynomial string output by "sollya accurate_log2.sollya"
# sage: analyze_logpoly(p)
# err[-1]=  -250.299000000000
# err[0]=  -282.702160816241
# err[1]=  -332.884781260879
# err[2]=  -320.860597692641
# err[3]=  -308.833781849149
# err[4]=  -296.803892298400
# err[5]=  -284.770381346131
# err[6]=  -272.732560615954
# err[7]=  -260.689551902842
# err[8]=  -373.990874962087
# err[9]=  -361.991874962087
# err[10]=  -349.992874962087
# err[11]=  -337.993874962087
# err[12]=  -325.994874962087
# err[13]=  -313.995874962087
# err[14]=  -300.996874962087
# err[15]=  -288.997874962087
# err[16]=  -276.998874962087
# err[17]=  -263.999874962087
# err[18]=  -255.000000000000
# abs. error before final product =  -250.297925397070
# total rel. error =  -249.997704460729181
def analyze_logpoly(p):
	R64  = RealField(64,  rnd="RNDU")
	R128 = RealField(128, rnd="RNDU")
	R192 = RealField(192, rnd="RNDU")
	R256 = RealField(256, rnd="RNDU")
	R.<x> = RealField(256)[]
	y = R64(2^-11.999)
	err = dict()
	err[-1] = 2^-250.299 # Sollya polynomial's error
	P = R(p)
	# we take the absolute value of the coefficients
	# to ensure we get an upper bound of the different values
	P = [abs(P[18-i]) for i in [0..18]]
	assert len(P) == 19, "len(P) == 19"
	# mul_qint_11(r, x, &P[0])
	r = y*P[0]
	err[0] = y.ulp()*P[0] # ignored low part of y
	err[0] *= y^17 # r has degree 1 now and degree 18 at the end
	r = R128(r)
	y = R128(y)
	for i in range(1,7+1):
		# add_qint_22(r, &P[i], r)
		r = P[i] + r
		erra = r.ulp()*2 # rounding error in the addition
		erra *= y^(18-i) # r has degree i
		# mul_qint_22(r, r, x)
		r_in = r
		r = r*y # now r has degree i+1
		errb = r_in.ulp()*y # ignored low limbs of the product
		errc = r_in*y.ulp()
		errbc = (errb+errc)*y^(18-(i+1))
		err[i] = erra+errbc
	r = R256(r)
	y = R256(y)
	for i in range(8, 17+1):
		# add_qint(r, &P[i], r)
		r = P[i] + r
		erra = R256(r).ulp()*2 # rounding error in the addition	
		erra *= y^(18 - i)
		# mul_qint(r, r, x)
		r = r*y
		errb = r.ulp() * 14 # rounding error of the product
		errb *= y^(18 - (i+1))
		err[i] = erra + errb
	# add_qint(r, &P[i], r) (with i = 18)
	r = P[i] + r
	erra = R256(r).ulp()*2 # rounding error in the addition	
	err[18] = erra
	for i in range(-1, 18 + 1):
		print("err["+str(i)+"]= ", log(err[i])/log(2.))
	tot = add(err[i] for i in [-1..10])
	print("abs. error before final product = ", log(tot)/log(2.))
	# before the last product, r approximates log2(1+x)/x
	# for |x| < 2^-11.999, |log2(1+x)/x| > 1.442
	# thus the relative error is bounded by tot/1.442
	rel = tot/1.442
	rel += 2^-255 * 14 # relative rounding error of the product
	print("total rel. error = ", R64(log(rel)/log(2.)))
	
