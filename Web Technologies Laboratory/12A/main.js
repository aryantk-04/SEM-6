import { Stack } from "./stack.js";
import { Queue } from "./queue.js";

window.onload = () => {
    const stack = new Stack();

    stack.push(1);
    stack.print();
    stack.push(2);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.print();

    const queue = new Queue();

    queue.enqueue(1);
    queue.print();
    queue.dequeue();
    queue.print();
    queue.dequeue();
    queue.print();
};
