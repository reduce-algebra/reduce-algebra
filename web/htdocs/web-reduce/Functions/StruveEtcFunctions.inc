<modal-dialogue dialogueId="StruveEtcFunctions"
	dialogueTitle="Struve, Lommel, Kummer, Whittaker and Spherical Harmonic Functions" dialogueSize="modal-lg"
	specfnsHeader="specfnsHeader">
	<div class="function-templates two-col">
		<div data-function="StruveH"
			title="Solution of d^2w/dz^2 + 1/z dw/dz + (1 - ν^2/z^2) w = (½z)^{ν-1}/(√π Γ(ν+½))">
			<p><a href="https://dlmf.nist.gov/11.2" target="_blank" title="Opens in a new tab.">Struve
					Function</a></p>
			<span class="fs-big"><b>H</b></span><sub><input type="text" size="2" value="ν" /></sub><span
				class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="StruveL"
			title="Solution of d^2w/dz^2 + 1/z dw/dz - (1 + ν^2/z^2) w = (½z)^{ν-1}/(√π Γ(ν+½))">
			<p><a href="https://dlmf.nist.gov/11.2" target="_blank" title="Opens in a new tab.">Modified Struve
					Function</a></p>
			<span class="fs-big"><b>L</b></span><sub><input type="text" size="2" value="ν" /></sub><span
				class="fs-big">(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Lommel1" title="Related to the solution of d^2w/dz^2 + 1/z dw/dz + (1-ν^2/z^2) w = z^{μ-1}">
			<p><a href="https://dlmf.nist.gov/11.9.i" target="_blank" title="Opens in a new tab.">Lommel
					Function of the First Kind</a></p>
			<span class="fs-big"><i>s</i></span><sub><input type="text" size="2" value="μ" />,<input type="text"
					size="2" value="ν" /></sub><span class="fs-big">(</span><input type="text" size="3"
				value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Lommel2" title="Related to the solution of d^2w/dz^2 + 1/z dw/dz + (1-ν^2/z^2) w = z^{μ-1}">
			<p><a href="https://dlmf.nist.gov/11.9.i" target="_blank" title="Opens in a new tab.">Lommel
					Function of the Second Kind</a></p>
			<span class="fs-big"><i>S</i></span><sub><input type="text" size="2" value="μ" />,<input type="text"
					size="2" value="ν" /></sub><span class="fs-big">(</span><input type="text" size="3"
				value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="KummerM" title="Solution of z d^2w/dz^2 + (b - z) dw/dz - a w = 0">
			<p><a href="https://dlmf.nist.gov/13.2" target="_blank" title="Opens in a new tab.">Kummer M
					Function</a></p>
			<span class="fs-big"><i>M</i>(</span><input type="text" size="2" value="a" />,<input type="text" size="2"
				value="b" />,<input type="text" size="2" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="KummerU" title="Solution of z d^2w/dz^2 + (b - z) dw/dz - a w = 0">
			<p><a href="https://dlmf.nist.gov/13.2" target="_blank" title="Opens in a new tab.">Kummer U
					Function</a></p>
			<span class="fs-big"><i>U</i>(</span><input type="text" size="2" value="a" />,<input type="text" size="2"
				value="b" />,<input type="text" size="2" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="WhittakerM" title="Solution of d^2W/dz^2 + (-¼ + κ/z + (¼-μ^2)/z^2) W = 0">
			<p><a href="https://dlmf.nist.gov/13.14" target="_blank" title="Opens in a new tab.">Whittaker M
					Function</a></p>
			<span class="fs-big"><i>M</i></span><sub><input type="text" size="2" value="κ" />,<input type="text"
					size="2" value="μ" /></sub><span class="fs-big">(</span><input type="text" size="2"
				value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="WhittakerW" title="Solution of d^2W/dz^2 + (-¼ + κ/z + (¼-μ^2)/z^2) W = 0">
			<p><a href="https://dlmf.nist.gov/13.14" target="_blank" title="Opens in a new tab.">Whittaker W
					Function</a></p>
			<span class="fs-big"><i>W</i></span><sub><input type="text" size="2" value="κ" />,<input type="text"
					size="2" value="μ" /></sub><span class="fs-big">(</span><input type="text" size="2"
				value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="SphericalHarmonicY"
			title="Solution of angular component of Laplace's PDE in 3D; Y_{n,m}(θ,ϕ) in notation of DLMF">
			<p><a href="https://dlmf.nist.gov/14.30" target="_blank" title="Opens in a new tab.">Spherical
					Harmonic Function</a></p>
			<span class="fs-big"><i>Y</i></span>
			<span style="display: inline-block; font-size: small; vertical-align: -50%;">
				<input type="text" size="2" value="m" title="Must be, or evaluate to, an integer." /><br />
				<input type="text" size="2" value="n" title="Must be, or evaluate to, an integer." />
			</span><span class="fs-big">(</span><input type="text" size="3" value="θ" />,<input type="text" size="3"
				value="φ" /><span class="fs-big">)</span>
		</div>
		<div data-function="SolidHarmonicY" title="Homogeneous polynomial solution of Laplace's PDE in 3D">
			<p>Solid Harmonic Function</p>
			<span class="fs-big"><i>Y</i></span>
			<span style="display: inline-block; font-size: small; vertical-align: -50%;">
				<input type="text" size="2" value="m" title="Must be, or evaluate to, an integer." /><br />
				<input type="text" size="2" value="n" title="Must be, or evaluate to, an integer." />
			</span><span class="fs-big">(</span><input type="text" size="3" value="x" />,<input type="text" size="3"
				value="y" />,<input type="text" size="3" value="z" />,<input type="text" size="3" value="r²" /><span
				class="fs-big">)</span>
		</div>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Functions } from "./GenJS/TempFuncs.js";

	// Imported functions:
	import { loadPackage } from "./GenJS/Main.js";

	class StruveEtcFunctions extends Functions {
		constructor() {
			super("StruveEtcFunctions");
			this.dialogue.querySelectorAll("div.function-templates>div[data-function$='HarmonicY']")
				.forEach(element => element.addEventListener("click", () => loadPackage("specfn")));
		}
	}

	window.addEventListener("load", () => new StruveEtcFunctions());
</script>
