<modal-dialogue dialogueId="IntegralTemplate" dialogueTitle="Evaluate a Multiple Integral" dialogueSize="modal-lg">
	<p class="text-center"><small>The integrand and first integration variable are required. Enter
			additional integration variables to create a double or triple integral and display additional ∫
			and d symbol pairs, which nest and their colours show how they match. Each pair of limits must
			be both empty, giving an indefinite integral, or both specified, giving a definite
			integral.</small></p>
	<p class="text-center">
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?INT%20Operator" target="_blank" title="Opens in a new tab.">INT
				Operator</a></small>
	</p>
	<div class="container-fluid" style="text-align: center">
		<div style="display: inline-block; vertical-align: middle">
			<input type="text" size="3" />
			<div style="margin-top: -1rem; font-size: 300%; color: red">∫</div>
			<input type="text" size="3" />
		</div>
		<div style="display: inline-block; vertical-align: middle">
			<input type="text" size="3" />
			<div style="margin-top: -1rem; font-size: 300%; color: green">∫</div>
			<input type="text" size="3" />
		</div>
		<div style="display: inline-block; vertical-align: middle">
			<input type="text" size="3" />
			<div style="margin-top: -1rem; font-size: 300%; color: blue">∫</div>
			<input type="text" size="3" />
		</div>
		<input type="text" size="25" value="ws" />
		<span style="color: blue">d</span>
		<input type="text" size="1" value="x" />&nbsp;
		<span style="color: green">d</span>
		<input type="text" size="1" />&nbsp;
		<span style="color: red">d</span>
		<input type="text" size="1" />
	</div>
</modal-dialogue>

<script type="module">
	import { Template } from "./TempFuncs.mjs";

	class IntegralTemplate extends Template {
		constructor() {
			super("Integral Template");
			const contents = this.content.children;
			this.zIntDiv = contents[0];
			const zLimTextFields = this.zIntDiv.querySelectorAll("input"); // [upper, lower]
			this.yIntDiv = contents[1];
			const yLimTextFields = this.yIntDiv.querySelectorAll("input");
			const xIntDiv = contents[2];
			const xLimTextFields = xIntDiv.querySelectorAll("input");
			this.limTextFields = [xLimTextFields, yLimTextFields, zLimTextFields];
			this.integrandTextField = contents[3];
			this.intVarTextFields = [contents[5], contents[7], contents[9]];
			this.yDSpan = contents[6];
			this.zDSpan = contents[8];

			this.intVarTextFields[0].addEventListener("input", () => {
				this.intVarTextFields[1].hidden = (this.intVarTextFields[0].value.trim().length == 0);
			});

			this.intVarTextFields[1].addEventListener("input", () => {
				const hidden = (this.intVarTextFields[1].value.trim().length == 0);
				this.yIntDiv.hidden = hidden;
				this.yDSpan.hidden = hidden;
				this.intVarTextFields[2].hidden = hidden;
			});

			this.intVarTextFields[2].addEventListener("input", () => {
				const hidden = (this.intVarTextFields[2].value.trim().length == 0);
				this.zIntDiv.hidden = hidden;
				this.zDSpan.hidden = hidden;
			});

			this.init();
		}

		init() {
			this.zIntDiv.hidden = this.yIntDiv.hidden = true;
			this.yDSpan.hidden = this.zDSpan.hidden = true;
			this.intVarTextFields[1].hidden = false;
			this.intVarTextFields[2].hidden = true;
		}

		resetButtonAction() {
			super.resetButtonAction();
			this.init();
		}

		result() {
			let text = this.integrandTextField.value.trim();
			if (text.length == 0 || this.intVarTextFields[0].value.trim().length == 0) {
				alert(this.alertHeader +
					"The integrand and integration variable are both required.");
				throw new Error("empty field");
			}
			// Wrap integrand in nested integrals:
			for (let i = 0; i < 3; i++) {
				const intVar = this.intVarTextFields[i].value.trim();
				if (intVar.length != 0) {
					text = "int(" + text;
					const lowLim = this.limTextFields[i][1].value.trim();
					const upLim = this.limTextFields[i][0].value.trim();
					const indefInt = (lowLim.length == 0);
					if ((indefInt) != (upLim.length == 0)) {
						// boolean != is equivalent to exclusive or.
						alert(this.alertHeader +
							"The limits must be both empty or both specified.");
						throw new Error("empty field");
					}
					text += ", " + intVar;
					if (!indefInt) text += ", " + lowLim + ", " + upLim;
					text += ")";
				}
			}
			return text;
		}
	}

	window.addEventListener("load", () => new IntegralTemplate());
</script>
