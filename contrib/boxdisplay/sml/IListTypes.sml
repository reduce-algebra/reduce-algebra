
  datatype item  =
    INoad  of  kind * hlist
  | IPen   of  penalty
  | ISpace of  mathSpace
  | IStyle of  style

  type ilist  =  item list
