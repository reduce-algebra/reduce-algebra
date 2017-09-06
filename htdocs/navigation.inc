<ul>
<script language="php">
    $filename = array_pop(explode('/', $_SERVER['PHP_SELF']));
    #echo "**Filepath: ${_SERVER['PHP_SELF']}**<br />";
    if (!$filename) $filename = 'index.php';
    #echo "**Filename: $filename**<br />";
    #echo "**Scriptname: " . __FILE__ . "**<br />";

    function menuItem($href, $label, $title = NULL) {
        global $filename, $root;
        if ($href === $filename)
            echo "<li title=\"$title\" class=\"selected\">$label</li>";
        else {
			if ($root) $href = "$root$href";
            echo "<li title=\"$title\"><a href=\"$href\">$label</a></li>";
		}
    }

    menuItem('index.php', 'Home', 'The REDUCE Computer Algebra System');
    menuItem('features.php', 'Features', 'REDUCE features and design characteristics');
    menuItem('obtaining.php', 'Obtaining REDUCE', 'Guidance on obtaining REDUCE from SourceForge');
    menuItem('documentation.php', 'Documentation', 'User guides for REDUCE, its packages and Lisp systems');
    menuItem('books.php', 'Books', 'Books about REDUCE');
    menuItem('support.php', 'Support', 'Support available for REDUCE');
    menuItem('packages.php', 'Related Packages', 'Packages that use REDUCE');
    menuItem('projects.php', 'Related Projects', 'Projects related to REDUCE');
    menuItem('bibliography.php', 'Bibliography', 'Publications that reference REDUCE');
    menuItem('about.php', 'About REDUCE', 'History and contributors');
</script>
</ul>

<a href="https://sourceforge.net/p/reduce-algebra/" rel="nofollow"><p>Download REDUCE from<br />
	<img alt="Download REDUCE" src="https://sourceforge.net/sflogo.php?type=13&group_id=248416"></p></a>

<div id="google_translate_element"></div><script type="text/javascript">
function googleTranslateElementInit() {
  new google.translate.TranslateElement({pageLanguage: 'en'}, 'google_translate_element');
}
</script><script type="text/javascript" src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>
