signature GLUE_CALCULATION  =
sig

  exception Rigid        (* cannot stretch / shrink *)

  val extractGlue: (BoxTypes.glueSpec -> (BasicTypes.dist * BoxTypes.infOrder)) ->
                   BoxTypes.node list -> (BasicTypes.dist * BoxTypes.infOrder) list
  (* Given an access function (#stretch or #shrink),
     the relevant glue information is extracted from a node list. *)

  val addGlue: BoxTypes.infOrder -> (BasicTypes.dist * BoxTypes.infOrder) list -> BasicTypes.dist
  (* This function adds up the glue values of the given infinity order. *)

  val totalGlue: (BasicTypes.dist * BoxTypes.infOrder) list -> BasicTypes.dist * BoxTypes.infOrder
  (* This function adds up the glue values in the list,
     separately by the infOrder,
     and returns the highest order where the sum does not cancel out to zero,
     and this sum *)

  val getGlueParam: BasicTypes.dist -> BoxTypes.node list -> BoxTypes.glueParam
  (* computes the glue parameter resulting from changing the natural size
     of the node list by the given amount *)
end  (* signature GLUE_CALCULATION *)
(*----------*)

structure GlueCalculation: GLUE_CALCULATION  =
struct
  open BasicTypes;  open BoxTypes
  open Distance;  open BasicBox

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

end  (* structure GlueCalculation *)
