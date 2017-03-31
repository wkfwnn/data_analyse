#ifndef DATABASESEARCH_H
#define DATABASESEARCH_H

#include "QThread"
#include <QList>
#include<QStringList>

class dataBaseSearch : public QThread
{
    Q_OBJECT

public:
    dataBaseSearch();
    void setSearchPara(QString date);
signals:
    void sendListData(QList<QStringList> list_2061,QList<QStringList> list_2031, QList<QStringList> list_2051);
protected:
    void run();
private:
    QString mDate;
    QString mCn;
};

#endif // DATABASESEARCH_H
