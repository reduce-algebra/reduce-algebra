<!--*- mhtml -*-->
<div class="modal fade" id="DerivativeTemplate" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="DerivativeTemplateLabel" aria-hidden="true">
  <div class="modal-dialog modal-dialog-centered">
	<div class="modal-content">
	  <div class="modal-header">
		<h5 class="modal-title" id="DerivativeTemplateLabel">Evaluate a Multiple (Partial) Derivative</h5>
		<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
	  </div>
	  <div class="modal-body">
		<p class="text-center"><small>The dependent variable or expression and an independent variable are required. Other fields may be left empty. Superscripts represent orders, which unless empty must be positive integers.</small></p>
		<p class="text-center">
		  <small>REDUCE Manual:&ensp;
            <a href="/manual-lookup.php?DF%20Operator" target="_blank" title="Opens in a new tab.">DF Operator</a></small>
		</p>
		<div class="container-fluid text-center">
		  <div>
			∂ <sup></sup>
			<input type="text" style="width: 11em" value="ws" />
		  </div>
		  <div style="display: inline-block; margin-top: 5px; border-top: thin solid black; padding-top: 5px;">
			∂<input type="text" data-index="0" style="width: 2em" value="x" /><sup><input type="text" data-index="0" style="width: 2em; font-style: normal" /></sup>
			∂<input type="text" data-index="1" style="width: 2em" /><sup><input type="text" data-index="1" style="width: 2em; font-style: normal" /></sup>
			∂<input type="text" data-index="2" style="width: 2em" /><sup><input type="text" data-index="2" style="width: 2em; font-style: normal" /></sup>
		  </div>
		</div>
		<div class="modal-footer">
		  <button type="button" class="btn btn-secondary me-auto" title="Reset to default inputs">Reset</button>
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
	  const content = document.querySelector("#DerivativeTemplate div[class^=container]");
	  const totalOrdSup = content.querySelector("sup");
	  const inputs = content.querySelectorAll("input");
	  const depVarTextField = inputs[0];
	  const indVarTextFields = [inputs[1], inputs[3], inputs[5]];
	  const ordTextFields = [inputs[2], inputs[4], inputs[6]];
	  const buttons = document.querySelectorAll("#DerivativeTemplate div.modal-footer > button");

	  const orders = [1, 0, 0];

	  function resetButtonAction() {
		  totalOrdSup.innerText = "";
		  depVarTextField.value = "ws";
		  indVarTextFields[0].value = "x";
		  indVarTextFields[1].value = indVarTextFields[2].value = "";
		  ordTextFields[0].value = ordTextFields[1].value = ordTextFields[2].value = "";
		  orders[0] = 1; orders[1] = orders[2] = 0;
	  }
	  resetButtonAction();
	  buttons[0].addEventListener("click", resetButtonAction);

	  const alertHeader = "Derivative Template Error\n";

	  function indVarAction(event) {
		  const n = event.target.dataset.index;
		  const indVar = indVarTextFields[n].value.trim();
		  let order = ordTextFields[n].value.trim();
		  if (indVar.length == 0) {
			  if (order.length > 0) {
				  alert(alertHeader +
						"Specify the independent variable before specifying its order.");
				  ordTextFields[n].value = "";
			  }
			  order = 0;
		  } else if (order.length == 0)
			  order = 1;
		  else {
			  order = Number(order);
			  if (!Number.isInteger(order) || order <= 0) {
				  alert(alertHeader +
						"An order must be a positive integer.");
				  ordTextFields[n].value = "";
				  return;
			  }
		  }
		  orders[n] = order;
		  order = orders.reduce((acc, val) => acc + val); // sum of orders
		  if (order > 1) {
			  totalOrdSup.innerText = order + " ";
		  } else {
			  totalOrdSup.innerText = "";
		  }
	  }

	  for (let n = 0; n < 3; n++) {
		  indVarTextFields[n].addEventListener("input", indVarAction);
		  ordTextFields[n].addEventListener("input", indVarAction);
	  }

	  function result() {
		  const depVar = depVarTextField.value.trim();
		  let indVarFound = false;
		  if (depVar.length == 0) {
			  alert(alertHeader +
					"A dependent variable or expression is required.");
			  throw new Error("empty field");
		  }
		  let text = "df(" + depVar;
		  for (let n = 0; n < 3; n++) {
			  const indVar = indVarTextFields[n].value.trim();
			  if (indVar.length != 0) {
				  indVarFound = true;
				  text += ", " + indVar;
				  if (orders[n] > 1) text += ", " + orders[n];
			  }
		  }
		  if (indVarFound) return text + ")";
		  else {
			  alert(alertHeader +
					"At least one independent variable is required.");
			  throw new Error("empty field");
		  }
	  }

	  buttons[1].addEventListener("click", () => {
		  try {
			  inputTextArea.setRangeText(result());
			  buttons[3].click();
		  } catch (ignored) { }
	  });

	  buttons[2].addEventListener("click", () => {
		  try {
			  sendToReduceAndEcho(result() + ";");
			  buttons[3].click();
		  } catch (ignored) { }
	  });
  }
</script>
