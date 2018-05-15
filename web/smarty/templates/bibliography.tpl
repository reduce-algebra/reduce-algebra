{* Smarty *}
{extends file="main.tpl"}

{block name=style}
	<style type="text/css">
	 dt.divider {
		 margin: 1em auto
	 }
	</style>
{/block}

{block name=main}
	<div id="main" class="col-md-9 col-xl-7">
		<p>
			This document contains a list of all known references to REDUCE.
		</p>
		<p style="text-align: center">
			[ <a href="#A">A</a> | <a href="#B">B</a> | <a href="#C">C</a> | <a href="#D">D</a>
			| <a href="#E">E</a> | <a href="#F">F</a> | <a href="#G">G</a> | <a href="#H">H</a>
			| <a href="#I">I</a> | <a href="#J">J</a> | <a href="#K">K</a> | <a href="#L">L</a>
			| <a href="#M">M</a> | <a href="#N">N</a> | <a href="#O">O</a> | <a href="#P">P</a>
			| <a href="#Q">Q</a> | <a href="#R">R</a> | <a href="#S">S</a> | <a href="#T">T</a>
			| <a href="#U">U</a> | <a href="#V">V</a> | <a href="#W">W</a> | <a href="#Y">Y</a>
			| <a href="#Z">Z</a> ]
		</p>
		<dl>
			{foreach $biblio as $alpha => $section}
				<dt class="divider"><a id="{$alpha}" href="#TOP">[top]</a></dt>
				{$section}
			{/foreach}
		</dl>
	</div>
{/block}
