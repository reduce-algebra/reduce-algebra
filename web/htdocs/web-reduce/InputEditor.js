// Input editor code

const inputList = [];
let inputListIndex = 0;
let maxInputListIndex = -1;

function sendInput(event) {
    // Strip trailing white space from the input:
    let text = inputTextArea.value.replace(/\s+^/, "");
    if (text.length > 0) {
        if (!event.shiftKey) {
            // Ensure the input ends with a terminator:
            let c = text[text.length - 1];
            if (!(c == ';' || c == '$')) text += ";";
        }
        sendToOutputDiv(text);
        sendToReduce(text);
        inputListIndex = inputList.push(text);
        maxInputListIndex = inputListIndex - 1;
        inputTextArea.value = "";
        earlierButton.disabled = false;
        laterButton.disabled = true;
    }
    inputTextArea.focus()
}

sendButton.addEventListener('click', sendInput);

function earlierInput() {
    if (inputListIndex > 0) {
        inputTextArea.value = inputList[--inputListIndex];
        if (inputListIndex <= maxInputListIndex)
            laterButton.disabled = false;
    }
    if (inputListIndex == 0)
        earlierButton.disabled = true;
    inputTextArea.focus()
}

earlierButton.addEventListener('click', earlierInput);

function laterInput() {
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
    inputTextArea.focus()
}

laterButton.addEventListener('click', laterInput);

inputTextArea.addEventListener("keydown", event => {
    if (event.ctrlKey) {
        switch (event.key) {
            case "Enter":
                sendInput(event);
                break;
            case "ArrowUp":
                earlierInput();
                break;
            case "ArrowDown":
                laterInput();
        }
    }
});
