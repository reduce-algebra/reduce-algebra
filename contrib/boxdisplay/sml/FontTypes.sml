  type fontNr  =  int
  type varCharInfo  =  {top: charCode option,
                        bot: charCode option,
                        rep: charCode}
  type charInfo  =  {width:    dist,
                     height:   dist,
                     depth:    dist,
                     itCorr:   dist,
                     accentSkew : dist,
                     larger:   charCode option,
                     varChar:  varCharInfo option}
  type font = charInfo Vector.vector
