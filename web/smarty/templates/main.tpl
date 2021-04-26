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
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css"
          integrity="sha384-B0vP5xmATw1+K9KRQjQERJvTumQW0nPEzvF6L/Z6nronJ3oUOFUFpCjEUQouq2+l"
          crossorigin="anonymous">
    <link rel="stylesheet" href="/StyleSheet.css" /> {block
    name=style} {$head_extras|default:''} {/block}
  </head>
  <body>
    <div class="container-fluid">
      {block name=header}
      <header class="navbar navbar-expand-md navbar-light">
        <a class="navbar-brand d-none d-md-block" href="https://sourceforge.net/p/reduce-algebra/" title="REDUCE project page">
          <img src="/images/icon.png" alt="" />
        </a>
        <span class="mx-auto">REDUCE</span>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navmenu">
          <span class="navbar-toggler-icon"></span>
        </button>
        <!-- The following link is hidden on the search page! -->
        <a id="top-search-button" class="btn d-none d-md-block" title="Search the REDUCE web site" href="/search.php">
          <svg width="13" height="13" viewBox="0 0 13 13">
            <path d="m4.8495 7.8226c0.82666 0 1.5262-0.29146 2.0985-0.87438 0.57232-0.58292 0.86378-1.2877 0.87438-2.1144 0.010599-0.82666-0.28086-1.5262-0.87438-2.0985-0.59352-0.57232-1.293-0.86378-2.0985-0.87438-0.8055-0.010599-1.5103 0.28086-2.1144 0.87438-0.60414 0.59352-0.8956 1.293-0.87438 2.0985 0.021197 0.8055 0.31266 1.5103 0.87438 2.1144 0.56172 0.60414 1.2665 0.8956 2.1144 0.87438zm4.4695 0.2115 3.681 3.6819-1.259 1.284-3.6817-3.7 0.0019784-0.69479-0.090043-0.098846c-0.87973 0.76087-1.92 1.1413-3.1207 1.1413-1.3553 0-2.5025-0.46363-3.4417-1.3909s-1.4088-2.0686-1.4088-3.4239c0-1.3553 0.4696-2.4966 1.4088-3.4239 0.9392-0.92727 2.0864-1.3969 3.4417-1.4088 1.3553-0.011889 2.4906 0.45771 3.406 1.4088 0.9154 0.95107 1.379 2.0924 1.3909 3.4239 0 1.2126-0.38043 2.2588-1.1413 3.1385l0.098834 0.090049z">
            </path>
          </svg>
        </a>
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
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"
            integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
            crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/js/bootstrap.min.js"
            integrity="sha384-+YQ4JLhjyBLPDQt//I+STsc9iw4uQqACwlvpslubQzn4u2UU2UFM80nGisd026JF"
            crossorigin="anonymous"></script>
    {block name=javascript}{/block}
  </body>
</html>
