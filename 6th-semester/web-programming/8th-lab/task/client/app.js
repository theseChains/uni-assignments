var main = function () {
    "use strict";

    $(".tabs a span").toArray().forEach(function (element) {
        $(element).on("click", function (event) {
            event.preventDefault();

            var $element = $(element),
                $content;
            $(".tabs a span").removeClass("active");
            $element.addClass("active");
            $("main .content").empty();

            // Новые -> Старые.
            if ($element.parent().is(":nth-child(1)")) {
                fetch("api/students", {
                    method: "GET",
                    headers: { "Accept": "application/json" }
                })
                    .then(function (response) {
                        if (response.ok) {
                            return response.json();
                        } else {
                            throw new Error('Ошибка получения данных');
                        }
                    })
                    .then(function (students) {
                        $content = $("<div>");
                        students.reverse();
                        students.forEach(function (item) {
                            var $infoClassDiv = $("<div>").addClass("infoClass");

                            $infoClassDiv.append($("<h4>").text("ФИО: " + item.name));
                            $infoClassDiv.append($("<h4>").text("Институт: " + item.institute));
                            $infoClassDiv.append($("<h4>").text("Группа: " + item.group));
                            $infoClassDiv.append($("<h4>").text("Форма обучения: " + item.studyForm));
                            $infoClassDiv.append($("<p>").text("Телефон(-ы):"));
                            var $innerUl = $("<ul>");
                            item.phone.forEach(function (phone) {
                                var $innerLi = $("<li>").text(phone);
                                $innerUl.append($innerLi);
                            });
                            $infoClassDiv.append($innerUl);
                            $content.append($infoClassDiv);
                        });
                        $("main .content").append($content);
                    })
                    .catch(function (error) {
                        console.error('Произошла ошибка при получении данных:', error);
                    });

            // Старые -> Новые.
            } else if ($element.parent().is(":nth-child(2)")) {
                fetch("api/students", {
                    method: "GET",
                    headers: { "Accept": "application/json" }
                })
                    .then(function (response) {
                        if (response.ok) {
                            return response.json();
                        } else {
                            throw new Error('Ошибка получения данных');
                        }
                    })
                    .then(function (students) {
                        $content = $("<div>");
                        students.forEach(function (item) {
                            var $infoClassDiv = $("<div>").addClass("infoClass");

                            $infoClassDiv.append($("<h4>").text("ФИО: " + item.name));
                            $infoClassDiv.append($("<h4>").text("Институт: " + item.institute));
                            $infoClassDiv.append($("<h4>").text("Группа: " + item.group));
                            $infoClassDiv.append($("<h4>").text("Форма обучения: " + item.studyForm));
                            $infoClassDiv.append($("<p>").text("Телефон(-ы):"));
                            var $innerUl = $("<ul>");
                            item.phone.forEach(function (phone) {
                                var $innerLi = $("<li>").text(phone);
                                $innerUl.append($innerLi);
                            });
                            $infoClassDiv.append($innerUl);
                            $content.append($infoClassDiv);
                        });
                        $("main .content").append($content);
                    })
                    .catch(function (error) {
                        console.error('Произошла ошибка при получении данных:', error);
                    });

            // Группировка по институту.
            } else if ($element.parent().is(":nth-child(3)")) {
                fetch("api/students", {
                    method: "GET",
                    headers: { "Accept": "application/json" }
                })
                    .then(function (response) {
                        if (response.ok) {
                            return response.json();
                        } else {
                            throw new Error('Ошибка получения данных');
                        }
                    })
                    .then(function (students) {
                        var institutes = {};
                        students.forEach(function (item) {
                            if (institutes.hasOwnProperty(item.institute)) {
                                institutes[item.institute].push(item);
                            } else {
                                institutes[item.institute] = [item];
                            }
                        });

                        $content = $("<div>");
                        for (var institute in institutes) {
                            if (institutes.hasOwnProperty(institute)) {
                                var $instituteClassDiv = $("<div>").addClass("instituteClass");
                                $instituteClassDiv.append($("<p>").text("Институт: " + institute));
                                var $innerContent = $("<div>");
                                institutes[institute].forEach(function (student) {
                                    var $infoClassDiv = $("<div>").addClass("infoClass");
                                    $infoClassDiv.append($("<h4>").text("ФИО: " + student.name));
                                    $infoClassDiv.append($("<h4>").text("Группа: " + student.group));
                                    $infoClassDiv.append($("<h4>").text("Форма обучения: " + student.studyForm));
                                    $innerContent.append($infoClassDiv);
                                });
                                $instituteClassDiv.append($innerContent);
                                $content.append($instituteClassDiv);
                            }
                        }
                        $("main .content").append($content);
                    })
                    .catch(function (error) {
                        console.error('Произошла ошибка при получении данных:', error);
                    });
            // Группировка по ФИО и группе.
            } else if ($element.parent().is(":nth-child(4)")) {
                fetch("api/students", {
                    method: "GET",
                    headers: { "Accept": "application/json" }
                })
                    .then(function (response) {
                        if (response.ok) {
                            return response.json();
                        } else {
                            throw new Error('Ошибка получения данных');
                        }
                    })
                    .then(function (students) {
                        var groups = {};

                        students.forEach(function (item) {
                            var key = item.group;
                            if (groups.hasOwnProperty(key)) {
                                groups[key].push(item);
                            } else {
                                groups[key] = [item];
                            }
                        });

                        $content = $("<div>");
                        for (var key in groups) {
                            if (groups.hasOwnProperty(key)) {
                                var $groupClassDiv = $("<div>").addClass("groupClass");
                                $groupClassDiv.append($("<p>").text("Группа: " + key));

                                groups[key].forEach(function (student) {
                                    var $infoClassDiv = $("<div>").addClass("infoClass");
                                    $infoClassDiv.append($("<h4>").text("ФИО: " + student.name));
                                    $infoClassDiv.append($("<h4>").text("Институт: " + student.institute));
                                    $infoClassDiv.append($("<h4>").text("Форма обучения: " + student.studyForm));
                                    $infoClassDiv.append($("<p>").text("Телефон(-ы):"));
                                    var $innerUl = $("<ul>");
                                    student.phone.forEach(function (phone) {
                                        var $innerLi = $("<li>").text(phone);
                                        $innerUl.append($innerLi);
                                    });
                                    $infoClassDiv.append($innerUl);
                                    $groupClassDiv.append($infoClassDiv);
                                });
                                $content.append($groupClassDiv);
                            }
                        }
                        $("main .content").append($content);
                    })
                    .catch(function (error) {
                        console.error('Произошла ошибка при получении данных:', error);
                    });

            // Группировка по телефону.
            } else if ($element.parent().is(":nth-child(5)")) {
                fetch("api/students", {
                    method: "GET",
                    headers: { "Accept": "application/json" }
                })
                    .then(function (response) {
                        if (response.ok) {
                            return response.json();
                        } else {
                            throw new Error('Ошибка получения данных');
                        }
                    })
                    .then(function (students) {
                        var phones = {};

                        students.forEach(function (item) {
                            item.phone.forEach(function (phone) {
                                if (phones.hasOwnProperty(phone)) {
                                    phones[phone].push(item);
                                } else {
                                    phones[phone] = [item];
                                }
                            });
                        });

                        $content = $("<div>");
                        for (var phone in phones) {
                            if (phones.hasOwnProperty(phone)) {
                                var $phoneClassDiv = $("<div>").addClass("phoneClass");
                                $phoneClassDiv.append($("<p>").text("Телефон: " + phone));

                                phones[phone].forEach(function (student) {
                                    var $infoClassDiv = $("<div>").addClass("infoClass");
                                    $infoClassDiv.append($("<h4>").text("ФИО: " + student.name));
                                    $infoClassDiv.append($("<h4>").text("Институт: " + student.institute));
                                    $infoClassDiv.append($("<h4>").text("Группа: " + student.group));
                                    $infoClassDiv.append($("<h4>").text("Форма обучения: " + student.studyForm));
                                    $phoneClassDiv.append($infoClassDiv);
                                });
                                $content.append($phoneClassDiv);
                            }
                        }
                        $("main .content").append($content);
                    })
                    .catch(function (error) {
                        console.error('Произошла ошибка при получении данных:', error);
                    });

            // Форма для добавления/изменения записи.
            } else if ($element.parent().is(":nth-child(6)")) {
                $("main .content").empty();
                // Форма ввода.
                const $form = $("<form>").attr("id", "dataForm");
                $form.append(
                    $("<label>").text("ФИО:"),
                    $("<input>").attr({ type: "text", id: "name", name: "name" }),
                    $("<br>"),
                    $("<label>").text("Институт:"),
                    $("<input>").attr({ type: "text", id: "institute", name: "institute" }),
                    $("<br>"),
                    $("<label>").text("Группа:"),
                    $("<input>").attr({ type: "text", id: "group", name: "group" }),
                    $("<br>"),
                    $("<label>").text("Форма обучения:"),
                    $("<input>").attr({ type: "text", id: "studyForm", name: "studyForm" }),
                    $("<br>"),
                    $("<label>").text("Телефон(-ы):"),
                    $("<input>").attr({ type: "text", id: "phone", name: "phone" }),
                    $("<br>"),
                    $("<button>").attr({ type: "button", id: "saveBtn" }).addClass("btn").text("Сохранить")
                );

                $("main .content").append($form);

                // Обработчик для кнопки сохранения.
                $("#saveBtn").on("click", function () {
                    const name = $("#name").val().trim();
                    const institute = $("#institute").val().trim();
                    const group = $("#group").val().trim();
                    const studyForm = $("#studyForm").val().trim();
                    const phone = $("#phone").val().trim().split(/\s*,\s*/);

                    if (!name || !institute || !group || !studyForm || !phone.length) {
                        alert("Пожалуйста, заполните все поля");
                        return;
                    }

                    const data = {
                        name: name,
                        institute: institute,
                        group: group,
                        studyForm: studyForm,
                        phone: phone
                    };

                    const id = $("#dataForm").data("current-id");

                    const method = id ? "PUT" : "POST";
                    const url = id ? `api/students/${id}` : "api/students";

                    fetch(url, {
                        method: method,
                        headers: { "Content-Type": "application/json" },
                        body: JSON.stringify(data)
                    })
                        .then(response => {
                            if (response.ok) {
                                loadData();
                                alert(`Запись успешно ${id ? "изменена" : "добавлена"}`);
                                $("#dataForm")[0].reset();
                                $("#dataForm").removeData("current-id");
                            } else {
                                throw new Error(`Ошибка ${id ? "изменения" : "добавления"} записи`);
                            }
                        })
                        .catch(error => {
                            console.error(`Произошла ошибка при ${id ? "изменении" : "добавлении"} записи:`, error);
                        });
                });
                return false;
            }
        });
    });

    // Автоматически активируем первую вкладку.
    $(".tabs a:first-child span").trigger("click");
};

$(document).ready(function () {
    main();
});
