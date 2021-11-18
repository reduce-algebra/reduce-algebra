// Input editor code
// This is a module, which automatically uses strict mode and makes identifiers local unless exported!

// Successive calls to sendToReduce() do not work because REDUCE appears
// to ignore input when it is not ready. Need to either concatenate
// input into a single call of sendToReduce() or delay successive calls
// by about 100ms (which is obviously unreliable).

const inputList = [];
let inputListIndex = 0;
let maxInputListIndex = -1;
const quitPattern = /\b(?:bye|quit)\s*[;$]/i;  // case insensitive

function sendInput(event) {
    if (noOutput) return; // REDUCE not yet loaded!
    inputFromKbd = true;
    // Strip trailing white space from the input:
    let text = inputDiv.innerText.replace(/\s+$/, "");
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
        inputDiv.innerHTML = "";
        earlierButton.disabled = false;
        laterButton.disabled = true;
        if (quitPattern.test(text)) stopREDUCE();
    }
    inputDiv.focus()
}

sendInputButton.addEventListener('click', sendInput);

function earlierInput(event) {
    event.preventDefault();
    if (inputListIndex > 0) {
        inputDiv.innerText = inputList[--inputListIndex];
        if (inputListIndex <= maxInputListIndex)
            laterButton.disabled = false;
    }
    if (inputListIndex == 0)
        earlierButton.disabled = true;
    inputDiv.focus();
}

earlierButton.addEventListener('click', earlierInput);

function laterInput(event) {
    event.preventDefault();
    if (inputListIndex < maxInputListIndex) {
        inputDiv.innerText = inputList[++inputListIndex];
    } else {
        inputDiv.innerHTML = "";
        inputListIndex = maxInputListIndex + 1;
    }
    if (inputListIndex > 0) {
        earlierButton.disabled = false;
    }
    if (inputListIndex > maxInputListIndex) {
        laterButton.disabled = true;
    }
    inputDiv.focus();
}

laterButton.addEventListener('click', laterInput);

inputDiv.addEventListener("keydown", event => {
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

/**********************
 * Delimiter matching *
 **********************/

let delimsHighlighted = false;  // true when matching delimiters are highlighted.
const selection = getSelection();

const matchDelimsCheckbox = document.getElementById("MatchDelimsCheckbox");
matchDelimsCheckbox.checked = true;

matchDelimsCheckbox.addEventListener("change", () =>
    enableMatchDelims(matchDelimsCheckbox.checked));

/**
* Enable or disable delimiter matching by adding or removing the event handlers.
* @param {boolean} enable - if true then enable.
*/
function enableMatchDelims(enable) {
    if (enable) {
        inputDiv.addEventListener("keyup", matchDelimsKeyHandler);
        inputDiv.addEventListener("click", highlightMatchingDelims);
        selection.collapse(inputDiv, 0);
        highlightMatchingDelims();
    } else {
        inputDiv.removeEventListener("keyup", matchDelimsKeyHandler);
        inputDiv.removeEventListener("click", highlightMatchingDelims);
        if (delimsHighlighted) {
            // Clear any highlighting:
            inputDiv.innerText = inputDiv.innerText;
            delimsHighlighted = false;
        }
    }
    inputDiv.focus();
}

enableMatchDelims(true);

/**
 * Filter keyboard events that trigger delimiter matching.
 * @param {KeyboardEvent} event - keyboard event to handle.
 */
function matchDelimsKeyHandler(event) {
    switch (event.key) {
        case "Enter": case "ArrowUp": case "ArrowDown":
            // Control+key already handled by keydown event:
            if (!event.ctrlKey) highlightMatchingDelims();
            break;
        case "ArrowLeft": case "ArrowRight": case "End": case "Home":
        case "Tab": case "Backspace": case "Delete":
            highlightMatchingDelims();
            break;
        default:
            // Ignore modifier keys:
            if (event.key.length == 1) highlightMatchingDelims();
    }
}

const closeDelimToRegexp = { ")": /[()]/g, "}": /[{}]/g, ">>": /<<|>>/g, "end": /\b(?:begin|end)\b/ig };
const openDelimToRegexp = { "(": /[()]/g, "{": /[{}]/g, "<<": /<<|>>/g, "begin": /\b(?:begin|end)\b/ig };

const span = document.createElement("span"); // used to highlight matching delimiters.
span.style.textDecoration = "underline";

/**
 * If there is a closing delimiter immediately before or an opening delimiter immediately after
 * the caret then highlight the matching delimiters; otherwise, remove any highlighting.
 * Run this function on events that normally move caret (i.e. mouse click and some keyup events).
 * BEWARE: In Firefox, editable <div> content may end with <br> and each line may be a <div>.
 */
function highlightMatchingDelims() {
    // Abort if input is empty or text is selected:
    if (!inputDiv.firstChild || !selection.isCollapsed) return;
    // Get text before and after caret:
    const caretNode = selection.anchorNode, caret = selection.anchorOffset;
    // Using a range would be better here, but Range.toString() ignores newlines, at least in Firefox.
    selection.setBaseAndExtent(inputDiv, 0, caretNode, caret);
    const textBefore = selection.toString();
    selection.setBaseAndExtent(caretNode, caret, inputDiv, inputDiv.childNodes.length);
    const textAfter = selection.toString();
    // Restore original selection in case it is not set later:
    selection.collapse(caretNode, caret);
    // Separate lines may be in <div> elements, which implicitly end with a <br/>, so...
    const atEOL = caretNode.parentNode !== inputDiv && caretNode.parentNode.tagName === "DIV" &&
        caret === caretNode.length && caretNode.parentNode.nextSibling !== null;
    if (textBefore) {
        // Check for matching delimiters closing immediately before caret.
        // The regexp flag i makes searching case-insensitive.
        let openIndex;
        const initialMatch = textBefore.match(/(?:[)}]|>>|\bend)$/i);
        if (initialMatch) {
            const closeDelim = initialMatch[0].toLowerCase();
            if (!(closeDelim === "end" && /^(?:\w|\d)/.test(textAfter))) {
                const regexp = closeDelimToRegexp[closeDelim];
                let closeCount = 0;
                const matches = [...textBefore.matchAll(regexp)];
                for (let index = matches.length - 1; index >= 0; index--) {
                    const match = matches[index];
                    if (match[0].toLowerCase() === closeDelim) closeCount++;
                    else {
                        closeCount--;
                        if (closeCount === 0) {
                            openIndex = match.index;
                            break;
                        }
                    }
                }
            }
        }
        if (openIndex !== undefined) {
            // Replace inputDiv contents with textBeforeOpen<span>textBeforeClose</span>textAfter:
            inputDiv.innerText = textBefore.substr(0, openIndex);
            span.innerText = textBefore.substr(openIndex);
            inputDiv.appendChild(span);
            if (atEOL) inputDiv.appendChild(document.createElement("br"));
            appendText(textAfter);
            // Set caret to end of span:
            selection.collapse(span, span.childNodes.length);
            delimsHighlighted = true;
            return;
        }
    }
    if (textAfter) {
        // Check for matching delimiters opening immediately after caret.
        let closeIndex;
        const initialMatch = textAfter.match(/^(?:[({]|<<|begin\b)/i);
        if (initialMatch) {
            const openDelim = initialMatch[0].toLowerCase();
            if (!(openDelim === "begin" && /(?:\w|\d)$/.test(textBefore))) {
                const regexp = openDelimToRegexp[openDelim];
                let openCount = 0;
                for (const match of textAfter.matchAll(regexp)) {
                    if (match[0].toLowerCase() === openDelim) openCount++;
                    else {
                        openCount--;
                        if (openCount === 0) {
                            closeIndex = match.index + match[0].length;
                            break;
                        }
                    }
                }
            }
        }
        if (closeIndex) {
            // Replace inputDiv contents with textBefore<span>textAfterOpen</span>textAfterClose:
            inputDiv.innerText = textBefore;
            if (atEOL) inputDiv.appendChild(document.createElement("br"));
            span.innerText = textAfter.substr(0, closeIndex);
            inputDiv.appendChild(span);
            appendText(textAfter.substr(closeIndex));
            // Set caret to beginning of span:
            selection.collapse(span, 0);
            delimsHighlighted = true;
            return;
        }
    }
    // If matching delimiters are highlighted then clear the highlighting.
    if (delimsHighlighted) {
        // Reset inputDiv content to plain text containing caret:
        inputDiv.innerText = textBefore;
        selection.collapse(inputDiv, inputDiv.childNodes.length);
        appendText(textAfter);
        inputDiv.normalize();
        delimsHighlighted = false;
    }
}

const tmpDiv = document.createElement("div");

/**
 * Convert newlines in text to <br/> elements and append to inputDiv.
 * @param {string} text - plain text.
 */
function appendText(text) {
    if (text) {
        tmpDiv.innerText = text;
        inputDiv.append(...tmpDiv.childNodes);
    }
}
