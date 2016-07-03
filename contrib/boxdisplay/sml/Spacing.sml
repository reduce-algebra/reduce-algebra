
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

