const express = require('express');
const path = require('path');
const app = express();

app.get('/', (req, res) => {
    res.send(
        `<h3>Choose Department</h3>
        <a href = "/cse">Computer Science Engineering</a>
        <a href = "/ece">Electronics and Communications Engineering</a>
        <a href = "/me">Mechanical Engineering</a>`
    );
});

app.get("/cse", (req, res) => {
    res.sendFile(path.join(__dirname, 'cse.html'));
})

app.get("/ece", (req, res) => {
    res.sendFile(path.join(__dirname, 'ece.html'));
})

app.get("/me", (req, res) => {
    res.sendFile(path.join(__dirname, 'me.html'));
})

app.listen(3000);
