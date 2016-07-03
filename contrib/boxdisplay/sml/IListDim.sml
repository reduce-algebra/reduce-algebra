
  fun  ilistDim (f: hlist -> dist)  =
       fn []                     =>  zero
       |  INoad (_, hl) :: rest  =>  Int.max (f hl, ilistDim f rest)
       |  _             :: rest  =>                 ilistDim f rest

  val  ilistHeight  =  ilistDim  hlistHeight
  val  ilistDepth   =  ilistDim  hlistDepth
