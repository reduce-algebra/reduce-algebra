signature CHANGE_STYLE  =
sig
  val fract:  BasicTypes.style -> BasicTypes.style
  val script: BasicTypes.style -> BasicTypes.style
end  (* signature CHANGE_STYLE *)
(*----------*)

structure ChangeStyle: CHANGE_STYLE  =
struct
  open BasicTypes
  fun fract D  =  T
  |   fract T  =  S
  |   fract _  =  SS

  fun script D  =  S
  |   script T  =  S
  |   script _  =  SS
end  (* structure ChangeStyle *)
