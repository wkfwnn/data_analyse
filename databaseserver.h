#ifndef DATABASESERVER_H
#define DATABASESERVER_H

#include "QThread"

class QSqlDatabase;
class QStringList;

class dataBaseServer : public QThread

{
public:
    dataBaseServer(QWidget *parent, bool *ret1);
    void setList(QStringList * list);
protected:
    void run();
private:
    QSqlDatabase *db;
    QStringList *mParaList;
    QString mDate;
    bool isDataBaseOK;
    QWidget *mParent;
};

#endif // DATABASESERVER_H
