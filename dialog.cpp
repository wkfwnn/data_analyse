#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(sendTimeString(QString)),parent,SLOT(receiveTimeString(QString)));
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    emit sendTimeString(ui->calendarWidget->selectedDate().toString(QString("yyyyMMdd")));

}
