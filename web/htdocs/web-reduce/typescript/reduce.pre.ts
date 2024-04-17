// To facilitate development, this version of "pre.js" initializes
// the Module object and then imports "reduce.web.js".
// It should eventually be incorporated when "reduce.web.js" is built by Emscripten!
// See https://emscripten.org/docs/api_reference/module.html#module.
// Modification to the original "pre.js" based on code by Hermann Rolfes.
// Check for a call to Gnuplot whenever REDUCE writes to stdout.
var Module = {};
Module["print"] = function (s: string) {
  try {
    let cmds: string = FS.readFile("/tmp/plotcmds.txt", { encoding: "utf8" });
    // console.log("/tmp/plotcmds.txt\n" + cmds);
    FS.unlink("/tmp/plotcmds.txt");
    // Find the data files used:
    const matches: string[] = cmds.match(/'\/tmp\/.*?'/g); // quoted filenames
    const files: { filename: string; data: Uint8Array }[] = matches.map(
      (match) => {
        const filename = match.slice(1, -1); // strip off surrounding quotes
        const data = FS.readFile(filename); // returns new Uint8Array buffer
        // console.log(filename + "\n" + data);
        FS.unlink(filename); // ???
        return { filename: filename, data: data };
      },
    );
    const filedata: ArrayBuffer[] = files.map((file) => {
      return file.data.buffer;
    });
    // Transfer file contents efficiently rather than copying them:
    postMessage(
      { channel: "plot", script: cmds, files: files },
      { transfer: filedata },
    );
  } catch (error) {
    // Assume (for now) that "/tmp/plotcmds.txt" does not exist, so nothing to plot!
  }
  // Original content of this function:
  // console.log('print', s);
  self.postMessage({ channel: "stdout", line: s });
};
importScripts("reduce.web.js");
