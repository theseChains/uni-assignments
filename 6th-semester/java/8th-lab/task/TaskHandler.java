package jspappl;

import java.util.ArrayList;

public class TaskHandler {
    private int counter;
    private ArrayList<String> results = new ArrayList<>();
    private ArrayList<int[]> arrays = new ArrayList<>();

    public TaskHandler() {
        counter = 0;
    }

    public void calculateNewResult(int[] numbers) {
        this.arrays.add(numbers);
        this.results.add(getResult(numbers));
    }

    public String getResult(int[] numbers) {
        int evenPositiveCount = 0;
        int oddPositiveCount = 0;

        for (int num : numbers) {
            if (num > 0) {
                if (num % 2 == 0) {
                    ++evenPositiveCount;
                } else {
                    ++oddPositiveCount;
                }
            }
        }

        if (evenPositiveCount > oddPositiveCount) {
            return "Чётных и положительных чисел больше";
        } else if (evenPositiveCount < oddPositiveCount) {
            return "Нечётных и положительных чисел больше";
        } else {
            return "Чётных и нечётных положительных чисел поровну";
        }
    }

    public ArrayList<String> getResults() {
        return this.results;
    }

    public ArrayList<int[]> getArrays() {
        return this.arrays;
    }

    public int getCounter() {
        return this.counter;
    }

    public void incrementCounter() {
        ++this.counter;
    }
}
