<?php
$queryString = $_SERVER['QUERY_STRING'];
if ($queryString):

$doc = new DOMDocument();
libxml_use_internal_errors(true);
if ($doc->loadHTMLFile('manual/manual.html')) {
    // Use XPath to extract the href attribute of the contents item containing the query string:
    $xpath = new DOMXpath($doc);
    $href = $xpath->query("/html/body/div[@class='tableofcontents']/span/a[contains(.,'$queryString')]/@href");
    if ($href->length == 1) {
        // If precisely one contents item is found, display the corresponding page:
        header("Location: manual/{$href->item(0)->nodeValue}");
    } else {
        // Otherwise, display the contents page:
        header('Location: manual/manual.html');
    }
    exit;
} // else fall through to the error message page below...
?>

    <!DOCTYPE html>
    <html lang="en" xmlns="http://www.w3.org/1999/xhtml">
        <head>
            <meta charset="utf-8" />
            <title>REDUCE Manual Lookup Error</title>
        </head>
        <body style="font-family: Arial, Helvetica, sans-serif;">
            <h1>REDUCE Manual Lookup Error</h1>
	    <p>
                The REDUCE manual lookup facility failed to load the
	        contents page.  Sorry.  This should not happen!
            </p>
	    <p>
                Please email this error message to
                <a href="mailto:fjwright@users.sourceforge.net?subject=REDUCE%20web%20site">fjwright@users.sourceforge.net</a>,
            </p>
        </body>
    </html>

<?php else:

require_once('../php/Smarty/setup.php');
$smarty = new Smarty_REDUCE();

$smarty->assign('head_extras', <<< END_OF_HEAD_EXTRAS
<style type="text/css">
  #form {
      text-align: center;
  }
  #Text1 {
      width: 250px;
  }
</style>
END_OF_HEAD_EXTRAS
);

$smarty->assign('header_title', 'Manual Page Look-Up');

$smarty->assign('main_content', <<< END_OF_MAIN_CONTENT
<p>
  Internal links within the HTML version of the REDUCE manual should
  not be used externally because they may change when the manual is
  rebuilt from source, which typically happens a few times a year.
  Instead, use a URL of the form
  <a href="#"><span class="href"></span>?<em>query string</em></a>,
  where <em>query string</em> is any (case-sensitive) string of
  characters that appears uniquely in the title of an entry in
  the <a href="/manual/manual.html">REDUCE manual table of
  contents</a>.  (Don&apos;t use section numbers, which may change.)
  For example, these links should reliably access appropriate sections
  of the manual describing <strong>User Contributed Packages</strong>:
</p>
<ul>
  <li><a href="?EXCALC"><span class="href"></span>?EXCALC</a></li>
  <li><a href="?GROEBNER"><span class="href"></span>?GROEBNER</a></li>
  <li><a href="?LINALG"><span class="href"></span>?LINALG</a></li>
  <li><a href="?ODESOLVE"><span class="href"></span>?ODESOLVE</a></li>
  <li><a href="?REDLOG"><span class="href"></span>?REDLOG</a></li>
  <li><a href="?ROOTS"><span class="href"></span>?ROOTS</a></li>
</ul>
<p>
  Alternatively, for interactive experimentation, enter a <em>query
    string</em> in the field below and hit <em>Enter</em> or click on
    the <em>Go</em> button.
</p>
<p id="form">
  <input id="Text1" type="text" placeholder="query string" />
  <input id="Button1" type="button" value="Go" />
</p>
<p>
  If a query string is not found then the
  <a href="/manual/manual.html">REDUCE manual table of
  contents</a> is displayed.
</p>
END_OF_MAIN_CONTENT
);

$smarty->display('manual-lookup.tpl');

endif; ?>
