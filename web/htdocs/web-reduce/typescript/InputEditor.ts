/**
 * Input editor code.
 * @module InputEditor
 * Successive calls to sendToReduce() do not work because REDUCE appears
 * to ignore input when it is not ready. Need to either concatenate
 * input into a single call of sendToReduce() or delay successive calls
 * by about 100ms (which is obviously unreliable).
 */

// Imported variables:
import { inputDiv, earlierButton, sendInputButton, laterButton, noOutput, Global } from "./Main.js";

// Imported functions:
import { sendToReduce, sendToReduceAndEcho, stopREDUCE } from "./Main.js";

const inputList = [];
let inputListIndex = 0;
let maxInputListIndex = -1;
const quitPattern = /\b(?:bye|quit)\s*[;$]/i;  // case insensitive

function sendInput(event: KeyboardEvent | MouseEvent) {
    if (noOutput) return; // REDUCE not yet loaded!
    Global.inputFromKbd = true;
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
            if (Global.echo) {
                sendToReduce(text);
            } else {
                sendToReduce("on echo;" + text);
                Global.echo = true;
            }
        } else {
            if (Global.echo) {
                Global.hideOutput = true;
                sendToReduce("off echo;");
                Global.echo = false;
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

function earlierInput(event: KeyboardEvent | MouseEvent) {
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

function laterInput(event: KeyboardEvent | MouseEvent) {
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

let highlighted = false;  // true when text is highlighted.
const selection: Selection = getSelection();

const matchDelimsCheckbox = document.getElementById("MatchDelimsCheckbox") as HTMLInputElement;
matchDelimsCheckbox.checked = true;

matchDelimsCheckbox.addEventListener("change", () =>
    enableMatchDelims(matchDelimsCheckbox.checked));

/**
* Enable or disable delimiter matching by adding or removing the event handlers.
* @param {boolean} enable - if true then enable.
*/
function enableMatchDelims(enable: boolean) {
    if (enable) {
        inputDiv.addEventListener("keyup", matchDelimsKeyHandler);
        inputDiv.addEventListener("click", highlightMatchingDelims);
        selection.collapse(inputDiv, 0);
        highlightMatchingDelims();
    } else {
        inputDiv.removeEventListener("keyup", matchDelimsKeyHandler);
        inputDiv.removeEventListener("click", highlightMatchingDelims);
        if (highlighted) {
            // Clear the highlighting:
            inputDiv.innerText = inputDiv.innerText;
            highlighted = false;
        }
    }
    inputDiv.focus();
}

enableMatchDelims(true);

/**
 * Filter keyboard events that trigger delimiter matching.
 * @param {KeyboardEvent} event - keyboard event to handle.
 */
function matchDelimsKeyHandler(event: { key: string | any[]; ctrlKey: any; }) {
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

const closeDelimToRegexp = { ")": /[()"]/g, "}": /[{}"]/g, ">>": /<<|>>|"/g, "end": /\bbegin\b|\bend\b|"/ig };
const openDelimToRegexp = { "(": /[()"]/g, "{": /[{}"]/g, "<<": /<<|>>|"/g, "begin": /\bbegin\b|\bend\b|"/ig };

const matchSpan = document.createElement("span"); // used to highlight matching delimiters.
matchSpan.style.textDecoration = "underline";
const errorSpan = document.createElement("span"); // used to highlight mismatched delimiters.
errorSpan.className = "error";

/**
 * If there is a closing delimiter immediately before or an opening delimiter immediately after
 * the caret then: if there is a matching delimiter then highlight the pair and their content
 * using underlining; if the delimiter is unmatched then highlight it as an error;
 * otherwise, remove any highlighting.
 * Run this function on events that normally move caret (i.e. mouse clicks and some keyup events).
 * BEWARE: editable <div> content may end with <br> and each line may be in a <div>.
 */
function highlightMatchingDelims() {
    // Abort if input is empty or text is selected:
    if (!inputDiv.firstChild || !selection.isCollapsed) return;
    // Get text before and after caret:
    const caretNode: Node = selection.anchorNode, caret: number = selection.anchorOffset;
    // Using a range would be better here, but Range.toString() ignores newlines, at least in Firefox.
    selection.setBaseAndExtent(inputDiv, 0, caretNode, caret);
    const textBefore: string = selection.toString();
    selection.setBaseAndExtent(caretNode, caret, inputDiv, inputDiv.childNodes.length);
    const textAfter: string = selection.toString();
    // Restore original selection in case it is not set later:
    selection.collapse(caretNode, caret);
    // Separate lines may be in <div> elements, which implicitly end with a <br/>, so...
    const atEOL: boolean = caretNode.parentNode !== inputDiv && (<Element>caretNode.parentNode).tagName === "DIV" &&
        caret === (<Text>caretNode).length && caretNode.parentNode.nextSibling !== null;
    if (textBefore) {
        // Check for matching delimiters closing immediately before caret.
        // The regexp flag i makes searching case-insensitive.
        let closeDelim: string | any[], openIndex = -1;
        const initialMatch = textBefore.match(/(?:[)}]|>>|\bend)$/i);
        if (initialMatch &&
            !((closeDelim = initialMatch[0].toLowerCase()) === "end" && /^(?:\w|\d)/.test(textAfter))) {
            const regexp = closeDelimToRegexp[closeDelim];
            let inString = false, closeCount = 0;
            const matches = [...textBefore.matchAll(regexp)];
            for (let index = matches.length - 1; index >= 0; index--) {
                const match = matches[index];
                if (inString) {
                    if (match[0] === '"') inString = false;
                    continue;
                }
                if (match[0] === '"') {
                    inString = true; continue;
                } else if (match[0].toLowerCase() === closeDelim) closeCount++;
                else {
                    closeCount--;
                    if (closeCount === 0) {
                        openIndex = match.index;
                        break;
                    }
                }
            }
            let span: Node;
            if (openIndex >= 0) {
                // Matching opening delimiter found.
                // Replace inputDiv contents with textBeforeOpen<matchSpan>textBeforeClose</matchSpan>textAfter:
                inputDiv.innerText = textBefore.substring(0, openIndex);
                matchSpan.innerText = textBefore.substring(openIndex);
                span = matchSpan;
            } else {
                // Unmatched closing delimiter immediately before caret.
                // Replace inputDiv contents with textBeforeClose<errorSpan>closeDelim</errorSpan>textAfter:
                inputDiv.innerText = textBefore.slice(0, -closeDelim.length);
                errorSpan.innerText = textBefore.slice(-closeDelim.length);
                span = errorSpan;
            }
            inputDiv.appendChild(span);
            // Set caret to end of span. (It *must* be within the span!)
            selection.collapse(span, span.childNodes.length);
            if (atEOL) inputDiv.appendChild(document.createElement("br"));
            appendText(textAfter);
            highlighted = true;
            return;
        }
    }
    if (textAfter) {
        // Check for matching delimiters opening immediately after caret.
        let openDelim: string | any[], closeIndex = -1;
        const initialMatch = textAfter.match(/^(?:[({]|<<|begin\b)/i);
        if (initialMatch &&
            !((openDelim = initialMatch[0].toLowerCase()) === "begin" && /(?:\w|\d)$/.test(textBefore))) {
            const regexp = openDelimToRegexp[openDelim];
            let inString = false, openCount = 0;
            for (const match of textAfter.matchAll(regexp)) {
                if (inString) {
                    if (match[0] === '"') inString = false;
                    continue;
                }
                if (match[0] === '"') {
                    inString = true; continue;
                } else if (match[0].toLowerCase() === openDelim) openCount++;
                else {
                    openCount--;
                    if (openCount === 0) {
                        closeIndex = match.index + match[0].length;
                        break;
                    }
                }
            }
            let span: Node;
            inputDiv.innerText = textBefore;
            if (atEOL) inputDiv.appendChild(document.createElement("br"));
            if (closeIndex >= 0) {
                // Matching closing delimiter found.
                // Replace inputDiv contents with textBefore<matchSpan>textAfterOpen</matchSpan>textAfterClose:
                matchSpan.innerText = textAfter.substring(0, closeIndex);
                inputDiv.appendChild(matchSpan);
                appendText(textAfter.substring(closeIndex));
                span = matchSpan;
            } else {
                // Unmatched opening delimiter immediately after caret.
                // Replace inputDiv contents with textBefore<errorSpan>openDelim</errorSpan>textAfterOpen:
                errorSpan.innerText = textAfter.substring(0, openDelim.length);
                inputDiv.appendChild(errorSpan);
                appendText(textAfter.substring(openDelim.length));
                span = errorSpan;
            }
            // Set caret to beginning of span:
            selection.collapse(span, 0);
            highlighted = true;
            return;
        }
    }
    // If text is highlighted then clear the highlighting.
    if (highlighted) {
        // Reset inputDiv content to plain text containing caret:
        inputDiv.innerText = textBefore;
        selection.collapse(inputDiv, inputDiv.childNodes.length);
        appendText(textAfter);
        inputDiv.normalize();
        highlighted = false;
    }
}

const tmpDiv = document.createElement("div");

/**
 * Convert newlines in text to <br/> elements and append to inputDiv.
 * @param {string} text - plain text.
 */
function appendText(text: string) {
    if (text) {
        tmpDiv.innerText = text;
        inputDiv.append(...tmpDiv.childNodes);
    }
}
