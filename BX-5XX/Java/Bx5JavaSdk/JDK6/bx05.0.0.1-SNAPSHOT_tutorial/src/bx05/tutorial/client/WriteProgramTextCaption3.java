package bx05.tutorial.client;

import java.awt.Font;

import onbon.bx05.Bx5GEnv;
import onbon.bx05.Bx5GScreenClient;
import onbon.bx05.area.TextCaptionBxArea;
import onbon.bx05.file.ProgramBxFile;
import onbon.bx05.utils.ColorType2;
import onbon.bx05.utils.DisplayStyleFactory;

public class WriteProgramTextCaption3 {

    public static void main(String[] args) throws Exception {

        for (int i = 0; i < 1; i++) {
            Bx5GEnv.initial("log.properties");

            Bx5GScreenClient screen = new Bx5GScreenClient("MyScreen");
            if (!screen.connect("192.168.5.7", 5005)) {
                System.out.println("connect failed");
            }

            ProgramBxFile program = new ProgramBxFile("P000", screen.getProfile());

            TextCaptionBxArea area = new TextCaptionBxArea(440, 0, 72, 32, screen.getProfile());
            area.addText("測試文字", new Font("Monospace", Font.PLAIN, 16), ColorType2.RED, ColorType2.BLACK, DisplayStyleFactory.getStyle(6));

            program.addArea(area);

            long t1 = System.currentTimeMillis();
            screen.writeProgramQuickly(program);
            long t2 = System.currentTimeMillis();
            System.out.println((t2 - t1) / 1000.0d);

            screen.disconnect();
        }
    }

}
