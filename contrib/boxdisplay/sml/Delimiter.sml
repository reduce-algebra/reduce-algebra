
  fun charBox info = boxList [Char info]

  fun extensibleDelimiter size (fontNr, ch) = 
  let fun addFont ch = (fontNr, ch)
      val top = Option.map addFont (charExtensibleTop (fontNr, ch))
      val bot = Option.map addFont (charExtensibleBot (fontNr, ch))
      val rep = addFont (charExtensibleRep (fontNr, ch))
      val baseSize = getOpt(Option.map charHeight top, 0) + 
                     getOpt(Option.map charDepth  top, 0) +
                     getOpt(Option.map charHeight bot, 0) + 
                     getOpt(Option.map charDepth  bot, 0)
      val repSize = charHeight rep + charDepth rep
      val repN = 1 + (size - baseSize) div repSize
      val reps = List.tabulate(repN, fn _ => Char rep)
      val w = charWidth rep
      val vlist = if isSome bot then reps @ [Char (valOf bot)] else reps 
  in case top of
       NONE      => dnVBox w (boxList[hd vlist]) (tl vlist)
     | SOME top' => dnVBox w (charBox top') vlist 
  end

  fun varDelimiter'' size (fontNr, ch) = 
  if charHeight (fontNr, ch) + charDepth (fontNr, ch) >= size then charBox (fontNr, ch)
  else case charLarger (fontNr, ch) of
         SOME ch' => varDelimiter'' size (fontNr, ch')
       | NONE     => if charExtensible (fontNr, ch) 
                     then extensibleDelimiter size (fontNr, ch)
                     else charBox (fontNr, ch)

  fun varDelimiter  _  _    NONE                          =  Kern nullDelimiterSpace
  |   varDelimiter  st size (SOME (sfam, sch, lfam, lch)) = 
      let fun next (st', fam, ch) = 
              if      st' = T andalso fam = lfam then (T,  lfam, lch)
              else if st' = T                    then (st, lfam, lch)
              else if st' = S                    then (T,  fam,  ch)
              else                                    (S,  fam,  ch)
          fun search (st', fam, ch) = 
              let val fontNr = fontNumber st' fam 
                  val delim  = varDelimiter'' size (fontNr, ch)
                  val next'  = next (st', fam, ch)
              in if #height delim + #depth delim >= size then delim 
                 else if next' = (st', fam, ch)          then delim
                 else search next' 
              end
      in (Box0 o search) (st, sfam, sch) end

  fun makeDelimiter st del   =  varDelimiter st (Delim st) del
