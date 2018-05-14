{* Smarty *}
{extends file="main.tpl"}

{block name=title}
	<title>REDUCE Computer Algebra System</title>
	<meta name="Description" content="The REDUCE Computer Algebra System" />
	<meta name="Keywords" content="Open Source, Software, Development, Developers, Projects, Downloads, SF.net, SourceForge, BSD License, Science/Research, OS Portable (Source code to work with many OS platforms), Mathematics, Lisp, REDUCE, reduce-algebra, computer algebra system, CAS" />
{/block}

{block name=style}
	<style type="text/css">
	 #main img {
		 float: none;
		 margin: 0;
		 width: 100%;
		 border: thin solid;
	 }

	 aside iframe {
		 border: 0;
		 padding: 0;
		 width: 100%;
		 height: 500px;
		 border: 1px solid #333333;
		 background-color: #f8f8ff;
	 }
	</style>
{/block}

{block name=header}
	<header><img src="images/icon.png" class="d-none d-md-block" />
		REDUCE
	</header>
	<p>A portable general-purpose computer algebra system</p>
{/block}

{*<nav class="col-md-3 col-xl-2">*}

{block name=main}
	<div id="main" class="col-md-6 col-xl-6">
		{$main_content}
	</div>
	<aside class="col-md-3 col-xl-2">
		<h2 style="text-align:center; font-size:medium;">SourceForge RSS feeds</h2>
		<div class="row">
			<div class="col-sm col-md-12">
				<iframe src="displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/news/feed.rss">Please use a browser that supports the HTML iframe element.</iframe>
			</div>
			<div class="col-sm col-md-12">
				<iframe src="displayRSSfeed.php?https://sourceforge.net/p/reduce-algebra/activity/feed?source=project_activity">Please use a browser that supports the HTML iframe element.</iframe>
			</div>
		</div>
		<p style="text-align:center; font-size:small;">RSS feed display courtesy of <a href="http://simplepie.org/">SimplePie</a></p>
	</aside>
{/block}

{block name=footer}
	{include file='footer.tpl' class='col-xl-2'}
{/block}
