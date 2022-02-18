<modal-dialogue dialogueId="SumProdTemplate" dialogueTitle="Evaluate a Sum or Product">
	<p>
		<small>
			The main operand must be specified and may be any algebraic expression. The control variable (bottom left
			field) must also be specified. Sums and products over symbolic ranges are exact, may be indefinite, so the
			upper or both limits may be omitted, or the limits may be symbolic, and the variable may be a kernel. Sums
			and products over numeric ranges require both limits to evaluate to numbers.
		</small>
	</p>
	<div style="display: flex; justify-content: space-evenly; flex-wrap: wrap;">
		<div class="btn-group btn-group-sm mb-2" role="group" aria-label="Basic radio toggle button group">
			<input type="radio" class="btn-check" name="SumProdTemplate-SumProdButtons" id="SumProdTemplate-Sum"
				autocomplete="off" value="∑" checked="checked" />
			<label class="btn btn-outline-primary" for="SumProdTemplate-Sum">Sum</label>
			<input type="radio" class="btn-check" name="SumProdTemplate-SumProdButtons" id="SumProdTemplate-Prod"
				autocomplete="off" value="∏" />
			<label class="btn btn-outline-primary" for="SumProdTemplate-Prod">Product</label>
		</div>
		<div class="btn-group btn-group-sm mb-2" role="group" aria-label="Basic radio toggle button group">
			<input type="radio" class="btn-check" name="SumProdTemplate-SymNumButtons" id="SumProdTemplate-Sym"
				autocomplete="off" checked="checked" />
			<label class="btn btn-outline-primary" for="SumProdTemplate-Sym" title="Seek a closed-form result.">Symbolic
				Range</label>
			<input type="radio" class="btn-check" name="SumProdTemplate-SymNumButtons" id="SumProdTemplate-Num"
				autocomplete="off" />
			<label class="btn btn-outline-primary" for="SumProdTemplate-Num" title="Use a for loop.">Numeric
				Range</label>
		</div>
	</div>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?SUM:%20A%20package%20for%20series%20summation" target="_blank"
				title="Opens in a new tab.">SUM Package</a>
			<a href="/manual-lookup.php?FOR%20Statements" target="_blank" title="Opens in a new tab.">FOR
				Statements</a>
		</small>
	</p>
	<div class="pattern">
		<table style="margin-left: auto; margin-right: auto;">
			<tbody>
				<tr>
					<td><input type="text" placeholder="alg" style="width: 3em; font-size: small;" /></td>
				</tr>
				<tr>
					<td style="font-size: xx-large; line-height: 95%; padding-bottom: 0.4em;">∑</td>
					<td><input type="text" placeholder="algebraic" value="ws" /></td>
				</tr>
				<tr>
					<td style="white-space: nowrap;">
						<input type="text" placeholder="var" style="width: 3em; font-size: small;" value="i" />
						=
						<input type="text" placeholder="alg" style="width: 3em; font-size: small;" value="0" />
					</td>
				</tr>
			</tbody>
		</table>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./GenJS/TempFuncs.js";

	class SumProdTemplate extends Template {
		constructor() {
			super("SumProd Template");
			const sumProdTdElement = this.pattern.querySelector("table tr+tr>td:first-child");
			document.getElementsByName("SumProdTemplate-SumProdButtons").forEach(element =>
				element.addEventListener("change", () => sumProdTdElement.innerText = element.value));
			const aElements = document.querySelectorAll("#SumProdTemplate a");
			aElements[1].hidden = true;
			document.getElementsByName("SumProdTemplate-SymNumButtons").forEach(element =>
				element.addEventListener("change", () => aElements.forEach(el => el.hidden = !el.hidden)));
		}

		resetButtonAction() {
			super.resetButtonAction();
			document.getElementById("SumProdTemplate-Sum").click();
			document.getElementById("SumProdTemplate-Sym").click();
		}

		result() {
			const sumProd = document.getElementById("SumProdTemplate-Sum").checked ? "sum" : "prod";
			if (document.getElementById("SumProdTemplate-Sym").checked) {
				// symbolic range: use sum/prod function:
				let text = sumProd + "(" +
					this.getValueCheckNonEmpty(this.inputs[1]) // operand
					+ ", " + this.getValueCheckNonEmpty(this.inputs[2]); // var
				let t = this.inputs[3].value.trim(); // lowLim
				if (t) {
					text += ", " + t;
					t = this.inputs[0].value.trim(); // upLim
					if (t) text += ", " + t;
				}
				return text + ")";
			} else {
				// numeric range: use for loop:
				// switchNameOnOff("rounded");
				return "for " + this.getValueCheckNonEmpty(this.inputs[2]) // var
					+ " := " + this.getValueCheckNonEmpty(this.inputs[3]) // lowLim
					+ " : " + this.getValueCheckNonEmpty(this.inputs[0]) // upLim
					+ " " + sumProd + " "
					+ this.getValueCheckNonEmpty(this.inputs[1]); // operand
			}
		}
	}

	window.addEventListener("load", () => new SumProdTemplate());
</script>
