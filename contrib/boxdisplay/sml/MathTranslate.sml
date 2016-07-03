
  fun isSingleChar [MathChar _] = true
    | isSingleChar _            = false

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

  and doGenScripts1 st cr limits isOp script =
  case #nucleus script of
    [Accent (fam, ch, ml)] =>
      let
        val noAccentScript = {nucleus=ml, supOpt=(#supOpt script), subOpt=(#subOpt script)}
        val noAccentHList = doGenScripts st cr limits isOp noAccentScript
        val nucleus = NoadToHList st cr (Accent (fam,ch,ml))
      in
        (hd nucleus) :: (tl noAccentHList)
      end
  | _                      => doGenScripts st cr limits isOp script


  and doBigOp st cr lim script  =
  let val limits  =  (st = D  andalso  lim = default)  orelse  lim = yes
  in  doGenScripts st cr limits true script  end

  and NoadToHList st cr  =
  fn MathChar(_, fam, ch)  =>  makeChar st fam ch
  |  Radical    (del, ml)  =>  HL (makeRadical st del    (cleanBox st true ml))
  |  Accent (fam, ch, ml)  =>  HL (makeAccent (isSingleChar ml) st fam ch (cleanBox st true ml))
  |  VCenter    ml  =>  [axisCenter   st (cleanBox st cr ml)]
  |  Overline   ml  =>  HL (makeOver  st (cleanBox st true ml))
  |  Underline  ml  =>  HL (makeUnder st (cleanBox st cr ml))
  |  GenFraction genFract  =>  HL (doGenFraction st cr genFract)
  |  LeftRight (left, ml, right)  =>  HL (doLeftRight st cr left ml right)
  |  Script script   =>  doGenScripts1 st cr false false script
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
