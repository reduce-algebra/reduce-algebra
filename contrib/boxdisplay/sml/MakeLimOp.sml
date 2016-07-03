
  fun LimDist distFun posFun st size  =  Int.max (distFun st, posFun st - size)

  val LimSupDist   =  LimDist  BigOpSupDist  BigOpSupPos
  val LimSubDist   =  LimDist  BigOpSubDist  BigOpSubPos

  fun LimList distFun sizeFun st rightShift w pad  =
  optFold [] (fn box: box  =>
              let val dist  =  distFun st (sizeFun box)
              in  [Kern dist,  Box (rightShift, rebox w box),  Kern pad]  end)

  val SupList  =  LimList LimSupDist #depth
  val SubList  =  LimList LimSubDist #height

  fun makeLimOp st itCorr nucNode supOptBox subOptBox  =
  let val nucBox  =  boxList (extend itCorr nucNode)
      val optWidth  =  optFold zero (#width: box -> dist)
      val w  =  Int.max(optWidth supOptBox,
                  Int.max(#width nucBox, optWidth subOptBox))
      val pad  =  BigOpPadding st
      val shift  =  half itCorr
      val supList  =  SupList st   shift  w  pad  supOptBox
      val subList  =  SubList st (~shift) w  pad  subOptBox
      val nucItem  =  Box0 (rebox w nucBox)
  in  makeVBox w nucItem supList subList  end
