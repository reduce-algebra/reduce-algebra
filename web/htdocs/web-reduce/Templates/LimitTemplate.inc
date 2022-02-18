<modal-dialogue dialogueId="LimitTemplate" dialogueTitle="Evaluate a Limit of a Function">
	<p>
		<small>
			Only limits of (mostly) continuous functions are supported, not sequences. All fields
			are required. The variable must be an identifier. Click the superscript box immediately after the limit
			point to cycle through the directions: from right / above (+), left / below (−), both sides (blank).
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?LIMITS:" target="_blank" title="Opens in a new tab.">LIMITS Package</a></small>
	</p>
	<div class="pattern" style="display: flex; justify-content: center; align-items: flex-start;">
		<div style="display: inline-block; vertical-align: middle; flex: 0 0 auto;">
			lim<br />
			<input type="text" placeholder="var" style="width: 3em; font-size: small;" value="x" />
			→
			<input type="text" placeholder="alg" style="width: 3em; font-size: small;" value="0" />
			<sup style="border: gray solid thin; cursor: pointer;">&ensp;</sup>
		</div>
		&ensp;
		<input type="text" placeholder="algebraic" value="ws" style="flex: 0 1 10em;" />
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./GenJS/TempFuncs.js";

	// Imported functions:
	// import { loadPackage } from "./GenJS/Main.js";

	class LimitTemplate extends Template {
		constructor() {
			super("Limit Template");
			// this.dialogue.addEventListener("show.bs.modal", () => loadPackage("matrix"));
			this.dirInd = 0;
			this.DIRSTRINGS = ["\u2000", "+", "−"]; // En Quad = U+2000
			this.dirSup = this.pattern.querySelector("sup");
			this.dirSup.addEventListener("click", () =>
				this.dirSup.innerText = this.DIRSTRINGS[this.dirInd = (++this.dirInd) % 3]);
		}

		resetButtonAction() {
			super.resetButtonAction();
			this.dirSup.innerText = this.DIRSTRINGS[this.dirInd = 0];
		}

		result() {
			// if (loadSPECFN.isSelected()) preamble("load_package specfn;\n");
			const dir = ["", "!+", "!-"][this.dirInd];
			const values = Array.from(this.inputs).map(input => this.getValueCheckNonEmpty(input));
			return `limit${dir}(${values[2]}, ${values[0]}, ${values[1]})`;
		}
	}

	window.addEventListener("load", () => new LimitTemplate());
</script>
