
  fun hlistGlue  {width = w, height = h, depth = d}  dw  nl  =
  let val gp  =  getGlueParam dw nl
  in  {kind = HBox,  height = h,  depth = d,  width = w,
       content = nl,  glueParam = gp}
  end
