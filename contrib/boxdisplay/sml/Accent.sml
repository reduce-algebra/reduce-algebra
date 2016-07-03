
  fun makeAccent singleChar st fam ch box  =  
  let fun min a b = if a < b then a else b
      fun max a b = if a > b then a else b
      val x     = box
      val u     = #width box
      val s     = if not singleChar then 0 else
                  let val (Char c) = (hd o #content) box
                  in charAccentSkew c end
      fun selectLargestAccent ch = 
      let val fontNr   = fontNumber st fam
          val maybeCh' = charLarger (fontNr, ch)
      in case maybeCh' of 
           NONE     => ch
         | SOME ch' => if charWidth (fontNr, ch') <= u then selectLargestAccent ch' else ch end
      val ch'   = selectLargestAccent ch
      val chi   = xHeight st
      val delta = min (#height x) chi
      val y     = boxList (makeChar st fam ch')
      val y'    = Box (s + half (u - (#width y)), y)
      val vl    = [y', Kern (~delta), Box0 x]
      val w = #width x and d = #depth x
      val h = #height x - delta + #height y + #depth y
  in { kind=VBox, width=w, depth=d, height=h, content=vl, glueParam=natural } end


(*
let val accent = boxList (makeChar st fam ch)
      val (Box (0, boxx)) = makeAtop st accent box
  in boxx end
*)
