signature NODE_LIST_DIM  =
sig
  (* Versions of width, height, and depth for node lists *)
  val hlistWidth:  BoxTypes.hlist -> BasicTypes.dist
  val hlistHeight: BoxTypes.hlist -> BasicTypes.dist
  val hlistDepth:  BoxTypes.hlist -> BasicTypes.dist
  val vlistVsize:  BoxTypes.vlist -> BasicTypes.dist
  val vlistWidth:  BoxTypes.vlist -> BasicTypes.dist
end  (* signature NODE_LIST_DIM *)
(*----------*)

structure NodeListDim: NODE_LIST_DIM  =
struct
  open General
  open NodeDim
  fun compute f g nl  =  f (map g nl)
  val hlistWidth   =  compute sum width
  val hlistHeight  =  compute Max height
  val hlistDepth   =  compute Max depth
  val vlistWidth   =  compute Max vwidth
  val vlistVsize   =  compute sum vsize
end  (* structure NodeListDim *)
