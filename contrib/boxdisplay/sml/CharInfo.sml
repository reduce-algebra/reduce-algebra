signature CHAR_INFO  =
sig
  val charWidth  : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charHeight : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charDepth  : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charItalic : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charLarger : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode option
end  (* signature CHAR_INFO *)
(*----------*)

structure CharInfo: CHAR_INFO  =
struct
  open Vector
  infix 8 sub
  open BasicTypes;  open FontTypes
  open FontVector

  fun charInfo (fontNr, ch)  =  (fontVector sub fontNr sub ch): charInfo

  fun charWidth   pair  =  #width  (charInfo pair)
  fun charHeight  pair  =  #height (charInfo pair)
  fun charDepth   pair  =  #depth  (charInfo pair)
  fun charItalic  pair  =  #itCorr (charInfo pair)
  fun charLarger  pair  =  #larger (charInfo pair)
end  (* structure CharInfo *)
