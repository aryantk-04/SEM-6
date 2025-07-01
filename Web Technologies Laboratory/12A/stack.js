export class Stack {
    constructor() {
        this.items = [];
    }
    push(element) {
        this.items.push(element);
    }
    pop() {
        this.items.pop();
    }
    print() {
        document.getElementById("stackOutput").innerText += "Stack: " + this.items.join(', ') + "\n";
    }
}
