(*
 This is the Dutch version of TeX Maths Layout coded in SML, adjusted so
 it only uses a subset of SML. It also has some extensions that add support
 for accents and delimiters, and the aim is that eventually it should
 cover all maths.
*)

fun myValOf w (SOME x) = x
  | myValOf w (NONE)   = ( print ("valof failing at " ^ w ^ "\n");
                           raise Option );

use "General.sml";
use "Powers2.sml";
use "BasicTypes.sml";
use "Distance.sml";
use "Size.sml";
use "FontTypes.sml";
use "LoadFont.sml";
use "FontVector.sml";
use "CharInfo.sml";
use "CharFunctions.sml";
use "Const.sml";
use "FontParams.sml";
use "StyleParams.sml";
use "BoxTypes.sml";
use "BasicBox.sml";
use "NodeDim.sml";
use "NodeListDim.sml";
use "GlueCalculation.sml";
use "HListGlue.sml";
use "BoxPack.sml";
use "MakeVBox.sml";
use "AxisCenter.sml";
use "ChangeStyle.sml";
use "Radical.sml";
use "BasicChar.sml";
use "MakeChar.sml";
use "Accent.sml";
use "MakeLine.sml";
use "MakeAtop.sml";
use "MakeFract.sml";
use "Delimiter.sml";
use "GenFraction.sml";
use "MakeLimOp.sml";
use "MakeScripts.sml";
use "MathTypes.sml";
use "Kind.sml";
use "MathSpace.sml";
use "MathGlue.sml";
use "Spacing.sml";
use "IListTypes.sml";
use "IListDim.sml";
use "ChangeKind.sml";
use "MathPenalty.sml";
use "Boundaries.sml";
use "IListTranslate.sml";
use "MathTranslate.sml";
use "Formula.sml";
use "Out.sml";
use "OutHigh.sml";
use "OutDvi.sml";
use "DviState.sml";
use "DviCmd.sml";
use "SetNode.sml";
use "SetBox.sml";
use "ShipOut.sml";
use "Input.sml";
use "test.sml";

(* End of everything *)

