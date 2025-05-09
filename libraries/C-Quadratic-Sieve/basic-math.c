qs_md xor_random(qs_md *s) {
	// A shift-register generator has a reproducible behavior across platforms.
	return *s ^= *s << 13, *s ^= *s >> 7, *s ^= *s << 17 ;
}

qs_md xor_rand(qs_md *seed, qs_md min, qs_md max) {
	// Return a random number within the specified range.
	return min + xor_random(seed) % (max - min + 1);
}

int is_prime_4669913(const qs_sm n) {
	// Used to iterate through the first 326,983 prime numbers, up to 4,669,913 (the next one is not identified as prime).
	return ((n > 1) & ((n < 6) * 42 + 0x208A2882) >> n % 30 && (n < 49 || (n % 7 && n % 11 && n % 13 && n % 17 && n % 19 && n % 23 && n % 29 && (n < 961 || (n % 31 && n % 37 && n % 41 && n % 43 && n % 47 && n % 53 && n % 59 && n % 61 && n % 67 && (n < 5041 || (n % 71 && n % 73 && n % 79 && n % 83 && n % 89 && n % 97 && n % 101 && n % 103 && n % 107 && (n < 11881 || (n % 109 && n % 113 && n % 127 && n % 131 && n % 137 && n % 139 && n % 149 && n % 151 && n % 157 && (n < 26569 || (n % 163 && n % 167 && n % 173 && n % 179 && n % 181 && n % 191 && n % 193 && n % 197 && n % 199 && (n < 44521 || (n % 211 && n % 223 && n % 227 && n % 229 && n % 233 && n % 239 && n % 241 && n % 251 && n % 257 && (n < 69169 || (n % 263 && n % 269 && n % 271 && n % 277 && n % 281 && n % 283 && n % 293 && n % 307 && n % 311 && (n < 97969 || (n % 313 && n % 317 && n % 331 && n % 337 && n % 347 && n % 349 && n % 353 && n % 359 && n % 367 && (n < 139129 || (n % 373 && n % 379 && n % 383 && n % 389 && n % 397 && n % 401 && n % 409 && n % 419 && n % 421 && (n < 185761 || (n % 431 && n % 433 && n % 439 && n % 443 && n % 449 && n % 457 && n % 461 && n % 463 && n % 467 && (n < 229441 || (n % 479 && n % 487 && n % 491 && n % 499 && n % 503 && n % 509 && n % 521 && n % 523 && n % 541 && (n < 299209 || (n % 547 && n % 557 && n % 563 && n % 569 && n % 571 && n % 577 && n % 587 && n % 593 && n % 599 && (n < 361201 || (n % 601 && n % 607 && n % 613 && n % 617 && n % 619 && n % 631 && n % 641 && n % 643 && n % 647 && (n < 426409 || (n % 653 && n % 659 && n % 661 && n % 673 && n % 677 && n % 683 && n % 691 && n % 701 && n % 709 && (n < 516961 || (n % 719 && n % 727 && n % 733 && n % 739 && n % 743 && n % 751 && n % 757 && n % 761 && n % 769 && (n < 597529 || (n % 773 && n % 787 && n % 797 && n % 809 && n % 811 && n % 821 && n % 823 && n % 827 && n % 829 && (n < 703921 || (n % 839 && n % 853 && n % 857 && n % 859 && n % 863 && n % 877 && n % 881 && n % 883 && n % 887 && (n < 822649 || (n % 907 && n % 911 && n % 919 && n % 929 && n % 937 && n % 941 && n % 947 && n % 953 && n % 967 && (n < 942841 || (n % 971 && n % 977 && n % 983 && n % 991 && n % 997 && n % 1009 && n % 1013 && n % 1019 && n % 1021 && (n < 1062961 || (n % 1031 && n % 1033 && n % 1039 && n % 1049 && n % 1051 && n % 1061 && n % 1063 && n % 1069 && n % 1087 && (n < 1190281 || (n % 1091 && n % 1093 && n % 1097 && n % 1103 && n % 1109 && n % 1117 && n % 1123 && n % 1129 && n % 1151 && (n < 1329409 || (n % 1153 && n % 1163 && n % 1171 && n % 1181 && n % 1187 && n % 1193 && n % 1201 && n % 1213 && n % 1217 && (n < 1495729 || (n % 1223 && n % 1229 && n % 1231 && n % 1237 && n % 1249 && n % 1259 && n % 1277 && n % 1279 && n % 1283 && (n < 1661521 || (n % 1289 && n % 1291 && n % 1297 && n % 1301 && n % 1303 && n % 1307 && n % 1319 && n % 1321 && n % 1327 && (n < 1852321 || (n % 1361 && n % 1367 && n % 1373 && n % 1381 && n % 1399 && n % 1409 && n % 1423 && n % 1427 && n % 1429 && (n < 2053489 || (n % 1433 && n % 1439 && n % 1447 && n % 1451 && n % 1453 && n % 1459 && n % 1471 && n % 1481 && n % 1483 && (n < 2211169 || (n % 1487 && n % 1489 && n % 1493 && n % 1499 && n % 1511 && n % 1523 && n % 1531 && n % 1543 && n % 1549 && (n < 2411809 || (n % 1553 && n % 1559 && n % 1567 && n % 1571 && n % 1579 && n % 1583 && n % 1597 && n % 1601 && n % 1607 && (n < 2588881 || (n % 1609 && n % 1613 && n % 1619 && n % 1621 && n % 1627 && n % 1637 && n % 1657 && n % 1663 && n % 1667 && (n < 2785561 || (n % 1669 && n % 1693 && n % 1697 && n % 1699 && n % 1709 && n % 1721 && n % 1723 && n % 1733 && n % 1741 && (n < 3052009 || (n % 1747 && n % 1753 && n % 1759 && n % 1777 && n % 1783 && n % 1787 && n % 1789 && n % 1801 && n % 1811 && (n < 3323329 || (n % 1823 && n % 1831 && n % 1847 && n % 1861 && n % 1867 && n % 1871 && n % 1873 && n % 1877 && n % 1879 && (n < 3568321 || (n % 1889 && n % 1901 && n % 1907 && n % 1913 && n % 1931 && n % 1933 && n % 1949 && n % 1951 && n % 1973 && (n < 3916441 || (n % 1979 && n % 1987 && n % 1993 && n % 1997 && n % 1999 && n % 2003 && n % 2011 && n % 2017 && n % 2027 && (n < 4116841 || (n % 2029 && n % 2039 && n % 2053 && n % 2063 && n % 2069 && n % 2081 && n % 2083 && n % 2087 && n % 2089 && (n < 4405801 || (n % 2099 && n % 2111 && n % 2113 && n % 2129 && n % 2131 && n % 2137 && n % 2141 && n % 2143 && n % 2153)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

double log_computation(const double n) {
	// Basic logarithm calculation, so <math.h> isn't needed.
	static const double euler_constant = 2.718281828459045;
	unsigned a = 0, d;
	double b, c, e, f;
	if (n > 0) {
		for (c = n < 1 ? 1 / n : n; (c /= euler_constant) > 1; ++a);
		c = 1 / (c * euler_constant - 1), c = c + c + 1, f = c * c, b = 0;
		for (d = 1, c /= 2; e = b, b += 1 / (d * c), b - e > 0.00001;) {
			d += 2, c *= f;
		}
	} else b = (n == 0) / 0.;
	return n < 1 ? -(a + b) : a + b;
}

qs_sm multiplication_modulo(qs_md a, qs_md b, const qs_sm mod) {
	if (a < 0x100000000 && b < 0x100000000)
		return a * b % mod ;
// the implementation is designed for beginners, so there aren't many preprocessing "tricks".
#ifdef __SIZEOF_INT128__
	return (qs_sm) ((__int128_t) a * (__int128_t) b % (__int128_t) mod);
#else
	// Return (a * b) % mod, avoiding overflow errors while doing modular multiplication.
	qs_md res = 0, tmp;
	for (b %= mod; a; a & 1 ? b >= mod - res ? res -= mod : 0, res += b : 0, a >>= 1, (tmp = b) >= mod - b ? tmp -= mod : 0, b += tmp);
	return (qs_sm)(res % mod);
#endif
}

qs_sm power_modulo(qs_md n, qs_md exp, const qs_sm mod) {
	// Return (n ^ exp) % mod
	qs_sm res = 1;
	for (n %= mod; exp; exp & 1 ? res = multiplication_modulo(res, n, mod) : 0, n = multiplication_modulo(n, n, mod), exp >>= 1);
	return res;
}

int kronecker_symbol(qs_sm a, qs_sm b) {
	static const int s[8] = {0, 1, 0, -1, 0, -1, 0, 1};
	qs_sm c;
	int res = (int) (a | b);
	if (a && b)
		if (res & 1) {
			for (c = 0; !(b & 1); ++c, b >>= 1);
			// When B is odd Jacobi and Kronecker symbols are identical, in factorization algorithms B is often the prime number.
			// When B is an odd prime number, Jacobi symbol is equal to the Legendre symbol.
			for (res = c & 1 ? s[a & 7] : 1; a; c & 1 ? res *= s[b & 7] : 0, a & b & 2 ? res = -res : 0, c = b % a, b = a, a = c)
				for (c = 0; !(a & 1); ++c, a >>= 1);
			res = b == 1 ? res : 0;
		} else res = 0;
	else res = res == 1;
	return res;
}

qs_sm tonelli_shanks(const qs_sm n, const qs_sm mod) {
	// return root such that (root * root) % mod congruent to n % mod.
	// return 0 if no solution to the congruence exists.
	// mod is assumed odd prime, if mod = 2 then res is (n & 7 == 1 || n & 7 == 7).
	const qs_sm a = (qs_sm) (n % mod);
	qs_sm res = kronecker_symbol(a, mod) == 1, b, c, d, e, f, g, h;
	if (res)
		switch (mod & 7) {
			case 3 :
			case 7 :
				res = power_modulo(a, (mod + 1) >> 2, mod);
				break;
			case 5 :
				res = power_modulo(a, (mod + 3) >> 3, mod);
				if (multiplication_modulo(res, res, mod) != a) {
					b = power_modulo(2, (mod - 1) >> 2, mod);
					res = multiplication_modulo(res, b, mod);
				}
				break;
			default :
				if (a == 1)
					res = 1;
				else {
					for (c = mod - 1, d = 2; d < mod && power_modulo(d, c >> 1, mod) != c; ++d);
					for (e = 0; !(c & 1); ++e, c >>= 1);
					f = power_modulo(a, c, mod);
					b = power_modulo(d, c, mod);
					for (h = 0, g = 0; h < e; h++) {
						d = power_modulo(b, g, mod);
						d = multiplication_modulo(d, f, mod);
						d = power_modulo(d, 1 << (e - h - 1), mod);
						if (d == mod - 1)
							g += 1 << h;
					}
					f = power_modulo(a, (c + 1) >> 1, mod);
					b = power_modulo(b, g >> 1, mod);
					res = multiplication_modulo(f, b, mod);
				}
		}
	return res;
}

qs_sm modular_inverse(qs_sm ra, qs_sm rb) {
	// Return a modular multiplicative inverse of N with respect to the modulus.
	// Return 0 if the linear congruence has no solutions.
	// The answer is also called "u1" in the context of extended Euclidean algorithm.
	qs_sm rc, sa = 1, sb = 0, sc, i = 0;
	if (rb > 1)
		do {
			rc = ra % rb;
			sc = sa - (ra / rb) * sb;
			sa = sb, sb = sc;
			ra = rb, rb = rc;
		} while (++i, rc);
	sa *= (i *= ra == 1) != 0;
	sa += (i & 1) * sb;
	return sa;
}
