#include "config.h"
#include "QFile"
#include "QMessageBox"
#include "qdebug.h"
#include "QTextStream"

Config::Config(QWidget *parent)
{
  mParent = parent;
}

int Config::loadConfigData(QHash<QString,QString> *hashData)
{
    QString line;
    QStringList list;
    QFile data("config.dat");
    if (data.open(QFile::ReadOnly)) {
        QTextStream out(&data);
         while( !out.atEnd()) {
            line = out.readLine();
            list = line.split(":");
            hashData->insert(list.at(0),list.at(1));
         }
        return 0;
    }
    else{
        QMessageBox::warning(this->mParent,QString("敬告"),QString("请先配置屏的参数"));
        return -1;
    }
}
