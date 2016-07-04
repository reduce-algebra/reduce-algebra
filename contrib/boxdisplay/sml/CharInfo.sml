signature CHAR_INFO  =
sig
  val charWidth  : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charHeight : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charDepth  : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charItalic : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charLarger : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode option
  val charAccentSkew : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.dist
  val charExtensible : FontTypes.fontNr * BasicTypes.charCode -> bool
  val charExtensibleTop : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode option
  val charExtensibleRep : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode
  val charExtensibleBot : FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode option 

end  (* signature CHAR_INFO *)
(*----------*)

structure CharInfo: CHAR_INFO  =
struct
  open Vector
(* infix 8 sub *)
  open BasicTypes;  open FontTypes
  open FontVector

  fun charInfo (fontNr, ch)  =  sub(sub(fontVector, fontNr), ch): charInfo

  fun charWidth   pair  =  #width  (charInfo pair)
  fun charHeight  pair  =  #height (charInfo pair)
  fun charDepth   pair  =  #depth  (charInfo pair)
  fun charItalic  pair  =  #itCorr (charInfo pair)
  fun charLarger  pair  =  #larger (charInfo pair)
  fun charAccentSkew pair = #accentSkew (charInfo pair)
  fun charExtensible pair = (isSome o #varChar) (charInfo pair)
  fun charExtensibleTop pair = (#top o valOf o #varChar) (charInfo pair)
  fun charExtensibleRep pair = (#rep o valOf o #varChar) (charInfo pair)
  fun charExtensibleBot pair = (#bot o valOf o #varChar) (charInfo pair)

end  (* structure CharInfo *)
