// arith-quad.cpp                         Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

// $Id: arith-quad.cpp 6450 2022-12-01 14:58:05Z arthurcnorman $


/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

#include "headers.h"

// This has some support for 128-bit floats at a higher level than
// that in float128_t.[h,cpp].
//
// Let me start by noting that on some but very definitely not all
// platforms that C++ compiler will support a type that may be called
// __float128 or that may be called long double which may represent
// IEEE-style 128-bit floating point with 113 bits of precision. However
// in some cases one or the other of those may be an 80-bit float padded
// with waste space to fill 129-bits, or just a synonym for 64-bit floats
// or perhaps neither are present at all. And the issue of library support
// for extra precision floats and even syntax for writing literals is
// also rather variable. In cases where the long float type is "proper"
// 128-bit arithmetic with a range up as far as 2^16383 the implementation
// is liable to be in software come what may.
//
// So for CSL I will use a software implementation that I can build
// everywhere and it will not be dramatically slower than any scheme
// more directly supported by the C++ compiler.

// There are several suites of 128-bit float elementary functions that
// I could collect. The two that seem most plausible are Cephes in Netlib
// and a Sun library now in openBSD - both are generously licensed.
//
// When I move to one of them the main problem I will have is that they
// are written assuming that the C compiler used to compile them has a
// type "long double" that supports 128-bit floats. C++ does not guarantee
// that and sometimes "long double" will be 80-bits wide, and my code
// uses type float128_t and QuadFloat with different degrees of
// inconvenience. My input syntax for QuadFloat uses a suffix "_Q".

// If I am to support the elementary functions then a key challenge
// is range reduction, and with the wide range of QuadFloat that is
// fairly extreme!

// Let me suppose that values of (f mod (pi/2)) are evenly distributed
// on -pi/4 .. pi/4 then to simplify my arithmetic I will imagine that
// half of them are evenly spread across 0 .. 1 (because pi/4 is not
// much less than 1).
//
// For IEEE double values there are 2^64 distinct values, and so I imagine
// 2^63 of them across 0 .. 1 and predict that one might be as small as
// 2^(-63). This is really a rather crude way to analyse however it seems
// to have turned out well, because a principled and careful analysis for
// that case shows the floating point value 6381956970095103*2^797 as
// the worst case and it reduces to around 3.0e-19 which is around 2^(-62).
//
// Thus for double precision arithmetic the precision of a value for 2/pi
// that is needed is (1024 + 53 + 62 + some spare) where 1024 is the largest
// exponent in the representation. Well 1023 is but hey. 1144 bits = 345
// decimals is about adequate.
//
// Encouraged by that I am going to imagine that for 128-bit floats the
// same line of informal reasoning will suffice and then I have something
// like (16384 + 113 + 127 + spare) = say 16640, so we need a value of
// 2/pi accurate to 5009 decimals.
//
// K C Ng (Argument reduction for huge arguments: Good to the Last Bit, 1992)
// suggests starting with a lower accuracy version and watching for leading
// digit cancellation - then moving to higher precision if necessary.
// In that writeup the suggestion involves splitting everything into 24-bit
// digits to perform multiple-precision arithmetic (because the product
// of two double-floats that have only 24 significant bits in each input
// will only have 48 on the product, so the calculation will be exact). That
// gets dramatically heavier duty for 128-bit values!

// Well since I found it took me a while to understand it all let me
// try an explanation of an argument reduction process:

// We want to compute sin(v) and we know that sin(2pi + v) = sin(v) so
// taking a simplistic first stance the aim is to take the input value v and
// subtract an integer multiple of 2pi. So v' = v - (2 k pi). The desired
// result will then be sin(v').
// if v is small (eg less than 2pi) we can just move ahead, so from now
// assume that v is larger than that - and in particular this means that
// all cases where v is really tiny do not need to be worried about.
// An obvious way to achieve this would be to let k = fix(v/(2pi)). That is
// in fact clumsy! A better recipe is to observe that
//    v' = 2*pi*frac(v*(1/(2*pi)))
// computes the same value v'. Well it then makes sense to think in terms of
// a function sinaux(u) = sin(2*pi*u) defined on value of u from 0 to 1. That
// can be evaluated using a minimax polynomial just about as easily as
// sin(v') could!
// Now consider the computation of frac(v*(1/(2*pi))). For 128-bit floats
// the value v can be expressed in the form m*2^(64x) where m is an
// integer with (up to) 177 bits. This will fit within three 64-bit "digits".
// So if a pre-computed value for 1/(2*pi) is written using d 64-bit
// digits (probably 260 of them!) to get the full version of v/(2pi)
// involved multiplying a 256-digit number with only 3 non-zero digits
// by a 260 digit number - which gives about a 512 digit result. The value
// v has bits to the left of an implied decimal point while 1/(2pi) has
// its bits to the right. Since we are interested in the fractional part
// of the product there is just now need to compute any of the higher
// order digits. So it is necessary to be ready to compute the low 260
// digits - but only the three non-zero digits making up v have to be used
// so even in the worst case this is in effect a 3*260 multiplication.
// In pathological cases the fraction will end up with a serious number
// of leading zero bits (as in the 6381956970095103*2^797 case previously
// mentioned. But most of the time there will not be many leading zeros.
// So for instance it will probably make sense to start out seeing what
// emerges from a 3*4 (or some other small calculation) and if it
// unambiguously does noy have many leading zeros in the fraction accept
// it. If it is not good then try the next more expensive option.
//
// Well all the above is expressed in terms of reducing by a multiple of
// 2*pi to end up with a fraction that corresponds to the input range
// 0 to 2pi. So now refine things a little! I will suggest two diffent
// ideas:
// (1) Compute a fractional part just as above but then look at its
//     first three bits. These indicate which octant the input value
//     fell in. In relevant cases negate value and sometimes add 0.25,
//     0.5 or 0.75. The result can then be a result in the range -0.125
//     to +0.125 corresponding to inputs in the range -pi/4 to +pi/4,
//     and one then comptes sinaux() or cosaux() on that to obtain the
//     final result. Almost the only ugliness in this is that the top
//     3 bits of the result have to be removed and that has to be
//     allowed for while converting it back to floating point format. Well
//     also when in the initial explanation I talked about "leading zeros"
//     in the fraction, it is now necessary to consider sequences of
//     either zeros or ones after the initial couple of bits.
// (2) Rather then multiplying by 1/(2pi) multiply by 2/pi. Now it is
//     necessary to compute the lowest two bits of the integer part of the
//     result, and in reality that probably involves computing the whole
//     least significant (64-bit) digit. Again it will make sense to
//     view both fractional parts with many leading zeros and those with
//     many leading ones as being values "close to an integer".
//
// Well actually the two schemes are essentially the same, and given a
// tabulated reciprocal of pi the difference can reduce to just how the
// mantissa of the input is aligned! 
 



// Here is 2/pi in hex to sufficient precision for range reduction in
// IEEE-style 128-bit floating point. I am storing 2/pi rather than
// for instance 1/(2pi) because the value here makes use of all the
// bits in its most significant digit. The little Reduce program that
// generated this is included at the end of this file.

uint64_t twoOverPi[] = {
0xa2f9836e4e441529, 0xfc2757d1f534ddc0, 0xdb6295993c439041, 0xfe5163abdebbc561,
0xb7246e3a424dd2e0, 0x06492eea09d1921c, 0xfe1deb1cb129a73e, 0xe88235f52ebb4484,
0xe99c7026b45f7e41, 0x3991d639835339f4, 0x9c845f8bbdf9283b, 0x1ff897ffde05980f,
0xef2f118b5a0a6d1f, 0x6d367ecf27cb09b7, 0x4f463f669e5fea2d, 0x7527bac7ebe5f17b,
0x3d0739f78a5292ea, 0x6bfb5fb11f8d5d08, 0x56033046fc7b6bab, 0xf0cfbc209af4361d,
0xa9e391615ee61b08, 0x6599855f14a06840, 0x8dffd8804d732731, 0x06061556ca73a8c9,
0x60e27bc08c6b47c4, 0x19c367cddce8092a, 0x8359c4768b961ca6, 0xddaf44d15719053e,
0xa5ff07053f7e33e8, 0x32c2de4f98327dbb, 0xc33d26ef6b1e5ef8, 0x9f3a1f35caf27f1d,
0x87f121907c7c246a, 0xfa6ed5772d30433b, 0x15c614b59d19c3c2, 0xc4ad414d2c5d000c,
0x467d862d71e39ac6, 0x9b0062337cd2b497, 0xa7b4d55537f63ed7, 0x1810a3fc764d2a9d,
0x64abd770f87c6357, 0xb07ae715175649c0, 0xd9d63b3884a7cb23, 0x24778ad623545ab9,
0x1f001b0af1dfce19, 0xff319f6a1e666157, 0x9947fbacd87f7eb7, 0x652289e83260bfe6,
0xcdc4ef09366cd43f, 0x5dd7de16de3b5892, 0x9bde2822d2e88628, 0x4d58e232cac616e3,
0x08cb7de050c017a7, 0x1df35be01834132e, 0x6212830148835b8e, 0xf57fb0adf2e91e43,
0x4a48d36710d8ddaa, 0x425faece616aa428, 0x0ab499d3f2a6067f, 0x775c83c2a3883c61,
0x78738a5a8cafbdd7, 0x6f63a62dcbbff4ef, 0x818d67c12645ca55, 0x36d9cad2a8288d61,
0xc277c9121426049b, 0x4612c459c444c5c8, 0x91b24df31700ad43, 0xd4e5492910d5fdfc,
0xbe00cc941eeece70, 0xf53e1380f1ecc3e7, 0xb328f8c79405933e, 0x71c1b3092ef3450b,
0x9c12887b20ab9fb5, 0x2ec292472f327b6d, 0x550c90a7721fe76b, 0x96cb314a1679e279,
0x4189dff49794e884, 0xe6e29731996bed88, 0x365f5f0efdbbb49a, 0x486ca46742727132,
0x5d8db8159f09e5bc, 0x25318d3974f71c05, 0x30010c0d68084b58, 0xee2c90aa4702e774,
0x24d6bda67df77248, 0x6eef169fa6948ef6, 0x91b45153d1f20acf, 0x3398207e4bf56863,
0xb25f3edd035d407f, 0x8985295255c06437, 0x10d86d324832754c, 0x5bd4714e6e5445c1,
0x090b69f52ad56614, 0x9d072750045ddb3b, 0xb4c576ea17f9877d, 0x6b49ba271d296996,
0xacccc65414ad6ae2, 0x9089d98850722cbe, 0xa4049407777030f3, 0x27fc00a871ea49c2,
0x663de06483dd9797, 0x3fa3fd94438c860d, 0xde41319d39928c70, 0xdde7b7173bdf082b,
0x3715a0805c93805a, 0x921110d8e80faf80, 0x6c4bffdb0f903876, 0x185915a562bbcb61,
0xb989c7bd401004f2, 0xd2277549f6b6ebbb, 0x22dbaa140a2f2689, 0x768364333b091a94,
0x0eaa3a51c2a31dae, 0xedaf12265c4dc26d, 0x9c7a2d9756c0833f, 0x03f6f0098c402b99,
0x316d07b43915200c, 0x5bc3d8c492f54bad, 0xc6a5ca4ecd37a736, 0xa9e69492ab6842dd,
0xde6319ef8c76528b, 0x6837dbfcaba1ae31, 0x15dfa1ae00dafb0c, 0x664d64b705ed3065,
0x29bf56573aff47b9, 0xf96af3be75df9328, 0x3080abf68c6615cb, 0x040622fa1de4d9a4,
0xb33d8f1b5709cd36, 0xe9424ea4be13b523, 0x331aaaf0a8654fa5, 0xc1d20f3f0bcd785b,
0x76f923048b7b7217, 0x8953a6c6e26e6f00, 0xebef584a9bb7dac4, 0xba66aacfcf761d02,
0xd12df1b1c1998c77, 0xadc3da4886a05df7, 0xf480c62ff0ac9aec, 0xddbc5c3f6dded01f,
0xc790b6db2a3a25a3, 0x9aaf009353ad0457, 0xb6b42d297e804ba7, 0x07da0eaa76a1597b,
0x2a12162db7dcfde5, 0xfafedb89fdbe896c, 0x76e4fca90670803e, 0x156e85ff87fd073e,
0x2833676186182aea, 0xbd4dafe7b36e6d8f, 0x3967955bbf3148d7, 0x8416df30432dc735,
0x6125ce70c9b8cb30, 0xfd6cbfa200a4e46c, 0x05a0dd5a476f21d2, 0x1262845cb9496170,
0xe0566b0152993755, 0x50b7d51ec4f1335f, 0x6e13e4305da92e85, 0xc3b21d3632a1a4b7,
0x08d4b1ea21f716e4, 0x698f77ff2780030c, 0x2d408da0cd4f99a5, 0x20d3a2b30a5d2f42,
0xf9b4cbda11d0be7d, 0xc1db9bbd17ab81a2, 0xca5c6a0817552e55, 0x0027f0147f8607e1,
0x640b148d4196debe, 0x872afddab6256b34, 0x897bfef3059ebfb9, 0x4f6a68a82a4a5ac4,
0x4fbcf82d985ad795, 0xc7f48d4d0da63a20, 0x5f57a4b13f149538, 0x800120cc86dd71b6,
0xdec9f560bf11654d, 0x6b0701acb08cd0c0, 0xb24855510efb1ec3, 0x72953b06a33540c0,
0x7bdc06cc45e0fa29, 0x4ec8cad641f3e8de, 0x647cd8649b31bed9, 0xc397a4d45877c5e3,
0x6913daf03c3aba46, 0x18465f7555f5bdd2, 0xc6926e5d2eaced44, 0x0e423e1c87c461e9,
0xfd29f3d6e7ca7c22, 0x35916fc5e0088dd7, 0xffe26a6ec6fdb0c1, 0x0893745d7cb2ad6b,
0x9d6ecd7b723e6a11, 0xc6a9cff7df7329ba, 0xc9b55100b70db2e2, 0x24ba74607de58ad8,
0x742c150d0c188194, 0x667e162901767a9f, 0xbefdfdef4556367e, 0xd913d9ecb9ba8bfc,
0x97c427a831c36ef1, 0x36c59456a8d8b5a8, 0xb40ecccf2d891234, 0x576f89562ce3ce99,
0xb920d6aa5e6b9c2a, 0x3ecc5f114a0bfdfb, 0xf4e16d3b8e2c86e2, 0x84d4e9a9b4fcd1ee,
0xefc9352e61392f44, 0x2138c8d91b0afc81, 0x6a4afbd81c2f84b4, 0x538c994ecc2254dc,
0x552ad6c6c096190b, 0xb8701a649569605a, 0x26ee523f0f117f11, 0xb5f4f5cbfc2dbc34,
0xeebc34cc5de8605e, 0xdd9b8e67ef3392b8, 0x17c99b5861bc57e1, 0xc68351103ed84871,
0xdddd1c2da118af46, 0x2c21d7f359987ad9, 0xc0549efa864ffc06, 0x56ae79e536228922,
0xad38dc9367aae855, 0x3826829be7caa40d, 0x51b133990ed7a948, 0x0569f0b265a7887f,
0x974c8836d1f9b392, 0x214a827b21cf98dc, 0x9f405547dc3a74e1, 0x42eb67df9dfe5fd4,
0x5ea4677b7aacbaa2, 0xf65523882b55ba41, 0x086e59862a218347, 0x39e6e389d49ee540,
0xfb49e956ffca0f1c, 0x8a59c52bfa94c5c1, 0xd3cfc50fae5adb86, 0xc5476243853b8621,
0x94792c8761107b4c, 0x2a1a2c8012bf4390, 0x2688893c78e4c4a8, 0x7bdbe5c23ac4eaf4,
0x268a67f7bf920d2b, 0xa365b1933d0b7cbd, 0xdc51a463dd27dde1, 0x6919949a9529a828,
0xce68b4ed09209f44, 0xca984e638270237c, 0x7e32b90f8ef5a7e7, 0x561408f1212a9db5,
0x4d7e6f5119a5abf9, 0xb5d6df8261dd9602, 0x36169f3ac4a1a283, 0x6ded727a8d39a9b8,
0x825c326b5b2746ed, 0x34007700d255f4fc, 0x4d59018071e0e13f, 0x89b295f364a8f1ae
};

const size_t twoOverPiDigits = sizeof(twoOverPi)/sizeof(twoOverPi[0]);
uint64_t product[twoOverPiDigits + 4];
const size_t productDigits = sizeof(product)/sizeof(product[0]);


QuadFloat reduceMod2Pi(QuadFloat aa)
{   int x = aa.exponent();
    uint64_t m[3];
    m[2] = aa.v.v[LOPART];
// I insert the hidden bit here - so the input must not be subnormal!
    m[1] = (aa.v.v[HIPART] & 0x0000ffffffffffffLLU) |
                             0x0001000000000000LLU;
    m[0] = 0;
    int sh = (x-2) & 0x3f;
    x = (x-sh)/64;
    if (sh != 0)
    {   m[0] = (m[0]<<sh) | (m[1]>>(64-sh));
        m[1] = (m[1]<<sh) | (m[2]>>(64-sh));
        m[2] = m[2]<<sh;
    }
/*
    zprintf("Plain %x.%x.%x\n", 0x12345, 0x123, 0x12345);
    zprintf("Prec16 %.16x.%.16x.%.16x\n", 0x123, 0x12345, 0x12345);
    zprintf("width16 %16x.%16x.%16x\n", 0x12345, 0x123, 0x12345);
    zprintf("Width+Prec %16.16x.%16.16x.%16.16x\n", 0x12345, 0x123, 0x12345);
    zprintf("0W+prec %016.16x.%016.16x.%016.16x\n", 0x12345, 0x123, 0x12345);
    zprintf("0Width %016x.%016x.%016x\n", 0x12345, 0x123, 0x12345);
*/
    zprintf("M(%2d) = %016x %016x %016x :: %d\n",
        sh, m[0], m[1], m[2], x);

    for (size_t i=0; i<productDigits; i++) product[i] = 0;

int count = 0;
    for (size_t i=0; i<twoOverPiDigits; i++)
    for (size_t j=0; j<3; j++)
    {   size_t k = i+j;
        uint64_t hi, lo;
        arithlib_implementation::multiply64(
            twoOverPi[i], m[j], product[k+1], hi, lo);
if (count < 10) zprintf("%016x * %016x + %016x = (%016x, %016x)\n",
                        twoOverPi[i], m[j], product[k+1], hi, lo);
        product[k+1] = lo;
if (count++ < 10) zprintf("set p[%d] = %016x\n", k+1, lo);
        int k1 = k;
        while (hi != 0)
        {   uint64_t w = product[k1] + hi;
            product[k1] = w;
if (count++ < 10) zprintf("carry p[%d] = %016x\n", k1, w);
            hi = w < hi ? 1 : 0;
            if (k1 == 0) break;
            k1--;
        }
    }
    for (size_t i=0; i<productDigits; i++)
    {   zprintf("%016x", product[i]);
        if (i%4 == 3) zprintf("\n");
        else zprintf(" ");
    }
    zprintf("\n");

    return 0.0_Q;
}

// I will start off with placeholders here that yield the correct types
// but only compute results to double precision accuracy - ie 53-bits.
// Eventually maybe I will work through and replace all these with
// proper 128-bit floating point versions, maybe adopting the Cephes maths
// library code (which is released under the MIT licence). A challenge
// there is that their code is written (very reasonably) using "long double"
// as the name for the 128-bit floating type, but across all platforms
// "long double" is sometimes not supported and is sometimes an 80-bit
// type - all of which is why I use software floating point and a raw
// type float128_t that has to be used via explicit function calls and
// then a type QuadFloat that is slightly nicer to use. And for me
// 128-bit floating point literals need to be written with a "_Q" suffix.
// So I will have some straightforward but mildly time-consuming adaptation
// to do!

float128_t qatan2(float128_t a, float128_t b)
{   QuadFloat aa(a), bb(b);
    return QuadFloat(std::atan2(static_cast<double>(aa),
                                static_cast<double>(bb))).v;
}

float128_t qatan2d(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qexpt(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qacos(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::acos(static_cast<double>(aa))).v;
}

float128_t qacosd(float128_t a)
{   return f128_NaN;
}

float128_t qacosh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::acosh(static_cast<double>(aa))).v;
}

float128_t qacot(float128_t a)
{   return f128_NaN;
}

float128_t qacotd(float128_t a)
{   return f128_NaN;
}

float128_t qacoth(float128_t a)
{   return f128_NaN;
}

float128_t qacsc(float128_t a)
{   return f128_NaN;
}

float128_t qacscd(float128_t a)
{   return f128_NaN;
}

float128_t qacsch(float128_t a)
{   return f128_NaN;
}

float128_t qasec(float128_t a)
{   return f128_NaN;
}

float128_t qasecd(float128_t a)
{   return f128_NaN;
}

float128_t qasech(float128_t a)
{   return f128_NaN;
}

float128_t qasin(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::asin(static_cast<double>(aa))).v;
}

float128_t qasind(float128_t a)
{   return f128_NaN;
}
 
float128_t qasinh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::asinh(static_cast<double>(aa))).v;
}

float128_t qatan(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::atan(static_cast<double>(aa))).v;
}

float128_t qatand(float128_t a)
{   return f128_NaN;
}

float128_t qatanh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::atanh(static_cast<double>(aa))).v;
}

float128_t qcbrt(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cbrt(static_cast<double>(aa))).v;
}
  
float128_t qcos(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cos(static_cast<double>(aa))).v;
}

float128_t qcosd(float128_t a)
{   return f128_NaN;
}
  
float128_t qcosh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::cosh(static_cast<double>(aa))).v;
}

float128_t qcot(float128_t a)
{   return f128_NaN;
}

float128_t qcotd(float128_t a)
{   return f128_NaN;
}

float128_t qcoth(float128_t a)
{   return f128_NaN;
}

float128_t qcsc(float128_t a)
{   return f128_NaN;
}

float128_t qcscd(float128_t a)
{   return f128_NaN;
}

float128_t qcsch(float128_t a)
{   return f128_NaN;
}
  
float128_t qexp(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::exp(static_cast<double>(aa))).v;
}

float128_t qhypot(float128_t x, float128_t y)
{   QuadFloat a(x);
    QuadFloat b(y);
    QuadFloat scale = 1.0_Q;
    QuadFloat r = a*a + b*b;
// If the above calculation overflows or underflows I will repeat
// it but on scaled inputs.
    if (r.isinf())
    {   scale = 1.0e4000_Q;
        a /= scale;
        b /= scale;
        r = a*a + b*b;
    }
    if (r.issubnorm())
    {   scale = 1.0e-4000_Q;
        a /= scale;
        b /= scale;
        r = a*a + b*b;
    }
    return f128_mul(scale.v, qsqrt(r.v));
}

float128_t qln(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::log(static_cast<double>(aa))).v;
}
    
float128_t qlog(float128_t a, float128_t b)
{   return f128_NaN;
}

float128_t qlog10(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::log10(static_cast<double>(aa))).v;
}

float128_t qsec(float128_t a)
{   return f128_NaN;
}

float128_t qsecd(float128_t a)
{   return f128_NaN;
}

float128_t qsech(float128_t a)
{   return f128_NaN;
}
  
float128_t qsin(float128_t a)
{   QuadFloat aa(a);
// If the input is really tiny I will deal with it specially so that
// I never hand a very very small argument to the range reduction code.
    if (aa > 1.0e-17_Q && aa < 1.0e-17_Q) return a;
    if (aa > 1.0e-8_Q && aa < 1.0e-8_Q)
        return (aa - aa*aa*aa/120.0_Q).v;
    QuadFloat reduced = reduceMod2Pi(aa);  // so I can test it!
    return QuadFloat(std::sin(static_cast<double>(aa))).v;
}

float128_t qsind(float128_t a)
{   return f128_NaN;
}
  
float128_t qsinh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::sinh(static_cast<double>(aa))).v;
}

float128_t qsqrt(float128_t a)
{   return f128_sqrt(a);
}

float128_t qtan(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::tan(static_cast<double>(aa))).v;
}

float128_t qtand(float128_t a)
{   return f128_NaN;
}

float128_t qtanh(float128_t a)
{   QuadFloat aa(a);
    return QuadFloat(std::tanh(static_cast<double>(aa))).v;
}

float128_t qlog2(float128_t a)
{   return f128_NaN;
}

#if 0

% This is going to print a value of 2/pi good to around 5010 decimals
% (ie 16384 plus some) bits but as a hexadecimal fraction.

on echo, time, rounded;
precision 6000;

a := 2/pi$
share w;

<<
lisp terpri(); lisp terpri(); lisp printc "uint64_t twoOverPi[] = {";
for i := 1:260 do <<
  a := 2^64*a;
  k := fix a;
  a := a - k;
  off rounded;
  w := k;
  lisp princ "0x";
  lisp prinhex(w, 16);
  if i neq 260 then
  <<  if remainder(i, 4) = 0 then lisp printc ","
      else lisp princ ", ";
  >>;
  on rounded >>;
lisp terpri(); lisp printc "};"; lisp terpri() >>;

end;

#endif // 0

#endif // ARITHLIB

// end of arith-quad.cpp

