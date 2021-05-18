<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
    <head>
        <meta charset="utf-8" />
        <title>Encountered a 404 Error</title>
        <style>
         body {max-width: 40em; margin-left: auto; margin-right: auto;
             font-family: Arial, Helvetica, sans-serif;}
         code {font-size: large;}
         .centre {text-align: center;}
        </style>
    </head>
    <body>
        <h1>Encountered a 404 Error</h1>
        <p>
	    The URL
        </p>
        <p class="centre"><strong><code>
            <?php
            $host = (isset($_SERVER['HTTPS']) ? 'https://' : 'http://') .
                    $_SERVER['HTTP_HOST'];
            $url = $host . getenv('REDIRECT_URL');
            $queryString = getenv('REDIRECT_QUERY_STRING');
            if ($queryString) $url .= "?$queryString";
            echo $url;
            ?>
        </code></strong></p>
        <p>
            you requested from the REDUCE web site was not found.  Sorry!
        </p>
	<p>
	    If you think this is a server error then please email this
	    error message to
            <a href="mailto:fjwright@users.sourceforge.net?subject=REDUCE%20web%20site">fjwright@users.sourceforge.net</a>
            and if appropriate include the URL of the page containing
            the link you tried to access.
        </p>
        <p>
            Please note that the REDUCE web site home page is
        </p>
        <p class="centre"><a href="<?= $host ?>"><?= $host ?></a></p>
        <p>
            from which you can access all the site content by
            following appropriate links.  All the main pages have URLs
            ending in <code>.php</code>, but most manual pages have
            URLs ending in <code>.html</code> and a few documents have
            URLs ending in <code>.pdf</code>.
        </p>
</body>
</html>
