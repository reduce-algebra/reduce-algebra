
  fun FontDef f  =
    if  isDefined f  then  ()
                     else  (fontDef f;  addFont f)

  fun Font f  =
    if  sameFont f  then  ()
                    else  (FontDef f;  font f;  setFont f)

  fun resetMove ()  =  (resetX ();  resetY ())
  fun Move ()  =  (right (getX ());  down (getY ());  resetMove ())

  fun Obj setX x  =  (Move ();  setX x)

  fun DoChar charFun (font, ch)  =  (Font font;  Obj charFun ch)

  val SetChar   =   DoChar setChar
  val PutChar   =   DoChar putChar
  val SetRule   =   Obj    setRule
  val PutRule   =   Obj    putRule

  fun Right dx  =  moveX   dx
  fun Left  dx  =  moveX (~dx)
  fun Down  dy  =  moveY   dy
  fun Up    dy  =  moveY (~dy)

  fun Push ()  =  (     Move ();  push ();  incLevel ())
  fun Pop  ()  =  (resetMove ();  pop  ();  decLevel ())

  fun Bop ()  =
    ( markPos ();  nextPage ();  bop (actPage (), prevPos ()) )

  fun Eop ()  =  ( resetMove ();  resetFont ();  eop () )

  fun Pre mag  =  ( initState ();  pre mag )

  fun Post mag  =
    ( markPos ();
      post mag (actPage (), prevPos (), maxLevel ());
      fontDefs (definedFonts ());
      postpost (actPos ());
      markPos ();
      tail (actPos ())
    )

