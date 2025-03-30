package org.example;
import com.fazecast.jSerialComm.SerialPort;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        SerialPort sp = SerialPort.getCommPort("COM5");
        sp.setComPortParameters(9600, 8, 1, 0);
        sp.setComPortTimeouts(SerialPort.TIMEOUT_READ_SEMI_BLOCKING, 0, 0);
        if (!sp.openPort()) {
            System.out.println("COM port not available.");
        }
        Scanner input = new Scanner(System.in);
        while(true){
            System.out.println("Enter number of LED blinks (0 to exit): )");
            Integer blink_num = input.nextInt();
            if(blink_num == 0) break;
            Thread.sleep(1500);
            sp.getOutputStream().write(blink_num.byteValue());
        }
        input.close();

    }
}