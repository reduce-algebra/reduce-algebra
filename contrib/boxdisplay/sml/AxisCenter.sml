signature AXIS_CENTER  =
sig
  val axisCenter: BasicTypes.style -> BoxTypes.box -> BoxTypes.node
end  (* signature AXIS_CENTER *)
(*----------*)

structure AxisCenter: AXIS_CENTER  =
struct
  open BasicTypes;  open BoxTypes
  open Distance;  open StyleParams
  fun axisCenter st box  =
  let val axh  =  AxisHeight st
      val h  =  #height box   and  d  =  #depth box
      val shift  =  half (h - d)  -  axh
  in  Box (shift, box)  end
  (* now the effective height is  h - shift = (h + d)/2 + axh,
     and the effective depth  is  d + shift = (h + d)/2 - axh.
     These are the values which Knuth directly assigns to height and depth. *)
end  (* structure AxisCenter *)
