
  fun basicChar st enlarge fam ch  =
  let val fontNr  =  fontNumber st fam
      val ch'     =  if  enlarge  then  larger (fontNr, ch)  else  ch
      val info    =  (fontNr, ch')
  in  (Char info, charItalic info)  end
