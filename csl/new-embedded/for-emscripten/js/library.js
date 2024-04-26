// Use this code via the emcc link option "--js-library js/library.js". See:
// https://emscripten.org/docs/porting/connecting_cpp_and_javascript/Interacting-with-code.html#implement-a-c-api-in-javascript
// https://emscripten.org/docs/api_reference/preamble.js.html?highlight=library#conversion-functions-strings-pointers-and-arrays
// addToLibrary({ // fails! Documentation error?
mergeInto(LibraryManager.library, {
  system: function (command) {
    // int system(const char *command);
    // http://pubs.opengroup.org/onlinepubs/000095399/functions/system.html
    if (!command) return 0 // no shell available
    try {
      const commandString = AsciiToString(command)
      // console.log("system(" + commandString + ")");
      // Check for "gnuplot /tmp/plotcmds.txt".
      if (commandString.startsWith('gnuplot')) {
        const cmdFilename = commandString.substring(8)
        const cmds = FS.readFile(cmdFilename, { encoding: 'utf8' })
        // console.log(cmdFilename + ":\n" + cmds);
        // FS.unlink(cmdFilename);
        // Find the data files used:
        const matches = cmds.match(/'\/tmp\/.*?'/g) // single-quoted filenames
        const files =
          matches &&
          matches.map((match) => {
            const filename = match.slice(1, -1) // strip off surrounding quotes
            const data = FS.readFile(filename) // returns new Uint8Array buffer
            // console.log(filename + ":\n" + data);
            // FS.unlink(filename); // ???
            return { filename, data }
          })
        const filedata = files?.map((file) => {
          return file.data.buffer
        })
        // Transfer file contents efficiently rather than copying them:
        postMessage(
          { channel: 'plot', script: cmds, files },
          { transfer: filedata }
        )
        return 0 // success
      }
    } catch (error) {
      console.error("Error in 'std::system' function:", error)
      return 1 // failure
    }
    // Can't call external programs.
    setErrNo(52)
    return -1
  }
})
