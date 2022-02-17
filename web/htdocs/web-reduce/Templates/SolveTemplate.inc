<modal-dialogue dialogueId="SolveTemplate" dialogueTitle="Solve Algebraic Equations">
	<p>
		<small>
			At least one equation or expression is required. If no unknowns are specified then REDUCE solves for all
			those found. Unknowns must be kernels.
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?SOLVE%20Operator" target="_blank" title="Opens in a new tab.">SOLVE
				Operator</a></small>
	</p>
	<div class="pattern">
		<table>
			<colgroup>
				<col style="width: 75%">
				<col style="width: 5%;">
				<col>
			</colgroup>
			<tbody>
				<tr>
					<th>Equations or expressions</th>
					<th></th>
					<th>Unknowns</th>
				</tr>
				<tr>
					<td><input type="text" placeholder="equation or expression" style="width: 100%;" value="ws" /></td>
					<td></td>
					<td><input type="text" placeholder="unknown" style="width: 100%;" /></td>
				</tr>
				<tr>
					<td><input type="text" placeholder="equation or expression" style="width: 100%;" /></td>
					<td></td>
					<td><input type="text" placeholder="unknown" style="width: 100%;" /></td>
				</tr>
				<tr>
					<td><input type="text" placeholder="equation or expression" style="width: 100%;" /></td>
					<td></td>
					<td><input type="text" placeholder="unknown" style="width: 100%;" /></td>
				</tr>
			</tbody>
		</table>

		<!-- <table style="margin-left: auto; margin-right: auto; margin-top: 1em;" class="text-start">
			<colgroup>
				<col>
				<col style="width: 20%;">
				<col>
			</colgroup>
			<tbody>
				<tr>
					<td>
						<div class="form-check" title="Include multiple solutions">
							<input class="form-check-input" type="checkbox" value="" id="multiplicitiesCheckBox">
							<label class="form-check-label" for="multiplicitiesCheckBox">
								multiplicities
							</label>
						</div>
					</td>
					<td></td>
					<td>
						<div class="form-check" title="Use arbitrary constants for degenerate systems">
							<input class="form-check-input" type="checkbox" value="" id="solvesingularCheckBox"
								checked="checked">
							<label class="form-check-label" for="solvesingularCheckBox">
								solvesingular
							</label>
						</div>
					</td>
				</tr>
				<tr>
					<td>
						<div class="form-check" title="Output full roots of cubics and quartics">
							<input class="form-check-input" type="checkbox" value="" id="fullrootsCheckBox">
							<label class="form-check-label" for="fullrootsCheckBox">
								fullroots
							</label>
						</div>
					</td>
					<td></td>
					<td>
						<div class="form-check" title="Include all branches">
							<input class="form-check-input" type="checkbox" value="" id="allbranchCheckBox"
								checked="checked">
							<label class="form-check-label" for="allbranchCheckBox">
								allbranch
							</label>
						</div>
					</td>
				</tr>
				<tr>
					<td>
						<div class="form-check" title="Use trigonometric forms for roots of cubics and quartics">
							<input class="form-check-input" type="checkbox" value="" id="trigformCheckBox"
								checked="checked">
							<label class="form-check-label" for="trigformCheckBox">
								trigform
							</label>
						</div>
					</td>
					<td></td>
					<td>
						<div class="form-check" title="Use new indeterminate kernels">
							<input class="form-check-input" type="checkbox" value="" id="arbvarsCheckBox"
								checked="checked">
							<label class="form-check-label" for="arbvarsCheckBox">
								arbvars
							</label>
						</div>
					</td>
				</tr>
			</tbody>
		</table> -->

	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./GenJS/TempFuncs.js";

	class SolveTemplate extends Template {
		constructor() {
			super("Solve Template");
		}

		result() {
			// Process equations and unknowns:
			const eqns = [], vars = [];
			for (let i = 0; i < this.inputs.length; i++) {
				let value = this.inputs[i].value.trim();
				if (value) eqns.push(value);
				value = this.inputs[++i].value.trim();
				if (value) vars.push(value);
			}
			if (eqns.length === 0) {
				alert(this.alertHeader +
					"At least one equation/expression is required.");
				throw new Error("empty field");
			}
			// Construct and return the REDUCE input:
			let text = "solve(";
			if (eqns.length === 1) text += eqns[0];
			else text += "{" + eqns.join(", ") + "}";
			// Process variables and, if numeric, start values:
			if (vars.length > 0) {
				text += ", ";
				if (vars.length === 1) text += vars[0];
				else text += "{" + vars.join(", ") + "}";
			}
			return text + ")";
		}
	}

	window.addEventListener("load", () => new SolveTemplate());
</script>
