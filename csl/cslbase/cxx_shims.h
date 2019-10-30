// cxx_shims.h                                  Copyright (C) 2019 Codemist

#ifndef header_cxx_shims_h
#define header_cxx_shims_h 1

// $Id$


/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
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

// As I convert parts of CSL from the original C code to use C++ there will
// be places where I store data as std::string rather than char*, or as
// std::vector<int> rather than int[]. To mak ethe transition easier I will
// have fragments of code here that adapt between the two representations.
// These will typically be just overloads to make it appear that the old
// code could accept the new type of argument, and being presented here
// as inline functions the overhead will be small.
//
// I also have this long list of "using" statements that import the things
// that the C library defines into the global namespace. These are intended
// to cover everything exported by the header files. The set of names here
// was extracted from files in the directory /usr/include/c++/v1 on a cygwin
// system, just using the "<cxxx>" headers.
// I have then commented out ones where when I compile CSL I get a diagnostic
// of the form "std::xxx has not been declared". These may often be cases
// where my code does not include the header file that contains the
// declaration concerned!


using std::isalnum;
using std::isalpha;
using std::isblank;
using std::iscntrl;
using std::isdigit;
using std::isgraph;
using std::islower;
using std::isprint;
using std::ispunct;
using std::isspace;
using std::isupper;
using std::isxdigit;
using std::tolower;
using std::toupper;
//using std::fenv_t;
//using std::fexcept_t;
//using std::feclearexcept;
//using std::fegetexceptflag;
//using std::feraiseexcept;
//using std::fesetexceptflag;
//using std::fetestexcept;
//using std::fegetround;
//using std::fesetround;
//using std::fegetenv;
//using std::feholdexcept;
//using std::fesetenv;
//using std::feupdateenv;
using std::imaxdiv_t;
using std::imaxabs;
using std::imaxdiv;
using std::strtoimax;
using std::strtoumax;
using std::wcstoimax;
using std::wcstoumax;
using std::lconv;
using std::setlocale;
using std::localeconv;
using std::signbit;
using std::fpclassify;
using std::isfinite;
using std::isinf;
using std::isnan;
using std::isnormal;
using std::isgreater;
using std::isgreaterequal;
using std::isless;
using std::islessequal;
using std::islessgreater;
using std::isunordered;
using std::isunordered;
using std::float_t;
using std::double_t;
using std::abs;
using std::acos;
//using std::acosf;
using std::asin;
//using std::asinf;
using std::atan;
//using std::atanf;
using std::atan2;
//using std::atan2f;
using std::ceil;
//using std::ceilf;
using std::cos;
//using std::cosf;
using std::cosh;
//using std::coshf;
using std::exp;
//using std::expf;
using std::fabs;
//using std::fabsf;
using std::floor;
//using std::floorf;
using std::fmod;
//using std::fmodf;
using std::frexp;
//using std::frexpf;
using std::ldexp;
//using std::ldexpf;
using std::log;
//using std::logf;
using std::log10;
//using std::log10f;
using std::modf;
//using std::modff;
using std::pow;
//using std::powf;
using std::sin;
//using std::sinf;
using std::sinh;
//using std::sinhf;
using std::sqrt;
//using std::sqrtf;
using std::tan;
//using std::tanf;
using std::tanh;
//using std::tanhf;
using std::acosh;
//using std::acoshf;
using std::asinh;
//using std::asinhf;
using std::atanh;
//using std::atanhf;
using std::cbrt;
//using std::cbrtf;
using std::copysign;
//using std::copysignf;
using std::erf;
//using std::erff;
using std::erfc;
//using std::erfcf;
using std::exp2;
//using std::exp2f;
using std::expm1;
//using std::expm1f;
using std::fdim;
//using std::fdimf;
using std::fmaf;
using std::fma;
using std::fmax;
//using std::fmaxf;
using std::fmin;
//using std::fminf;
using std::hypot;
//using std::hypotf;
using std::ilogb;
//using std::ilogbf;
using std::lgamma;
//using std::lgammaf;
using std::llrint;
//using std::llrintf;
using std::llround;
//using std::llroundf;
using std::log1p;
//using std::log1pf;
using std::log2;
//using std::log2f;
using std::logb;
//using std::logbf;
using std::lrint;
//using std::lrintf;
using std::lround;
//using std::lroundf;
using std::nan;
//using std::nanf;
using std::nearbyint;
//using std::nearbyintf;
using std::nextafter;
//using std::nextafterf;
using std::nexttoward;
//using std::nexttowardf;
using std::remainder;
//using std::remainderf;
using std::remquo;
//using std::remquof;
using std::rint;
//using std::rintf;
using std::round;
//using std::roundf;
using std::scalbln;
//using std::scalblnf;
using std::scalbn;
//using std::scalbnf;
using std::tgamma;
//using std::tgammaf;
using std::trunc;
//using std::truncf;
//using std::acosl;
//using std::asinl;
//using std::atanl;
//using std::atan2l;
//using std::ceill;
//using std::cosl;
//using std::coshl;
//using std::expl;
//using std::fabsl;
//using std::floorl;
//using std::fmodl;
//using std::frexpl;
//using std::ldexpl;
//using std::logl;
//using std::log10l;
//using std::modfl;
//using std::powl;
//using std::sinl;
//using std::sinhl;
//using std::sqrtl;
//using std::tanl;
//using std::tanhl;
//using std::acoshl;
//using std::asinhl;
//using std::atanhl;
//using std::cbrtl;
//using std::copysignl;
//using std::erfl;
//using std::erfcl;
//using std::exp2l;
//using std::expm1l;
//using std::fdiml;
//using std::fmal;
//using std::fmaxl;
//using std::fminl;
//using std::hypotl;
//using std::ilogbl;
//using std::lgammal;
//using std::llrintl;
//using std::llroundl;
//using std::log1pl;
//using std::log2l;
//using std::logbl;
//using std::lrintl;
//using std::lroundl;
//using std::nanl;
//using std::nearbyintl;
//using std::nextafterl;
//using std::nexttowardl;
//using std::remainderl;
//using std::remquol;
//using std::rintl;
//using std::roundl;
//using std::scalblnl;
//using std::scalbnl;
//using std::tgammal;
//using std::truncl;
using std::jmp_buf;
using std::longjmp;
using std::sig_atomic_t;
using std::signal;
using std::raise;
using std::va_list;
using std::ptrdiff_t;
using std::size_t;
using std::max_align_t;
using std::int8_t;
using std::int16_t;
using std::int32_t;
using std::int64_t;
using std::uint8_t;
using std::uint16_t;
using std::uint32_t;
using std::uint64_t;
using std::int_least8_t;
using std::int_least16_t;
using std::int_least32_t;
using std::int_least64_t;
using std::uint_least8_t;
using std::uint_least16_t;
using std::uint_least32_t;
using std::uint_least64_t;
using std::int_fast8_t;
using std::int_fast16_t;
using std::int_fast32_t;
using std::int_fast64_t;
using std::uint_fast8_t;
using std::uint_fast16_t;
using std::uint_fast32_t;
using std::uint_fast64_t;
using std::intptr_t;
using std::uintptr_t;
using std::intmax_t;
using std::uintmax_t;
using std::FILE;
using std::fpos_t;
using std::size_t;
using std::fclose;
using std::fflush;
using std::setbuf;
using std::setvbuf;
using std::fprintf;
using std::fscanf;
using std::snprintf;
using std::sprintf;
using std::sscanf;
using std::vfprintf;
using std::vfscanf;
using std::vsscanf;
using std::vsnprintf;
using std::vsprintf;
using std::fgetc;
using std::fgets;
using std::fputc;
using std::fputs;
using std::getc;
using std::putc;
using std::ungetc;
using std::fread;
using std::fwrite;
using std::fgetpos;
using std::fseek;
using std::fsetpos;
using std::ftell;
using std::rewind;
using std::clearerr;
using std::feof;
using std::ferror;
using std::perror;
using std::fopen;
using std::freopen;
using std::remove;
using std::rename;
using std::tmpfile;
using std::tmpnam;
using std::getchar;
//using std::gets;
using std::scanf;
using std::vscanf;
using std::printf;
using std::putchar;
using std::puts;
using std::vprintf;
using std::size_t;
using std::div_t;
using std::ldiv_t;
using std::lldiv_t;
using std::atof;
using std::atoi;
using std::atol;
using std::atoll;
using std::strtod;
using std::strtof;
using std::strtold;
using std::strtol;
using std::strtoll;
using std::strtoul;
using std::strtoull;
using std::rand;
using std::srand;
using std::calloc;
using std::free;
using std::malloc;
using std::realloc;
using std::abort;
using std::atexit;
using std::exit;
using std::_Exit;
using std::getenv;
using std::system;
using std::bsearch;
using std::qsort;
using std::abs;
using std::labs;
using std::llabs;
using std::div;
using std::ldiv;
using std::lldiv;
using std::mblen;
using std::mbtowc;
using std::wctomb;
using std::mbstowcs;
using std::wcstombs;
using std::at_quick_exit;
using std::quick_exit;
using std::aligned_alloc;
using std::size_t;
using std::memcpy;
using std::memmove;
using std::strcpy;
using std::strncpy;
using std::strcat;
using std::strncat;
using std::memcmp;
using std::strcmp;
using std::strncmp;
using std::strcoll;
using std::strxfrm;
using std::memchr;
using std::strchr;
using std::strcspn;
using std::strpbrk;
using std::strrchr;
using std::strspn;
using std::strstr;
using std::strtok;
using std::memset;
using std::strerror;
using std::strlen;
using std::clock_t;
using std::size_t;
using std::time_t;
using std::tm;
//using std::timespec;
using std::clock;
using std::difftime;
using std::mktime;
using std::time;
using std::asctime;
using std::ctime;
using std::gmtime;
using std::localtime;
using std::strftime;
//using std::timespec_get;
using std::mbstate_t;
using std::size_t;
using std::tm;
using std::wint_t;
using std::FILE;
using std::fwprintf;
using std::fwscanf;
using std::swprintf;
using std::vfwprintf;
using std::vswprintf;
using std::swscanf;
using std::vfwscanf;
using std::vswscanf;
using std::fgetwc;
using std::fgetws;
using std::fputwc;
using std::fputws;
using std::fwide;
using std::getwc;
using std::putwc;
using std::ungetwc;
using std::wcstod;
using std::wcstof;
using std::wcstold;
using std::wcstol;
using std::wcstoll;
using std::wcstoul;
using std::wcstoull;
using std::wcscpy;
using std::wcsncpy;
using std::wcscat;
using std::wcsncat;
using std::wcscmp;
using std::wcscoll;
using std::wcsncmp;
using std::wcsxfrm;
using std::wcschr;
using std::wcspbrk;
using std::wcsrchr;
using std::wcsstr;
using std::wmemchr;
using std::wcscspn;
using std::wcslen;
using std::wcsspn;
using std::wcstok;
using std::wmemcmp;
using std::wmemcpy;
using std::wmemmove;
using std::wmemset;
using std::wcsftime;
using std::btowc;
using std::wctob;
using std::mbsinit;
using std::mbrlen;
using std::mbrtowc;
using std::wcrtomb;
using std::mbsrtowcs;
using std::wcsrtombs;
using std::getwchar;
using std::vwscanf;
using std::wscanf;
using std::putwchar;
using std::vwprintf;
using std::wprintf;
using std::wint_t;
using std::wctrans_t;
using std::wctype_t;
using std::iswalnum;
using std::iswalpha;
using std::iswblank;
using std::iswcntrl;
using std::iswdigit;
using std::iswgraph;
using std::iswlower;
using std::iswprint;
using std::iswpunct;
using std::iswspace;
using std::iswupper;
using std::iswxdigit;
using std::iswctype;
using std::wctype;
using std::towlower;
using std::towupper;
using std::towctrans;
using std::wctrans;

inline FILE *fopen(std::string name, const char *mode)
{   return std::fopen(name.c_str(), mode);
}


#endif // header_cxx_shims_h

// end of cxx_shims.h
