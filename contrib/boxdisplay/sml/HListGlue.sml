signature HLIST_GLUE  =
sig
  val hlistGlue:  BoxTypes.dim -> BasicTypes.dist -> BoxTypes.hlist -> BoxTypes.box
  (* Arguments:
     1. desired width, plus (natural) height, plus (natural) depth
     2. difference between desired and natural width
  *)
end  (* signature HLIST_GLUE *)
(*----------*)

structure HListGlue: HLIST_GLUE  =
struct
  open BasicTypes
  open BoxTypes
  val getGlueParam  =  GlueCalculation.getGlueParam

  fun hlistGlue  {width = w, height = h, depth = d}  dw  nl  =
  let val gp  =  getGlueParam dw nl
  in  {kind = HBox,  height = h,  depth = d,  width = w,
       content = nl,  glueParam = gp}
  end
end  (* structure HListGlue *)
