signature OUT_DVI  =
sig
  val setChar  :  BasicTypes.charCode -> unit
  val putChar  :  BasicTypes.charCode -> unit
  val setRule  :  BasicTypes.dist * BasicTypes.dist -> unit
  val putRule  :  BasicTypes.dist * BasicTypes.dist -> unit
  val right    :  BasicTypes.dist -> unit
  val down     :  BasicTypes.dist -> unit
  val push     :             unit -> unit
  val pop      :             unit -> unit
  val font     : FontTypes.fontNr -> unit
  val fontDef  : FontTypes.fontNr -> unit
  val fontDefs : FontTypes.fontNr list -> unit
  val bop      :    int * int -> unit
  val eop      :         unit -> unit
  val pre      :          int -> unit
  val post     :  int -> int * int * int -> unit
  val postpost :  int -> unit
  val tail     :  int -> unit
end
(*----------*)

structure OutDvi: OUT_DVI  =
struct
  open BasicTypes;  open FontTypes
  open OutHigh
  open Distance;  open FontVector

  val instr    =  outNat1

  fun instrArg code arg  =  (instr code;  outNat1 arg)

  fun setChar ch  =  if  ch < 128  then  instr ch  else  instrArg 128 ch
  val putChar  =  instrArg 133

  fun rule code (a, b)  =  (instr code;  outInt4 a;  outInt4 b)
  val setRule  =  rule  132
  val putRule  =  rule  137

  val right   =  outInstrV  142
  val down    =  outInstrV  156

  val push    =  fn () => instr  141
  val pop     =  fn () => instr  142

  fun font f  =  instr (171 + f)

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
      ( instr 139;  outInt4 pageNr;  outZero 36;  outInt4 prevPos)

  val eop  =  fn () => instr 140

  val version  =  fn () =>  outNat1 2
  val numDen   =  fn () => (outInt4 25400000;  outInt4 473628672)
  val banner   =  fn () =>  outString "Reinhold Heckmann's Formula Formatter"

  fun pre mag  =
      ( instr 247;  version ();  numDen ();  outInt4 mag;  banner () )

  fun trailer 0  =  ()
  |   trailer n  =  (instr 223;  trailer (n - 1))

  fun post mag (pageNr, prevPos, maxLevel)  =
      ( instr 248;  outInt4 prevPos;
        numDen ();  outInt4 mag;
        outInt4 (distInt (10 * 72));   (* maxVSize *)
        outInt4 (distInt ( 7 * 72));   (* maxWidth *)
        outNat2 maxLevel;  outNat2 pageNr )

  fun postpost postPos  =
      ( instr 249;  outInt4 postPos;  version ();  trailer 3 )

  fun tail ownPos  =  trailer (4 - ownPos mod 4)

end
