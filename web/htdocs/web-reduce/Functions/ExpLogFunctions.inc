<modal-dialogue dialogueId="ExpLogFunctions" dialogueTitle="Exponentials, Logarithms, Powers, Roots, etc."
	dialogueSize="modal-lg">
	<p class="text-center"><small>Click on the function you want to use. Hover over a function for a brief
			description. Some functions do not simplify symbolically but evaluate numerically, as indicated
			in their tooltips.</small></p>
	<p class="text-center">
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?Mathematical%20Functions" target="_blank"
				title="Opens in a new tab.">Mathematical Functions</a>&ensp;
			<a href="/manual-lookup.php?SPECFN:" target="_blank" title="Opens in a new tab.">SPECFN
				Package</a>&ensp;
			<a href="/manual-lookup.php?TRIGD:" target="_blank" title="Opens in a new tab.">TRIGD
				Package</a></small>
	</p>
	<div class="function-templates three-col">
		<div data-function="exp" title="Exponential: e^x = exp(x)">
			<span class="fs-big">e</span> <sup><input type="text" size="3" value="ws" /></sup>
		</div>
		<div data-function="log" title="Natural, i.e. base e, logarithm: ln e = 1">
			<span class="fs-big">ln</span> <input type="text" size="3" value="ws" />
		</div>
		<div data-function="logb" title="Logarithm to any base, e.g. 2">
			<span class="fs-big">log</span><sub><input type="text" size="2" value="2"
					style="font-style: normal" /></sub>
			<input type="text" size="3" value="ws" />
		</div>
		<div data-function="power" title="Power, e.g. x^2">
			<input type="text" size="3" value="ws" />
			<sup><input type="text" size="2" value="2" style="font-style: normal" /></sup>
		</div>
		<div data-function="sqrt" title="Square root">
			<span class="fs-big">√</span>
			<input type="text" size="3" value="ws" />
		</div>
		<div data-function="hypot" title="hypot(x,y) = √(x^2+y^2); numerical only!">
			<span class="fs-big">hypot(</span><input type="text" size="3" value="x" />
			<span class="fs-big">,</span>
			<input type="text" size="3" value="y" /><span class="fs-big">)</span>
		</div>
		<div data-function="log10" title="Base 10 logarithm">
			<span class="fs-big">log<sub>10</sub></span>
			<input type="text" size="3" value="ws" />
		</div>
		<div data-function="root" title="Any root, e.g. cube or third root: (n√x)^n = x">
			<sup><input type="text" size="2" value="3" style="font-style: normal" /></sup>
			<span class="fs-big">√</span>
			<input type="text" size="3" value="ws" />
		</div>
		<div data-function="atan2"
			title="Two argument version of atan(y/x) that returns an angle in the interval (-π/2, π/2] in the correct quadrant depending on the signs of x and y">
			<span class="fs-big">atan<sub>2</sub>(</span><input type="text" size="3" value="y" />
			<span class="fs-big">/</span>
			<input type="text" size="3" value="x" /><span class="fs-big">)</span>
		</div>
		<div data-function="factorial" title="Factorial: n! = n×(n-1)×…×2×1">
			<input type="text" size="3" value="ws" />
			<span class="fs-big">!</span>
		</div>
		<div data-function="binomial" title="Binomial coefficient: (n over m) = n!/((n-m)!m!)">
			<span style="font-size: 400%; line-height: 0.8">(</span>
			<span style="display: inline-block">
				<input type="text" size="3" value="n" /><br />
				<input type="text" size="3" value="m" />
			</span>
			<span style="font-size: 400%; line-height: 0.8">)</span>
		</div>
		<!-- This needs better handling of the load_package and a manual link to trigd. -->
		<div data-function="atan2d"
			title="Two argument version of atand(y/x) that returns an angle in the interval (-90°, 90°] in the correct quadrant depending on the signs of x and y">
			<span class="fs-big">atan<sub>2</sub>d(</span><input type="text" size="3" value="y" />
			<span class="fs-big">/</span>
			<input type="text" size="3" value="x" /><span class="fs-big">)</span>
		</div>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Functions } from "./GenJS/TempFuncs.js";

	// Imported functions:
	import { loadPackage } from "./GenJS/Main.js";

	class ExpLogFunctions extends Functions {
		constructor() {
			super("ExpLogFunctions");
			this.dialogue.querySelector("div.function-templates>div:last-child")
				.addEventListener("click", () => loadPackage("trigd"));
		}

		result() {
			const values = [...this.selectedFunction.getElementsByTagName("input")]
				.map(el => el.value.trim());
			const fn = this.selectedFunction.dataset.function;
			switch (fn) {
				case "logb":
					return `logb(${values[1]},${values[0]})`;
				case "power":
					return `(${values[0]})^(${values[1]})`;
				case "root":
					return `(${values[1]})^(1/(${values[0]}))`;
				default:
					return `${fn}(${values.join()})`;
			}
		}
	}

	window.addEventListener("load", () => new ExpLogFunctions());
</script>
