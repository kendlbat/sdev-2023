import express from "express";

const app = express();
app.use(express.json());
app.use(express.static("public"));

let surveys = [];

let answers = {

};

app.get("/respond/:answer", (req, res) => {
    let answer = req.params.answer;
    if (answer != "yes" && answer != "no")
        return res.status(400).send("Invalid answer");

    if (answers[req.ip])
        return res.status(400).send("You already answered");

    answers[req.ip] = answer;

    res.send("<p>Answer recorded</p><a href='/'>Back to survey</a>");
});

app.get("/results", (req, res) => {
    return res.json(Object.values(answers).reduce((acc, cur) => {
        acc[cur]++;
        return acc;
    }, { "yes": 0, "no": 0 }));
});

app.get("/reset/6789098765rt6789876tre", (req, res) => {
    answers = {};
    res.send("Reset successful");
});

app.listen(3000, () => {
    console.log("Server started");
});