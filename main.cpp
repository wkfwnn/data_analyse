#include "mwidget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <qdebug.h>
#include <QMetaType>
#include <QStringList>
#include <QList>
#include <qdebug.h>
#include <QFile>
#include <QtGlobal>
#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>
#include <QMutex>
#include<QDateTime>

#define MAX_LOG_FILE_SIZE    10485760

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
 {
     static bool is_opened = false;
     static QFile file("log.txt");
     static QTextStream text_stream(&file);
     static QMutex mutex;
     mutex.lock();

#if 0
     switch (type) {
     case QtDebugMsg:
         qDebug() <<"nimei\n";
         fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtInfoMsg:
         fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtWarningMsg:
         fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtCriticalMsg:
         fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         break;
     case QtFatalMsg:
         fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
         abort();
     }
#endif

    QString message = QString("[%1]%2").arg(QDateTime::currentDateTime().toString("yyyyMMdd,hh:mm:ss")).arg(msg);
fileOpen:
    if(is_opened == false){
        if(file.open(QIODevice::WriteOnly | QIODevice::Append) == true)
            is_opened = true;
    }
    if(file.size() > MAX_LOG_FILE_SIZE ){
        file.close();
        file.remove();
        is_opened = false;
        goto fileOpen;
    }

#if defined (Q_OS_WIN)
    text_stream << message << "\r"<<endl;
#elif defined(Q_OS_LINUX)
    text_stream << message <<endl;
#endif
    file.flush();
    file.close();
    mutex.unlock();
 }


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qInstallMessageHandler(myMessageOutput);
    qRegisterMetaType<QList<QStringList>>("QList<QStringList>");
    MWidget w;
    w.show();
    return a.exec();
}
