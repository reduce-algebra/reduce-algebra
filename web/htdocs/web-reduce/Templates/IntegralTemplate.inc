<modal-dialogue dialogueId="IntegralTemplate" dialogueTitle="Evaluate a Multiple Integral" dialogueSize="modal-lg">
	<p>
		<small>
			The integrand and first integration variable are required. Enter additional integration variables to create
			a double or triple integral and display additional ∫ and d symbol pairs, which nest and their colours show
			how they match. Each pair of limits must be both empty, giving an indefinite integral, or both specified,
			giving a definite integral.
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?INT%20Operator" target="_blank" title="Opens in a new tab.">INT
				Operator</a></small>
	</p>
	<div class="pattern" style="display: flex; justify-content: center; align-items: center;">
		<div style="display: inline-block; vertical-align: middle; min-width: 1em; flex: 0 1 3em;">
			<input type="text" style="width: 100%;" />
			<div style="margin-top: -1rem; font-size: 300%; color: red">∫</div>
			<input type="text" style="width: 100%;" />
		</div>
		&nbsp;
		<div style="display: inline-block; vertical-align: middle; min-width: 1em; flex: 0 1 3em;">
			<input type="text" style="width: 100%;" />
			<div style="margin-top: -1rem; font-size: 300%; color: green">∫</div>
			<input type="text" style="width: 100%;" />
		</div>
		&nbsp;
		<div style="display: inline-block; vertical-align: middle; min-width: 1em; flex: 0 1 3em;">
			<input type="text" style="width: 100%;" />
			<div style="margin-top: -1rem; font-size: 300%; color: blue">∫</div>
			<input type="text" style="width: 100%;" />
		</div>
		&nbsp;
		<input placeholder="algebraic" type="text" value="ws" style="min-width: 5em; flex: 0 1 15em;" />
		&nbsp; <span style=" color: blue">d</span>
		<input placeholder="var" type="text" value="x" style="min-width: 1em; flex: 0 2 2em;" />
		&nbsp; <span style="color: green">d</span>
		<input type="text" style="min-width: 1em; flex: 0 2 2em;" />
		&nbsp; <span style="color: red">d</span>
		<input type="text" style="min-width: 1em; flex: 0 2 2em;" />
	</div>
</modal-dialogue>

<script type="module">
	import { Template } from "./GenJS/TempFuncs.js";

	class IntegralTemplate extends Template {
		constructor() {
			super("Integral Template");
			const fields = this.pattern.children;
			this.zIntDiv = fields[0];
			const zLimTextFields = this.zIntDiv.querySelectorAll("input"); // [upper, lower]
			this.yIntDiv = fields[1];
			const yLimTextFields = this.yIntDiv.querySelectorAll("input");
			const xIntDiv = fields[2];
			const xLimTextFields = xIntDiv.querySelectorAll("input");
			this.limTextFields = [xLimTextFields, yLimTextFields, zLimTextFields];
			this.integrandTextField = fields[3];
			this.intVarTextFields = [fields[5], fields[7], fields[9]];
			this.yDSpan = fields[6];
			this.zDSpan = fields[8];

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
			if (this.checkNonEmpty && (!text || !this.intVarTextFields[0].value.trim())) {
				alert(this.alertHeader +
					"The integrand and integration variable are both required.");
				throw new Error("empty field");
			}
			// Wrap integrand in nested integrals:
			for (let i = 0; i < 3; i++) {
				const intVar = this.intVarTextFields[i].value.trim();
				if (intVar) {
					text = "int(" + text;
					const lowLim = this.limTextFields[i][1].value.trim();
					const upLim = this.limTextFields[i][0].value.trim();
					if (this.checkNonEmpty && (!lowLim !== !upLim)) {
						// boolean !== is equivalent to exclusive or.
						alert(this.alertHeader +
							"The limits must be both empty or both specified.");
						throw new Error("empty field");
					}
					text += ", " + intVar;
					if (lowLim) text += ", " + lowLim + ", " + upLim;
					text += ")";
				}
			}
			return text;
		}
	}

	window.addEventListener("load", () => new IntegralTemplate());
</script>
