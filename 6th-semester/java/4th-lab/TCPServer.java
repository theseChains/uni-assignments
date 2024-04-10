import java.io.*;
import java.net.*;

public class TCPServer {
    private static final int TIME_SEND_SLEEP = 100;
    private static final int COUNT_TO_SEND = 10;
    private ServerSocket serverSocket;

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Incorrect number of command line arguments");
        } else {
            int port = Integer.parseInt(args[0]);
            TCPServer tcpServer = new TCPServer(port);
            tcpServer.go();
        }
    }

    public TCPServer(int port) {
        try {
            serverSocket = new ServerSocket(port);
        } catch (IOException exception) {
            System.err.println("Unable to open socket for server: " + exception.toString());
        }
    }

    public void go() {
        class Listener implements Runnable{
            Socket socket;

            public Listener(Socket aSocket){
                socket = aSocket;
            }

            public void run(){
                try {
                    System.out.println("Слушатель запущен");

                    BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

                    StringBuilder expression = new StringBuilder();
                    String line;
                    while ((line = reader.readLine()) != null) {
                        if (line.endsWith("=")) {
                            expression.append(line);
                            System.err.println("string got in listener: " + expression);

                            double result = calculateExpression(expression.toString());
                            writer.println(result);

                            expression.setLength(0);
                        } else {
                            expression.append(line);
                        }
                    }

                    writer.close();
                    reader.close();
                    socket.close();
                } catch(IOException e) {
                    System.err.println("Исключение: " + e.toString());
                }
            }
        }

        System.out.println("Сервер запущен...");
        while (true) {
            try {
                Socket socket = serverSocket.accept();
                Listener listener = new Listener(socket);
                Thread thread = new Thread(listener);
                thread.start();
            } catch(IOException e) {
                System.err.println("Исключение: " + e.toString());
            }
        }
    }

    public double calculateExpression(String expression) {
        String removedLastChar = expression.substring(0, expression.length() - 1);
        String[] tokens = removedLastChar.split("[\\+\\-]");

        double result = Double.parseDouble(tokens[0]);

        int operatorIndex = tokens[0].length();
        for (int i = 1; i < tokens.length; i++) {
            char operator = removedLastChar.charAt(operatorIndex);
            operatorIndex += tokens[i].length() + 1;

            double operand = Double.parseDouble(tokens[i]);

            switch (operator) {
                case '+':
                    result += operand;
                    break;
                case '-':
                    result -= operand;
                    break;
                default:
                    throw new IllegalArgumentException("Invalid operator: " + operator);
            }
        }

        return result;
    }
}
