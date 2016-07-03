  val zero =  0
  val one  =  two16       (* 2^16 *)
  fun half  d  =  d div 2
  fun realMult (r, d)  =  round (r * real d)
  fun distInt n  =  n * one
  fun distRat (num, den)  =  (one * num) div den
  fun distReal r  =  realMult (r, one)
