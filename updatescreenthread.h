#ifndef UPDATESCREENTHREAD_H
#define UPDATESCREENTHREAD_H


#include "QThread"

class UpdateScreenThread :public QThread
{
public:
    UpdateScreenThread(int screen_num);
protected:
    void run();
private:
    int mScreenNum;


};

#endif // UPDATESCREENTHREAD_H
