#!/bin/sh
#
# Usage: ./Fortran.sh [has_extended] > core_math.F90
#
# where "has_extended" should be specified only if the intended
# Fortran compiler is gfortran AND the platform is x86_64, i.e.,
# has a native support for the Intel's 80-bit extended datatype.
#
# The generated interfaces are packed into a module to facilitate
# a quick syntactic check with, e.g., gfortran -c core_math.F90,
# but can be used independently of the module and of each other.
#
# Contributed by: Vedran Novaković <venovako@gmail.com>
# For support, contact Vedran Novaković <venovako@gmail.com>
#
echo "module core_math"
echo "implicit none"
echo "! float unary functions"
for I in acos acosh acospi asin asinh asinpi atan atanh atanpi cbrt cos cosh cospi erf erfc exp exp10 exp10m1 exp2 exp2m1 expm1 lgamma log log10 log10p1 log1p log2 log2p1 rsqrt sin sinh sinpi tan tanh tanpi tgamma
do
	echo "interface"
	echo "   pure function cr_${I}f(x) bind(c,name='cr_${I}f')"
	echo "     use, intrinsic :: iso_c_binding, only: c_float"
	echo "     implicit none"
	echo "     real(kind=c_float), intent(in), value :: x"
	echo "     real(kind=c_float) :: cr_${I}f"
	echo "   end function cr_${I}f"
	echo "end interface"
done
echo "! float binary functions"
for I in atan2 atan2pi compound hypot pow
do
	echo "interface"
	echo "   pure function cr_${I}f(x, y) bind(c,name='cr_${I}f')"
	echo "     use, intrinsic :: iso_c_binding, only: c_float"
	echo "     implicit none"
	echo "     real(kind=c_float), intent(in), value :: x, y"
	echo "     real(kind=c_float) :: cr_${I}f"
	echo "   end function cr_${I}f"
	echo "end interface"
done
echo "! float sincos function"
I=sincos
echo "interface"
echo "   pure subroutine cr_${I}f(x, s, c) bind(c,name='cr_${I}f')"
echo "     use, intrinsic :: iso_c_binding, only: c_float"
echo "     implicit none"
echo "     real(kind=c_float), intent(in), value :: x"
echo "     real(kind=c_float), intent(out) :: s, c"
echo "   end subroutine cr_${I}f"
echo "end interface"
echo "! double unary functions"
for I in acos acosh acospi asin asinh asinpi atan atanh atanpi cbrt cos cosh cospi erf erfc exp exp10 exp10m1 exp2 exp2m1 expm1 lgamma log log10 log10p1 log1p log2 log2p1 rsqrt sin sinh sinpi tan tanh tanpi
do
	echo "interface"
	echo "   pure function cr_${I}(x) bind(c,name='cr_${I}')"
	echo "     use, intrinsic :: iso_c_binding, only: c_double"
	echo "     implicit none"
	echo "     real(kind=c_double), intent(in), value :: x"
	echo "     real(kind=c_double) :: cr_${I}"
	echo "   end function cr_${I}"
	echo "end interface"
done
echo "! double binary functions"
for I in atan2 atan2pi hypot pow
do
	echo "interface"
	echo "   pure function cr_${I}(x, y) bind(c,name='cr_${I}')"
	echo "     use, intrinsic :: iso_c_binding, only: c_double"
	echo "     implicit none"
	echo "     real(kind=c_double), intent(in), value :: x, y"
	echo "     real(kind=c_double) :: cr_${I}"
	echo "   end function cr_${I}"
	echo "end interface"
done
echo "! double sincos function"
I=sincos
echo "interface"
echo "   pure subroutine cr_${I}(x, s, c) bind(c,name='cr_${I}')"
echo "     use, intrinsic :: iso_c_binding, only: c_double"
echo "     implicit none"
echo "     real(kind=c_double), intent(in), value :: x"
echo "     real(kind=c_double), intent(out) :: s, c"
echo "   end subroutine cr_${I}"
echo "end interface"
if [ "$1" = "has_extended" ]
then
	echo "! extended unary functions"
	for I in cbrt exp exp2 log2 rsqrt
	do
		echo "interface"
		echo "   pure function cr_${I}l(x) bind(c,name='cr_${I}l')"
		echo "     use, intrinsic :: iso_c_binding, only: c_long_double"
		echo "     implicit none"
		echo "     real(kind=c_long_double), intent(in), value :: x"
		echo "     real(kind=c_long_double) :: cr_${I}l"
		echo "   end function cr_${I}l"
		echo "end interface"
	done
	echo "! extended binary functions"
	for I in hypot pow
	do
		echo "interface"
		echo "   pure function cr_${I}l(x, y) bind(c,name='cr_${I}l')"
		echo "     use, intrinsic :: iso_c_binding, only: c_long_double"
		echo "     implicit none"
		echo "     real(kind=c_long_double), intent(in), value :: x, y"
		echo "     real(kind=c_long_double) :: cr_${I}l"
		echo "   end function cr_${I}l"
		echo "end interface"
	done
fi
# Please uncomment the lines below if your Fortran compiler supports the REAL128 kind.
# echo "! quad unary functions"
# for I in cbrt exp rsqrt sqrt
# do
# 	echo "interface"
# 	echo "   pure function cr_${I}q(x) bind(c,name='cr_${I}q')"
# 	echo "     use, intrinsic :: iso_fortran_env, only: real128"
# 	echo "     implicit none"
# 	echo "     real(kind=real128), intent(in), value :: x"
# 	echo "     real(kind=real128) :: cr_${I}q"
# 	echo "   end function cr_${I}q"
# 	echo "end interface"
# done
# echo "! quad binary functions"
# for I in hypot
# do
# 	echo "interface"
# 	echo "   pure function cr_${I}q(x, y) bind(c,name='cr_${I}q')"
# 	echo "     use, intrinsic :: iso_fortran_env, only: real128"
# 	echo "     implicit none"
# 	echo "     real(kind=real128), intent(in), value :: x, y"
# 	echo "     real(kind=real128) :: cr_${I}q"
# 	echo "   end function cr_${I}q"
# 	echo "end interface"
# done
echo "end module core_math"
unset I
