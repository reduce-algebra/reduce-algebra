<?php declare(strict_types=1);
$header_title = 'Site Map / Recent Updates';
define('CACHE_FILE', '../sitemap/cache');
if ($_SERVER['QUERY_STRING'] == 'show-time'):
$time = 0;
elseif ($_SERVER['QUERY_STRING'] == 'show-cache'):
?>
    <!DOCTYPE html>
    <html lang="en" xmlns="http://www.w3.org/1999/xhtml">
        <head>
            <meta charset="utf-8" />
            <title>REDUCE Site Map Cache</title>
        </head>
        <body>
            <pre><?php
                 if ($handle = @fopen(CACHE_FILE, 'r')) {
                     if ($cache = fread($handle, filesize(CACHE_FILE)))
                         $cache = unserialize($cache);
                     fclose($handle);
                 }
                 if (isset($cache)) print_r($cache);
                 else echo "Cannot read cache file!"
                 ?></pre>
        </body>
    </html>
<?php
exit;
endif;
include 'include/begin-head.php';
?>

<style>
 div.tab-content {
     margin-top: 1ex; margin-bottom: 1ex;
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
     white-space: nowrap; text-align: center;
 }

 /* Hide sub-folders for initial display */
 #SiteMap tr[data-level='1'], #SiteMap tr[data-level='2'] {
     display: none;
 }
 #SiteMap tr[data-level='1'] > td:first-child {
     padding-left: 1.5em;
 }
 #SiteMap tr[data-level='2'] > td:first-child {
     padding-left: 3em;
 }
 #SiteMap tr.folder:not(.expanded) > td:first-child::before {
     content: "⊞ ";
 }
 #SiteMap tr.folder.expanded > td:first-child::before {
     content: "⊟ ";
 }
</style>

<?php
include 'include/begin-body.php';

// $sitemap is an array of arrays that stores the site map table, in
// which each row is an array of the form
// [ isfile:bool, level:int, file:string, title:string|null, date:int|null ].

function processDir(string $dir, int $level) {
    // Process all files in each directory recursively.
    global $sitemap;
    foreach (glob($dir) as $file) {
        if (is_dir($file)) {
            if ($file != 'images' and $file != 'include' and $file != 'manual.old') {
                $sitemap[] = array(false, $level, $file);
                processDir("$file/*", $level + 1); // recurse!
            }
        } elseif ($file != 'robots.txt') {
            processFile($file, $level);
        }
    }
}

// $cache is an associative array keyed by filename of arrays of title and date (for files only).

function processFile(string $file, int $level) {
    global $sitemap, $cache, $recache;
    $date = filemtime($file);

    // If this file is in the cache and up to date then use the cached title:
    if (array_key_exists($file, $cache) and $date == ($c=$cache[$file])[1]) {
        $sitemap[] = array(true, $level, $file, $c[0], $date);
        return;
    }

    // Otherwise, determine the page title or description for
    // the file $file with extension $ext:
    preg_match('/^[^.]+$|\.([^.]+)$/', $file, $matches);
    $ext = (count($matches) == 2 ? strtoupper($matches[1]) : '');
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
    $sitemap[] = array(true, $level, $file, $title, $date);
    $recache = true;
}

if (isset($time)) $time = microtime(true);
// Try to read the cache file:
if ($handle = @fopen(CACHE_FILE, 'r')) {
    if ($cache = fread($handle, filesize(CACHE_FILE))) $cache = unserialize($cache);
    fclose($handle);
}
if (!$cache) $cache = array();

// Build or update $sitemap:
processDir('*', 0);

// Re-write the cache if necessary:
if ($recache) {
    if ($handle = @fopen(CACHE_FILE, 'w')) {
        $cache = array();
        reset($sitemap);
        while (list(, $row) = each($sitemap))
            if ($row[0]) $cache[$row[2]] = array($row[3], $row[4]);
        $written = fwrite($handle, serialize($cache));
        fclose($handle);
    }
    if (!$written) echo "<p>WARNING: Cannot write cache file!</p>\n";
}

// Time to build $sitemap in seconds as a float (double) accurate to the nearest micro-second:
if (isset($time)) $time = microtime(true) - $time;
?>

<ul class="nav nav-tabs nav-justified" role="tablist">
    <li class="nav-item" role="presentation">
        <a class="nav-link active" id="SiteMap-tab" data-toggle="tab" href="#SiteMap"
           role="tab" aria-controls="SiteMap" aria-selected="true">Site Map</a>
    </li>
    <li class="nav-item" role="presentation">
        <a class="nav-link" id="RecentUpdates-tab" data-toggle="tab" href="#RecentUpdates"
           role="tab" aria-controls="RecentUpdates" aria-selected="false">Recent Updates</a>
    </li>
</ul>
<div class="tab-content">
    <div class="tab-pane fade show active" id="SiteMap"
         role="tabpanel" aria-labelledby="SiteMap-tab">
        <p>
            The table below displays all the pages, documents, files
            and folders that are directly available to users on this
            web site, sorted alphabetically by URL.  Only the final
            component of each URL is displayed.  Clicking on a page,
            document or file URL opens it.  Clicking on a (bold)
            folder URL expands or collapses the folder contents.  A
            collapsed folder URL is preceded by the symbol ⊞ and an
            expanded folder URL is preceded by the symbol ⊟.  The
            table displays the title of a page if it has one,
            otherwise it displays a brief description of the item.
            The table also shows the date on which each page, document
            or file was last modified in some way on the web server,
            which may imply a change or at least a review of the
            content.
        </p>
        <table>
            <tr><th>URL</th><th>Page Title / Description</th><th>Date</th></tr>
            <?php
            // Output the site map table, in which each row is an array of the form
            // [ isfile:bool, level:int, file:string, title:string|null, date:int|null ].
            reset($sitemap);
            while (list(, $row) = each($sitemap)) {
                if ($row[0]) {
                    echo "<tr data-level='$row[1]'><td><a href='$row[2]'>$row[2]</a></td>";
                    $date = date('d M Y', $row[4]);
                    echo "<td>$row[3]</td><td>$date</td></tr>\n";
                } else {
                    echo "<tr data-level='$row[1]' class='folder'><td><b>$row[2]</b></td>";
                    echo "<td>&mdash; <i>folder</i> &mdash;</td><td></td></tr>\n";
                }
            }
            ?>
        </table>
    </div>
    <div class="tab-pane fade" id="RecentUpdates"
         role="tabpanel" aria-labelledby="RecentUpdates-tab">
        <p>
            The table below displays the 10 pages, documents or files
            that are directly available to users on this web site and
            were most recently modified in some way, sorted by
            decreasing date.  Clicking on a page, document or file URL
            opens it.  The table displays the title of a page if it
            has one, otherwise it displays a brief description of the
            item.
        </p>
        <table>
            <tr><th>URL</th><th>Page Title / Description</th><th>Date</th></tr>
            <?php
            // Output the site map table, in which each row is an array of the form
            // [ isfile:bool, level:int, file:string, title:string|null, date:int|null ],
            // after removing folder rows, sorting by date in descending order,
            // and selecting the 10 most recent file rows.
            $sitemap = array_filter($sitemap, create_function('$row', 'return $row[0];'));

            function sort_rows_by_date($a, $b) {
                $a_date = $a[4];
                $b_date = $b[4];
                return $a_date == $b_date ? 0 : ($a_date > $b_date ? -1 : 1);
            }
            usort($sitemap, 'sort_rows_by_date');

            reset($sitemap);
            while ((list($index, $row) = each($sitemap)) && $index < 10 ) {
                echo "<tr data-level='$row[1]'><td><a href='$row[2]'>$row[2]</a></td>";
                $date = date('d M Y', $row[4]);
                echo "<td>$row[3]</td><td>$date</td></tr>\n";
            }
            ?>
        </table>
    </div>
</div>
<?php if (isset($time)) printf("<p>Time to build site map: %.3f seconds</p>\n", $time); ?>

</div><!-- opened in begin-body.php -->

<?php
include 'include/footer.php';
?>

<script>
 // Strip leading folders from file names:
 $("#SiteMap tr[data-level=1],tr[data-level=2]")
     .find("td:first-child > a, td:first-child:not(:has(a))")
     .text(function(n, current) {
         /* var pos = current.lastIndexOf("/");
          * return pos == -1 ? current : current.substring(pos+1); */
         return current.substring(current.lastIndexOf("/") + 1);
     });

 // Register a click handler on folder name cells:
 $("#SiteMap tr.folder > td:first-child").css("cursor", "pointer").click(function() {
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
