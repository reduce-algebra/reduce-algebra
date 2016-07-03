
  fun famName RM = "RM"  |  famName MI = "MI"
  |   famName SY = "SY"  |  famName EX = "EX"

  fun sizeExt s  =  Int.toString (s div 10) ^ Int.toString (s mod 10)

  fun FileName fam s  =  famName fam ^ sizeExt s

  fun dig ch  =  ord ch - ord #"0"

  fun varChar NONE NONE NONE  =  NONE
  |   varChar t    b    r     =  SOME {top = t, bot = b, rep = valOf r}

(* BEGIN destructive file reading *)

  (* The next two functions read until the next end of line,
     consuming the newline character *)
  fun getDist size file  =
  realMult (valOf (Real.fromString (valOf (TextIO.inputLine file))), size)

  fun getOctal file  =
  let fun found n  =
      let val ch  =  valOf (TextIO.input1 file)
      in  if Char.isDigit ch  then  found (8 * n + dig ch)  else  n  end
  in  found 0  end

  (* The next function is called with an W ... R ahead,
     and reads until the next C or E, consuming this character *)
  fun getInfo size file  =
  let fun collect w h d i l t b r a =
      case  valOf(TextIO.input1 file)  of
        #"W"  =>  let val w'  =  getDist size file
                  in  collect w' h  d  i  l  t  b  r  a  end
      | #"H"  =>  let val h'  =  getDist size file
                  in  collect w  h' d  i  l  t  b  r  a  end
      | #"D"  =>  let val d'  =  getDist size file
                  in  collect w  h  d' i  l  t  b  r  a  end
      | #"I"  =>  let val i'  =  getDist size file
                  in  collect w  h  d  i' l  t  b  r  a  end
      | #"L"  =>  let val l'  =  SOME (getOctal file)
                  in  collect w  h  d  i  l' t  b  r  a  end
      | #"T"  =>  let val t'  =  SOME (getOctal file)
                  in  collect w  h  d  i  l  t' b  r  a  end
      | #"B"  =>  let val b'  =  SOME (getOctal file)
                  in  collect w  h  d  i  l  t  b' r  a  end
      | #"R"  =>  let val r'  =  SOME (getOctal file)
                  in  collect w  h  d  i  l  t  b  r' a  end
(* The M information is in fact at present ignored!!!! *)
      | #"M"  =>  let val m'  =  SOME (getOctal file)
                  in  collect w  h  d  i  l  t  b  r a  end
      | #"S"  =>  let val a' =   getDist size file
                  in  collect w  h  d  i  l  t  b  r  a' end
      (* The code above may be expressed simpler using references *)
      | code  =>  ({width  = w,  height = h,  depth = d,  itCorr = i,
                    accentSkew = a,
                    larger = l,  varChar  =  varChar t b r},
                   code = #"E")
  in  collect zero zero zero zero NONE NONE NONE NONE zero end

  fun getList size file  =
  let val _  =  TextIO.inputLine file    (* skips remainder of C line *)
      val (info, eof)  =  getInfo size file
  in  if  eof  then  [info]  else  info :: getList size file  end

  fun loadFont (fam, s)  =
  let val size  =  distInt s
      val fileName  =  FileName fam s
      val file  =  TextIO.openIn fileName
      val infoList  =  getList size file
  in  TextIO.closeIn file;  vector (infoList)  end

(* END destructive file reading *)

