#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>
#include "QHash"
#include <QList>
#include <QStringList>

#define USE_NET    1




namespace Ui {
class MWidget;
}
class QTcpServer;
class Dll;
class Config;
class QSerialPort;
class UpdateScreenThread;
class dataBaseServer;
class QStringList;
class Dialog;
class dataBaseSearch;
class QSqlDatabase;

class MWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWidget(QWidget *parent = 0);
    ~MWidget();
private:
    void analyse_data(QStringList list);
    void ui_Design();
public slots:
   void  receiveTimeString(QString date);
   void  receiveListData(QList<QStringList> list_2061, QList<QStringList> list_2031, QList<QStringList> list_2051);
#if (USE_NET)
    QString getHwPara();
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
    void on_treeWidget_clicked(const QModelIndex &index);
protected:
    void keyPressEvent(QKeyEvent *event);
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
    dataBaseServer *dbServer;
    dataBaseSearch *dbSearch;
    QString mCn;
    QString mDateTime;
    QString mSO2;
    QString mNOx;
    QString mYanchen;
    QString mZsSO2;
    QString mZsNOx;
    QString mZsYanchen;
    QString mOxygen;
    QString mFlowRate;
    QString mTemp;
    QString mDongYa;
    QString mHumidity;
    QString mArea;
    QString mPresure;
    QStringList mParaList;
    QString mCurrentDate;
    Dialog *setTimeDialog;
};

#endif // MWIDGET_H
