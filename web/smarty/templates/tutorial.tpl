{* Smarty *}
{extends file="secondary.tpl"}

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
	<p>
		Click on a problem to show (or hide) its solution.
	</p>
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
	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
	<script src='https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.4/latest.js?config=TeX-MML-AM_CHTML' async='async'></script>
{/block}

