
  fun makeGenFraction st thickness left right numBox denBox  =
  let val width    =  Int.max (#width numBox, #width denBox)
      val numBox'  =  rebox width numBox  and  denBox'  =  rebox width denBox
      val th       =  optVal (RuleThickness st) thickness
      val middle   =  if  th = zero  then  makeAtop  st numBox' denBox'
                                     else  makeFract st th width numBox' denBox'
      val leftNode   =  makeDelimiter st left
      val rightNode  =  makeDelimiter st right
  in  boxList [leftNode, middle, rightNode]  end
