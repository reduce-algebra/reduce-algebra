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
	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js" integrity="sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js" integrity="sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T" crossorigin="anonymous"></script>
{/block}

