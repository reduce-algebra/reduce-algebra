{* Smarty *}
{extends file="main.tpl"}

{block name=style}
<style type="text/css">
  h5.mb-0 button.btn {
      text-align: left;
      white-space: normal;
  }
</style>
{/block}

{block name=main}
{$preamble}
<p>Click on a problem to show (or hide) its solution.</p>
<div class="accordion" id="P_S_accordion">
  {foreach $P_S as $index => $item}
  <div class="card">
    <div class="card-header" id="heading{$index}">
      <h5 class="mb-0">
	<button class="btn btn-link collapsed" type="button" data-toggle="collapse" data-target="#collapse{$index}" aria-expanded="false" aria-controls="collapse{$index}">
	  <p><strong>Problem {$index+1}:</strong> {$item.P}</p>
	</button>
      </h5>
    </div>
    <div id="collapse{$index}" class="collapse" aria-labelledby="heading{$index}" data-parent="#P_S_accordion">
      <div class="card-body">
	<p><strong>REDUCE solution:</strong></p>
	<pre>{$item.S}</pre>
      </div>
    </div>
  </div>
  {/foreach}
</div>
{/block}

{block name=javascript}
{include file='bootstrap-js.tpl'}
<script src='https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.6/latest.js?config=TeX-MML-AM_CHTML' async='async'></script>
{/block}
