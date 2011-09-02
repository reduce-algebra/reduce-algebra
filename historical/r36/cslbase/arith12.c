/*  arith12.c                         Copyright (C) 1990-94 Codemist Ltd */

/*
 * Arithmetic functions... specials for Reduce (esp. factoriser)
 *
 */

/* Signature: 4047a73b 16-Oct-1997 */

#define FP_EVALUATE   1

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "entries.h"
#ifdef TIMEOUT
#include "timeout.h"
#endif


Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a)
{
    double d;
    int x;
    d = float_of_number(a);
    d = frexp(d, &x);
    if (d == 1.0) d = 0.5, x++;
    a = make_boxfloat(d, TYPE_DOUBLE_FLOAT);
    errexit();
    return Lcons(nil, fixnum_of_int((int32)x), a);
}

Lisp_Object Lmodular_difference(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 r;
    CSL_IGNORE(nil);
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < 0) r += current_modulus;
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Lmodular_minus(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (a != fixnum_of_int(0))
    {   int32 r = current_modulus - int_of_fixnum(a);
        a = fixnum_of_int(r);
    }
    return onevalue(a);
}

Lisp_Object Lmodular_number(Lisp_Object nil, Lisp_Object a)
{
    int32 r;
    a = Cremainder(a, fixnum_of_int(current_modulus));
    errexit();
    r = int_of_fixnum(a);
    if (r < 0) r += current_modulus;
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Lmodular_plus(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 r;
    CSL_IGNORE(nil);
    r = int_of_fixnum(a) + int_of_fixnum(b);
    if (r >= current_modulus) r -= current_modulus;
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Lmodular_reciprocal(Lisp_Object nil, Lisp_Object n)
{
    int32 a, b, x, y;
    CSL_IGNORE(nil);
    a = current_modulus;
    b = int_of_fixnum(n);
    x = 0;
    y = 1;
    if (b == 0) return aerror1("modular-reciprocal", n);
    while (b != 1)
    {   int32 w = a / b;
        int32 t = b;
        b = a - b*w;
        a = t;
        t = y;
        y = x - y*w;
        x = t;
    }
    if (y < 0) y += current_modulus;
    return onevalue(fixnum_of_int(y));
}

Lisp_Object Lmodular_times(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    unsigned32 h, l, r, cm;
    int32 aa, bb;
    CSL_IGNORE(nil);
    cm = (unsigned32)current_modulus;
    aa = int_of_fixnum(a);
    bb = int_of_fixnum(b);
/*
 * The constant 46341 is sqrt(2^31) suitable rounded - if my modulus
 * is no bigger than that then a and b will both be strictly smaller,
 * and hence a*b will be < 2^31 and hence in range for 32-bit signed
 * arithmetic.  I make this test because I expect Imultiply and Idivide
 * to be pretty painful, while regular C multiplication and division are
 * (probably!) much better.
 */
    if (cm <= 46341U) r = (aa * bb) % cm;
    else
    {
#ifdef MULDIV64
        r = (unsigned32)(((unsigned64)aa * (unsigned64)bb) % (unsigned32)cm);
#else
        Dmultiply(h, l, aa, bb, 0);
        Ddivide(r, l, h, l, cm);
#endif
    }
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Lmodular_quotient(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    push(a);
    b = Lmodular_reciprocal(nil, b);
    pop(a);
    errexit();
    return Lmodular_times(nil, a, b);
}

Lisp_Object Lmodular_expt(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 x, r, p;
    unsigned32 h, l;
    CSL_IGNORE(nil);
    x = int_of_fixnum(b);
    if (x == 0) return onevalue(fixnum_of_int(1));
    p = int_of_fixnum(a);
/*
 * I could play games here on half-length current_modulus and use
 * native C arithmetic, but I judge this case not to be quite that
 * critically important. Also on 64-bit machines I could do more
 * work in-line.
 */
    p = p % current_modulus; /* In case somebody is being silly! */
    while ((x & 1) == 0)
    {   Dmultiply(h, l, p, p, 0);
        Ddivide(p, l, h, l, current_modulus);
        x = x/2;
    }
    r = p;
    while (x != 1)
    {   Dmultiply(h, l, p, p, 0);
        Ddivide(p, l, h, l, current_modulus);
        x = x/2;
        if ((x & 1) != 0)
        {   Dmultiply(h, l, r, p, 0);
            Ddivide(r, l, h, l, current_modulus);
        }
    }
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Lset_small_modulus(Lisp_Object nil, Lisp_Object a)
{
    int32 r, old = current_modulus;
    CSL_IGNORE(nil);
    if (!is_fixnum(a)) return aerror1("set-small-modulus", a);
    r = int_of_fixnum(a);
/*
 * I COULD allow a small modulus of up to 2^27, but for compatibility
 * with Cambridge Lisp I will limit myself to 24 bits.
 */
    if (r > 0x00ffffff) return aerror1("set-small-modulus", a);
    current_modulus = r;
    return onevalue(fixnum_of_int(old));
}

Lisp_Object Liadd1(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a)) return aerror1("iadd1", a);
    return onevalue((Lisp_Object)((int32)a + 0x10));
}

Lisp_Object Lidifference(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("idifference", a, b);
    return onevalue((Lisp_Object)((int32)a - (int32)b + TAG_FIXNUM));
}

/*
 * xdifference is provided just for the support of the CASE operator. It
 * subtracts its arguments but returns NIL if either argument is not
 * an small integer or if the result overflows.
 */

Lisp_Object Lxdifference(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 r;
    if (!is_fixnum(a) || !is_fixnum(b)) return onevalue(nil);
    r = int_of_fixnum(a) - int_of_fixnum(b);
    if (r < -0x08000000 || r > 0x07ffffff) return onevalue(nil);
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Ligreaterp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igreaterp", a, b);
    return onevalue(Lispify_predicate(a > b));
}

Lisp_Object Lilessp(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilessp", a, b);
    return onevalue(Lispify_predicate(a < b));
}

Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("igeq", a, b);
    return onevalue(Lispify_predicate(a >= b));
}

Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ileq", a, b);
    return onevalue(Lispify_predicate(a <= b));
}

static Lisp_Object MS_CDECL Lilogand(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    if (nargs == 0) return onevalue(fixnum_of_int(-1));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogand");
    CSL_IGNORE(nil);
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (!is_fixnum(r)) return aerror1("ilogand", r);
    while (--nargs != 0)
    {   Lisp_Object w = va_arg(a, Lisp_Object);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogand", w);
        }
        r = (Lisp_Object)((int32)r & (int32)w);
    }
    va_end(a);
    return onevalue(r);
}

static Lisp_Object MS_CDECL Lilogor(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogor");
    CSL_IGNORE(nil);
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (!is_fixnum(r)) return aerror1("ilogor", r);
    while (--nargs != 0)
    {   Lisp_Object w = va_arg(a, Lisp_Object);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogor", w);
        }
        r = (Lisp_Object)((int32)r | (int32)w);
    }
    va_end(a);
    return onevalue(r);
}

static Lisp_Object MS_CDECL Lilogxor(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for ilogxor");
    CSL_IGNORE(nil);
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (!is_fixnum(r)) return aerror1("ilogxor", r);
    while (--nargs != 0)
    {   Lisp_Object w = va_arg(a, Lisp_Object);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("ilogxor", w);
        }
        r = (Lisp_Object)(((int32)r ^ (int32)w) + TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

static Lisp_Object Lilogand2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogand", a, b);
    return onevalue(a & b);    
}

static Lisp_Object Lilogor2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogor", a, b);
    return onevalue(a | b);    
}

static Lisp_Object Lilogxor2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("ilogxor", a, b);
    return onevalue((a ^ b) + TAG_FIXNUM);    
}

Lisp_Object Limin(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imin", a, b);
    return onevalue(a < b ? a : b);
}

Lisp_Object Limax(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("imax", a, b);
    return onevalue(a > b ? a : b);
}

Lisp_Object Liminus(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a)) return aerror1("iminus", a);
    return onevalue((Lisp_Object)(2*TAG_FIXNUM - (int32)a));
}

Lisp_Object Liminusp(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(Lispify_predicate((int32)a < (int32)fixnum_of_int(0)));
}

static Lisp_Object MS_CDECL Liplus(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object r;
    if (nargs == 0) return onevalue(fixnum_of_int(0));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for iplus");
    CSL_IGNORE(nil);
    va_start(a, nargs);
    r = va_arg(a, Lisp_Object);
    if (!is_fixnum(r)) return aerror1("iplus", r);
    while (--nargs != 0)
    {   Lisp_Object w = va_arg(a, Lisp_Object);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("iplus", w);
        }
        r = (Lisp_Object)((int32)r + (int32)w - TAG_FIXNUM);
    }
    va_end(a);
    return onevalue(r);
}

Lisp_Object Liplus2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("iplus2", a, b);
    return onevalue((Lisp_Object)((int32)a + (int32)b - TAG_FIXNUM));
}

Lisp_Object Liquotient(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 aa, bb, c;
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) return aerror2("iquotient", a, b);
/* C does not define the exact behaviour of /, % on -ve args */
    aa = int_of_fixnum(a);
    bb = int_of_fixnum(b);
    c = aa % bb;
    if (aa < 0)
    {   if (c > 0) c -= bb;
    }
    else if (c < 0) c += bb;
    return onevalue(fixnum_of_int((aa-c)/bb));
}

Lisp_Object Liremainder(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    int32 aa, bb, c;
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b) ||
        b == fixnum_of_int(0)) return aerror2("iremainder", a, b);
/* C does not define the exact behaviour of /, % on -ve args */
    aa = int_of_fixnum(a);
    bb = int_of_fixnum(b);
    c = aa % bb;
    if (aa < 0)
    {   if (c > 0) c -= bb;
    }
    else if (c < 0) c += bb;
    return onevalue(fixnum_of_int(c));
}

Lisp_Object Lirightshift(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("irightshift", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) >> int_of_fixnum(b)));
}

Lisp_Object Lisub1(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a)) return aerror1("isub1", a);
    return onevalue((Lisp_Object)((int32)a - 0x10));
}

static Lisp_Object MS_CDECL Litimes(Lisp_Object nil, int nargs, ...)
{
    va_list a;
    Lisp_Object rr;
    int32 r;
    if (nargs == 0) return onevalue(fixnum_of_int(1));
    if (nargs > ARG_CUT_OFF) return aerror("too many args for itimes");
    CSL_IGNORE(nil);
    va_start(a, nargs);
    rr = va_arg(a, Lisp_Object);
    if (!is_fixnum(rr)) return aerror1("itimes", rr);
    r = int_of_fixnum(rr);
    while (nargs-- != 0)
    {   Lisp_Object w = va_arg(a, Lisp_Object);
        if (!is_fixnum(w))
        {   va_end(a);
            return aerror1("itimes", w);
        }
        r = r * int_of_fixnum(w);
    }
    va_end(a);
    return onevalue(fixnum_of_int(r));
}

Lisp_Object Litimes2(Lisp_Object nil, Lisp_Object a, Lisp_Object b)
{
    CSL_IGNORE(nil);
    if (!is_fixnum(a) || !is_fixnum(b)) return aerror2("itimes2", a, b);
    return onevalue(fixnum_of_int(int_of_fixnum(a) * int_of_fixnum(b)));
}

Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(Lispify_predicate((int32)a == (int32)fixnum_of_int(1)));
}

Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a)
{
    CSL_IGNORE(nil);
    return onevalue(Lispify_predicate((int32)a == (int32)fixnum_of_int(0)));
}

#ifdef FP_EVALUATE

static double fp_args[32];
static double fp_stack[16];

/* codes 0 to 31 just load up arguments */
#define FP_RETURN        32
#define FP_PLUS          33
#define FP_DIFFERENCE    34
#define FP_TIMES         35
#define FP_QUOTIENT      36
#define FP_MINUS         37
#define FP_SQUARE        38
#define FP_CUBE          39
#define FP_SIN           40
#define FP_COS           41
#define FP_TAN           42
#define FP_EXP           43
#define FP_LOG           44
#define FP_SQRT          45


static Lisp_Object Lfp_eval(Lisp_Object nil, Lisp_Object code,
                                             Lisp_Object args)
/*
 * The object of this code is to support fast evaluation of numeric
 * expressions.  The first argument is a vector of byte opcodes, while
 * the second arg is a list of floating point values whose value will (or
 * at least may) be used.  There are at most 32 values in this list.
 */
{
    int n = 0;
    double w;
    unsigned char *p;
    if (!is_vector(code)) return aerror("fp-evaluate");
    while (consp(args))
    {   fp_args[n++] = float_of_number(qcar(args));
        args = qcdr(args);
    }
    n = 0;
    p = &ucelt(code, 0);
    for (;;)
    {   int op = *p++;
/*
 * Opcodes 0 to 31 just load up the corresponding input value.
 */
        if (op < 32)
        {   fp_stack[n++] = fp_args[op];
            continue;
        }
        switch (op)
        {
    default:
            return aerror("Bad op in fp-evaluate");
    case FP_RETURN:
            args = make_boxfloat(fp_stack[0], TYPE_DOUBLE_FLOAT);
            errexit();
            return onevalue(args);
    case FP_PLUS:
            n--;
            fp_stack[n] += fp_stack[n-1];
            continue;
    case FP_DIFFERENCE:
            n--;
            fp_stack[n] -= fp_stack[n-1];
            continue;
    case FP_TIMES:
            n--;
            fp_stack[n] *= fp_stack[n-1];
            continue;
    case FP_QUOTIENT:
            n--;
            fp_stack[n] /= fp_stack[n-1];
            continue;
    case FP_MINUS:
            fp_stack[n] = -fp_stack[n];
            continue;
    case FP_SQUARE:
            fp_stack[n] *= fp_stack[n];
            continue;
    case FP_CUBE:
            w = fp_stack[n];
            w *= w;
            fp_stack[n] *= w;
            continue;
    case FP_SIN:
            fp_stack[n] = sin(fp_stack[n]);
            continue;
    case FP_COS:
            fp_stack[n] = cos(fp_stack[n]);
            continue;
    case FP_TAN:
            fp_stack[n] = tan(fp_stack[n]);
            continue;
    case FP_EXP:
            fp_stack[n] = exp(fp_stack[n]);
            continue;
    case FP_LOG:
            fp_stack[n] = log(fp_stack[n]);
            continue;
    case FP_SQRT:
            fp_stack[n] = sqrt(fp_stack[n]);
            continue;
        }
    }
}

#endif

setup_type const arith12_setup[] =
{
    {"frexp",                   Lfrexp, too_many_1, wrong_no_1},
    {"modular-difference",      too_few_2, Lmodular_difference, wrong_no_2},
    {"modular-minus",           Lmodular_minus, too_many_1, wrong_no_1},
    {"modular-number",          Lmodular_number, too_many_1, wrong_no_1},
    {"modular-plus",            too_few_2, Lmodular_plus, wrong_no_2},
    {"modular-quotient",        too_few_2, Lmodular_quotient, wrong_no_2},
    {"modular-reciprocal",      Lmodular_reciprocal, too_many_1, wrong_no_1},
    {"modular-times",           too_few_2, Lmodular_times, wrong_no_2},
    {"modular-expt",            too_few_2, Lmodular_expt, wrong_no_2},
    {"set-small-modulus",       Lset_small_modulus, too_many_1, wrong_no_1},
    {"iadd1",                   Liadd1, too_many_1, wrong_no_1},
    {"idifference",             too_few_2, Lidifference, wrong_no_2},
    {"xdifference",             too_few_2, Lxdifference, wrong_no_2},
    {"igeq",                    too_few_2, Ligeq, wrong_no_2},
    {"igreaterp",               too_few_2, Ligreaterp, wrong_no_2},
    {"ileq",                    too_few_2, Lileq, wrong_no_2},
    {"ilessp",                  too_few_2, Lilessp, wrong_no_2},
    {"ilogand",                 Lidentity, Lilogand2, Lilogand},
    {"ilogor",                  Lidentity, Lilogor2, Lilogor},
    {"ilogxor",                 Lidentity, Lilogxor2, Lilogxor},
    {"imax",                    too_few_2, Limax, wrong_no_2},
    {"imin",                    too_few_2, Limin, wrong_no_2},
    {"iminus",                  Liminus, too_many_1, wrong_no_1},
    {"iminusp",                 Liminusp, too_many_1, wrong_no_1},
    {"iplus",                   Lidentity, Liplus2, Liplus},
    {"iplus2",                  too_few_2, Liplus2, wrong_no_2},
    {"iquotient",               too_few_2, Liquotient, wrong_no_2},
    {"iremainder",              too_few_2, Liremainder, wrong_no_2},
    {"irightshift",             too_few_2, Lirightshift, wrong_no_2},
    {"isub1",                   Lisub1, too_many_1, wrong_no_1},
    {"itimes",                  Lidentity, Litimes2, Litimes},
    {"itimes2",                 too_few_2, Litimes2, wrong_no_2},
    {"ionep",                   Lionep, too_many_1, wrong_no_1},
    {"izerop",                  Lizerop, too_many_1, wrong_no_1},
#ifdef FP_EVALUATE
    {"fp-evaluate",             too_few_2, Lfp_eval, wrong_no_2},
#endif
    {NULL,                      0, 0, 0}
};

/* end of arith12.c */
