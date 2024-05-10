<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">

<head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta name="description" content="The REDUCE Computer Algebra System" />
    <meta name="keywords" content="Open Source, Software, Development, Developers, Projects, Downloads, SF.net, SourceForge,
                    BSD License, Science/Research, OS Portable (Source code to work with many OS platforms),
                    Mathematics, Lisp, REDUCE, reduce-algebra, computer algebra system, CAS" />
    <title>
        <?= isset($page_title) ? $page_title : "REDUCE $header_title" ?>
    </title>
    <?php
    $script_name = $_SERVER['SCRIPT_NAME'];
    if (str_ends_with($script_name, 'index.php')) $script_name = substr($script_name, 0, strlen($script_name) - 9);
    ?>
    <link rel="canonical" href="https://reduce-algebra.sourceforge.io<?= $script_name ?>" />
    <link rel="icon" type="image/png" href="/images/icon.png" />
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">
    <link rel="stylesheet" href="/StyleSheet.css" />