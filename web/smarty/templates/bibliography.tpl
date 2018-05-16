{* Smarty *}
{extends file="main.tpl"}

{block name=style}
	<style type="text/css">
	</style>
{/block}

{block name=main}
	<div id="main" class="col-md-9 col-xl-7">
		<p>
			This document contains a list of all known references to REDUCE sorted by first author surname.
		</p>
		<nav>
			<div class="nav nav-tabs" id="TabbedHeader" role="tablist">
				{foreach $biblio as $alpha => $section}
					<a class="nav-item nav-link" id="{$alpha}-tab" data-toggle="tab" href="#{$alpha}" role="tab" aria-controls="{$alpha}" aria-selected="false">{$alpha}</a>
				{/foreach}
			</div>
		</nav>
		<div class="tab-content" id="TabbedContent">
			{foreach $biblio as $alpha => $section}
				<div class="tab-pane fade" id="{$alpha}" role="tabpanel" aria-labelledby="{$alpha}-tab">
					{$section}
				</div>
			{/foreach}
		</div>
	</div>
{/block}

{block name=javascript}
	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
	<script>
	 // Set initial state of tablist.
	 $("#TabbedHeader > a:first-child").addClass("active").attr("aria-selected", "true");
	 $("#TabbedContent > div:first-child").addClass("show active");
	</script>
{/block}
