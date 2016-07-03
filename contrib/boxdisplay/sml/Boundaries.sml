  fun delimiterSize axisDist  =
      Int.max ((axisDist div 500) * delimiterFactor,   (* units of 1000! *)
           2 * axisDist - delimiterShortfall)

  fun makeBoundaries st height depth left right  =
  let val axh        =  AxisHeight st
      val axisDist   =  Int.max (height - axh, depth + axh)
      val delSize    =  delimiterSize axisDist
      val leftNode   =  varDelimiter st delSize left
      val rightNode  =  varDelimiter st delSize right
  in  (leftNode, rightNode)  end

  fun attachBoundaries st left right il  =
  let val height = ilistHeight il  and  depth = ilistDepth il
      val (leftNode, rightNode)  =  makeBoundaries st height depth left right
      fun makeIList kind node  =  [INoad (kind, [node])]
  in  makeIList Open leftNode  @  il  @  makeIList Close rightNode  end
