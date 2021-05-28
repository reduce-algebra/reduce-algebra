<nav id="navmenu" class="col-md-3 col-xl-2 d-md-block collapse">
    <div class="sticky-top">
        <ul>
            <?php
            navMenuItem('/index.php', 'Home', 'The REDUCE Computer Algebra System');
            navMenuItem('/features.php', 'Features', 'REDUCE features and design characteristics');
            navMenuItem('/obtaining.php', 'Obtain and Run', 'How to download, install and run REDUCE');
            navMenuItem('/documentation.php', 'Documentation', 'User guides for REDUCE, its packages and Lisp systems');
            navMenuItem('/books.php', 'Books', 'Details of books about REDUCE');
            navMenuItem('/support.php', 'Support Q & A', 'Answers to questions about using REDUCE');
            navMenuItem('/tutorials.php', 'Tutorials', 'Simple examples of using REDUCE');
            navMenuItem('/packages.php', 'External Packages', 'External packages that use REDUCE');
            navMenuItem('/helpwanted.php', 'Help Wanted!', 'Join the REDUCE developer community!');
            navMenuItem('/bibliography.php', 'Bibliography', 'Publications that reference REDUCE');
            navMenuItem('/about.php', 'About REDUCE', 'REDUCE history and contributors');
            navMenuItem('/projects.php', 'Related Projects', 'Projects related to REDUCE');
            navMenuItem('/search.php', 'Search&nbsp;
      <svg width="13" height="13" viewBox="0 0 13 13">
        <path d="m4.8495 7.8226c0.82666 0 1.5262-0.29146 2.0985-0.87438 0.57232-0.58292 0.86378-1.2877 0.87438-2.1144 0.010599-0.82666-0.28086-1.5262-0.87438-2.0985-0.59352-0.57232-1.293-0.86378-2.0985-0.87438-0.8055-0.010599-1.5103 0.28086-2.1144 0.87438-0.60414 0.59352-0.8956 1.293-0.87438 2.0985 0.021197 0.8055 0.31266 1.5103 0.87438 2.1144 0.56172 0.60414 1.2665 0.8956 2.1144 0.87438zm4.4695 0.2115 3.681 3.6819-1.259 1.284-3.6817-3.7 0.0019784-0.69479-0.090043-0.098846c-0.87973 0.76087-1.92 1.1413-3.1207 1.1413-1.3553 0-2.5025-0.46363-3.4417-1.3909s-1.4088-2.0686-1.4088-3.4239c0-1.3553 0.4696-2.4966 1.4088-3.4239 0.9392-0.92727 2.0864-1.3969 3.4417-1.4088 1.3553-0.011889 2.4906 0.45771 3.406 1.4088 0.9154 0.95107 1.379 2.0924 1.3909 3.4239 0 1.2126-0.38043 2.2588-1.1413 3.1385l0.098834 0.090049z">
        </path>
      </svg>', 'Search the REDUCE web site');
            navMenuItem('/sitemap.php', 'Site Map / Recent', 'Full REDUCE site map and recently updated files');
            ?>
        </ul>

        <a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow">
            <p>
	        Download REDUCE from<br />
	        <img alt="SourceForge" src="https://sourceforge.net/sflogo.php?type=13&amp;group_id=248416">
            </p>
        </a>

        <div id="google_translate_element"></div>
        <script type="text/javascript">
         function googleTranslateElementInit() {
	     new google.translate.TranslateElement( { pageLanguage: 'en' } , 'google_translate_element');
         }
        </script>
        <script defer="defer" type="text/javascript" src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>
    </div>
</nav>
<?php
/*
 * Return one navigation menu list item.
 */
function navMenuItem($href, $label, $title) {
    static $filename;
    # Constant for all menu items on the same page, so only set once.
    if (!$filename) {
	$filename = $_SERVER['PHP_SELF'];
	# echo "**Filename: $filename**<br />";
    }
    if ($href === $filename)
        echo "<li title=\"$title\" class=\"selected\">$label</li>\n";
    else
        echo "<li title=\"$title\"><a href=\"$href\">$label</a></li>\n";
}
?>
