#ifndef CONFIG_H
#define CONFIG_H


#include "QHash"
#include "QWidget"

class Config
{
public:
    Config(QWidget *parent);
    int loadConfigData(QHash<QString, QString> *hashData);
private:
QWidget *mParent;
};

#endif // CONFIG_H
