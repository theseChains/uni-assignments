package client;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import compute.Compute;

public class ComputeTask {
    public static void main(String args[]) {
        try {
            String name = "Compute";
            Registry registry = LocateRegistry.getRegistry(args[0], 1099);

            Compute comp = (Compute)registry.lookup(name);
            int numbers[] = new int[args.length - 1];
            for (int i = 1; i < args.length; ++i) {
                try {
                    numbers[i - 1] = Integer.parseInt(args[i]);
                } catch (NumberFormatException e) {
                    System.err.println("Argument " + (i + 1) + " is not a valid integer: " + args[i]);
                }
            }
            MainTask task = new MainTask(numbers);
            String result = comp.executeTask(task);
            System.out.println(result);
        } catch (Exception e) {
            System.err.println("ComputeTask exception:");
            e.printStackTrace();
        }
    }
}
