
  (* Most parameters are from the symbol fonts
     which exist in sizes 5 through 10.
     If possible, we used algebraic formulae instead of weird numbers. *)


  (* Note that the code here is dodgy to the extent that it only supports
     sized 5 to 10. I make a fallback to use size 10 values. *)

  fun math_x_height s  =  distRat (31 * s, 72)

  fun math_quad 10  =  distInt 10            (* 360 / 36  =  40 / 4 *)
  |   math_quad  9  =  distRat ( 37,  4)     (* 333 / 36  =  37 / 4 *)
  |   math_quad  8  =  distRat ( 17,  2)     (* 306 / 36  =  34 / 4 *)
  |   math_quad  7  =  distRat (295, 36)     (* 295 / 36 *)
  |   math_quad  6  =  distRat ( 23,  3)     (* 276 / 36 *)
  |   math_quad  5  =  distRat (265, 36)     (* 265 / 36 *)
  |   math_quad  _  =  distInt 10


  fun num1 10  =  distReal 6.765080
  |   num1  9  =  distReal 5.820651
  |   num1  8  =  distReal 5.570648
  |   num1  7  =  distReal 5.126191
  |   num1  6  =  distReal 4.876188
  |   num1  5  =  distReal 4.626205
  |   num1  _  =  distReal 6.785080

  fun num2 10  =  distReal 3.937320
  |   num2  9  =  distReal 3.687318
  |   num2  8  =  distReal 3.270664
  |   num2  7  =  distReal 2.687321
  |   num2  6  =  distReal 2.353986
  |   num2  5  =  distReal 1.937320
  |   num2  _  =  distReal 3.937320

  fun num3 10  =  distReal 4.437310
  |   num3  9  =  distReal 4.048425
  |   num3  8  =  distReal 3.659544
  |   num3  7  =  distReal 3.298435
  |   num3  6  =  distReal 2.909544
  |   num3  5  =  distReal 2.520660
  |   num3  _  =  distReal 4.437310

  fun denom1 10  =  distReal 6.859510
  |   denom1  9  =  distReal 6.104007
  |   denom1  8  =  distReal 5.992872
  |   denom1  7  =  distReal 5.265050
  |   denom1  6  =  distReal 5.181732
  |   denom1  5  =  distReal 5.126205
  |   denom1  _  =  distReal 6.859510

  fun denom2 10  =  distReal 3.448410
  |   denom2  9  =  distReal 3.054015
  |   denom2  8  =  distReal 3.137328
  |   denom2  7  =  distReal 2.409498
  |   denom2  6  =  distReal 2.576184
  |   denom2  5  =  distReal 2.659545
  |   denom2  _  =  distReal 3.448410

  (* Auxiliary function *)
  fun sup_sum 10  =  distRat (749, 100)
  |   sup_sum  9  =  distRat (699, 100)
  |   sup_sum  8  =  distRat (599, 100)
  |   sup_sum  7  =  distRat (549, 100)
  |   sup_sum  6  =  distRat (499, 100)
  |   sup_sum  5  =  distRat (449, 100)
  |   sup_sum  _  =  distRat (749, 100)

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
  |   sup3  _  =  distRat (26,  9)

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
  |   delim1  _  =  distRat (239, 10)

  fun delim2 10  =  distRat (101, 10)
  |   delim2  9  =  distRat ( 91, 10)
  |   delim2  8  =  distRat ( 91, 10)
  |   delim2  7  =  distRat ( 81, 10)
  |   delim2  6  =  distRat ( 81, 10)
  |   delim2  5  =  distRat ( 71, 10)
  |   delim2  _  =  distRat (101, 10)

  fun axis_height s  =  distRat (s, 4)

  (* The following are taken from the math extension fonts
     which exist in sizes 10 and 9 only. *)

  fun default_rule_thickness s  =  distRat (10 + s, 50)

  fun big_op_spacing1 s  =  distRat (s, 9)
  fun big_op_spacing2 s  =  distRat (s, 6)
  fun big_op_spacing3 s  =  distRat (s, 5)
  fun big_op_spacing4 s  =  distRat (4 + 5 * s, 9)
  fun big_op_spacing5 s  =  one

