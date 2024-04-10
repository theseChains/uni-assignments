import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient implements Runnable {
    public static final int CLIENT_COUNT = 1;
    public static final int READ_BUFFER_SIZE = 10;

    private String name = null;
    private String host = null;
    private int serverPort = 0;

    public TCPClient(String clientName, String hostName, int port) {
        name = clientName;
        host = hostName;
        serverPort = port;
    }

    public void run() {
        String[] expression = { "33333333333.7+", "1.6-", "5=" };
        try {
            Socket socket = new Socket(host, serverPort);
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            for (String argument : expression)
            {
                System.out.println("writing: " + argument);
                writer.println(argument);
                writer.flush();
            }

            String result = reader.readLine();
            System.out.println("Result: " + result);

            writer.close();
            reader.close();
            socket.close();

            Thread.yield();
        } catch (UnknownHostException e) {
            System.err.println("Исключение: " + e.toString());
        } catch (IOException e) {
            System.err.println("Исключение: " + e.toString());
        }
    }

    public static void main(String[] args) {
        try {
            File file = new File("settings.txt");
            Scanner scanner = new Scanner(file);
            String host = scanner.nextLine();
            int serverPort = Integer.parseInt(scanner.nextLine());
            scanner.close();

            String name = "client";
            TCPClient client = new TCPClient(name, host, serverPort);
            Thread clientThread = new Thread(client);
            clientThread.start();
        } catch (FileNotFoundException e) {
            System.err.println("Error: settings.txt file not found.");
            e.printStackTrace();
        } catch (NumberFormatException e) {
            System.err.println("Error: Invalid port number in settings.txt");
            e.printStackTrace();
        }
    }
}
