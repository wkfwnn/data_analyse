package bx05.tutorial.client;

import onbon.bx05.Bx5GEnv;
import onbon.bx05.Bx5GException;
import onbon.bx05.Bx5GScreen;
import onbon.bx05.Bx5GScreenClient;
import onbon.bx05.area.TextCaptionBxArea;
import onbon.bx05.area.page.TextBxPage;
import onbon.bx05.file.BxFileWriterListener;
import onbon.bx05.file.ProgramBxFile;
import onbon.bx05.utils.TextBinary.Alignment;

public class WriteProgramTextCaption2 implements BxFileWriterListener<Bx5GScreen> {

    public static void main(String[] args) throws Exception {
        // Bx5GEnv.initial();
        Bx5GEnv.initial("log.properties");

        //
        Bx5GScreenClient screen = new Bx5GScreenClient("MyScreen");
        if (!screen.connect("192.168.5.7", 5005)) {
            System.out.println("connect failed");
        }

        //
        ProgramBxFile program = new ProgramBxFile("P000", screen.getProfile());
        program.setFrameShow(true);
        program.setFrameSpeed(20);
        program.loadFrameImage(13);

        //
        TextCaptionBxArea area = new TextCaptionBxArea(448, 0, 64, 32, screen.getProfile());
        area.setFrameShow(true);
        area.setFrameSpeed(20);
        area.loadFrameImage(13);

        // code 1: using object
        TextBxPage page = new TextBxPage("什麼啊!\n好阿\n搞什麼鬼東西");
        page.setHorizontalAlignment(Alignment.FAR);
        area.addPage(page);
        //
        program.addArea(area);

        //
        screen.writeProgramAsync(program, new WriteProgramTextCaption2());
        Thread.sleep(5000);

        //
        screen.readProgramList();

        //
        screen.disconnect();
    }

    @Override
    public void cancel(Bx5GScreen owner, String fileName, Bx5GException ex) {
        ex.printStackTrace();
    }

    @Override
    public void done(Bx5GScreen owner) {

    }

    @Override
    public void fileFinish(Bx5GScreen owner, String fileName, int total) {
        System.out.println(fileName + " fileFinish:" + total);
    }

    @Override
    public void fileWriting(Bx5GScreen owner, String fileName, int total) {
        System.out.println(fileName + " fileWriting:" + total);
    }

    @Override
    public void progressChanged(Bx5GScreen owner, String fileName, int write, int total) {
        System.out.println(fileName + " progressChanged:" + write + "/" + total);
    }
}
