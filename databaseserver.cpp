#include "databaseserver.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <qdebug.h>
#include <QMessageBox>
#include<QFile>

dataBaseServer::dataBaseServer(QWidget *parent, bool *ret1)
{
    bool ret;
    QFile file("data.db");
    if(file.exists() == false){
        isDataBaseOK = false;
        *ret1 = isDataBaseOK;
        return;
    }
    QSqlDatabase *db  = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName("data.db");
    ret = db->open();
    if(ret != true){
        isDataBaseOK = false;
       *ret1 = isDataBaseOK;
        return;
    }
    mParaList = new QStringList();
    isDataBaseOK = true;
    *ret1 = isDataBaseOK;
    mParent = parent;
}

void dataBaseServer::setList(QStringList *list)
{
    *mParaList = *list;
}

void dataBaseServer::run()
{
    bool ok = false;
    if(mParaList->count()  > 0)
    {
        if( !isDataBaseOK) return;
        QSqlQuery query("data.db");
#if 1
        qDebug() <<QString("insert into data_table values"
                           " ('%1',%2,'%3','%4','%5','%6','%7','%8','%9','%10','%11');").arg(mParaList->at(0))
                   .arg(mParaList->at(1)).arg(mParaList->at(2)).arg(mParaList->at(3)).arg(mParaList->at(4))
                   .arg(mParaList->at(5)).arg(mParaList->at(6)).arg(olmParaList->at(7)).arg(mParaList->at(8))
                   .arg(mParaList->at(9)).arg(mParaList->at(10));
#endif
            ok = query.exec(QString("insert into data_table values"
                           " ('%1',%2,'%3','%4','%5','%6','%7','%8','%9','%10','%11','%12');").arg(mParaList->at(0))
                   .arg(mParaList->at(1)).arg(mParaList->at(2)).arg(mParaList->at(3)).arg(mParaList->at(4))
                   .arg(mParaList->at(5)).arg(mParaList->at(6)).arg(mParaList->at(7)).arg(mParaList->at(8))
                   .arg(mParaList->at(9)).arg(mParaList->at(10)).arg(mParaList->at(11)));
            if( !ok ){
                 QMessageBox::warning(mParent,QString("警告"),QString("无法插入数据到相应的数据库！"));
                 qDebug() << "can not insert data into database";
                 isDataBaseOK = false;
            }
    }
}
