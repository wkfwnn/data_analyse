#ifndef UPDATESCREENTHREAD_H
#define UPDATESCREENTHREAD_H

#include "QThread"

class UpdateScreenThread :public QThread
{
public:
    UpdateScreenThread();
protected:
    void run();
};

#endif // UPDATESCREENTHREAD_H
