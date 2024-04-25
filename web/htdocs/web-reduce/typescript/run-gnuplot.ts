// *** Main Web Gnuplot page logic ***
// Cannot easily make this into a module!

// gnuplot.init = function () { };

// Defined in "gnuplot.js":
declare function callMain(args: string[]): void;
var HEAPU8: Uint8Array;

// WebAssembly module config
var STDOUT: string[] = [],
  SCRIPT_FILE = "script.gnuplot";

var Module: { [index: string]: any } = {};
// Don't run main on page load
Module["noInitialRun"] = true;
// Print functions: each call handles one text line.
// stdout is used for output such as the version.
// stderr is used for reporting input errors.
Module["print"] = (stdout: string) => STDOUT.push(stdout);
Module["printErr"] = (stderr: string) => STDOUT.push(stderr);
// When the module is ready
Module["onRuntimeInitialized"] = function () {
  document.getElementById("gnuplot-version")!.innerText =
    "Powered by " + run_gnuplot("", "--version");
};
Module["preRun"] = [function () {
  function stdin() {
    return null; // if gnuplot asks for input, say NO
  }
  FS.init(stdin, null, null);
}];

// Utility function to run gnuplot
function run_gnuplot(script: string, options: string | string[]) {
  // Create file from object
  // See http://gnuplot.info/docs_6.0/loc19528.html.
  script =
    "set term canvas name 'draw_plot_on_canvas';set output 'plot.js'\n" +
    script;
  FS.writeFile(SCRIPT_FILE, script);

  // Clear previous stdout/stderr before launching gnuplot
  STDOUT = [];

  // Launch gnuplot's main() function
  let args = [SCRIPT_FILE];
  args = args.concat(options);
  // HACK: gnuplot does not clean up memory when it exits.
  // this is OK under normal circumstances because the OS will
  // reclaim the memory. But the emscripten runtime does not
  // do this, so we create a snapshot of the memory before calling
  // main and restore it after calling main.
  const mem_snapshot = Uint8Array.from(HEAPU8);
  callMain(args);
  HEAPU8.set(mem_snapshot);

  return STDOUT.join("\n");
}

/**
 * Launch Gnuplot.
 * @param data: {} - event.data object from REDUCE web worker message.
 * @returns void
 */
function launchGnuplot(data:
  { channel: string, script: string, files: { filename: string, data: Uint8Array }[] }) {
  // console.log(script);
  // data = {channel: "plot", files: null, script: ""} is possible!!!
  data.files?.map(file => {
    FS.writeFile(file.filename, file.data);
  });
  data.script && showPlot(data.script);
}

declare function draw_plot_on_canvas(): void; // Defined in "plot.js"

/**
 * Show Plot.
 * @param script: string - Gnuplot input script.
 * @returns void
 */
function showPlot(script: string) {
  // Call gnuplot
  const output = run_gnuplot(script, []);
  // Handle output -- there shouldn't be any!
  if (output) {
    alert("Gnuplot Message:\n" + output);
    return;
  }
  // Display plot image
  let draw_script = FS.readFile("plot.js", { encoding: "utf8" });
  // BEWARE that in Gnuplot 5.4.10 this defines
  // a function that uses two global variables:
  // function draw_plot_on_canvas() {
  //   canvas = document.getElementById("draw_plot_on_canvas");
  //   ctx = canvas.getContext("2d");
  // Localise these two variables...
  let canvas, ctx;
  try {
    // Indirect eval necessary because I am using strict mode; see
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/eval
    eval?.(draw_script); // indirect eval through optional chaining operator (?.)
  } catch (error) {
    console.error(error);
  }
  if (typeof draw_plot_on_canvas !== "function") {
    console.error("Function draw_plot_on_canvas not defined!");
    return;
  }
  // Clear any previous plot from the canvas:
  (<HTMLCanvasElement>document.getElementById("draw_plot_on_canvas")).getContext("2d")!.reset();
  draw_plot_on_canvas();
  showPlotWindowDisplay();
}

let plotWindow: HTMLElement, togglePlotWindowDisplayBtn: HTMLElement;
const inputDiv = document.getElementById("InputDiv");
// inputDiv is exported from module Main.ts but inaccessible here!

// On page load
document.addEventListener("DOMContentLoaded", function () {
  plotWindow = document.getElementById("plot-window")!;
  plotWindow.hidden = true;
  togglePlotWindowDisplayBtn = document.getElementById("toggle-plot-display-button")!;
});

function togglePlotWindowDisplay() {
  if (plotWindow.hidden)
    showPlotWindowDisplay();
  else {
    plotWindow.hidden = true;
    togglePlotWindowDisplayBtn.innerText = "Show Plot Window";
  }
  inputDiv!.focus();
}

function showPlotWindowDisplay() {
  plotWindow.hidden = false;
  togglePlotWindowDisplayBtn.innerText = "Hide Plot Window";
  // Make the plot window visible.
  // Doing this asynchronously is necessary in Chrome.
  setTimeout(() => plotWindow.scrollIntoView());
}
