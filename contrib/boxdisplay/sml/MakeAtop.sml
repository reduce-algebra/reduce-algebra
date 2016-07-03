
  fun atopMinDist D   =  7 * RuleThickness D
  |   atopMinDist st  =  3 * RuleThickness st

  fun atopDistances st dtop hbot  =
  let val distTop  =  atopNum st - dtop
      val distBot  =  Denom   st - hbot
      val dist     =  distTop + distBot
      val minDist  =  atopMinDist st
  in  if  dist >= minDist
          then  (distTop, dist)
          else  (distTop + half (minDist - dist), minDist)
  end

  fun makeAtop  st  topBox  botBox  =
  let val distances  =  atopDistances st (#depth topBox) (#height botBox)
  in  above (Box0 topBox) distances (Box0 botBox)  end
