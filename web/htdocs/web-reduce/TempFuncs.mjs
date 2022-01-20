/**
 * Support for the Template and Functions menus.
 * @module TempFuncs
 */

// Imported variables:
import { inputDiv } from "./GenJS/Main.js";

// Imported functions:
import { sendToReduce, sendToReduceAndEcho } from "./GenJS/Main.js";

/**
 * Implement the modal-dialogue custom element.
 */
class ModalDialogue extends HTMLElement {
	constructor() {
		super();
		// Handle <modal-dialogue> funcsHeader attribute:
		if (this.hasAttribute("specfnsHeader")) {
			const specfnsHeader = document.getElementById("special-functions-header").cloneNode(true).content.children;
			this.prepend(...specfnsHeader);
		}
		// Wrap the template content around the content of this <modal-dialogue> element.
		const templateContent = document.getElementById("modal-dialogue-template").content.firstElementChild.cloneNode(true);
		const modalBody = templateContent.querySelector("div.modal-body");
		modalBody.append(...this.children);
		this.appendChild(templateContent);
		// Handle other <modal-dialogue> attributes:
		const dialogueId = this.getAttribute("dialogueId");
		templateContent.setAttribute("id", dialogueId);
		const dialogueLabel = dialogueId + "Label";
		templateContent.setAttribute("aria-labelledby", dialogueLabel);
		const modalTitle = templateContent.querySelector("h5");
		modalTitle.setAttribute("id", dialogueLabel);
		modalTitle.innerText = this.getAttribute("dialogueTitle");
		const dialogueSize = this.getAttribute("dialogueSize");
		if (dialogueSize)
			templateContent.querySelector("div.modal-dialog").classList.add(dialogueSize);
	}
}

// All modal-dialogue elements must be loaded before the ModalDialogue class is instantiated, so...
window.addEventListener("load", () =>
	// A custom element name MUST contain a hyphen!
	customElements.define("modal-dialogue", ModalDialogue));

/**
 * The Template and Functions classes inherit from this class.
 */
class TempFuncs {
	constructor(dialogueId) {
		this.dialogue = document.getElementById(dialogueId);
		this.inputs = this.dialogue.querySelectorAll("input[type=text]");
		this.buttons = this.dialogue.querySelectorAll("div.modal-footer > button");

		this.buttons[0].addEventListener("click", () => this.resetButtonAction());
		// Just using the function this.resetButtonAction fails because this in resetButtonAction refers to the wrong object!

		this.dialogue.addEventListener("hidden.bs.modal", () => inputDiv.focus());

		// Save initial input values:
		this.initialInputValues = [];
		for (let i = 0; i < this.inputs.length; i++)
			this.initialInputValues.push(this.inputs[i].value);
	}

	/**
	 * Reset the values of all input fields.
	 */
	resetButtonAction() {
		for (let i = 0; i < this.inputs.length; i++)
			this.inputs[i].value = this.initialInputValues[i];
	}

	/**
	 * Insert text in inputDiv at caret or replace a selection if there is one.
	 */
	inputDivInsert(text) {
		let selBeg = 0;
		const selProps = preMenuSelectionProps;
		const insertionNode = selProps.anchorNode;
		if (insertionNode === inputDiv) {
			// Whole node rather than content selected:
			inputDiv.textContent = text;
		} else {
			// Content selected:
			if (!(inputDiv.contains(insertionNode) && inputDiv.contains(selProps.focusNode))) {
				alert("Invalid selection");
				return;
			}
			selBeg = selProps.anchorOffset;
			let selEnd = selProps.focusOffset;
			if (selBeg > selEnd) { let tmp = selBeg; selBeg = selEnd; selEnd = tmp; }
			const cont = insertionNode.textContent;
			inputDiv.textContent = cont.substr(0, selBeg) + text + cont.substr(selEnd);
		}
		const index = text.search(/\bws\b/), selection = getSelection();
		if (index >= 0) {
			// Select ws if available within inserted text:
			selection.setBaseAndExtent(inputDiv.firstChild, selBeg + index, inputDiv.firstChild, selBeg + index + 2);
		} else {
			// Otherwise, set caret to end of insertion:
			selection.collapse(inputDiv.firstChild, selBeg + text.length);
		}
	}
}

/**
 * Specific template classes inherit from this class.
 */
export class Template extends TempFuncs {
	constructor(templateName) {
		super(templateName.replace(/\s+/g, ""));
		this.pattern = this.dialogue.querySelector("div.pattern");
		this.alertHeader = `${templateName} Error\n`;

		this.buttons[1].addEventListener("click", () => {
			// try {
			// No fields are required:
			this.checkNonEmpty = false;
			this.inputDivInsert(this.result());
			this.buttons[3].click();
			// } catch (ignored) { }
		});

		this.buttons[2].addEventListener("click", () => {
			try {
				// Check required fields provided:
				this.checkNonEmpty = true;
				sendToReduceAndEcho(this.result() + ";");
				this.buttons[3].click();
			} catch (ignored) { }
		});
	}

	resetButtonAction() {
		// This seems to be necessary!
		super.resetButtonAction();
	}

	getValueCheckNonEmpty(input) {
		const value = input.value.trim();
		if (this.checkNonEmpty && !value) {
			alert(this.alertHeader +
				"A required field is empty.");
			throw new Error("empty field");
		}
		return value;
	}
}

/**
 * Specific functions classes inherit from this class.
 */
export class Functions extends TempFuncs {
	constructor(functionsId) {
		super(functionsId);
		this.selectedFunction = undefined;

		const functions = this.dialogue.querySelectorAll("td");
		for (const fn of functions)
			fn.addEventListener("click", event => {
				if (this.selectedFunction) this.selectedFunction.classList.remove("selected");
				this.selectedFunction = fn;
				this.selectedFunction.classList.add("selected");
			});

		this.buttons[1].addEventListener("click", () => {
			if (this.selectedFunction) this.inputDivInsert(this.result());
			this.buttons[3].click();
		});

		this.buttons[2].addEventListener("click", () => {
			if (this.selectedFunction) sendToReduceAndEcho(this.result() + ";");
			this.buttons[3].click();
		});
	}

	resetButtonAction() {
		super.resetButtonAction();
		if (this.selectedFunction) {
			this.selectedFunction.classList.remove("selected");
			this.selectedFunction = undefined;
		}
	}

	result() {
		const values = [...this.selectedFunction.getElementsByTagName("input")]
			.map(el => el.value.trim());
		return `${this.selectedFunction.dataset.function}(${values.join()})`;
	}
}

// Template and Function menu support:
let preMenuSelectionProps; // set when drop-down menus are shown

/**
* Save relevant properties of the current Selection object.
*/
function saveSelectionProps() {
	// A Selection object represents the range of text selected by the user or the current position of the caret.
	const selection = getSelection();
	preMenuSelectionProps = {
		anchorNode: selection.anchorNode,
		anchorOffset: selection.anchorOffset,
		focusNode: selection.focusNode,
		focusOffset: selection.focusOffset
	}
}

document.getElementById("TemplatesMenuLink")
	.addEventListener('show.bs.dropdown', saveSelectionProps);
document.getElementById("FunctionsMenuLink")
	.addEventListener('show.bs.dropdown', saveSelectionProps);
