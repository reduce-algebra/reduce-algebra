
  fun round r  =  trunc (r + 0.5)         (* "truncate" in other versions *)

  fun contains list x  =  let fun f    []     =  false
                              |   f (h :: t)  =  (h = x)  orelse  f t
                          in  f list  end

  fun revAppend    []     yl  =  yl
  |   revAppend (x :: xl) yl  =  revAppend xl (x :: yl)

  fun optMap f NONE    =  NONE
    | optMap f (SOME x)  =  SOME (f x)

  fun optFold y f NONE    =  y
    | optFold y f (SOME x)  =  f x
 
  fun optVal y NONE = y
    | optVal y (SOME x) = x

  fun lookUp x  =
  let fun searchx          []        =  NONE
      |   searchx ((x', y) :: rest)  =  if  x = x'  then  SOME y
                                        else  searchx rest
  in  searchx  end


