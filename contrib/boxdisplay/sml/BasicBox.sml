signature BASIC_BOX  =
sig
  val rule: BasicTypes.dist -> BasicTypes.dist -> BoxTypes.node (* height and width *)
  val ssGlue:   BoxTypes.glueSpec
  val emptyBox: BoxTypes.box
  val hbox: BoxTypes.dim -> BoxTypes.hlist -> BoxTypes.box  (* constructs hbox with given dimensions *)
  val vbox: BoxTypes.dim -> BoxTypes.vlist -> BoxTypes.box  (* constructs vbox with given dimensions *)
  val extend: BasicTypes.dist -> BoxTypes.node -> BoxTypes.hlist     (* extends to the right *)
end  (* signature BASIC_BOX *)
(*----------*)

structure BasicBox: BASIC_BOX =
struct
  open BasicTypes;  open BoxTypes
  open Distance

  fun rule h w  =  Rule {height = h, depth = zero, width = w}

  val ssGlue:  glueSpec   =
  let val fil1  =  (one, fil)
  in  {size = zero,  stretch = fil1,  shrink = fil1}  end

  (* makebox: boxkind -> dim -> node list -> box
        constructs a box of given kind with given dimensions and content *)
  fun makebox boxkind {height = h, depth = d, width = w} nl  =
          {kind    = boxkind,
           height  = h,   depth = d,  width = w,
           content = nl,  glueParam = natural}

  (* hbox: dim -> hlist -> box
        constructs a hbox with given dimensions and content *)
  (* Need to explicitly declare parameters - value restriction stuff... *)
  fun hbox (d: dim) nl = makebox HBox d nl

  (* vbox: dim -> vlist -> box
        constructs a vbox with given dimensions and content *)
  (* Explicitly declare as above with hbox *)
  fun vbox (d: dim) nl  =  makebox VBox d nl

  val emptyBox : box  =
      hbox  {width = zero,  depth = zero,  height = zero}  []

  fun extend dist node  =
  let val extension  =  if  dist = zero  then  []  else  [Kern dist]
  in  node :: extension  end

end  (* structure BasicBox *)
