{* Smarty *}
{extends file="main.tpl"}

{block name=main}
	<p>
		Click on a question to show (or hide) its answer.
	</p>
	<div class="accordion" id="Q_A_accordion">
		{foreach $Q_A as $index => $item}
			<div class="card">
				<div class="card-header" id="heading{$index}">
					<h5 class="mb-0">
						<button class="btn btn-link collapsed" type="button" data-toggle="collapse" data-target="#collapse{$index}" aria-expanded="false" aria-controls="collapse{$index}">
							{$index+1}. {$item.Q}
						</button>
					</h5>
				</div>
				<div id="collapse{$index}" class="collapse" aria-labelledby="heading{$index}" data-parent="#Q_A_accordion">
					<div class="card-body">
						{$item.A}
					</div>
				</div>
			</div>
		{/foreach}
	</div>
{/block}

{block name=javascript}
	{include file='bootstrap-js.tpl'}
{/block}

