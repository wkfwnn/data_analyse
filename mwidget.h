#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>
#include "QHash"

#define USE_NET    0




namespace Ui {
class MWidget;
}
class QTcpServer;
class Dll;
class Config;
class QSerialPort;
class UpdateScreenThread;
class MWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWidget(QWidget *parent = 0);
    ~MWidget();
private:
    void analyse_data(QStringList list);
    void ui_Design();
#if (USE_NET)
    QString GetIp();
#else
    void serportInit();
#endif
private slots:
#if (USE_NET)
    void newConnectSlot();
    void listen();
    void readMessage();
#else
    void readData();
#endif
    void loadDll();
    void on_treeWidget_clicked(const QModelIndex &index);
    void on_saveButton_clicked(); 


private:
    Ui::MWidget *ui;
#if (USE_NET)
    QTcpServer *mTcpServer;
#else
    QSerialPort *mPort;
#endif

    Dll *mDll;
    Config *mConfig;
    QHash<QString, QString> mHash;
    UpdateScreenThread *mThread;

};

#endif // MWIDGET_H
