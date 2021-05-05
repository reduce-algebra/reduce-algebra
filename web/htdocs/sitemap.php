<?php declare(strict_types=1) ?>
<!DOCTYPE html>
<html>
<head>
<style>
td {
    padding-left:10px;
}
</style>
</head>
<body>

<table>
<tr><th>URL</th><th>Page Title</th><th>Date</th></tr>
<?php
processDir('*');

function processDir(string $dir) {
    // Process all files in each directory recursively.
    foreach (glob($dir) as $file) {
        if (is_dir($file)) {
            if ($file != 'images') {
                echo "<tr><td>$file</td><td>&mdash; <i>folder</i> &mdash;</td><td></td></tr>\n";
                processDir("$file/*"); // recurse!
            }
        } elseif (preg_match('/^[^.]*$|\.(html|pdf|php)$/', $file, $matches)) {
            echo "<tr><td><a href='$file'>$file</a></td>";
            echo '<td>', fileTitle($file, count($matches) == 2 ? $matches[1] : ''), '</td>';
            echo '<td>', date('d M Y', filemtime($file)), "</td></tr>\n";
        }
    }
}

function fileTitle(string $file, string $ext) : string {
    // Return a title for the document file $file with extension $ext.
    $title = '';
    switch ($ext) {
    case 'html':
        if ($handle = @fopen($file, 'r')) {
            for ($i = 0; ($line = fgets($handle)) !== false && $i < 25; $i++) {
                if (preg_match('/<title>(.*)<\/title>/', $line, $matches)) {
                    $title = "<b>$matches[1]</b>";
                    break;
                }
            }
            fclose($handle);
        }
        break;
    case 'pdf':
        $title = '&mdash; <i>PDF file</i> &mdash;';
        break;
    case 'php':
        $title = '&mdash; <i>non-browsable PHP file</i> &mdash;';
        if ($handle = @fopen($file, 'r')) {
            for ($i = 0; ($line = fgets($handle)) !== false && $i < 25; $i++) {
                if (preg_match('/\$smarty->assign\(\'(page_title|header_title)\',\s*\'(.*)\'\);/',
                               $line, $matches)) {
                    if ($matches[1] == 'page_title')
                        $title = "<b>$matches[2]</b>";
                    else
                        $title = "<b>REDUCE $matches[2]</b>";
                    break;
                }
            }
            fclose($handle);
        }
        break;
    default:
        $title = '&mdash; <i>text file</i> &mdash;';
    }
    return $title;
}
?>
</table>

</body>
</html>
