var findKthDigit = function() {
    var k = parseInt(document.getElementById("numberInput").value);

    if (k <= 0) {
        alert("Пожалуйста, введите натуральное число больше нуля.");
        return;
    }

    var result = findKthDigitExecutor(k);

    document.getElementById("result").innerText = "K-я цифра последовательности: " + result;
}

document.getElementById("calculateButton").addEventListener("click", findKthDigit);

function findKthDigitExecutor(k) {
    var numObj = {};
    var currentNumber = 1;
    var index = 0;

    while (currentNumber <= k) {
        var digits = [];
        var tempNumber = currentNumber;

        while (tempNumber > 0) {
            var digit = tempNumber % 10;
            digits.unshift(digit);
            tempNumber = Math.floor(tempNumber / 10);
        }

        for (var i = 0; i < digits.length; ++i) {
            numObj[index++] = digits[i];
        }
        ++currentNumber;
    }

    return numObj[k - 1];
}

var calculateDaysUntilExams = function() {
    var currentDate = new Date();
    var targetDate = new Date(2024, 5, 10);
    var remainingDays = Math.ceil((targetDate - currentDate) / (1000 * 60 * 60 * 24));

    console.log("calculated");
    document.getElementById("daysCount").value =
        "Кол-во дней: " + remainingDays;
}

document.getElementById("calculateDays").addEventListener("click", calculateDaysUntilExams);

var calculateDaysUntilDate = function() {
    var dateInput = document.getElementById('dateInput');
    var daysPassedCount = document.getElementById('daysPassedCount');

    var selectedDate = new Date(dateInput.value);
    var currentDate = new Date();

    var timeDiff = Math.abs(currentDate.getTime() - selectedDate.getTime());
    var daysPassed = Math.ceil(timeDiff / (1000 * 3600 * 24));

    daysPassedCount.value = daysPassed - 1;
}

document.getElementById("calculateFromDate").addEventListener("click", calculateDaysUntilDate);

var calculateSequence = function() {
    var firstTermInput = document.getElementById('firstTermInput');
    var numTermsInput = document.getElementById('numTermsInput');
    var resultDiv = document.getElementById('resultSequence');

    var firstTerm = firstTermInput.value.trim();
    var numTerms = numTermsInput.value.trim();

    function isValidNumber(str) {
        for (var i = 0; i < str.length; i++) {
            var charCode = str.charCodeAt(i);
            if (charCode < 48 || charCode > 57) {
                return false;
            }
        }
        return true;
    }

    console.log(isValidNumber(firstTerm));
    console.log(isValidNumber(numTerms));

    if (firstTerm !== "" && numTerms !== "" && isValidNumber(firstTerm) && isValidNumber(numTerms)) {
        firstTerm = parseInt(firstTerm);
        numTerms = parseInt(numTerms);

        var sum = 0;

        for (var i = 0; i < numTerms; i++) {
            sum += Math.pow(-2, 3 * (firstTerm + i));
        }

        resultDiv.textContent = "Сумма последовательности: " + sum;
    } else {
        resultDiv.textContent = "Пожалуйста, введите корректные данные (только целые числа).";
    }
}

document.getElementById("calculateSequence").addEventListener("click", calculateSequence);

function displayDateTime() {
    var months = ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"];
    var daysOfWeek = ["Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"];

    var now = new Date();
    var year = now.getFullYear();
    var month = months[now.getMonth()];
    var dayOfWeek = daysOfWeek[now.getDay()];
    var dayOfMonth = now.getDate();

    document.getElementById("dateOutput").innerHTML = year + " " + dayOfMonth + " " +  month;
    document.getElementById("dayOfWeekOutput").innerHTML = dayOfWeek;
}

displayDateTime();
