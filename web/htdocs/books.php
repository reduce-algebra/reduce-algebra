<?php

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('header_title', 'Books');

$smarty->assign('preamble', <<< END_OF_PREAMBLE
	<p>The definitive guide to using REDUCE, namely the REDUCE User&#39;s Manual, and other user guides are distributed with REDUCE and also <a href="documentation.php">available online</a>. In addition, the following books are available, sorted by publication date from newest to oldest. (They should also be included in the <a href="bibliography.php">bibliography</a>, but may be hard to find there.) Book titles and front cover images link to the publisher or to a bookseller such as Amazon (whichever seems more useful).</p>
END_OF_PREAMBLE
);

$smarty->assign('primary_books_heading', 'Books primarily about REDUCE');

$smarty->assign('primary_books', array(
	
	array('url' => 'http://www.cambridge.org/gb/academic/subjects/physics/particle-physics-and-nuclear-physics/using-reduce-high-energy-physics?format=PB#si7TZq9PBUEIGGG9.97',
		  'img' => '<img src="images/Grozin.jpg" width="180" height="259" />',
		  'ttl' => '<span class="title">Using REDUCE in High Energy Physics</span>',
		  'dsc' => '<span class="authors">by A. G. Grozin</span>
					<span class="biblio">404 pages, Cambridge University Press, ISBN 9780521019521, 2005</span>
					(See also <a href="http://www.inp.nsk.su/~grozin/book/">the author&#39;s own web page</a>.)'),
	
	array('url' => 'https://www.amazon.co.uk/REDUCE-Physicists-N-MacDonald/dp/0750302771/ref=sr_1_1?s=books&ie=UTF8&qid=1506678783&sr=1-1&keywords=9780750302777',
		  'img' => '<img src="images/MacDonald.jpg" width="301" height="474" />',
		  'ttl' => '<span class="title">REDUCE for Physicists</span>',
		  'dsc' => '<span class="authors">by N. MacDonald</span>
					<span class="biblio">168 pages, CRC Press, ISBN 9780750302777, 1994</span>'),

	array('url' => 'http://www.springer.com/gb/book/9783540567059',
		  'img' => '<img src="images/Hehl-Winkelmann-Meyer.jpg" width="153" height="235" />',
		  'ttl' => '<span class="title">REDUCE</span>',
		  'dsc' => '<span class="subtitle" lang="de">Ein Kompaktkurs &uuml;ber die Anwendung von Computer-Algebra</span>
					<span class="authors">by Friedrich W. Hehl, Volker Winkelmann and Hartmut Meyer</span>
					<span class="biblio">143 pages, Springer, ISBN 9783540567059, 1993</span>'),

	array('url' => 'https://www.amazon.de/Einf%C3%BChrung-Computeralgebra-Mathematiker-Informatiker-Physiker/dp/341115781X/ref=sr_1_1?s=books&ie=UTF8&qid=1504285074&sr=1-1',
		  'img' => '<img src="images/Ueberberg.jpg" width="202" height="306" />',
		  'ttl' => '<span class="title" lang="de">Einf&uuml;hrung in die Computeralgebra mit REDUCE</span>',
		  'dsc' => '<span class="subtitle" lang="de">f&uuml;r Mathematiker, Informatiker und Physiker</span>
					<span class="authors" lang="de">by Johannes Ueberberg</span>
					<span class="biblio">331 pages, BI-Wiss.-Verlag, ISBN 9783411157815, 1992</span>'),

	array('url' => 'http://www.springer.com/gb/book/9780792314417',
		  'img' => '<img src="images/Brackx-Constales.jpg" width="153" height="232" />',
		  'ttl' => '<span class="title">Computer Algebra with LISP and REDUCE</span>',
		  'dsc' => '<span class="subtitle">An Introduction to Computer-aided Pure Mathematics</span>
					<span class="authors">by F.&nbsp;Brackx and D.&nbsp;Constales</span>
					<span class="biblio">264 pages, Springer, ISBN 9789401055499, 1991</span>'),

	array('url' => 'https://global.oup.com/academic/product/algebraic-computing-with-reduce-9780198534433?lang=en&amp;cc=se',
		  'img' => '<img src="images/MacCallum-Wright.jpg" width="180" height="273" />',
		  'ttl' => '<span id="MacCallum-Wright" class="title">Algebraic Computing with REDUCE</span>',
		  'dsc' => '<span class="authors">by Malcolm A. H. MacCallum and Francis J. Wright</span>
					<span class="biblio">314 pages, Oxford University Press, ISBN 9780198534433, 1991</span>'),

	array('url' => 'http://www.springer.com/math/cse/book/978-0-387-96598-7',
		  'img' => '<img src="images/Rayna.jpg" width="153" height="232" />',
		  'ttl' => '<span class="title">REDUCE</span>',
		  'dsc' => '<span class="subtitle">Software for Computer Algebra</span>
					<span class="authors">by Gerhard Rayna</span>
					<span class="biblio">329 pages, Springer, ISBN 9780387965987, 1987</span>')));

$smarty->assign('secondary_books_heading', 'Books that include information about, or closely related to, REDUCE');

$smarty->assign('secondary_books', array(
	
	array('url' => 'http://www.springer.com/la/book/9783319716541',
		  'img' => '<img src="images/Krasilshchik-Verbovetsky-Vitolo.jpg" width="153" height="232" />',
		  'ttl' => '<span class="title">The Symbolic Computation of Integrability Structures<br />for Partial Differential Equations</span>',
		  'dsc' => '<span class="authors">by Joseph Krasil\'shchik, Alexander Verbovetsky and Raffaele Vitolo</span>
					<span class="biblio">250 pages, Springer, ISBN 9783319716558, 2017</span>'),
	
	array('url' => 'http://www.springer.com/gb/book/9783540654667',
		  'img' => '<img src="images/Grabmeier-Kaltofen-Weispfenning.jpg" width="153" height="232" />',
		  'ttl' => '<span class="title">Computer Algebra Handbook</span>',
		  'dsc' => '<span class="subtitle">Foundations &middot; Applications &middot; Systems</span>
					<span class="authors">edited by Johannes Grabmeier, Erich Kaltofen and Volker Weispfenning</span>
					<span class="biblio">637 pages, Springer, ISBN 9783642629884, 2003</span>'),
	
	array('url' => 'http://www.worldscientific.com/worldscibooks/10.1142/2362',
		  'img' => '<img src="images/Steeb.jpg" width="120" height="168" />',
		  'ttl' => '<span class="title">Quantum Mechanics Using Computer Algebra</span>',
		  'dsc' => '<span class="subtitle">Includes Sample Programs for REDUCE, MAPLE, MATHEMATICA and C++</span>
					<span class="authors">by Willi-Hans Steeb</span>
					<span class="biblio">200 pages, World Scientific, ISBN 9789810217709, 1994</span>'),
	
	array('url' => 'http://www.springer.com/gb/book/9783540565307',
		  'img' => '<img src="images/Stauffer-Hehl-Ito-Winkelmann-Zabolitzky.jpg" width="153" height="232" />',
		  'ttl' => '<span class="title">Computer Simulation and Computer Algebra</span>',
		  'dsc' => '<span class="subtitle">Lectures for Beginners</span>
					<span class="authors">by D. Stauffer, Friedrich W. Hehl, Nobuyasu Ito, Volker Winkelmann and John G. Zabolitzky</span>
					<span class="biblio">287 pages, Springer, ISBN 9783540565307, 1993</span>'),
	
	array('url' => 'http://www.worldscientific.com/worldscibooks/10.1142/2097',
		  'img' => '<img src="images/Marti.jpg" width="120" height="168" />',
		  'ttl' => '<span class="title">RLISP &#39;88</span>',
		  'dsc' => '<span class="subtitle">An Evolutionary Approach to Program Design and Reuse</span>
					<span class="authors">by Jed Marti</span>
					<span class="biblio">268 pages, World Scientific, ISBN 9789810214791, 1993</span>'),
	
	array('url' => 'https://www.amazon.co.uk/Computer-Algebra-Algorithms-Algebraic-Computation/dp/0122042328',
		  'img' => '<img src="images/Davenport-Siret-Tournier.jpg" width="128" height="202" />',
		  'ttl' => '<span id="Davenport-Siret-Tournier" class="title">Computer Algebra</span>',
		  'dsc' => '<span class="subtitle">Systems and Algorithms for Algebraic Computation</span>
					<span class="authors">by J. H. Davenport, Y. Siret and E. Tournier</span>
					<span class="biblio">256 pages, Academic Press, second edition, ISBN 0122042301, 1993</span>')));

$smarty->display('books.tpl');

?>
