// *** Main Web Gnuplot page logic ***
// Cannot easily make this into a module!

// gnuplot.init = function () { };

// Defined in "gnuplot.js":
declare function callMain(args: string[]): void;
var HEAPU8: Uint8Array;

// WebAssembly module config
var STDOUT = [],
  SCRIPT_FILE = "script.gnuplot";

var Module = {};
// Don't run main on page load
Module["noInitialRun"] = true;
// Print functions
Module["print"] = (stdout: string) => STDOUT.push(stdout);
Module["printErr"] = (stderr: string) => STDOUT.push(stderr);
// When the module is ready
Module["onRuntimeInitialized"] = function () {
  document.getElementById("gnuplot-version").innerText =
    "Powered by " + run_gnuplot("", "--version").stdout;
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

  return {
    stdout: STDOUT.join("\n")
  };
}

declare function draw_plot_on_canvas(): void; // Defined in "plot.js"

/**
 * Launch Gnuplot.
 * @param data: {} - event.data object from REDUCE web worker message.
 * @returns void
 */
function launchGnuplot(data:
  { channel: string, script: string, files: { filename: string, data: Uint8Array }[] }) {
  // console.log(script);
  data.files.map(file => {
    FS.writeFile(file.filename, file.data);
  });
  // Call gnuplot
  const output = run_gnuplot(data.script, []).stdout;
  // Handle output -- there shouldn't be any!
  if (output) {
    alert("Gnuplot Message:\n" + output);
    return;
  }

  // Display plot image
  let draw_script = FS.readFile("plot.js", { encoding: "utf8" });

  eval(draw_script);
  // BEWARE that in Gnuplot 5.4.10 this defines function
  // draw_plot_on_canvas that uses global variables canvas and ctx!
  // Clear any previous plot from the canvas.
  // (There might be a better way to do this!)
  (<HTMLCanvasElement>document.getElementById("draw_plot_on_canvas")).getContext("2d").reset();
  if (typeof draw_plot_on_canvas === "function") {
    draw_plot_on_canvas();
    showPlotWindowDisplay();
  }
}

let plotWindow: HTMLElement, togglePlotWindowDisplayBtn: HTMLElement, bottom: number;
const inputDiv = document.getElementById("InputDiv");
// inputDiv is exported from module Main.ts but inaccessible here!

// On page load
document.addEventListener("DOMContentLoaded", function () {
  plotWindow = document.getElementById("plot-window");
  togglePlotWindowDisplayBtn = document.getElementById("toggle-plot-display-button");
  bottom = document.getElementById("main").scrollHeight;
});

function togglePlotWindowDisplay() {
  if (plotWindow.classList.contains("d-none")) showPlotWindowDisplay();
  else {
    plotWindow.classList.add("d-none");
    togglePlotWindowDisplayBtn.innerText = "Show Plot Window";
  }
  inputDiv.focus();
}

function showPlotWindowDisplay() {
  plotWindow.classList.remove("d-none");
  scroll(0, bottom); // make the whole plot window visible
  togglePlotWindowDisplayBtn.innerText = "Hide Plot Window";
}
