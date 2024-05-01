import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Main {
    static int count;
    public static void main(String[] args){
        count = 0;
        Balls balls = new Balls();
    }
}

class Balls extends Frame implements Observer, ActionListener, ItemListener {
    private LinkedList<Ball> LL = new LinkedList<>();
    private Color col;
    private Frame f;
    private Button b, bChangeSpeed;
    private Choice cColor, cShape, cFigs, cSpeed;
    private TextField tfNumFigs, tfSpeed, tfFigNumber;
    private HashMap<String, Ball> figMap = new HashMap<>();
    private HashMap<String, Integer> figSpeeds = new HashMap<>();
    
    Balls(){
        this.addWindowListener(new WindowAdapter2());
        f = new Frame();
        f.setSize(new Dimension(400,220));
        f.setTitle("Управление ФиО");
        f.setLayout(new GridLayout(8, 2));
        f.addWindowListener(new WindowAdapter2());
        
        Label lNumFigs = new Label("Число ФиО:");
        f.add(lNumFigs);
        tfNumFigs = new TextField();
        f.add(tfNumFigs);
        
        Label lColor = new Label("Цвет ФиО:");
        f.add(lColor);
        cColor = new Choice();
        cColor.addItem("Синий");
        cColor.addItem("Зелёный");
        cColor.addItem("Красный");
        cColor.addItem("Чёрный");
        cColor.addItem("Жёлтый");
        f.add(cColor);
        
        Label lShape = new Label("Тип ФиО:");
        f.add(lShape);
        cShape = new Choice();
        cShape.addItem("Круг");
        cShape.addItem("Квадрат");
        f.add(cShape);
        
        Label lSpeed = new Label("Начальная скорость:");
        f.add(lSpeed);
        tfSpeed = new TextField();
        f.add(tfSpeed);
        
        Label lFigNumber = new Label("Номер ФиО:");
        f.add(lFigNumber);
        tfFigNumber = new TextField();
        f.add(tfFigNumber);
        
        Label lFigs = new Label("Выберите ФиО:");
        f.add(lFigs);
        cFigs = new Choice();
        cFigs.addItemListener(this);
        f.add(cFigs);
        
        Label lSpeedOptions = new Label("Скорость:");
        f.add(lSpeedOptions);
        cSpeed = new Choice();
        for (int i = 1; i <= 5; i++) {
            cSpeed.addItem(String.valueOf(i));
        }
        f.add(cSpeed);
        
        b = new Button("Пуск");
        b.setActionCommand("OK");
        b.addActionListener(this);
        f.add(b);
        
        bChangeSpeed = new Button("Изменить скорость");
        bChangeSpeed.setActionCommand("Change Speed");
        bChangeSpeed.addActionListener(this);
        f.add(bChangeSpeed);
        
        f.setVisible(true);
        this.setSize(500,200);
        this.setVisible(true);
        this.setLocation(100, 150);
    }
    
    public void update(Observable o, Object arg) {
        Ball ball = (Ball)arg;
        System.out.println ("x= " + ball.thr.getName() + ball.x);
        repaint();
    }
    
    public void paint(Graphics g) {
        for (Ball ball : LL) {
            g.setColor(ball.col);
            if (ball.shape.equals("Круг"))
                g.drawOval(ball.x, ball.y, 20, 20);
            else if (ball.shape.equals("Квадрат"))
                g.drawRect(ball.x, ball.y, 20, 20);
            g.drawString(String.valueOf(ball.number), ball.x + 25, ball.y + 10);
        }
    }

    public void itemStateChanged(ItemEvent iE) {
        if (iE.getSource() == cFigs && iE.getStateChange() == ItemEvent.SELECTED) {
            String selectedFig = cFigs.getSelectedItem();
            if (selectedFig != null) {
                Ball selectedBall = figMap.get(selectedFig);
                if (selectedBall != null) {
                    int speed = figSpeeds.getOrDefault(selectedFig, 1);
                    cSpeed.select(String.valueOf(speed));
                }
            }
        }
    }

    public void actionPerformed(ActionEvent aE) {
        String str = aE.getActionCommand();
        if (str.equals("OK")){
            int numFigs = Integer.parseInt(tfNumFigs.getText());
            String shape = cShape.getSelectedItem();
            switch (cColor.getSelectedIndex()) {
                case 0: col = Color.blue; break;
                case 1: col = Color.green; break;
                case 2: col = Color.red; break;
                case 3: col = Color.black; break;
                case 4: col = Color.yellow; break;
            }
            int speed = Integer.parseInt(tfSpeed.getText());
            int figNumber = Integer.parseInt(tfFigNumber.getText());
            for (int i = 0; i < numFigs; i++) {
                Ball ball = new Ball(col, shape, speed, figNumber);
                LL.add(ball);
                ball.addObserver(this);
                figMap.put(ball.toString(), ball);
                cFigs.add(ball.toString());
                figSpeeds.put(ball.toString(), speed);
            }
        } else if (str.equals("Change Speed")){
            String selectedFig = cFigs.getSelectedItem();
            if (selectedFig != null) {
                Ball selectedBall = figMap.get(selectedFig);
                int newSpeed = Integer.parseInt(cSpeed.getSelectedItem());
                selectedBall.setSpeed(newSpeed);
                figSpeeds.put(selectedFig, newSpeed);
            }
        }
        repaint();
    }
}

class Ball extends Observable implements Runnable {
    Thread thr;
    private boolean xplus;
    private boolean yplus;
    int x;
    int y;
    Color col;
    String shape;
    int speed;
    int sleepTime;
    int number;

    public Ball(Color col, String shape, int speed, int number) {
        xplus = true; yplus = true;
        x = 0; y = 30;
        this.col = col;
        this.shape = shape;
        this.speed = speed;
        this.sleepTime = calculateSleepTime();
        this.number = number;
        Main.count++;
        thr = new Thread(this, Main.count + ":" + shape + ":");
        thr.start();
    }

    private int calculateSleepTime() {
        switch (speed) {
            case 1: return 20;
            case 2: return 10;
            case 3: return 5;
            case 4: return 3;
            case 5: return 1;
            default: return 10;
        }
    }

    public void setSpeed(int speed) {
        this.speed = speed;
        this.sleepTime = calculateSleepTime();
    }

    public void run() {
        Random rand = new Random();
        while (true) {
            int xChange = rand.nextInt(3) - 1;
            int yChange = rand.nextInt(3) - 1;
            x += xChange;
            y += yChange;
            if (x >= 475) x = 475;
            if (x <= 0) x = 0;
            if (y >= 175) y = 175;
            if (y <= 29) y = 29;
            setChanged();
            notifyObservers(this);
            try {
                Thread.sleep(sleepTime);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public String toString() {
        return thr.getName();
    }
}

class WindowAdapter2 extends WindowAdapter {
    public void windowClosing (WindowEvent wE) {
        System.exit(0);
    }
}
