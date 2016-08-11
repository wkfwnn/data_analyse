#include "mwidget.h"
#include "ui_mwidget.h"
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
#include "QSerialPort"
#include "QTimer"
#include "updatescreenthread.h"
#include "QDateTime"


MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    int ret = 0;
    ui->setupUi(this);
    this->ui_Design();
#if (USE_NET)
    this->GetIp();
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer,SIGNAL(newConnection()),this,SLOT(newConnectSlot()));
    this->listen();
#else
    mPort = new QSerialPort(this);
    connect(mPort, &QIODevice::readyRead, this, &MWidget::readData);
    this->serportInit();
#endif


    mConfig = new Config(this);
    ret = mConfig->loadConfigData(&mHash);
    if(ret == 0){
        ui->spinBox->setValue(mHash.value(QString("screen_num")).toInt());
        ui->spinBox_2->setValue(mHash.value(QString("screen_height")).toInt());
        ui->spinBox_3->setValue(mHash.value(QString("screen_width")).toInt());
        ui->lineEdit->setText(mHash.value(QString("ip")));
        ui->lineEdit_2->setText(mHash.value(QString("ip_port")));
    }
    mThread = new UpdateScreenThread();
}

MWidget::~MWidget()
{
    delete ui;
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
     else if(str.contains("01-ZsRtd=")){
         result = str.left(str.lastIndexOf(','));
         result = result.mid(result.lastIndexOf('=')+1);
         ui->pushButton_3->setText(QString("烟尘\n")+ result);
         mYanchen  = result;
     }
     else if(str.contains("02-ZsRtd=")){
         result = str.left(str.lastIndexOf(','));
         result = result.mid(result.lastIndexOf('=')+1);
         qDebug()<<result;
         ui->so2Button->setText(QString("SO2\n")+result);
         mSO2  = result;
     }
     else if(str.contains("03-ZsRtd=")){
         result = str.left(str.lastIndexOf(','));
         result = result.mid(result.lastIndexOf('=')+1);
         ui->No2Button->setText(QString("NOx\n")+result);
         mNOx = result;
     }
    }

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy年MM月dd日  ddd   hh时mm分ss秒");
    qDebug()<<current_date;

    QFile file("Test.txt");
    if (file.open(QFile::WriteOnly)) {
        QTextStream out(&file);
        out << current_date                                <<"\r\n"
            << QString("         折  算(mg/m3)       标准") << "\r\n"
            << QString("SO2")<<QString("      ") << mSO2 << QString("                < 100\r\n")
            << QString("NOx")<<QString("      ") << mNOx << QString("              < 200\r\n")
            << QString("烟尘")<<QString("     ") << mYanchen << QString("                < 10\r\n");
        out.flush();
        file.close();
    }
    mThread->start();
}

void MWidget::ui_Design()
{
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("导航栏"));
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("实时数据")));
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("参数设置")));
    QTreeWidgetItem *imageItem3 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("帮助")));
    this->setFixedSize(1366,768);
    ui->stackedWidget->setCurrentIndex(0);

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
    data.insert(QString("screen_width"),QString::number(ui->spinBox_3->value()));
    data.insert(QString("screen_height"),QString::number(ui->spinBox_2->value()));
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

#if (USE_NET)

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
void MWidget::newConnectSlot()
{
    QTcpSocket *tcp = mTcpServer->nextPendingConnection();
    connect(tcp,SIGNAL(readyRead()),this,SLOT(readMessage()));
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


void MWidget::listen()
{
    if(mTcpServer->listen(QHostAddress::Any, 8000)){
        qDebug()<<"listen ok";
    }else{
        qDebug()<<"listen error";
    }
}

#else
void MWidget::readData()
{
  QStringList list;
  QString message;
  QByteArray data = mPort->readAll();
  message = QString(data);
  list = message.split(";");
  analyse_data(list);
}



void MWidget::serportInit()
{
    QStringList list;
    QString baudRate;
    QString line;
    QFile data("serport.txt");
    if (data.open(QFile::ReadOnly)) {
        QTextStream out(&data);
        line = out.readLine();
        list = line.split(",");
    }else{
        QMessageBox::warning(this,QString("警告"),QString("软件文件缺失"));
        return;
    }
    baudRate = list.at(1);
    ui->lineEdit_3->setText(list.at(0));
    ui->lineEdit_4->setText(list.at(1));

    mPort->setPortName(list.at(0));
    mPort->setBaudRate(baudRate.toInt());
    mPort->setDataBits(QSerialPort::Data8);
    mPort->setParity(QSerialPort::NoParity);
    mPort->setStopBits(QSerialPort::OneStop);
    mPort->setFlowControl(QSerialPort::NoFlowControl);
     if (mPort->open(QIODevice::ReadWrite)) {

     }else{
        QMessageBox::critical(this, tr("错误"), QString("无法打开串口"));
     }
}
#endif
