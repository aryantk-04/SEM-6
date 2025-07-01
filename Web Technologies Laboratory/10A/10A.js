const express = require('express');
const app = express();

function logger(req, res, next) {
    console.log("Logged");
    console.log(`Date: ${new Date()} Method: ${req.method} URL: ${req.url}`);
    next();
}

app.use(logger);

let count = 0;

function counter(req, res, next) {
    count++;
    next();
}

app.use(counter);

app.get('/', (req, res) => {
    res.send(`<p>You have visted this page ${count} times`);
});

app.listen(3000);
