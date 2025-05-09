// 64-bit integer factorization algorithm released "as it" into the public domain, without any warranty, express or implied.

// The "worker" algorithm uses the Pollard Rho method when trial division isn't enough
// to fully factor the number, and Miller-Rabin identifies that the number is not prime.

int bit_size(u64 n) {
	int size = n != 0;
	while (n >>= 1)
		++size;
	return size;
}

u64 mul_mod(u64 a, u64 b, const u64 mod) {
	u64 res = 0, c; // return (a * b) % mod, avoiding overflow errors while doing modular multiplication.
	for (b %= mod; a; a & 1 ? b >= mod - res ? res -= mod : 0, res += b : 0, a >>= 1, (c = b) >= mod - b ? c -= mod : 0, b += c);
	return res % mod;
}

u64 pow_mod(u64 n, u64 exp, const u64 mod) {
	u64 res = 1; // return (n ^ exp) % mod.
	for (n %= mod; exp; exp & 1 ? res = mul_mod(res, n, mod) : 0, n = mul_mod(n, n, mod), exp >>= 1);
	return res;
}

int is_prime_64_bits(u64 n) {
	// Perform a Miller-Rabin test, it should be a deterministic version.
	static const u64 bases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	static const int n_bases = (int) sizeof(*bases);
	for (int i = 0; i < n_bases; ++i)
		if (n % bases[i] == 0)
			return n == bases[i];
	if (n < bases[n_bases - 1] * bases[n_bases - 1])
		return 1 < n;
	// Depending on the size of the number, we don't need to test all the bases.
	const int lim = n < 2152302898747 ? n < 25326001 ? n < 2047 ? 1 : n < 1373653 ? 2 : 3 : n < 3215031751 ? 4 : 5 : n < 341550071728321 ? n < 3474749660383 ? 6 : 7 : n < 3825123056546413051 ? 9 : 12;
	int res = 1, a = 0;
	u64 b, c;
	for (b = n - 1; ~b & 1; b >>= 1, ++a);
	for (int i = 0; i < lim && res; ++i)
		if (c = pow_mod(bases[i], b, n), c != 1) {
			for (int d = a; d-- && (res = c + 1 != n);)
				c = mul_mod(c, c, n);
			res = !res;
		}
	return res;
}

u64 pollard_rho(const u64 n, uint64_t *seed) {
	// Factorize N using the given seed to explore different sequences.
	u64 divisor = 1, a, b, c, i = 0, j = 1, x = 1, y = xor_rand(seed, 1, n - 1);
	for (; divisor == 1; ++i) {
		if (i == j) {
			if (j >> 18) // Adjust the timeout with (j >> 18) for 20 ms .......... (j >> 17) for 10 ms.
				break;
			j <<= 1;
			x = y;
		}
		a = y, b = y;
		for (y = 0; a; a & 1 ? b >= n - y ? y -= n : 0, y += b : 0, a >>= 1, (c = b) >= n - b ? c -= n : 0, b += c);
		y = (1 + y) % n;
		for (a = x < y ? y - x : x - y, b = n; (a %= b) && (b %= a););
		divisor = a | b;
	}
	return divisor;
}

u64 nth_root(const u64 n, const u64 nth) {
	// Use an iterative approach for finding the nth-roots.
	u64 a = n, b, c, r = nth ? n + (n > 1) : n == 1 ;
	for (; a < r; b = a + (nth - 1) * r, a = b / nth)
		for (r = a, a = n, c = nth - 1; c && (a /= r); --c);
	return r;
}

u64 square_extraction(u64 *n, int *pow) {
	u64 root = 1;
	if (3 < *n)
		while (root = nth_root(*n, 2), *n == root * root)
			*n = root, *pow <<= 1;
	return 65522U * 65522U < *n ? 65522U : root + 1;
}

void fac_64_worker(state *state, u64 n, fac64_row *rows) {
	if (3 < n) {
		int pow = 1;
		if (~n & 1) {
			// Powers of two are removed.
			*rows = (fac64_row) {2, 0};
			do {
				++(*rows).power;
				n >>= 1;
			} while (~n & 1);
			++rows;
		}
		if (8 < n) {
			// The number is odd.
			u64 limit = square_extraction(&n, &pow);
			// Ensure the number has no 16-bit factor by trial division.
			for (u64 prime = 3; prime < limit; prime += 2)
				if (n % prime == 0) {
					int p = 0;
					do ++p, n /= prime;
					while (n % prime == 0);
					*rows++ = (fac64_row) {prime, p * pow};
					limit = square_extraction(&n, &pow);
				}
			if (n >> 32) {
				int i = 0, j = 0;
				fac64_row tasks[8]; // Stack-based approach for the remainder (greater than 16-bit).
				tasks[i++] = (fac64_row) {n, pow};
				do {
					u64 x;
					n = tasks[--i].prime;
					pow = tasks[i].power;
					if (n == 1)
						continue;
					if (!(n >> 32) || is_prime_64_bits(n)) {
						for (int k = !(x = 1); k < i; ++k)
							while (tasks[k].prime % n == 0)
								tasks[k].prime /= n, x += tasks[k].power;
						*rows++ = (fac64_row) {n, (int) x * pow};
					} else if (x = nth_root(n, 2), n == x * x) {
						debug_print(state, 4, "- %" PRIu64 " is the square of %" PRIu64 ".\n", n, x);
						tasks[i++] = (fac64_row) {x, 2 * pow};
					} else if (x = nth_root(n, 3), n == x * x * x) {
						debug_print(state, 4, "- %" PRIu64 " is the cube of %" PRIu64 ".\n", n, x);
						tasks[i++] = (fac64_row) {x, 3 * pow};
					} else {
						debug_print(state, 4, "%sPollard's Rho on %" PRIu64 " (%d-bit).\n", ++j == 1 ? "" : "- Recursively applying ", n, bit_size(n));
						while (x = pollard_rho(n, state->session.seed), x == 1 || x == n);
						tasks[i++] = (fac64_row) {x * x < n ? x : n / x, pow};
						tasks[i++] = (fac64_row) {x * x < n ? n / x : x, pow};
					}
				} while (i);
			} else if(n != 1)
				*rows++ = (fac64_row) {n, pow};
		} else
			*rows++ = (fac64_row) {n, 1};
	} else if (n)
		*rows++ = (fac64_row) {n, 1};
	*rows = (fac64_row) {0};
}
