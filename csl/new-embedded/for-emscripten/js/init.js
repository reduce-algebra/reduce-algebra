// this is a sample file for reference
if (typeof(Module) === "undefined") Module = {};
// any arguments put here as strings
Module["arguments"] = ["-v"];
Module["preInit"] = function () {
};
Module["print"] = function(s) {
    self.postMessage({channel: "stdout", line: s});
};