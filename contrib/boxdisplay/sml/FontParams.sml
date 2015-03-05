signature FONT_PARAMS  =
sig
  val math_x_height: BasicTypes.size -> BasicTypes.dist        (* height of `x' *)
  val math_quad:     BasicTypes.size -> BasicTypes.dist        (* width  of `M' *)
  val num1:   BasicTypes.size -> BasicTypes.dist    (* numerator shift-up in display style *)
  val num2:   BasicTypes.size -> BasicTypes.dist    (* ... in non-display, non-atop *)
  val num3:   BasicTypes.size -> BasicTypes.dist    (* ... in non-display atop *)
  val denom1: BasicTypes.size -> BasicTypes.dist    (* denominator shift-down in display style *)
  val denom2: BasicTypes.size -> BasicTypes.dist    (* ... in non-display styles *)
                              (* superscript shift-up ... *)
  val sup1:   BasicTypes.size -> BasicTypes.dist    (* ... in uncramped display style *)
  val sup2:   BasicTypes.size -> BasicTypes.dist    (* ... in uncramped non-display styles *)
  val sup3:   BasicTypes.size -> BasicTypes.dist    (* ... in cramped styles *)
                              (* subscript shift-down ... *)
  val sub1:   BasicTypes.size -> BasicTypes.dist    (* ... if superscript is absent *)
  val sub2:   BasicTypes.size -> BasicTypes.dist    (* ... if superscript is present *)
  val sup_drop: BasicTypes.size -> BasicTypes.dist  (* superscript baseline below top of large box *)
  val sub_drop: BasicTypes.size -> BasicTypes.dist  (* subscript baseline below bottom of large box *)
  val delim1: BasicTypes.size -> BasicTypes.dist    (* size of delimiters in display styles *)
  val delim2: BasicTypes.size -> BasicTypes.dist    (* size of delimiters in non-displays *)
  val axis_height: BasicTypes.size -> BasicTypes.dist
                        (* height of fraction lines above the baseline *)
  val default_rule_thickness: BasicTypes.size -> BasicTypes.dist
                        (* thickness of fraction strokes *)
  val big_op_spacing1: BasicTypes.size -> BasicTypes.dist  (* minimum clearance above *)
  val big_op_spacing2: BasicTypes.size -> BasicTypes.dist  (* minimum clearance below *)
  val big_op_spacing3: BasicTypes.size -> BasicTypes.dist  (* minimum baselineskip above *)
  val big_op_spacing4: BasicTypes.size -> BasicTypes.dist  (* minimum baselineskip below *)
  val big_op_spacing5: BasicTypes.size -> BasicTypes.dist  (* padding above and below *)
end  (* signature FONT_PARAMS *)
(*----------*)

structure FontParams: FONT_PARAMS  =
struct
  open BasicTypes;  open Size
  open Distance

  (* Most parameters are from the symbol fonts
     which exist in sizes 5 through 10.
     If possible, we used algebraic formulae instead of weird numbers. *)

  fun math_x_height s  =  distRat (31 * s, 72)

  fun math_quad 10  =  distInt 10            (* 360 / 36  =  40 / 4 *)
  |   math_quad  9  =  distRat ( 37,  4)     (* 333 / 36  =  37 / 4 *)
  |   math_quad  8  =  distRat ( 17,  2)     (* 306 / 36  =  34 / 4 *)
  |   math_quad  7  =  distRat (295, 36)     (* 295 / 36 *)
  |   math_quad  6  =  distRat ( 23,  3)     (* 276 / 36 *)
  |   math_quad  5  =  distRat (265, 36)     (* 265 / 36 *)

  fun num1 10  =  distReal 6.765080
  |   num1  9  =  distReal 5.820651
  |   num1  8  =  distReal 5.570648
  |   num1  7  =  distReal 5.126191
  |   num1  6  =  distReal 4.876188
  |   num1  5  =  distReal 4.626205

  fun num2 10  =  distReal 3.937320
  |   num2  9  =  distReal 3.687318
  |   num2  8  =  distReal 3.270664
  |   num2  7  =  distReal 2.687321
  |   num2  6  =  distReal 2.353986
  |   num2  5  =  distReal 1.937320

  fun num3 10  =  distReal 4.437310
  |   num3  9  =  distReal 4.048425
  |   num3  8  =  distReal 3.659544
  |   num3  7  =  distReal 3.298435
  |   num3  6  =  distReal 2.909544
  |   num3  5  =  distReal 2.520660

  fun denom1 10  =  distReal 6.859510
  |   denom1  9  =  distReal 6.104007
  |   denom1  8  =  distReal 5.992872
  |   denom1  7  =  distReal 5.265050
  |   denom1  6  =  distReal 5.181732
  |   denom1  5  =  distReal 5.126205

  fun denom2 10  =  distReal 3.448410
  |   denom2  9  =  distReal 3.054015
  |   denom2  8  =  distReal 3.137328
  |   denom2  7  =  distReal 2.409498
  |   denom2  6  =  distReal 2.576184
  |   denom2  5  =  distReal 2.659545

  (* Auxiliary function *)
  fun sup_sum 10  =  distRat (749, 100)
  |   sup_sum  9  =  distRat (699, 100)
  |   sup_sum  8  =  distRat (599, 100)
  |   sup_sum  7  =  distRat (549, 100)
  |   sup_sum  6  =  distRat (499, 100)
  |   sup_sum  5  =  distRat (449, 100)

  fun sup_drop 10  =  distRat (139, 36)
  |   sup_drop  9  =  distRat (114, 36)
  |   sup_drop  8  =  distRat (114, 36)
  |   sup_drop  _  =  distRat ( 89, 36)

  fun sup2 s  =  sup_sum s - sup_drop s
  fun sup1 s  =  sup2 s + distRat (1, 2)

  fun sup3 10  =  distRat (26,  9)      (* 104 / 36 *)
  |   sup3  9  =  distRat (31, 12)      (*  93 / 36 *)
  |   sup3  8  =  distRat (41, 18)      (*  82 / 36 *)
  |   sup3  7  =  distInt 2             (*  72 / 36 *)
  |   sup3  6  =  distRat (31, 18)      (*  62 / 36 *)
  |   sup3  5  =  distRat (53, 36)      (*  53 / 36 *)

  fun sub1 10  =  distRat (3, 2)
  |   sub1  _  =  one

  fun sub2 10  =  distRat (89, 36)
  |   sub2  9  =  distRat (19, 12)
  |   sub2  _  =  distInt 2

  fun sub_drop _  =  distRat (1, 2)

  fun delim1 10  =  distRat (239, 10)
  |   delim1  9  =  distRat (239, 10)
  |   delim1  8  =  distRat (119, 10)
  |   delim1  7  =  distRat (119, 10)
  |   delim1  6  =  distRat (119, 10)
  |   delim1  5  =  distRat ( 99, 10)

  fun delim2 10  =  distRat (101, 10)
  |   delim2  9  =  distRat ( 91, 10)
  |   delim2  8  =  distRat ( 91, 10)
  |   delim2  7  =  distRat ( 81, 10)
  |   delim2  6  =  distRat ( 81, 10)
  |   delim2  5  =  distRat ( 71, 10)

  fun axis_height s  =  distRat (s, 4)

  (* The following are taken from the math extension fonts
     which exist in sizes 10 and 9 only. *)

  fun default_rule_thickness s  =  distRat (10 + s, 50)

  fun big_op_spacing1 s  =  distRat (s, 9)
  fun big_op_spacing2 s  =  distRat (s, 6)
  fun big_op_spacing3 s  =  distRat (s, 5)
  fun big_op_spacing4 s  =  distRat (4 + 5 * s, 9)
  fun big_op_spacing5 s  =  one

end  (* structure FontParams *)
