
  fun instrArg code arg  =  (outNat1 code;  outNat1 arg)

  fun setChar ch  =  if  ch < 128  then  outNat1 ch  else  instrArg 128 ch
  val putChar  =  instrArg 133

  fun rule code (a, b)  =  (outNat1 code;  outInt4 a;  outInt4 b)
  val setRule  =  rule  132
  val putRule  =  rule  137

  val right   =  outInstrV  142
  val down    =  outInstrV  156

  fun push()  =  outNat1  141
  fun pop()   =  outNat1  142

  fun font f  =  outNat1 (171 + f)

  fun fontDef nr   =  
  let val (fam, s)  =  Vector.sub (famSizeVector, nr)
      val size  =  distInt s
      fun cmName RM  =  "cmr"    |   cmName MI  =  "cmmi"
      |   cmName SY  =  "cmsy"   |   cmName EX  =  "cmex"
      val fileName   =  cmName fam ^ Int.toString s
  in  instrArg 243 nr;  outZero 4;  outInt4 size;  outInt4 size;
                        outZero 1;  outString fileName
  end

  fun fontDefs    []     =  ()
  |   fontDefs (h :: t)  =  (fontDef h;  fontDefs t)

  fun bop (pageNr, prevPos)  =
      ( outNat1 139;  outInt4 pageNr;  outZero 36;  outInt4 prevPos)

  fun eop() = outNat1 140

  fun version() =  outNat1 2
  fun numDen() = (outInt4 25400000;  outInt4 473628672)
  fun banner() =  outString "Reinhold Heckmann's Formula Formatter"

  fun pre mag  =
      ( outNat1 247;  version ();  numDen ();  outInt4 mag;  banner () )

  fun trailer 0  =  ()
  |   trailer n  =  (outNat1 223;  trailer (n - 1))

  fun post mag (pageNr, prevPos, maxLevel)  =
      ( outNat1 248;  outInt4 prevPos;
        numDen ();  outInt4 mag;
        outInt4 (distInt (10 * 72));   (* maxVSize *)
        outInt4 (distInt ( 7 * 72));   (* maxWidth *)
        outNat2 maxLevel;  outNat2 pageNr )

  fun postpost postPos  =
      ( outNat1 249;  outInt4 postPos;  version ();  trailer 3 )

  fun tail ownPos  =  trailer (4 - ownPos mod 4)

