
  fun charInfo (fontNr, ch)  =  Vector.sub(Vector.sub(fontVector, fontNr), ch): charInfo

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

