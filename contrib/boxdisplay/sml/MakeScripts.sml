signature MAKE_SCRIPTS  =
sig
  val makeSup:
          BasicTypes.style -> bool -> bool -> BasicTypes.dist -> BoxTypes.node
          -> BoxTypes.box -> BoxTypes.hlist
  val makeSub:
          BasicTypes.style ->         bool ->   BoxTypes.node -> BoxTypes.box
          -> BoxTypes.hlist
  val makeSupSub:
          BasicTypes.style -> bool -> bool -> BasicTypes.dist -> BoxTypes.node
          -> BoxTypes.box -> BoxTypes.box -> BoxTypes.hlist
  val makeScripts:
          BasicTypes.style -> bool -> bool -> BasicTypes.dist -> BoxTypes.node
          -> BoxTypes.box option -> BoxTypes.box option -> BoxTypes.hlist
end  (* signature MAKE_SCRIPTS *)
(*----------*)

structure MakeScripts: MAKE_SCRIPTS  =
struct
  open BasicTypes;  open BoxTypes
  open StyleParams;  open Const
  open Distance;  open General;  open ChangeStyle
  open BasicBox;  open MakeVBox;  open NodeDim

  fun almost_xHeight st  =  (xHeight st * 4) div 5

  fun SupPos0 st isChar hnuc  =
      if  isChar  then  zero  else  hnuc - SupDrop (script st)

  fun SubPos0 st isChar dnuc  =
      if  isChar  then  zero  else  dnuc + SubDrop (script st)

  fun SupPos st cr isChar hnuc dsup  =
      Max [SupPos0 st isChar hnuc,  Sup cr st,    dsup + xHeight st div 4]

  fun SubAlonePos st isChar dnuc hsub  =
      Max [SubPos0 st isChar dnuc,  SubAlone st,  hsub - almost_xHeight st]

  fun SubWithSupPos st isChar dnuc  =
      Int.max (SubPos0 st isChar dnuc,  SubWithSup st)

  val minSupDist  =  almost_xHeight
  fun minSupSubDist st  =  4 * RuleThickness st

  fun SupSubDistances st cr isChar hnuc dsup dnuc hsub  =
  let val supDist  =  SupPos  st  cr   isChar hnuc dsup - dsup
      val subDist  =  SubWithSupPos st isChar dnuc      - hsub
      val Dist     =  supDist + subDist
      val supDist' =  Int.max (supDist,  minSupDist st)
      val Dist'    =  Int.max (Dist,  minSupSubDist st)
  in  (supDist', Dist')  end

  val extendScript  =  extend scriptSpace

  fun makeSup st cr isChar itCorr nucNode supBox  =
  let val shift  =  SupPos st cr isChar (height nucNode) (#depth supBox)
      val scriptNode  =  Box (~shift, supBox)
  in  extend itCorr nucNode @ extendScript scriptNode  end

  fun makeSub st isChar nucNode subBox  =
  let val shift  =  SubAlonePos st isChar (depth nucNode) (#height subBox)
      val scriptNode  =  Box (shift, subBox)
  in  nucNode :: extendScript scriptNode  end

  fun makeSupSub st cr isChar itCorr nucNode supBox subBox  =
  let val dnuc  =   depth nucNode  and  hnuc  =   height nucNode
      val dsup  =  #depth supBox   and  hsub  =  #height subBox
      val distances  =  SupSubDistances st cr isChar hnuc dsup dnuc hsub
      val scriptNode =  above (Box (itCorr, supBox)) distances (Box0 subBox)
  in  nucNode :: extendScript scriptNode  end

  fun makeScripts st cr isChar itCorr nucNode  =
    (fn NONE         =>
        (fn NONE         =>  extend itCorr nucNode
         |  SOME subBox  =>  makeSub st isChar nucNode subBox)
     |  SOME supBox  =>  
        (fn NONE         =>  makeSup st cr isChar itCorr nucNode supBox
         |  SOME subBox  =>  makeSupSub st cr isChar itCorr
                                        nucNode supBox subBox)
    )
end  (* structure MakeScripts *)
