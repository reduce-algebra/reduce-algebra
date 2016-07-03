  fun fontNumber st fam  =
    Vector.sub (fontNumberVector, 4 * famNr fam + styleNr st)
  fun larger  (pair as (_, ch))  =  optVal ch (charLarger pair)
