//  Enjoy the Classic Self-Initializing Quadratic Sieve (SIQS) written in C,
//  released "as it" into the public domain, without any warranty, express or implied.

int factorization_quadratic_sieve(state * state, int bits) {
	// The state contains a number N from the factorization manager and the Quadratic Sieve must :
	// - use resources present in the state (temporary variables + parameters)
	// - register prime (as possible) factors of N using the state
	// - maintain the value of N consistent with the removed factors
	// - return a non-zero value if the factorization has progressed

	if (bits < 65 || (DEFAULT_BIT_LIMIT_QS < bits && !state->params.force))
		return 0; // For every additional 10 bits, the factorization duration roughly doubles.

	// In 2025 on Michel Leonard’s test machine : 260 bits took 12 minutes, 270-bit took 24 minutes, 310-bit took 5 hours.

	qs_sheet qs = {0};
	preparation_part_1(&qs, state, bits);
	preparation_part_2(&qs);
	preparation_part_3(&qs);
	qs_parametrize(&qs);
	preparation_part_4(&qs);
	preparation_part_5(&qs);
	preparation_part_6(&qs);
	do {
		do {
			// Keep randomly trying various polynomials.
			get_started_iteration(&qs);
			iteration_part_1(&qs, &qs.poly.D, &qs.poly.A);
			iteration_part_2(&qs, &qs.poly.A, &qs.poly.B);
			iteration_part_3(&qs, &qs.poly.A, &qs.poly.B);
			for (qs_sm i = 0, addi, *corr; i < qs.poly.gray_max && qs.n_bits != 1; ++i, ++qs.poly.curves) {
				addi = iteration_part_4(&qs, i, &corr, &qs.poly.B);
				iteration_part_5(&qs, &qs.constants.kN, &qs.poly.B);
				iteration_part_6(&qs, &qs.constants.kN, &qs.poly.A, &qs.poly.B, &qs.poly.C);
				iteration_part_7(&qs, addi, corr);
				iteration_part_8(&qs, addi, corr);
				register_relations(&qs, &qs.poly.A, &qs.poly.B, &qs.poly.C);
			}
		} while (inner_continuation_condition(&qs));
		// Analyzes all observations made by the algorithm.
		finalization_part_1(&qs, block_lanczos(&qs));
	} while (outer_continuation_condition(&qs));
	const int res = finalization_part_2(&qs);
	free(qs.mem.base);
	return res;
}

// Quadratic sieve main condition 1 (often) :
// - Returns 1 : to produce more polynomials and relations.
// - Returns 0 : to start linear algebra with Block Lanczos.
int inner_continuation_condition(qs_sheet *qs) {
	int answer = 1 ;
	if ((qs->time.end || 2 < qs->state->params.verbose) && qs->time.tick % 16 == 1)
		qs->time.now = get_time_ms();
	answer &= qs->n_bits != 1 ; // the bit count of N may have changed.
	answer &= (qs->relations.length.peak = qs->relations.length.now) < qs->relations.length.needs; // the condition.
	answer &= !qs->time.end || qs->time.tick % 16 == 1 || qs->time.now < qs->time.end ;
	answer &= qs->time.tick != qs->state->params.qs_tick_end ;
	const double pct = .01 * (10000 * qs->relations.length.now / qs->relations.length.needs) ;
	if (pct != qs->time.prev_pct) {
		if (qs->state->params.tty && qs->state->params.verbose)
			display_progress("Quadratic Sieve", pct); // progress isn't linear.
		else if (DEFAULT_BIT_LIMIT_QS < qs->n_bits && (qs_sm)qs->time.prev_pct != (qs_sm)pct)
			DEBUG_LEVEL_4("%s", answer && !(qs->time.prev_pct < 50. && 50. <= pct) ? "." : ".\n");
		qs->time.prev_pct = pct;
	}
	return answer;
}

// Quadratic sieve main condition 2. Block Lanczos linear algebra has been completed :
// - Returns 1 : to get a new attempt at linear algebra with more relations.
// - Returns 0 : when N = 1 (meaning it is fully factored) or to give up.
int outer_continuation_condition(qs_sheet *qs) {
	int answer = 1 ;
	answer &= qs->n_bits != 1 ; // the bit count of N isn't 1.
	answer &= qs->sieve_again_perms-- != 0 ; // avoid infinite loop.
	answer &= qs->divisors.total_primes == 0 ; // search prime factors.
	answer &= !qs->time.end || get_time_ms() < qs->time.end ;
	answer &= qs->time.tick != qs->state->params.qs_tick_end ;
	if (answer) {
		qs_sm new_needs = qs->relations.length.needs;
		new_needs += new_needs >> (2 + qs->sieve_again_perms);
		DEBUG_LEVEL_3("[x] Maintenance re-evaluates the needs for %u additional relations.\n", new_needs - qs->relations.length.needs);
		qs->relations.length.needs = new_needs ;
	}
	return answer;
}

void qs_parametrize(qs_sheet *qs) {

	const qs_sm bits = qs->kn_bits; // N adjusted has at least 115-bit.
	qs->kn_bits = (qs_sm) cint_count_bits(qs->state->session.tmp); // kN may be slight larger.

	DEBUG_LEVEL_4("N is a %u-bit number, and kN is a %u-bit number using %u words.\n", (qs_sm) cint_count_bits(&qs->state->session.num), qs->kn_bits, (unsigned)(qs->state->session.tmp->end - qs->state->session.tmp->mem));

	qs_md tmp ;
	// params as { bits, value } take the extremal value if bits exceed.
	static const double param_base_size [][2]= { {135, 1300}, {165, 4200}, {200, 10000}, {260, 20000}, {330, 55000}, {0} };
	qs->base.length = (tmp = qs->state->params.qs_base_size) ? tmp : linear_param_resolution(param_base_size, bits);

	static const double param_laziness [][2]= {{150, 95}, {220, 100}, {0} };
	// collecting more/fewer relations than recommended (in percentage).
	qs->relations.length.needs = qs->base.length * ((tmp = qs->state->params.qs_laziness) ? tmp : linear_param_resolution(param_laziness, bits)) / 100;
	DEBUG_LEVEL_4("The algorithm use the seed %" PRIu64 " and targets %u relations.\n", qs->state->params.rand.custom, qs->relations.length.needs);

	static const double param_m_value [][2]= { {120, 1}, {330, 6}, {0} };
	qs->m.length = (qs->m.length_half = (qs->state->params.qs_sieve ? qs->state->params.qs_sieve : 31744) * linear_param_resolution(param_m_value, bits)) << 1;

	qs->m.cache_size = 95232 ; // algorithm reaches "M length" by steps of "cache size".

	static const double param_error [][2]= { {120, 15}, {330, 35}, {0} };
	// Logarithms of primes are rounded and errors accumulate; this specifies the magnitude of the error.
	qs->error_bits = (tmp = qs->state->params.qs_error_bits) ? tmp : linear_param_resolution(param_error, bits);

	static const double param_threshold [][2]= { {120, 60}, {330, 110}, {0} };
	// The threshold that the sieve value must exceed to be considered smooth.
	qs->threshold.value = (tmp = qs->state->params.qs_threshold) ? tmp : linear_param_resolution(param_threshold, bits);

	// A good multiplier reduces memory usage up to twice.
	static const double param_alloc [][2]= { {130, 992}, {140, 1280}, {150, 2176}, {160, 3584}, {170, 7168}, {180, 12288}, {190, 14336}, {190, 14336}, {200, 24576}, {210, 30720}, {220, 40960}, {230, 49152}, {240, 57344}, {250, 67584}, {260, 81920}, {270, 98304}, {280, 114688}, {290, 122880}, {300, 139264}, {310, 163840}, {320, 196608}, {330, 229376}, {0} };
	qs->mem.bytes_allocated = (tmp = qs->state->params.qs_alloc_mb) ? tmp << 20 : linear_param_resolution(param_alloc, qs->kn_bits) << 10;

	qs->sieve_again_perms = 3; // Sieve again up to 3 times before giving up

	// Iterative list
	qs->iterative_list[0] = 1; // one
	static const double param_first_prime [][2] = { {170, 8}, {210, 12}, {320, 40}, {0} };
	qs->iterative_list[1] = linear_param_resolution(param_first_prime, bits); // first
	tmp = qs->state->params.qs_sieve_cutoff ? qs->state->params.qs_sieve_cutoff : 5120 ;
	const qs_sm large_base = tmp < qs->base.length ? tmp : qs->base.length;
	qs->iterative_list[2] = large_base >> 2; // medium
	qs->iterative_list[3] = large_base >> 1; // mid
	qs->iterative_list[4] = large_base; // sec

	DEBUG_LEVEL_4("The iterative list contains %u, %u, %u and %u.\n", qs->iterative_list[1], qs->iterative_list[2], qs->iterative_list[3], qs->iterative_list[4]);

	const qs_md last_prime_in_base = (qs_md) (qs->base.length * 2.5 * log_computation(qs->base.length));
	qs->relations.too_large_prime = (tmp = qs->state->params.qs_large_prime) ? tmp : last_prime_in_base << 4;

	if (155 < qs->kn_bits)
		DEBUG_LEVEL_4("The single large-prime variation is being processed under %" PRIu64 ".\n", qs->relations.too_large_prime);

	qs->s.values.double_value = (qs->s.values.defined = (qs->s.values.subtract_one = bits / 28) + 1) << 1;
	qs->poly.gray_max = 1 << (qs->s.values.defined - 3); // computing the roots of f(x) once for all these polynomials.

	DEBUG_LEVEL_4("Other params include sieve=%u, error_bits=%u, threshold=%u and s=%u.\n", qs->m.length_half, qs->error_bits, qs->threshold.value, qs->s.values.defined);

	// The algorithm itself completes its configuration during the last preparation part.
	assert(qs->s.values.defined >= 3);

}

// Quadratic sieve utility function for parameter extrapolation.
qs_sm linear_param_resolution(const double v[][2], const qs_sm point) {
	qs_sm res, i, j ;
	if (v[1][0] == 0)
		res = (qs_sm) v[0][1];
	else {
		for (j = 1; v[j + 1][0] && point > v[j][0]; ++j);
		i = j - 1;
		if (v[i][0] > point) res = (qs_sm) v[i][1];
		else if (v[j][0] < point) res = (qs_sm) v[j][1];
		else {
			const double a = (v[j][1] - v[i][1]) / (v[j][0] - v[i][0]);
			const double b = v[i][1] - a * v[i][0];
			res = (qs_sm) (a * point + b);
		}
	}
	return res + (res > 512) * (16 - res % 16) ;
}

// Quadratic sieve source (algorithm)
void preparation_part_1(qs_sheet *qs, state *state, int bits) {
	// initializing (until kN is computed) with manager resources.
	qs->state = state;
	DEBUG_LEVEL_4("\nQuadratic Sieve on %s.\n", simple_cint_string(state, &state->session.num));
	qs->sheet = state->session.sheet;
	qs->seed = state->session.seed;
	qs->n_bits = qs->kn_bits = bits;
	if (2 < state->params.verbose || state->params.timeout) {
		qs->time.start = get_time_ms() ;
		if (state->params.timeout)
			qs->time.end = qs->time.start + 1000 * qs->state->params.timeout;
	}
}

void preparation_part_2(qs_sheet *qs) {
	// The algorithm is suitable for numbers larger than 115-bit,
	// and may adjust kN by a prime number to reach this size.
	cint * N = &qs->state->session.num, * kN = qs->state->session.tmp, *ADJUSTOR = kN + 1 ;
	static const unsigned char prime_generator[] = {
			9, 7, 5, 3, 17, 27, 3, 1, 29, 3, 21, 7, 17, 15,
			9, 43, 35, 15, 29, 3, 11, 3, 11, 15, 17, 25, 53,
			31, 9, 7, 23, 15, 27, 15, 29, 7, 59, 15, 5, 21,
			69, 55, 21, 21, 5, 159, 3, 81, 9, 69, 131, 33, 15 };
	const qs_sm bits = (qs_sm) qs->n_bits;
	if (bits < 115) {
		qs->adjustor = (1LLU << (124 - bits)) + prime_generator[115 - bits] ;
		simple_int_to_cint(ADJUSTOR, qs->adjustor);
		cint_mul(N, ADJUSTOR, kN);
		qs->kn_bits = (qs_sm) cint_count_bits(kN);
		DEBUG_LEVEL_4("Input (%u bits) is multiplied by %" PRIu64 " to reach %u bits.\n", bits, qs->adjustor, qs->kn_bits);
	} else
		qs->adjustor = 1, cint_dup(kN, N);
}

void preparation_part_3(qs_sheet *qs) {
	// Frequently select a small multiplier (under 8-bit) that will save time and memory.
	// After it, the algorithm will factor kN instead of N, where k is a constant named "multiplier".
	const qs_sm mul = (qs_sm) qs->state->params.qs_multiplier ;
	if (mul){
		DEBUG_LEVEL_4("The multiplier is %u.\n", mul);
		qs->multiplier = mul ;
	} else {
		const size_t total_best = 7;
		qs_sm best[total_best];
		for (int i = qs->state->params.verbose < 2; i < 2; ++i) {
			if (i)
				preparation_part_3_default_proposition(qs, best, total_best);
			else
				preparation_part_3_alternative_proposition(qs, best, total_best);
			DEBUG_LEVEL_4("%s", "Suggested multipliers are [");
			for (size_t j = 0; j < total_best - 1; ++j)
				DEBUG_LEVEL_4("%u, ", best[j]);
			DEBUG_LEVEL_4("%u]%s", best[total_best - 1], i ? "" : ".\n");
		}
		qs->multiplier = *best;
		DEBUG_LEVEL_4(", so use %u.\n", *best);
	}
	if (1 < qs->multiplier) {
		cint *kN = qs->state->session.tmp, *MUL = kN + 1, *N = kN + 2 ;
		simple_int_to_cint(MUL, qs->multiplier);
		cint_dup(N, kN);
		cint_mul(MUL, N, kN);
	}
}

void preparation_part_3_default_proposition(qs_sheet *qs, qs_sm *caller_res, const size_t caller_res_len) {
	// Choose a multiplier that make the input more favorable for smoothness
	// over the future factor base, and lead to faster relation gathering.
	struct {
		qs_sm mul;
		double score;
	} res[128] ; // 127 is the greatest multiplier.

	cint *N = qs->state->session.tmp, *PRIME = N + 1, *Q = N + 2, *R = N + 3;
	const double log_2 = 0.6931471805599453;
	const size_t len = sizeof(res) / sizeof(*res) - 1;
	for (qs_sm i = 0; i < len ; ++i) {
		res[i].mul = i + 1;
		res[i].score = -0.5 * log_computation(res[i].mul);
		switch (*N->mem * res[i].mul % 8) {
			// Special case against 2, the first prime number.
			case 3 : case 7 : res[i].score += 0.5 * log_2; break;
			case 5 : res[i].score += 1.0 * log_2; break;
			case 1 : res[i].score += 3.0 * log_2; break;
		}
	}

	const int limit = qs->n_bits * qs->n_bits >> 5 ;
	for (qs_sm prime = 3; prime < limit; prime += 2)
		if (is_prime_4669913(prime)) {
			// Normal case against the odd primes.
			simple_int_to_cint(PRIME, prime);
			cint_div(qs->sheet, N, PRIME, Q, R);
			const qs_sm n_mod_prime = (qs_sm) simple_cint_to_int(R);
			const double intake = 2.0 / (prime - 1) * log_computation(prime);
			const int kronecker = kronecker_symbol(n_mod_prime, prime);
			for (qs_sm i = 0; i < len; ++i)
				if (kronecker * kronecker_symbol(res[i].mul, prime) == 1)
					res[i].score += intake;
		}

	// Sort the results.
	for (int i = 0; i < len; ++i)
		for (int j = 1 + i; j < len; ++j)
			if (res[i].score < res[j].score)
				res[len] = res[i], res[i] = res[j], res[j] = res[len];

	for(int i = 0; i < caller_res_len; ++i)
		caller_res[i] = res[i].mul ;
}

void preparation_part_3_alternative_proposition(qs_sheet *qs, qs_sm *caller_res, const size_t caller_res_len) {
	// Choose a multiplier that make the input more favorable for smoothness
	// over the future factor base, and lead to faster relation gathering.
	struct {
		qs_sm mul;
		double score;
	} res[] = {{1, 0}, {2, 0}, {3, 0}, {5, 0}, {6, 0}, {7, 0}, {10, 0}, {11, 0}, {13, 0}, {14, 0}, {15, 0}, {17, 0}, {19, 0}, {21, 0}, {22, 0}, {23, 0}, {26, 0}, {29, 0}, {30, 0}, {31, 0}, {33, 0}, {34, 0}, {35, 0}, {37, 0}, {38, 0}, {39, 0}, {41, 0}, {42, 0}, {43, 0}, {46, 0}, {47, 0}, {51, 0}, {53, 0}, {55, 0}, {57, 0}, {58, 0}, {59, 0}, {61, 0}, {62, 0}, {65, 0}, {66, 0}, {67, 0}, {69, 0}, {70, 0}, {71, 0}, {73, 0}, {79, 0}, {83, 0}, {89, 0}, {97, 0}, {101, 0}, {103, 0}, {107, 0}, {109, 0}, {0, 0}};

	cint *N = qs->state->session.tmp, *TMP = N + 1, *Q = N + 2, *R = N + 3;
	const double log_2 = 0.6931471805599453;
	const size_t len = sizeof(res) / sizeof(*res) - 1;
	for (qs_sm i = 0; i < len; ++i) {
		res[i].score = -0.5 * log_computation(res[i].mul);
		switch (*N->mem * res[i].mul % 8) {
			// Special case against 2, the first prime number.
			case 3 : case 7 : res[i].score += 0.5 * log_2; break;
			case 5 : res[i].score += 1.0 * log_2; break;
			case 1 : res[i].score += 3.0 * log_2; break;
		}
	}

	for (qs_sm prime = 3; prime < 504; prime += 2)
		if (is_prime_4669913(prime)) {
			// Normal case against the odd primes.
			simple_int_to_cint(TMP, prime);
			cint_div(qs->sheet, N, TMP, Q, R);
			const qs_sm n_mod_prime = (qs_sm) simple_cint_to_int(R);
			const double intake = log_computation(prime) / (prime - 1);
			for (qs_sm i = 0; i < len; ++i) {
				const qs_sm kn_mod_prime = n_mod_prime * res[i].mul % prime;
				if (kn_mod_prime == 0)
					res[i].score += intake;
				else if (kronecker_symbol(kn_mod_prime, prime) == 1)
					res[i].score += 2.0 * intake;
			}
		}

	// Sort the results.
	for (int i = 0; i < len; ++i)
		for (int j = 1 + i; j < len; ++j)
			if (res[i].score < res[j].score)
				res[len] = res[i], res[i] = res[j], res[j] = res[len];

	for(int i = 0; i < caller_res_len; ++i)
		caller_res[i] = res[i].mul ;
}

void preparation_part_4(qs_sheet *qs) {
	void *mem;
	mem = qs->mem.base = calloc(1, qs->mem.bytes_allocated);
	assert(mem);

	// kN has been prepared in the manager memory, now the QS has been parameterized and allocated.
	const size_t kn_size = qs->state->session.tmp[0].end - qs->state->session.tmp[0].mem + 1 ;
	// the Quadratic Sieve variables can store at most kN ^ 2 in terms of bits
	const size_t vars_size = kn_size << 1 ;

	DEBUG_LEVEL_4("The underlying calculations use %u-bit variables.\n", (unsigned)(vars_size * cint_exponent));

	const size_t buffers_size = qs->base.length + (qs->iterative_list[1] << 1);
	// more relation pointers than "guessed" are available (sieve again feature).
	const size_t relations_size = (qs->base.length < qs->relations.length.needs ? qs->relations.length.needs : qs->base.length) * 7 / 4 ;

	{
		// list of the numbers used by the algorithm
		cint * const n[] = {
				&qs->vars.N,
				// polynomial
				&qs->poly.A,
				&qs->poly.B,
				&qs->poly.C,
				&qs->poly.D,
				// temporary
				&qs->vars.TEMP[0], &qs->vars.TEMP[1], &qs->vars.TEMP[2], &qs->vars.TEMP[3], &qs->vars.TEMP[4],
				// relations finder
				&qs->vars.X,
				&qs->vars.KEY,
				&qs->vars.VALUE,
				&qs->vars.CYCLE,
				// a factor of N
				&qs->vars.FACTOR,
				// constants
				&qs->constants.kN,
				&qs->constants.ONE,
				&qs->constants.M_HALF,
				&qs->constants.TOO_LARGE_PRIME,
				&qs->constants.MULTIPLIER,
				0,
		};
		for (int i = 0; n[i]; ++i) {
			n[i]->mem = n[i]->end = mem_aligned(mem) ;
			mem = n[i]->mem + (n[i]->size = vars_size);
		}
	}

	cint_dup(&qs->vars.N, &qs->state->session.num);
	cint_dup(&qs->constants.kN, qs->state->session.tmp);

	simple_int_to_cint(&qs->constants.ONE, 1);
	simple_int_to_cint(&qs->constants.M_HALF, qs->m.length_half);
	simple_int_to_cint(&qs->constants.TOO_LARGE_PRIME, qs->relations.too_large_prime);
	simple_int_to_cint(&qs->constants.MULTIPLIER, qs->multiplier);

	// Allocates "s" rows
	qs->s.data = mem_aligned(mem);
	mem = mem_aligned(qs->s.data + qs->s.values.defined);
	for (qs_sm i = 0; i < qs->s.values.defined; ++i) {
		simple_inline_cint(&qs->s.data[i].B_terms, kn_size, &mem); // also "s" more cint
		qs->s.data[i].A_inv_double_value_B_terms = mem;
		mem = mem_aligned(qs->s.data[i].A_inv_double_value_B_terms + qs->base.length);
	}
	qs->s.A_indexes = mem_aligned(mem); // the indexes of the prime numbers that compose A.

	// Allocates "base length" rows
	qs->base.data = mem_aligned(qs->s.A_indexes + qs->s.values.double_value);
	qs->m.positions[0] = mem_aligned(qs->base.data + qs->base.length);
	qs->m.positions[1] = mem_aligned(qs->m.positions[0] + qs->base.length);
	qs->m.sieve = mem_aligned(qs->m.positions[1] + qs->base.length);
	qs->m.sieve[qs->m.length] = 0xFF ; // the end of the sieve evaluates to "true" under any "truthy" mask.
	qs->m.flags = mem_aligned(qs->m.sieve + qs->m.length + sizeof(uint64_t));
	// Usage: buffer[0] is zeroed after use, buffer[1] isn't supposed zeroed after use.
	qs->buffer[0] = mem_aligned(qs->m.flags + qs->base.length);
	qs->buffer[1] = mem_aligned(qs->buffer[0] + buffers_size);

	// Other allocations
	qs->relations.length.capacity = (qs_sm) relations_size ;
	// Block Lanczos has a part of memory, it takes a "lite" snapshot before throwing relations.
	qs->lanczos.snapshot = mem_aligned(qs->buffer[1] + buffers_size) ;
	qs->relations.data = mem_aligned(qs->lanczos.snapshot + relations_size);
	qs->divisors.data = mem_aligned(qs->relations.data + relations_size);
	// A lot of divisors isn't needed because the algorithm calculate their GCD to reduce N.
	qs->mem.now = mem_aligned(qs->divisors.data + (qs->n_bits * qs->n_bits >> 8));

	const qs_sm n_trees = (qs_sm) (sizeof(qs->uniqueness) / sizeof(struct avl_manager));
	for (qs_sm i = 0; i < n_trees; ++i) {
		// the trees are used to identify duplicates (relations, partials, divisors of N)
		qs->uniqueness[i].inserter_argument = &qs->mem.now;
		qs->uniqueness[i].inserter = &avl_cint_inserter;
		qs->uniqueness[i].comparator = (int (*)(const void *, const void *)) &h_cint_compare;
		// they use default sign-less comparator.
	}
	avl_at(&qs->uniqueness[2], &qs->constants.ONE); // Ignore 1 as a divisor of N.
	DEBUG_LEVEL_4("Allocated %u MB of memory with a %u KB structure.\n", qs->mem.bytes_allocated >> 20, (unsigned)((char*)qs->mem.now - (char*)qs->mem.base) >> 10);
}

void preparation_part_5(qs_sheet *qs) {
	// Prepare the factor base (a set of small prime numbers used to find smooth numbers).
	static const double inv_ln_2 = 1.4426950408889634;
	cint *A = qs->vars.TEMP, *B = A + 1, *C = A + 2;
	qs_sm i = 0, prime;

	// the factor base contain the multiplier if different from 2.
	if (qs->multiplier != 2)
		qs->base.data[i].size = (qs_sm) (.35 + inv_ln_2 * log_computation(qs->base.data[i].num = qs->multiplier)), ++i;

	// then it contains the number 2.
	qs->base.data[i].num = 2, qs->base.data[i].size = 1;
	qs->base.data[i].sqrt_kN_mod_prime = *qs->constants.kN.mem % 8 == 1 || *qs->constants.kN.mem % 8 == 7, ++i;

	// then the prime numbers for which kN is a quadratic residue modulo.
	for (prime = 3; i < qs->base.length; prime += 2)
		if (is_prime_4669913(prime)) {
			simple_int_to_cint(A, prime);
			cint_div(qs->sheet, &qs->constants.kN, A, B, C);
			const qs_sm kn_mod_prime = (qs_sm) simple_cint_to_int(C);
			qs->base.data[i].sqrt_kN_mod_prime = tonelli_shanks(kn_mod_prime, prime);
			if (qs->base.data[i].sqrt_kN_mod_prime) {
				qs->base.data[i].num = prime;
				qs->base.data[i].size = (qs_sm) (.35 + inv_ln_2 * log_computation(prime)), ++i;
			}
		}
	// 2.5 * (base size) * ln(base size) is close to the largest prime number in factor base.
	qs->base.largest = qs->base.data[i - 1].num ;

	DEBUG_LEVEL_4("The factor base of %u suitable primes ends with %u.\n", qs->base.length, qs->base.largest);
}

void preparation_part_6(qs_sheet *qs) {
	// completes the configuration by the algorithm itself.
	// computes D : a template (optimal value of hypercube) for the A polynomial coefficient.
	qs_sm i, min, span;
	const qs_sm s = qs->s.values.defined ;
	qs->poly.span.half = (span = qs->base.length / (s * (s + s))) >> 1;
	cint *kN = qs->vars.TEMP, *TMP = kN + 1, *R = kN + 2;
	cint_dup(kN, &qs->constants.kN);
	cint_left_shifti(kN, 1);
	cint_sqrt(qs->sheet, kN, TMP, R);
	cint_div(qs->sheet, TMP, &qs->constants.M_HALF, &qs->poly.D, R);
	qs->poly.d_bits = (qs_sm) cint_count_bits(&qs->poly.D);
	cint_nth_root(qs->sheet, &qs->poly.D, s, R); // use the s-th root of D.
	const qs_sm root = (qs_sm) simple_cint_to_int(R) ;
	for (i = 1; qs->base.data[i].num <= root; ++i, assert(i < qs->base.length));
	if (i < span) {
		DEBUG_LEVEL_3("[x] Maintenance adjusts the span value from %u to %u.\n", span, i);
		span = i; // Avoids a rare case of failure when factoring small numbers (graceful degradation).
	}
	assert(i >= span);
	for (min = i - qs->poly.span.half, i *= i; i / min < span + min; --min);
	qs->poly.span.x_1 = min ;
	qs->poly.span.x_2 = min + qs->poly.span.half ;
	qs->poly.span.x_3 = qs->poly.span.x_2 * qs->poly.span.x_2 ;
	assert(qs->poly.span.x_2 < qs->base.length);
}

void get_started_iteration(qs_sheet *qs) {
	if (qs->lanczos.snapshot[0].relation) {
		// the operation is fast, it shouldn't happen in average case.
		// it restores the relations reduced by the linear algebra step that failed.
		qs_sm i ;
		for(i = 0; qs->lanczos.snapshot[i].relation; ++i) {
			qs->relations.data[i] = qs->lanczos.snapshot[i].relation;
			qs->relations.data[i]->Y.length = qs->lanczos.snapshot[i].y_length;
			qs->lanczos.snapshot[i].relation = 0 ;
		}
		assert(qs->relations.length.prev == i) ;
		qs->relations.length.now = i;
		DEBUG_LEVEL_4("[x] Maintenance restores the relations to a size of %u.\n", i);
	}
	//  Increase the tick value in each iteration of the algorithm.
	if (++qs->time.tick % 32 == 0) {
		if (qs->relations.length.prev == qs->relations.length.now) {
			// The algorithm notices that no relations accumulates, and reacts to unblock the situation.
			DEBUG_LEVEL_3("[x] Maintenance randomizes D because the relation counter remains at %u.\n", qs->relations.length.now);
			cint_random_bits(&qs->poly.D, qs->poly.d_bits, qs->seed);
			*qs->poly.D.mem |= 1; // Shouldn't happen, D becomes a randomized odd number.
		}
		qs->relations.length.prev = qs->relations.length.now;
	}
}

void iteration_part_1(qs_sheet * qs, const cint * D, cint * A) {
	qs_sm n_tries = 0 ; // several attempts may rarely be necessary.
	retry:;
	// A is a "random" product of "s" distinct prime numbers from the factor base.
	cint * X = qs->vars.TEMP, * Y = X + 1, *TMP, *_A = A ;
	qs_sm a, b, i = 0, j;
	if (qs->s.values.defined & 1) TMP = A, A = X, X = TMP ;
	// swap pointers so the last multiplication completes inside the A variable.
	simple_int_to_cint(A, 1);
	for (a = 0, b = qs->poly.span.x_3; a < qs->s.values.subtract_one; ++a) {
		if (a & 1) i = b / (i + qs->poly.span.x_1) - (qs_sm) xor_rand(qs->seed, 0, 9);
		else i = qs->poly.span.x_2 + (qs_sm) xor_rand(qs->seed, 0, qs->poly.span.half);
		for (j = 0; j < a; j = i == qs->s.data[j].prime_index ? ++i, 0 : j + 1);
		qs->s.data[a].prime_index = i; // the selected divisor of A wasn't already present in the product.
		simple_int_to_cint(Y, qs->base.data[i].num);
		cint_mul(A, Y, X), TMP = A, A = X, X = TMP;
	}
	// a prime number from the factor base completes A, which must be close to D.
	cint_div(qs->sheet, D, A, X, Y);
	const qs_sm d_over_a = (qs_sm) simple_cint_to_int(X);
	for (i = qs->base.data[0].num != 2 ; qs->base.data[i].num <= d_over_a; ++i);
	for (j = 0; j < qs->s.values.subtract_one; j = i == qs->s.data[j].prime_index ? ++i, 0 : j + 1);
	if (qs->base.length <= i) {
		const char *ord = n_tries == 0 ? "st" : n_tries == 1 ? "nd" : n_tries == 2 ? "rd" : "th" ;
		DEBUG_LEVEL_3("[x] Maintenance discards A=%s on %u%s attempt.\n", simple_cint_string(qs->state, A), n_tries + 1, ord);
		assert(++n_tries <= 16); // clearly shouldn't happen 16 times, review the algorithm parameters otherwise.
		A = _A ;
		goto retry;
	}
	qs->s.data[qs->s.values.subtract_one].prime_index = i ;
	simple_int_to_cint(Y, qs->base.data[i].num);
	cint_mul(A, Y, X); // generated A values should always be distinct, A no longer change.
	assert(X == &qs->poly.A);
}

void iteration_part_2(qs_sheet * qs, const cint * A, cint * B) {
	cint *X = qs->vars.TEMP, *PRIME = X + 1, *Y = X + 2, *R = X + 3;
	qs_sm i, *pen = qs->s.A_indexes;
	cint_erase(B);
	for (i = 0; i < qs->s.values.defined; ++i) {
		const qs_sm idx = qs->s.data[i].prime_index, prime = qs->base.data[idx].num;
		if (idx >= qs->iterative_list[3])
			qs->iterative_list[3] = 8 + idx - idx % 8 ;
		// write [index of prime number, power] of the A factors into buffer.
		*pen++ = qs->s.data[i].prime_index, *pen++ = 1;
		qs->s.data[i].prime_squared = (qs_md)prime * (qs_md)prime ;
		simple_int_to_cint(PRIME, prime);
		cint_div(qs->sheet, A, PRIME, X, R), assert(R->mem == R->end); // div exact.
		cint_div(qs->sheet, X, PRIME, Y, R);
		qs->s.data[i].A_over_prime_mod_prime = (qs_sm) simple_cint_to_int(R);
		qs_md x = modular_inverse(qs->s.data[i].A_over_prime_mod_prime, prime);
		x = x * qs->base.data[qs->s.data[i].prime_index].sqrt_kN_mod_prime % prime;
		simple_int_to_cint(X, x > prime >> 1 ? prime - x : x);
		cint_mul(A, X, Y);
		cint_div(qs->sheet, Y, PRIME, &qs->s.data[i].B_terms, R), assert(R->mem == R->end); // div exact.
		cint_addi(B, &qs->s.data[i].B_terms);
	}
}

void iteration_part_3(qs_sheet * qs, const cint * A, const cint * B) {
	cint *Q = qs->vars.TEMP, *R = Q + 1, *PRIME = Q + 2;
	qs_md i, j, x, y;
	for (i = 0; i < qs->base.length; ++i) {
		// prepare the "roots" and "A_inv_double_value_B_terms". The algorithm will
		// fill 2 ** (s - 3) sieves by using these values and adding "prime sizes".
		const qs_sm prime = qs->base.data[i].num;
		simple_int_to_cint(PRIME, prime);
		cint_div(qs->sheet, A, PRIME, Q, R);
		const qs_sm a_mod_prime = (qs_sm) simple_cint_to_int(R) ;
		cint_div(qs->sheet, B, PRIME, Q, R) ;
		const qs_sm b_mod_prime = (qs_sm) simple_cint_to_int(R) ;
		const qs_sm a_inv_double_value = modular_inverse(a_mod_prime, prime) << 1 ;
		// Arithmetic shifts "<<" and ">>" performs multiplication or division by powers of two.
		x = y = prime;
		x += qs->base.data[i].sqrt_kN_mod_prime;
		y -= qs->base.data[i].sqrt_kN_mod_prime;
		x -= b_mod_prime;
		x *= a_inv_double_value >> 1;
		y *= a_inv_double_value ;
		x += qs->m.length_half ;
		x %= prime ;
		y += x ;
		y %= prime ;
		qs->base.data[i].root[0] = (qs_sm) x ; // First root of the polynomial mod prime.
		qs->base.data[i].root[1] = (qs_sm) y ; // Second root of the polynomial mod prime.
		for (j = 0; j < qs->s.values.defined; ++j) {
			// compute the roots update value for all "s".
			cint_div(qs->sheet, &qs->s.data[j].B_terms, PRIME, Q, R);
			const qs_md b_term = simple_cint_to_int(R);
			qs->s.data[j].A_inv_double_value_B_terms[i] = (qs_sm)(a_inv_double_value * b_term % prime);
		}
	}
	// The next function operates over "B_terms" multiplied by 2.
	for (i = 0; i < qs->s.values.defined; cint_left_shifti(&qs->s.data[i++].B_terms, 1));
}

qs_sm iteration_part_4(const qs_sheet * qs, const qs_sm nth_curve, qs_sm ** corr, cint *B) {
	qs_sm i, gray_act; // the Gray code in "nth_curve" indicates which "B_term" to consider.
	for (i = 0; nth_curve >> i & 1; ++i);
	if (gray_act = (nth_curve >> i & 2) != 0, gray_act)
		cint_addi(B, &qs->s.data[i].B_terms) ;
	else // and which action to perform.
		cint_subi(B, &qs->s.data[i].B_terms) ;
	*corr = qs->s.data[i].A_inv_double_value_B_terms;
	return gray_act; // B values generated here should always be distinct.
}

void iteration_part_5(qs_sheet *  qs, const cint * kN, const cint * B) {
	cint *P = qs->vars.TEMP, *Q = P + 1, *R_kN = P + 2, *R_B = P + 3, *TMP = P + 4;
	for (qs_sm a = 0; a < qs->s.values.defined; ++a) {
		const qs_sm i = qs->s.data[a].prime_index;
		const qs_tmp prime = qs->base.data[i].num ;
		simple_int_to_cint(P, qs->s.data[a].prime_squared);
		cint_div(qs->sheet, B, P, Q, R_B);
		cint_div(qs->sheet, kN, P, Q, R_kN);
		if (B->nat < 0) cint_addi(R_B, P); // if B is negative.
		const qs_tmp rem_b = (qs_tmp) simple_cint_to_int(R_B);
		const qs_tmp rem_kn = (qs_tmp) simple_cint_to_int(R_kN);
		qs_tmp s ; // both remainders are modulo the prime number squared.
		if (rem_b < 0xb504f334) {
			// the multiplication is straightforward.
			s = rem_b * rem_b - rem_kn;
			s /= prime ;
		} else {
			// the common multiplication would overflow.
			cint_mul(R_B, R_B, TMP);
			cint_subi(TMP, R_kN);
			simple_int_to_cint(P, (qs_md) prime);
			cint_div(qs->sheet, TMP, P, Q, R_B);
			s = (qs_tmp) simple_cint_to_int(Q);
			if (Q->nat < 0) s = -s ;
		}
		//
		qs_tmp bezout = (rem_b % prime) * (qs_tmp) qs->s.data[a].A_over_prime_mod_prime ;
		bezout = (qs_tmp) modular_inverse((qs_sm) (bezout % prime), (qs_sm) prime);
		//
		s = (qs_tmp) qs->m.length_half - s * bezout ;
		s %= prime ;
		s += (s < 0) * prime ;
		qs->base.data[i].root[0] = (qs_sm) s;
		qs->base.data[i].root[1] = (qs_sm) -1; // Zero out roots corresponding to the factors of A.
	}
}

void iteration_part_6(qs_sheet *qs, const cint *kN, const cint *A, const cint *B, cint *C) {
	cint *TMP = qs->vars.TEMP, *R = TMP + 1;
	cint_mul(B, B, TMP); // (B * B) % A = kN % A
	cint_subi(TMP, kN); // C = (B * B - kN) / A
	cint_div(qs->sheet, TMP, A, C, R), assert(R->mem == R->end); // div exact.
}

void iteration_part_7(qs_sheet * qs, const qs_sm gray_addi, const qs_sm * restrict corr) {
	// Sieve for larger prime numbers.
	memset(qs->m.sieve, 0, qs->m.length * sizeof(*qs->m.sieve));
	memset(qs->m.flags, 0, qs->base.length * sizeof(*qs->m.flags));
	uint8_t * restrict end = qs->m.sieve + qs->m.length, *p_0, *p_1;
	for(qs_sm i = qs->iterative_list[3], j = qs->iterative_list[4]; i < j; ++i) {
		const qs_sm prime = qs->base.data[i].num, size = qs->base.data[i].size, co = gray_addi ? prime - corr[i] : corr[i];
		qs->base.data[i].root[0] += co; if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -= prime;
		qs->base.data[i].root[1] += co; if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -= prime;
		p_0 = qs->m.sieve + qs->base.data[i].root[0];
		p_1 = qs->m.sieve + qs->base.data[i].root[1];
		for (; end > p_0 && end > p_1;)
			*p_0 += size, p_0 += prime, *p_1 += size, p_1 += prime;
		*p_0 += (end > p_0) * size, *p_1 += (end > p_1) * size;
	}
	for(qs_sm i = qs->iterative_list[4], j = qs->base.length; i < j; ++i){
		const qs_sm prime = qs->base.data[i].num, size = qs->base.data[i].size, co = gray_addi ? prime - corr[i] : corr[i] ;
		qs->base.data[i].root[0] += co; if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -= prime;
		qs->base.data[i].root[1] += co; if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -= prime;
		for(p_0 = qs->m.sieve + qs->base.data[i].root[0]; end > p_0; qs->m.flags[i] |= 1 << ((p_0 - qs->m.sieve) & 7), *p_0 += size, p_0 += prime);
		for(p_1 = qs->m.sieve + qs->base.data[i].root[1]; end > p_1; qs->m.flags[i] |= 1 << ((p_1 - qs->m.sieve) & 7), *p_1 += size, p_1 += prime);
	}
}

void iteration_part_8(qs_sheet * qs, const qs_sm gray_addi, const qs_sm *  corr) {
	// Sieving means taking an interval [−M/2, +M/2] and determining for
	// which X in [−M/2, +M/2] a given prime number divides AX^2 + 2BX + C.
	uint8_t * chunk_begin = qs->m.sieve, *chunk_end = chunk_begin;
	uint8_t * sieve_end = chunk_begin + qs->m.length ;
	qs_sm *buffer = qs->buffer[0], walk_idx, * walk = buffer;
	// Since the previous function, the check is performed for the prime numbers of the factor base.
	for(qs_sm i = 0; i < qs->iterative_list[3]; ++i)
		if (qs->base.data[i].root[1] != (qs_sm) -1) {
			*walk++ = i ; // the current prime number isn't a factor of A.
			const qs_sm prime = qs->base.data[i].num, co = gray_addi ? prime - corr[i] : corr[i] ;
			qs->base.data[i].root[0] += co; if (qs->base.data[i].root[0] >= prime) qs->base.data[i].root[0] -= prime;
			qs->base.data[i].root[1] += co; if (qs->base.data[i].root[1] >= prime) qs->base.data[i].root[1] -= prime;
			qs->m.positions[0][i] = chunk_begin + qs->base.data[i].root[0];
			qs->m.positions[1][i] = chunk_begin + qs->base.data[i].root[1];
		}
	for(walk_idx = 0; buffer[walk_idx] < qs->iterative_list[1]; ++walk_idx);
	do{ // iterates step by step until the entire sieve is filled.
		walk = buffer + walk_idx ;
		chunk_end = chunk_end + qs->m.cache_size < sieve_end ? chunk_end + qs->m.cache_size : sieve_end;
		do{
			const qs_sm size = qs->base.data[*walk].size, prime = qs->base.data[*walk].num, times = 4 >> (*walk > qs->iterative_list[2]) ;
			uint8_t ** const p_0 = qs->m.positions[0] + *walk, ** const p_1 = qs->m.positions[1] + *walk;
			const qs_tmp diff = *p_1 - *p_0 ;
			for(const uint8_t * const bound = chunk_end - prime * times; bound > *p_0;)
				for(qs_sm i = 0; i < times; ++i)
					**p_0 += size, *(*p_0 + diff) += size, *p_0 += prime;
			for(; *p_0 < chunk_end && *p_0 + diff < chunk_end;)
				**p_0 += size, *(*p_0 + diff) += size, *p_0 += prime;
			*p_1 = *p_0 + diff ;
			if (*p_0 < chunk_end) **p_0 += size, *p_0 += prime;
			if (*p_1 < chunk_end) **p_1 += size, *p_1 += prime;
		} while(*++walk);
	} while(chunk_begin = chunk_end, chunk_begin < sieve_end);
	memset(qs->buffer[0], 0, (walk - qs->buffer[0]) * sizeof(*walk));
}

cint * qs_divisors_uniqueness_helper(qs_sheet * qs, const cint * num) {
	// Helper for uniqueness within the divisors of N.
	struct avl_node *node;
	node = avl_at(&qs->uniqueness[2], num) ;
	return qs->uniqueness[2].affected ? node->key : 0 ;
}

int qs_register_divisor(qs_sheet *qs) {
	// Register a divisor of N, combine them with GCD and identify the perfect powers.
	// Returns 0 when the factorization is completed, 1 otherwise.
#define IN_RANGE(F) (h_cint_compare(&qs->constants.ONE, F) < 0 && h_cint_compare(F, &qs->vars.N) < 0)
	cint *F = &qs->vars.FACTOR, *tmp;
	F->nat = 1 ; // Absolute value.
	if (!(IN_RANGE(F) && (tmp = qs_divisors_uniqueness_helper(qs, F))))
		return 1; // Duplicates are ignored.
	struct task {
		cint * num ;
		char origin ;
	} tasks[63] ; // Implements a stack-based recursion.
	cint *curr, **divisors = qs->divisors.data, *Q = qs->vars.TEMP + 3, *R = Q + 1;
	int i = 0, pow;
	tasks[i++] = (struct task) {tmp, 0};
	DEBUG_LEVEL_4("- New divisor %s shown.\n", simple_cint_string(qs->state, tmp));
	do {
		curr = tasks[--i].num; // Retrieve the top element.
		if (cint_is_prime(qs->sheet, curr, -1, qs->seed)) {
			pow = (int) cint_remove(qs->sheet, &qs->vars.N, curr);
			assert(pow); // Prime factors are removed from N.
			++qs->divisors.total_primes;
			qs->n_bits = (qs_sm) cint_count_bits(&qs->vars.N);
			// Register this prime factor in the manager's routine.
			manager_add_factor(qs->state, curr, pow, 1);
			if (tasks[i].origin) {
				char * msg = 0 ; // Explain succinctly how this prime factor was found.
				switch(tasks[i].origin) {
					case 1 : msg = "And allows us for N"; break;
					case 2 : msg = "Prunes the divisors"; break;
					case 3 : msg = "Divides N"; break;
					case 4 : msg = "Notes a perfect power"; break;
					case 5 : msg = "Performs GCD within the divisors"; break;
				}
				DEBUG_LEVEL_4("%*s- %s to get %s.\n", (i + 1) << 1, "", msg, simple_cint_string(qs->state, curr));
			}
			if (qs->n_bits != 1) {
				DEBUG_LEVEL_4("%*s- This prime factor reduces N to %d-bit.\n", (i + 1) << 1, "", qs->n_bits);
				if ((tmp = qs_divisors_uniqueness_helper(qs, &qs->vars.N)))
					tasks[i++] = (struct task){tmp, 1}; // 1. And allows us.
				for (qs_sm j = 0; j < qs->divisors.length; ++j) {
					cint_dup(F, divisors[j]);
					pow = cint_remove(qs->sheet, F, curr);
					if (pow) {
						divisors[j--] = divisors[--qs->divisors.length];
						if ((tmp = qs_divisors_uniqueness_helper(qs, F)) && IN_RANGE(tmp))
							tasks[i++] = (struct task){tmp, 2}; // 2. Prunes the divisors.
					}
				}
			} else
				DEBUG_LEVEL_4("%*s- The factorization is complete since it's a prime.\n", (i + 1) << 1, "");
		} else {
			cint_div(qs->sheet, &qs->vars.N, curr, Q, R) ;
			if (R->mem == R->end && IN_RANGE(Q) && (tmp = qs_divisors_uniqueness_helper(qs, Q)))
				tasks[i++] = (struct task){tmp, 3}; // 3. Divides N.
			pow = factorization_any_root_checker(qs->state, curr, Q, R) ;
			if (pow && IN_RANGE(Q) && (tmp = qs_divisors_uniqueness_helper(qs, Q)))
				tasks[i++] = (struct task){tmp, 4}; // 4. Notes a perfect power.
			for (qs_sm j = 0; j < qs->divisors.length; ++j) {
				cint_gcd(qs->sheet, curr, divisors[j], Q);
				if (IN_RANGE(Q) && (tmp = qs_divisors_uniqueness_helper(qs, Q)))
					tasks[i++] = (struct task){tmp, 5}; // 5. Performs GCD within the divisors.
			}
			divisors[qs->divisors.length++] = curr;
		}
	} while (i && qs->n_bits != 1);
	return qs->n_bits != 1;
#undef IN_RANGE
}

void register_relations(qs_sheet * qs, const cint * A, const cint * B, const cint * C) {
	cint *  TMP = qs->vars.TEMP, * K = &qs->vars.KEY, * V = &qs->vars.VALUE ;
	qs_sm m_idx, idx, mod;
	// iterates the values of X in [-M/2, +M/2].
	for (m_idx = 0; m_idx < qs->m.length; ++m_idx)
		if (qs->m.sieve[m_idx] >= qs->threshold.value) {
			// over the threshold, compute f(X) and check candidate for smoothness.
			simple_int_to_cint(&qs->vars.X, m_idx);
			cint_subi(&qs->vars.X, &qs->constants.M_HALF); // X = "current index" - M/2
			cint_mul(A, &qs->vars.X, TMP); // TMP = AX
			cint_addi(TMP, B); // TMP = AX + B
			cint_dup(K, TMP); // Key = copy of AX + B
			cint_addi(TMP, B); // TMP = AX + 2B
			cint_mul(TMP, &qs->vars.X, V); // V = AX^2 + 2BX
			cint_addi(V, C); // Value = f(X) = AX^2 + 2BX + C
			// We can inject X in the equation A * C + kN = B * B
			// So it should hold that (A * X + B)^2 - kN = A * f(X)
			V->nat = 1 ; // absolute value
			qs_sm target_bits = (qs_sm) cint_count_bits(V) - qs->error_bits;
			qs_sm removed_bits = 0, * restrict pen = qs->buffer[1];
			//  writes the pairs [index of the prime number, power found in V].
			if (qs->base.data[0].num != 1) {
				simple_int_to_cint(TMP, qs->base.data[0].num);
				*pen++ = 0; // remove powers of the multiplier.
				*pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
				if (*pen) removed_bits += *pen++ * qs->base.data[0].size; else --pen;
			}
			for (idx = 1; idx < qs->iterative_list[1]; ++idx)
				if (qs->base.data[idx].root[1] == (qs_sm) -1 || (mod = m_idx % qs->base.data[idx].num, mod == qs->base.data[idx].root[0] || mod == qs->base.data[idx].root[1])) {
					simple_int_to_cint(TMP, qs->base.data[idx].num);
					// for a given prime number of the factor base, "remove" returns
					// the numbers of powers that was present in V, and V is updated.
					*pen++ = idx;
					*pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
					if (*pen) removed_bits += *pen++ * qs->base.data[idx].size; else --pen;
				}
			if (removed_bits + qs->m.sieve[m_idx] >= target_bits) {
				// there is a chance to register a new relation.
				for (removed_bits = 0, target_bits = qs->m.sieve[m_idx]; idx < qs->iterative_list[4] && removed_bits < target_bits; ++idx)
					if (qs->base.data[idx].root[1] == (qs_sm) -1 || (mod = m_idx % qs->base.data[idx].num, mod == qs->base.data[idx].root[0] || mod == qs->base.data[idx].root[1])) {
						simple_int_to_cint(TMP, qs->base.data[idx].num);
						*pen++ = idx;
						*pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
						if (*pen) removed_bits += *pen++ * qs->base.data[idx].size; else --pen;
					}
				for (const uint8_t mask = 1 << (m_idx & 7); idx < qs->base.length && removed_bits < target_bits; ++idx)
					if (qs->m.flags[idx] & mask)
						if (mod = m_idx % qs->base.data[idx].num, mod == qs->base.data[idx].root[0] || mod == qs->base.data[idx].root[1]) {
							simple_int_to_cint(TMP, qs->base.data[idx].num);
							*pen++ = idx;
							*pen = (qs_sm) cint_remove(qs->sheet, V, TMP);
							if (*pen) removed_bits += *pen++ * qs->base.data[idx].size; else --pen;
						}
				const qs_sm * restrict const prime_indexes_and_powers[4] = {
						qs->s.A_indexes, // really factoring A * f(X), commit outstanding A factors.
						qs->s.A_indexes + qs->s.values.double_value,
						qs->buffer[1],
						pen,
				};
				if (h_cint_compare(V, &qs->constants.ONE) == 0)
					register_regular_relation(qs, K, prime_indexes_and_powers);
				else if (155 < qs->kn_bits && h_cint_compare(V, &qs->constants.TOO_LARGE_PRIME) < 0)
					//  Store it until another partial share the same variation (also called large prime, cofactor).
					register_partial_relation(qs, K, V, prime_indexes_and_powers);
			}
		}
}

void register_regular_relation(qs_sheet * qs, const cint * KEY, const qs_sm * const restrict args[4]) {
	struct avl_node *node = avl_at(&qs->uniqueness[0], KEY);
	if (node->value)
		return; // duplicates at this stage are ignored.
	struct qs_relation * rel = qs->mem.now;
	qs_sm i, j ;
	qs->mem.now = rel + 1 ; // a relation must be swappable for Block Lanczos reducing.
	rel->X = node->key; // constant X is stored by the node key.
	rel->Y.data = qs->mem.now; // Y data length only decreases.
	const size_t y_length = (args[1] - args[0] + args[3] - args[2]) >> 1 ;
	rel->axis.Z.data = rel->Y.data + y_length; // writes Z ahead.
	for (i = 0; i < 4;) {
		// processes the given column arrays.
		const qs_sm * restrict idx = args[i++], * restrict const end_index = args[i++];
		for (; idx < end_index; idx += 2) {
			const qs_sm power = *(idx + 1) ;
			if (power & 1) {
				// remove from Y the indexes of the prime numbers that are already listed (factors of A).
				for (j = 0; j < rel->Y.length && rel->Y.data[j] != *idx; ++j);
				if (j == rel->Y.length) // add, the index wasn't present.
					rel->Y.data[rel->Y.length++] = *idx;
				else // or remove.
					memmove(rel->Y.data + j, rel->Y.data + j + 1, (--rel->Y.length - j) * sizeof(*rel->Y.data));
			}
			for (j = 0; j < power; ++j)
				rel->axis.Z.data[rel->axis.Z.length++] = *idx;
		}
	}
	qs->mem.now = rel->axis.Z.data + rel->axis.Z.length; // Z length is known.
	int verified = 0 ;
	if (rel->Y.length > qs->s.values.defined) {
		// it often passes.
		cint *A = qs->vars.TEMP, *B = A + 1;
		simple_int_to_cint(A, 1);
		for (j = 0; j < rel->axis.Z.length; ++j) {
			simple_int_to_cint(B, qs->base.data[rel->axis.Z.data[j]].num);
			cint_mul_modi(qs->sheet, A, B, &qs->constants.kN);
		}
		cint_mul_mod(qs->sheet, rel->X, rel->X, &qs->constants.kN, B);
		verified = !cint_compare(A, B) || (cint_addi(A, B), !cint_compare(A, &qs->constants.kN));
	}
	if (verified){
		node->value = qs->relations.data[qs->relations.length.now] = rel;
		qs->mem.now = rel->axis.Z.data + rel->axis.Z.length;
		rel->id = ++qs->relations.length.now; // Keep the relation.
	} else {
		DEBUG_LEVEL_3("[x] Maintenance discards the relation at index %u.\n", qs->relations.length.now);
		char * open = (char*) rel, * close = qs->mem.now ;
		qs->mem.now = memset(open, 0, close - open); // Throw.
	}
}

void register_partial_relation(qs_sheet * qs, const cint * KEY, const cint * VALUE, const qs_sm * const restrict args[4]) {
	// Process the single large-prime variation.
	// Searches 2 different KEY sharing the same VALUE.
	struct avl_node *node = avl_at(&qs->uniqueness[1], VALUE);
	struct qs_relation *old, *new;
	cint * BEZOUT = 0;
	old = node->value;
	if (old) {
		if (old->X == 0) return; // the value is already marked as "ignored".
		if (old->axis.next) return; // accepting all "next" without caring compromise the linear algebra.
		for (; old && h_cint_compare(KEY, old->X); old = old->axis.next);
		if (old) return; // same KEY already registered.
		old = node->value;
		if (old->axis.next == 0) {
			// there is an "old" using the same VALUE, and it has no "next" yet.
			cint *A = qs->vars.TEMP, *B = A + 1;
			if (qs->multiplier != 1)
				if (cint_gcd(qs->sheet, VALUE, &qs->constants.MULTIPLIER, A), cint_compare_char(A, 1)){
					old->X = 0; // VALUE shouldn't be related so close to the multiplier.
					return;
				}
			// so compute BEZOUT.
			cint_modular_inverse(qs->sheet, VALUE, &qs->constants.kN, A);
			if (A->mem == A->end) {
				old->X = 0; // no solution to the linear congruence.
				cint_gcd(qs->sheet, VALUE, &qs->constants.kN, &qs->vars.FACTOR);
				cint_div(qs->sheet, &qs->vars.N, &qs->vars.FACTOR, A, B);
				if (B->mem == B->end) // found a small factor of N ?
					qs_register_divisor(qs);
				return; // nothing.
			} else
				BEZOUT = A;
		}
	}

	new = mem_aligned(qs->mem.now);
	qs->mem.now = new + 1;
	new->X = qs->mem.now;

	if (BEZOUT) {
		// BEZOUT is stored directly after the new X, like in an array.
		qs->mem.now = new->X + 2;
		simple_dup_cint(new->X, KEY, &qs->mem.now);
		simple_dup_cint(new->X + 1, BEZOUT, &qs->mem.now);
		// The 2nd newcomer become the root of the linked list.
		new->axis.next = old, node->value = new = old = new;
	} else {
		// All but the 2nd have no special treatment.
		qs->mem.now = new->X + 1; // they come at the end of the linked list.
		simple_dup_cint(new->X, KEY, &qs->mem.now);
		if (old) {
			for (; old->axis.next; old = old->axis.next);
			old->axis.next = new, old = node->value;
		} else node->value = new;
	}

	// data buffered isn't persistent, it may be needed, so it's copied.
	qs_sm * data = new->Y.data = mem_aligned(qs->mem.now);
	new->Y.length = (qs_sm) (args[1] - args[0]);
	memcpy(data, args[0], new->Y.length * sizeof(*data));
	memcpy(data + new->Y.length, args[2], (args[3] - args[2]) * sizeof(*data));
	new->Y.length += (qs_sm) (args[3] - args[2]);
	qs->mem.now = new->Y.data + new->Y.length;

	if (old) {
		BEZOUT = old->X + 1 ; // the modular inverse was stored here.
		cint_mul_mod(qs->sheet, new->X, BEZOUT, &qs->constants.kN, &qs->vars.CYCLE);
		do {
			if (old != new) {
				// combines, it registers a smooth relation using the 2 buffers.
				cint_mul_mod(qs->sheet, &qs->vars.CYCLE, old->X, &qs->constants.kN, &qs->vars.KEY);
				qs_sm * restrict begin = qs->buffer[0], * restrict pen = begin;
				data = memset(qs->buffer[1], 0, qs->base.length * sizeof(*data));
				for (qs_sm i = 0; i < new->Y.length; i += 2)
					data[new->Y.data[i]] += new->Y.data[i + 1];
				for (qs_sm i = 0; i < old->Y.length; i += 2)
					data[old->Y.data[i]] += old->Y.data[i + 1];
				for (qs_sm i = 0; i < qs->base.length; ++i)
					if (data[i]) // writes [index of the prime number, power]
						*pen++ = i, *pen++ = data[i];
				args = (const qs_sm * restrict const[4]){ begin, pen, 0, 0, };
				register_regular_relation(qs, &qs->vars.KEY, args);
				++qs->relations.length.by_partial;
				memset(begin, 0, (char *) pen - (char *) begin); // zeroed.
			}
		} while ((old = old->axis.next));
		// the linked list can handle 2+ entries, but their more complex combinations isn't implemented.
	}
}

void finalization_part_1(qs_sheet * qs, const uint64_t * restrict const lanczos_answer) {
	// Block Lanczos linear algebra answer is simply "mask followed by null_rows", with read-only.
	if (*lanczos_answer == 0)
		return;
	const uint64_t mask = *lanczos_answer, * restrict null_rows = lanczos_answer + 1;
	cint *X = &qs->vars.X, *Y = qs->vars.TEMP, *TMP = Y + 1, *POW = Y + 2;
	qs_sm * restrict power_of_primes;
	for(qs_sm row = 0; row < 64 && qs->n_bits != 1; ++row)
		if (mask >> row & 1){
			// use the Fermat's (1607 - 1665) method to compute a factorization of N.
			simple_int_to_cint(X, 1), simple_int_to_cint(TMP, 1), simple_int_to_cint(Y, 1);
			power_of_primes = memset(qs->buffer[1], 0, qs->base.length * sizeof(*power_of_primes));
			for (qs_sm i = 0; i < qs->relations.length.now; ++i)
				if (null_rows[i] >> row & 1) {
					const struct qs_relation * restrict const rel = qs->relations.data[i];
					// The algorithm must retrieve the X and Z relation fields
					// related to the Y field initially submitted to Block Lanczos.
					cint_mul_modi(qs->sheet, X, rel->X, &qs->vars.N);
					for (qs_sm j = 0; j < rel->axis.Z.length; ++j)
						++power_of_primes[rel->axis.Z.data[j]];
				}
			for (qs_sm i = 0; i < qs->base.length; ++i)
				if (power_of_primes[i]){
					// powers are even ... square root ...
					simple_int_to_cint(TMP, qs->base.data[i].num);
					simple_int_to_cint(POW, power_of_primes[i] >> 1);
					cint_pow_modi(qs->sheet, TMP, POW, &qs->vars.N);
					cint_mul_modi(qs->sheet, Y, TMP, &qs->vars.N);
				}
			h_cint_subi(Y, X);
			if (Y->mem != Y->end) {
				cint_gcd(qs->sheet, &qs->vars.N, Y, &qs->vars.FACTOR);
				// 100 digits RSA number has been factored by the software in 2022.
				if (qs_register_divisor(qs) == 0)
					break;
			}
		}
}

int finalization_part_2(qs_sheet *qs) {
	if (qs->n_bits != 1 && qs->divisors.length) {
		// In rare cases N must be partially factored.
		// Registers a divisor encountered by the algorithm in the manager routine.
		cint **divisors = qs->divisors.data, *tmp;
		for (qs_sm i = 0; i < qs->divisors.length; ++i) {
			for (qs_sm j = 1 + i; j < qs->divisors.length; ++j)
				if (h_cint_compare(divisors[j], divisors[i]) < 0)
					tmp = divisors[i], divisors[i] = divisors[j], divisors[j] = tmp; // Apply a selection sort.
			if (h_cint_compare(&qs->constants.ONE, divisors[i]) < 0 && h_cint_compare(divisors[i], &qs->vars.N) < 0) {
				const int power = (int) cint_remove(qs->sheet, &qs->vars.N, divisors[i]);
				if (power) {
					DEBUG_LEVEL_4("Quadratic Sieve submits the composite divisor %s as a result.\n", simple_cint_string(qs->state, divisors[i]));
					manager_add_factor(qs->state, divisors[i], power, -1); // -1 marks this divisor as composite for recursive factorization.
					qs->n_bits = (qs_sm) cint_count_bits(&qs->vars.N);
				}
			} else
				break; // No need to sort more.
		}
		// Recursively running the Quadratic Sieve will allow faster factorization than this oversized instance.
		DEBUG_LEVEL_3("[x] Maintenance is to forward the remainder %s.\n", simple_cint_string(qs->state, &qs->vars.N));
	}

	if (qs->uniqueness[1].count)
		DEBUG_LEVEL_4("The sieve reported %u partials which added %u smooth relations.\n", (unsigned) qs->uniqueness[1].count, qs->relations.length.by_partial);
	DEBUG_LEVEL_4("The algorithm completed with %u polynomials and %u relations.\n", qs->poly.curves, qs->relations.length.peak);
	DEBUG_LEVEL_4("Used %u MB of memory during %.02f second(s).\n", (unsigned) ((char *) qs->mem.now - (char *) qs->mem.base) >> 20, 0.001 * (get_time_ms() - qs->time.start));

	// Tells the factorization manager whether its task has progressed using the Quadratic Sieve.
	const int has_fully_factored = qs->n_bits == 1, has_partially_factored = qs->divisors.length != 0 ;
	const int res = has_fully_factored || has_partially_factored ;
	if (res) // Updates the input number accordingly, since the algorithm worked on a copy of it.
		cint_dup(&qs->state->session.num, &qs->vars.N);

	return res ;
}

// Compiling with "gcc -Wall -pedantic -O2 -std=c99 main.c -o factor" can speed up by a factor 2 or 3.
