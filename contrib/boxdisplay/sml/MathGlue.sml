
  val zeropair    =  (0, normal)

  val thinGlue  =  {size = 3, stretch =  zeropair,   shrink =  zeropair}
  val medGlue   =  {size = 4, stretch = (2, normal), shrink = (4, normal)}
  val thickGlue =  {size = 5, stretch = (5, normal), shrink =  zeropair}

  fun space always g  =  SOME {isMu = true, always = always, entry = SGlue g}
  val allstyles  =  space true
  val nonscript  =  space false

  val noSkip     =  NONE
  val thinSkip   =  allstyles thinGlue
  val medSkip    =  allstyles medGlue
  val thickSkip  =  allstyles thickGlue
  val thinSkip'  =  nonscript thinGlue
  val medSkip'   =  nonscript medGlue
  val thickSkip' =  nonscript thickGlue

