#include "databasesearch.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include<QString>
#include <qdebug.h>
#include <QList>
#include <QStringList>

dataBaseSearch::dataBaseSearch()
{
    mDate = "";
}

void dataBaseSearch::setSearchPara(QString date)
{
    mDate = date;
}

void dataBaseSearch::run()
{
    QStringList dataList_2061;
    QList<QStringList> list_2061;
    QStringList dataList_2031;
    QList<QStringList> list_2051;
    QStringList dataList_2051;
    QList<QStringList> list_2031;
    //小时数据
    QString cn2061  = QString("2061");
    //日数据
    QString cn2031  = QString("2031");
    //分钟数据
    QString cn2051  = QString("2051");
    mDate = QString("20160805155435");
    QSqlQuery query("data.db");
    qDebug()<<"dataBaseSearch :run";
    qDebug() << QString("select * from data_table where  dateTime=%1 and CN='%2' order by dateTime desc ").arg(QString("20160805155435")).arg(QString("2061"));
    query.exec(QString("select * from data_table where  dateTime=%1 and CN='%2' order by dateTime desc")
               .arg(mDate).arg(cn2061));
    while(query.next()){
        for(int i  = 2;i < 12;i ++){
            dataList_2061.push_back(query.value(i).toString());
        }
        qDebug()<<dataList_2061;
         list_2061.push_back(dataList_2061);
         dataList_2061.clear();
    }
    query.exec(QString("select * from data_table where  dateTime=%1 and CN='%2' order by dateTime desc")
               .arg(mDate).arg(cn2031));
    while(query.next()){
        for(int i  = 2;i < 12;i ++){
            dataList_2031.push_back(query.value(i).toString());
        }
        qDebug()<<dataList_2031;
         list_2031.push_back(dataList_2031);
          dataList_2031.clear();
    }
    query.exec(QString("select * from data_table where  dateTime=%1 and CN='%2' order by dateTime desc")
               .arg(mDate).arg(cn2051));
    while(query.next()){
        for(int i  = 2;i < 12;i ++){
            dataList_2051.push_back(query.value(i).toString());
        }
        qDebug()<<dataList_2051;
        list_2051.push_back(dataList_2051);
        dataList_2051.clear();
    }
    emit sendListData(list_2061,list_2031,list_2051);
}
