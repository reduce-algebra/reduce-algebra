signature SET_BOX  =
sig
  val setNode:   BoxTypes.boxkind -> BoxTypes.glueParam -> BoxTypes.node -> unit
  val setList:   BoxTypes.boxkind -> BoxTypes.glueParam -> BoxTypes.node list -> unit
  val setBox:    BoxTypes.boxkind -> BoxTypes.box -> unit
  val setHList:  BoxTypes.hlist -> unit
end
(*----------*)

structure SetBox: SET_BOX  =
struct
  open BasicTypes;  open BoxTypes
  open Distance
  open OutHigh;  open DviCmd;  open SetNode

  (* Invariant for horizontal stuff:
     reference point -> end point = reference point + (0, width)
     Invariant for vertical stuff:
     upper left corner -> lower left corner
  *)

  fun setNode kind  _ (Char info)  =  outChar kind info
  |   setNode HBox  _ (Box  (shift, b))  =
       ( Down  shift;  setBox HBox b;  Up   shift )
  |   setNode VBox  _ (Box  (shift, b))  =
       ( Right shift;  setBox VBox b;  Left shift )
  |   setNode kind  _ (Rule  dim)        =  outRule kind dim
  |   setNode kind gp (Glue  glue)       =  outGlue kind gp glue
  |   setNode kind  _ (Kern  size)       =  outKern kind size
  |   setNode _     _  _                 =  ()

  and setList kind gp  =  List.app (setNode kind gp)

  and setBox outerKind
      {kind,  glueParam,  content,  height,  depth,  width}  =
      let val out  =  setList kind glueParam
      in  if  outerKind = kind
              then  out content
          else if  outerKind = HBox
              then  ( Up   height;  out content;  Up   depth;  Right width )
              else  ( Down height;  out content;  Down depth;  Left  width )
      end

(* With push and pop:
  and setBox outerKind
      {kind,  glueParam,  content,  height,  depth,  width}  =
      let val out  =  setList kind glueParam
      in  if  outerKind = kind
              then  out content
          else if  outerKind = HBox
              then ( Push ();  Up   height;  out content;  Pop ();  Right width)
              else ( Down height;  Push ();  out content;  Pop ();  Down depth )
      end
*)

  val setHList  =  setBox VBox o BoxPack.boxList

end
