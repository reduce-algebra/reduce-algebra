
  val mag = 2000
  val lineSkip    =  distInt 50

  fun lines    []     =  ( )
  |   lines   [l]     =  ( setHList l )
  |   lines (h :: t)  =  ( setHList h;  Down lineSkip;  lines t )

  fun shipOut hlists  =
    ( startOut "das.dvi";
      Pre mag;
      Bop ();
      lines hlists;
      Eop ();
      Post mag;
      endOut ();
      ()
    )

