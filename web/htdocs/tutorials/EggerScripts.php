<?php  // -*-mhtml-*-

require_once('../../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Scripts von Dieter Egger');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p style="text-align: center"><a href="EggerScripts.en.php">English translation</a></p>
<p>
  Hier finden Sie einige Beispiele f&uuml;r REDUCE-Scripts.  Sie
  k&ouml;nnen entweder auf die folgenden Links klicken, um die
  Scripts in einem Webbrowser zu lesen, oder Sie k&ouml;nnen sie
  f&uuml;r sp&auml;tere Eingaben in REDUCE herunterladen.  Da die
  Scripts oft gleich lautende Variable verwenden, ist vor der
  Verarbeitung eines neuen Scripts eventuell ein "Reset REDUCE"
  ratsam.
</p>
<p>
  Gleichungen l&ouml;sen:
  <a href="EggerReduceScripts/algebra.txt">algebra.txt</a>
</p>
<p>
  Funktionen analysieren:
  <a href="EggerReduceScripts/analyze.red">analyze.red</a>
  <br />
  Vereinbaren Sie vorher die zu analysierende Funktion, beispielsweise "f:=x**3 - 2*x**2;"
</p>
<p>
  Eigenschaften:
  <a href="EggerReduceScripts/boolean.txt">boolean.txt</a>
</p>
<p>
  Analysis:
  <a href="EggerReduceScripts/calculus.txt">calculus.txt</a>
</p>
<p>
  <b>Physikalische Konstante</b>:
  Definitionen bereitstellen:
  <a href="EggerReduceScripts/constants.red">constants.red</a>;
  Definitionen l&ouml;schen:
  <a href="EggerReduceScripts/clear_constants.red">clear_constants.red</a>
</p>
<p>
  Sinus, Cosinus, Tangens:
  <a href="EggerReduceScripts/example01.red">example01.red</a>
</p>
<p>
  Binom, Trigo, Rechengenauigkeit:
  <a href="EggerReduceScripts/example02.red">example02.red</a>
</p>
<p>
  Einfache Funktionsanalyse:
  <a href="EggerReduceScripts/example03.red">example03.red</a>
</p>
<p>
  Einfache Ableitung:
  <a href="EggerReduceScripts/example04.red">example04.red</a>
</p>
<p>
  Binome, Regeln:
  <a href="EggerReduceScripts/example05.red">example05.red</a>
</p>
<p>
  Verschachtelte Klammern:
  <a href="EggerReduceScripts/heron.txt">heron.txt</a>
</p>
<p>
  Hypergeometrie und MeijerG:
  <a href="EggerReduceScripts/hypermeijerg.txt">hypermeijerg.txt</a>
  <br />
  Ohne LaTeX-Formatierung OK.
</p>
<p>
  Integration, Limits:
  <a href="EggerReduceScripts/integLimit.red">integLimit.red</a>
</p>
<p>
  Integration:
  <a href="EggerReduceScripts/integral.txt">integral.txt</a>
</p>
<p>
  Einf&uuml;hrung:
  <a href="EggerReduceScripts/introReduce.txt">introReduce.txt</a>
</p>
<p>
  Lineare Algebra:
  <a href="EggerReduceScripts/linalg.txt">linalg.txt</a>
</p>
<p>
  Matrix Inversion:
  <a href="EggerReduceScripts/mat.red">mat.red</a>
</p>
<p>
  <b>Berechnungen zur Raum-Zeit Metrik</b>
  <br />
  Metrik-Tensor aus Gleichung der Hyperoberfl&auml;che einer Hyperkugel,
  2-dim:
  <a href="EggerReduceScripts/metric2calc.red">metric2calc.red</a>,
  3-dim:
  <a href="EggerReduceScripts/metric3calc.red">metric3calc.red</a>,
  4-dim:
  <a href="EggerReduceScripts/metric4calc.red">metric4calc.red</a>
  <br />
  Riemann-, Ricci-, Einstein-Tensoren und L&ouml;sung der Feldgleichungen,
  2-dim:
  <a href="EggerReduceScripts/metric2d.red">metric2d.red</a>,
  3-dim:
  <a href="EggerReduceScripts/metric3d.red">metric3d.red</a>,
  4-dim:
  <a href="EggerReduceScripts/metric4d.red">metric4d.red</a>
</p>
<p>
  Dynamische Variablennamen:
  <a href="EggerReduceScripts/mkid.txt">mkid.txt</a>
</p>
<p>
  Teilbr&uuml;che:
  <a href="EggerReduceScripts/partialFraction.txt">partialFraction.txt</a>
</p>
<p>
  Energie eines Photons
  (ben&ouml;tigt <a href="EggerReduceScripts/constants.red">constants.red</a>
  und <a href="EggerReduceScripts/clear_constants.red">clear_constants.red</a>):
  <a href="EggerReduceScripts/photonenergy.txt">photonenergy.txt</a>
</p>
<p>
  Prefix-Operatoren:
  <a href="EggerReduceScripts/prefix.txt">prefix.txt</a>
</p>
<p>
  Programmieren:
  <a href="EggerReduceScripts/programming.txt">programming.txt</a>
</p>
<p>
  Einfache Regeln:
  <a href="EggerReduceScripts/rules.red">rules.red</a>
</p>
<p>
  Definition einer Funktion:
  <a href="EggerReduceScripts/scalprod.red">scalprod.red</a>
</p>
<p>
  Lichtgeschwindigkeit:
  <a href="EggerReduceScripts/speedoflight.txt">speedoflight.txt</a>
</p>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
