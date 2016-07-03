
  fun makeVBox  w  node  upList  dnList  =    (* node: Box0 or Rule! *)
  let val h  =  vlistVsize upList + height node
      val d  =  vlistVsize dnList + depth  node
      val nodeList  =  revAppend upList (node :: dnList)
  in  vbox  {width = w,  height = h,  depth = d}  nodeList  end

  fun upVBox  w  box  upList   =   makeVBox w (Box0 box) upList []
  fun dnVBox  w  box  dnList   =   makeVBox w (Box0 box) [] dnList

  fun above n1 (dist1, dist) n2  =
  let val w  =  Int.max (vwidth n1, vwidth n2)
      val h  =  vsize n1 + dist1
      val d  =  vsize n2 + dist - dist1
      val nodeList  =  [n1, Kern dist, n2]
  in  Box0 (vbox  {width = w,  height = h,  depth = d}  nodeList)  end

