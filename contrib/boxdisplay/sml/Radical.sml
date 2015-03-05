signature RADICAL  =
sig
  val makeRadical: BasicTypes.style -> BasicTypes.delim -> BoxTypes.box ->
  BoxTypes.box
end  (* signature RADICAL *)
(*----------*)

structure Radical: RADICAL  =
struct
  open BasicTypes;  open BoxTypes
  fun makeRadical st del box  =  raise (NotImplemented "makeRadical")
end  (* structure Radical *)
