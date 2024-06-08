const mongoose = require("mongoose");
const express = require("express");
const Schema = mongoose.Schema;
const app = express();

app.use(express.static("client"));
app.use(express.json());

// Define student schema and model
const studentSchema = new Schema({
    institute: String,
    group: String,
    name: String,
    studyForm: String,
    phone: [String]
}, { versionKey: false });

const Student = mongoose.model("Student", studentSchema);

async function main() {
    try {
        // Connect to MongoDB
        await mongoose.connect("mongodb://127.0.0.1:27017/studentdb", {
            useNewUrlParser: true,
            useUnifiedTopology: true
        });

        // Start the server
        app.listen(3000, () => {
            console.log("Server is running on http://localhost:3000");
        });
        console.log("Connected to MongoDB");
    } catch (err) {
        console.error("Error connecting to MongoDB:", err);
    }
}

app.get("/api/students", async (req, res) => {
    try {
        const students = await Student.find({});
        res.send(students);
    } catch (err) {
        res.status(500).send(err);
    }
});

app.get("/api/students/:id", async (req, res) => {
    try {
        const id = req.params.id;
        const student = await Student.findById(id);
        if (student) res.send(student);
        else res.sendStatus(404);
    } catch (err) {
        res.status(500).send(err);
    }
});

app.post("/api/students", async (req, res) => {
    try {
        if (!req.body) return res.sendStatus(400);
        const { institute, group, name, studyForm, phone } = req.body;
        const student = new Student({ institute, group, name, studyForm, phone });
        await student.save();
        res.send(student);
    } catch (err) {
        res.status(500).send(err);
    }
});

app.delete("/api/students/:id", async (req, res) => {
    try {
        const id = req.params.id;
        const student = await Student.findByIdAndDelete(id);
        if (student) res.send(student);
        else res.sendStatus(404);
    } catch (err) {
        res.status(500).send(err);
    }
});

app.put("/api/students/:id", async (req, res) => {
    try {
        if (!req.body) return res.sendStatus(400);
        const id = req.params.id;
        const { institute, group, name, studyForm, phone } = req.body;
        const newStudent = { institute, group, name, studyForm, phone };
        const student = await Student.findOneAndUpdate({ _id: id }, newStudent, { new: true });
        if (student) res.send(student);
        else res.sendStatus(404);
    } catch (err) {
        res.status(500).send(err);
    }
});

main();

// Listen for process termination (ctrl-c)
process.on("SIGINT", async () => {
    try {
        await mongoose.disconnect();
        console.log("Application has stopped");
        process.exit();
    } catch (err) {
        console.error("Error during disconnection:", err);
        process.exit(1);
    }
});
