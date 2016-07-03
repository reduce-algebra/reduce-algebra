  type byte = Word8.word

  exception NoOut

  val out = ref (NONE: BinIO.outstream option)

  fun startOut fileName   =
    ( case  !out  of  NONE    =>  ()
                   |  SOME s  =>  BinIO.closeOut s;
      out := SOME (BinIO.openOut fileName) )

  fun getStream ()  =
      case  !out  of  NONE    =>  raise NoOut
                   |  SOME s  =>  s

  fun outByte b  =  BinIO.output1   (getStream (), b)

  fun outPos ()  =  BinIO.StreamIO.filePosOut (BinIO.getPosOut (getStream ()))

  fun endOut ()  =  BinIO.closeOut  (getStream ())

