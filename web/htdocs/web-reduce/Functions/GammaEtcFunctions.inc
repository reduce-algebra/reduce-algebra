<modal-dialogue dialogueId="GammaEtcFunctions" dialogueTitle="Gamma, Beta and Related Functions" dialogueSize="modal-lg"
	specfnsHeader="specfnsHeader">
	<div class="function-templates two-col">
		<div data-function="Gamma" title="Γ(z) = (z-1)!">
			<p><a href="https://dlmf.nist.gov/5.2.E1" target="_blank" title="Opens in a new tab.">Gamma
					Function</a></p>
			<span class="fs-big">Γ(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="Beta" title="B(a,b) = Γ(a)Γ(b)/Γ(a+b)">
			<p><a href="https://dlmf.nist.gov/5.12" target="_blank" title="Opens in a new tab.">Beta
					Function</a></p>
			<span class="fs-big">Β(</span><input type="text" size="3" value="a" />
			<span class="fs-big">,</span>
			<input type="text" size="3" value="b" /><span class="fs-big">)</span>
		</div>
		<div data-function="psi" title="ψ(z) = Γ′(z)/Γ(z)">
			<p><a href="https://dlmf.nist.gov/5.2.E2" target="_blank" title="Opens in a new tab.">Digamma
					Function</a></p>
			<span class="fs-big">ψ(</span><input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="polygamma" title="ψ^(n)(z) = d^nψ(z)/dz^n">
			<p><a href="https://dlmf.nist.gov/5.15" target="_blank" title="Opens in a new tab.">Polygamma
					Function</a></p>
			<span class="fs-big">ψ<sup>(<span class="fs-normal"><input type="text" size="2"
							value="n" /></span>)</sup>(</span><input type="text" size="3" value="z" /><span
				class="fs-big">)</span>
		</div>
		<div data-function="iGamma" title="P(a,z) = 1/Γ(a) ∫_0^z t^{a-1} e^{-t} dt">
			<p><a href="https://dlmf.nist.gov/8.2.i" target="_blank" title="Opens in a new tab.">Normalized
					Incomplete Gamma</a></p>
			<span class="fs-big"><i>P</i>(</span><input type="text" size="3" value="a" />
			<span class="fs-big">,</span>
			<input type="text" size="3" value="z" /><span class="fs-big">)</span>
		</div>
		<div data-function="iBeta" title="I_x(a,b) = 1/B(a,b) ∫_0^x t^{a-1} (1-t)^{b-1} dt">
			<p><a href="https://dlmf.nist.gov/8.17.i" target="_blank" title="Opens in a new tab.">Normalized
					Incomplete Beta</a></p>
			<span class="fs-big"><i>I</i></span><sub><input type="text" size="2" value="x" /></sub><span
				class="fs-big">(</span><input type="text" size="3" value="a" />
			<span class="fs-big">,</span>
			<input type="text" size="3" value="b" /><span class="fs-big">)</span>
		</div>
		<div data-function="dilog" title="Li_2(z) ≡ ∑_{n=1}^∞ z^n/n^2">
			<p><a href="https://dlmf.nist.gov/25.12.i" target="_blank" title="Opens in a new tab.">Dilogarithm</a></p>
			<span class="fs-big">Li<sub>2</sub>(</span><input type="text" size="3" value="z" /><span
				class="fs-big">)</span>
		</div>
		<div data-function="Pochhammer" title="(a)_n = Γ(a+n)/Γ(a)">
			<p><a href="https://dlmf.nist.gov/5.2.iii" target="_blank" title="Opens in a new tab.">Pochhammer&quot;s
					Symbol</a></p>
			<span class="fs-big">(</span><input type="text" size="3" value="a" /><span
				class="fs-big">)</span><sub><input type="text" size="2" value="n" /></sub>
		</div>
		<div data-function="binomial" title="(n over m) = n!/((n-m)!m!)">
			<p><a href="https://dlmf.nist.gov/26.3.E1" target="_blank" title="Opens in a new tab.">Binomial
					Coefficient</a></p>
			<span style="font-size: 400%; line-height: 0.8">(</span>
			<span style="display: inline-block">
				<input type="text" size="3" value="n" /><br />
				<input type="text" size="3" value="m" />
			</span>
			<span style="font-size: 400%; line-height: 0.8">)</span>
		</div>
		<div data-function="zeta" title="ζ(s) = ∑_{n=1}^∞ 1/n^s">
			<p><a href="https://dlmf.nist.gov/25.2.E1" target="_blank" title="Opens in a new tab.">Riemann
					Zeta Function</a></p>
			<span class="fs-big">ζ(</span><input type="text" size="3" value="s" /><span class="fs-big">)</span>
		</div>
	</div>
</modal-dialogue>

<script type="module">
	import { Functions } from "./GenJS/TempFuncs.js";

	class GammaEtcFunctions extends Functions {
		constructor() {
			super("GammaEtcFunctions");
		}

		result() {
			const values = [...this.selectedFunction.getElementsByTagName("input")]
				.map(el => el.value.trim());
			const fn = this.selectedFunction.dataset.function;
			if (fn === "iBeta") return `iBeta(${values[1]},${values[2]},${values[0]})`;
			return `${fn}(${values.join()})`;
		}
	}

	window.addEventListener("load", () => new GammaEtcFunctions());
</script>
