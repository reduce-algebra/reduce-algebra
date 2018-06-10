<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('page_title', 'About REDUCE');

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
 #main img {
	 margin-top: 0
 }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'About REDUCE');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<h2>A brief history of REDUCE</h2>
<p>
	<img src="images/140px-Hearn.jpg" alt="Tony Hearn" height="180px" width="140px" />In 2008, Tony Hearn, who is the main and original author of this software, wrote:
</p>
<blockquote>In 1963, I began work on a software system that would in time evolve into REDUCE. By 1968, copies had been made available to various researchers throughout the world. Forty years later, there is still an active community of users. In order to encourage further development, I have decided to make the software freely available under a <a href="license.php">modified BSD license</a>.</blockquote>
<p>The Open Source version of the REDUCE algebra system was registered on SourceForge.net on Dec 18, 2008.</p>
<p><a href="/reduce40.pdf">REDUCE: The First Forty Years</a> provides a more complete history.</p>
<p>The documentation for <a href="documentation38.php">REDUCE 3.8</a>, the last commercial version of REDUCE released in 2004, is also still available.</p>
<h2 id="contributors">Contributors</h2>
<p>REDUCE <a>traces its origins to work begun by Anthony Hearn in 1963</a> and continued ever since. The first distribution occurred in 1968. Since that time, over a hundred people have been involved in various ways in its development.</p>
<p>A small number of these people have made sustained contributions to the REDUCE core and associated packages over many years, namely John Fitch, Herbert Melenk, Winfried Neun, Arthur Norman and Eberhard Schr&uuml;fer.</p>
<p>Others who have contributed to either documentation or packages for REDUCE include John Abbott, Paul Abbott, Victor Adamchik, Werner Antweiler, Alan Barnes, Andreas Bernig, Yuri A. Blinkov, Harald Boeing, W.N. Borst, F. Brackx, Russell Bradford, Andreas Brand, Fran Burstall, Chris Cannam, Hubert Caprasse, D. Constales, Caroline Cotter, James Davenport, Michael Dewar, C. Dicrescenzo, Andreas Dolzmann, Alain Dresse, Ladislav Drska, James Eastwood, Bruce A. Florman, Kerry Gaskell, Karin Gatermann, Barbara L. Gates, R. Gebauer, Vladimir Gerdt, John Gottschalk, Hans-Gert Graebe, Martin Griss, A.G. Grozin, David Harper, John Harper, Steve Harrington, David Hartley, M.C. van Heerwaarden, Friedrich Hehl, Daniel Hobbs, Joachim Hollman, B.J.A. Hulshof, J.A. van Hulzen, V. Ilyin, N. Ito, F. Kako, Stan Kameny, C. Kazasov, Nancy Kirkwood, K. Kishimoto, Wolfram Koepf, H. Kredel, A.P. Kryukov, Neil Langmead, A. Lasaruk, D. Lewien, Richard Liska, Ruediger Loos, Malcolm MacCallum, Norman MacDonald, Jed Marti, Kevin McIsaac, H. Meyer, H. Michael Moeller, Mary Ann Moore, Shuichi Moritsugu, Donald Morrison, Alain Moussiaux, C.J. Neerdaels, K. Onaga, Julian Padget, Gerhard Rayna, Matt Rebbeck, Francoise Richard, F. Richard-Jung, A.J. Roberts, A.Ya. Rodionov, T. Sasaki, Carsten Schoebel, Franziska Schoebel, Rainer Schoepf, Fritz Schwarz, Andreas Seidl, James Sherring, Luis Alvarez Sobreviela, D. Stauffer, Gregor Stoelting, David R. Stoutemyer, Stephen Scowcroft, Yves Siret, M. Spiridonova, H. Steeb, Andreas Strotmann, Thomas Sturm, Takeyuki Takahashi, A. Taranov, Lisa Temme, Walter Tietze, V. Tomov, Evelyne Tournier, Arrigo Triulzi, R.W. Tucker, Philip A Tuckey, Gokturk Ucoluk, J. Ueberberg, J.B. van Veelen, Mathias Warns, Volker Winkelmann, Thomas Wolf, Francis Wright, K. Yamamoto, J.G. Zabolitzky, Alexey Yu. Zharkov and Vadim V. Zhytnikov.</p>
END_OF_MAIN_CONTENT
);

$smarty->display('main.tpl');

?>
