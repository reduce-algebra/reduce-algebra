
  fun makeChar st fam ch  =
  let val (charNode, itCorr)  =  basicChar st false fam ch
  in  extend itCorr charNode  end

  fun makeNucChar st isOp fam ch  =
  let val enlarge  =  isOp  andalso  st = D
      val (charNode, itCorr)  =  basicChar st enlarge fam ch
      val nucNode   =  if  isOp  then  axisCenter st (boxList [charNode])
                                 else  charNode
  in  (nucNode, itCorr, not isOp)  end
