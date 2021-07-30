<!--*- mhtml -*-->
<div class="modal fade" id="ExpLogFunctions" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="ExpLogFunctionsLabel" aria-hidden="true">
  <div class="modal-dialog modal-dialog-centered modal-lg">
	<div class="modal-content">
	  <div class="modal-header">
		<h5 class="modal-title" id="ExpLogFunctionsLabel">Exponentials, Logarithms, Powers, Roots, etc</h5>
		<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
	  </div>
	  <div class="modal-body">
		<p class="text-center"><small>Click on the function you want to use.  Hover over a function for a brief description.  Some functions do not simplify symbolically but evaluate numerically, as indicated in their tooltips.</small></p>
		<p class="text-center">
		  <small>REDUCE Manual:&ensp;
            <a href="/manual-lookup.php?Mathematical%20Functions" target="_blank" title="Opens in a new tab.">Mathematical Functions</a>&ensp;
            <a href="/manual-lookup.php?SPECFN:" target="_blank" title="Opens in a new tab.">SPECFN Package</a></small>
		</p>
		<table class="function-templates">
          <tbody>
		    <tr>
			  <td data-function="Exp" title="Exponential: e^x = exp(x)">
			    <span class="fs-big">e</span> <sup><input type="text" size="3" value="ws" /></sup>
			  </td>
			  <td data-function="Ln" title="Natural, i.e. base e, logarithm: ln e = 1">
			    <span class="fs-big">ln</span> <input type="text" size="3" value="ws" />
			  </td>
			  <td data-function="LogBase" title="Logarithm to any base, e.g. 2">
			    <span class="fs-big">log</span><sub><input type="text" size="2" value="2" style="font-style: normal" /></sub>
			    <input type="text" size="3" value="ws" />
			  </td>
            </tr>
            <tr>
			  <td data-function="Power" title="Power, e.g. x^2">
			    <input type="text" size="3" value="ws" />
			    <sup><input type="text" size="2" value="2" style="font-style: normal" /></sup>
			  </td>
			  <td data-function="Sqrt" title="Square root">
			    <span class="fs-big">√</span>
			    <input type="text" size="3" value="ws" />
			  </td>
			  <td data-function="Hypot" title="hypot(x,y) = √(x^2+y^2); numerical only!">
			    <span class="fs-big">hypot(</span><input type="text" size="3" value="x" />
			    <span class="fs-big">,</span>
			    <input type="text" size="3" value="y" /><span class="fs-big">)</span>
			  </td>
            </tr>
            <tr>
			  <td data-function="Log10" title="Base 10 logarithm">
			    <span class="fs-big">log<sub>10</sub></span>
			    <input type="text" size="3" value="ws" />
			  </td>
			  <td data-function="Root" title="Any root, e.g. cube or third root: (n√x)^n = x">
			    <sup><input type="text" size="2" value="3" style="font-style: normal" /></sup>
			    <span class="fs-big">√</span>
			    <input type="text" size="3" value="ws" />
			  </td>
			  <td data-function="Atan2" title="Two argument version of atan(y/x) that returns an angle in the interval (-π/2, π/2] in the correct quadrant depending on the signs of x and y">
			    <span class="fs-big">atan<sub>2</sub>(</span><input type="text" size="3" value="y" />
			    <span class="fs-big">/</span>
			    <input type="text" size="3" value="x" /><span class="fs-big">)</span>
			  </td>
            </tr>
            <tr>
			  <td data-function="Factorial" title="Factorial: n! = n×(n-1)×…×2×1">
			    <input type="text" size="3" value="ws" />
			    <span class="fs-big">!</span>
			  </td>
			  <td data-function="BinCoeff" title="Binomial coefficient: (n over m) = n!/((n-m)!m!)">
			    <span style="font-size: 400%; line-height: 0.8">(</span>
			    <span style="display: inline-block">
				  <input type="text" size="3" value="n" /><br />
				  <input type="text" size="3" value="m" />
			    </span>
			    <span style="font-size: 400%; line-height: 0.8">)</span>
			  </td>
			  <!-- This needs better handling of the load_package and a manual link to trigd. -->
			  <!-- <td data-function="Atan2D" title="Two argument version of atand(y/x) that returns an angle in the interval (-90°, 90°] in the correct quadrant depending on the signs of x and y"> -->
			  <!--   <span class="fs-big">atan<sub>2</sub>d(</span><input type="text" size="3" value="y" /> -->
			  <!--   <span class="fs-big">/</span> -->
			  <!--   <input type="text" size="3" value="x" /><span class="fs-big">)</span> -->
			  <!-- </td> -->
		    </tr>
          </tbody>
		</table>
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
	  const buttons = document.querySelectorAll("#ExpLogFunctions div.modal-footer > button");

      const functions = document.querySelectorAll("#ExpLogFunctions td");
      let selectedFunction;
      for (let i = 0; i < functions.length; i++)
          functions[i].addEventListener("click", event => {
              if (selectedFunction) selectedFunction.classList.remove("selected");
              selectedFunction = functions[i];
              selectedFunction.classList.add("selected");
          });

      const inputs = document.querySelectorAll("#ExpLogFunctions input");
      const initialInputValues = ["ws","ws","2","ws","ws","2","ws","x","y","ws","3","ws","y","x","ws","n","m","y","x"];
	  function resetButtonAction() {
          for (let i = 0; i < inputs.length; i++)
              inputs[i].value = initialInputValues[i];
          if (selectedFunction) {
              selectedFunction.classList.remove("selected");
              selectedFunction = undefined;
          }
      }
	  resetButtonAction();
	  buttons[0].addEventListener("click", resetButtonAction);

	  function result() {
          let values = [...selectedFunction.getElementsByTagName("input")]
              .map(el => el.value.trim());
		  switch (selectedFunction.dataset.function) {
		  case "Exp":
              return `exp(${values[0]})`;
		  case "Ln":
			  return `log(${values[0]})`;
		  case "LogBase":
			  return `logb(${values[1]},${values[0]})`;
		  case "Power":
			  return `(${values[0]})^(${values[1]})`;
		  case "Sqrt":
			  return `sqrt(${values[0]})`;
		  case "Hypot":
			  return `hypot(${values[0]},${values[1]})`;
		  case "Log10":
			  return `log10(${values[0]})`;
		  case "Root":
			  return `(${values[1]})^1/(${values[0]})`;
		  case "Atan2":
			  return `atan2(${values[0]},${values[1]})`;
		  case "Factorial":
			  return `factorial(${values[0]})`;
		  case "BinCoeff":
			  return `binomial(${values[0]},${values[1]})`;
		  case "Atan2D":
			  //loadPackage("trigd"); // This fails because it needs to wait for REDUCE to digest it!
			  return `load_package trigd; atan2d(${values[0]},${values[1]})`;
		  }
	  }

	  buttons[1].addEventListener("click", () => {
		  if (selectedFunction) inputTextArea.setRangeText(result());
		  buttons[3].click();
	  });

	  buttons[2].addEventListener("click", () => {
		  if (selectedFunction) sendToReduceAndEcho(result() + ";");
		  buttons[3].click();
	  });
  }
</script>
