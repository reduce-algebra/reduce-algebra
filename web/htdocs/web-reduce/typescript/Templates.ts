// Imported classes:
import { Template } from "./TempFuncs.js";

// Imported functions:
import { loadPackage } from "./Main.js";

class ODESolveTemplate extends Template {
    constructor() {
        super("ODESolve Template");
        this.dialogue.addEventListener("show.bs.modal", () => loadPackage("odesolve"));
    }

    result() {
        let ode = this.getValueCheckNonEmpty(this.inputs[0]);
        // Dep and ind vars both optional:
        let y = this.inputs[1].value.trim(), x: string;
        // Conditions (optional):
        let conds = this.inputs[3].value.trim();
        // ' means d/dx.
        if (ode.includes("'") || conds.includes("'")) {
            function deprime(text: string) {
                return text.replace(/(\w+)(\'+)/g, (match: string, p1: string, p2: string) => {
                    let deriv = `df(${p1},${x}`;
                    const order = p2.length;
                    if (order > 1) deriv += "," + order;
                    return deriv + ")";
                });
            }
            x = this.getValueCheckNonEmpty(this.inputs[2], true); // always check
            ode = deprime(ode);
            conds = deprime(conds);
        } else
            x = this.inputs[2].value.trim();
        let text = "odesolve(" + ode;
        if (x.length > 0) {
            if (y.length == 0) y = "{}";
            text += ", " + y + ", " + x;
        } else if (y.length > 0)
            text += ", " + y;
        if (conds.length > 0)
            text += ", {" + conds + "}";
        // Options:
        const optEls = this.pattern.querySelectorAll<HTMLInputElement>("input[type=checkbox]:checked");
        for (const optEl of optEls) {
            const option = this.pattern.querySelector<HTMLInputElement>(`label[for=${optEl.id}]`).innerText;
            text += ", " + (option == "tracing+" ? "tracing=1" : option);
        }
        return text + ")";
    }

    /**
     * Reset the values of all input fields.
     */
    resetButtonAction() {
        super.resetButtonAction();
        this.pattern.querySelectorAll<HTMLInputElement>("input[type=checkbox]:checked")
            .forEach(optEl => optEl.checked = false);
    }
}

window.addEventListener("load", () => new ODESolveTemplate());
