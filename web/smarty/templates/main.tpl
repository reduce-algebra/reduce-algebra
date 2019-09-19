{* Smarty *}
<!DOCTYPE html>
<html lang="en" xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta name="description" content="The REDUCE Computer Algebra System" />
    <meta name="keywords" content="Open Source, Software, Development, Developers, Projects, Downloads, SF.net, SourceForge, 
                                   BSD License, Science/Research, OS Portable (Source code to work with many OS platforms), 
                                   Mathematics, Lisp, REDUCE, reduce-algebra, computer algebra system, CAS" />
    {block name=title}
    <title>{$page_title|default: "REDUCE $header_title"}</title>
    {/block}
    <link rel="canonical" href="https://reduce-algebra.sourceforge.io{$SCRIPT_NAME}" />
    <link rel="icon" type="image/png" href="/images/icon.png" />
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
          integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous" />
    <link rel="stylesheet" href="/StyleSheet.css" />
    {block name=style}
    {$head_extras|default:''}
    {/block}
  </head>
  <body>
    <div class="container-fluid">
      {block name=header}
      <header class="navbar navbar-expand-md navbar-light">
        <img class="navbar-brand d-none d-md-block" src="/images/icon.png" alt="" />
        <span class="mx-auto">REDUCE</span>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navmenu">
          <span class="navbar-toggler-icon"></span>
        </button>
      </header>
      {/block}
      <div class="row">
        {include file='navigation.tpl'}
        <div id="main" class="{$main_class|default:'col-md-9 col-xl-7'}">
          <h1>{$header_title}</h1>
          {block name=main}
          {$main_content}
          {/block}
        </div>
        {block name=RSS}{/block}
        {block name=footer}
        {include file='footer.tpl' class='col-xl-3'}
        {/block}
      </div>
    </div>
    <!-- The slim version of jQuery does not include ajax (or effects)
         and so cannot be used because I use ajax on the documentation
         page! -->
    <script
      src="https://code.jquery.com/jquery-3.3.1.min.js"
      integrity="sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8="
      crossorigin="anonymous"></script>
    <script
      src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"
      integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM"
      crossorigin="anonymous"></script>
    {block name=javascript}{/block}
  </body>
</html>
