
  fun IListToHList st insertPenalty iList  =
  let fun trans st prevKind  =
      fn []  =>  []
      |  IPen  pen  :: rest  =>  Penalty pen     ::  trans st  prevKind rest
      |  ISpace sp  :: rest  =>  makeSpace st sp  @  trans st  prevKind rest
      |  IStyle st' :: rest  =>                      trans st' prevKind rest
      |  INoad (actKind, hList) :: rest  =>
         let val newKind  =  changeKind  prevKind  actKind  rest
             val spaceList  =  makeSpaceOpt st (mathSpacing (prevKind, newKind))
             val penaltyList  =  mathPenalty  insertPenalty  newKind  rest
         in  spaceList  @  hList  @  penaltyList  @  trans st newKind rest  end
  in  trans st None iList  end
