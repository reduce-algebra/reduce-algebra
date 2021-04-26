{* Smarty *}
{extends file="main.tpl"}

{block name=main}
{$preamble}
<div class="accordion" id="P_S_accordion">
  {foreach $P_S as $index => $item}
  <div class="card">
    {* Problem *}
    <h4 class="card-header" id="heading{$index}">
      Problem {$index+1}
      <button class="btn btn-link collapsed" type="button" data-toggle="collapse" data-target="#collapse{$index}" aria-expanded="false" aria-controls="collapse{$index}">
        Show/hide solution
      </button>
    </h4>
    <div class="card-body">
      {$item.P}
    </div>
    {* Solution *}
    <div id="collapse{$index}" class="card-body collapse" aria-labelledby="heading{$index}" data-parent="#P_S_accordion">
      <h5 class="card-title">REDUCE solution</h5>
      <pre class="card-text">{$item.S}</pre>
    </div>
  </div>
  {/foreach}
</div>
{/block}

{block name=javascript}
<!-- Use the same URL as used for the HTML manual for cache efficiency. -->
<script id="MathJax-script" src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml-full.js"></script>
{/block}
