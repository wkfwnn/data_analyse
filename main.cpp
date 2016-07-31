#include "mwidget.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MWidget w;
    w.show();


    return a.exec();
}
