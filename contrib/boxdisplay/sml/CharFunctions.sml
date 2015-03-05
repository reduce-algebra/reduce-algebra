signature CHAR_FUNCTIONS  =
sig
  val fontNumber:   BasicTypes.style -> BasicTypes.family -> FontTypes.fontNr
  val larger:       FontTypes.fontNr * BasicTypes.charCode -> BasicTypes.charCode
end  (* signature CHAR_FUNCTIONS *)
(*----------*)

structure CharFunctions: CHAR_FUNCTIONS  =
struct
  open Vector
  open BasicTypes;  open FontTypes
  open General;  open FontVector;  open CharInfo
  fun fontNumber st fam  =  sub (fontNumberVector, 4 * famNr fam + styleNr st)
  fun larger  (pair as (_, ch))  =  optVal ch (charLarger pair)
end  (* structure CharFunctions *)
