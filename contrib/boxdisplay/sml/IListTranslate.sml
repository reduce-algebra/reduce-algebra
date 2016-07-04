signature ILIST_TRANSLATE  =
sig
  val IListToHList: BasicTypes.style -> bool -> IListTypes.ilist -> BoxTypes.hlist
end  (* signature ILIST_TRANSLATE *)
(*----------*)

structure IListTranslate: ILIST_TRANSLATE  =
struct
  open BasicTypes;  open BoxTypes;  open IListTypes
  open ChangeKind;  open MathSpace;  open Spacing;  open MathPenalty

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
end  (* structure IListTranslate *)
