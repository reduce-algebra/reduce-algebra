signature BASIC_CHAR  =
sig
  val basicChar: BasicTypes.style -> bool -> BasicTypes.family ->
  BasicTypes.charCode -> BoxTypes.node * BasicTypes.dist
end  (* signature BASIC_CHAR *)
(*----------*)

structure BasicChar: BASIC_CHAR  =
struct
  open BasicTypes;  open BoxTypes
  open CharInfo;  open CharFunctions

  fun basicChar st enlarge fam ch  =
  let val fontNr  =  fontNumber st fam
      val ch'     =  if  enlarge  then  larger (fontNr, ch)  else  ch
      val info    =  (fontNr, ch')
  in  (Char info, charItalic info)  end
end  (* structure BasicChar *)
