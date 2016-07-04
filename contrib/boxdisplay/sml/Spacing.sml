signature SPACING  =
sig
  val mathSpacing: MathTypes.kind * MathTypes.kind -> MathTypes.mathSpace option
end  (* signature SPACING *)
(*----------*)

structure Spacing: SPACING  =
struct
  open MathTypes
  open MathGlue

  fun mathSpacing (None , _    )  =  noSkip
  |   mathSpacing (_    , None )  =  noSkip
  |   mathSpacing (Bin  , _    )  =  medSkip'
  |   mathSpacing (Open , _    )  =  noSkip
  |   mathSpacing (Punct, _    )  =  thinSkip'
  |   mathSpacing (_    , Bin  )  =  medSkip'
  |   mathSpacing (_    , Close)  =  noSkip
  |   mathSpacing (Rel  , Rel  )  =  noSkip
  |   mathSpacing (Rel  , Punct)  =  noSkip
  |   mathSpacing (Rel  , _    )  =  thickSkip'
  |   mathSpacing (_    , Rel  )  =  thickSkip'
  |   mathSpacing (_    , Op   )  =  thinSkip
  |   mathSpacing (_    , Inner)  =  thinSkip'
  |   mathSpacing (Inner, _    )  =  thinSkip'
  |   mathSpacing (Op   , Ord  )  =  thinSkip
  |   mathSpacing       _         =  noSkip

end  (* structure Spacing *)
