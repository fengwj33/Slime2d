#ifndef AUTOREMOVE_H
#define AUTOREMOVE_H
#include"Slime2d.h"

class AutoRemove:public Component
{
    public:
        virtual void Start();
        virtual void Update();
        void setLife(int life);
        CREATE_CPN(AutoRemove);
    protected:
    private:
        int Life;
        int timer;
};

#endif // AUTOREMOVE_H
