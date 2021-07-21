<?php
$header_title = 'Books';
include './include/begin-head.php';
?>

<style type="text/css">
 #main img {
     width: 60px;
     height: 90px;
     margin: 0;
     float: none;
     box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.5);
     transition: 0.2s 0.1s;
 }

 #main img:hover {
     transform: scale(2);
     box-shadow: 4px 4px 10px rgba(0, 0, 0, 0.5);
     z-index: 100;
 }

 #main > div.row {
     margin-left: 0.5em;
     min-height: 110px;
     font-size: 90%;
 }

 #main span.title {
     display: block;
     font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif;
     font-weight: bold;
     font-size: large;
 }

 #main span.subtitle {
     display: block;
 }

 #main span.authors {
     display: block;
 }

 #main span.biblio {
     display: block;
     margin-top: 1ex;
 }
</style>

<?php
include './include/begin-body.php';
?>

<p>
    The definitive guide to using REDUCE, namely the REDUCE User&#39;s
    Manual, and other user guides are distributed with REDUCE and also
    <a href="documentation.php">available online</a>. In
    addition, the following books are available, sorted by publication
    date from newest to oldest. (They should also be included in the
    <a href="bibliography.php">bibliography</a>,
    but may be hard to find there.) Book titles and front cover images
    link to the publisher or to a bookseller such as Amazon (whichever
    seems more useful).
</p>

<h2>Books primarily about REDUCE</h2>

<?php $primary_books = array(

    array('url' => 'http://www.cambridge.org/gb/academic/subjects/physics/particle-physics-and-nuclear-physics/using-reduce-high-energy-physics?format=PB#si7TZq9PBUEIGGG9.97',
          'img' => '<img src="images/Grozin.jpg" width="180" height="259" alt="" />',
          'ttl' => '<span class="title">Using REDUCE in High Energy Physics</span>',
          'dsc' => '<span class="authors">by A. G. Grozin</span>
<span class="biblio">404 pages, Cambridge University Press, ISBN 9780521019521, 2005</span>
(See also <a href="http://www.inp.nsk.su/~grozin/book/">the author&#39;s own web page</a>.)'),

    array('url' => 'https://www.amazon.co.uk/REDUCE-Physicists-N-MacDonald/dp/0750302771/ref=sr_1_1?s=books&ie=UTF8&qid=1506678783&sr=1-1&keywords=9780750302777',
          'img' => '<img src="images/MacDonald.jpg" width="301" height="474" alt="" />',
          'ttl' => '<span class="title">REDUCE for Physicists</span>',
          'dsc' => '<span class="authors">by N. MacDonald</span>
<span class="biblio">168 pages, CRC Press, ISBN 9780750302777, 1994</span>'),

    array('url' => 'http://www.springer.com/gb/book/9783540567059',
          'img' => '<img src="images/Hehl-Winkelmann-Meyer.jpg" width="153" height="235" alt="" />',
          'ttl' => '<span class="title">REDUCE</span>',
          'dsc' => '<span class="subtitle" lang="de">Ein Kompaktkurs &uuml;ber die Anwendung von Computer-Algebra</span>
<span class="authors">by Friedrich W. Hehl, Volker Winkelmann and Hartmut Meyer</span>
<span class="biblio">143 pages, Springer, ISBN 9783540567059, 1993</span>'),

    array('url' => 'https://www.amazon.de/Einf%C3%BChrung-Computeralgebra-Mathematiker-Informatiker-Physiker/dp/341115781X/ref=sr_1_1?s=books&ie=UTF8&qid=1504285074&sr=1-1',
          'img' => '<img src="images/Ueberberg.jpg" width="202" height="306" alt="" />',
          'ttl' => '<span class="title" lang="de">Einf&uuml;hrung in die Computeralgebra mit REDUCE</span>',
          'dsc' => '<span class="subtitle" lang="de">f&uuml;r Mathematiker, Informatiker und Physiker</span>
<span class="authors" lang="de">by Johannes Ueberberg</span>
<span class="biblio">331 pages, BI-Wiss.-Verlag, ISBN 9783411157815, 1992</span>'),

    array('url' => 'http://www.springer.com/gb/book/9780792314417',
          'img' => '<img src="images/Brackx-Constales.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">Computer Algebra with LISP and REDUCE</span>',
          'dsc' => '<span class="subtitle">An Introduction to Computer-aided Pure Mathematics</span>
<span class="authors">by F.&nbsp;Brackx and D.&nbsp;Constales</span>
<span class="biblio">264 pages, Springer, ISBN 9789401055499, 1991</span>'),

    array('url' => 'https://global.oup.com/academic/product/algebraic-computing-with-reduce-9780198534433?lang=en&amp;cc=se',
          'img' => '<img src="images/MacCallum-Wright.jpg" width="180" height="273" alt="" />',
          'ttl' => '<span id="MacCallum-Wright" class="title">Algebraic Computing with REDUCE</span>',
          'dsc' => '<span class="authors">by Malcolm A. H. MacCallum and Francis J. Wright</span>
<span class="biblio">314 pages, Oxford University Press, ISBN 9780198534433, 1991</span>'),

    array('url' => 'http://www.springer.com/math/cse/book/978-0-387-96598-7',
          'img' => '<img src="images/Rayna.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">REDUCE</span>',
          'dsc' => '<span class="subtitle">Software for Computer Algebra</span>
<span class="authors">by Gerhard Rayna</span>
<span class="biblio">329 pages, Springer, ISBN 9780387965987, 1987</span>'));

foreach ($primary_books as $book): ?>
    <div class="row align-items-center">
        <div class="col-auto">
            <a href="<?=$book['url']?>"><?=$book['img']?></a>
        </div>
        <div class="col"><a href="<?=$book['url']?>"><?=$book['ttl']?></a>
            <?=$book['dsc']?>
        </div>
    </div>
<?php endforeach; ?>

<h2>Books that include information about, or closely related to, REDUCE</h2>

<?php $secondary_books = array(

    array('url' => 'http://www.springer.com/la/book/9783319716541',
          'img' => '<img src="images/Krasilshchik-Verbovetsky-Vitolo.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">The Symbolic Computation of Integrability Structures<br />for Partial Differential Equations</span>',
          'dsc' => '<span class="authors">by Joseph Krasil&apos;shchik, Alexander Verbovetsky and Raffaele Vitolo</span>
<span class="biblio">250 pages, Springer, ISBN 9783319716558, 2017</span>'),

    array('url' => 'https://my.siam.org/Store/Product/viewproduct/?ProductId=26052157',
          'img' => '<img id="roberts" src="images/Roberts.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">Model Emergent Dynamics in Complex Systems</span>',
          'dsc' => '<span class="authors">by A. J. Roberts</span>
<span class="biblio">748 pages, SIAM, ISBN 9781611973556, 2014</span>'),

    array('url' => 'http://www.springer.com/gb/book/9783540654667',
          'img' => '<img src="images/Grabmeier-Kaltofen-Weispfenning.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">Computer Algebra Handbook</span>',
          'dsc' => '<span class="subtitle">Foundations &middot; Applications &middot; Systems</span>
<span class="authors">edited by Johannes Grabmeier, Erich Kaltofen and Volker Weispfenning</span>
<span class="biblio">637 pages, Springer, ISBN 9783642629884, 2003</span>'),

    array('url' => 'http://www.worldscientific.com/worldscibooks/10.1142/2362',
          'img' => '<img src="images/Steeb.jpg" width="120" height="168" alt="" />',
          'ttl' => '<span class="title">Quantum Mechanics Using Computer Algebra</span>',
          'dsc' => '<span class="subtitle">Includes Sample Programs for REDUCE, MAPLE, MATHEMATICA and C++</span>
<span class="authors">by Willi-Hans Steeb</span>
<span class="biblio">200 pages, World Scientific, ISBN 9789810217709, 1994</span>'),

    array('url' => 'http://www.springer.com/gb/book/9783540565307',
          'img' => '<img src="images/Stauffer-Hehl-Ito-Winkelmann-Zabolitzky.jpg" width="153" height="232" alt="" />',
          'ttl' => '<span class="title">Computer Simulation and Computer Algebra</span>',
          'dsc' => '<span class="subtitle">Lectures for Beginners</span>
<span class="authors">by D. Stauffer, Friedrich W. Hehl, Nobuyasu Ito, Volker Winkelmann and John G. Zabolitzky</span>
<span class="biblio">287 pages, Springer, ISBN 9783540565307, 1993</span>'),

    array('url' => 'http://www.worldscientific.com/worldscibooks/10.1142/2097',
          'img' => '<img src="images/Marti.jpg" width="120" height="168" alt="" />',
          'ttl' => '<span class="title">RLISP &#39;88</span>',
          'dsc' => '<span class="subtitle">An Evolutionary Approach to Program Design and Reuse</span>
<span class="authors">by Jed Marti</span>
<span class="biblio">268 pages, World Scientific, ISBN 9789810214791, 1993</span>'),

    array('url' => 'https://www.amazon.co.uk/Computer-Algebra-Algorithms-Algebraic-Computation/dp/0122042328',
          'img' => '<img src="images/Davenport-Siret-Tournier.jpg" width="128" height="202" alt="" />',
          'ttl' => '<span id="Davenport-Siret-Tournier" class="title">Computer Algebra</span>',
          'dsc' => '<span class="subtitle">Systems and Algorithms for Algebraic Computation</span>
<span class="authors">by J. H. Davenport, Y. Siret and E. Tournier</span>
<span class="biblio">256 pages, Academic Press, second edition, ISBN 0122042301, 1993</span>'));

foreach ($secondary_books as $book): ?>
    <div class="row align-items-center">
        <div class="col-auto">
            <a href="<?=$book['url']?>"><?=$book['img']?></a>
        </div>
        <div class="col"><a href="<?=$book['url']?>"><?=$book['ttl']?></a>
            <?=$book['dsc']?>
        </div>
    </div>
<?php endforeach; ?>

</div><!-- opened in begin-body.php -->

<?php
include './include/footer.php';
?>

</body>
</html>
