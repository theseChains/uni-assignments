class NumberTooSmall extends Exception {
    public String toString() {
        return "Number too small expception thrown";
    }
}

class ContainsIllegalSymbol extends Exception {
    public String toString() {
        return "Contains illegal symbol exception thrown";
    }
}

class IllegalArraySize extends Exception {
    public String toString() {
        return "Illegal array size exception thrown";
    }
}

interface Constants {
    int MIN_ARRAY_NUMBER = -10;
    String ILLEGAL_SYMBOL = "7";
    int MAX_ARRAY_SIZE = 10;
}

interface ArgumentHandling {
    void CheckNumberOfArguments(String[] arguments) throws IllegalArraySize;
    void CheckForIllegalSymbol(String argument) throws ContainsIllegalSymbol;
    int ConvertNumberFromString(String string);
    void CheckNumberValue(int value) throws NumberTooSmall;
}

class ArgumentParser implements ArgumentHandling {
    public void CheckNumberOfArguments(String[] arguments) throws IllegalArraySize {
        if (arguments.length > Constants.MAX_ARRAY_SIZE) {
            throw new IllegalArraySize();
        }
    }

    public void CheckForIllegalSymbol(String argument) throws ContainsIllegalSymbol {
        if (argument.contains(Constants.ILLEGAL_SYMBOL)) {
            throw new ContainsIllegalSymbol();
        }
    }

    public int ConvertNumberFromString(String argument) {
        return Integer.parseInt(argument);
    }

    public void CheckNumberValue(int value) throws NumberTooSmall {
        if (value < Constants.MIN_ARRAY_NUMBER) {
            throw new NumberTooSmall();
        }
    }
}

class MainTask {
    public static void main(String[] args) {
        try {
            ArgumentParser parser = new ArgumentParser();
            parser.CheckNumberOfArguments(args);

            int numberOfPositiveOddNumbers = 0;
            int numberOfPositiveEvenNumbers = 0;
            for (String argument : args) {
                parser.CheckForIllegalSymbol(argument);
                int currentNumber = parser.ConvertNumberFromString(argument);
                parser.CheckNumberValue(currentNumber);

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
        } catch (NumberTooSmall exception) {
            System.out.println(exception);
        } catch (ContainsIllegalSymbol exception) {
            System.out.println(exception);
        } catch (IllegalArraySize exception) {
            System.out.println(exception);
        }
    }
}
