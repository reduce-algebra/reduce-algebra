<modal-dialogue dialogueId="ForTemplate" dialogueTitle="Repetition using a For Statement" dialogueSize="modal-lg">
	<p>
		<small>
			A 'var' entry must be an identifier. For iteration over a numerical range, the 'number' entries must
			*evaluate* to numbers. For iteration over a list, the 'list' entry must *evaluate* to a list; the 'on'
			option is allowed only in symbolic mode and makes the 'for variable' evaluate to successive 'cdr's of the
			list.
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?FOR%20Statements" target="_blank" title="Opens in a new tab.">FOR
				Statements</a></small>
	</p>
	<p>
		Iterate over a
		<span class="btn-group btn-group-sm" role="group" aria-label="Basic radio toggle button group">
			<input type="radio" class="btn-check" name="ForTemplate-EachButtons" id="ForTemplate-ForButton"
				autocomplete="off" checked="checked" />
			<label class="btn btn-outline-primary" for="ForTemplate-ForButton" title="Use a 'for' loop">numeric
				range</label>
			<input type="radio" class="btn-check" name="ForTemplate-EachButtons" id="ForTemplate-EachButton"
				autocomplete="off" />
			<label class="btn btn-outline-primary" for="ForTemplate-EachButton"
				title="Use a 'for each' loop">list</label>
		</span>
	</p>
	<div class="pattern" style="max-width: 40em; margin-left: auto; margin-right: auto;">
		<div style="display: flex;">
			<div class="for" style="min-width: 0; display: flex; justify-content: space-between; flex: auto;">
				for
				<input type="text" placeholder="var" style="min-width: 1em; flex: 0 1 6em"
					title="Must be an identifier" />
				:=
				<input type="text" placeholder="number" style="min-width: 1em; flex: 0 1 6em"
					title="Must evaluate to a number" />
				step
				<input type="text" placeholder="number" style="min-width: 1em; flex: 0 1 6em"
					title="Must evaluate to a number" value="1" />
				until
				<input type="text" placeholder="number" style="min-width: 1em; flex: 0 1 6em"
					title="Must evaluate to a number" />
			</div>
			<div class="for" style="min-width: 0; display: flex; justify-content: space-between; flex: auto;">
				for&nbsp;each
				<input type="text" placeholder="var" style="min-width: 1em; flex: 0 1 6em"
					title="Must be an identifier" />
				<span class="dropdown">
					<button class="btn btn-secondary btn-sm dropdown-toggle" type="button" id="ForTemplate-InButton"
						data-bs-toggle="dropdown" aria-expanded="false">
						in
					</button>
					<ul class="dropdown-menu" aria-labelledby="ForTemplate-InButton">
						<li><button class="dropdown-item" type="button" value="in"
								title="The 'for variable' evaluates to successive elements of the list.">in</button>
						</li>
						<li><button class="dropdown-item" type="button" value="on"
								title="Allowed only in symbolic mode; the 'for variable' evaluates to successive 'cdr's of the list.">on</button>
						</li>
					</ul>
				</span>
				<input type="text" placeholder="list" style="min-width: 3em; flex: 0 1 20em"
					title="Must evaluate to a list" />
			</div>
			&nbsp;
			<div class="dropdown"
				title="The action to perform on the following statement or expression; all but 'do' cause the 'for' to return a value.">
				<button class="btn btn-secondary btn-sm dropdown-toggle" type="button" id="ForTemplate-DoButton"
					data-bs-toggle="dropdown" aria-expanded="false" style="width: 6em;">
					do
				</button>
				<ul class="dropdown-menu" aria-labelledby="ForTemplate-DoButton">
					<li><button class="dropdown-item" type="button" value="do"
							title="Execute the following statement; no value is returned.">do</button></li>
					<li><button class="dropdown-item" type="button" value="sum"
							title="Return the sum of the values of the following expression.">sum</button></li>
					<li><button class="dropdown-item" type="button" value="product"
							title="Return the product of the values of the following expression.">product</button>
					</li>
					<li><button class="dropdown-item" type="button" value="collect"
							title="Return a list of the values of the following expression.">collect</button>
					</li>
					<li><button class="dropdown-item" type="button" value="join"
							title="Join the values of the following expression, which must be lists, into a new list and return it.">join</button>
					</li>
				</ul>
			</div>
		</div>
		<textarea class="mt-1" title="Any expression, which is evaluated on each iteration"
			placeholder="A single statement or expression, which can be a group (<<&hellip;>>) or compound (begin&hellip;end) statement."
			rows="2" style="width: 100%"></textarea>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./GenJS/TempFuncs.js";

	class ForTemplate extends Template {
		constructor() {
			super("For Template");
			const forElements = this.pattern.querySelectorAll("div.for");
			forElements[1].hidden = true;
			document.getElementsByName("ForTemplate-EachButtons").forEach(element =>
				element.addEventListener("change", () =>
					forElements.forEach(el => { el.hidden = !el.hidden })));
			this.inOn = "in";
			this.inButton = document.getElementById("ForTemplate-InButton");
			this.inButton.parentElement.querySelectorAll("ul>li>button").forEach(element =>
				element.addEventListener("click", () => {
					this.inOn = element.value;
					this.inButton.innerText = this.inOn;
				}));
			this.doWhat = "do";
			this.doButton = document.getElementById("ForTemplate-DoButton");
			this.doButton.parentElement.querySelectorAll("ul>li>button").forEach(element =>
				element.addEventListener("click", () => {
					this.doWhat = element.value;
					this.doButton.innerText = this.doWhat;
				}));
			this.forButton = document.getElementById("ForTemplate-ForButton");
			this.textArea = this.pattern.querySelector("textarea");
		}

		resetButtonAction() {
			super.resetButtonAction();
			this.forButton.click();
			this.inButton.innerText = this.inOn = "in";
			this.doButton.innerText = this.doWhat = "do";
			this.textArea.value = "";
		}

		result() {
			let text = "for ";
			if (this.forButton.checked) {
				// Iterate over a numerical range:
				text += this.getValueCheckNonEmpty(this.inputs[0]) // forVar
					+ " := " + this.getValueCheckNonEmpty(this.inputs[1]); // from
				const step = this.inputs[2].value.trim(); // step
				if (!step || step === "1")
					text += " : ";
				else
					text += " step " + step + " until ";
				text += this.getValueCheckNonEmpty(this.inputs[3]); // until
			} else  // Iterate over a list:
				text += "each " + this.getValueCheckNonEmpty(this.inputs[4]) // foreachVar
					+ " " + this.inOn
					+ " " + this.getValueCheckNonEmpty(this.inputs[5]); // foreachList
			return text + " " + this.doWhat
				+ " " + this.getValueCheckNonEmpty(this.textArea); // exprn
		}
	}

	window.addEventListener("load", () => new ForTemplate());
</script>
