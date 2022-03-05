// Imported functions:
import { mobileVersion, refocus, sendToReduceAndEcho } from "./Main.js";

// This is based on the output from executing: lisp loadable!-packages!*;
const loadable_packages = mobileVersion ?
	`(algint avector defint ezgcd factor ineq int limits linalg matrix odesolve
polydiv sets sfgamma solve specbess specfaux specfn specfn2 sum
tps trigd)` :
	`(acfsf algint applysym arnum assert assist atensor avector bibasis boolean
breduce cali camal cantens cde cdiff cedit cgb changevr cl clprl coeff2 compact
conlaw crack cuba cvit dcfsf defint desir dfpart dipoly dummy dvfsf eds ellipfn
excalc ezgcd factor fide fide1 fmprint fps gcref gentran geoprover gnuplot
groebner groebnr2 guardian gurobi hephys ibalp ideals ineq int invbase lalr
laplace libreduce lie liepde limits linalg listvecops lpdo mathml mathmlom
matrix misc modsr mri mri_ofsf mri_pasf mrvlimit ncpoly nlopt noncom2 normform
numeric odesolve ofsf orthovec pasf pf pgauss physop pident plot pm polydiv
pretty profile qhull qqe qqe_ofsf qsum randpoly ranum rataprx ratint rcref
reacteqn redfront redlog reduce4 reset residue rlfi rlisp88 rlsupport
rltools roots roots2 rprint rsolve rtrace rubi_red scope sets sfgamma smt
solve sparse spde specbess specfaux specfn specfn2 sstools sum susy2 symaux
symmetry tables talp taylor tps tri trigd trigint trigsimp turtle utf8 v3tools
wu xcolor xideal z3 zeilberg ztrans)`;
const packages = loadable_packages.slice(1, -1).split(/\s+/);
const loadPackagesDialogue = document.getElementById("LoadPackagesDialogue");
const pkgButtonGrid = loadPackagesDialogue.querySelector("div.modal-body > div");
const pkgButtons = [];
let pkgNo = 1;
for (const pkg of packages) {
	const pkgId = "LoadPackageButton" + pkgNo++;
	const button = document.createElement("input");
	button.setAttribute("type", "checkbox");
	button.setAttribute("id", pkgId);
	button.setAttribute("autocomplete", "off");
	button.className = "btn-check";
	pkgButtonGrid.appendChild(button);
	pkgButtons.push(button);
	const label = document.createElement("label");
	label.className = "btn btn-outline-primary";
	label.setAttribute("for", pkgId);
	label.innerText = pkg;
	pkgButtonGrid.appendChild(label);
	label.addEventListener("click", enableManualButton);
	label.addEventListener("dblclick", loadThisPackage);
	label.addEventListener("contextmenu", showManualForThisPackage);
}

const buttons = loadPackagesDialogue.querySelectorAll<HTMLButtonElement>("div.modal-footer > button");
buttons[0].addEventListener("click", () => pkgButtons.forEach(btn => btn.checked = false));
buttons[1].disabled = true;
buttons[2].addEventListener("click", loadButtonAction);

/**
 * Load the selected package(s).
 * Run when the "Load" button is clicked.
 */
function loadButtonAction() {
	// Build an array of selected package names:
	const selectedPackages = pkgButtons.filter(btn => btn.checked)
		.map(btn => pkgButtonGrid.querySelector<HTMLLabelElement>(`label[for='${btn.id}']`).innerText);
	if (selectedPackages.length !== 0)
		sendToReduceAndEcho(`load_package ${selectedPackages.join(", ")};`);
	// Close dialogue:
	buttons[3].click();
	refocus(); // return focus to input editor on desktop, I/O Display on mobile
}

/**
 * Load the mouse-clicked package.
 * Run when a package label is double-clicked.
 */
function loadThisPackage(event: MouseEvent) {
	const label = event.target as HTMLLabelElement;
	sendToReduceAndEcho(`load_package ${label.innerText};`);
	// Close dialogue:
	buttons[3].click();
	refocus(); // return focus to input editor on desktop, I/O Display on mobile
}

/**
 * Enable "Display Manual Entry" button when precisely one package is selected.
 * Run when a package is clicked.
 */
function enableManualButton() {
	// Normal click action must happen first!
	setTimeout(() => { buttons[1].disabled = (pkgButtons.filter(btn => btn.checked).length !== 1) });
}

buttons[1].addEventListener("click", showManualForSelectedPackage);

/**
 * Show the manual entry for the (first) selected package.
 * Run when the "Display Manual Entry" button is clicked.
 */
function showManualForSelectedPackage() {
	let button = pkgButtons.find(btn => btn.checked);
	if (button)
		showManualForLabel(pkgButtonGrid.querySelector<HTMLLabelElement>(`label[for='${button.id}']`));
}

/**
 * Show the manual entry for the mouse-clicked package.
 * Run when a package label is secondary-clicked.
 * @param {MouseEvent} event - click on package label.
 */
function showManualForThisPackage(event: MouseEvent) {
	event.preventDefault();
	showManualForLabel(event.target as HTMLLabelElement);
}

const manualLookupMap = new Map();
const redlogSubPackages = ["acfsf", "cl", "clprl", "dcfsf", "dvfsf", "ibalp", "mri", "mri_ofsf", "mri_pasf",
	"ofsf", "pasf", "pgauss", "pident", "qqe", "qqe_ofsf", "rlsupport", "rltools", "smt", "talp"];
for (const pkg of redlogSubPackages) manualLookupMap.set(pkg, "REDLOG");
manualLookupMap.set("algint", "INT Operator")
	.set("cedit", "Commands for Interactive Use")
	.set("changevr", "CHANGEVAR Operator")
	.set("conlaw", "CRACK:")
	.set("cvit", "CVIT:")
	.set("ezgcd", "Cancellation of Common Factors")
	.set("factor", "Factorization of Polynomials")
	.set("hephys", "High Energy Physics Operators")
	.set("ineq", "Support for Solving Inequalities")
	.set("int", "INT Operator")
	.set("liepde", "CRACK:")
	.set("limits", "LIMIT Operator")
	.set("matrix", "Matrix Calculations")
	.set("modsr", "Modular Solve and Roots")
	.set("noncom2", "PHYSOP:")
	.set("numeric", "Solving Numerical Problems")
	.set("pf", "PF Operator")
	.set("plot", "GNUPLOT:")
	.set("polydiv", "Euclidean Division")
	.set("pretty", "Prettyprinting Standard Lisp S-Expressions")
	.set("rlisp88", "Rlisp")
	.set("roots", "Finding Roots")
	.set("rprint", "Prettyprinting REDUCE Expressions")
	.set("rsolve", "Finding Rational or Integer Zeros")
	.set("rtrace", "Tracing in REDUCE")
	.set("solve", "SOLVE Operator")
	.set("sfgamma", "SPECFN:")
	.set("specbess", "SPECFN:")
	.set("specfaux", "SPECFN:")
	.set("specfn", "SPECFN:")
	.set("sum", "SUM: A Package for Series Summation")
	.set("taylor", "Taylor Expansion")
	.set("tri", "TRI:")
	.set("turtle", "Turtle Graphics")
	.set("v3tools", "CRACK:");

/**
 * Show the manual entry for the specified package label.
 * @param {HTMLLabelElement} label - package label.
 */
function showManualForLabel(label: HTMLLabelElement) {
	let pkg = label.innerText, lookup: string = manualLookupMap.get(pkg);
	if (lookup) pkg = lookup;
	else pkg = pkg.toUpperCase();
	const url = `/manual-lookup.php?${pkg}`;
	window.open(url);
}
