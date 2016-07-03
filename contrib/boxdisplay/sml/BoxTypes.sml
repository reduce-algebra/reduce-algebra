  datatype infOrder   =  normal | fil | fill | filll
  datatype glueParam  =  natural
                      |  stretching of (real * infOrder)
                      |  shrinking  of (real * infOrder)

  type     glueSpec  =  {size:    dist,
                         stretch: dist * infOrder,
                         shrink:  dist * infOrder}
  type     dim  =  {width: dist, depth: dist, height: dist}
  datatype boxkind  =  HBox | VBox

  datatype node =
    Char    of  fontNr * charCode
  | Box     of  dist * box      (* dist = shift_amount *)
  | Rule    of  dim             (* no running dimensions! *)
  | Glue    of  glueSpec
  | Kern    of  dist
  | Penalty of  penalty
  withtype box  =
       {kind:      boxkind,
        width:     dist,
        depth:     dist,
        height:    dist,
        content:   node list,
        glueParam: glueParam}
  type hlist  =  node list
  type vlist  =  node list
  fun Box0 b  =  Box (0, b)        (* creates node with zero shift *)
  fun HL   b  =  [Box0 b]          (* creates horizontal list from box *)
