<?php declare(strict_types=1);
$header_title = 'Site Map';
include 'include/begin-head.php';
?>

<style>
 /* Hide sub-folders for initial display */
 tr[data-level='1'], tr[data-level='2'] {
     display: none;
 }
 table {
     margin-left: auto; margin-right: auto;
 }
 tr:first-child {
     border-bottom: thin solid black;
 }
 th:not(:first-child), td:not(:first-child) {
     padding-left: 1em;
 }
 td:nth-child(3) {
     white-space: nowrap;
     text-align: center;
 }
 tr[data-level='1'] > td:first-child {
     padding-left: 1.5em;
 }
 tr[data-level='2'] > td:first-child {
     padding-left: 3em;
 }
 tr.folder:not(.expanded) > td:first-child::before {
     content: "⊞ ";
 }
 tr.folder.expanded > td:first-child::before {
     content: "⊟ ";
 }
</style>

<?php
include 'include/begin-body.php';
?>

<p>
    The table below displays all the pages, documents, files and
    folders that are directly available to users on this web site,
    sorted alphabetically by URL.  Only the final component of each
    URL is displayed.  Clicking on a page or document URL opens that
    page or document.  Clicking on a (bold) folder URL expands or
    collapses the folder contents.  A collapsed folder URL is preceded
    by the symbol ⊞ and an expanded folder URL is preceded by the
    symbol ⊟.  The table displays the title of a page if it has one,
    otherwise it displays a brief description of the item.  The table
    also shows the date on which each page or document was last
    modified on the web server, which probably implies either a change
    or at least a review of the content.
</p>
<table>
    <tr><th>URL</th><th>Page Title / Description</th><th>Date</th></tr>
<?php
processDir('*', 0);

function processDir(string $dir, int $level) {
    // Process all files in each directory recursively.
    foreach (glob($dir) as $file) {
        if (is_dir($file)) {
            if ($file != 'images' && $file != 'include') {
                echo "<tr data-level='$level' class='folder'><td><b>$file</b></td>";
                echo "<td>&mdash; <i>folder</i> &mdash;</td><td></td></tr>\n";
                processDir("$file/*", $level + 1); // recurse!
            }
        } elseif (preg_match('/^[^.]+$|\.([^.]+)$/', $file, $matches))
        processFile($file, count($matches) == 2 ? $matches[1] : '', $level);
    }
}

function processFile(string $file, string $ext, int $level) {
    // Display details (URL, page title, last modified date) for the
    // document file $file with extension $ext if appropriate.
    $ext = strtoupper($ext);
    switch ($ext) {
        case 'CSS': case 'PNG': return;
        case '':
            $title = '&mdash; <i>text file</i> &mdash;';
            break;
        case 'HTML':
            $title = '&mdash; <i>HTML file</i> &mdash;';
            if ($handle = @fopen($file, 'r')) {
                for ($i = 0; ($line = fgets($handle)) !== false && $i < 5; $i++) {
                    if (preg_match('/<title>(.*)<\/title>/', $line, $matches) && $matches[1]) {
                        $title = "<b>$matches[1]</b>";
                        break;
                    }
                }
                fclose($handle);
            }
            break;
        case 'PHP':
            $title = '&mdash; <i>PHP file</i> &mdash;';
            if ($handle = @fopen($file, 'r')) {
                for ($i = 0; ($line = fgets($handle)) !== false && $i < 25; $i++) {
                    if (preg_match('/\$(page_title|header_title)\s*=\s*\'(.*)\'/',
                                   $line, $matches)) {
                        $title = $matches[2];
                        if ($matches[1] == 'header_title') $title = "REDUCE $title";
                        $title = "<b>$title</b>";
                        break;
                    }
                }
                fclose($handle);
            }
            break;
        default: // GZ, PDF, PS, RED, TAR, TXT, ZIP, ...
            $title = '&mdash; <i>' . $ext . ' file</i> &mdash;';
    }
    echo "<tr data-level='$level'><td><a href='$file'>$file</a></td>";
    echo "<td>$title</td>";
    echo '<td>', date('d M Y', filemtime($file)), "</td></tr>\n";
}
?>
</table>

</div><!-- opened in begin-body.php -->

<?php
include 'include/footer.php';
?>

<script>
 // Strip leading folders from file names:
 $("tr[data-level=1],tr[data-level=2]")
     .find("td:first-child > a, td:first-child:not(:has(a))")
     .text(function(n, current) {
         /* var pos = current.lastIndexOf("/");
          * return pos == -1 ? current : current.substring(pos+1); */
         return current.substring(current.lastIndexOf("/") + 1);
     });

 // Register a click handler on folder name cells:
 $("tr.folder > td:first-child").css("cursor", "pointer").click(function() {
     var $folderTr = $(this).closest("tr"); // folder table row
     var folderLevel = $folderTr.toggleClass("expanded").data("level");
     var hiding = !$folderTr.hasClass("expanded"); // collapsing folder
     $folderTr.nextAll().each(function(){
         var $this = $(this); // a table row below the folder table row
         var level = $this.data("level");
         if (level == folderLevel) return false; // below this subfolder
         if (hiding) $this.hide().removeClass("expanded"); // hide all descendants
         else if (level == folderLevel+1) $this.show(); // but show only children
     })
 });
</script>

</body>
</html>
