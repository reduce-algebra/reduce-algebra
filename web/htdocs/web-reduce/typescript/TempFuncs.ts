/**
 * Support for the Template and Functions menus.
 * @module TempFuncs
 */

// Imported variables:
import { inputDiv } from "./Main.js";

// Imported functions:
import { refocus, sendToReduce, sendToReduceAndEcho } from "./Main.js";

/**
 * Class implementing the modal-dialogue custom element.
 */
class ModalDialogue extends HTMLElement {
	constructor() {
		super();
		// Handle <modal-dialogue> funcsHeader attribute:
		if (this.hasAttribute("specfnsHeader")) {
			const specfnsHeader = (document.getElementById("special-functions-header").cloneNode(true) as HTMLTemplateElement)
				.content.children;
			this.prepend(...specfnsHeader);
		}
		// Wrap the template content around the content of this <modal-dialogue> element.
		const templateContent = (document.getElementById("modal-dialogue-template") as HTMLTemplateElement)
			.content.firstElementChild.cloneNode(true) as HTMLElement;
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
 * Class representing a generic template or function dialogue,
 * which the Template and Functions classes extend.
 */
class TempFuncs {
	dialogue: HTMLElement;
	inputs: NodeListOf<HTMLInputElement>;
	buttons: NodeListOf<HTMLButtonElement>;
	initialInputValues: string[];

	/**
	 * Create a generic template or function dialogue.
	 * @param {string} dialogueId - The id attribute of the modal-dialogue element.
	 */
	constructor(dialogueId: string) {
		this.dialogue = document.getElementById(dialogueId);
		this.inputs = this.dialogue.querySelectorAll<HTMLInputElement>("input[type=text]");
		this.buttons = this.dialogue.querySelectorAll<HTMLButtonElement>("div.modal-footer > button");

		this.buttons[0].addEventListener("click", () => this.resetButtonAction());
		// Just using the function this.resetButtonAction fails because this in resetButtonAction refers to the wrong object!

		// this.dialogue.addEventListener("hidden.bs.modal", () => inputDiv.focus());

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
	 * @param {string} text - The text to insert.
	 */
	inputDivInsert(text: string) {
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
 * Class representing a generic template dialogue,
 * which specific template classes extend.
 * @extends TempFuncs
 */
export class Template extends TempFuncs {
	pattern: HTMLDivElement;
	alertHeader: string;
	checkNonEmpty: boolean;
	result?(): string;

	/**
	 * Create a generic template dialogue.
	 * @param {string} templateName - The id attribute of the modal-dialogue element, but with added spaces.
	 */
	constructor(templateName: string) {
		super(templateName.replace(/\s+/g, ""));
		this.pattern = this.dialogue.querySelector("div.pattern");
		this.alertHeader = `${templateName} Error\n`;

		// Edit button action:
		this.buttons[1].addEventListener("click", () => {
			try {
				// No fields are normally required:
				this.checkNonEmpty = false;
				this.inputDivInsert(this.result());
				this.buttons[3].click();
			} catch (ignored) { }
			inputDiv.focus(); // always return focus to input editor
		});

		// Evaluate button action:
		this.buttons[2].addEventListener("click", () => {
			try {
				// Check required fields provided:
				this.checkNonEmpty = true;
				sendToReduceAndEcho(this.result() + ";");
				this.buttons[3].click();
			} catch (ignored) { }
			refocus(); // return focus to input editor on desktop, I/O Display on mobile
		});
	}

	/**
	 * Reset the values of all input fields.
	 */
	resetButtonAction() {
		// This seems to be necessary!
		super.resetButtonAction();
	}

	/**
	 * Get the value of an input element and check that it is not empty.
	 * Throw an error if empty.
	 * @param {HTMLInputElement} input - The input element.
	 * @returns {string} The non-empty value of the input element.
	 */
	getValueCheckNonEmpty(input: HTMLInputElement, checkNonEmpty?: boolean) {
		const value = input.value.trim();
		if ((checkNonEmpty || this.checkNonEmpty) && value.length === 0) {
			alert(this.alertHeader +
				"A required field is empty.");
			throw new Error("empty field");
		}
		return value;
	}
}

/**
 * Class representing a generic function dialogue,
 * which specific function classes extend.
 * @extends TempFuncs
 */
export class Functions extends TempFuncs {
	selectedFunction: HTMLElement;

	/**
	 * Create a generic function dialogue.
	 * @param {string} dialogueId - The id attribute of the modal-dialogue element.
	 */
	constructor(functionsId: string) {
		super(functionsId);
		this.selectedFunction = undefined;

		const functions = this.dialogue.querySelectorAll("div.function-templates>div") as NodeListOf<HTMLElement>;
		for (const fn of functions)
			fn.addEventListener("click", event => {
				if (this.selectedFunction) this.selectedFunction.classList.remove("selected");
				this.selectedFunction = fn;
				this.selectedFunction.classList.add("selected");
			});

		// Edit button action:
		this.buttons[1].addEventListener("click", () => {
			if (this.selectedFunction) this.inputDivInsert(this.result());
			this.buttons[3].click();
			inputDiv.focus(); // always return focus to input editor
		});

		// Evaluate button action:
		this.buttons[2].addEventListener("click", () => {
			if (this.selectedFunction) sendToReduceAndEcho(this.result() + ";");
			this.buttons[3].click();
			refocus(); // return focus to input editor on desktop, I/O Display on mobile
		});
	}

	/**
	 * Reset the values of all input fields.
	 */
	resetButtonAction() {
		super.resetButtonAction();
		if (this.selectedFunction) {
			this.selectedFunction.classList.remove("selected");
			this.selectedFunction = undefined;
		}
	}

	/**
	 * Get the REDUCE input representing the selected function application.
	 * @returns {string} The REDUCE input string.
	 */
	result(): string {
		const values = [...this.selectedFunction.getElementsByTagName("input")]
			.map(el => el.value.trim());
		return `${this.selectedFunction.dataset.function}(${values.join()})`;
	}
}

// Template and Function menu support:
let preMenuSelectionProps: {
	anchorNode: Node,
	anchorOffset: number,
	focusNode: Node,
	focusOffset: number
}; // set when drop-down menus are shown

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
