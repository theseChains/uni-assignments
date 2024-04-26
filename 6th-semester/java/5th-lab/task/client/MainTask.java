package client;
import compute.Task;
import java.io.Serializable;

public class MainTask implements Task<String>, Serializable {
    private static final long serialVersionUID = 227L;
    int[] numbers;

    public MainTask(int[] numbers) {
        this.numbers = numbers;
    }

    public String execute() {
        return computeResult(numbers);
    }

    public static String computeResult(int[] numbers) {
        int numberOfPositiveOddNumbers = 0;
        int numberOfPositiveEvenNumbers = 0;

        for (int number : numbers) {
            if (number % 2 == 0 && number > 0) {
                ++numberOfPositiveEvenNumbers;
            } else if (number > 0) {
                ++numberOfPositiveOddNumbers;
            }
        }

        String result = "";
        if (numberOfPositiveOddNumbers > numberOfPositiveEvenNumbers) {
            result = "Нечётных положительных чисел больше";
        } else if (numberOfPositiveOddNumbers < numberOfPositiveEvenNumbers) {
            result = "Чётных положительных чисел больше";
        } else {
            result = "Нечётных положительных и чётных положительных чисел поровну";
        }

        return result;
    }
}
