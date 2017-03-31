#include "mwidget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <qdebug.h>
#include <QMetaType>
#include <QStringList>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QList<QStringList>>("QList<QStringList>");
    MWidget w;
    w.show();
    return a.exec();
}
