signature MATH_PENALTY  =
sig
  val mathPenalty:  bool -> MathTypes.kind -> IListTypes.ilist -> BoxTypes.hlist
end  (* signature MATH_PENALTY *)
(*----------*)

structure MathPenalty: MATH_PENALTY  =
struct
  open BoxTypes;  open MathTypes;  open IListTypes
  open Const

  val allowPenalty  =
  fn []                   =>  false
  |  IPen _         :: _  =>  false
  |  INoad (Rel, _) :: _  =>  false
  |  _                    =>  true

  fun makeList pen  =  if  pen = infPenalty  then  []  else  [Penalty pen]

  fun penaltyList Bin  =  makeList binopPenalty
  |   penaltyList Rel  =  makeList relPenalty
  |   penaltyList  _   =  []

  fun mathPenalty false _       _          =  []
  |   mathPenalty true  actKind restIList  =
        if  allowPenalty restIList  then  penaltyList actKind  else  []
end  (* structure MathPenalty *)
