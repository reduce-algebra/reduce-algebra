if (typeof(Module) === "undefined") Module = {};
Module["arguments"] = ["-i", "reduce.img"];
Module["preInit"] = function () {
    FS.createLazyFile('/', "reduce.img", "http://0.0.0.0:8000/new-embedded/for-emscripten/reduce.img", true, false);
};
Module["print"] = function(s) {
    self.postMessage({channel: "stdout", line: s});
};