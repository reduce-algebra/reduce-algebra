
  fun fractMinDist D halfTh  =  6 * halfTh
  |   fractMinDist _ halfTh  =  2 * halfTh

  fun distances st axh halfTh dnum hden  =
  let val axisNum  =  fractNum st - axh
      and axisDen  =  Denom    st + axh
      val distNum  =  axisNum - halfTh - dnum
      and distDen  =  axisDen - halfTh - hden
      fun correct dist  =  Int.max (dist, fractMinDist st halfTh)
  in  (correct distNum,  correct distDen)  end

  fun makeFract  st  th  w  numBox  denBox  =
  let val halfTh  =  half th
      val axh     =  AxisHeight st
      val stroke  =  Rule {height = halfTh,  depth = halfTh,  width = w}
      val (distNum, distDen)  =
           distances st axh halfTh (#depth numBox) (#height denBox)
      fun makeList dist box  =  [Kern dist, Box0 box]
      val fractBox  =  makeVBox w stroke (makeList distNum numBox)
                                         (makeList distDen denBox)
  in  Box (~axh, fractBox)  end
