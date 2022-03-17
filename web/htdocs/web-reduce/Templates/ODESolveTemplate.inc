<modal-dialogue dialogueId="ODESolveTemplate" dialogueTitle="Solve an Ordinary Differential Equation">
	<p>
		<small>
			The ordinary differential equation (ODE) can be an expression that is implicitly equated to zero. All other
			entries are optional; REDUCE can normally deduce the dependent variable or function, and the independent
			variable. Derivatives can be specified using primes (single forward quotes) provided the independent
			variable is specified.
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?ODESOLVE:" target="_blank" title="Opens in a new tab.">ODESOLVE:
				Ordinary differential equation solver</a></small>
	</p>
	<div class="pattern">
		<p title="Required ordinary differential equation or expression" style="display: flex;">
			<b>ODE:</b>&nbsp;<input type="text" placeholder="ordinary differential equation" style="flex: 1 0;" />
		</p>
		<p style="display: flex; justify-content: space-evenly;">
			<span title="Optional dependent variable or function (kernel)"><b>Dep Var:</b>&nbsp;
				<input type="text" placeholder="kernel" style="width: 5em;" /></span>
			<span title="Optional independent variable (kernel)"><b>Ind Var:</b>&nbsp;
				<input type="text" placeholder="kernel" style="width: 5em;" /></span>
		</p>
		<p title="Optional conditions as equations or lists of equations" style="display: flex;">
			<b>Conds:</b>&nbsp;<input type="text" placeholder="eqn, eqn, ... or {eqns}, {eqns}, ..."
				style="flex: 1 0;" />
		</p>
		<div style="display: grid; justify-content: center; align-items: center; justify-items: left;
			grid-template-columns: repeat(auto-fill, 6em); grid-column-gap: 0.5em;">
			<span title="fully explicit"><input id="ODESolveTemplate1" type="checkbox" />
				<label for="ODESolveTemplate1">explicit</label></span>
			<span title="expand roots of unity"><input id="ODESolveTemplate2" type="checkbox" />
				<label for="ODESolveTemplate2">expand</label></span>
			<span title="fully explicit and expanded"><input id="ODESolveTemplate3" type="checkbox" />
				<label for="ODESolveTemplate3">full</label></span>
			<span title="implicit instead of parametric"><input id="ODESolveTemplate4" type="checkbox" />
				<label for="ODESolveTemplate4">implicit</label></span>
			<span title="turn on algint locally"><input id="ODESolveTemplate5" type="checkbox" />
				<label for="ODESolveTemplate5">algint</label></span>
			<span title="turn off selected integrations"><input id="ODESolveTemplate6" type="checkbox" />
				<label for="ODESolveTemplate6">noint</label></span>
			<span title="display ODE and conditions"><input id="ODESolveTemplate7" type="checkbox" />
				<label for="ODESolveTemplate7">verbose</label></span>
			<span title="output basis solution for linear ODE"><input id="ODESolveTemplate8" type="checkbox" />
				<label for="ODESolveTemplate8">basis</label></span>
			<span title="turn on algorithm tracing"><input id="ODESolveTemplate9" type="checkbox" />
				<label for="ODESolveTemplate9">tracing</label></span>
			<span title="turn on increased algorithm tracing"><input id="ODESolveTemplate10" type="checkbox" />
				<label for="ODESolveTemplate10">tracing+</label></span>
			<span title="turn off heuristics"><input id="ODESolveTemplate11" type="checkbox" />
				<label for="ODESolveTemplate11">fast</label></span>
			<span title="turn on solution checking"><input id="ODESolveTemplate12" type="checkbox" />
				<label for="ODESolveTemplate12">check</label></span>
		</div>
	</div>
</modal-dialogue>
