signature MAKE_CHAR  =
sig
  val makeChar:    BasicTypes.style -> BasicTypes.family -> BasicTypes.charCode
  -> BoxTypes.hlist
  val makeNucChar: BasicTypes.style -> bool -> BasicTypes.family ->
  BasicTypes.charCode -> BoxTypes.node * BoxTypes.dist * bool
end  (* signature MAKE_CHAR *)
(*----------*)

structure MakeChar: MAKE_CHAR  =
struct
  open BasicTypes;  open BoxTypes
  open BasicChar
  open BasicBox;  open BoxPack;  open AxisCenter

  fun makeChar st fam ch  =
  let val (charNode, itCorr)  =  basicChar st false fam ch
  in  extend itCorr charNode  end

  fun makeNucChar st isOp fam ch  =
  let val enlarge  =  isOp  andalso  st = D
      val (charNode, itCorr)  =  basicChar st enlarge fam ch
      val nucNode   =  if  isOp  then  axisCenter st (boxList [charNode])
                                 else  charNode
  in  (nucNode, itCorr, not isOp)  end
end  (* structure MakeChar *)
