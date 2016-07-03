
  fun extractGlue  access  =
  let fun extr []              =  []
      |   extr (Glue gs :: t)  =  access gs :: extr t
      |   extr (_       :: t)  =               extr t
  in extr end

  fun addGlue ord  =
  let fun add            []     =  zero
      |   add ((s, ord') :: t)  =  if  ord = ord'  then  s + add t  else  add t
  in  add  end

  exception Rigid

  fun totalGlue gl  =
  let fun checkGlue []             =  raise Rigid
      |   checkGlue (ord :: rest)  =
          let val sum  =  addGlue ord gl
          in  if  sum = zero  then  checkGlue rest  else  (sum, ord)  end
  in  checkGlue [filll, fill, fil, normal]  end

  fun getGlueParam dw nl  =
    (if dw > zero then
       let val (str, order) = totalGlue (extractGlue #stretch nl)
       in  stretching ( (real dw) / real str, order )  end
     else if dw < zero then
       let val (shr, order) = totalGlue (extractGlue #shrink  nl)
       in  shrinking ( ~(real dw) / real shr, order )  end
     else natural
    )
    handle Rigid => natural

