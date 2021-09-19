// Support for the File menu
// See The File System Access API: https://web.dev/file-system-access/
// and https://developer.mozilla.org/en-US/docs/Web/API/File_System_Access_API.
// The File System Access API is currently supported on most Chromium browsers,
// namely Chrome, Edge and Opera, on Windows, macOS, Chrome OS, and Linux.
// *** Firefox needs additional support. ***

'use strict';

// Block used for namespace control:
{
    const inputPickerOpts = {
        id: "input", // keep this picker distinct
        multiple: true,
        types: [
            {
                description: "REDUCE Input Files",
                accept: { "text/plain": [".red", ".tst"] }
            },
            {
                description: "REDUCE Test Files",
                accept: { "text/plain": [".tst"] }
            },
            {
                description: "Text Files",
                accept: { "text/plain": [".txt"] }
            }
        ]
    };

    document.getElementById("InputFilesMenuItem").addEventListener('click', async () => {
        try {
            const fileHandles = await window.showOpenFilePicker(inputPickerOpts);
            for (const fileHandle of fileHandles) {
                const file = await fileHandle.getFile();
                const contents = await file.text();
                sendToReduceAndEcho(contents, true);
            }
        } catch (ignore) { }
    });

    const outputPickerOpts = {
        id: "output", // keep this picker distinct
        suggestedName: "output.log",
        types: [
            {
                description: "REDUCE Log Files",
                accept: { "text/plain": [".log", ".rlg"] }
            },
            {
                description: "Text Files",
                accept: { "text/plain": [".txt"] }
            }
        ]
    };

    const outputFileMenuItem = document.getElementById("OutputFileMenuItem");
    const shutFileMenuItem = document.getElementById("ShutFileMenuItem");
    shutFileMenuItem.disabled = true;

    /*
     * While writable in defined (true), REDUCE outputs using
     * writable.write(output);
     */
    var writable; // Accessed in "Main.js".
    let typesetMathsEnabled;

    outputFileMenuItem.addEventListener('click', async () => {
        try {
            const fileHandle = await window.showSaveFilePicker(outputPickerOpts);
            // Cancelling the picker throws an AbortError.
            // Create a FileSystemWritableFileStream to write to:
            writable = await fileHandle.createWritable();
            sendPlainTextToIODisplay(`Outputting to file "${fileHandle.name}"...`, "info");
            // Don't write TeX syntax to output file:
            typesetMathsEnabled = typesetMathsCheckbox.checked;
            if (typesetMathsEnabled) enableTypesetMaths(false);
            outputFileMenuItem.disabled = true;
            shutFileMenuItem.disabled = false;
        } catch (ignore) { }
    });

    shutFileMenuItem.addEventListener('click', async () => {
        if (writable) {
            // Close the file and write the contents to disk:
            await writable.close();
            writable = undefined;
            sendPlainTextToIODisplay("Outputting to terminal...", "info");
            if (typesetMathsEnabled) enableTypesetMaths(true);
            outputFileMenuItem.disabled = false;
            shutFileMenuItem.disabled = true;
        }
    });
}
