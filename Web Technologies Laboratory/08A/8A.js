function vowelCounter(sentence) {
    const count = {'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0};

    for (let i = 0; i < sentence.length; i++) {
        if ('aeiou'.includes(sentence[i])) {
            count[sentence[i]]++;
        }
    }
    console.log(`a: ${count.a} e: ${count.e} i: ${count.i} o: ${count.o} u: ${count.u}`);
}

vowelCounter("Le Tour De France");
