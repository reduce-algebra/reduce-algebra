
  val sumsym    =  MathChar (Op,    EX,  80)
  val intsym    =  MathChar (Op,    EX,  82)

  fun sym ch  =  
  if  Char.isAlpha ch                      then  (Ord,   MI, ord ch)  else
  if  Char.isDigit ch  orelse  ch = #"@"   then  (Ord,   RM, ord ch)  else
  if  ch = #"("   orelse  ch = #"["   then  (Open,  RM, ord ch)  else
  if  ch = #")"   orelse  ch = #"]"   then  (Close, RM, ord ch)  else
  if  ch = #"="   orelse  ch = #":"   then  (Rel,   RM, ord ch)  else
  if  ch = #"<"   orelse  ch = #">"   then  (Rel,   MI, ord ch)  else
  if  contains [#"!", #"?", #";"]  ch   then  (Punct, RM, ord ch)  else
  case  ch  of
    #","  =>  (Punct, MI, 59)
  | #"+"  =>  (Bin,   RM, 43)
  | #"-"  =>  (Bin,   SY,  0)
  | #"*"  =>  (Bin,   SY,  3)
  | #"."  =>  (Bin,   SY,  1)
  | _     =>  raise (NotImplemented ("Character " ^ Char.toString ch))

  fun trans str  =  map (MathChar o sym) (String.explode str)

  val overline   =  Overline
  val underline  =  Underline

  fun fraction num den  =
  GenFraction {num = num, den = den, thickness = NONE,   left = NONE, right = NONE}

  fun atop top bot  =
  GenFraction {num = top, den = bot, thickness = SOME 0, left = NONE, right = NONE}

  fun sup    a b    =  Script {nucleus = a, supOpt = SOME b, subOpt = NONE}
  fun sub    a b    =  Script {nucleus = a, supOpt = NONE,   subOpt = SOME b}
  fun supsub a b c  =  Script {nucleus = a, supOpt = SOME b, subOpt = SOME c}

  fun bigop sym subopt supopt  =
  BigOp (default, {nucleus = [sym], supOpt = supopt, subOpt = subopt})

  val sum  =  bigop sumsym
  val int  =  bigop intsym

  fun math kind ml  =  Kind (kind, ml)

  val style = Style

  fun choice d t s ss  =  Choice (fn D => d | T => t | S => s | SS => ss)

  fun accent "hat"     base = Accent (RM, 94,  base)
    | accent "check"   base = Accent (RM, 20,  base)
    | accent "tilde"   base = Accent (RM, 126, base)
    | accent "widehat" base = Accent (EX, 98,  base)
    | accent _         _    = raise (NotImplemented "math accent")

  fun sqrt ml = Radical (SOME (SY, 112, EX, 112), ml)

  fun delim "lparen"   = SOME (RM, 40, EX, 0)
    | delim "rparen"   = SOME (RM, 41, EX, 1)
    | delim "lbracket" = SOME (RM, 91, EX, 2)
    | delim "rbracket" = SOME (RM, 93, EX, 3)
    | delim "langle"   = SOME (SY, 104, EX, 10)
    | delim "rangle"   = SOME (SY, 105, EX, 11)
    | delim "null"     = NONE

