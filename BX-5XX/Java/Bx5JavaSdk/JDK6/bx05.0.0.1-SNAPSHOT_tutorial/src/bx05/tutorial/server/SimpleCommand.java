package bx05.tutorial.server;

import onbon.bx05.Bx5GEnv;
import onbon.bx05.Bx5GScreen;
import onbon.bx05.Bx5GServer;
import onbon.bx05.Bx5GServerListener;

public class SimpleCommand {

    public static void main(String[] args) throws Exception {
        // 初始化 Bx5G API 環境，必需於系統啟動時先執行。
        Bx5GEnv.initial("log.properties");

        // 啟動服務氣模式，8001 PORT 為通勳埠。
        Bx5GServer server = new Bx5GServer("TEST", 8001);

        // 加入設備連入監聽程式
        server.addListener(new ConnectionListener());

        // 啟動服務器
        server.start();
        System.out.println("waiting...");

        Thread.sleep(120000);

        // 終止服務器
        server.stop();
        System.out.println("done!");
    }

    public static class ConnectionListener implements Bx5GServerListener {

        @Override
        public void connected(String socketId, String controllerAddr, Bx5GScreen screen) {
            // 當有屏幕連線時，會發生此事件。
            System.out.println(socketId + " online:" + controllerAddr);
            System.out.println("ping:     " + screen.ping());						// PING 設備
            System.out.println("status:   " + screen.checkControllerStatus());		// 取得控制器狀態
            System.out.println("frimware: " + screen.checkFirmware());				// 檢查韌體版本
            System.out.println("id:       " + screen.readControllerId());			// 讀取控制器編號

            // TODO: 整合 screen 資訊至二次開發系統，進行連線後的相關操作
        }

        @Override
        public void disconnected(String socketId, String controllerAddr, Bx5GScreen screen) {
            // 當有屏幕斷線時，會發生此事件。

            // TODO: 整合 screen 資訊至二次開發系統，進行斷線處理
        }
    }
}
