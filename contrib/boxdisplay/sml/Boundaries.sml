signature BOUNDARIES  =
sig
  val makeBoundaries:    BasicTypes.style -> BasicTypes.dist -> BasicTypes.dist
  -> BasicTypes.delim -> BasicTypes.delim -> BoxTypes.node * BoxTypes.node
  val attachBoundaries:  BasicTypes.style -> BasicTypes.delim ->
  BasicTypes.delim -> IListTypes.ilist -> IListTypes.ilist
end  (* signature BOUNDARIES *)
(*----------*)

structure Boundaries: BOUNDARIES  =
struct
  open BasicTypes;  open BoxTypes;  open IListTypes
  open Const;  open StyleParams;  open Delimiter;  open IListDim
  open BoxPack; open AxisCenter 

  fun delimiterSize axisDist  =
      Int.max ((axisDist div 500) * delimiterFactor,   (* units of 1000! *)
           2 * axisDist - delimiterShortfall)

  fun makeBoundaries st height depth left right  =
  let val axh        =  AxisHeight st
      val axisDist   =  Int.max (height - axh, depth + axh)
      val delSize    =  delimiterSize axisDist
      val leftNode   =  boxList [varDelimiter st delSize left]
      val rightNode  =  boxList [varDelimiter st delSize right]
  in  (axisCenter st leftNode, axisCenter st rightNode)  end

  fun attachBoundaries st left right il  =
  let val height = ilistHeight il  and  depth = ilistDepth il
      val (leftNode, rightNode)  =  makeBoundaries st height depth left right
      fun makeIList kind node  =  [INoad (kind, [node])]
  in  makeIList Open leftNode  @  il  @  makeIList Close rightNode  end
end  (* structure Boundaries *)
