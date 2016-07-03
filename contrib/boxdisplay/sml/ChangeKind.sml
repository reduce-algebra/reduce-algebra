
  fun listKind [] = None
    | listKind (INoad (k, _) :: _) = k
    | listKind (_ :: t) = listKind t;

  fun checkPrev u  =  contains [Bin, Op, Rel, Open, Punct, None] u
  fun checkNext u  =  contains [Rel, Close, Punct, None] u

  fun changeKind  prevKind  Bin  rest  =
        if  checkPrev prevKind  orelse  checkNext (listKind rest)
        then  Ord  else  Bin
  |   changeKind  _  k  _   =   k
