class MainTask {
    public static void main(String[] args) {
        int numberOfPositiveOddNumbers = 0;
        int numberOfPositiveEvenNumbers = 0;

        for (String argument : args) {
            int currentNumber = Integer.parseInt(argument);
            if (currentNumber % 2 == 0 && currentNumber > 0) {
                ++numberOfPositiveEvenNumbers;
            } else if (currentNumber > 0) {
                ++numberOfPositiveOddNumbers;
            }
        }

        if (numberOfPositiveOddNumbers > numberOfPositiveEvenNumbers) {
            System.out.println("Нечётных положительных чисел больше");
        } else if (numberOfPositiveOddNumbers < numberOfPositiveEvenNumbers) {
            System.out.println("Чётных положительных чисел больше");
        } else {
            System.out.println("Нечётных положительных и чётных положительных чисел поровну");
        }
    }
}
