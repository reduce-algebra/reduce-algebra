<modal-dialogue dialogueId="AiryBesselFunctions" dialogueTitle="Airy, Bessel and Related Functions"
	dialogueSize="modal-lg" specfnsHeader="specfnsHeader">
	<table class="function-templates">
		<tbody>
			<tr>
				<td data-function="Airy_Ai" title="Solution of d^2w/dz^2 = z w">
					<p><a href="https://dlmf.nist.gov/9.2" target="_blank" title="Opens in a new tab.">Airy Function of
							the First Kind</a></p>
					<span class="fs-big">Ai(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
				<td data-function="Airy_Bi" title="Solution of d^2w/dz^2 = z w">
					<p><a href="https://dlmf.nist.gov/9.2" target="_blank" title="Opens in a new tab.">Airy Function of
							the Second Kind</a></p>
					<span class="fs-big">Bi(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="Airy_AiPrime" title="dAi(z)/dz">
					<p><a href="https://dlmf.nist.gov/9.2" target="_blank" title="Opens in a new tab.">Derivative of
							Airy Function of the First Kind</a></p>
					<span class="fs-big">Ai'(</span><input type="text" size="3" value="z" /><span
						class="fs-big">)</span>
				</td>
				<td data-function="Airy_BiPrime" title="dBi(z)/dz">
					<p><a href="https://dlmf.nist.gov/9.2" target="_blank" title="Opens in a new tab.">Derivative of
							Airy Function of the Second Kind</a></p>
					<span class="fs-big">Bi'(</span><input type="text" size="3" value="z" /><span
						class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="BesselJ" title="Solution of z^2 d^2w/dz^2 + z dw/dz + (z^2 - ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.2" target="_blank" title="Opens in a new tab.">Bessel Function
							of the First Kind</a></p>
					<span class="fs-big"><i>J</i></span><sub><input type="text" size="2" value="ν" /></sub>
					<span class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
				<td data-function="BesselY" title="Solution of z^2 d^2w/dz^2 + z dw/dz + (z^2 - ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.2" target="_blank" title="Opens in a new tab.">Bessel Function
							of the Second Kind</a></p>
					<span class="fs-big"><i>Y</i></span><sub><input type="text" size="2" value="ν" /></sub>
					<span class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="BesselI" title="Solution of z^2 d^2w/dz^2 + z dw/dz - (z^2 + ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.25" target="_blank" title="Opens in a new tab.">Modified Bessel
							Function
							of the First Kind</a></p>
					<span class="fs-big"><i>I</i></span><sub><input type="text" size="2" value="ν" /></sub>
					<span class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
				<td data-function="BesselK" title="Solution of z^2 d^2w/dz^2 + z dw/dz - (z^2 + ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.25" target="_blank" title="Opens in a new tab.">Modified Bessel
							Function
							of the Second Kind</a></p>
					<span class="fs-big"><i>K</i></span><sub><input type="text" size="2" value="ν" /></sub>
					<span class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
			</tr>
			<tr>
				<td data-function="Hankel1" title="Solution of z^2 d^2w/dz^2 + z dw/dz + (z^2 - ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.2" target="_blank" title="Opens in a new tab.">Hankel Function
							of the First Kind</a></p>
					<span class="fs-big"><i>H</i></span><span style="display: inline-block; vertical-align: -50%;">
						<span style="font-size: small">(1)</span><br />
						<input type="text" size="2" value="ν" style="font-size: small" /></span><span
						class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
				<td data-function="Hankel2" title="Solution of z^2 d^2w/dz^2 + z dw/dz + (z^2 - ν^2) w = 0">
					<p><a href="https://dlmf.nist.gov/10.2" target="_blank" title="Opens in a new tab.">Hankel Function
							of the Second Kind</a></p>
					<span class="fs-big"><i>H</i></span><span style="display: inline-block; vertical-align: -50%;">
						<span style="font-size: small">(2)</span><br />
						<input type="text" size="2" value="ν" style="font-size: small" /></span><span
						class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
				</td>
			</tr>
		</tbody>
	</table>
</modal-dialogue>

<script type="module">
	import { Functions } from "./TempFuncs.mjs";

	class AiryBesselFunctions extends Functions {
		constructor() {
			super("AiryBesselFunctions");
		}
	}

	window.addEventListener("load", () => new AiryBesselFunctions());
</script>
