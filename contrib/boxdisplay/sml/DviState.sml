
  fun incr (n: int) r  =  (r := !r + n)
  val inc  =  incr   1
  val dec  =  incr (~1)

  val xMove  =  ref 0
  fun getX   ()  =  !xMove
  fun moveX  dx  =  incr dx xMove
  fun resetX ()  =  (xMove := 0)

  val yMove  =  ref 0
  fun getY   ()  =  !yMove
  fun moveY  dy  =  incr dy yMove
  fun resetY ()  =  (yMove := 0)

  val noFont   =  ~1
  val actFont  =  ref noFont
  fun sameFont  f   =  (f = !actFont)
  fun setFont   f   =  (actFont := f)
  fun resetFont ()  =  (actFont := noFont)

  val fontList  =  ref ([]: fontNr list)
  fun isDefined f  =  contains (!fontList) f
  fun addFont   f  =  (fontList  :=  f :: !fontList)
  fun definedFonts ()  =  !fontList
  
  val pageNr  =  ref 0
  fun actPage  ()  =  !pageNr
  fun nextPage ()  =  inc pageNr

  val oldPos  =  ref (~1)
  val newPos  =  ref (~1)
  fun prevPos ()  =  !oldPos
  fun actPos  ()  =  !newPos
  fun markPos ()  =  (oldPos := !newPos;  newPos := outPos ())

  val ActLevel  =  ref 0
  val MaxLevel  =  ref 0
  fun incLevel ()  =  (inc ActLevel;
                       if  !ActLevel > !MaxLevel  then  inc MaxLevel  else  () )
  fun decLevel ()  =  dec ActLevel
  fun maxLevel ()  =  !MaxLevel

  fun initState ()  =
    ( xMove     :=  0;
      yMove     :=  0;
      actFont   :=  noFont;
      fontList  :=  [];
      pageNr    :=  0;
      oldPos    :=  (~1);
      newPos    :=  (~1);
      ActLevel  :=  0;
      MaxLevel  :=  0
    )

