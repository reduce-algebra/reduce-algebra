<modal-dialogue dialogueId="DerivativeTemplate" dialogueTitle="Evaluate a Multiple (Partial) Derivative">
	<p class="text-center"><small>The dependent variable or expression and an independent variable are
			required. Other fields may be left empty. Superscripts represent orders, which unless empty must
			be positive integers.</small></p>
	<p class="text-center">
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?DF%20Operator" target="_blank" title="Opens in a new tab.">DF
				Operator</a></small>
	</p>
	<div class="container-fluid text-center">
		<div>
			∂ <sup></sup>
			<input type="text" style="width: 11em" value="ws" />
		</div>
		<div style="display: inline-block; margin-top: 5px; border-top: thin solid black; padding-top: 5px;">
			∂<input type="text" data-index="0" style="width: 2em" value="x" /><sup><input type="text" data-index="0"
					style="width: 2em; font-style: normal" /></sup>
			∂<input type="text" data-index="1" style="width: 2em" /><sup><input type="text" data-index="1"
					style="width: 2em; font-style: normal" /></sup>
			∂<input type="text" data-index="2" style="width: 2em" /><sup><input type="text" data-index="2"
					style="width: 2em; font-style: normal" /></sup>
		</div>
	</div>
</modal-dialogue>

<script type="module">
	import { Template } from "./TempFuncs.mjs";

	class DerivativeTemplate extends Template {
		constructor() {
			super("Derivative Template");
			const inputs = this.content.querySelectorAll("input");
			this.totalOrdSup = this.content.querySelector("sup");
			this.depVarTextField = inputs[0];
			this.indVarTextFields = [inputs[1], inputs[3], inputs[5]];
			this.ordTextFields = [inputs[2], inputs[4], inputs[6]];
			this.orders = [1, 0, 0];

			for (let n = 0; n < 3; n++) {
				this.indVarTextFields[n].addEventListener("input", this.indVarAction);
				this.ordTextFields[n].addEventListener("input", this.indVarAction);
			}
		}

		resetButtonAction() {
			this.totalOrdSup.innerText = "";
			this.depVarTextField.value = "ws";
			this.indVarTextFields[0].value = "x";
			this.indVarTextFields[1].value = this.indVarTextFields[2].value = "";
			this.ordTextFields[0].value = this.ordTextFields[1].value = this.ordTextFields[2].value = "";
			this.orders[0] = 1; this.orders[1] = this.orders[2] = 0;
		}

		indVarAction(event) {
			const n = event.target.dataset.index;
			const indVar = this.indVarTextFields[n].value.trim();
			let order = this.ordTextFields[n].value.trim();
			if (indVar.length == 0) {
				if (order.length > 0) {
					alert(this.alertHeader +
						"Specify the independent variable before specifying its order.");
					this.ordTextFields[n].value = "";
				}
				order = 0;
			} else if (order.length == 0)
				order = 1;
			else {
				order = Number(order);
				if (!Number.isInteger(order) || order <= 0) {
					alert(this.alertHeader +
						"An order must be a positive integer.");
					this.ordTextFields[n].value = "";
					return;
				}
			}
			this.orders[n] = order;
			order = this.orders.reduce((acc, val) => acc + val); // sum of orders
			if (order > 1) {
				this.totalOrdSup.innerText = order + " ";
			} else {
				this.totalOrdSup.innerText = "";
			}
		}

		result() {
			const depVar = this.depVarTextField.value.trim();
			let indVarFound = false;
			if (depVar.length == 0) {
				alert(this.alertHeader +
					"A dependent variable or expression is required.");
				throw new Error("empty field");
			}
			let text = "df(" + depVar;
			for (let n = 0; n < 3; n++) {
				const indVar = this.indVarTextFields[n].value.trim();
				if (indVar.length != 0) {
					indVarFound = true;
					text += ", " + indVar;
					if (this.orders[n] > 1) text += ", " + this.orders[n];
				}
			}
			if (indVarFound) return text + ")";
			else {
				alert(this.alertHeader +
					"At least one independent variable is required.");
				throw new Error("empty field");
			}
		}
	}

	window.addEventListener("load", () => new DerivativeTemplate());
</script>
