#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>

namespace Ui {
class MWidget;
}
class QTcpServer;
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

private:
    Ui::MWidget *ui;
    QTcpServer *mTcpServer;
};

#endif // MWIDGET_H
