<div id="LoadPackagesDialogue" class="modal fade" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1"
	aria-hidden="true">
	<div class="modal-dialog modal-dialog-centered modal-lg">
		<div class="modal-content">
			<div class="modal-header">
				<h5 class="modal-title">Load Packages</h5>
				<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
			</div>
			<div class="modal-body text-center">
				<p>
					<small>
						Select one or more packages then press the Load button below,
						or double-press a single package.
						Right-click / press-and-hold a package, or select <strong>one</strong>
						package and press the Manual button below,
						to display the manual entry (if it exists) for the package in a new tab.
						Note that many packages autoload.
					</small>
				</p>
				<div style="display: grid; align-items: center; justify-content: center; grid-gap: 1px 1px;
				grid-template-columns: repeat(auto-fill, 5em);" class="btn-group-sm">
				</div>
			</div>
			<div class="modal-footer">
				<button type="button" class="btn btn-secondary me-auto" title="Clear all selections">Reset</button>
				<button type="button" class="btn btn-secondary me-auto"
					title="Display the manual entry (if it exists) for the *single* selected package in a new tab.">Manual</button>
				<button type="button" class="btn btn-primary" title="Load the selected package(s).">Load</button>
				<button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cancel</button>
			</div>
		</div>
	</div>
</div>

<script type="module" src="GenJS/LoadPackagesDialogue.js"></script>
