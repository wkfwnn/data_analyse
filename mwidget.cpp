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


#define ANALYSE_DEBUG  0
//if want give other people exe file ,enable marco blow
#define SUPPORT_ONLY_ONE_COMPUTER  1
#define TEST_VERSION   1



MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    bool ret  = false;
    ui->setupUi(this);
    this->ui_Design();
#if (TEST_VERSION)
    this->setWindowTitle(QString("烟气数据管理平台试用版"));
#endif
#if defined(Q_OS_WIN)
#if SUPPORT_ONLY_ONE_COMPUTER
    if(this->getVolumeId() != 0x81f51){
        QMessageBox::warning(this,QString("警告"),QString("do not support on this computer"));
        qDebug()<< "not support this computer";
        exit(1);
    }
#endif
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
    QString str;
    QString display;
    foreach (const QString &strTmp, list) {
        str = strTmp;
#if ANALYSE_DEBUG
       qDebug()<< "new line"<< str;
#endif
        if(str.contains("&&")){
           if(str.contains("DataTime="));
           else{
               str  = str.left(str.indexOf("&&"));
           }
        }
        if (str.contains("CN=2011")){
            result = str.mid(str.indexOf('=')+1);
            mCn = result;
            #if ANALYSE_DEBUG
            qDebug()<< "CN实时数据"<<result;
            #endif
        }
        if (str.contains("CN=2051")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            #if ANALYSE_DEBUG
            qDebug()<< "CN分钟数据"<<result;
            #endif
        }
        if (str.contains("CN=2031")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            #if ANALYSE_DEBUG
            qDebug()<< "CN日数据"<<result;
            #endif

        }
        if (str.contains("CN=2061")){
            result = str.mid(str.indexOf('=')+1);
             mCn = result;
            #if ANALYSE_DEBUG
            qDebug()<< "CN小时数据"<<result;
            #endif
        }
        else if (str.contains("MN=")){
             result = str.mid(str.indexOf('=')+1);
             qDebug()<<result;
         }
         else if(str.contains("DataTime=")){
             result = str.mid(str.indexOf("DataTime=")+QString("DataTime=").length());
             mDateTime = result;
             #if ANALYSE_DEBUG
             qDebug()<< "dataTime"<< result;
             #endif
         }
        else if(str.contains("S01-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mOxygen = result;
            #if ANALYSE_DEBUG
            qDebug() << "S01-Rtd=" <<mOxygen;
            #endif
        }
        else if(str.contains("S02-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mFlowRate = result;
            #if ANALYSE_DEBUG
            qDebug() << "S02-Rtd=" <<mFlowRate;
            #endif

        }
        else if(str.contains("S03-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mTemp = result;
            #if ANALYSE_DEBUG
            qDebug() << "S03-Rtd=" <<mTemp;
            #endif
        }
        else if(str.contains("S04-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mDongYa = result;
            #if ANALYSE_DEBUG
            qDebug() << "S04-Rtd=" <<mDongYa;
            #endif
        }
        else if(str.contains("S05-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mHumidity = result;
            #if ANALYSE_DEBUG
            qDebug() << "S05-Rtd=" <<mHumidity;
            #endif
        }
        else if(str.contains("S07-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mArea = result;
            #if ANALYSE_DEBUG
            qDebug() << "S07-Rtd=" <<mArea;
            #endif
        }
        else if(str.contains("S08-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mPresure = result;
            #if ANALYSE_DEBUG
            qDebug() << "S08-Rtd=" <<mPresure;
            #endif
        }
        else if(str.contains("B02-Rtd=")){
            #if ANALYSE_DEBUG
            qDebug() << "B02-Rtd=";
            #endif
        }
        else if(str.contains("S01-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S01-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S01-Avg"))) +1);
            mOxygen = result;
            #if ANALYSE_DEBUG
            qDebug() << "S01-Avg=" <<mOxygen;
            #endif
        }
        else if(str.contains("S02-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S02-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S02-Avg"))) +1);
            mFlowRate = result;
            #if ANALYSE_DEBUG
            qDebug() << "S02-Avg=" <<mFlowRate;
            #endif
        }
        else if(str.contains("S03-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S03-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S03-Avg"))) +1);
            mTemp = result;
            #if ANALYSE_DEBUG
            qDebug() << "S03-Avg=" <<mTemp;
            #endif
        }
        else if(str.contains("S04-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S04-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S04-Avg"))) +1);
            mDongYa = result;
            #if ANALYSE_DEBUG
            qDebug() << "S04-Avg=" <<mDongYa;
            #endif
        }
        else if(str.contains("S05-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S05-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S05-Avg"))) +1);
            mHumidity = result;
            #if ANALYSE_DEBUG
            qDebug() << "S05-Avg=" <<mHumidity;
            #endif
        }
        else if(str.contains("S07-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S07-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S07-Avg"))) +1);
            mArea = result;
            #if ANALYSE_DEBUG
            qDebug() << "S07-Avg=" <<mArea;
            #endif
        }
        else if(str.contains("S08-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("S08-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("S08-Avg"))) +1);
            mPresure= result;
            #if ANALYSE_DEBUG
            qDebug() << "S08-Avg=" <<mPresure;
            #endif
        }
        else if(str.contains("B02-Avg=")){
            str = str + QString(",");
            #if ANALYSE_DEBUG
            qDebug() << "B02-Avg=";
            #endif
        }
         else if(str.contains("01-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             mZsYanchen  = result;
             #if ANALYSE_DEBUG
             qDebug() << "01-ZsRtd=" <<mZsYanchen;
             #endif

         }
         else if(str.contains("02-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             mZsSO2  = result;
             #if ANALYSE_DEBUG
             qDebug() << "02-ZsRtd=" <<mZsSO2;
             #endif

         }
         else if(str.contains("03-ZsRtd=")){
             result = str.left(str.lastIndexOf(','));
             result = result.mid(result.lastIndexOf('=')+1);
             mZsNOx = result;
             #if ANALYSE_DEBUG
             qDebug() << "03-ZsRtd=" <<mZsNOx;
             #endif
         }
        else if(str.contains("01-Rtd=")){
             result = str.left(str.indexOf(','));
             result = result.mid(result.indexOf('=') +1);
             mYanchen = result;
             #if ANALYSE_DEBUG
             qDebug() << "01-Rtd=" <<mYanchen;
             #endif

        }
        else if(str.contains("02-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mSO2 = result;
            #if ANALYSE_DEBUG
            qDebug() << "02-Rtd=" <<mSO2;
            #endif
        }
        else if(str.contains("03-Rtd=")){
            result = str.left(str.indexOf(','));
            result = result.mid(result.indexOf('=') +1);
            mNOx = result;
            #if ANALYSE_DEBUG
            qDebug() << "03-Rtd=" <<mNOx;
            #endif
        }
         else if(str.contains("01-Avg=")){
             str = str + QString(",");
             result = str.left(str.indexOf(',',str.indexOf(QString("01-Avg"))));
             result = result.mid(result.indexOf('=',str.indexOf(QString("01-Avg"))) +1);
             mYanchen = result;
             #if ANALYSE_DEBUG
             qDebug() << "01-Avg=" <<mYanchen;
             #endif
         }
          else if(str.contains("02-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("02-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("02-Avg"))) +1);
            mSO2 = result;
            #if ANALYSE_DEBUG
            qDebug() << "02-Avg=" <<mSO2;
            #endif
         }
          else if(str.contains("03-Avg=")){
            str = str + QString(",");
            result = str.left(str.indexOf(',',str.indexOf(QString("03-Avg"))));
            result = result.mid(result.indexOf('=',str.indexOf(QString("03-Avg"))) +1);
            mNOx = result;
            #if ANALYSE_DEBUG
            qDebug() << "03-Avg=" <<mZsNOx;
            #endif
         }
         else if(str.contains("01-ZsAvg=")){
             str = str + QString(",");
             result = str.left(str.indexOf(',',str.indexOf(QString("01-ZsAvg"))));
             result = result.mid(result.indexOf('=',str.indexOf(QString("01-ZsAvg")))+1);
             mZsYanchen  = result;
             #if ANALYSE_DEBUG
             qDebug() << "01-ZsAvg=" <<mZsYanchen;
             #endif

         }
         else if(str.contains("02-ZsAvg=")){
             str = str + QString(",");
             result = str.left(str.indexOf(',',str.indexOf(QString("02-ZsAvg"))));
             result = result.mid(result.indexOf('=',str.indexOf(QString("02-ZsAvg")))+1);
             mZsSO2  = result;
             #if ANALYSE_DEBUG
             qDebug() << "02-ZsAvg=" <<mZsSO2;
             #endif

         }
         else if(str.contains("03-ZsAvg=")){
             str = str + QString(",");
             result = str.left(str.indexOf(',',str.indexOf(QString("03-ZsAvg"))));
             result = result.mid(result.indexOf('=',str.indexOf(QString("03-ZsAvg")))+1);
             mZsNOx = result;
             #if ANALYSE_DEBUG
             qDebug() << "03-ZsAvg=" <<mZsNOx;
             #endif

         }

    }
    ui->yanchengButton->setText(QString("烟尘\n") + QString("折算:") + mZsYanchen + QString("\n")+
                                 QString("实测:") + mYanchen );
    ui->so2Button->setText(QString("SO2\n") + QString("折算:") + mZsSO2 + QString("\n")+
                                 QString("实测:") + mSO2 );
    ui->No2Button->setText(QString("NOX\n") + QString("折算:") + mZsNOx + QString("\n")+
                                 QString("实测:") + mNOx );
    ui->oxygenButton->setText(QString("氧含量\n") + mOxygen);
    ui->flowRateButton->setText(QString("流速\n") + mFlowRate);
    ui->tempButton->setText(QString("温度\n") + mTemp);
    ui->humidityButton->setText(QString("湿度\n") + mHumidity);
    ui->pressureButton->setText(QString("压力\n") + mPresure);

    qDebug() <<"\n"<< "| "<< "CN"  << "      |     "<< mCn  <<"\n"
             <<"| " << "DateTime" << "|     "<<mDateTime <<"\n"
             <<"| " << "烟尘" << "    |     "<<mYanchen  << "\n"
             <<"| " << "烟尘折算" << "|     "<<mZsYanchen  << "\n"
             <<"| " << "SO2" << "     |     "<<mSO2 << "\n"
             <<"| " << "SO2折算" << " |     "<<mZsSO2 << "\n"
             <<"| " << "NOx" << "     |     "<<mNOx << "\n"
             <<"| " << "NOx折算" << " |     "<<mZsNOx << "\n"
             <<"| " << "氧含量" << "  |     "<<mOxygen<< "\n"
             <<"| " << "流速" << "    |     "<<mFlowRate << "\n"
             <<"| " << "温度" << "    |     "<<mTemp << "\n"
             <<"| " << "湿度" << "    |     "<<mHumidity << "\n"
             <<"| " << "压力" << "    |     "<<mPresure << "\n"
             <<"| " << "动压" << "    |     "<<mDongYa << "\n"
             <<"| " << "烟道截面积" << "|     "<<mArea;

#if (TEST_VERSION)
    QDateTime dateTime = QDateTime::fromString(mDateTime,QString("yyyyMMddhhmmss"));
    //qDebug()<<dateTime.date().month() << dateTime.date().year();

    if(dateTime.date().month() >= 8  ||dateTime.date().year() > 2017 ){
        QMessageBox::warning(this,QString(""),QString("试用版已经到期！"));
        exit(1);
    }
#endif

    if(mCn == QString("2011")){

        qDebug()<<"实时数据";
        return;
    }

    mParaList.clear();
    mParaList << mCn<< mDateTime << mYanchen << mZsYanchen
              << mSO2  << mZsSO2<< mNOx<< mZsNOx<< mOxygen
              << mFlowRate<< mTemp << mHumidity
              << mPresure << mDongYa << mArea;
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
    ui->tableWidget->setColumnCount(12);
    ui->tableWidget_2->setColumnCount(12);
    ui->tableWidget_3->setColumnCount(12);
    QStringList header;
    header << "时间" << " 烟 尘(mg/m³)" << "烟 尘 折 算(mg/m³)"<<  "SO2(mg/m³)" << "SO2 折算(mg/m³)"<<"NOX(mg/m³)"<<"NOX折算(mg/m³)"
           <<"氧含量(%)" << "流速(m³/h)" << "温度(℃)" << "湿度(%)"<< "压力(mpa)";
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

    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget_2->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    ui->tableWidget_3->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

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
