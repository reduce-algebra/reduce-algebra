void print_help(const char *path) {
	puts("=== Factorization software v2.0.0 using Quadratic Sieve ===\n");
	puts("This software is released \"as it is\" into the public domain, without any warranty, express or implied.\n");
	puts("DESCRIPTION:");
	puts("  This software supports factoring numbers through a Self-Initializing Quadratic Sieve (SIQS).");
	puts("  The Factorization Manager reads numbers to be factored from either a file or the command line.\n");
	puts("USAGE:");
	printf("  %s [options] [numbers]\n\n", path);
	puts("OPTIONS:");
	puts("  -i, --input-file <FILE>      Factor all numbers from the specified input file.");
	puts("  -o, --output-file <FILE>     Write results to the specified output file.");
	puts("  -t, --timeout <SECONDS>      Set a timeout in seconds to interrupt the Quadratic Sieve.");
	puts("  -r, --rand-seed <NUMBER>     Use another set of random numbers that depend on <NUMBER>, 0 for the Unix timestamp.");
	puts("  -v, --verbose <VALUE>        Between 0 and 4, displays more or less information.");
	printf("  -f, --force                  Override default limits (8191 digits for numbers and %u-bit for the Quadratic Sieve).\n", DEFAULT_BIT_LIMIT_QS);
	puts("  -h, --help                   Show this help message and exit.\n");
	puts("OUTPUT FORMATS:");
	puts("  -j, --output-json            Format the results in JSON.");
	puts("  -J, --output-json-extended   Format the results in JSON with details.");
	puts("  -c, --output-csv             Format the results in CSV.");
	puts("  -C, --output-csv-extended    Format the results in CSV with details.\n");
	puts("QUADRATIC SIEVE OPTIONS:");
	puts("  --qs-multiplier <value>      Usually from 1 to 150");
	puts("  --qs-base-size <value>       Usually from 1000 to 50000");
	puts("  --qs-large-prime <value>     Usually from 300000 to 30000000");
	puts("  --qs-alloc-mb <value>        Usually from 1 to a few hundred");
	puts("  --qs-sieve <value>           Usually close to a multiple of 31744");
	puts("  --qs-threshold <value>       Usually from 60 to 110");
	puts("  --qs-error-bits <value>      Usually from 15 to 35");
	puts("  --qs-laziness <value>        Usually from 80 to 120 (in percentage)\n");
	puts("  Navigate through the source code to see their default value and usage.\n");
	puts("EXAMPLES:");
	puts("  -i input.txt -o output.txt --output-csv    # Factor all numbers from \"input.txt\" to \"output.txt\" in CSV.");
	puts("  27333597444727959277 36190584594536893817  # Factor the numbers.\n");
	puts("REPORTING BUGS:");
	puts("  Read the full documentation and report issues to the \"github.com/michel-leonard/C-Quadratic-Sieve\" repository.\n");
	puts("TESTING:");
	puts("  --demand -r 123        # provide a 'demand.txt' file that depends on the seed 123, suitable as input file.");
	puts("  -d 150                 # provide a 'demand.txt' file containing a single 150-bit sample number.");
	puts("  -d 60 150              # provide a 'demand.txt' file containing sample numbers ranging from 60-bit to 150-bit.");
	puts("  -d 150 150 100         # provide a 'demand.txt' file containing 100 sample numbers of 150-bit.");
	puts("  -i demand.txt -C -v 2  # Factor the 'demand.txt' file and display a status message.\n");
	puts("EXIT STATUS:");
	puts("  0  All numbers were successfully fully factored.");
	puts("  1  At least one number among the results is not fully factored.\n");
}

qs_md get_num(const char *s) {
	char *end = 0;
	const qs_md res = strtoull(s + (*s == '-'), &end, 10);
	return end != s && !*end ? *s == '-' ? -res : res : 0;
}

int cli_param_match(const char *str, const char *long_name, const char *short_name) {
	return (short_name && !strcmp(str, short_name)) || !strcmp(str, long_name);
}

int read_key_and_3_values(const char **argv, state *state) {
#define FILL(name_1, shortcut, name_2) \
    if (cli_param_match(*argv, "--" #name_1, "-" #shortcut) && \
        (n_1 = get_num(*(argv + 1))) && \
        (n_2 = get_num(*(argv + 2))) && \
        (n_3 = get_num(*(argv + 3)))) { \
        state->params.name_2[0] = n_1; \
        state->params.name_2[1] = n_2; \
        state->params.name_2[2] = n_3; \
    }
	qs_md n_1, n_2, n_3;
	FILL(demand, d, demand)
	else
		return 0;
	*argv = *(argv + 1) = *(argv + 2) = *(argv + 3) = 0;
	return 1;
}

int read_key_and_2_values(const char **argv, state *state) {
#define FETCH ((n_1 = get_num(val_1)) && (n_2 = get_num(val_2)))
	const char *key = *argv, *val_1 = *(argv + 1), *val_2 = *(argv + 2);
	qs_md n_1, n_2;
	if (cli_param_match(key, "--demand", "-d") && FETCH)
		state->params.demand[0] = n_1, state->params.demand[1] = n_2;
	else
		return 0;
	*argv = *(argv + 1) = *(argv + 2) = 0;
	return 1;
#undef FETCH
}

int read_key_value(const char **argv, state *state) {
	const char *key = *argv, *value = *(argv + 1);
	if (cli_param_match(key, "--verbose", "-v") && *value >= '0' && *value <= '9' && !*(value + 1))
		state->params.verbose = *value - '0';
	else if (cli_param_match(key, "--input-file", "-i"))
		state->params.input_file = value;
	else if (cli_param_match(key, "--output-file", "-o"))
		state->params.output_file = value;
	else if (cli_param_match(key, "--timeout", "-t"))
		state->params.timeout = get_num(value);
	else if (cli_param_match(key, "--rand-seed", "-r"))
		state->params.rand.seed ^= state->params.rand.custom = *value == '0' && *(value + 1) == 0 ? get_time_ms() : get_num(value);
	else if (cli_param_match(key, "--demand", "-d") && get_num(value))
		state->params.demand[0] = get_num(value);
		// Quadratic Sieve specific parameters.
#define QS_PARAM(name_1, name_2) \
    else if (cli_param_match(key, "--qs-" #name_1, 0)) \
        state->params.qs_##name_2 = get_num(value);
	QS_PARAM(multiplier, multiplier)
	QS_PARAM(base-size, base_size)
	QS_PARAM(large-prime, large_prime)
	QS_PARAM(alloc-mb, alloc_mb)
	QS_PARAM(sieve, sieve)
	QS_PARAM(sieve-cutoff, sieve_cutoff)
	QS_PARAM(threshold, threshold)
	QS_PARAM(error-bits, error_bits)
	QS_PARAM(laziness, laziness)
	QS_PARAM(tick-end, tick_end)
	else
		return 0;
#undef QS_PARAM
	*argv = *(argv + 1) = 0;
	return 1;
}

int read_flags(const char **argv, state *state) {
	const char *key = *argv;
	if (cli_param_match(key, "--verbose", "-v"))
		state->params.verbose = 2;
	else if (cli_param_match(key, "--output-json-extended", "-J"))
		state->params.output_format = 'J';
	else if (cli_param_match(key, "--output-json", "-j"))
		state->params.output_format = 'j';
	else if (cli_param_match(key, "--output-csv-extended", "-C"))
		state->params.output_format = 'C';
	else if (cli_param_match(key, "--output-csv", "-c"))
		state->params.output_format = 'c';
	else if (cli_param_match(key, "--force", "-f"))
		state->params.force = 1;
	else if (cli_param_match(key, "--demand", "-d"))
		state->params.demand[0] = -1;
	else if (cli_param_match(key, "--help", "-h"))
		state->params.help = 1;
	else
		return 0;
	*argv = 0;
	return 1;
}

void simple_rand(cint_sheet *sheet, uint64_t *seed, cint *nums, char *comment, const int factors_needed, const int bits_needed) {
// Produces a random composite number based on the seed, number of bits, and factors.
// Fill in the comment if the resulting number intentionally contains a power, empty it otherwise.
	begin :;
	cint *N = nums, *P = N + 1, *A = N + 2, *TMP;
	int bits_generated = 0, i = 0, remaining_factors = factors_needed, sym = 'A';
	char *message = comment ;
	*message = 0 ;
	cint_reinit(N, 1);
	do {
		const int factor_bits = (bits_needed - bits_generated) / remaining_factors;
		retry :;
		if (factor_bits < 3)
			goto begin;
		cint_random_bits(P, factor_bits + i, seed);
		*P->mem |= 1;
		if (!cint_is_prime(sheet, P, -1, seed))
			goto retry;
		i = !i;
		if (2 < remaining_factors && !xor_rand(seed, 0, 24)) {
			// Occasionally raise this prime number to a power.
			int pow = (int) xor_rand(seed, 2, remaining_factors - 1);
			remaining_factors += 1 - pow;
			message += sprintf(message, " %s %c^%d", sym == 'A' ? "and" : "*", sym, pow);
			++sym;
			do {
				cint_mul(N, P, A);
				if (--pow)
					TMP = A, A = N, N = TMP;
			} while (pow);
		} else
			cint_mul(N, P, A);
		const int old_bits = bits_generated;
		bits_generated = (int) cint_count_bits(A);
		if (remaining_factors == 1 && bits_generated != bits_needed) {
			bits_generated = old_bits;
			goto retry;
		}
		TMP = A, A = N, N = TMP;
	} while (--remaining_factors);
	if (N != nums)
		cint_dup(nums, N);
}

void generate_input_file(state *state) {
	// Simulate a factorization demand based on the "-d <min-bits> <max-bits> <count>" command line option.
	// For example "--demand 130 140 1000" provide 1000 non-trivial numbers between 130 and 140 bits.
	// The generated "demand.txt" file is suitable as an input file and consistent across platforms.
	// The contents of the file may depend on the "--rand-seed" command line option.
	const char *path = state->params.output_file;
	FILE *fp = fopen(path ? path : "demand.txt", "wb");
	if (fp) {
		uint64_t seed = state->params.rand.seed;
		qs_md *g = state->params.demand, min = g[0], max = g[1], count = g[2], tmp, i;
		if (min == -1) // No params specified.
			min = 6, max = DEFAULT_BIT_LIMIT_QS ;
		assert(!(min >> 12) && !(max >> 12));
		min = min < 6 ? 6 : 1300 < min ? 1300 : min;
		if (max) {
			max = max < 6 ? 6 : 1300 < max ? 1300 : max;
			if (max < min)
				tmp = min, min = max, max = tmp;
		} else
			max = min;
		count += !count;
		tmp = max - min + 1;
		if (count < tmp)
			count = tmp;
		if (count * (max + 12) >> 24)
			count = (1 << 24) / (max + 12) ; // ~8MB per file.
		double bits = min, step = (double) tmp / (double) count;
		cint_sheet *sheet = cint_new_sheet(max << 1);
		cint nums[3];
		for (i = 0; i < 3; ++i)
			cint_init(nums + i, max << 1, 1);
		const int max_len = cint_approx_digits_from_bits(max, 10);
		char buf[max_len + 255], *title = buf + max_len, *comment = title + 127, *str = title ;
		str += sprintf(str, "Generated %d sample number%s ", (int) count, 1 < count ? "s" : "");
		if (min == max)
			str += sprintf(str, "of %d-bit", (int) min);
		else
			str += sprintf(str, "ranging from %d-bit to %d-bit", (int) min, (int) max);
		if (state->params.rand.custom)
			sprintf(str, " using seed %" PRIu64, state->params.rand.custom);
		fprintf(fp, "# %s.\n# Use \"--demand", title);
		for(int j = 0; j < 3 && g[j] && g[j] != -1; ++j)
			fprintf(fp, " %d", (int)g[j]);
		if (state->params.rand.custom)
			fprintf(fp, " --rand-seed %" PRIu64, state->params.rand.custom);
		fprintf(fp, "\" to retrieve this file.\n\n");
		i = 0;
		do {
			// DEVELOPMENT : decrease 24 and 17 in the next line to test the trial division.
			const int n_factors_max = (int)bits / (65.0 <= bits ? 24 : 34.0 <= bits ? 17 : 3);
			const int n_factors = xor_rand(&seed, 2, xor_rand(&seed, 2, n_factors_max));
			simple_rand(sheet, &seed, nums, comment, n_factors, bits);
			cint_to_string_buffer(nums, buf, 10);
			fprintf(fp, "%-*s # %d bits with %d factors%s\n", max_len, buf, (int) bits, n_factors, comment);
			fflush(fp);
			if (state->params.tty && state->params.verbose)
				display_progress("Factorization file preparation", (double) i * 100.0 / (double) count);
		} while (bits += step, ++i < count);
		if (state->params.tty && state->params.verbose)
			display_progress(0, 100);
		fclose(fp);
		for (i = 0; i < 3; ++i)
			free(nums[i].mem);
		cint_clear_sheet(sheet);
		if (state->params.verbose)
			fprintf(stdout, "%s in file '%s'.\n", title, path ? path : "demand.txt");
	} else
		perror("Factorization program generator");
}

// cint shortcuts
char *simple_cint_string(state *state, const cint *N) {
	char *s = cint_to_string_buffer(N, state->session.output_string, 10);
	if (0)    // Add a thousand separator in debug for large number (as desired).
		for (int len = (int) strlen(s), i = len - 3, j = *s == '-'; j < i; i -= 3)
			memmove(s + i + 1, s + i, ++len - i), s[i] = ',';
	return s;
}

void simple_inline_cint(cint *N, const size_t size, void **mem) {
	// Fixed size cint is inlined, given mem is updated accordingly.
	N->mem = N->end = (h_cint_t *) *mem;
	*mem = N->mem + (N->size = size + 1);
}

void simple_dup_cint(cint *A, const cint *B, void **mem) {
	// Duplicates cint using the given memory, which is updated accordingly.
	// It uses the minimal size, the duplicate is not resizable.
	A->mem = A->end = (h_cint_t *) *mem;
	cint_dup(A, B);
	A->size = A->end - A->mem + 1;
	*mem = A->mem + A->size;
}

void simple_int_to_cint(cint *num, qs_md value) {
	// Pass the given 64-bit number into the given cint (positive only).
	for (cint_erase(num); value; *num->end++ = (h_cint_t) (value & cint_mask), value >>= cint_exponent);
}

qs_md simple_cint_to_int(const cint *num) {
	// Return the value of a cint as a 64-bit integer (sign is ignored).
	qs_md res = 0;
	for (h_cint_t *ptr = num->end; ptr > num->mem; res = (qs_md) (res * cint_base + *--ptr));
	return res;
}

// Avl
struct avl_node *avl_cint_inserter(void *args, const void *key_to_save) {
	// it expects as result a new node containing the given constant key.
	void *mem = *(void **) args;
	struct avl_node *res = mem;
	res->key = (cint *) (res + 1);
	mem = (cint *) res->key + 1;
	simple_dup_cint(res->key, key_to_save, &mem);
	assert(res->value == 0);
	*(void **) args = mem;
	return res;
}

// System
void *mem_aligned(void *ptr) {
	// Default alignment of the return value is 64.
	char *res __attribute__((aligned(64)));
	res = (char *) ptr + (64 - (uintptr_t) ptr) % 64;
	return res;
}

uint64_t get_time_ms(void) {
	// returns the current Unix timestamp with milliseconds.
	struct timeval time;
	gettimeofday(&time, NULL);
	return (uint64_t) time.tv_sec * 1000 + (uint64_t) time.tv_usec / 1000;
}

void debug_print(const state *state, int level, const char *format, ...) {
	if (level <= state->params.verbose) {
		va_list args;
		va_start(args, format);
		vfprintf(stderr, format, args);
		va_end(args);
		fflush(stderr);
	}
}

void display_progress(const char *name, double percentage) {
	static int chars = 0;
	if (percentage < 100.)
		// Print a progression percentage.
		chars = printf("\r- %s at %.02f %% ...\r", name, percentage);
	else
		// Clear the progression line.
		chars = !printf("\r%*s\r", chars, "");
	fflush(stdout);
}

// Factorization
void manager_add_factor(state *state, const cint *num, int pow, int is_prime) {
	assert(0 < pow);
	int i = 0;
	while (state->session.res[i].power && h_cint_compare(&state->session.res[i].num, num))
		++i;
	simple_inline_cint(&state->session.res[i].num, num->end - num->mem, &state->session.mem.now);
	cint_dup(&state->session.res[i].num, num);
	state->session.res[i].power = state->session.power * pow;
	if (0 < is_prime && !cint_is_prime(state->session.sheet, num, -1, state->session.seed)) {
		debug_print(state, 3, "[x] Maintenance challenges %s's primality test.\n", simple_cint_string(state, num));
		is_prime = -1 ; // [MATH INSURANCE] Re-factor this number due to conflicting Miller-Rabin tests.
	}
	state->session.res[i].prime = is_prime; // Possible values are: -1 (must factorize), 0 (not prime), and 1 (prime).
	//
}

void manager_add_simple_factor(state *state, qs_md num, int pow, int is_prime) {
	assert(0 < pow);
	simple_int_to_cint(state->session.tmp, num);
	manager_add_factor(state, state->session.tmp, pow, is_prime);
}

void factorization_64_bits(state *state) {
	fac64_row res[16];
	u64 num = simple_cint_to_int(&state->session.num);
	fac_64_worker(state, num, res);
	for (fac64_row *r = res; (*r).power; ++r)
		manager_add_simple_factor(state, (*r).prime, (*r).power, (*r).prime != 1);
	cint_reinit(&state->session.num, 1);
}

int factorization_trial_division(state *state, int stage, int bits) {
	assert(64 < bits);
	const int calc = stage == 2 ? (1 << 20) - 23250 * bits + 127 * bits * bits : 4669914;
	const qs_sm trial_upto = stage == 1 ? 524 : calc < 65522 ? 65522 : 4669914 < calc ? 4669914 : calc;
	cint *a = state->session.tmp, *b = a + 1, *c = a + 2, *tmp;
	cint *n = &state->session.num;
	cint_sheet *sheet = state->session.sheet;
	cint_reinit(a, 1);
	qs_sm trial = state->session.trial_start;
	for (; trial < trial_upto; trial += 2)
		if (is_prime_4669913(trial)) {
			a->mem[0] = (h_cint_t) trial;
			cint_div(sheet, n, a, b, c);
			if (c->mem == c->end) {
				int pow = 0;
				do {
					++pow;
					tmp = n, n = b, b = tmp;
					cint_div(sheet, n, a, b, c);
				} while (c->mem == c->end);
				manager_add_simple_factor(state, trial, pow, 1);
				if (n != &state->session.num)
					cint_dup(&state->session.num, n);
				state->session.trial_start = trial + 2;
				return 1;
			}
		}
	state->session.trial_start = trial + 2;
	return 0;
}

int factorization_any_root_checker(state *state, const cint *n, cint *root, cint *rem) {
	// Returns the lowest power when the number is a perfect power, 0 otherwise.
	// The function takes into account the trial divisions already performed.
	int res = 0;
	cint_sheet *sheet = state->session.sheet;
	cint *max = state->session.tmp;
	cint_reinit(max, (int) state->session.trial_start - 2);
	const int max_root = (int) cint_count_bits(n);
	for (int nth = 2; nth < max_root; nth += 1 + (nth != 2))
		if (is_prime_4669913((qs_sm)nth)) {
			cint_nth_root_remainder(sheet, n, nth, root, rem);
			if (rem->mem == rem->end) {
				res = nth;
				break;
			}
			if (h_cint_compare(root, max) <= 0)
				break;
		}
	return res;
}

int factorization_perfect_power_checker(state *state, int bits) {
	assert(64 < bits);
	cint *root = state->session.tmp + 1, *rem = root + 1;
	int pow = factorization_any_root_checker(state, &state->session.num, root, rem);
	if (pow) {
		manager_add_factor(state, root, pow, -1);
		cint_reinit(&state->session.num, 1);
	}
	return pow;
}

int factorization_prime_number_checker(state *state, int bits) {
	assert(64 < bits);
	cint_sheet *sheet = state->session.sheet;
	const int is_prime = cint_is_prime(sheet, &state->session.num, -1, state->session.seed) != 0;
	if (is_prime) {
		manager_add_factor(state, &state->session.num, 1, 1);
		cint_reinit(&state->session.num, 1);
	}
	return is_prime;
}

int factorization_give_up(state *state, int bits) {
	assert(64 < bits);
	manager_add_factor(state, &state->session.num, 1, 0);
	cint_reinit(&state->session.num, 1);
	return 1;
}

int factor(state *state) {
	state->session.duration_ms = get_time_ms();
	state->session.trial_start = 3;
	state->session.power = 1;
	int start_idx = 0, end_idx = 0;
	cint_dup(state->session.tmp + 9, &state->session.num);
	if (state->session.num.nat < 0) {
		// Add -1 as factor for a negative number.
		cint_reinit(state->session.tmp, -1);
		manager_add_factor(state, state->session.tmp, 1, 0);
		state->session.num.nat = 1;
		++start_idx;
	}
	int bits = (int) cint_count_zeros(&state->session.num);
	if (bits) {
		// Remove the powers of two from the number.
		manager_add_simple_factor(state, 2, bits, 1);
		cint_right_shifti(&state->session.num, bits);
		// The number is odd.
		++start_idx;
	}
	if (cint_compare_char(&state->session.num, 1) == 0) {
		if (start_idx == 0) {
			manager_add_simple_factor(state, 1, 1, 0);
			++start_idx;
		}
	} else {
		start :;
		bits = (int) cint_count_bits(&state->session.num);
		if (state->params.tty && state->params.verbose)
			display_progress(0, 100);
		if (bits < 65) {
			// 64-bit simple Pollard's Rho.
			if (1 < bits || start_idx == 0)
				factorization_64_bits(state);
		} else {
			const int res = factorization_trial_division(state, 1, bits)
							|| factorization_prime_number_checker(state, bits)
							|| factorization_trial_division(state, 2, bits)
							|| factorization_perfect_power_checker(state, bits)
							|| factorization_quadratic_sieve(state, bits)
							|| factorization_trial_division(state, 3, bits)
							|| factorization_give_up(state, bits);
			assert(res);
			if (cint_compare_char(&state->session.num, 1))
				manager_add_factor(state, &state->session.num, 1, -1);
		}
		end_idx = start_idx;
		for (int i = (int) state->scale.max_factors - 1; start_idx <= i; --i)
			if (state->session.res[i].prime == -1) {
				// Continue with a recursive-like approach to decompose non-prime factors.
				cint_dup(&state->session.num, &state->session.res[i].num);
				state->session.power = state->session.res[i].power;
				cint_erase(&state->session.res[i].num);
				if (end_idx == start_idx)
					state->session.mem.now = state->session.res[i].num.mem;
				state->session.res[i].power = state->session.res[i].prime = 0;
				goto start;
			} else if (end_idx == start_idx && state->session.res[i].power)
				end_idx = 1 + i;
	}

	// Sort the results (they start with a cint) using the unsigned cint comparator.
	if (end_idx)
		qsort(state->session.res + start_idx, end_idx - start_idx, sizeof(*state->session.res), (int (*)(const void *, const void *)) h_cint_compare);

	// [MATH INSURANCE] Verify the correctness of all factorizations.
	// Exit code 0 will mean that the product of all factors is equal to the input number.
	cint *A = state->session.tmp, *B = A + 1, *PRODUCT_OF_FACTORS = A + 2, *INPUT_NUMBER = A + 9, *TMP;
	cint_reinit(PRODUCT_OF_FACTORS, 1);
	for (int i = 0; state->session.res[i].power; ++i) {
		cint_reinit(B, state->session.res[i].power);
		cint_pow(state->session.sheet, &state->session.res[i].num, B, A);
		cint_mul(PRODUCT_OF_FACTORS, A, B), TMP = PRODUCT_OF_FACTORS, PRODUCT_OF_FACTORS = B, B = TMP;
	}

	if (cint_compare(INPUT_NUMBER, PRODUCT_OF_FACTORS) != 0){
		fprintf(stderr, "Input: %s\n", state->session.input_string);
		assert(!"[x] Maintenance points to a fatal mathematical error.");
	}

	// [MATH INSURANCE] Verify the completeness of all factorizations.
	// Exit code 0 will mean that the software has fully factored all numbers.
	int status = 0 ;
	for (int i = start_idx; state->session.res[i].power; ++i)
		state->code |= status |= !state->session.res[i].prime;

	state->session.duration_ms = get_time_ms() - state->session.duration_ms;
	return status ;
}

// Manager
int validate_input_file(state *state) {
	FILE *fp = state->in;
	while (!feof(fp)) {
		int c = fgetc(fp);
		if (!feof(fp) && (c == '+' || c == '-'))
			c = fgetc(fp);
		if (c >= '1' && c <= '9') {
			size_t digits = 1;
			while (!feof(fp) && (c = fgetc(fp)) >= '0' && c <= '9')
				++digits;
			++state->scale.total_rows;
			if (state->scale.max_digits < digits)
				state->scale.max_digits = digits;
		} else if (c != '\n')
			while (!feof(fp) && fgetc(fp) != '\n');
	}
	fseek(fp, 0, SEEK_SET);
	return state->scale.max_digits != 0;
}

size_t prepare_file_descriptors(state *state) {
	if (state->params.output_file) {
		state->out = fopen(state->params.output_file, "wb");
		if (!state->out)
			return perror("Factorization program output"), 0;
	} else
		state->out = stdout; // Standard output.

	if (state->params.input_file) {
		state->in = fopen(state->params.input_file, "rb");
		if (!state->in) {
			perror("Factorization program input");
			if (state->out != stdout)
				fclose(state->out);
			return 0;
		} else if (!validate_input_file(state)) {
			if (state->out != stdout)
				fclose(state->out);
			fclose(state->in);
			return 0;
		}
	}
	// Set a limit for numbers that are too large.
	if (state->scale.max_digits >> 13 && !state->params.force)
		return !fprintf(stderr, "A number of %" PRIu64 " digits when \x1b[37;40;1moption -f\033[0m isn't set is too large for the %d limit.\n", (uint64_t)state->scale.max_digits, 1 << 13);
	return state->scale.total_rows;
}

int validate_string_number(const char *s, state *state) {
	// Ensure that the string (number to factor) is well-formed, count the
	// total of submitted numbers, and note the size (decimal digits) of the largest.
	size_t digits;
	s += *s == '-' || *s == '+';
	if (*s >= '1' && *s <= '9' && !s[digits = 1 + strspn(s + 1, "0123456789")]) {
		if (state->scale.max_digits < digits)
			state->scale.max_digits = digits;
		return ++state->scale.total_rows, 1;
	}
	return 0;
}

void output_csv(state *state, int has_prev, int has_next, int status) {
	if (has_prev == 0)
		fprintf(state->out, "Input,Factors%s\n", state->params.output_format == 'C' ? ",Duration (s),Status" : "");
	fprintf(state->out, "%s,", state->session.input_string);
	for (int i = 0, pow; (pow = state->session.res[i].power); ++i) {
		const char *s = cint_to_string_buffer(&state->session.res[i].num, state->session.output_string, 10);
		for (int j = 0; j < pow; ++j)
			fprintf(state->out, !i && !j ? "%s" : ";%s", s);
	}
	if (state->params.output_format == 'C')
		fprintf(state->out, ",%.02f,%s", (double)state->session.duration_ms / 1000.0, status ? "Incomplete" : "Complete");
	fprintf(state->out, "\n");
}

void output_json(state *state, int has_prev, int has_next, int status) {
	fprintf(state->out, has_prev ? "    {" : "[\n    {");
	fprintf(state->out, "\n        \"input\": \"%s\",\n        \"factors\": [", state->session.input_string);
	for (int i = 0, pow; (pow = state->session.res[i].power); ++i) {
		const char *s = cint_to_string_buffer(&state->session.res[i].num, state->session.output_string, 10);
		const char *c = i ? "," : "", *p = state->session.res[i].prime ? "true" : "false";
		fprintf(state->out, "%s\n            {\n                \"num\": \"%s\",\n                \"power\": %d,\n                \"prime\": %s\n            }", c, s, pow, p);
	}
	fprintf(state->out, "%s]", "\n        ");
	if (state->params.output_format == 'J')
		fprintf(state->out, ",\n        \"duration\": %" PRIu64 ",\n        \"complete\": %s", state->session.duration_ms, status ? "false" : "true");
	fprintf(state->out, has_next ? "%s},\n" : "%s}\n]\n", "\n    ");
}

void output_default(state *state, int has_prev, int has_next, int status) {
	fprintf(state->out, "Number: %s\nFactors: ", state->session.input_string);
	for (int i = 0, pow; (pow = state->session.res[i].power); ++i) {
		const char *s = cint_to_string_buffer(&state->session.res[i].num, state->session.output_string, 10);
		const char *c = i ? ", " : "";
		if (pow == 1)
			fprintf(state->out, "%s%s (%s)", c, s, state->session.res[i].prime ? "prime" : "not prime");
		else
			fprintf(state->out, "%s%s^%d", c, s, pow);
	}
	if (2 < state->params.verbose)
		fprintf(state->out, "\nStatus: %s factored in %.02f s", status ? "incompletely" : "fully", (double)state->session.duration_ms / 1000.0);
	fprintf(state->out, has_next ? "\n\n" : "\n");
}

void output(state *state, int status) {
	const int has_prev = state->scale.row_idx != 0, has_next = state->scale.row_idx + 1 != state->scale.total_rows;
	if (state->params.tty && state->params.verbose)
		display_progress(0, 100);
	switch (state->params.output_format) {
		case 'c' : case 'C' : output_csv(state, has_prev, has_next, status); break;
		case 'J' : case 'j' : output_json(state, has_prev, has_next, status); break;
		default : output_default(state, has_prev, has_next, status); break;
	}
	++state->scale.row_idx; // Update the index after each factorization.
	if (state->params.tty && state->params.verbose)
		display_progress("Overall Progress", (double) state->scale.row_idx / (double) state->scale.total_rows * 100.0);
	fflush(state->out);
}

void prepare_sessions(state *state) {
	// Prepare a session containing enough memory to handle the largest (in terms of digits) number.
	state->scale.max_factors = 1;
	state->scale.max_bits = cint_approx_bits_from_digits(state->scale.max_digits, 10);
	for (int i = 3, bits = (int) state->scale.max_bits; 0 < bits; i += 2)
		if (is_prime_4669913(i))
			for (int j = (++state->scale.max_factors, i); j >>= 1; --bits);
	state->session.output_string = malloc(state->scale.max_bits + 32 - state->scale.max_bits % 16);
	assert(state->session.output_string); // String buffer to store any number represented in any base.
	const size_t bits = (2 + (state->scale.max_bits >> 4)) << 5;
	cint_init(&state->session.num, bits, 1); // The number to be factored.
	const size_t el_count = sizeof(state->session.tmp) / sizeof(*state->session.tmp);
	const size_t el_size = state->session.num.size * sizeof(*state->session.num.mem);
	cint *T = state->session.tmp;
	T[0].mem = T[0].end = calloc(el_count, el_size);
	assert(T[0].mem); // Temporary variables.
	T[0].size = state->session.num.size;
	for (size_t i = 1; i < el_count; ++i)
		T[i].mem = T[i].end = T[i - 1].mem + (T[i].size = T[i - 1].size);
	state->session.sheet = cint_new_sheet(bits);
	assert(state->session.sheet); // A computation sheet.
	state->session.mem.base = calloc(1, state->scale.max_factors * (sizeof(*state->session.res) + sizeof(*state->session.num.mem)) + (el_size << 1));
	assert(state->session.mem.base);
	state->session.res = state->session.mem.base;
	state->session.mem.now = state->session.res + state->scale.max_factors;
}

void erase_session(state *state) {
	// Erase the session (clear variables, number, and results).
	for (size_t i = 0; i < sizeof(state->session.tmp) / sizeof(*state->session.tmp); ++i)
		if (state->session.tmp[i].mem != state->session.tmp[i].end)
			cint_erase(&state->session.tmp[i]);
	cint_erase(&state->session.num);
	memset(state->session.mem.base, 0, (char *) state->session.mem.now - (char *) state->session.mem.base);
	state->session.mem.now = state->session.res + state->scale.max_factors;
}

void clear_sessions(state *state) {
	// Free all memory, close all descriptors.
	free(state->session.output_string);
	free(state->session.tmp[0].mem);
	free(state->session.num.mem);
	cint_clear_sheet(state->session.sheet);
	free(state->session.mem.base);
	if (state->in)
		fclose(state->in);
	if (state->out != stdout)
		fclose(state->out);
}

void process_single(state *state) {
	cint_reinit_by_string(&state->session.num, state->session.input_string, 10);
	uint64_t seed = state->params.rand.seed ;
	state->session.seed = &seed ; // Each number is factored with the seed.
	const int status = factor(state);
	output(state, status);
	state->duration_ms += state->session.duration_ms;
	if (state->scale.row_idx != state->scale.total_rows)
		erase_session(state); // Get ready for the next request.
}

void process_multi(int argc, const char **argv, state *state) {
	prepare_sessions(state);
	if (state->in) {
		// Process request(s) incoming from a file.
		const size_t buf_size = state->scale.max_digits + 4096;
		char *s = malloc(buf_size);
		assert(s);
		state->session.input_string = s ;
		while (fgets(s, buf_size, state->in))
			if ((*s >= '1' && *s <= '9') || ((*s == '+' || *s == '-') && *(s + 1) >= '1' && *(s + 1) <= '9')) {
				s[strspn(s, "+-0123456789")] = 0;
				process_single(state);
			}
		free(s);
	} else
		// Process request(s) incoming from the command line.
		for (int i = 1; i < argc; ++i)
			if (argv[i]) {
				state->session.input_string = argv[i];
				process_single(state);
			}
	if (1 < state->params.verbose)
		fprintf(stderr, "\n%s result%s %s in %.02f s.\n", state->code ? "[x] Maintenance reports that the" : "The", state->scale.row_idx == 1 ? " is" : "s are", state->code ? "correct but lacks accuracy" : "completely accurate and verified", (double) state->duration_ms * 0.001) ;
	// Clear all memory used to process the requests.
	clear_sessions(state);
}
