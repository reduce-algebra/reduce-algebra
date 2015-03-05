signature FORMULA  =
sig
  val inlineFormula:  MathTypes.mlist -> BoxTypes.hlist
  val displayFormula: MathTypes.mlist -> BoxTypes.hlist
end  (* signature FORMULA *)
(*----------*)

structure Formula: FORMULA  =
struct
  open BasicTypes
  open MathTranslate

  val displayFormula  =  MListToHList D false false
  val inlineFormula   =  MListToHList T false true
end  (* structure Formula *)
