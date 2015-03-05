signature DELIMITER  =
sig
  val varDelimiter:  BasicTypes.style -> BasicTypes.dist -> BasicTypes.delim ->
  BoxTypes.node
  val makeDelimiter: BasicTypes.style -> BasicTypes.delim -> BoxTypes.node
end  (* signature DELIMITER *)
(*----------*)

structure Delimiter: DELIMITER  =
struct
  open BasicTypes;  open BoxTypes
  open Const;  open StyleParams
  fun varDelimiter  _ _ 0   =  Kern nullDelimiterSpace
  |   varDelimiter  _ _ _   =  raise (NotImplemented "varDelimiter")
  fun makeDelimiter st del  =  varDelimiter st (Delim st) del
end  (* structure Delimiter *)
