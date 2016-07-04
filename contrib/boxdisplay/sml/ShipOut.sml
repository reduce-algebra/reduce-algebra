signature SHIP_OUT  =
sig
  val shipOut: BoxTypes.hlist list -> unit
end

structure ShipOut: SHIP_OUT  =
struct
  open Out;  open DviCmd;  open SetBox
  open Distance

  val mag = 2000
  val lineSkip    =  distInt 50

  fun lines    []     =  ( )
  |   lines   [l]     =  ( setHList l )
  |   lines (h :: t)  =  ( setHList h;  Down lineSkip;  lines t )

  fun shipOut hlists  =
    ( startOut "das.dvi";
      Pre mag;
      Bop ();
      lines hlists;
      Eop ();
      Post mag;
      endOut ();
      ()
    )

end
