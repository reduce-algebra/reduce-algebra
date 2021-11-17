<!--*- mhtml -*-->
<div class="modal fade" id="IntegralTemplate" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1"
	aria-labelledby="IntegralTemplateLabel" aria-hidden="true">
	<div class="modal-dialog modal-dialog-centered modal-lg">
		<div class="modal-content">
			<div class="modal-header">
				<h5 class="modal-title" id="IntegralTemplateLabel">Evaluate a Multiple Integral</h5>
				<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
			</div>
			<div class="modal-body">
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
</div>
<script>
	'use strict'; // Necesary to make functions defined in a block local
	// Block used for namespace control:
	{
		const contents = document.querySelector("#IntegralTemplate div[class^=container]").children;
		const zIntDiv = contents[0];
		const zLimTextFields = zIntDiv.querySelectorAll("input"); // [upper, lower]
		const yIntDiv = contents[1];
		const yLimTextFields = yIntDiv.querySelectorAll("input");
		const xIntDiv = contents[2];
		const xLimTextFields = xIntDiv.querySelectorAll("input");
		const limTextFields = [xLimTextFields, yLimTextFields, zLimTextFields];
		const integrandTextField = contents[3];
		const intVarTextFields = [contents[5], contents[7], contents[9]];
		const yDSpan = contents[6];
		const zDSpan = contents[8];
		const buttons = document.querySelectorAll("#IntegralTemplate div.modal-footer > button");

		function resetButtonAction() {
			for (let i = 0; i < 3; i++)
				limTextFields[i][0].value = limTextFields[i][1].value = "";
			zIntDiv.hidden = yIntDiv.hidden = true;
			integrandTextField.value = "ws";
			intVarTextFields[0].value = "x";
			intVarTextFields[1].value = intVarTextFields[2].value = "";
			yDSpan.hidden = zDSpan.hidden = true;
			intVarTextFields[1].hidden = false;
			intVarTextFields[2].hidden = true;
		}
		resetButtonAction();
		buttons[0].addEventListener("click", resetButtonAction);

		const alertHeader = "Integral Template Error\n";

		intVarTextFields[0].addEventListener("input", () => {
			intVarTextFields[1].hidden = (intVarTextFields[0].value.trim().length == 0);
		});

		intVarTextFields[1].addEventListener("input", () => {
			const hidden = (intVarTextFields[1].value.trim().length == 0);
			yIntDiv.hidden = hidden;
			yDSpan.hidden = hidden;
			intVarTextFields[2].hidden = hidden;
		});

		intVarTextFields[2].addEventListener("input", () => {
			const hidden = (intVarTextFields[2].value.trim().length == 0);
			zIntDiv.hidden = hidden;
			zDSpan.hidden = hidden;
		});

		function result() {
			let text = integrandTextField.value.trim();
			if (text.length == 0 || intVarTextFields[0].value.trim().length == 0) {
				alert(alertHeader +
					"The integrand and integration variable are both required.");
				throw new Error("empty field");
			}
			// Wrap integrand in nested integrals:
			for (let i = 0; i < 3; i++) {
				const intVar = intVarTextFields[i].value.trim();
				if (intVar.length != 0) {
					text = "int(" + text;
					const lowLim = limTextFields[i][1].value.trim();
					const upLim = limTextFields[i][0].value.trim();
					const indefInt = (lowLim.length == 0);
					if ((indefInt) != (upLim.length == 0)) {
						// boolean != is equivalent to exclusive or.
						alert(alertHeader +
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

		buttons[1].addEventListener("click", () => {
			try {
				inputDivInsert(result());
				buttons[3].click();
			} catch (ignored) { }
		});

		buttons[2].addEventListener("click", () => {
			try {
				sendToReduceAndEcho(result() + ";");
				buttons[3].click();
			} catch (ignored) { }
		});

		document.getElementById("IntegralTemplate")
			.addEventListener("hidden.bs.modal", () => inputDiv.focus());
	}
</script>
