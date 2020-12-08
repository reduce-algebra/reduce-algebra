// this is a sample file for reference
if (typeof(Module) === "undefined") Module = {};
// any arguments put here as strings
Module["arguments"] = ["-i", "reduce.img"];
Module["preInit"] = function () {
    // if running reduce in a web worker (recommended), then createLazyFile can be used.
    FS.createLazyFile('/', "reduce.img", "http://0.0.0.0:8000/reduce.img", true, false);
};
Module["print"] = function(s) {
    self.postMessage({channel: "stdout", line: s});
};