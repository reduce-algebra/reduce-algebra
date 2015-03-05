signature ACCENT  =
sig
  val makeAccent: BasicTypes.style -> BasicTypes.family -> BasicTypes.charCode
  -> BoxTypes.box -> BoxTypes.box
end  (* signature ACCENT *)
(*----------*)

structure Accent: ACCENT  =
struct
  open BasicTypes;  open BoxTypes
  fun makeAccent  st fam ch box  =  raise (NotImplemented "makeAccent")
end  (* structure Accent *)
