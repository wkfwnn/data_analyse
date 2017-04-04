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
#include "databaseserver.h"
#include "QDialog"
#include "dialog.h"
#include <QKeyEvent>
#include "databasesearch.h"
#include <QList>
#include<QStringList>
#include <QFont>
#include<QScrollBar>
#include <QFile>
#include<QTextStream>
#include<QDir>
#include<QNetworkInterface>
#include <QTableView>

#if defined (Q_OS_WIN)
#include<windows.h>
#endif

MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    bool ret  = false;
    ui->setupUi(this);
    this->ui_Design();
#if defined(Q_OS_WIN)
    if(this->getVolumeId() != 0xa63f2d0b){
        QMessageBox::warning(this,QString("警告"),QString("do not support on this computer"));
        qDebug()<< "not support this computer";
        exit(1);
    }

#endif

    mCurrentDate = QDate::currentDate().toString(QString("yyyyMMdd"));
    dbServer = new dataBaseServer(this,&ret);
    if(ret == false){
       QMessageBox::warning(this,QString("警告"),QString("无法连接数据库文件！"));
    }
    dbSearch  = new dataBaseSearch();
    connect(dbSearch,SIGNAL(sendListData(QList<QStringList>,QList<QStringList>,QList<QStringList>)),
            this,SLOT(receiveListData(QList<QStringList>,QList<QStringList>,QList<QStringList>)));
#if (USE_NET)
    //
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer,SIGNAL(newConnection()),this,SLOT(newConnectSlot()));
    this->listen();
#if defined(Q_OS_LINUX)
    this->getHwPara();
#endif

#else
    mPort = new QSerialPort(this);
    connect(mPort, &QIODevice::readyRead, this, &MWidget::readData);
    this->serportInit();

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
#endif
}

MWidget::~MWidget()
{
    delete dbServer;
    delete mTcpServer;
    delete setTimeDialog;
    delete ui;
}

void MWidget::analyse_data(QStringList list)
{
    QString result;
    QString display;
    foreach (const QString &str, list) {
       // qDebug()<<str;
        if (str.contains("CN=2011")){
            result = str.mid(str.indexOf('=')+1);
            mCn = result;
            qDebug()<< "CN实时数据"<<result;
        }
        if (str.contains("CN=2051")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            qDebug()<< "CN分钟数据"<<result;
        }
        if (str.contains("CN=2031")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            qDebug()<< "CN分钟数据"<<result;
        }
        if (str.contains("CN=2061")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            qDebug()<< "CN小时数据"<<result;
        }
     else if (str.contains("MN=")){
             result = str.mid(str.indexOf('=')+1);
             qDebug()<<result;
         }
         else if(str.contains("DataTime=")){
             result = str.mid(str.indexOf("DataTime=")+QString("DataTime=").length());
             mDateTime = result;
             qDebug()<<result;
         }
         else if(str.contains("01-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             qDebug()<<QString("折算")+result;
             display = QString("烟尘\n")+ QString("折算:") + result + QString("\n");
             mZsYanchen  = result;
            //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             mYanchen = result;
             qDebug()<<QString("实测")+result;
             display = display + QString("实测:") + result;
             ui->yanchengButton->setText(display);
         }
         else if(str.contains("02-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             qDebug()<<QString("折算")+result;
             display = QString("SO2\n")+ QString("折算:") + result + QString("\n");
             mZsSO2  = result;
             //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = display + QString("实测:") + result;
               qDebug()<<QString("实测")+result;
             mSO2 = result;
             ui->so2Button->setText(display);
         }
         else if(str.contains("03-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             display = QString("NOx\n")+ QString("折算:") + result + QString("\n");
             mZsNOx = result;
            qDebug()<<QString("折算")+result;
             //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = display + QString("实测:") + result;
            mNOx = result;
            qDebug()<<QString("实测")+result;
            ui->No2Button->setText(display);
         }
         else if(str.contains("S01-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("氧含量\n") + result;
             ui->oxygenButton->setText(display);
         }
         else if(str.contains("S02-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("流速\n") + result;
             ui->flowRateButton->setText(display);
         }
         else if(str.contains("S03-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("温度\n") + result;
             ui->tempButton->setText(display);
         }
         else if(str.contains("S04-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("动压\n") + result;
             //ui->dongYaButton->setText(display);
         }
         else if(str.contains("S05-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("湿度\n") + result;
             ui->humidityButton->setText(display);
         }
         else if(str.contains("S07-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("烟道截面积\n") + result;
             //ui->areaButton->setText(display);
         }
         else if(str.contains("S08-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = QString("压力\n") + result;
             ui->pressureButton->setText(display);
         }
         else if(str.contains("01-ZsAvg=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             qDebug()<<QString("折算")+result;
             display = QString("烟尘\n")+ QString("折算:") + result + QString("\n");
             mZsYanchen  = result;
            //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             mYanchen = result;
             qDebug()<<QString("实测")+result;
             display = display + QString("实测:") + result;
             ui->yanchengButton->setText(display);
         }
         else if(str.contains("02-ZsAvg=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             qDebug()<<QString("折算")+result;
             display = QString("SO2\n")+ QString("折算:") + result + QString("\n");
             mZsSO2  = result;
             //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = display + QString("实测:") + result;
               qDebug()<<QString("实测")+result;
             mSO2 = result;
             ui->so2Button->setText(display);
         }
         else if(str.contains("03-ZsAvg=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             display = QString("NOx\n")+ QString("折算:") + result + QString("\n");
             mZsNOx = result;
            qDebug()<<QString("折算")+result;
             //zs
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             display = display + QString("实测:") + result;
             mNOx = result;
             qDebug()<<QString("实测")+result;
             ui->No2Button->setText(display);
         }
        else if(str.contains("S01-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("氧含量\n") + result;
            mOxygen = result;
            ui->oxygenButton->setText(display);
        }
        else if(str.contains("S02-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("流速\n") + result;
            mFlowRate = result;
            ui->flowRateButton->setText(display);
        }
        else if(str.contains("S03-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("温度\n") + result;
            mTemp = result;
            ui->tempButton->setText(display);
        }
        else if(str.contains("S04-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("动压\n") + result;
            mDongYa = result;
            //ui->dongYaButton->setText(display);
        }
        else if(str.contains("S05-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("湿度\n") + result;
            mHumidity = result;
            ui->humidityButton->setText(display);
        }
        else if(str.contains("S07-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("烟道截面积\n") + result;
            mArea = result;
            //ui->areaButton->setText(display);
        }
        else if(str.contains("S08-Avg=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            display = QString("压力\n") + result;
            mPresure= result;
            ui->pressureButton->setText(display);
        }
    }
    bool ok = false;
    qDebug() << "CN" << "   |     " << "DateTime" << "          |        "<< " 烟 尘"  << "|" << "SO2" << "|"
             <<"NOX" << "|" <<"氧含量" << "|" << "流速" << " | " << "温度" << "|" <<"动压" << "|" << "湿度"
            <<"|" << "烟道截面积"  << "|" << "压力";
    qDebug()<< mCn<< mDateTime.toLongLong(&ok) << mYanchen << mSO2 << mNOx << mOxygen<<mFlowRate
            << mTemp << mDongYa<< mHumidity << mArea << mPresure;
    if(mCn == QString("2011")){

        qDebug()<<"实时数据";
        return;
    }

    mParaList.clear();
    mParaList << mCn<< mDateTime << mYanchen << mSO2 << mNOx << mOxygen<<mFlowRate
                 << mTemp << mDongYa<< mHumidity << mArea << mPresure;
    dbServer->setList(&mParaList);
    dbServer->start();

}

void MWidget::ui_Design()
{
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(tr("导航栏"));
    QTreeWidgetItem *imageItem1 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("实时数据")));
    QTreeWidgetItem *imageItem2 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("历史数据查询")));
    QTreeWidgetItem *imageItem3 = new QTreeWidgetItem(ui->treeWidget,QStringList(QString("帮助")));
    this->setFixedSize(1366,768);
    ui->stackedWidget->setCurrentIndex(0);
    setTimeDialog = new Dialog (this);
    connect(setTimeDialog,SIGNAL(sendTimeString(QString)),this,SLOT(receiveTimeString(QString)));

    //设置列数为9
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget_2->setColumnCount(9);
    ui->tableWidget_3->setColumnCount(9);
    QStringList header;
    header << "时间" << " 烟 尘(mg/m³)" << "SO2(mg/m³)" <<"NOX(mg/m³)"<<"氧含量(%)" << "流速(m³/h)" << "温度(℃)" << "湿度(%)"<< "压力(mpa)";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_3->setHorizontalHeaderLabels(header);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式

    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(font);
    ui->tableWidget_2->horizontalHeader()->setFont(font);
    ui->tableWidget_3->horizontalHeader()->setFont(font);

    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->resizeSections(QHeaderView::Stretch);
    ui->tableWidget_3->horizontalHeader()->resizeSections(QHeaderView::Stretch);

}



void MWidget::receiveTimeString(QString date)
{
    dbSearch->setSearchPara(date);
    dbSearch->start();
}

void MWidget::receiveListData(QList<QStringList> list_2061, QList<QStringList> list_2031, QList<QStringList> list_2051)
{
    ui->tableWidget->setRowCount(list_2051.count());
    ui->tableWidget_2->setRowCount(list_2061.count());
    ui->tableWidget_3->setRowCount(list_2031.count());

    for(int i = 0; i < list_2051.count();i ++){
        for(int j = 0; j< list_2051.at(0).count();j++){
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(list_2051.at(i).at(j)));
        }
    }
    for(int i = 0; i < list_2061.count();i ++){
        for(int j = 0; j< list_2061.at(0).count();j++){
            ui->tableWidget_2->setItem(i,j,new QTableWidgetItem(list_2061.at(i).at(j)));
        }
    }
    for(int i = 0; i < list_2031.count();i ++){
        for(int j = 0; j< list_2031.at(0).count();j++){
            ui->tableWidget_3->setItem(i,j,new QTableWidgetItem(list_2031.at(i).at(j)));
        }
    }

}

void MWidget::on_treeWidget_clicked(const QModelIndex &index)
{
    switch(index.row())
    {
     case 0:ui->stackedWidget->setCurrentIndex(0);
        break;
     case 1:ui->stackedWidget->setCurrentIndex(1);
                ui->tabWidget->setCurrentIndex(0);
                dbSearch->setSearchPara(mCurrentDate);
                dbSearch->start();
        break;
     case 2:ui->stackedWidget->setCurrentIndex(2);
       break;
    }
}


#if (USE_NET)
#if defined (Q_OS_LINUX)
QString MWidget::getHwPara()
{
   QList<QNetworkInterface>list = QNetworkInterface::allInterfaces();//获取所有网络接口信息

   foreach(QNetworkInterface interface,  list){
    //    qDebug()<<"Device:"<< interface.name();//设备名称
      //  qDebug()<<"HardwareAddress:"<< interface.hardwareAddress();//获取硬件地址
   }
}
#elif defined(Q_OS_WIN)
/*磁盘序列号*/
DWORD MWidget::getVolumeId()
{
    QString lpRootPathName = "C:\\";
    LPTSTR lpVolumeNameBuffer=new TCHAR[12];//磁盘卷标
    DWORD nVolumeNameSize=12;// 卷标的字符串长度
    DWORD VolumeSerialNumber;//硬盘序列号
    DWORD MaximumComponentLength;// 最大的文件长度
    LPTSTR lpFileSystemNameBuffer=new TCHAR[10];// 存储所在盘符的分区类型的长指针变量
    DWORD nFileSystemNameSize=10;// 分区类型的长指针变量所指向的字符串长度
    DWORD FileSystemFlags;// 文件系统的一此标志

    GetVolumeInformation((LPTSTR)lpRootPathName.utf16(),
      lpVolumeNameBuffer, nVolumeNameSize,
      &VolumeSerialNumber, &MaximumComponentLength,
      &FileSystemFlags,
      lpFileSystemNameBuffer, nFileSystemNameSize);

    //qDebug() << VolumeSerialNumber;
    return VolumeSerialNumber;
}
#endif
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
    QFile f(QDir::currentPath() + QString("/port.txt"));

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open failed.";
        return;
    }
    QTextStream txtInput(&f);
    QString port;
    port = txtInput.readLine();
    qDebug() << "net port:" << port;
    bool ok = false;
    if(mTcpServer->listen(QHostAddress::Any, port.toInt(&ok))){
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

void MWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F12 && ui->stackedWidget->currentIndex() == 1){
        setTimeDialog->show();
    }
    if(event->key() == Qt::Key_F5 && ui->stackedWidget->currentIndex() == 1){
        dbSearch->setSearchPara(mCurrentDate);
        dbSearch->start();
    }

}
