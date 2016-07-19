#include "mwidget.h"
#include "ui_mwidget.h"
#include "QLibrary"
#include "qdebug.h"

typedef int ( *pcom_open)(); //定义函数指针

MWidget::MWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MWidget)
{
    ui->setupUi(this);
    QLibrary mylib("BX_IV.dll");
           if(mylib.load())
           {

                   pcom_open open=(pcom_open)mylib.resolve("Initialize");
                   if(open)
                   {
                           open(); //在这里调用DLL里的函数
                           qDebug()<<"jiexichenggong!";
                           qDebug()<<open();
                   }
                   else
                   {

                   }
           }
           else
           {

           }
}

MWidget::~MWidget()
{
    delete ui;
}
