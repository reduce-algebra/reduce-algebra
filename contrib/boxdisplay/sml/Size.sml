signature SIZE  =
sig
  val size: BasicTypes.family -> BasicTypes.style -> BasicTypes.size
end  (* signature SIZE *)
(*-----------*)

structure Size: SIZE  =
struct
  open BasicTypes
  fun size _  D   =  10
  |   size _  T   =  10
  |   size EX _   =  10
  |   size _  S   =   7
  |   size _  SS  =   5
end
