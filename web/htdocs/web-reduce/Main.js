// Main source code

'use strict';

const debug = (location.search == '?debug');

// Set up access to document elements and reset their defaults for when the page is reloaded:
const ioColouringCheckbox = document.getElementById('IOColouringCheckbox');
const typesetMathsCheckbox = document.getElementById('TypesetMathsCheckbox');
typesetMathsCheckbox.disabled = true;
const centreTypesetMathsCheckbox = document.getElementById('CentreTypesetMathsCheckbox');
const ioDisplayDiv = document.getElementById('IODisplayDiv');
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
 * Scroll the REDUCE IO display to the bottom.
 */
function scrollIODisplayDivToBottom() {
    ioDisplayDiv.scrollTo(0, ioDisplayDiv.scrollHeight);
}

function sendToIODisplayDiv(text, inputOrOutput) {
    if (noOutput) {
        // This code executes immediately after REDUCE loads:
        ioDisplayDiv.textContent = "";
        sendButton.disabled = false;
        typesetMathsCheckbox.disabled = false;
        inputOrOutput = false;
        noOutput = false;
    }
    // For now, append text within a <pre> element:
    const pre = document.createElement("pre");
    if (inputOrOutput) pre.classList.add(inputOrOutput);
    pre.innerText = text;
    ioDisplayDiv.appendChild(pre);
    scrollIODisplayDivToBottom();
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
            debug && console.log("OUTPUT: Empty line"); // for debugging
            sendToIODisplayDiv(' ');
            return;
        }
        debug && console.log(`OUTPUT: ${output}`); // for debugging

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
            output = MathJax.tex2chtml(output);
            output.classList.add("output");
            ioDisplayDiv.appendChild(output);
            // The MathJax documentation doesn't tell the whole story!
            // See https://github.com/mathjax/MathJax/issues/2365:
            MathJax.startup.document.clear();
            MathJax.startup.document.updateDocument();
            scrollIODisplayDivToBottom();
        }
        else {
            // Textual rather than mathematical output from REDUCE gets inserted as is.
            sendToIODisplayDiv(output, "output");
        }
    }
}

function sendToReduce(str) {
    debug && console.log(` INPUT: ${str}`); // for debugging
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
    sendToIODisplayDiv(text, "input");
    sendToReduce(text);
}

const loadedPackages = new Set(); // should probably be in a closure!

/**
 * Load the specified package once only.
 * @param {any} pkg
 */
function loadPackage(pkg) {
    if (loadedPackages.has(pkg)) return;
    sendToReduceAndEcho(`load_package ${pkg};`);
    // Need to wait for REDUCE to digest this.
    // Should wait for the next prompt, but can't at present, so...
    // ...
    loadedPackages.add(pkg);
}

// ************
// Menu Support
// ************

// Block used for namespace control:
{
    const id = "IOColouringStyle";
    const style = document.createElement("style");
    style.innerText = "#IODisplayDiv pre.input {color: red;} #IODisplayDiv *.output {color: blue;}";
    style.setAttribute("id", id);
    document.head.appendChild(style); // initially checked

    ioColouringCheckbox.addEventListener("change", event => {
        if (ioColouringCheckbox.checked)
            document.head.appendChild(style);
        else
            document.getElementById(id).remove();
    });
}

typesetMathsCheckbox.addEventListener("change", event => {
    hideOutput = true;
    sendToReduce(typesetMathsCheckbox.checked ? 'on fancy;' : 'off fancy;');
});

centreTypesetMathsCheckbox.addEventListener("change", event => {
    MathJax.config.chtml.displayAlign = centreTypesetMathsCheckbox.checked ? 'center' : 'left';
    MathJax.startup.getComponents(); // See http://docs.mathjax.org/en/latest/web/configuration.html
});
