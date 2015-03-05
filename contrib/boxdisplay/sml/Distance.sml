signature DISTANCE  =
sig
  val zero :  BasicTypes.dist
  val one  :  BasicTypes.dist
  val half :  BasicTypes.dist -> BasicTypes.dist
  (* multiply distance with real factor *)
  val realMult :  real * BasicTypes.dist -> BasicTypes.dist
  (* integer to distance *)
  val distInt  :  int -> BasicTypes.dist
  (* fraction to distance *)
  val distRat  :  int * int -> BasicTypes.dist
  (* decimal fraction to distance *)
  val distReal :  real -> BasicTypes.dist
end
(*----------*)

structure Distance: DISTANCE  =
struct
  open BasicTypes
  open Powers2;  open General
  val zero =  0
  val one  =  two16       (* 2^16 *)
  fun half  d  =  d div 2
  fun realMult (r, d)  =  round (r * real d)
  fun distInt n  =  n * one
  fun distRat (num, den)  =  (one * num) div den
  fun distReal r  =  realMult (r, one)
end
