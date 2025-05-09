#ifndef CINT_MASTER
#define CINT_MASTER

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

// The tiny Big Integer Library (released "as is", into the public domain, without any warranty, express or implied)
// is provided for handling large integers. It includes basic and advanced mathematical functions to support calculations.
// This library does not use global variables but computation sheets, so it is stateless and thread-safe.

// memory is supposed provided by the system, allocations are passed to "assert".
// cint use "computation sheets" instead of global vars, it's thread-safe.

// the functions name that terminates by "i" means immediate, in place.
// the functions name that begin by "h_" means intended for internal usage.

typedef int64_t h_cint_t; // worked with short, int, long, etc.

static const h_cint_t cint_exponent = 4 * sizeof(h_cint_t) - 1;
static const h_cint_t cint_base = (h_cint_t) 1 << (4 * sizeof(h_cint_t) - 1);
static const h_cint_t cint_mask = cint_base - 1;
// Alphabet used for input and output strings in base from 2 to 62.
static const char *cint_alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

typedef struct {
	h_cint_t *mem;	// Where the lowest bits of the number are stored  (little-endian format)
	h_cint_t *end;	// Where the highest bits of the number are stored (at end - 1)
	// The only number having mem == end is zero
	h_cint_t nat;	// -1 = negative, +1 = positive, (zero is a positive)
	size_t size;	// The allocated size (greater than or equal to end - mem)
} cint;

typedef struct {
	cint temp[10];
} cint_sheet;

static cint_sheet *cint_new_sheet(const size_t bits) {
	// a computation sheet is required by function needing temporary vars.
	cint_sheet *sheet = calloc(1, sizeof(cint_sheet));
	assert(sheet);
	const size_t x = bits / cint_exponent, num_size = x + 8 - x % 4;
	for (size_t i = 0; i < sizeof(sheet->temp) / sizeof(*sheet->temp); ++i) {
		sheet->temp[i].nat = 1;
		sheet->temp[i].mem = sheet->temp[i].end = calloc(num_size, sizeof(h_cint_t));
		assert(sheet->temp[i].mem);
		sheet->temp[i].size = num_size;
	}
	return sheet;
}

static void cint_clear_sheet(cint_sheet *sheet) {
	for (size_t i = 0; i < sizeof(sheet->temp) / sizeof(*sheet->temp); ++i)
		free(sheet->temp[i].mem);
	free(sheet);
}

__attribute__((unused)) static uint64_t cint_checksum(const cint *num) {
	uint64_t sum = (0xc6a4a7935bd1e995ULL * num->nat ^ (num->end - num->mem)) * 0xff51afd7ed558ccdULL;
	for (h_cint_t *p = num->mem; p < num->end; ++p) // Apply a XorShift process.
		sum ^= *p, sum ^= sum >> 33, sum *= 0xff51afd7ed558ccdULL, sum ^= sum >> 33, sum *= 0xc4ceb9fe1a85ec53ULL, sum ^= sum >> 33;
	return sum;
}

__attribute__((unused)) static inline long long int cint_to_int(cint *num) {
	long long int res = 0;
	for (h_cint_t *p = num->end - 1; p >= num->mem; --p)
		res = (res << cint_exponent) + (long long int) *p;
	return res * num->nat;
}

__attribute__((unused)) static inline void cint_negate(cint *num) {
	num->nat *= 1 - ((num->mem != num->end) << 1);
}

static size_t cint_count_bits(const cint *num) {
	size_t res = 0;
	if (num->end != num->mem) {
		for (; *(num->end - 1) >> ++res;);
		res += (num->end - num->mem - 1) * cint_exponent;
	}
	return res;
}

static size_t cint_count_zeros(const cint *num) {
	// examine the binary representation of the number to count trailing zeros.
	size_t res = 0, i;
	h_cint_t *ptr;
	for (ptr = num->mem; ptr < num->end && !*ptr; ++ptr, res += cint_exponent);
	for (i = 0; !(*ptr >> i & 1); ++i);
	return res + i;
}

static inline int cint_compare_char(const cint *lhs, const char rhs) {
	// compare a cint with a simple number between -128 and 127
	const h_cint_t res = lhs->end <= lhs->mem + 1 ? *lhs->mem * lhs->nat - (h_cint_t)rhs : lhs->nat ;
	return (0 < res) - (res < 0);
}

static inline int h_cint_compare(const cint *lhs, const cint *rhs) {
	h_cint_t res = (h_cint_t) ((lhs->end - lhs->mem) - (rhs->end - rhs->mem));
	if (res == 0 && rhs->end != rhs->mem)
		for (const h_cint_t *l = lhs->end, *r = rhs->end; !(res = *--l - *--r) && l != lhs->mem;);
	return (0 < res) - (res < 0);
}

static inline int cint_compare(const cint *lhs, const cint *rhs) {
	// compare the sign first, then the data
	int res = (int) (lhs->nat - rhs->nat);
	if (res == 0) res = (int) lhs->nat * h_cint_compare(lhs, rhs);
	return res;
}

static void cint_init(cint *num, size_t bits, long long int val) {
	num->size = bits / cint_exponent;
	num->size += 8 - num->size % 4;
	num->end = num->mem = calloc(num->size, sizeof(*num->mem));
	assert(num->mem);
	if ((num->nat = 1 - ((val < 0) << 1)) < 0) val = -val;
	for (; val; *num->end++ = (h_cint_t) (val % cint_base), val /= cint_base);
}

static inline void cint_erase(cint *num) {
	num->nat = 1, num->end = memset(num->mem, 0, (size_t) (num->end - num->mem) * sizeof(h_cint_t));
}

static void cint_reinit(cint *num, long long int val) {
	// it's like an initialization, but there is no memory allocation here
	if (cint_erase(num), val < 0)
		num->nat = -1, val = -val;
	for (; val; *num->end = (h_cint_t) (val % cint_base), val /= cint_base, ++num->end);
}

static void cint_reinit_by_string(cint *num, const char *str, const int base) {
	cint_erase(num);
	for (; *str && memchr(cint_alpha, *str, base) == 0; num->nat *= 1 - ((*str++ == '-') << 1));
	for (h_cint_t *p; *str; *num->mem += (h_cint_t) ((char *) memchr(cint_alpha, *str++, base) - cint_alpha), num->end += *num->end != 0)
		for (p = num->end; --p >= num->mem; *(p + 1) += (*p *= base) >> cint_exponent, *p &= cint_mask);
	for (h_cint_t *p = num->mem; p < num->end; *(p + 1) += *p >> cint_exponent, *p++ &= cint_mask);
	num->end += *num->end != 0, num->mem != num->end || (num->nat = 1);
}

__attribute__((unused)) static inline void cint_init_by_string(cint *num, const size_t bits, const char *str, const int base) {
	cint_init(num, bits, 0), cint_reinit_by_string(num, str, base);
}

static void cint_reinit_by_double(cint *num, const double value) {
	// sometimes tested against Microsoft STL, it worked.
	cint_erase(num);
	uint64_t memory;
	memcpy(&memory, &value, sizeof(value));
	uint64_t ex = (memory << 1 >> 53) - 1023, m_1 = 1ULL << 52;
	if (ex < 1024) {
		h_cint_t m_2 = 1 << ex % cint_exponent;
		num->nat *= (value > 0) - (value < 0);
		num->end = 1 + num->mem + ex / cint_exponent;
		h_cint_t *n = num->end;
		for (*(n - 1) |= m_2; --n >= num->mem; m_2 = cint_base)
			for (; m_2 >>= 1;)
				if (m_1 >>= 1)
					*n |= m_2 * ((memory & m_1) != 0);
				else return;
	}
}

__attribute__((unused)) static double cint_to_double(const cint *num) {
	// sometimes tested, it worked.
	uint64_t memory = cint_count_bits(num) + 1022, m_write = 1ULL << 52, m_read = 1 << memory % cint_exponent;
	double res = 0;
	memory <<= 52;
	for (h_cint_t *n = num->end; --n >= num->mem; m_read = 1LL << cint_exponent)
		for (; m_read >>= 1;)
			if (m_write >>= 1)
				memory |= m_write * ((*n & m_read) != 0);
			else
				n = num->mem, m_read = 0;
	memcpy(&res, &memory, sizeof(memory));
	return (double) num->nat * res;
}

__attribute__((unused)) static inline void cint_init_by_double(cint *num, const size_t size, const double value) { cint_init(num, size, 0), cint_reinit_by_double(num, value); }

static void cint_dup(cint *to, const cint *from) {
	// duplicate number (no verification about overlapping or available memory, caller must check)
	const size_t b = from->end - from->mem, a = to->end - to->mem;
	memcpy(to->mem, from->mem, b * sizeof(h_cint_t));
	to->end = to->mem + b;
	to->nat = from->nat;
	if (b < a) memset(to->end, 0, (size_t) (a - b) * sizeof(h_cint_t));
}

static void cint_rescale(cint *num, const size_t bits) {
	// rarely tested, it should allow to resize a number transparently.
	size_t new_size = 1 + bits / cint_exponent;
	new_size = new_size + 8 - new_size % 8;
	const size_t curr_length = num->end - num->mem;
	if (num->size < new_size) {
		num->mem = realloc(num->mem, new_size * sizeof(h_cint_t));
		assert(num->mem);
		memset(num->mem + num->size, 0,(size_t) (new_size - num->size) * sizeof(h_cint_t));
		num->end = num->mem + curr_length;
		num->size = new_size;
	} else if (curr_length >= new_size) {
		cint_erase(num); // can't keep the number when reducing its size under the minimal size it needs.
		num->end = num->mem = realloc(num->mem, (num->size = new_size) * sizeof(h_cint_t));
		assert(num->mem); // realloc can fail on trimming.
	}
}

static inline cint *h_cint_tmp(cint_sheet *sheet, const int id, const cint *least) {
	// request at least the double of "least" to allow performing multiplication then modulo...
	const size_t needed_size = (1 + least->end - least->mem) << 1;
	if (sheet->temp[id].size < needed_size)
		cint_rescale(&sheet->temp[id], (1 + (cint_count_bits(least) >> 4)) << 5);
	return &sheet->temp[id];
}

static void h_cint_addi(cint *lhs, const cint *rhs) {
	// perform an addition (without caring of the sign)
	h_cint_t *l = lhs->mem;
	for (const h_cint_t *r = rhs->mem; r < rhs->end;)
		*l += *r++, *(l + 1) += *l >> cint_exponent, *l++ &= cint_mask;
	for (; *l & cint_base; *(l + 1) += *l >> cint_exponent, *l++ &= cint_mask);
	if (rhs->end - rhs->mem > lhs->end - lhs->mem)
		lhs->end = lhs->mem + (rhs->end - rhs->mem);
	lhs->end += *lhs->end != 0;
}

static void h_cint_subi(cint *lhs, const cint *rhs) {
	// perform a subtraction (without caring about the sign, it performs high subtract low)
	h_cint_t a = 0, cmp, *l, *r, *e, *o;
	if (lhs->mem == lhs->end)
		cint_dup(lhs, rhs);
	else if (rhs->mem != rhs->end) {
		cmp = h_cint_compare(lhs, rhs);
		if (cmp) {
			if (cmp < 0) l = lhs->mem, r = rhs->mem, e = rhs->end, lhs->nat = -lhs->nat;
			else l = rhs->mem, r = lhs->mem, e = lhs->end;
			for (o = lhs->mem; r < e; *o = *r++ - *l++ - a, a = (*o & cint_base) != 0, *o++ &= cint_mask);
			for (*o &= cint_mask, o += a; --o > lhs->mem && !*o;);
			lhs->end = 1 + o;
		} else cint_erase(lhs);
	}
}

// regular functions, they care of the input sign
static inline void cint_addi(cint *lhs, const cint *rhs) { lhs->nat == rhs->nat ? h_cint_addi(lhs, rhs) : h_cint_subi(lhs, rhs); }

static inline void cint_subi(cint *lhs, const cint *rhs) { lhs->nat == rhs->nat ? lhs->nat = -lhs->nat, h_cint_subi(lhs, rhs), lhs->mem == lhs->end || (lhs->nat = -lhs->nat), (void) 0 : h_cint_addi(lhs, rhs); }

static void cint_left_shifti(cint *num, const size_t bits) {
	// execute a left shift immediately over the input, for any amount of bits (no verification about available memory)
	if (num->end != num->mem) {
		const size_t a = bits / cint_exponent, b = bits % cint_exponent, c = cint_exponent - b;
		if (a) {
			memmove(num->mem + a, num->mem, (size_t) (num->end - num->mem + 1) * sizeof(h_cint_t));
			memset(num->mem, 0, a * sizeof(h_cint_t));
			num->end += a;
		}
		if (b) for (h_cint_t *l = num->end, *e = num->mem + a; --l >= e; *(l + 1) |= *l >> c, *l = *l << b & cint_mask);
		num->end += *(num->end) != 0;
	}
}

static void cint_right_shifti(cint *num, const size_t bits) {
	const size_t a = bits / cint_exponent, b = bits % cint_exponent, c = cint_exponent - b;
	if (num->mem + a < num->end) {
		if (a) {
			memmove(num->mem, num->mem + a, (size_t) (num->end - num->mem - a) * sizeof(h_cint_t));
			memset(num->end -= a, 0, a * sizeof(h_cint_t));
		}
		if (b) for (h_cint_t *l = num->mem; l < num->end; *l = (*l >> b | *(l + 1) << c) & cint_mask, ++l);
		if (num->mem < num->end) num->end -= *(num->end - 1) == 0, num->end == num->mem && (num->nat = 1);
	} else cint_erase(num);
}

static void cint_mul(const cint *lhs, const cint *rhs, cint *res) {
	// the multiplication (longhand method)
	h_cint_t *l, *r, *o, *p;
	cint_erase(res);
	if (lhs->mem != lhs->end && rhs->mem != rhs->end) {
		res->nat = lhs->nat * rhs->nat, res->end += (lhs->end - lhs->mem) + (rhs->end - rhs->mem) - 1;
		for (l = lhs->mem, p = res->mem; l < lhs->end; ++l)
			for (r = rhs->mem, o = p++; r < rhs->end; *(o + 1) += (*o += *l * *r++) >> cint_exponent, *o++ &= cint_mask);
		res->end += *res->end != 0;
	}
}

static void cint_powi(cint_sheet *sheet, cint *n, const cint *exp) {
	// read the exponent bit by bit to perform the "fast" exponentiation in place.
	if (n->mem != n->end) {
		size_t bits = cint_count_bits(exp);
		switch (bits) {
			case 0 : cint_reinit(n, n->mem != n->end); break;
			case 1 : break;
			default:;
				cint *a = h_cint_tmp(sheet, 0, n);
				cint *b = h_cint_tmp(sheet, 1, n), *res = n, *tmp;
				cint_erase(a), *a->end++ = 1;
				h_cint_t mask = 1;
				for (const h_cint_t *ptr = exp->mem;;) {
					if (*ptr & mask)
						cint_mul(a, n, b), tmp = a, a = b, b = tmp;
					if (--bits) {
						cint_mul(n, n, b), tmp = n, n = b, b = tmp;
						mask <<= 1;
						if (mask == cint_base) mask = 1, ++ptr;
					} else break;
				}
				if (res != a) cint_dup(res, a);
		}
	}
}

static inline void cint_pow(cint_sheet *sheet, const cint *n, const cint *exp, cint *res) {
	cint_dup(res, n);
	cint_powi(sheet, res, exp);
}

__attribute__((unused)) static void cint_binary_div(const cint *lhs, const cint *rhs, cint *q, cint *r) {
	// the original division algorithm, it doesn't take any temporary variable.
	cint_erase(r);
	if (rhs->end == rhs->mem)
		for (q->nat = lhs->nat * rhs->nat, q->end = q->mem; q->end < q->mem + q->size; *q->end++ = cint_mask); // DBZ
	else {
		h_cint_t a = h_cint_compare(lhs, rhs);
		if (a) {
			cint_erase(q);
			if (a > 0) {
				h_cint_t *l = lhs->end, *k, *qq = q->mem + (lhs->end - lhs->mem);
				for (; --qq, --l >= lhs->mem;)
					for (a = cint_base; a >>= 1;) {
						for (k = r->end; --k >= r->mem; *(k + 1) |= (*k <<= 1) >> cint_exponent, *k &= cint_mask);
						*r->mem += (a & *l) != 0, r->end += *r->end != 0;
						h_cint_compare(r, rhs) >= 0 ? h_cint_subi(r, rhs), *qq |= a : 0;
					}
				q->end += (lhs->end - lhs->mem) - (rhs->end - rhs->mem), q->end += *q->end != 0;
				q->nat = rhs->nat * lhs->nat, (r->end == r->mem) || (r->nat = lhs->nat); // lhs = q * rhs + r
			} else cint_dup(r, lhs);
		} else cint_reinit(q, rhs->nat * lhs->nat);
	}
}

static void h_cint_div_approx(const cint *lhs, const cint *rhs, cint *res) {
	// the division approximation algorithm (answer isn't always exact)
	h_cint_t x, bits = h_cint_compare(lhs, rhs), *o = rhs->end, *p;
	if (bits == 0)
		cint_erase(res), *res->end++ = 1, res->nat = lhs->nat * rhs->nat;
	else if (bits < 0)
		cint_erase(res);
	else {
		cint_dup(res, lhs);
		res->nat *= rhs->nat;
		x = *--o, --o < rhs->mem || (x = x << cint_exponent | *o);
		for (bits = 0; cint_mask < x; x >>= 1, ++bits);
		cint_right_shifti(res, (rhs->end - rhs->mem - 1) * cint_exponent + (bits > 0) * (bits - cint_exponent));
		p = res->end - 3 > res->mem ? res->end - 3 : res->mem;
		for (o = res->end; --o > p; *(o - 1) += (*o % x) << cint_exponent, *o /= x);
		*o /= x;
		res->end -= *(res->end - 1) == 0;
	}
}

static void cint_div(cint_sheet *sheet, const cint *lhs, const cint *rhs, cint *q, cint *r) {
	// The combined division algorithm, it uses the approximation algorithm, "fast" with small inputs.
	// When the function terminates, it must guarantee: lhs = rhs * q + r.
	assert(rhs->mem != rhs->end);
	cint_erase(q);
	const int cmp = h_cint_compare(lhs, rhs);
	if (cmp < 0)
		cint_dup(r, lhs);
	else if (cmp) {
		if (lhs->end < lhs->mem + 3 && rhs->end < rhs->mem + 3) {
			// System native division.
			cint_erase(r);
			const h_cint_t a = *lhs->mem | *(lhs->mem + 1) << cint_exponent, b = *rhs->mem | *(rhs->mem + 1) << cint_exponent;
			*q->mem = a / b, *r->mem = a % b;
			if (*q->mem & ~cint_mask) { *++q->end = *q->mem >> cint_exponent, *q->mem &= cint_mask; }
			q->end += *q->end != 0;
			if (*r->mem & ~cint_mask) { *++r->end = *r->mem >> cint_exponent, *r->mem &= cint_mask; }
			r->end += *r->end != 0;
		} else if (rhs->end == rhs->mem + 1) {
			// Special cased "divide by a single word".
			cint_erase(r);
			h_cint_t *x = q->end = q->mem + (lhs->end - lhs->mem);
			for(h_cint_t * p = lhs->end - 1; p >= lhs->mem; --p){
				h_cint_t combined = *r->mem << cint_exponent | *p ;
				*--x = combined / *rhs->mem ;
				*r->mem = combined % *rhs->mem ;
			}
			q->end -= !*(q->end - 1);
			r->end += *r->mem != 0 ;
		} else {
			// Regular division for larger numbers.
			cint *a = h_cint_tmp(sheet, 0, lhs), *b = h_cint_tmp(sheet, 1, lhs);
			cint_dup(r, lhs);
			for (; h_cint_div_approx(r, rhs, b), b->mem != b->end;)
				cint_addi(q, b), cint_mul(b, rhs, a), h_cint_subi(r, a);
			if (r->end != r->mem && r->nat != lhs->nat) // lhs = q * rhs + r
				cint_reinit(b, q->nat), h_cint_subi(q, b), h_cint_subi(r, rhs);
		}
	} else cint_erase(r), *q->end++ = 1;
	if (lhs->nat != rhs->nat && q->mem != q->end)
		q->nat = -1; // Sign of the quotient.
	if (r->mem != r->end)
		r->nat = lhs->nat; // Sign of the remainder.
}

static inline size_t cint_approx_bits_from_digits(const size_t digits, const int base) {
	// approximate the number of bits for a given number of digits
	static const unsigned char logs[] = {252, 200, 172, 154, 142, 133, 126, 120, 115, 111, 108, 105, 102, 100, 97, 95, 94, 92, 91, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 80, 79, 78, 77, 77, 76, 76, 75, 75, 74, 74, 73, 73, 72, 72, 72, 71, 71, 70, 70, 70, 69, 69, 69, 68, 68, 68, 67, 67, 67, 67};
	return base == 2 ? digits : 1 + digits * 400 / logs[base - 3];
}

static inline size_t cint_approx_digits_from_bits(const size_t bits, const int base){
	// approximate the number of digits for a given number of bits (suitable to malloc)
	static const unsigned char logs[] = {40, 63, 80, 92, 103, 112, 120, 126, 132, 138, 143, 148, 152, 156, 160, 163, 166, 169, 172, 175, 178, 180, 183, 185, 188, 190, 192, 194, 196, 198, 200, 201, 203, 205, 206, 208, 209, 211, 212, 214, 215, 217, 218, 219, 220, 222, 223, 224, 225, 226, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238};
	return 3 + bits * 40 / logs[base - 2]; // including a byte for the sign.
}

static char *cint_to_string_buffer(const cint *num, char * buf, const int base) {
	// write the string representation of the given number into a provided buffer.
	assert(buf);
	h_cint_t a, b, *c = num->end;
	size_t d, e = 1;
	char *s = buf;
	if (num->nat < 0)
		*s++ = '-';
	*s++ = '0';
	for (*s-- = 0; --c >= num->mem;) {
		for (a = *c, d = e; d;) {
			b = (h_cint_t) ((char *) memchr(cint_alpha, s[--d], base) - cint_alpha), b = b * cint_base + a;
			s[d] = cint_alpha[b % base];
			a = b / base;
		}
		for (; a; memmove(s + 1, s, ++e), *s = cint_alpha[a % base], a /= base);
	}
	return buf;
}

__attribute__((unused)) static inline char *cint_to_string(const cint *num, const int base) {
	char *mem = malloc(cint_approx_digits_from_bits(cint_count_bits(num), base));
	assert(mem); // Allocate a string to represent the number in the given base.
	return cint_to_string_buffer(num, mem, base);
}

__attribute__((unused)) static char *cint_to_string_buffer_alt(cint_sheet *sheet, const cint *num, char * buf, const int base) {
	// designed for verifications, the two methods that output a number (negative, zero or positive)
	// to a string are independent and must always provide the same output for bases 2 to 62.
	assert(buf);
	if (num->mem == num->end)
		*buf = '0', *(buf + 1) = 0;
	else {
		cint *A = h_cint_tmp(sheet, 3, num), *B = h_cint_tmp(sheet, 4, num), *C = h_cint_tmp(sheet, 5, num), *D = h_cint_tmp(sheet, 6, num), *TMP;
		cint_dup(A, num);
		cint_reinit(B, base);
		char * end = buf ;
		while (A->mem != A->end) {
			cint_div(sheet, A, B, C, D);
			*end++ = cint_alpha[*D->mem];
			TMP = A, A = C, C = TMP;
		}
		if (num->nat < 0)
			*end++ = '-';
		*end = 0;
		for (char t, *z = buf; z < --end; t = *z, *z++ = *end, *end = t);
	}
	return buf;
}

__attribute__((unused)) static inline char *cint_to_string_alt(cint_sheet *sheet, const cint *num, const int base) {
	char *mem = malloc(cint_approx_digits_from_bits(cint_count_bits(num), base));
	assert(mem); // Allocate a string to represent the number in the given base.
	return cint_to_string_buffer_alt(sheet, num, mem, base);
}

__attribute__((unused)) static inline void cint_mul_mod(cint_sheet *sheet, const cint *lhs, const cint *rhs, const cint *mod, cint *res) {
	cint *a = h_cint_tmp(sheet, 2, res), *b = h_cint_tmp(sheet, 3, res);
	cint_mul(lhs, rhs, a);
	cint_div(sheet, a, mod, b, res);
}

static inline void cint_mul_modi(cint_sheet *sheet, cint *lhs, const cint *rhs, const cint *mod) {
	cint *a = h_cint_tmp(sheet, 2, lhs), *b = h_cint_tmp(sheet, 3, lhs);
	cint_mul(lhs, rhs, a);
	cint_div(sheet, a, mod, b, lhs);
}

static inline void cint_pow_modi(cint_sheet *sheet, cint *n, const cint *exp, const cint *mod) {
	// same as "power" algorithm, difference is that it take the modulo as soon as possible.
	if (n->mem != n->end) {
		size_t bits = cint_count_bits(exp);
		switch (bits) {
			case 0 :
				cint_reinit(n, n->mem != n->end);
				break;
			case 1 :
				break;
			default:;
				cint *a = h_cint_tmp(sheet, 2, n);
				cint *b = h_cint_tmp(sheet, 3, n);
				cint *c = h_cint_tmp(sheet, 4, n);
				cint_erase(a), *a->end++ = 1;
				h_cint_t mask = 1;
				for (const h_cint_t *ptr = exp->mem;;) {
					if (*ptr & mask)
						cint_mul(a, n, b), cint_div(sheet, b, mod, c, a);
					if (--bits) {
						cint_mul(n, n, b), cint_div(sheet, b, mod, c, n);
						mask <<= 1;
						if (mask == cint_base) mask = 1, ++ptr;
					} else break;
				}
				cint_dup(n, a);
		}
	}
}

__attribute__((unused)) static void cint_pow_mod(cint_sheet *sheet, const cint *n, const cint *exp, const cint *mod, cint *res) {
	cint_dup(res, n);
	cint_pow_modi(sheet, res, exp, mod);
}

static void cint_gcd(cint_sheet *sheet, const cint *lhs, const cint *rhs, cint *gcd) {
	// the basic GCD algorithm, by frontal divisions.
	if (rhs->mem == rhs->end)
		cint_dup(gcd, lhs), gcd->nat = 1;
	else {
		cint *A = h_cint_tmp(sheet, 2, lhs),
				*B = h_cint_tmp(sheet, 3, lhs),
				*C = h_cint_tmp(sheet, 4, lhs),
				*TMP, *RES = gcd;
		cint_dup(gcd, lhs);
		cint_dup(A, rhs);
		gcd->nat = A->nat = 1;
		for (; A->mem != A->end;) {
			cint_div(sheet, gcd, A, B, C);
			TMP = gcd, gcd = A, A = C, C = TMP;
		}
		gcd->nat = 1;
		if (RES != gcd) cint_dup(RES, gcd);
	}

}

__attribute__((unused)) static void cint_binary_gcd(cint_sheet *sheet, const cint *lhs, const cint *rhs, cint *gcd) {
	// a binary GCD algorithm.
	if (lhs->mem == lhs->end) cint_dup(gcd, rhs);
	else if (rhs->mem == rhs->end) cint_dup(gcd, lhs);
	else {
		cint *tmp = h_cint_tmp(sheet, 0, lhs),
				*swap, *res = gcd;
		cint_dup(gcd, lhs), gcd->nat = 1;
		cint_dup(tmp, rhs), tmp->nat = 1;
		const size_t a = cint_count_zeros(lhs), b = cint_count_zeros(rhs);
		for (size_t c = a > b ? b : a;; cint_right_shifti(tmp, cint_count_zeros(tmp))) {
			if (h_cint_compare(gcd, tmp) > 0)
				swap = gcd, gcd = tmp, tmp = swap;
			h_cint_subi(tmp, gcd);
			if (tmp->mem == tmp->end) {
				if (res != gcd)
					cint_dup(res, gcd);
				cint_left_shifti(res, c);
				break;
			}
		}
	}
}

static unsigned cint_remove(cint_sheet *sheet, cint *N, const cint *F) {
	// remove all occurrences of the factor from the input, and return the count.
	size_t res = 0;
	if (N->end != N->mem && F->end != F->mem)
		switch ((*N->mem == 1 && N->end == N->mem + 1) | (*F->mem == 1 && F->end == F->mem + 1) << 1) {
			case 1 :
				break; // it asks remove other than [-1, 1] but N is [-1, 1].
			case 2 : // it asks remove [-1, 1], so remove one occurrence if N != 0.
			case 3 :
				res = N->mem != N->end;
				if (res) N->nat *= F->nat;
				break;
			default:;
				cint *A = h_cint_tmp(sheet, 2, N), *B = h_cint_tmp(sheet, 3, N);
				// divides N by the factor until there is a remainder
				for (cint *tmp; cint_div(sheet, N, F, A, B), B->mem == B->end; tmp = N, N = A, A = tmp, ++res);
				if (res & 1) cint_dup(A, N);
		}
	return res;
}

static void cint_sqrt(cint_sheet *sheet, const cint *num, cint *res, cint *rem) {
	// original square root algorithm.
	cint_erase(res), cint_dup(rem, num); // answer ** 2 + rem = num
	if (num->nat > 0 && num->end != num->mem) {
		cint *a = h_cint_tmp(sheet, 0, num), *b = h_cint_tmp(sheet, 1, num);
		cint_erase(a), *a->end++ = 1;
		cint_left_shifti(a, cint_count_bits(num) & ~1);
		for (; a->mem != a->end;) {
			cint_dup(b, res);
			h_cint_addi(b, a);
			cint_right_shifti(res, 1);
			if (h_cint_compare(rem, b) >= 0)
				h_cint_subi(rem, b), h_cint_addi(res, a);
			cint_right_shifti(a, 2);
		}
	}
}

static void cint_cbrt(cint_sheet *sheet, const cint *num, cint *res, cint *rem) {
	// original cube root algorithm.
	cint_erase(res), cint_dup(rem, num); // answer ** 3 + rem = num
	if (num->mem != num->end) {
		cint *a = h_cint_tmp(sheet, 0, num), *b = h_cint_tmp(sheet, 1, num);
		for (size_t c = cint_count_bits(num) / 3 * 3; c < -1U; c -= 3) {
			cint_left_shifti(res, 1);
			cint_dup(a, res);
			cint_left_shifti(a, 1);
			h_cint_addi(a, res);
			cint_mul(a, res, b);
			++*b->mem; // "b" isn't "normalized", it should work for an addition.
			h_cint_addi(b, a);
			cint_dup(a, rem);
			cint_right_shifti(a, c);
			if (h_cint_compare(a, b) >= 0)
				cint_left_shifti(b, c), h_cint_subi(rem, b), cint_erase(b), *b->end++ = 1, h_cint_addi(res, b);
		}
		res->nat = num->nat;
	}
}

static void cint_nth_root(cint_sheet *sheet, const cint *num, const unsigned nth, cint *res) {
	// original nth-root algorithm, it does not try to decompose "nth" into prime factors.
	switch (nth) {
		case 0 : cint_reinit(res, num->end == num->mem + 1 && *num->mem == 1); break;
		case 1 : cint_dup(res, num); break;
		case 2 : cint_sqrt(sheet, num, res, h_cint_tmp(sheet, 2, num)); break;
		case 3 : cint_cbrt(sheet, num, res, h_cint_tmp(sheet, 2, num)); break;
		default:
			if (num->end > num->mem + 1 || *num->mem > 1) {
				cint *a = h_cint_tmp(sheet, 2, num),
						*b = h_cint_tmp(sheet, 3, num),
						*c = h_cint_tmp(sheet, 4, num),
						*d = h_cint_tmp(sheet, 5, num),
						*e = h_cint_tmp(sheet, 6, num), *r = res, *tmp;
				cint_erase(a), *a->end++ = 1, cint_erase(d), *d->end++ = 1;
				cint_left_shifti(a, (cint_count_bits(num) + nth - 1) / nth);
				h_cint_addi(r, d), cint_reinit(d, nth - 1), cint_reinit(e, nth);
				do {
					tmp = a, a = r, r = tmp, cint_dup(a, num);
					for (unsigned count = nth; --count && (cint_div(sheet, a, r, b, c), tmp = a, a = b, b = tmp, a->mem != a->end););
					cint_mul(r, d, b);
					h_cint_addi(b, a);
					cint_div(sheet, b, e, a, c);
				} while (h_cint_compare(a, r) < 0);
				r == res ? (void) 0 : cint_dup(res, tmp == a ? a : r);
				res->nat = nth & 1 ? num->nat : 1;
			} else cint_dup(res, num);
	}
}

static void cint_nth_root_remainder(cint_sheet *sheet, const cint *num, const unsigned nth, cint *res, cint *rem) {
	// nth-root algorithm don't provide the remainder, so here it computes the remainder.
	if (nth == 2) cint_sqrt(sheet, num, res, rem);
	else if (nth == 3) cint_cbrt(sheet, num, res, rem);
	else {
		cint_nth_root(sheet, num, nth, res);
		cint *a = h_cint_tmp(sheet, 2, num);
		cint_reinit(a, nth);
		cint_pow(sheet, res, a, rem);
		cint_subi(rem, num);
	}
}

static void cint_random_bits(cint *num, size_t bits, uint64_t * seed) {
	// provide a positive random number having exactly the requested number of bits.
	// the pseudorandom number generator (PRNG) seed is updated at every call.
	cint_erase(num);
	uint64_t *r = *seed ? seed : (*seed = 0x2236b69a7d223bd, seed);
	for (const size_t exp = cint_exponent; exp < bits; bits -= exp)
		*num->end++ = (h_cint_t) ((*r ^= *r << 13, *r ^= *r >> 7, *r ^= *r << 17) & cint_mask);
	if (bits) {
		*r ^= *r << 3, *r ^= *r >> 1, *r ^= *r << 11;
		*num->end++ |= 1 << (bits - 1) | (h_cint_t) (*r & cint_mask) >> (cint_exponent - bits);
	}
}

static void cint_modular_inverse(cint_sheet *sheet, const cint *lhs, const cint *rhs, cint *res) {
	// original modular inverse algorithm, answer is also called "u1" in extended Euclidean algorithm context.
	if (*rhs->mem > 1 || rhs->end > rhs->mem + 1) {
		cint *a = h_cint_tmp(sheet, 2, rhs),
				*b = h_cint_tmp(sheet, 3, rhs),
				*c = h_cint_tmp(sheet, 4, rhs),
				*d = h_cint_tmp(sheet, 5, rhs),
				*e = h_cint_tmp(sheet, 6, rhs),
				*f = h_cint_tmp(sheet, 7, rhs), *tmp, *out = res;
		cint_dup(a, lhs), cint_dup(b, rhs), cint_erase(res), *res->end++ = 1, cint_erase(e);
		a->nat = b->nat = 1;
		int i = 0;
		do {
			cint_div(sheet, a, b, c, d);
			cint_mul(c, e, f);
			cint_dup(c, res);
			cint_subi(c, f);
			tmp = a, a = b, b = d, d = tmp;
			tmp = res, res = e, e = c, c = tmp;
		} while (++i, (d->mem == d->end) == (b->mem == b->end));
		if (a->end == a->mem + 1 && *a->mem == 1) {
			if (i & 1) cint_addi(res, e);
		} else cint_erase(res);
		if (out != res) cint_dup(out, res);
	} else cint_erase(res);
}

int cint_is_prime(cint_sheet *sheet, const cint *N, int iterations, uint64_t * seed) {
	// is N is considered as a prime number ? the function returns 0 or 1.
	// when the number of Miller-Rabin iterations is zero, it's automatic.
	int res;
	if (0 < N->nat && *N->mem < 961 && N->mem + 1 >= N->end) {
		int n = (int) *N->mem; // Small numbers for which Miller-Rabin is not used.
		res = (n > 1) & ((n < 6) * 42 + 0x208A2882) >> n % 30 && (n < 49 || (n % 7 && n % 11 && n % 13 && n % 17 && n % 19 && n % 23 && n % 29));
	} else if (res = 0 < N->nat && (*N->mem & 1) != 0, res) {
		cint *A = h_cint_tmp(sheet, 5, N),
				*B = h_cint_tmp(sheet, 6, N),
				*C = h_cint_tmp(sheet, 7, N);
		size_t a, b, bits = cint_count_bits(N), rand_mod = bits - 3;
		if (iterations <= 0)
			// decides the number of Miller-Rabin iterations for the caller ...
			iterations = bits < 150 ? 24 : bits < 200 ? 18 : bits < 250 ? 16 : bits < 300 ? 13 : bits < 350 ? 10 : bits < 400 ? 9 : bits < 450 ? 8 : bits < 550 ? 7 : bits < 650 ? 6 : bits < 850 ? 5 : bits < 1300 ? 4 : 3 ;
		cint_dup(A, N);
		cint_erase(B), *B->end++ = 1;
		cint_subi(A, B);
		cint_dup(C, A); // C = (N - 1)
		cint_right_shifti(C, a = cint_count_zeros(C)); // divides C by 2 until C is odd
		for (bits = 2; iterations-- && res;) {
			cint_random_bits(B, bits, seed); // take a number
			bits = 3 + *B->mem % rand_mod;
			cint_pow_modi(sheet, B, C, N); // raise to the power C mod N
			if (*B->mem != 1 || B->end != B->mem + 1) {
				for (b = a; b-- && (res = h_cint_compare(A, B));)
					cint_mul_modi(sheet, B, B, N);
				res = !res;
			} // only a prime number can hold (res = 1) forever
		}
	}
	return res;
}

#endif
