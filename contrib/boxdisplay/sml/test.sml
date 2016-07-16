(*
*)
open Input

fun test f x  =  (f x) handle (ex as BasicTypes.NotImplemented s)
              => (print "        ---> "; print s; print " <---"; raise ex)

val disp = test Formula.displayFormula
val line = test Formula.inlineFormula

fun form formula  =  ShipOut.shipOut [disp formula, line formula]

val bigop  =  sum (SOME (trans "i=1")) (SOME (trans "n"))

val mlar = trans "1+2=3"
val mlop = [bigop]
val mleq = bigop :: trans "i=" @ [fraction (trans "n.(n+1)") (trans "2")]
val one  = trans "1"
fun scr s  =  let val nuc = trans s
              in  [sub nuc one, sup nuc one, supsub nuc one one]  end
val mlss  =  scr "M" @ scr "P" @ scr "g" @ scr "f" @ scr "ac" @ scr "ab"

fun fss f  =  let val One = SOME one
              in  [f One NONE, f NONE One, f One One]  end

val mlss'  =  fss sum @ fss int @ scr "a" @ scr "b" @ scr "aa" @ scr "ab"

val overmlss'  =  [overline mlss']

val out = ShipOut.shipOut
fun test1 ()  =  (out [disp mlar, line mlar, disp mleq, line mleq]; "test1 complete")
fun test2 ()  =  (out [disp mlss', disp overmlss', line mlss', line overmlss']; "test2 complete")



val mlaccents = accent "check" (trans "a") :: trans "+" @ 
                accent "check" (trans "T") :: trans "+" @
                accent "hat" (trans "a")   :: trans "+" @
                [accent "tilde" (trans  "g")]
val mlwidehat = accent "widehat" (trans "a")   :: trans "+" @ 
                accent "widehat" (trans "aa")  :: trans "+" @
                [accent "widehat" (trans "aaa")]
val two = trans "2";
val mlaccentscripts = accent "check" (trans "a")           :: trans "+" @ 
                      trans "a+" @ 
                      sup [accent "check" (trans "a")] two :: trans "+" @
                      sup (trans "a") two :: trans "+" @
                      sub [accent "check" (trans "a")] two :: trans "+" @
                      sub (trans "a") two :: trans "+" @ 
                      supsub [accent "check" (trans  "a")] two two :: trans "+" @
                      [supsub (trans "a") two two]               

fun testaccents () = (out [line mlwidehat, line mlaccents, line mlaccentscripts]; "testaccents complete")

val mlradical = sqrt (trans "a") :: trans "=" @
                sqrt (trans "2x-3") :: trans "." @
                [sqrt [(supsub (trans "y") one one)]]
fun testradical () = (out [disp mlradical]; "testradical complete")

val mltall' = [atop [atop mlar mlar] [atop mlar mlar]]
val mltall = [atop mltall' mltall'] 
val mldelims = MathTypes.LeftRight (delim "lparen", mlar, delim "rparen") :: trans "+" @
               MathTypes.LeftRight (delim "langle", mleq, delim "rangle") :: trans "+" @
               [MathTypes.LeftRight (delim "lbracket", mltall, delim "rbracket")]
fun testdelims () = (out [line mldelims, disp mldelims]; "testdelims complete")