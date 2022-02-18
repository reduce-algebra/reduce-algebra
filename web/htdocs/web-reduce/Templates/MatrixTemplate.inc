<modal-dialogue dialogueId="MatrixTemplate" dialogueTitle="Create a Matrix">
	<p>
		<small>
			Form a matrix in the top left-hand corner of the grid, leaving any cells outside this matrix empty. The
			right-most and lowest non-empty cells define the matrix size. Any empty cells within this matrix default to
			zero.
		</small>
	</p>
	<p>
		<small>REDUCE Manual:&ensp;
			<a href="/manual-lookup.php?MAT%20Operator" target="_blank" title="Opens in a new tab.">MAT
				Operator</a></small>
	</p>
	<div class="pattern" style="display: grid; justify-content: center; grid-template-areas:
	'L . . . . R'
	'L . . . . R'
	'L . . . . R'
	'L . . . . R';
	grid-template-columns: min-content repeat(4, minmax(1em,5em)) min-content;
	grid-gap: 2px 2px;">
		<span style="font-size: 10em; line-height: 50%; grid-area: L;">(</span>
		<input type="text" /><input type="text" /><input type="text" /><input type="text" />
		<input type="text" /><input type="text" /><input type="text" /><input type="text" />
		<input type="text" /><input type="text" /><input type="text" /><input type="text" />
		<input type="text" /><input type="text" /><input type="text" /><input type="text" />
		<span style="font-size: 10em; line-height: 50%; grid-area: R;">)</span>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./GenJS/TempFuncs.js";

	// Imported functions:
	import { loadPackage } from "./GenJS/Main.js";

	class MatrixTemplate extends Template {
		constructor() {
			super("Matrix Template");
			this.dialogue.addEventListener("show.bs.modal", () => loadPackage("matrix"));
		}

		result() {
			const maxRows = 4, maxCols = 4, rows = [];
			// Determine the matrix dimensions (nRows * nCols) and convert empty values to "0":
			let nColsI, nCols = 0, nRows = 0;
			for (let i = 0; i < maxRows; i++) {
				const row = [];
				nColsI = 0;
				for (let j = 0; j < maxCols; j++) {
					const value = this.inputs[i * maxCols + j].value;
					if (value) {
						row.push(value);
						nColsI = j + 1;
					} else row.push("0");
				}
				if (nColsI > nCols) nCols = nColsI;
				if (nColsI > 0) nRows = i + 1;
				rows.push(row);
			}
			// Construct and return the REDUCE input:
			let text = "mat((";
			for (let i = 0; i < nRows; i++) {
				if (i > 0) text += "), (";
				const row = rows[i];
				for (let j = 0; j < nCols; j++) {
					if (j > 0) text += ", ";
					text += row[j];
				}
			}
			return text + "))";
		}
	}

	window.addEventListener("load", () => new MatrixTemplate());
</script>
