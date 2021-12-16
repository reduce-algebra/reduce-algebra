<modal-dialogue dialogueId="OrthoPolyFunctions" dialogueTitle="Classical Orthogonal Polynomials" dialogueSize="modal-lg"
	specfnsHeader="specfnsHeader">
	<table class="function-templates">
		<tbody>
			<tr>
				<td data-function="JacobiP" title="Orthogonal on (-1,1) with weight function (1-x)^α (1+x)^β">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r2" target="_blank" title="Opens in a new tab.">Jacobi
							Polynomials</a></p>
					<span class="fs-big"><i>P</i></span><span style="display: inline-block; vertical-align: -50%;">
						(<input type="text" size="2" value="α" style="font-size: small" />,<input type="text" size="2"
							value="β" style="font-size: small" />)<br />
						<input type="text" size="2" value="n" style="font-size: small" />
					</span><span class="fs-big">(</span><input type="text" size="3" value="x" /><span
						class="fs-big">)</span>
				</td>
				<td data-function="GegenbauerP" title="Orthogonal on (-1,1) with weight function (1-x^2)^{λ-½}">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r3" target="_blank"
							title="Opens in a new tab.">Ultraspherical (Gegenbauer) Polynomials</a></p>
					<span class="fs-big"><i>C</i></span><span style="display: inline-block; vertical-align: -50%;">
						(<input type="text" size="2" value="λ" style="font-size: small" />)<br />
						<input type="text" size="2" value="n" style="font-size: small" />
					</span><span class="fs-big">(</span><input type="text" size="3" value="x" /><span
						class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="ChebyshevT" title="Orthogonal on (-1,1) with weight function (1-x^2)^{-½}">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r4" target="_blank"
							title="Opens in a new tab.">Chebyshev Polynomials of the First Kind</a></p>
					<span class="fs-big"><i>T</i></span><sub><input type="text" size="2" value="n" /></sub><span
						class="fs-big">(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
				</td>
				<td data-function="ChebyshevU" title="Orthogonal on (-1,1) with weight function (1-x^2)^½">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r5" target="_blank"
							title="Opens in a new tab.">Chebyshev Polynomials of the Second Kind</a></p>
					<span class="fs-big"><i>U</i></span><sub><input type="text" size="2" value="n" /></sub><span
						class="fs-big">(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="LegendreP" title="Orthogonal on (-1,1) with weight function 1">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r10" target="_blank"
							title="Opens in a new tab.">Legendre Polynomials</a></p>
					<span class="fs-big"><i>P</i></span><sub><input type="text" size="2" value="n" /></sub><span
						class="fs-big">(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
				</td>
				<td data-function="AssocLegendreP" title="P_n^m(x) = (-1)^m (1-x^2)^{m/2} d^m/dx^m P_n(x)">
					<p><a href="https://dlmf.nist.gov/14.7.E8" target="_blank" title="Opens in a new tab.">Associated
							Legendre Polynomials</a></p>
					<span class="fs-big"><i>P</i></span><span style="display: inline-block; vertical-align: -50%;">
						(<input type="text" size="2" value="m" style="font-size: small" />)<br />
						<input type="text" size="2" value="n" style="font-size: small" />
					</span><span class="fs-big">(</span><input type="text" size="3" value="x" /><span
						class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="LaguerreP" title="Orthogonal on (0,∞) with weight function e^{-x}">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r12" target="_blank"
							title="Opens in a new tab.">Laguerre Polynomials</a></p>
					<span class="fs-big"><i>L</i></span><sub><input type="text" size="2" value="n" /></sub><span
						class="fs-big">(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
				</td>
				<td data-function="GenLaguerreP" title="Orthogonal on (0,∞) with weight function e^{-x} x^α">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r12" target="_blank"
							title="Opens in a new tab.">Generalized
							Laguerre Polynomials</a></p>
					<span class="fs-big"><i>L</i></span><span style="display: inline-block; vertical-align: -50%;">
						(<input type="text" size="2" value="α" style="font-size: small" />)<br />
						<input type="text" size="2" value="n" style="font-size: small" />
					</span><span class="fs-big">(</span><input type="text" size="3" value="x" /><span
						class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="HermiteP" title="Orthogonal on (-∞,∞) with weight function e^{-x^2}">
					<p><a href="https://dlmf.nist.gov/18.3#T1.t1.r13" target="_blank"
							title="Opens in a new tab.">Hermite Polynomials</a></p>
					<span class="fs-big"><i>H</i></span><sub><input type="text" size="2" value="n" /></sub><span
						class="fs-big">(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
				</td>
			</tr>
		</tbody>
	</table>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Functions } from "./TempFuncs.mjs";

	// Imported functions:
	import { loadPackage } from "./Main.mjs";

	class OrthoPolyFunctions extends Functions {
		constructor() {
			super("OrthoPolyFunctions");
			this.dialogue.addEventListener("show.bs.modal", () => loadPackage("specfn"));
		}

		result() {
			const values = [...this.selectedFunction.getElementsByTagName("input")]
				.map(el => el.value.trim());
			const fn = this.selectedFunction.dataset.function;
			switch (fn) {
				case "JacobiP":
					return `JacobiP(${values[2]},${values[0]},${values[1]},${values[3]})`;
				case "GegenbauerP":
					return `GegenbauerP(${values[1]},${values[0]},${values[2]})`;
				case "AssocLegendreP":
					return `LegendreP(${values[1]},${values[0]},${values[2]})`;
				case "GenLaguerreP":
					return `LaguerreP(${values[1]},${values[0]},${values[2]})`;
				default:
					return `${fn}(${values.join()})`;
			}
		}
	}

	window.addEventListener("load", () => new OrthoPolyFunctions());
</script>
