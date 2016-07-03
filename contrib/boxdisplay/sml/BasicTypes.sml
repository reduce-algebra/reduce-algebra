  type charCode =  int
  type penalty  =  int
  type dist     =  int
  type size     =  int

  datatype family  =  RM | MI | SY | EX
  fun famNr RM = 0  |  famNr MI = 1  |  famNr SY = 2  |  famNr EX = 3

  type delim    =  (family * int * family * int) option

  datatype style   =  D | T | S | SS
  fun styleNr D = 0  |  styleNr T = 1  |  styleNr S = 2  |  styleNr SS = 3

  (* These numbers are only needed for vector indexing. *)

  exception NotImplemented of string
  exception CannotHappen
