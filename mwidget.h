#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>
#include "QHash"

namespace Ui {
class MWidget;
}
class QTcpServer;
class Dll;
class Config;
class MWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWidget(QWidget *parent = 0);
    ~MWidget();
private:
    QString GetIp();
    void analyse_data(QStringList list);
    void ui_Design(QWidget *MWidget);
private slots:
    void newConnectSlot();
    void listen();
    void readMessage();

    void on_treeWidget_clicked(const QModelIndex &index);

    void on_saveButton_clicked();

private:
    Ui::MWidget *ui;
    QTcpServer *mTcpServer;
    Dll *mDll;
    Config *mConfig;
    QHash<QString, QString> mHash;
};

#endif // MWIDGET_H
