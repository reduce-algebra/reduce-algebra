
  (* Invariant for horizontal stuff:
     reference point -> end point = reference point + (0, width)
     Invariant for vertical stuff:
     upper left corner -> lower left corner
  *)

  (* Characters *)
  fun outChar HBox info  =  SetChar info
  |   outChar VBox info  =
       ( Down (charHeight info);  PutChar info;  Down (charDepth info) )

  (* Rules *)
  fun outRule HBox {height, depth, width}  =
       ( Down depth;  SetRule (height + depth, width);  Up depth )
  |   outRule VBox {height, depth, width}  =
      let val vsize  =  height + depth
      in  Down vsize;  PutRule (vsize, width)  end

  (* Kerns *)
  fun outKern HBox  =  Right
  |   outKern VBox  =  Down

  (* Glue *)

  fun glueMult (r, ord) (d, ord')  =
  if  ord = ord'  then  realMult (r, d)  else  zero

  fun glueSize natural ({size, ...}: glueSpec)  =  size
  |   glueSize (stretching factor) {size, stretch, ...}  =
           size + glueMult factor stretch
  |   glueSize (shrinking  factor) {size, shrink,  ...}  =
           size - glueMult factor shrink

  fun outGlue kind glueParam glueSpec  =
      outKern kind (glueSize glueParam glueSpec)

