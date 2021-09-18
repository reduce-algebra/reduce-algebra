// Input editor code

'use strict';

const inputList = [];
let inputListIndex = 0;
let maxInputListIndex = -1;
const quitPattern = /\b(?:bye|quit)\s*[;$]/i; /* case insensitive */

// *** Merge the next two functions? ***

function sendInput(event) {
    if (noOutput) return; // REDUCE not yet loaded!
    // Strip trailing white space from the input:
    let text = inputTextArea.value.replace(/\s+$/, "");
    if (text.length > 0) {
        if (!event.shiftKey) {
            // Ensure the input ends with a terminator:
            let c = text[text.length - 1];
            if (!(c == ';' || c == '$')) text += ";";
        }
        sendToReduceAndEcho(text);
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

/**
 * A list (array) of statements waiting to be input into REDUCE.
 */
let inputStatements = [];

/**
 * Send a statement in the input to REDUCE, wait for a response,
 * then send the next statement.
 */
function sendStatements(event) {
    if (noOutput) return; // REDUCE not yet loaded!
    // Strip trailing white space from the input:
    let text = inputTextArea.value.replace(/\s+^/, "");
    if (text.length > 0) {
        if (!event.shiftKey) {
            // Ensure the input ends with a terminator:
            let c = text[text.length - 1];
            if (!(c == ';' || c == '$')) text += ";";
        }
        // Store each statement followed by its terminator as separate elements of the array,
        // which always ends with an empty string:
        let stmts = text.split(/([;$])/);
        let noPendingInput = (inputStatements.length == 0);
        for (let i = 0; i < stmts.length - 1; i++)
            inputStatements.push(stmts[i] + stmts[++i]);
        if (noPendingInput) // send the first statement:
            sendToReduceAndEcho(inputStatements.shift());
        inputListIndex = inputList.push(text);
        maxInputListIndex = inputListIndex - 1;
        inputTextArea.value = "";
        earlierButton.disabled = false;
        laterButton.disabled = true;
    }
    inputTextArea.focus()
}

sendStatementsButton.addEventListener('click', sendStatements);

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
