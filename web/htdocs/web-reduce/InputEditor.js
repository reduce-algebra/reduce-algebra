// Input editor code

// Successive calls to sendToReduce() do not work because REDUCE appears
// to ignore input when it is not ready. Need to either concatenate
// input into a single call of sendToReduce() or delay successive calls
// by about 100ms (which is obviously unreliable).

'use strict';

const inputList = [];
let inputListIndex = 0;
let maxInputListIndex = -1;
const quitPattern = /\b(?:bye|quit)\s*[;$]/i;  // case insensitive
var echo = false;  // setting of REDUCE echo switch

function sendInput(event) {
    if (noOutput) return; // REDUCE not yet loaded!
    inputFromKbd = true;
    // Strip trailing white space from the input:
    let text = inputTextArea.value.replace(/\s+$/, "");
    if (text.length > 0) {
        if (!event.shiftKey) {
            // Ensure the input ends with a terminator:
            let c = text[text.length - 1];
            if (!(c == ';' || c == '$')) text += ";";
        }
        if (event.altKey) {
            // Send keyboard input to REDUCE as if from a file via IN,
            // letting REDUCE echo the input.
            if (echo) {
                sendToReduce(text);
            } else {
                sendToReduce("on echo;" + text);
                echo = true;
            }
        } else {
            if (echo) {
                hideOutput = true;
                sendToReduce("off echo;");
                echo = false;
                setTimeout(sendToReduceAndEcho, 100, text);
            } else {
                sendToReduceAndEcho(text);
            }
        }
        inputListIndex = inputList.push(text);
        maxInputListIndex = inputListIndex - 1;
        inputTextArea.value = "";
        earlierButton.disabled = false;
        laterButton.disabled = true;
        if (quitPattern.test(text)) stopREDUCE();
    }
    inputTextArea.focus()
}

sendInputButton.addEventListener('click', sendInput);

function earlierInput(event) {
    event.preventDefault();
    if (inputListIndex > 0) {
        inputTextArea.value = inputList[--inputListIndex];
        if (inputListIndex <= maxInputListIndex)
            laterButton.disabled = false;
    }
    if (inputListIndex == 0)
        earlierButton.disabled = true;
    inputTextArea.focus();
}

earlierButton.addEventListener('click', earlierInput);

function laterInput(event) {
    event.preventDefault();
    if (inputListIndex < maxInputListIndex) {
        inputTextArea.value = inputList[++inputListIndex];
    } else {
        inputTextArea.value = "";
        inputListIndex = maxInputListIndex + 1;
    }
    if (inputListIndex > 0) {
        earlierButton.disabled = false;
    }
    if (inputListIndex > maxInputListIndex) {
        laterButton.disabled = true;
    }
    inputTextArea.focus();
}

laterButton.addEventListener('click', laterInput);

inputTextArea.addEventListener("keydown", event => {
    if (event.ctrlKey) {
        switch (event.key) {
            case "Enter":
                sendInput(event);
                break;
            case "ArrowUp":
                earlierInput(event);
                break;
            case "ArrowDown":
                laterInput(event);
        }
    }
});
