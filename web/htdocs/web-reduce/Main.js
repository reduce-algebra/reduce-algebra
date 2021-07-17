// Main source code

// Set up access to document elements and reset their defaults for when the page is reloaded:
const typesetMathsCheckbox = document.getElementById('TypesetMathsCheckbox');
typesetMathsCheckbox.disabled = true;
const centreTypesetMathsCheckbox = document.getElementById('CentreTypesetMathsCheckbox');
const outputDiv = document.getElementById('OutputDiv');
const inputTextArea = document.getElementById('InputTextArea');
inputTextArea.value = "";
inputTextArea.focus();
const earlierButton = document.getElementById('EarlierButton');
earlierButton.disabled = true;
const sendButton = document.getElementById('SendButton');
sendButton.disabled = true;
const laterButton = document.getElementById('LaterButton');
laterButton.disabled = true;
let noOutput = true, hideOutput = false;

// Only for use during development:
//throw new Error("Don't run REDUCE!");

/**
 * Scroll the REDUCE output to the bottom.
 * A sufficient delay seems necessary for the input to be rendered!
 * This may not be the best solution but it seems to work provided the delay is long enough.
 */
function scrollOutputDivToBottom() {
    setTimeout(function () { outputDiv.lastChild.scrollIntoView(false) }, 300);
    // Scroll again after KaTeX has had time to complete:
    setTimeout(function () { outputDiv.lastChild.scrollIntoView(false) }, 1000);
}

function sendToOutputDiv(text) {
    if (noOutput) {
        // This code executes immediately after REDUCE loads:
        outputDiv.textContent = "";
        sendButton.disabled = false;
        typesetMathsCheckbox.disabled = false;
        noOutput = false;
    }
    // For now, append text within a <pre> element:
    const pre = document.createElement("pre");
    pre.innerText = text;
    outputDiv.appendChild(pre);
    scrollOutputDivToBottom();
}

const worker = new Worker('./reduce.web.js');
worker.onmessage = function (event) {
    if (hideOutput) { // hide changes of switches etc.
        hideOutput = false;
        return;
    }
    if (event.data.channel === 'stdout') {
        let output = event.data.line;
        // If an empty string is passed (ie asking for a blank line of output)
        // it gets lost in the display, so output a single space character.
        if (output == '') {
            console.log("OUTPUT: Empty line"); // for debugging
            sendToOutputDiv(' ');
            return;
        }
        console.log(`OUTPUT: ${output}`); // for debugging

        // The mathematical part of the output delived by REDUCE will have the form:
        // latex:\black$\displaystyle\frac{-2\*\arctan\left(x\right)+\log\left(x-1\right)-\log\left(x+1\right)}{4}$
        // delimited by a pair of control characters, \u0002 before and \u0005 after.
        // The TeX in the middle is extracted and MathJax formats it.

        // Detect the case where the output line contains some TeX:
        let n = output.indexOf('\u0002');
        if (n != -1) {
            // Here I not only strip out the material before the "U+0002" but also the
            // "junk" that reads "latex:\black$\displaystyle" and a final "U+0005".
            // Those are fragments that the REDUCE interface for TeXmacs inserts.
            output = output.substring(n + 1 + 26, output.length - 2);
            outputDiv.appendChild(MathJax.tex2chtml(output));
            // The MathJax documentation doesn't tell the whole story!
            // See https://github.com/mathjax/MathJax/issues/2365:
            MathJax.startup.document.clear();
            MathJax.startup.document.updateDocument();
            scrollOutputDivToBottom();
        }
        else {
            // Textual rather than mathematical output from REDUCE gets inserted as is.
            sendToOutputDiv(output);
        }
    }
}

function sendToReduce(str) {
    console.log(` INPUT: ${str}`); // for debugging
    // This function posts a string to REDUCE, which treats it rather as if
    // it had been keyboard input. At the start of a run I use this to send a
    // sequence of commands to REDUCE to adjust its input and output processing
    // to suit the needs I have here.
    const buf = new Uint8Array(str.length + 1);
    for (let i = 0; i < str.length; i++)
        buf[i] = str.charCodeAt(i);
    buf[str.length] = 0; // null-terminate for benefit of C/C++.
    worker.postMessage({
        funcName: 'insert_buffer',
        callbackId: '',
        data: buf
    });
}

sendToReduce('<< lisp (!*redefmsg := nil); load_package tmprint;' +
    ' on nat; on fancy; off int >>$');

// *****************
// Utility Functions
// *****************

function sendToReduceAndEcho(text) {
    sendToOutputDiv(text);
    sendToReduce(text);
}

const loadedPackages = new Set(); // should probably be in a closure!

/**
 * Load the specified package once only.
 * @param {any} package
 */
function loadPackage(package) {
    if (loadedPackages.has(package)) return;
    sendToReduceAndEcho(`load_package ${package};`);
    // Need to wait for REDUCE to digest this.
    // Should wait for the next prompt, but can't at present, so...
    // ...
    loadedPackages.add(package);
}

// ****************
// User Interaction
// ****************

typesetMathsCheckbox.addEventListener("change", event => {
    hideOutput = true;
    if (typesetMathsCheckbox.checked) sendToReduce('on fancy;');
    else sendToReduce('off fancy;');
});

centreTypesetMathsCheckbox.addEventListener("change", event => {
    if (centreTypesetMathsCheckbox.checked) MathJax.config.chtml.displayAlign = 'center';
    else MathJax.config.chtml.displayAlign = 'left';
    MathJax.startup.getComponents(); // See http://docs.mathjax.org/en/latest/web/configuration.html
});
