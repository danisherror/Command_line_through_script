import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        runCommand("pwd");
        runCommand("ls -ltr");
    }

    public static void runCommand(String cmd) {
        try {
            ProcessBuilder builder = new ProcessBuilder();
            builder.command("bash", "-c", cmd);
            Process process = builder.start();

            BufferedReader reader = new BufferedReader(
                new InputStreamReader(process.getInputStream())
            );

            System.out.println("Output of command: " + cmd);
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            int exitCode = process.waitFor();
            System.out.println("Exited with code: " + exitCode + "\n");
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
