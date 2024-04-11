import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPServer {
    private ServerSocket serverSocket;
    private String journalFileName;
    private int id = 0;

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Incorrect number of command line arguments");
        } else {
            int port = Integer.parseInt(args[0]);

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the name of the server journal file: ");
            String fileName = scanner.nextLine();

            TCPServer tcpServer = new TCPServer(port, fileName);
            tcpServer.go();
        }
    }

    public TCPServer(int port, String journalFileName) {
        try {
            serverSocket = new ServerSocket(port);
            this.journalFileName = journalFileName;
        } catch (IOException exception) {
            System.err.println("Unable to open socket for server: " + exception.toString());
        }
    }

    public void writeToJournal(String entry) {
        try (FileWriter writer = new FileWriter(journalFileName, true)) {
            writer.write(entry + "\n");
        } catch (IOException e) {
            System.err.println("Error occurred while writing to the server journal: " + e.getMessage());
        }
    }

    public void go() {
        class Listener implements Runnable {
            Socket socket;
            PrintWriter writer;
            int listId = 0;

            public Listener(Socket socket, int id) {
                this.socket = socket;
                this.listId = id;
            }

            public void run() {
                try {
                    writeToJournal("Listener " + listId + " is running...");

                    BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    this.writer = new PrintWriter(socket.getOutputStream(), true);

                    StringBuilder expression = new StringBuilder();
                    String line;
                    while ((line = reader.readLine()) != null) {
                        writeToJournal("Read string from client " + listId + ": " + line);
                        if (line.endsWith("=")) {
                            expression.append(line);
                            writeToJournal("Expression read from client " + listId + ": " + expression);

                            double result = calculateExpression(expression.toString());
                            writer.println(result);
                            writeToJournal("Result sent to client " + listId + ": " + result);

                            expression.setLength(0);
                        } else {
                            expression.append(line);
                        }
                    }

                    writeToJournal("Client " + listId + " disconnected\n");
                    writer.close();
                    reader.close();
                    socket.close();
                    --id;
                } catch (IOException e) {
                    writeToJournal("IOException occurred: " + e.getMessage());
                    writer.println("IOException: " + e.getMessage());
                    System.err.println("Exception: " + e.toString());
                    writeToJournal("Client " + listId + " disconnected\n");
                    --id;
                } catch (ArithmeticException e) {
                    System.err.println("Overflow or underflow occurred");
                    writeToJournal("ArithmeticException occurred: " + e.getMessage());
                    writer.println("ArithmeticException: " + e.getMessage());
                    writeToJournal("Client " + listId + " disconnected\n");
                    --id;
                } catch (NumberFormatException e) {
                    System.err.println("Invalid number format in expression");
                    writeToJournal("NumberFormatException occurred: " + e.getMessage());
                    writer.println("NumberFormatException: " + e.getMessage());
                    writeToJournal("Client " + listId + " disconnected\n");
                    --id;
                }
            }
        }

        System.out.println("Server is running...");
        writeToJournal("Server is running...");
        while (true) {
            try {
                Socket socket = serverSocket.accept();
                Listener listener = new Listener(socket, ++id);
                Thread thread = new Thread(listener);
                thread.start();
            } catch (IOException e) {
                System.err.println("Exception: " + e.toString());
            }
        }
    }

    public double calculateExpression(String expression) throws ArithmeticException, NumberFormatException {
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
