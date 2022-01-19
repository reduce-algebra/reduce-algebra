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
	<div class="pattern">
		<span style="font-size: 10em; line-height: 60%; vertical-align: -0.48em;">(</span>
		<table style="display: inline-table;">
			<tbody>
				<tr>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
				</tr>
				<tr>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
				</tr>
				<tr>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
				</tr>
				<tr>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
					<td><input type="text" style="width: 5em" /></td>
				</tr>
			</tbody>
		</table>
		<span style="font-size: 10em; line-height: 60%; vertical-align: -0.48em;">)</span>
	</div>
</modal-dialogue>

<script type="module">
	// Imported classes:
	import { Template } from "./TempFuncs.mjs";

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
