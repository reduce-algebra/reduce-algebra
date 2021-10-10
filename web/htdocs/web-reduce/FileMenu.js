// Support for the File menu
// This is a module, which automatically uses strict mode and makes identifiers local unless exported!

// See The File System Access API: https://web.dev/file-system-access/
// and https://developer.mozilla.org/en-US/docs/Web/API/File_System_Access_API.
// The File System Access API is currently supported on most Chromium browsers,
// namely Chrome, Edge and Opera, on Windows, macOS, Chrome OS, and Linux.
// Other browsers, such as Firefox, need a fallback implementation, which is horrible!
// See https://web.dev/browser-fs-access/.

const supported = "showOpenFilePicker" in window;
const echoFileInputCheckbox = document.getElementById('EchoFileInputCheckbox');
const outputFileMenuItem = document.getElementById("OutputFileMenuItem");
const outputHereMenuItem = document.getElementById("OutputHereMenuItem");
outputHereMenuItem.disabled = true;
const outputOpenMenuItem = document.getElementById("OutputOpenMenuItem");
outputOpenMenuItem.disabled = true;
const shutFileMenuItem = document.getElementById("ShutFileMenuItem");
shutFileMenuItem.disabled = true;
let typesetMathsEnabled;

if (supported) {
    debug && console.log('Using the File System Access API.');
    const inputPickerOptions = {
        id: "input", // keep this picker distinct
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
    var fileOpen = async () => {
        const [fileHandle] = await window.showOpenFilePicker(inputPickerOptions);
        return fileHandle.getFile();
    };
} else {
    debug && console.log('The File System Access API is not available.');
    var fileOpen = async () => {
        return new Promise(resolve => {
            const input = document.createElement('input');
            input.type = 'file';
            input.accept = ".red, .tst, .txt, text/plain";
            input.addEventListener('change', () => resolve(input.files[0]));
            input.click();
        });
    };
};

document.getElementById("InputFileMenuItem").addEventListener('click', async () => {
    inputFromKbd = false;
    try {
        const file = await fileOpen();
        sendPlainTextToIODisplay(`Inputting from file "${file.name}"...`, "info");
        const contents = await file.text();
        if (echoFileInputCheckbox.checked) {
            if (echo) {
                sendToReduce(contents);
            } else {
                sendToReduce("on echo;");
                echo = true;
                setTimeout(sendToReduce, 100, contents);
            }
        } else {
            if (echo) {
                hideOutput = true;
                sendToReduce("off echo;");
                echo = false;
                setTimeout(sendToReduce, 100, contents);
            } else {
                sendToReduce(contents);
            }
        }
    } catch (err) {
        if (err.name !== 'AbortError') console.error(err.name, err.message);
    }
    inputTextArea.focus();
});

const defaultOutputFileName = "output.log";
let outputFileName;

if (supported) {
    // While outputToFile is defined (true), REDUCE outputs using
    // outputToFile.write(output);
    // outputToFile is declared in "Main.js".
    var outputFileHandle, writable;
    var outputPickerOptions = {
        id: "output", // keep this picker distinct
        suggestedName: defaultOutputFileName,
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
} else {
    // While outputToArray is defined (true), REDUCE outputs using
    // outputToArray.push(output);
    // outputToArray is declared in "Main.js".
    var outputArray;
    var fileSave = async (blob) => {
        const a = document.createElement('a');
        a.download = outputFileName;
        a.href = URL.createObjectURL(blob);
        a.addEventListener('click', (e) => {
            setTimeout(() => URL.revokeObjectURL(a.href), 30 * 1000);
        });
        a.click();
    };
}

function displayOutputtingToFile() {
    sendPlainTextToIODisplay(`Outputting to file "${outputFileName}"...`, "info");
}

function displayOutputtingToTerminal() {
    sendPlainTextToIODisplay("Outputting to terminal...", "info");
}

outputFileMenuItem.addEventListener('click', async () => {
    try {
        if (supported) {
            outputFileHandle = await window.showSaveFilePicker(outputPickerOptions);
            outputFileName = outputFileHandle.name;
            // Cancelling the picker throws an AbortError.
            // Create a FileSystemWritableFileStream to write to:
            outputToFile = writable = await outputFileHandle.createWritable();
        } else {
            let filename = prompt("Save output file to downloads location as:", defaultOutputFileName);
            if (!filename) {
                const error = new Error();
                error.name = "AbortError";
                throw error;
            }
            outputFileName = filename;
            outputToArray = outputArray = []; // array constructed from REDUCE output
        }
        displayOutputtingToFile();
        // Don't write TeX syntax to output file:
        typesetMathsEnabled = typesetMathsCheckbox.checked;
        if (typesetMathsEnabled) enableTypesetMaths(false);
        outputFileMenuItem.disabled = true;
        outputHereMenuItem.disabled = false;
        shutFileMenuItem.disabled = false;
    } catch (err) {
        if (err.name !== 'AbortError') console.error(err.name, err.message);
    }
    inputTextArea.focus();
});

outputHereMenuItem.addEventListener('click', () => {
    if (supported) {
        outputToFile = false;
    } else {
        outputToArray = false;
    }
    displayOutputtingToTerminal();
    // If typeset maths was on, it has been stealthily turned off,
    // so if necessary turn it back on:
    if (typesetMathsEnabled && typesetMathsCheckbox.checked) enableTypesetMaths(true);
    outputOpenMenuItem.disabled = false;
    outputHereMenuItem.disabled = true;
    inputTextArea.focus();
});

outputOpenMenuItem.addEventListener('click', () => {
    if (supported) {
        outputToFile = writable;
    } else {
        outputToArray = outputArray;
    }
    displayOutputtingToFile();
    // If typeset maths was on and has not explicilty been turned off,
    // then turn it off again:
    if (typesetMathsEnabled && typesetMathsCheckbox.checked) enableTypesetMaths(false);
    outputHereMenuItem.disabled = false;
    outputOpenMenuItem.disabled = true;
    inputTextArea.focus();
});

shutFileMenuItem.addEventListener('click', async () => {
    if (supported) {
        try {
            await writable.close();
        } catch (err) {
            console.error(err.name, err.message);
        }
        writable = undefined;
        outputToFile = false;
    } else {
        try {
            const blob = new Blob(outputArray); // array constructed from REDUCE output
            await fileSave(blob);
        } catch (err) {
            console.error(err.name, err.message);
        }
        outputArray = undefined;
        outputToArray = false;
    }
    displayOutputtingToTerminal();
    // If typeset maths was on, it has been stealthily turned off,
    // so if necessary turn it back on:
    if (typesetMathsEnabled && typesetMathsCheckbox.checked) enableTypesetMaths(true);
    outputFileMenuItem.disabled = false;
    outputHereMenuItem.disabled = true;
    outputOpenMenuItem.disabled = true;
    shutFileMenuItem.disabled = true;
    inputTextArea.focus();
});
