#include "mwidget.h"
#include "ui_mwidget.h"
#include "QLibrary"
#include "qdebug.h"
#include "QString"
#include "QHostInfo"
#include "QTcpServer"
#include "QTcpSocket"
#include "QStringList"

typedef int ( *pcom_open)(); //定义函数指针

MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    ui->setupUi(this);
    this->GetIp();
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer,SIGNAL(newConnection()),this,SLOT(newConnectSlot()));
    this->listen();
}

MWidget::~MWidget()
{
    delete ui;
}

QString MWidget::GetIp()
{
    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    foreach(QHostAddress address,info.addresses())
    {
      if(address.protocol()==QAbstractSocket::IPv4Protocol)
        qDebug()<<address.toString(); //输出IPV4的地址
        //return address.toString();
        return "127.0.0.1";
    }
    return 0;

}

void MWidget::analyse_data(QStringList list)
{
    QString result;
    foreach (const QString &str, list) {
        qDebug()<<str;
     if (str.contains("MN=")){
         result = str.mid(str.indexOf('=')+1);
         qDebug()<<result;
     }
     else if(str.contains("DataTime=")){
         result = str.mid(str.indexOf("DataTime=")+QString("DataTime=").length());
         qDebug()<<result;
     }
     else if(str.contains("-01-Rtd=")){
         result = str.left(str.indexOf(','));
         result = result.mid(result.indexOf('=')+1);
         qDebug()<<result;
     }
     else if(str.contains("-02-Rtd=")){
         result = str.left(str.indexOf(','));
         result = result.mid(result.indexOf('=')+1);
         qDebug()<<result;
     }
     else if(str.contains("-03-Rtd=")){
         result = str.left(str.indexOf(','));
         result = result.mid(result.indexOf('=')+1);
         qDebug()<<result;
     }

    }
}

void MWidget::newConnectSlot()
{
    QTcpSocket *tcp = mTcpServer->nextPendingConnection();
    connect(tcp,SIGNAL(readyRead()),this,SLOT(readMessage()));
}

void MWidget::listen()
{
    if(mTcpServer->listen(QHostAddress::Any, 8000)){
        qDebug()<<"listen ok";
    }else{
        qDebug()<<"listen error";
    }
}

void MWidget::readMessage()
{
    QString Message;
    QStringList list;
    QTcpSocket *socket = static_cast<QTcpSocket*>(sender());
    Message.prepend(socket->readAll());
    qDebug()<<Message;
    list = Message.split(';');
    analyse_data(list);
}
