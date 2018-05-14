{* Smarty *}
{extends file="main.tpl"}

{block name=style}
	<style type="text/css">
	 #main img {
		 width: 60px;
		 height: 90px;
		 margin: 0;
		 float: none;
		 box-shadow: 2px 2px 5px rgba(0, 0, 0, 0.5);
		 transition: 0.2s 0.1s;
	 }

	 #main img:hover {
		 transform: scale(2);
		 box-shadow: 4px 4px 10px rgba(0, 0, 0, 0.5);
		 z-index: 100;
	 }

	 #main > div.row {
		 min-height: 110px;
		 font-size: 90%;
	 }

	 #main span.title {
		 display: block;
		 font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif;
		 font-weight: bold;
		 font-size: large;
	 }

	 #main span.subtitle {
		 display: block;
	 }

	 #main span.authors {
		 display: block;
	 }

	 #main span.biblio {
		 display: block;
		 margin-top: 1ex;
	 }
	</style>
{/block}

{block name=main}
	<div id="main" class="col-md-9 col-xl-7">
		{$preamble}

		<h2>{$primary_books_heading}</h2>

		{foreach $primary_books as $book}
			<div class="row align-items-center">
				<div class="col-auto">
					<a href="{$book.url}">{$book.img}</a>
				</div>
				<div class="col"><a href="{$book.url}">{$book.ttl}</a>
					{$book.dsc}
				</div>
			</div>
		{/foreach}
		
		<h2>{$secondary_books_heading}</h2>

		{foreach $secondary_books as $book}
			<div class="row align-items-center">
				<div class="col-auto">
					<a href="{$book.url}">{$book.img}</a>
				</div>
				<div class="col"><a href="{$book.url}">{$book.ttl}</a>
					{$book.dsc}
				</div>
			</div>
		{/foreach}
	</div>
{/block}
