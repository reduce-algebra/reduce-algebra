structure FontTypes  =
struct
  open BasicTypes
  type fontNr  =  int
  type varCharInfo  =  {top: charCode option,
                        bot: charCode option,
                        rep: charCode option}
  type charInfo  =  {width:    dist,
                     height:   dist,
                     depth:    dist,
                     itCorr:   dist,
                     larger:   charCode option,
                     varChar:  varCharInfo option}
  type font = charInfo Vector.vector
end
