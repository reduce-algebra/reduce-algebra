signature MATH_TRANSLATE  =
sig
  val cleanBox:      BasicTypes.style -> bool -> MathTypes.mlist -> BoxTypes.box
  val doGenFraction: BasicTypes.style -> bool -> MathTypes.genfraction ->
  BoxTypes.box
  val doLeftRight:   BasicTypes.style -> bool -> BasicTypes.delim ->
  MathTypes.mlist -> BasicTypes.delim -> BoxTypes.box
  val doNucleus:     BasicTypes.style -> bool -> bool  -> MathTypes.mlist ->
  BoxTypes.node * BasicTypes.dist * bool
  val doGenScripts:  BasicTypes.style -> bool -> bool  -> bool  ->
  MathTypes.script -> BoxTypes.hlist
  val doBigOp:       BasicTypes.style -> bool -> MathTypes.limits ->
  MathTypes.script -> BoxTypes.hlist
  val NoadToHList:   BasicTypes.style -> bool -> MathTypes.noad  ->
  BoxTypes.hlist
  val MListToIList:  BasicTypes.style -> bool -> MathTypes.mlist ->
  IListTypes.ilist
  val MListToHList:  BasicTypes.style -> bool -> bool  -> MathTypes.mlist ->
  BoxTypes.hlist
end  (* signature MATH_TRANSLATE *)
(*----------*)

structure MathTranslate: MATH_TRANSLATE  =
struct
  open BasicTypes;  open BoxTypes;  open MathTypes;  open IListTypes
  open General;  open Distance;  open BoxPack;  open AxisCenter
  open Kind;  open ChangeStyle
  open MakeChar;  open Accent;  open Radical;  open Boundaries
  open MakeLine;  open GenFraction;  open MakeScripts;  open MakeLimOp
  open IListTranslate

  fun cleanBox st cr ml  =
      boxList (MListToHList st cr false (* no penalties! *) ml)

  and doGenFraction st cr {left, right, thickness, num, den}  =
  let val  st'      =  fract st
      val  numbox   =  cleanBox st' cr   num
      val  denbox   =  cleanBox st' true den
  in  makeGenFraction st thickness left right numbox denbox  end

  and doLeftRight st cr left ml right  =
  let val il   =  MListToIList st cr ml
      val il'  =  attachBoundaries st left right il
  in  boxList (IListToHList st false il')  end

  and doNucleus st _ isOp [MathChar (_, fam, ch)]  =  makeNucChar st isOp fam ch
  |   doNucleus st cr _    ml  =  (Box0 (cleanBox st cr ml), zero, false)

  and doGenScripts st cr limits isOp {nucleus, supOpt, subOpt}  =
  let val (nucNode, itCorr, isChar)  =  doNucleus st cr isOp nucleus
      val st'  =  script st
      val supOptBox  =  optMap (cleanBox st' cr)   supOpt
      val subOptBox  =  optMap (cleanBox st' true) subOpt
  in  if  limits
        then  HL  (makeLimOp st        itCorr nucNode supOptBox subOptBox)
        else  makeScripts st cr isChar itCorr nucNode supOptBox subOptBox
  end

  and doBigOp st cr lim script  =
  let val limits  =  (st = D  andalso  lim = default)  orelse  lim = yes
  in  doGenScripts st cr limits true script  end

  and NoadToHList st cr  =
  fn MathChar(_, fam, ch)  =>  makeChar st fam ch
  |  Radical    (del, ml)  =>  HL (makeRadical st del    (cleanBox st true ml))
  |  Accent (fam, ch, ml)  =>  HL (makeAccent  st fam ch (cleanBox st true ml))
  |  VCenter    ml  =>  [axisCenter   st (cleanBox st cr ml)]
  |  Overline   ml  =>  HL (makeOver  st (cleanBox st true ml))
  |  Underline  ml  =>  HL (makeUnder st (cleanBox st cr ml))
  |  GenFraction genFract  =>  HL (doGenFraction st cr genFract)
  |  LeftRight (left, ml, right)  =>  HL (doLeftRight st cr left ml right)
  |  Script script   =>  doGenScripts st cr false false script
  |  BigOp (lim, script)  =>  doBigOp st cr lim script
  |  SubBox   b    =>  HL b
  |  MList    ml   =>  HL (cleanBox st cr ml)
  |  Kind (k, ml)  =>  HL (cleanBox st cr ml)
  |  _             =>  raise CannotHappen
  (* MPen, MSpace, Style, and Choice are handled differently. *)

  and MListToIList st cr  =
  fn []  =>  []
  |  MPen   p     :: rest  =>  IPen   p   ::  MListToIList st  cr rest
  |  MSpace s     :: rest  =>  ISpace s   ::  MListToIList st  cr rest
  |  Style  st'   :: rest  =>  IStyle st' ::  MListToIList st' cr rest
  |  Choice chfun :: rest  =>  MListToIList st cr (chfun st @ rest)
  |  noad         :: rest  =>
       INoad (noadKind noad, NoadToHList st cr noad)
       :: MListToIList st cr rest

  and MListToHList st cr pen ml  =
  let val il  =  MListToIList st cr  ml
      val hl  =  IListToHList st pen il
  in  hl  end
end  (* structure MathTranslate *)
