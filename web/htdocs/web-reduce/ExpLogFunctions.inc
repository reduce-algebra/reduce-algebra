<!--*- mhtml -*-->
<div class="modal fade" id="ExpLogFunctions" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="ExpLogFunctionsLabel" aria-hidden="true">
	<div class="modal-dialog modal-dialog-centered modal-lg">
		<div class="modal-content">
			<div class="modal-header">
				<h5 class="modal-title" id="ExpLogFunctionsLabel">Exponentials, Logarithms, Powers, Roots, etc</h5>
				<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
			</div>
			<div class="modal-body">
				<p class="center"><small>Click on the radio button to the left of the function you want to use. Hover over a function for a brief description. Some functions do not simplify symbolically but evaluate numerically, as indicated in their tooltips.</small></p>
				<p class="center">
					<small>REDUCE Manual:&nbsp;
                        <a href="/manual-lookup.php?Mathematical%20Functions" target="_blank" title="Opens in a new tab.">Mathematical Functions</a>&nbsp;
                        <a href="/manual-lookup.php?SPECFN:" target="_blank" title="Opens in a new tab.">SPECFN Package</a></small>
				</p>
				<div class="container-fluid">
					<div class="row mb-4">
						<div class="col" title="Exponential: e^x = exp(x)">
							<input id="ExpRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="ExpRadioButton">
								e <sup>
									<input id="ExpTextField" type="text" size="3" value="ws" /></sup></label>
						</div>
						<div class="col" title="Natural, i.e. base e, logarithm: ln e = 1">
							<input id="LnRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="LnRadioButton">
								ln
                <input id="LnTextField" type="text" size="3" value="ws" /></label>
						</div>
						<div class="col" title="Logarithm to any base, e.g. 2">
							<input id="LogBaseRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="LogBaseRadioButton">
								log<sub><input id="LogATextField" type="text" size="2" value="2" style="font-style: normal" /></sub>
								<input id="LogBTextField" type="text" size="3" value="ws" /></label>
						</div>
					</div>
					<div class="row mb-4">
						<div class="col" title="Power, e.g. x^2">
							<input id="PowerRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="PowerRadioButton">
								<input id="PowATextField" type="text" size="3" value="ws" /></label>
							<sup>
								<input id="PowBTextField" type="text" size="2" value="2" style="font-style: normal" /></sup>
						</div>
						<div class="col" title="Square root">
							<input id="SqrtRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="SqrtRadioButton">
								<span style="font-size: 150%">√</span>
								<input id="SqrtTextField" type="text" size="3" value="ws" /></label>
						</div>
						<div class="col" title="hypot(x,y) = √(x^2+y^2); numerical only!">
							<input id="HypotRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="HypotRadioButton">
								hypot<span style="font-size: 150%">(</span><input id="HypotXTextField" type="text" size="3" value="x" />
								<span style="font-size: 150%">,</span>
								<input id="HypotYTextField" type="text" size="3" value="y" /><span style="font-size: 150%">)</span></label>
						</div>
					</div>
					<div class="row mb-4">
						<div class="col" title="Base 10 logarithm">
							<input id="Log10RadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="Log10RadioButton">
								log<sub>10</sub>
								<input id="Log10TextField" type="text" size="3" value="ws" /></label>
						</div>
						<div class="col" title="Any root, e.g. cube or third root: (n√x)^n = x">
							<input id="RootRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="RootRadioButton">
								<sup>
									<input id="RootATextField" type="text" size="2" value="3" style="font-style: normal" /></sup>
								<span style="font-size: 150%">√</span>
								<input id="RootBTextField" type="text" size="3" value="ws" /></label>
						</div>
						<div class="col" title="Two argument version of atan(y/x) that returns an angle in the interval (-π/2, π/2] in the correct quadrant depending on the signs of x and y">
							<input id="Atan2RadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="Atan2RadioButton">
								atan<sub>2</sub><span style="font-size: 150%">(</span><input id="Atan2YTextField" type="text" size="3" value="y" />
								<span style="font-size: 150%">/</span>
								<input id="Atan2XTextField" type="text" size="3" value="x" /><span style="font-size: 150%">)</span></label>
						</div>
					</div>
					<div class="row">
						<div class="col" title="Factorial: n! = n×(n-1)×…×2×1">
							<input id="FactorialRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="FactorialRadioButton">
								<input id="FactorialTextField" type="text" size="3" value="ws" />
								<span style="font-size: 150%">!</span></label>
						</div>
						<div class="col" title="Binomial coefficient: (n over m) = n!/((n-m)!m!)">
							<input id="BinCoeffRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="BinCoeffRadioButton">
								<span style="font-size: 400%; vertical-align: middle">(</span>
								<span style="display: inline-block; vertical-align: middle">
									<input id="BinCoeffNTextField" type="text" size="3" value="n" /><br />
									<input id="BinCoeffMTextField" type="text" size="3" value="m" />
								</span>
								<span style="font-size: 400%; vertical-align: middle">)</span>
							</label>
						</div>
						<!-- This needs better handling of the load_package and a manual link to trigd. -->
<!--						<div class="col" title="Two argument version of atand(y/x) that returns an angle in the interval (-90°, 90°] in the correct quadrant depending on the signs of x and y">
							<input id="Atan2DRadioButton" type="radio" name="ExpLogRadioGroup" />
							<label for="Atan2DRadioButton">
								atan<sub>2</sub>d<span style="font-size: 150%">(</span><input id="Atan2DYTextField" type="text" size="3" value="y" />
								<span style="font-size: 150%">/</span>
								<input id="Atan2DXTextField" type="text" size="3" value="x" /><span style="font-size: 150%">)</span></label>
						</div>-->
					</div>
				</div>
				<div class="modal-footer">
					<button type="button" class="btn btn-secondary me-auto" title="Reset to default inputs" style="display: none">Reset</button><!-- Not yet implemented -->
					<button type="button" class="btn btn-primary" title="Insert into input editor">Edit</button>
					<button type="button" class="btn btn-primary" title="Send to REDUCE">Evaluate</button>
					<button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Close</button>
				</div>
			</div>
		</div>
	</div>
</div>

<script>
	'use strict'; // Necesary to make functions defined in a block local
	// Block used for namespace control:
	{
		const buttons = document.querySelectorAll("#ExpLogFunctions div.modal-footer > button");

		function getTextFieldValue(elementId) {
			return document.getElementById(elementId).value.trim();
		}

		function result() {
			switch (document.querySelector('input[name="ExpLogRadioGroup"]:checked').id) {
				case "ExpRadioButton":
					return `exp(${getTextFieldValue("ExpTextField")})`;
				case "LnRadioButton":
					return `log(${getTextFieldValue("LnTextField")})`;
				case "LogBaseRadioButton":
					return `logb(${getTextFieldValue("LogBTextField")},${getTextFieldValue("LogATextField")})`;
				case "PowerRadioButton":
					return `(${getTextFieldValue("PowATextField")})^(${getTextFieldValue("PowBTextField")})`;
				case "SqrtRadioButton":
					return `sqrt(${getTextFieldValue("SqrtTextField")})`;
				case "HypotRadioButton":
					return `hypot(${getTextFieldValue("HypotXTextField")},${getTextFieldValue("HypotYTextField")})`;
				case "Log10RadioButton":
					return `log10(${getTextFieldValue("Log10TextField")})`;
				case "RootRadioButton":
					return `(${getTextFieldValue("RootBTextField")})^1/(${getTextFieldValue("RootATextField")})`;
				case "Atan2RadioButton":
					return `atan2(${getTextFieldValue("Atan2YTextField")},${getTextFieldValue("Atan2XTextField")})`;
				case "FactorialRadioButton":
					return `factorial(${getTextFieldValue("FactorialTextField")})`;
				case "BinCoeffRadioButton":
					return `binomial(${getTextFieldValue("BinCoeffNTextField")},${getTextFieldValue("BinCoeffMTextField")})`;
				case "Atan2DRadioButton":
					//loadPackage("trigd"); // This fails because it needs to wait for REDUCE to digest it!
					return `load_package trigd; atan2d(${getTextFieldValue("Atan2DYTextField")},${getTextFieldValue("Atan2DXTextField")})`;
			}
		}

		buttons[1].addEventListener("click", () => {
			inputTextArea.setRangeText(result());
			buttons[3].click();
		});

		buttons[2].addEventListener("click", () => {
			sendToReduceAndEcho(result() + ";");
			buttons[3].click();
		});
	}
</script>
