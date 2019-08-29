{* Smarty *}
{extends file="main.tpl"}

{block name=style}
	<style type="text/css">
	</style>
{/block}

{block name=main}
	<p>
		This document contains a list of all known references to REDUCE sorted by first-author surname.
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
{/block}

{block name=javascript}
	{include file='bootstrap-js.tpl'}
	<script>
	 // Set initial state of tablist.
	 $("#TabbedHeader > a:first-child").addClass("active").attr("aria-selected", "true");
	 $("#TabbedContent > div:first-child").addClass("show active");
	</script>
{/block}
