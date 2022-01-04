<!-- Support for the Template and Functions menus. -->

<!-- The modal-dialogue custom element is based on this template. -->
<template id="modal-dialogue-template">
	<div class="modal fade" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-hidden="true">
		<div class="modal-dialog modal-dialog-centered">
			<div class="modal-content">
				<div class="modal-header">
					<h5 class="modal-title"></h5>
					<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
				</div>
				<div class="modal-body text-center"></div>
				<div class="modal-footer">
					<button type="button" class="btn btn-secondary me-auto"
						title="Reset to default inputs">Reset</button>
					<button type="button" class="btn btn-primary" title="Insert into input editor">Edit</button>
					<button type="button" class="btn btn-primary" title="Send to REDUCE">Evaluate</button>
					<button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
				</div>
			</div>
		</div>
	</div>
</template>

<!-- The header HTML common to special-functions dialogues, included by the <modal-dialogue> funcsHeader attribute. -->
<template id="special-functions-header">
	<p class="text-center"><small>Click on the function you want to use. Hover over a function for a hint at
			its definition. Click on a function name to open the full definition in the <a href="https://dlmf.nist.gov/"
				target="_blank" title="Opens in a new tab.">NIST Digital
				Library of Mathematical Functions</a> in a new tab.</small></p>
	<p class="text-center">
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?Mathematical%20Functions" target="_blank"
				title="Opens in a new tab.">Mathematical Functions</a>&ensp;
			<a href="/manual-lookup.php?SPECFN:" target="_blank" title="Opens in a new tab.">SPECFN
				Package</a></small>
	</p>
</template>
