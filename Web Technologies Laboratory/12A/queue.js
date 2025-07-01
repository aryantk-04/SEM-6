export class Queue {
    constructor() {
        this.items = [];
    }
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        this.items.shift();
    }
    print() {
        document.getElementById("queueOutput").innerText += "Queue: " + this.items.join(', ') + "\n";
    }
}
