<!--*- mhtml -*-->
<div class="modal fade" id="GammaEtcFunctions" data-bs-backdrop="static" data-bs-keyboard="false" tabindex="-1" aria-labelledby="GammaEtcFunctionsLabel" aria-hidden="true">
  <div class="modal-dialog modal-dialog-centered modal-lg">
	<div class="modal-content">
	  <div class="modal-header">
		<h5 class="modal-title" id="GammaEtcFunctionsLabel">Gamma, Beta and Related Functions</h5>
		<button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
	  </div>
	  <div class="modal-body">
		<p class="text-center"><small>Click on the function you want to use.  Hover over a function for a hint at its definition.  Click on a function name to open the full definition in the <a href="https://dlmf.nist.gov/" target="_blank" title="Opens in a new tab.">NIST Digital Library of Mathematical Functions</a> in a new tab.</small></p>
		<p class="text-center">
		  <small>REDUCE Manual:&ensp;
            <a href="/manual-lookup.php?Mathematical%20Functions" target="_blank" title="Opens in a new tab.">Mathematical Functions</a>&ensp;
            <a href="/manual-lookup.php?SPECFN:" target="_blank" title="Opens in a new tab.">SPECFN Package</a></small>
		</p>
		<table class="function-templates">
          <tbody>
		    <tr>
			  <td data-function="Gamma" title="Γ(z) = (z-1)!">
                <p><a href="https://dlmf.nist.gov/5.2.E1" target="_blank" title="Opens in a new tab.">Gamma Function</a></p>
                <span class="fs-big">Γ(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
			  </td>
			  <td data-function="Beta" title="B(a,b) = Γ(a)Γ(b)/Γ(a+b)">
                <p><a href="https://dlmf.nist.gov/5.12" target="_blank" title="Opens in a new tab.">Beta Function</a></p>
			    <span class="fs-big">Β(</span><input type="text" size="3" value="a" />
                <span class="fs-big">,</span>
                <input type="text" size="3" value="b" /><span class="fs-big">)</span>
			  </td>
            </tr>
		    <tr>
			  <td data-function="Digamma" title="ψ(z) = Γ′(z)/Γ(z)">
                <p><a href="https://dlmf.nist.gov/5.2.E2" target="_blank" title="Opens in a new tab.">Digamma Function</a></p>
                <span class="fs-big">ψ(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
			  </td>
			  <td data-function="Polygamma" title="ψ^(n)(z) = d^nψ(z)/dz^n">
                <p><a href="https://dlmf.nist.gov/5.15" target="_blank" title="Opens in a new tab.">Polygamma Function</a></p>
			    <span class="fs-big">ψ<sup>(<span class="fs-normal"><input type="text" size="2" value="n" /></span>)</sup>(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
			  </td>
            </tr>
            <tr>
              <td data-function="IncompleteGamma" title="P(a,z) = 1/Γ(a) ∫_0^z t^{a-1} e^{-t} dt">
                <p><a href="https://dlmf.nist.gov/8.2.i" target="_blank" title="Opens in a new tab.">Normalized Incomplete Gamma</a></p>
			    <span class="fs-big"><i>P</i>(</span><input type="text" size="3" value="a" />
                <span class="fs-big">,</span>
                <input type="text" size="3" value="z" /><span class="fs-big">)</span>
			  </td>
			  <td data-function="IncompleteBeta" title="I_x(a,b) = 1/B(a,b) ∫_0^x t^{a-1} (1-t)^{b-1} dt">
                <p><a href="https://dlmf.nist.gov/8.17.i" target="_blank" title="Opens in a new tab.">Normalized Incomplete Beta</a></p>
			    <span class="fs-big"><i>I</i></span><sub><input type="text" size="2" value="x" /></sub><span class="fs-big">(</span><input type="text" size="3" value="a" />
                <span class="fs-big">,</span>
                <input type="text" size="3" value="b" /><span class="fs-big">)</span>
			  </td>
            </tr>
		    <tr>
			  <td data-function="Dilogarithm" title="Li_2(z) ≡ ∑_{n=1}^∞ z^n/n^2">
                <p><a href="https://dlmf.nist.gov/25.12.i" target="_blank" title="Opens in a new tab.">Dilogarithm</a></p>
                <span class="fs-big">Li<sub>2</sub>(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
			  </td>
			  <td data-function="Pochhammer" title="(a)_n = Γ(a+n)/Γ(a)">
                <p><a href="https://dlmf.nist.gov/5.2.iii" target="_blank" title="Opens in a new tab.">Pochhammer&quot;s Symbol</a></p>
			    <span class="fs-big">(</span><input type="text" size="3" value="a" /><span class="fs-big">)</span><sub><input type="text" size="2" value="n" /></sub>
			  </td>
            </tr>
		    <tr>
			  <td data-function="BinCoeff" title="(n over m) = n!/((n-m)!m!)">
                <p><a href="https://dlmf.nist.gov/26.3.E1" target="_blank" title="Opens in a new tab.">Binomial Coefficient</a></p>
			    <span style="font-size: 400%; line-height: 0.8">(</span>
			    <span style="display: inline-block">
				  <input type="text" size="3" value="n" /><br />
				  <input type="text" size="3" value="m" />
			    </span>
			    <span style="font-size: 400%; line-height: 0.8">)</span>
			  </td>
			  <td data-function="RiemannZeta" title="ζ(s) = ∑_{n=1}^∞ 1/n^s">
                <p><a href="https://dlmf.nist.gov/25.2.E1" target="_blank" title="Opens in a new tab.">Riemann Zeta Function</a></p>
			    <span class="fs-big">ζ(</span><input type="text" size="3" value="s" /><span class="fs-big">)</span>
			  </td>
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
	  const buttons = document.querySelectorAll("#GammaEtcFunctions div.modal-footer > button");

      const functions = document.querySelectorAll("#GammaEtcFunctions td");
      let selectedFunction;
      for (let i = 0; i < functions.length; i++)
          functions[i].addEventListener("click", event => {
              if (selectedFunction) selectedFunction.classList.remove("selected");
              selectedFunction = functions[i];
              selectedFunction.classList.add("selected");
          });

      const inputs = document.querySelectorAll("#GammaEtcFunctions input");
      const initialInputValues = ["z","a","b","z","n","z","a","z","x","a","b","z","a","n","m","n","s"];
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
		  case "Gamma":
              return `Gamma(${values[0]})`;
		  case "Beta":
			  return `Beta(${values[0]},${values[1]})`;
		  case "Digamma":
			  return `psi(${values[0]})`;
		  case "Polygamma":
			  return `polygamma(${values[0]},${values[1]})`;
		  case "IncompleteGamma":
			  return `iGamma(${values[0]},${values[1]})`;
		  case "IncompleteBeta":
			  return `iBeta(${values[1]},${values[2]},${values[0]})`;
		  case "Dilogarithm":
			  return `dilog(${values[0]})`;
		  case "Pochhammer":
			  return `Pochhammer(${values[0]},${values[1]})`;
		  case "BinCoeff":
			  return `binomial(${values[0]},${values[1]})`;
		  case "RiemannZeta":
			  return `zeta(${values[0]})`;
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
