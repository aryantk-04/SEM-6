const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const app = express();

app.use(bodyParser.urlencoded({extended:true}));
app.use(express.static('public'));

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});

function vowelCounter(sentence) {
    const count = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0};
    
    for (let i = 0; i < sentence.length; i++) {
        if ('aeiou'.includes(sentence[i])) {
            count[sentence[i]]++;
        }
    }
    return `a: ${count.a} e: ${count.e} i: ${count.i} o: ${count.o} u: ${count.u}`;
}

app.post('/count', (req, res) => {
    const result = vowelCounter(req.body.text);
    res.send(`Result: ${result}`);
});

app.listen(3000);
