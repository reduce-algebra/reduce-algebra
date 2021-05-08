<?php declare(strict_types=1)?>
<!DOCTYPE html>
<html>
    <head>
        <style>
         td:not(:first-child) {
             padding-left: 10px;
         }
         tr[data-level='1'] > td:first-child {
             padding-left: 10px;
         }
         tr[data-level='2'] > td:first-child {
             padding-left: 20px;
         }
         tr.folder > td:first-child {
             cursor: pointer;
         }
         tr.folder:not(.expanded) > td:first-child::before {
             content: "⊞ ";
         }
         tr.folder.expanded > td:first-child::before {
             content: "⊟ ";
         }
        </style>
    </head>
    <body>

        <table>
            <tr><th>URL</th><th>Page Title / Description</th><th>Date</th></tr>
<?php
processDir('*', 0);

function processDir(string $dir, int $level) {
    // Process all files in each directory recursively.
    foreach (glob($dir) as $file) {
        if (is_dir($file)) {
            if ($file != 'images') {
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
                for ($i = 0; ($line = fgets($handle)) !== false && $i < 25; $i++) {
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
                    if (preg_match('/\$smarty->assign\(\'(page_title|header_title)\',\s*\'(.*)\'\);/',
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
    echo '<td>', $title, '</td>';
    echo '<td>', date('d M Y', filemtime($file)), "</td></tr>\n";
}
?>
        </table>

        <script src="https://code.jquery.com/jquery-3.6.0.min.js"
                integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
                crossorigin="anonymous"></script>

        <script>
         $("tr[data-level=1],tr[data-level=2]").hide();
         $("tr.folder > td:first-child").click(function() {
             var $folderTr = $(this).closest("tr"); // folder table row
             var folderLevel = $folderTr.toggleClass("expanded").data("level");
             var hiding = !$folderTr.hasClass("expanded"); // collapsing folder
             $folderTr.nextAll().each(function(){
                 var $this = $(this); // a table row below the folder table row
                 var level = $this.data("level");
                 if (level == folderLevel) return false; // below this subfolder
                 if (hiding) $this.hide().removeClass("expanded"); // hide all descendants
                 else if (level == folderLevel+1) $this.show(); // show only children
             })
         });
        </script>
    </body>
</html>
