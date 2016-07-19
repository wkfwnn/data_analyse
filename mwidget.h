#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>

namespace Ui {
class MWidget;
}

class MWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MWidget(QWidget *parent = 0);
    ~MWidget();

private:
    Ui::MWidget *ui;
};

#endif // MWIDGET_H
