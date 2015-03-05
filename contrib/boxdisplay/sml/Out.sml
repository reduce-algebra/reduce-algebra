signature OUT  =
sig
  type byte
  val startOut  :  string -> unit
  val endOut    :  unit   -> unit
  val outByte   :  byte   -> unit
  val outPos    :  unit   -> int
  exception NoOut
end
(*----------*)

structure Out: OUT  =
struct
  open BinIO
  type byte = Word8.word
  exception NoOut

  val out = ref (NONE: outstream option)

  fun startOut fileName   =
    ( case  !out  of  NONE    =>  ()
                   |  SOME s  =>  closeOut s;
      out := SOME (openOut fileName) )

  fun getStream ()  =
      case  !out  of  NONE    =>  raise NoOut
                   |  SOME s  =>  s

  fun outByte b  =  output1   (getStream (), b)

  fun outPos ()  =  StreamIO.filePosOut (getPosOut (getStream ()))

  fun endOut ()  =  closeOut  (getStream ())

end
