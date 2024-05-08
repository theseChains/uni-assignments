package jspappl;

public class NameHandler {
    private String name;
    private int counter;

    public NameHandler() {
        name = null;
        counter = 0;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCounter() {
        return counter;
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    public void addCounter(int i) {
        this.counter = this.counter + i;
    }

}
