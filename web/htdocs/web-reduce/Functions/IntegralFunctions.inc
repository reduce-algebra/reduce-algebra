<modal-dialogue dialogueId="IntegralFunctions" dialogueTitle="Integral Functions" dialogueSize="modal-lg"
	specfnsHeader="specfnsHeader">
	<div class="function-templates two-col">
		<div data-function="Ei" title="Ei(x) = ⨍_{-∞}^x e^t/t dt">
			<p><a href="https://dlmf.nist.gov/6.2.E5" target="_blank" title="Opens in a new tab.">Exponential
					Integral</a></p>
			<span class="fs-big">Ei(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
		</div>
		<div data-function="li" title="li(x) = ⨍_0^x 1/ln(t) dt = Ei(ln x)">
			<p><a href="https://dlmf.nist.gov/6.2.E8" target="_blank" title="Opens in a new tab.">Logarithmic
					Integral</a></p>
			<span class="fs-big">li(</span><input type="text" size="3" value="x" /><span class="fs-big">)</span>
		</div>
		<div data-function="Si" title="Si(z) = ∫_0^z sin(t)/t dt">
			<p><a href="https://dlmf.nist.gov/6.2.E9" target="_blank" title="Opens in a new tab.">Sine
					Integral</a></p>
			<span class="fs-big">Si(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Ci" title="Ci(z) = -∫_z^∞ cos(t)/t dt">
			<p><a href="https://dlmf.nist.gov/6.2.E11" target="_blank" title="Opens in a new tab.">Cosine
					Integral</a></p>
			<span class="fs-big">Ci(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Shi" title="Shi(z) = ∫_0^z sinh(t)/t dt">
			<p><a href="https://dlmf.nist.gov/6.2.E15" target="_blank" title="Opens in a new tab.">Hyperbolic
					Sine Integral</a></p>
			<span class="fs-big">Shi(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Chi" title="Chi(z) = γ + ln z + ∫_0^z (cosh t - 1)/t dt">
			<p><a href="https://dlmf.nist.gov/6.2.E16" target="_blank" title="Opens in a new tab.">Hyperbolic
					Cosine Integral</a></p>
			<span class="fs-big">Chi(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="erf" title="erf z = 2/√π ∫_0^z e^{-t^2} dt">
			<p><a href="https://dlmf.nist.gov/7.2.E1" target="_blank" title="Opens in a new tab.">Error
					Function</a></p>
			<span class="fs-big">erf</span><input type="text" size="3" value="z" />
		</div>
		<div data-function="erfc" title="erfc z = 2/√π ∫_z^∞ e^{-t^2} dt = 1 - erf z">
			<p><a href="https://dlmf.nist.gov/7.2.E2" target="_blank" title="Opens in a new tab.">Complementary
					Error Function</a></p>
			<span class="fs-big">erfc</span><input type="text" size="3" value="z" />
		</div>
		<div data-function="Fresnel_S" title="S(z) = ∫_0^z sin(½πt^2) dt">
			<p><a href="https://dlmf.nist.gov/7.2.E8" target="_blank" title="Opens in a new tab.">Fresnel
					Sine Integral</a></p>
			<span class="fs-big">S(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Fresnel_C" title="C(z) = ∫_0^z cos(½πt^2) dt">
			<p><a href="https://dlmf.nist.gov/7.2.E7" target="_blank" title="Opens in a new tab.">Fresnel
					Cosine Integral</a></p>
			<span class="fs-big">C(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
	</div>
</modal-dialogue>

<script type="module">
	import { Functions } from "./GenJS/TempFuncs.js";

	class IntegralFunctions extends Functions {
		constructor() {
			super("IntegralFunctions");
		}
	}

	window.addEventListener("load", () => new IntegralFunctions());
</script>
