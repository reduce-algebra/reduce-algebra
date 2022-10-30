// arith-defs.h                                Copyright (C) Codemist, 2022

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

// $Id: arith.h 6408 2022-10-23 12:40:00Z arthurcnorman $

#ifndef header_arith_defs_h
#define header_arith_defs_h 1

inline LispObject onebool(bool b)
{   return onevalue(b ? lisp_true : nil);
}

extern LispObject Nplus(LispObject env);
extern LispObject Nplus(LispObject env, LispObject a1);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Ndifference(LispObject env);
extern LispObject Ndifference(LispObject env, LispObject a1);
extern LispObject Ndifference(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ndifference(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Ndifference(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Ntimes(LispObject env);
extern LispObject Ntimes(LispObject env, LispObject a1);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nquotient(LispObject env);
extern LispObject Nquotient(LispObject env, LispObject a1);
extern LispObject Nquotient(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nquotient(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nquotient(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nlessp(LispObject env);
extern LispObject Nlessp(LispObject env, LispObject a1);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nleq(LispObject env);
extern LispObject Nleq(LispObject env, LispObject a1);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Ngreaterp(LispObject env);
extern LispObject Ngreaterp(LispObject env, LispObject a1);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Ngeq(LispObject env);
extern LispObject Ngeq(LispObject env, LispObject a1);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nlogand(LispObject env);
extern LispObject Nlogand(LispObject env, LispObject a1);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nlogor(LispObject env);
extern LispObject Nlogor(LispObject env, LispObject a1);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nlogxor(LispObject env);
extern LispObject Nlogxor(LispObject env, LispObject a1);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nlogeqv(LispObject env);
extern LispObject Nlogeqv(LispObject env, LispObject a1);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4plus);
extern LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2);

extern LispObject Nabsval(LispObject env, LispObject a);
extern LispObject Nacos(LispObject env, LispObject a);
extern LispObject Nacosd(LispObject env, LispObject a);
extern LispObject Nacosh(LispObject env, LispObject a);
extern LispObject Nacot(LispObject env, LispObject a);
extern LispObject Nacotd(LispObject env, LispObject a);
extern LispObject Nacoth(LispObject env, LispObject a);
extern LispObject Nacsc(LispObject env, LispObject a);
extern LispObject Nacscd(LispObject env, LispObject a);
extern LispObject Nacsch(LispObject env, LispObject a);
extern LispObject Nasec(LispObject env, LispObject a);
extern LispObject Nasecd(LispObject env, LispObject a);
extern LispObject Nasech(LispObject env, LispObject a);
extern LispObject Nasin(LispObject env, LispObject a);
extern LispObject Nasind(LispObject env, LispObject a);
extern LispObject Nasinh(LispObject env, LispObject a);
extern LispObject Natand(LispObject env, LispObject a);
extern LispObject Natan2(LispObject env, LispObject a, LispObject b);
extern LispObject Natan2d(LispObject env, LispObject a, LispObject b);
extern LispObject Natanh(LispObject env, LispObject a);
extern LispObject Ncbrt(LispObject env, LispObject a);
extern LispObject Ncos(LispObject env, LispObject a);
extern LispObject Ncosd(LispObject env, LispObject a);
extern LispObject Ncosh(LispObject env, LispObject a);
extern LispObject Ncot(LispObject env, LispObject a);
extern LispObject Ncotd(LispObject env, LispObject a);
extern LispObject Ncoth(LispObject env, LispObject a);
extern LispObject Ncsc(LispObject env, LispObject a);
extern LispObject Ncscd(LispObject env, LispObject a);
extern LispObject Ncsch(LispObject env, LispObject a);
extern LispObject Nexp(LispObject env, LispObject a);
extern LispObject Nexpt(LispObject env, LispObject a, LispObject b);
extern LispObject Nhypot(LispObject env, LispObject a, LispObject b);
extern LispObject Nln(LispObject env, LispObject a);
extern LispObject Nln(LispObject env, LispObject a);
extern LispObject Nlog_2(LispObject env, LispObject a, LispObject b);
extern LispObject Nlog2(LispObject env, LispObject a);
extern LispObject Nlog10(LispObject env, LispObject a);
extern LispObject Nsec(LispObject env, LispObject a);
extern LispObject Nsecd(LispObject env, LispObject a);
extern LispObject Nsech(LispObject env, LispObject a);
extern LispObject Nsin(LispObject env, LispObject a);
extern LispObject Nsind(LispObject env, LispObject a);
extern LispObject Nsinh(LispObject env, LispObject a);
extern LispObject Nsqrt(LispObject env, LispObject a);
extern LispObject Ntan(LispObject env, LispObject a);
extern LispObject Ntand(LispObject env, LispObject a);
extern LispObject Ntanh(LispObject env, LispObject a);
extern LispObject Ncis(LispObject env, LispObject a);
extern LispObject Nisqrt(LispObject env, LispObject a);
extern LispObject Nphase(LispObject env, LispObject a);
extern LispObject Nsignum(LispObject env, LispObject a);
extern LispObject Natan(LispObject env, LispObject a);
extern LispObject Natan_2(LispObject env, LispObject a, LispObject b);
extern LispObject Nlog_2(LispObject env, LispObject a);

extern LispObject Nplusp(LispObject env, LispObject a);

extern LispObject Nmax(LispObject env);
extern LispObject Nmax(LispObject env, LispObject a);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);
extern LispObject Nmin(LispObject env);
extern LispObject Nmin(LispObject env, LispObject a);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);


extern LispObject Ncarg(LispObject env, LispObject re, LispObject im);
extern LispObject Ncabs(LispObject env, LispObject re, LispObject im);
extern LispObject Ncexp(LispObject env, LispObject re, LispObject im);
extern LispObject Nclog(LispObject env, LispObject re, LispObject im);
extern LispObject Ncsqrt(LispObject env, LispObject re, LispObject im);
extern LispObject Ncsin(LispObject env, LispObject re, LispObject im);
extern LispObject Nccos(LispObject env, LispObject re, LispObject im);
extern LispObject Nctan(LispObject env, LispObject re, LispObject im);
extern LispObject Nccsc(LispObject env, LispObject re, LispObject im);
extern LispObject Ncsec(LispObject env, LispObject re, LispObject im);
extern LispObject Nccot(LispObject env, LispObject re, LispObject im);
extern LispObject Ncasin(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacos(LispObject env, LispObject re, LispObject im);
extern LispObject Ncatan(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacsc(LispObject env, LispObject re, LispObject im);
extern LispObject Ncasec(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacot(LispObject env, LispObject re, LispObject im);
extern LispObject Ncsinh(LispObject env, LispObject re, LispObject im);
extern LispObject Nccosh(LispObject env, LispObject re, LispObject im);
extern LispObject Nctanh(LispObject env, LispObject re, LispObject im);
extern LispObject Nccsch(LispObject env, LispObject re, LispObject im);
extern LispObject Ncsech(LispObject env, LispObject re, LispObject im);
extern LispObject Nccoth(LispObject env, LispObject re, LispObject im);
extern LispObject Ncasinh(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacosh(LispObject env, LispObject re, LispObject im);
extern LispObject Ncatanh(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacsch(LispObject env, LispObject re, LispObject im);
extern LispObject Ncasech(LispObject env, LispObject re, LispObject im);
extern LispObject Ncacoth(LispObject env, LispObject re, LispObject im);

extern LispObject Nnumerator(LispObject env, LispObject a);
extern LispObject Ndenominator(LispObject env, LispObject a);
extern LispObject Nrealpart(LispObject env, LispObject a);
extern LispObject Nimagpart(LispObject env, LispObject a);
extern LispObject Ndecode_float(LispObject env, LispObject a);
extern LispObject Ninteger_decode_float(LispObject env, LispObject a);

extern LispObject Nfp_infinite(LispObject env, LispObject a);
extern LispObject Nfp_nan(LispObject env, LispObject a);
extern LispObject Nfp_finite(LispObject env, LispObject a);
extern LispObject Nfp_subnorm(LispObject env, LispObject a);
extern LispObject Nfp_signbit(LispObject env, LispObject a);
extern LispObject Nfloat_digits(LispObject env, LispObject a);
extern LispObject Nfloat_precision(LispObject env, LispObject a);
extern LispObject Nfloat_radix(LispObject env, LispObject a);
extern LispObject Nfloat_sign1(LispObject env, LispObject a);
extern LispObject Nfloat_sign2(LispObject env, LispObject a, LispObject b);

extern LispObject Nrational(LispObject env, LispObject a);
extern LispObject Nmanexp(LispObject env, LispObject a);
extern LispObject Nrationalize(LispObject env, LispObject a);
extern LispObject Nrandom(LispObject env, LispObject a, LispObject bb);
extern LispObject Nrandom(LispObject env, LispObject a);
extern LispObject Nnext_random(LispObject);
extern LispObject Nmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Nmake_random_state(LispObject env, LispObject a);
extern LispObject Nmd5(LispObject env, LispObject a);
extern LispObject Nmd5string(LispObject env, LispObject a);
extern LispObject Nmd60(LispObject env, LispObject a);

extern LispObject Nxdifference(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ninorm(LispObject env, LispObject a, LispObject k);
extern LispObject Nboole(LispObject env, LispObject op,
                         LispObject a, LispObject b);
extern LispObject Nbyte(LispObject env, LispObject a, LispObject b);
extern LispObject Nbyte_position(LispObject env, LispObject a);
extern LispObject Nbyte_size(LispObject env, LispObject a);


extern LispObject Nplus(LispObject env);
extern LispObject Nplus(LispObject env, LispObject a1);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus);
extern LispObject Ntimes(LispObject env);
extern LispObject Ntimes(LispObject env, LispObject a1);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3);
extern LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus);
extern LispObject Nexpt(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngcdn(LispObject env);
extern LispObject Ngcdn(LispObject env, LispObject a1);
extern LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus);
extern LispObject Nlcmn(LispObject env);
extern LispObject Nlcmn(LispObject env, LispObject a1);
extern LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus);
extern LispObject Ndifference(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nquotient(LispObject env, LispObject a1, LispObject a2);
extern LispObject NCLQuotient(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nremainder(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmod(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ndivide(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nadd1(LispObject env, LispObject a1);
extern LispObject Nsub1(LispObject env, LispObject a1);
extern LispObject Nonep(LispObject env, LispObject a1);
extern LispObject Nevenp(LispObject env, LispObject a1);
extern LispObject Noddp(LispObject env, LispObject a1);
extern LispObject Nzerop(LispObject env, LispObject a1);
extern LispObject Nminusp(LispObject env, LispObject a1);
extern LispObject Nplusp(LispObject env, LispObject a1);
extern LispObject Nminus(LispObject env, LispObject a1);
extern LispObject Nabs(LispObject env, LispObject a1);
extern LispObject Nreciprocal(LispObject env, LispObject a1);
extern LispObject Nsqrt(LispObject env, LispObject a1);
extern LispObject Nisqrt(LispObject env, LispObject a1);
extern LispObject Nsquare(LispObject env, LispObject a1);
extern LispObject Nfloat(LispObject env, LispObject a1);
extern LispObject Nfloat(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nfix(LispObject env, LispObject a1);
extern LispObject Ntruncate(LispObject env, LispObject a1);
extern LispObject Nfloor(LispObject env, LispObject a1);
extern LispObject Nceiling(LispObject env, LispObject a1);
extern LispObject Nftruncate(LispObject env, LispObject a1);
extern LispObject Nffloor(LispObject env, LispObject a1);
extern LispObject Nfceiling(LispObject env, LispObject a1);
extern LispObject Ntruncate(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nfloor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nceiling(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nftruncate(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nffloor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nfceiling(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nfloat128(LispObject env, LispObject a1);
extern LispObject Nfrexp(LispObject env, LispObject a1);
extern LispObject Nldexp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Ngreaterp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3, LispObject a4plus);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);
extern LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2);
extern LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus);
extern LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2);
extern LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus);
extern LispObject Nneqn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus);
extern LispObject Nmax(LispObject env);
extern LispObject Nmax(LispObject env, LispObject a1);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nmax(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);
extern LispObject Nmin(LispObject env);
extern LispObject Nmin(LispObject env, LispObject a1);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nmin(LispObject env, LispObject a1, LispObject a2,
                                       LispObject a3, LispObject a4plus);
extern LispObject Nlogand(LispObject env);
extern LispObject Nlogand(LispObject env, LispObject a1);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlogand(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nlogor(LispObject env);
extern LispObject Nlogor(LispObject env, LispObject a1);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                                         LispObject a3, LispObject a4plus);
extern LispObject Nlogxor(LispObject env);
extern LispObject Nlogxor(LispObject env, LispObject a1);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlogxor(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nlogeqv(LispObject env);
extern LispObject Nlogeqv(LispObject env, LispObject a1);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nlogeqv(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nlognot(LispObject env, LispObject a1);
extern LispObject Nlsd(LispObject env, LispObject a1);
extern LispObject Nmsd(LispObject env, LispObject a1);
extern LispObject Nlogcount(LispObject env, LispObject a1);
extern LispObject Nleftshift(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nash1(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nrightshift(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_plus(LispObject env);
extern LispObject Nmodular_plus(LispObject env, LispObject a1);
extern LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nmodular_plus(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nmodular_times(LispObject env);
extern LispObject Nmodular_times(LispObject env, LispObject a1);
extern LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nmodular_times(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nmodular_expt(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_difference(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_quotient(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodular_reciprocal(LispObject env, LispObject a1);
extern LispObject Nmodular_minus(LispObject env, LispObject a1);
extern LispObject Nset_modulus(LispObject env, LispObject a1);
extern LispObject Nmodular_number(LispObject env, LispObject a1);
extern LispObject Niplus(LispObject env);
extern LispObject Niplus(LispObject env, LispObject a1);
extern LispObject Niplus(LispObject env, LispObject a1, LispObject a2);
extern LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nitimes(LispObject env);
extern LispObject Nitimes(LispObject env, LispObject a1);
extern LispObject Nitimes(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nitimes(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nitimes(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Niexpt(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nigcdn(LispObject env);
extern LispObject Nigcdn(LispObject env, LispObject a1);
extern LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilcmn(LispObject env);
extern LispObject Nilcmn(LispObject env, LispObject a1);
extern LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nidifference(LispObject env, LispObject a1, LispObject a2);
extern LispObject Niquotient(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nimod(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nidivide(LispObject env, LispObject a1, LispObject a2);
extern LispObject Niadd1(LispObject env, LispObject a1);
extern LispObject Nisub1(LispObject env, LispObject a1);
extern LispObject Nionep(LispObject env, LispObject a1);
extern LispObject Nievenp(LispObject env, LispObject a1);
extern LispObject Nioddp(LispObject env, LispObject a1);
extern LispObject Nizerop(LispObject env, LispObject a1);
extern LispObject Niminusp(LispObject env, LispObject a1);
extern LispObject Niminus(LispObject env, LispObject a1);
extern LispObject Niabs(LispObject env, LispObject a1);
extern LispObject Nireciprocal(LispObject env, LispObject a1);
extern LispObject Nisquare(LispObject env, LispObject a1);
extern LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nigreaterp(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nigeq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilessp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilessp(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilessp(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nileq(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nieqn_a(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nineqn(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilogand(LispObject env);
extern LispObject Nilogand(LispObject env, LispObject a1);
extern LispObject Nilogand(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilogand(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilogand(LispObject env, LispObject a1,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilogor(LispObject env);
extern LispObject Nilogor(LispObject env, LispObject a1);
extern LispObject Nilogor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilogor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilogor(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilogxor(LispObject env);
extern LispObject Nilogxor(LispObject env, LispObject a1);
extern LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilogxor(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilogeqv(LispObject env);
extern LispObject Nilogeqv(LispObject env, LispObject a1);
extern LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2,
                                        LispObject a3);
extern LispObject Nilogeqv(LispObject env, LispObject a1, LispObject a2,
                                          LispObject a3, LispObject a4plus);
extern LispObject Nilognot(LispObject env, LispObject a1);
extern LispObject Nileftshift(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nirightshift(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmodf(LispObject env, LispObject a1);
extern LispObject Nrealpart(LispObject env, LispObject a);
extern LispObject Nimagpart(LispObject env, LispObject a);
extern LispObject Nnumerator(LispObject env, LispObject a);
extern LispObject Ndenominator(LispObject env, LispObject a);
extern LispObject Ncomplex_1(LispObject env, LispObject a);
extern LispObject Ncomplex_2(LispObject env, LispObject a, LispObject b);
extern LispObject Nconjugate(LispObject env, LispObject a);
extern LispObject Ndecode_long_float(LispObject a);
extern LispObject Ndecode_float(LispObject env, LispObject a);
extern LispObject Ninteger_decode_long_float(LispObject a);
extern LispObject Ninteger_decode_float(LispObject env, LispObject a);

extern LispObject Ntrap_floating_overflow(LispObject env, LispObject a);
extern LispObject Nfp_eval(LispObject env, LispObject a1, LispObject a2);

extern LispObject Nldb(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nldb_test(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nmask_field(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogbitp(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nlogtest(LispObject env, LispObject a1, LispObject a2);
extern LispObject Ndpb(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Ndeposit_field(LispObject env, LispObject a1, LispObject a2, LispObject a3);

extern LispObject Nlisp_fix_ratio(LispObject env, LispObject a1);
extern LispObject Nround(LispObject env, LispObject a1);
extern LispObject Nround(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nfround(LispObject env, LispObject a1);
extern LispObject Nfround(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nscale_float(LispObject env, LispObject a1, LispObject a2);
extern LispObject Nvalidate_number(LispObject env, LispObject a1);
extern LispObject Nvalidate_number(LispObject env, LispObject a1, LispObject a2);

#endif // header_arith_defs_h

// end of arith-defs.h
