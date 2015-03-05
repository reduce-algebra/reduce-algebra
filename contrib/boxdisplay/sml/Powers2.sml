signature POWERS2  =
sig
  val two6  :  int
  val two7  :  int
  val two8  :  int
  val two15 :  int
  val two16 :  int
  val two23 :  int
  val two24 :  int
  val two29 :  int
end  (* signature POWERS2 *)
(*----------*)

structure Powers2: POWERS2  =
struct
  val two6   =   64
  val two7   =  128
  val two8   =  256
  val two15  =  two7 * two8
  val two16  =  two8 * two8
  val two23  =  two7 * two16
  val two24  =  two8 * two16
  val two29  =  two6 * two23
end  (* structure Powers2 *)
