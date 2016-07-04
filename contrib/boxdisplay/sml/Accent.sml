signature ACCENT  =
sig
  val makeAccent: (BasicTypes.family * BasicTypes.charCode) option -> 
                  BasicTypes.style -> BasicTypes.family -> 
                  BasicTypes.charCode -> BoxTypes.box -> BoxTypes.box
end  (* signature ACCENT *)
(*----------*)

structure Accent: ACCENT  =
struct
  open BasicTypes;  open BoxTypes
  open Int
  open MakeChar; open CharInfo; open CharFunctions
  open StyleParams
  open NodeListDim; open Distance
  open MakeVBox; open BoxPack

  fun getSkew st (SOME (fam,ch)) = charAccentSkew (fontNumber st fam, ch)
    | getSkew _  NONE              = 0 

  fun widestAccent limit st fam ch =
  let val font = fontNumber st fam
  in case charLarger (font, ch) of 
       SOME ch' => if charWidth (font, ch') > limit then ch
                   else widestAccent limit st fam ch'
     | NONE     => ch 
  end

  fun makeAccent singleChar st fam ch box = 
  let val ch'        = widestAccent (#width box) st fam ch
      val accentBox  = boxList (makeChar st fam ch')
      val skew       = getSkew st singleChar
      val hzShift    = skew + half (#width box - #width accentBox)
      val vtKern     = min (#height box, xHeight st) 
  in upVBox (#width box) box [Kern (~vtKern), Box (hzShift, accentBox)] end

end  (* structure Accent *)
