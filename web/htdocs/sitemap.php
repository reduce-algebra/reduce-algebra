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
        } elseif (preg_match('/^[^.]+$|\.([^.]+)$/', $file, $matches))
              processFile($file, count($matches) == 2 ? $matches[1] : '');
    }
}

function processFile(string $file, string $ext) {
    // Display details (URL, page title, last modified date) for the
    // document file $file with extension $ext if appropriate.
    $ext = strtoupper($ext);
    switch ($ext) {
    case 'CSS': case 'PNG': return;
    case '':
        $title = '&mdash; <i>text file</i> &mdash;';
        break;
    case 'HTML':
        $title = '';
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
    echo "<tr><td><a href='$file'>$file</a></td>";
    echo '<td>', $title, '</td>';
    echo '<td>', date('d M Y', filemtime($file)), "</td></tr>\n";
}
?>
</table>

</body>
</html>
