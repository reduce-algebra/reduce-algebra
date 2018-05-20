{* Smarty *}
{extends file="main.tpl"}

{block name=main}
	<dl>
		{foreach $Q_A as $item}
			<dt>
				{$item.Q}
			</dt>
			<dd>
				{$item.A}
			</dd>
		{/foreach}
	</dl>
{/block}
