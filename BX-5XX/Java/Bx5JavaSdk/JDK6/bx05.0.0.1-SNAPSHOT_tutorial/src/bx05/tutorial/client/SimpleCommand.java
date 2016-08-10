package bx05.tutorial.client;

import onbon.bx05.Bx5GEnv;
import onbon.bx05.Bx5GScreenClient;
import onbon.bx05.cmd.led.ModifyBrightnessCmd;
import onbon.bx05.cmd.led.ScreenTimingOnOffCmd;

public class SimpleCommand {

    public static void main(String[] args) throws Exception {
        // Bx5GEnv.initial();
        Bx5GEnv.initial("log.properties");

        //
        Bx5GScreenClient screen = new Bx5GScreenClient("MyScreen");
        if (!screen.connect("192.168.5.7", 5005)) {
            System.out.println("connect failed");
            return;
        }

        //
        screen.ping();
        screen.checkControllerStatus();
        screen.checkFirmware();
        screen.checkMemVolumes();
        screen.syncTime();
        screen.readControllerId();

        //
        screen.checkHealth();
        screen.turnOff();
        screen.turnOn();
        screen.lock();
        screen.unlock();

        //
        ScreenTimingOnOffCmd cmd1 = screen.createTimingOnOff();
        cmd1.addTime(10, 20, 11, 0);
        screen.setupTimingOnOff(cmd1);
        screen.cancelTimingOnOff();

        //
        ModifyBrightnessCmd cmd2 = screen.createBrightness();
        cmd2.setupTimerBrightness(20, 12);  // 10:00 - 10:29
        screen.setupBrightness(cmd2);
        screen.manualBrightness((byte) 16);

        //
        screen.disconnect();

    }
}
