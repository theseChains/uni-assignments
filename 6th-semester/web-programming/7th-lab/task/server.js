var express = require("express"),
    http = require("http"),
    app = express(),
    students = [
        {
            "institute": "Институт информационных технологий",
            "group": "Группа 101",
            "name": "Иванов Иван Иванович",
            "studyForm": "бюджет",
            "phone": ["+7 (123) 456-7891", "+7 (987) 654-3210"]
        },
        {
            "institute": "Институт информационных технологий",
            "group": "Группа 101",
            "name": "Петров Петр Петрович",
            "studyForm": "бюджет",
            "phone": ["+7 (111) 222-3333"]
        },
        {
            "institute": "Институт гуманитарных наук",
            "group": "Группа 201",
            "name": "Сидорова Мария Ивановна",
            "studyForm": "платное",
            "phone": ["+7 (555) 666-7777", "+7 (987) 654-3210"]
        }
    ];

app.use(express.static(__dirname + "/client"));
http.createServer(app).listen(3000);
app.get("/students.json", function (req, res) {
    res.json(students);
});

app.use(express.urlencoded());
app.post("/students", function (req, res) {
    console.log("Данные были отправлены на сервер!");
    var newStudent = req.body;
    console.log(newStudent);
    students.push(newStudent);
    res.json({"message": "Вы размещаетесь на сервере!"});
});
