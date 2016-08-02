#ifndef UPDATELEDTHREAD_H
#define UPDATELEDTHREAD_H
#include "QThread"

class UpdateLedThread : public QThread
{
public:
    UpdateLedThread();
protected:
    void run();

};

#endif // UPDATELEDTHREAD_H
