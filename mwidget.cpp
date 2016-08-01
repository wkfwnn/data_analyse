#include "mwidget.h"
#include "ui_mwidget.h"
#include "dll.h"
#include "qdebug.h"
#include "QString"
#include "QHostInfo"
#include "QTcpServer"
#include "QTcpSocket"
#include "QStringList"
#include "QListWidget"
#include "QPushButton"
#include "QGridLayout"
#include "QStackedWidget"
#include "QVBoxLayout"
#include "config.h"
#include "QHash"
#include "QFile"
#include "QMessageBox"

MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    int ret = 0;
    ui->setupUi(this);
    this->ui_Design(this);
    this->GetIp();
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer,SIGNAL(newConnection()),this,SLOT(newConnectSlot()));
    this->listen();
    mDll = new Dll();
    mDll->loadLibrary(mDll);
    ret = mDll->initScreen();

    mConfig = new Config(this);
    ret = mConfig->loadConfigData(&mHash);
    if(ret == 0){
        ui->spinBox->setValue(mHash.value(QString("screen_num")).toInt());
        ui->spinBox_2->setValue(mHash.value(QString("screen_height")).toInt());
        ui->spinBox_3->setValue(mHash.value(QString("screen_width")).toInt());
        ui->lineEdit->setText(mHash.value(QString("ip")));
        ui->lineEdit_2->setText(mHash.value(QString("ip_port")));

    }
    qDebug()<<ret;

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
        return address.toString();
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
         ui->pushButton_3->setText(QString("烟尘\n")+ result);
     }
     else if(str.contains("-02-Rtd=")){
         result = str.left(str.indexOf(','));
         result = result.mid(result.indexOf('=')+1);
         qDebug()<<result;
         ui->so2Button->setText(QString("SO2\n")+result);
     }
     else if(str.contains("-03-Rtd=")){
         result = str.left(str.indexOf(','));
         result = result.mid(result.indexOf('=')+1);
         ui->No2Button->setText(QString("NOx\n")+result);
     }
    }
}

void MWidget::ui_Design(QWidget *MWidget)
{
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("导航栏"));
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("实时数据")));
    imageItem1->setIcon(0,QIcon("xxx.png"));
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("参数设置")));
    QTreeWidgetItem *imageItem3 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("帮助")));
    this->setFixedSize(1366,768);
    ui->stackedWidget->setCurrentIndex(0);

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

void MWidget::on_treeWidget_clicked(const QModelIndex &index)
{
    switch(index.row())
    {
     case 0:ui->stackedWidget->setCurrentIndex(0);
        break;
     case 1:ui->stackedWidget->setCurrentIndex(1);
        break;
     case 2:ui->stackedWidget->setCurrentIndex(2);
       break;
    }
}

void MWidget::on_saveButton_clicked()
{
    QHash<QString,QString>data;
    data.insert(QString("screen_num"),QString::number(ui->spinBox->value()));
    data.insert(QString("screen_width"),QString::number(ui->spinBox_2->value()));
    data.insert(QString("screen_height"),QString::number(ui->spinBox_3->value()));
    data.insert(QString("ip"),ui->lineEdit->text());
    data.insert(QString("ip_port"),ui->lineEdit_2->text());

    QFile file("config.dat");
    if (file.open(QFile::WriteOnly)){
        QTextStream out(&file);
        QHashIterator<QString, QString> i(data);
          while (i.hasNext()) {
              i.next();
              out << i.key() << ":" << i.value() << endl;
          }
        out.flush();
        file.close();
        mHash = data;
        ui->spinBox->setValue(mHash.value(QString("screen_num")).toInt());
        ui->spinBox_2->setValue(mHash.value(QString("screen_height")).toInt());
        ui->spinBox_3->setValue(mHash.value(QString("screen_width")).toInt());
        ui->lineEdit->setText(mHash.value(QString("ip")));
        ui->lineEdit_2->setText(mHash.value(QString("ip_port")));
    }else{
        QMessageBox::warning(this,QString("警告"),QString("数据未保存！"));
    }

}
