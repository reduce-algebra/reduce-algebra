signature GENERAL  =
sig
  val sum: int list -> int
  val Max: int list -> int
  val concat: 'a list list -> 'a list
  val contains:  ''a list -> ''a -> bool
  val revAppend:  'a list -> 'a list -> 'a list      (* rev a @ b *)
  val optVal:     'a -> 'a option -> 'a
  val optMap:     ('a -> 'b) -> 'a option -> 'b option
  val optFold:    'b -> ('a -> 'b) -> 'a option -> 'b
  val lookUp:       ''a -> (''a * 'b) list -> 'b option
end  (* signature GENERAL *)
(*----------*)

structure General: GENERAL  =
struct
(* Since functions such as `fold' and `exists' depend on the version,
   I program everything from the basic constructors. *)

  fun round r  =  trunc (r + 0.5)         (* "truncate" in other versions *)

  fun fold g c  =  let fun f    []     =  c
                       |   f (h :: t)  =  g (h, f t)
                   in  f  end

  val sum     =  fold (op +) 0
  val Max     =  fold Int.max 0

  (* This cannot be partially applied as otherwise we will have free type
     variables *)
  fun concat l =  fold (op @) [] l

  fun contains list x  =  let fun f    []     =  false
                              |   f (h :: t)  =  (h = x)  orelse  f t
                          in  f list  end

  fun revAppend    []     yl  =  yl
  |   revAppend (x :: xl) yl  =  revAppend xl (x :: yl)

  fun optMap f  =  fn NONE    =>  NONE
                   |  SOME x  =>  SOME (f x)

  fun optFold y f  =  fn NONE    =>  y
                      |  SOME x  =>  f x
 
  fun optVal y  =  optFold y (fn x => x)

  fun lookUp x  =
  let fun searchx          []        =  NONE
      |   searchx ((x', y) :: rest)  =  if  x = x'  then  SOME y
                                        else  searchx rest
  in  searchx  end

end  (* structure General *)
