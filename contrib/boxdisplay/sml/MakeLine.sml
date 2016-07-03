
  fun lineDist st  =  3 * RuleThickness st
  fun linePad  st  =      RuleThickness st

  fun makeLine constrVBox st box  =
  let val w  =  #width (box: box)
      val line  =  rule (RuleThickness st) w
  in  constrVBox w box [Kern (lineDist st),  line,  Kern (linePad st)]  end

  val makeOver   =  makeLine upVBox
  val makeUnder  =  makeLine dnVBox
