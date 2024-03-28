import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

interface Event {
    void handle(String message, File outputFile);
}

class VariableChangeSource {
    Event event;

    VariableChangeSource(Event event) {
        this.event = event;
    }

    void generateEvent(String message, File outputFile) {
        event.handle(message, outputFile);
    }
}

class VariableChangeReceiver implements Event {
    public void handle(String message, File outputFile) {
        System.out.println("Variable Change Receiver Event: " + message);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile, true))) {
            writer.write("Variable Change Receiver Event: " + message);
            writer.newLine();
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}

class FileOutputStreamSource {
    Event event;

    FileOutputStreamSource(Event event) {
        this.event = event;
    }

    void generateEvent(String message, File outputFile) {
        event.handle(message, outputFile);
    }
}

class FileOutputStreamReceiver implements Event {
    public void handle(String message, File outputFile) {
        System.out.println("File Output Stream Event: " + message);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile, true))) {
            writer.write("File Output Stream Event: " + message);
            writer.newLine();
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}

class FunctionEvaluationSource {
    Event event;

    FunctionEvaluationSource(Event event) {
        this.event = event;
    }

    void generateEvent(String message, File outputFile) {
        event.handle(message, outputFile);
    }
}

class FunctionEvaluationReceiver implements Event {
    public void handle(String message, File outputFile) {
        System.out.println("Function Evaluation Event: " + message);

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile, true))) {
            writer.write("Function Evaluation Event: " + message);
            writer.newLine();
        } catch (IOException e) {
            System.err.println("Error writing to file: " + e.getMessage());
        }
    }
}

class NumberInputHandler {
    VariableChangeSource variableChangeSource;
    FileOutputStreamSource fileOutputStreamSource;
    FunctionEvaluationSource functionEvaluationSource;

    File inputFile;
    File outputFile;

    int numberOfPositiveOddNumbers;
    int numberOfPositiveEvenNumbers;

    NumberInputHandler(VariableChangeSource variableChangeSource,
                       FileOutputStreamSource fileOutputStreamSource,
                       FunctionEvaluationSource functionEvaluationSource)
    {
        this.variableChangeSource = variableChangeSource;
        this.fileOutputStreamSource = fileOutputStreamSource;
        this.functionEvaluationSource = functionEvaluationSource;
    }

    public void initializeInputFile() {
        Scanner scanner = new Scanner(System.in);

        while (inputFile == null || !inputFile.exists()) {
            System.out.print("Введите путь до файла, где находится путь до 'Журнала' и заданная последовательность: ");
            String filePath = scanner.nextLine();
            inputFile = new File(filePath);

            if (!inputFile.exists()) {
                System.err.println("Файл не существует. Попробуйте ещё раз.");
            }
        }
    }

    public void initializeOutputFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line = reader.readLine();
            outputFile = new File(line);
            if (!outputFile.exists()) {
                System.out.println("Не удалось найти файл 'Журнала'.");
            } else {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile, true))) {
                    writer.newLine();
                    writer.write("Start of new log");
                    writer.newLine();
                } catch (IOException e) {
                    System.err.println("Ошибка чтения файла: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.err.println("Ошибка чтения файла: " + e.getMessage());
        }
    }

    public void handleNumberInput() {
        numberOfPositiveOddNumbers = 0;
        numberOfPositiveEvenNumbers = 0;

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String firstLine = reader.readLine();
            String numbersString = reader.readLine();
            String[] arguments = numbersString.split(" ");

            for (String argument : arguments) {
                processArgument(argument);
                functionEvaluationSource.generateEvent("processArgument evaluated", outputFile);
            }

        } catch (IOException exception) {
            System.err.println("Ошибка чтения файла: " + exception.getMessage());
        }

        printResult();
    }

    private void processArgument(String argument) {
        int currentNumber = Integer.parseInt(argument);
        if (currentNumber % 2 == 0 && currentNumber > 0) {
            ++numberOfPositiveEvenNumbers;
            variableChangeSource.generateEvent("incremented number of positive elements", outputFile);
        } else if (currentNumber > 0) {
            ++numberOfPositiveOddNumbers;
        }
    }

    private void printResult() {
        if (numberOfPositiveOddNumbers > numberOfPositiveEvenNumbers) {
            System.out.println("Нечётных положительных чисел больше");
            fileOutputStreamSource.generateEvent("More negative odd numbers", outputFile);
        } else if (numberOfPositiveOddNumbers < numberOfPositiveEvenNumbers) {
            System.out.println("Чётных положительных чисел больше");
            fileOutputStreamSource.generateEvent("More positive odd numbers", outputFile);
        } else {
            System.out.println("Нечётных положительных и чётных положительных чисел поровну");
            fileOutputStreamSource.generateEvent("Same amount of numbers", outputFile);
        }
    }
}

public class MainTask {
    public static void main(String[] args) {
        VariableChangeReceiver variableChangeReceiver = new VariableChangeReceiver();
        VariableChangeSource variableChangeSource = new VariableChangeSource(variableChangeReceiver);

        FileOutputStreamReceiver fileOutputStreamReceiver = new FileOutputStreamReceiver();
        FileOutputStreamSource fileOutputStreamSource = new FileOutputStreamSource(fileOutputStreamReceiver);

        FunctionEvaluationReceiver functionEvaluationReceiver = new FunctionEvaluationReceiver();
        FunctionEvaluationSource functionEvaluationSource = new FunctionEvaluationSource(functionEvaluationReceiver);

        NumberInputHandler numberInputHandler =
            new NumberInputHandler(variableChangeSource, fileOutputStreamSource, functionEvaluationSource);

        numberInputHandler.initializeInputFile();
        numberInputHandler.initializeOutputFile();
        numberInputHandler.handleNumberInput();
    }
}
