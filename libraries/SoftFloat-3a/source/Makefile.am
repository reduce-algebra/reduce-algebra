# This Makefile.am is derived from a Makefile that was in the
# softfp library sources, and is subject to the same liberal license.
# This adaptation to use autoconf/automake (and not to try too hard to
# get highest speed) is by A C Norman, February 2016


#=============================================================================
#
# This Makefile is part of the SoftFloat IEEE Floating-Point Arithmetic
# Package, Release 3a, by John R. Hauser.
#
# Copyright 2011, 2012, 2013, 2014 The Regents of the University of
# California.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#  1. Redistributions of source code must retain the above copyright notice,
#     this list of conditions, and the following disclaimer.
#
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions, and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#  3. Neither the name of the University nor the names of its contributors
#     may be used to endorse or promote products derived from this software
#     without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
# DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#=============================================================================

lib_LIBRARIES = libsoftfloat.a

VPATH = $(srcdir):$(srcdir)/8086-SSE

SOFTFLOAT_PRIMITIVES = \
  s_eq128.c \
  s_le128.c \
  s_lt128.c \
  s_shortShiftLeft128.c \
  s_shortShiftRight128.c \
  s_shortShiftRightJam64.c \
  s_shortShiftRightJam64Extra.c \
  s_shortShiftRightJam128.c \
  s_shortShiftRightJam128Extra.c \
  s_shiftRightJam32.c \
  s_shiftRightJam64.c \
  s_shiftRightJam64Extra.c \
  s_shiftRightJam128.c \
  s_shiftRightJam128Extra.c \
  s_shiftRightJam256M.c \
  s_countLeadingZeros8.c \
  s_countLeadingZeros32.c \
  s_countLeadingZeros64.c \
  s_add128.c \
  s_add256M.c \
  s_sub128.c \
  s_sub256M.c \
  s_mul64ByShifted32To128.c \
  s_mul64To128.c \
  s_mul128By32.c \
  s_mul128To256M.c \
  s_approxRecip32_1.c \
  s_approxRecipSqrt32_1.c

SOFTFLOAT_SPECIALIZE = \
  softfloat_raiseFlags.c \
  s_f32UIToCommonNaN.c \
  s_commonNaNToF32UI.c \
  s_propagateNaNF32UI.c \
  s_f64UIToCommonNaN.c \
  s_commonNaNToF64UI.c \
  s_propagateNaNF64UI.c \
  extF80M_isSignalingNaN.c \
  s_extF80UIToCommonNaN.c \
  s_commonNaNToExtF80UI.c \
  s_propagateNaNExtF80UI.c \
  f128M_isSignalingNaN.c \
  s_f128UIToCommonNaN.c \
  s_commonNaNToF128UI.c \
  s_propagateNaNF128UI.c

SOFTFLOAT_OTHERS = \
  s_roundPackToUI32.c \
  s_roundPackToUI64.c \
  s_roundPackToI32.c \
  s_roundPackToI64.c \
  s_normSubnormalF32Sig.c \
  s_roundPackToF32.c \
  s_normRoundPackToF32.c \
  s_addMagsF32.c \
  s_subMagsF32.c \
  s_mulAddF32.c \
  s_normSubnormalF64Sig.c \
  s_roundPackToF64.c \
  s_normRoundPackToF64.c \
  s_addMagsF64.c \
  s_subMagsF64.c \
  s_mulAddF64.c \
  s_normSubnormalExtF80Sig.c \
  s_roundPackToExtF80.c \
  s_normRoundPackToExtF80.c \
  s_addMagsExtF80.c \
  s_subMagsExtF80.c \
  s_normSubnormalF128Sig.c \
  s_roundPackToF128.c \
  s_normRoundPackToF128.c \
  s_addMagsF128.c \
  s_subMagsF128.c \
  s_mulAddF128.c \
  softfloat_state.c \
  ui32_to_f32.c \
  ui32_to_f64.c \
  ui32_to_extF80.c \
  ui32_to_extF80M.c \
  ui32_to_f128.c \
  ui32_to_f128M.c \
  ui64_to_f32.c \
  ui64_to_f64.c \
  ui64_to_extF80.c \
  ui64_to_extF80M.c \
  ui64_to_f128.c \
  ui64_to_f128M.c \
  i32_to_f32.c \
  i32_to_f64.c \
  i32_to_extF80.c \
  i32_to_extF80M.c \
  i32_to_f128.c \
  i32_to_f128M.c \
  i64_to_f32.c \
  i64_to_f64.c \
  i64_to_extF80.c \
  i64_to_extF80M.c \
  i64_to_f128.c \
  i64_to_f128M.c \
  f32_to_ui32.c \
  f32_to_ui64.c \
  f32_to_i32.c \
  f32_to_i64.c \
  f32_to_ui32_r_minMag.c \
  f32_to_ui64_r_minMag.c \
  f32_to_i32_r_minMag.c \
  f32_to_i64_r_minMag.c \
  f32_to_f64.c \
  f32_to_extF80.c \
  f32_to_extF80M.c \
  f32_to_f128.c \
  f32_to_f128M.c \
  f32_roundToInt.c \
  f32_add.c \
  f32_sub.c \
  f32_mul.c \
  f32_mulAdd.c \
  f32_div.c \
  f32_rem.c \
  f32_sqrt.c \
  f32_eq.c \
  f32_le.c \
  f32_lt.c \
  f32_eq_signaling.c \
  f32_le_quiet.c \
  f32_lt_quiet.c \
  f32_isSignalingNaN.c \
  f64_to_ui32.c \
  f64_to_ui64.c \
  f64_to_i32.c \
  f64_to_i64.c \
  f64_to_ui32_r_minMag.c \
  f64_to_ui64_r_minMag.c \
  f64_to_i32_r_minMag.c \
  f64_to_i64_r_minMag.c \
  f64_to_f32.c \
  f64_to_extF80.c \
  f64_to_extF80M.c \
  f64_to_f128.c \
  f64_to_f128M.c \
  f64_roundToInt.c \
  f64_add.c \
  f64_sub.c \
  f64_mul.c \
  f64_mulAdd.c \
  f64_div.c \
  f64_rem.c \
  f64_sqrt.c \
  f64_eq.c \
  f64_le.c \
  f64_lt.c \
  f64_eq_signaling.c \
  f64_le_quiet.c \
  f64_lt_quiet.c \
  f64_isSignalingNaN.c \
  extF80_to_ui32.c \
  extF80_to_ui64.c \
  extF80_to_i32.c \
  extF80_to_i64.c \
  extF80_to_ui32_r_minMag.c \
  extF80_to_ui64_r_minMag.c \
  extF80_to_i32_r_minMag.c \
  extF80_to_i64_r_minMag.c \
  extF80_to_f32.c \
  extF80_to_f64.c \
  extF80_to_f128.c \
  extF80_roundToInt.c \
  extF80_add.c \
  extF80_sub.c \
  extF80_mul.c \
  extF80_div.c \
  extF80_rem.c \
  extF80_sqrt.c \
  extF80_eq.c \
  extF80_le.c \
  extF80_lt.c \
  extF80_eq_signaling.c \
  extF80_le_quiet.c \
  extF80_lt_quiet.c \
  extF80_isSignalingNaN.c \
  extF80M_to_ui32.c \
  extF80M_to_ui64.c \
  extF80M_to_i32.c \
  extF80M_to_i64.c \
  extF80M_to_ui32_r_minMag.c \
  extF80M_to_ui64_r_minMag.c \
  extF80M_to_i32_r_minMag.c \
  extF80M_to_i64_r_minMag.c \
  extF80M_to_f32.c \
  extF80M_to_f64.c \
  extF80M_to_f128M.c \
  extF80M_roundToInt.c \
  extF80M_add.c \
  extF80M_sub.c \
  extF80M_mul.c \
  extF80M_div.c \
  extF80M_rem.c \
  extF80M_sqrt.c \
  extF80M_eq.c \
  extF80M_le.c \
  extF80M_lt.c \
  extF80M_eq_signaling.c \
  extF80M_le_quiet.c \
  extF80M_lt_quiet.c \
  f128_to_ui32.c \
  f128_to_ui64.c \
  f128_to_i32.c \
  f128_to_i64.c \
  f128_to_ui32_r_minMag.c \
  f128_to_ui64_r_minMag.c \
  f128_to_i32_r_minMag.c \
  f128_to_i64_r_minMag.c \
  f128_to_f32.c \
  f128_to_extF80.c \
  f128_to_f64.c \
  f128_roundToInt.c \
  f128_add.c \
  f128_sub.c \
  f128_mul.c \
  f128_mulAdd.c \
  f128_div.c \
  f128_rem.c \
  f128_sqrt.c \
  f128_eq.c \
  f128_le.c \
  f128_lt.c \
  f128_eq_signaling.c \
  f128_le_quiet.c \
  f128_lt_quiet.c \
  f128_isSignalingNaN.c \
  f128M_to_ui32.c \
  f128M_to_ui64.c \
  f128M_to_i32.c \
  f128M_to_i64.c \
  f128M_to_ui32_r_minMag.c \
  f128M_to_ui64_r_minMag.c \
  f128M_to_i32_r_minMag.c \
  f128M_to_i64_r_minMag.c \
  f128M_to_f32.c \
  f128M_to_extF80M.c \
  f128M_to_f64.c \
  f128M_roundToInt.c \
  f128M_add.c \
  f128M_sub.c \
  f128M_mul.c \
  f128M_mulAdd.c \
  f128M_div.c \
  f128M_rem.c \
  f128M_sqrt.c \
  f128M_eq.c \
  f128M_le.c \
  f128M_lt.c \
  f128M_eq_signaling.c \
  f128M_le_quiet.c \
  f128M_lt_quiet.c

libsoftfloat_a_SOURCES = $(SOFTFLOAT_PRIMITIVES) \
	$(SOFTFLOAT_SPECIALIZE) $(SOFTFLOAT_OTHERS)

# I want the version of softfloat.h that is installed to capture all the
# options used to build this version.

softfloat_types.h:	platform.h $(srcdir)/include/softfloat_types.h
	cat platform.h $(srcdir)/include/softfloat_types.h > softfloat_types.h

include_HEADERS = include/softfloat.h softfloat_types.h

# end of Makefile.am
