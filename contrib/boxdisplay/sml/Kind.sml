
  fun nucKind [MathChar (k, _, _)]  =  k
  |   nucKind  ml                   =  Ord

  val noadKind  =
  fn MathChar (k, _, _)  =>  k
  |  Radical      _  =>  Ord
  |  Accent       _  =>  Ord
  |  VCenter      _  =>  Ord
  |  Overline     _  =>  Ord
  |  Underline    _  =>  Ord
  |  GenFraction  _  =>  Inner
  |  LeftRight    _  =>  Inner             (* 1191, TeX-Program *)
  |  Script {nucleus, ...}  =>  nucKind nucleus
  |  BigOp    _   =>  Op
  |  SubBox   _   =>  Ord
  |  MList    _   =>  Ord
  |  Kind (k, _)  =>  k
  |  _            =>  raise CannotHappen
  (* not called for the remaining possibilities:
     MPen, MSpace, Style, Choice *)
