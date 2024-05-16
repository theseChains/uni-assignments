let main = function (studentObjects) {
    "use strict";

    let students = studentObjects.map(function (student) {
        return { institute: student.institute, group: student.group, name: student.name, studyForm: student.studyForm };
    });

    let organizeByProperty = function (studentObjects, property) {
        let organizedData = {};

        studentObjects.forEach(function (student) {
            let key = student[property];
            if (!organizedData.hasOwnProperty(key)) {
                organizedData[key] = [];
            }

            organizedData[key].push(student);
        });

        return organizedData;
    }

    let organizeByPhoneNumber = function (studentObjects) {
        let studentsByPhone = {};

        studentObjects.forEach(function (student) {
            student.phone.forEach(function (phoneNumber) {
                if (!studentsByPhone.hasOwnProperty(phoneNumber)) {
                    studentsByPhone[phoneNumber] = [];
                }
                console.log("phone number: " + phoneNumber);
                console.log("student: " + student.name);
                studentsByPhone[phoneNumber].push(student);
            });
        });

        return studentsByPhone;
    }

    let $content;

    let organizeAndDisplay = function (studentObjects, property) {
        let organizedData;
        if (property === 'phone') {
            organizedData = organizeByPhoneNumber(studentObjects);
        } else {
            organizedData = organizeByProperty(studentObjects, property);
        }

        $content = $("<ul>");
        for (let key in organizedData) {
            $content.append($("<h2>").text(key));

            organizedData[key].forEach(function(student) {
                let info;
                if (property === 'institute') {
                    info = student.name + ", " + student.group + ", " + student.studyForm;
                } else if (property === 'group') {
                    info = student.name + ", " + student.institute + ", " + student.studyForm;
                } else if (property === 'phone') {
                    info = student.name + ", " + student.group + ", " + student.institute + ", " + student.studyForm;
                }
                $content.append($("<li>").text(info));
            });
        }
    };

    $(".tabs a span").toArray().forEach(function (element) {
        $(element).on("click", function () {
            let $element = $(element);

            $(".tabs a span").removeClass("active");
            $element.addClass("active");
            $("main .content").empty();

            if ($element.parent().is(":nth-child(1)")) {
                $content = $("<ul>");
                for (let i = students.length - 1; i >= 0; i--) {
                    let student = students[i];
                    let info = student.institute + ", " + student.group + ", " + student.name + ", " + student.studyForm;
                    $content.append($("<li>").text(info));
                }
            } else if ($element.parent().is(":nth-child(2)")) {
                $content = $("<ul>");
                students.forEach(function (student) {
                    let info = student.institute + ", " + student.group + ", " + student.name + ", " + student.studyForm;
                    $content.append($("<li>").text(info));
                });
            } else if ($element.parent().is(":nth-child(3)")) {
                organizeAndDisplay(studentObjects, 'institute');
            } else if ($element.parent().is(":nth-child(4)")) {
                organizeAndDisplay(studentObjects, 'group');
            } else if ($element.parent().is(":nth-child(5)")) {
                organizeAndDisplay(studentObjects, 'phone');
            } else if ($element.parent().is(":nth-child(6)")) {
                $content = $("<div>");
                $content.append($("<p>").text("Добавьте нового студента"));

                $content.append($("<div>").text("ФИО:"));
                let $nameInput = $("<input>");
                $content.append($nameInput);

                $content.append($("<div>").text("Институт:"));
                let $instituteInput = $("<input>");
                $content.append($instituteInput);

                $content.append($("<div>").text("Группа:"));
                let $groupInput = $("<input>");
                $content.append($groupInput);

                $content.append($("<div>").text("Форма обучения:"));
                let $studyFormInput = $("<input>");
                $content.append($studyFormInput);

                $content.append($("<div>").text("Номера телефонов (через запятую):"));
                let $phoneNumbersInput = $("<input>");
                $content.append($phoneNumbersInput);

                $content.append($("<div>"));
                let $button = $("<button>");
                $content.append($button.text("Добавить"));

                let addStudent = function() {
                    if ($nameInput.val() === "" || $instituteInput.val() === "" ||
                        $groupInput.val() === "" || $phoneNumbersInput.val() === "") {
                        return;
                    }

                    let newStudent = { institute: $instituteInput.val(),
                                       group: $groupInput.val(),
                                       name: $nameInput.val(),
                                       studyForm: $studyFormInput.val() };
                    students.push(newStudent);
                    studentObjects.push({
                        "institute": $instituteInput.val(),
                        "group": $groupInput.val(),
                        "name": $nameInput.val(),
                        "studyForm": $studyFormInput.val(),
                        "phone": $phoneNumbersInput.val().split(",")
                    });

                    $instituteInput.val("");
                    $groupInput.val("");
                    $nameInput.val("");
                    $studyFormInput.val("");
                    $phoneNumbersInput.val("");
                };

                $button.on("click", function (event) {
                    addStudent();
                })
            }
            $("main .content").append($content);
            return false;
        });
    });
    $(".tabs a:first-child span").trigger("click");
};

$(document).ready(function () {
    $.getJSON("students.json", function (studentObjects) {
        main(studentObjects);
    });
});
