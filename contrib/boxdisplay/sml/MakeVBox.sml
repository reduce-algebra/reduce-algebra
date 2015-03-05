signature MAKE_VBOX  =
sig

  val makeVBox:  BasicTypes.dist -> BoxTypes.node -> BoxTypes.vlist -> BoxTypes.vlist -> BoxTypes.box
  (* 1. width,
     2. center node -> reference point,  (must be  Box0  or  Rule !!!)
     3. above center, enumerated from bottom to top,
     4. below center, enumerated from top to bottom
   *)

  val upVBox:    BasicTypes.dist -> BoxTypes.box -> BoxTypes.vlist -> BoxTypes.box
  (* 1. width,
     2. center box -> reference point,
     3. above center, enumerated from bottom to top
   *)

  val dnVBox:    BasicTypes.dist -> BoxTypes.box -> BoxTypes.vlist -> BoxTypes.box
  (* 1. width,
     2. center box -> reference point,
     3. below center, enumerated from top to bottom
   *)

   val above:    BoxTypes.node -> (BasicTypes.dist * BasicTypes.dist) -> BoxTypes.node -> BoxTypes.node
   (* above n1 (dist1, dist) n2:
      Nodes n1 and n2 are placed above each other.
      dist     vertical distance between n1 and n2,
      dist1    distance from bottom of n1 to baseline
      The pairing of the two distances simplifies the calls of this function.
      The result is a node since all callers expect to see a node.
   *)
end  (* signature MAKE_VBOX *)
(*----------*)

structure MakeVBox: MAKE_VBOX  =
struct
  open BasicTypes;  open BoxTypes
  open General;  open BasicBox;  open NodeDim;  open NodeListDim

  fun makeVBox  w  node  upList  dnList  =    (* node: Box0 or Rule! *)
  let val h  =  vlistVsize upList + height node
      val d  =  vlistVsize dnList + depth  node
      val nodeList  =  revAppend upList (node :: dnList)
  in  vbox  {width = w,  height = h,  depth = d}  nodeList  end

  fun upVBox  w  box  upList   =   makeVBox w (Box0 box) upList []
  fun dnVBox  w  box  dnList   =   makeVBox w (Box0 box) [] dnList

  fun above n1 (dist1, dist) n2  =
  let val w  =  Int.max (vwidth n1, vwidth n2)
      val h  =  vsize n1 + dist1
      val d  =  vsize n2 + dist - dist1
      val nodeList  =  [n1, Kern dist, n2]
  in  Box0 (vbox  {width = w,  height = h,  depth = d}  nodeList)  end

end  (* structure MakeVBox *)
