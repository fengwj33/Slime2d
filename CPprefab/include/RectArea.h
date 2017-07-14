#ifndef RECTAREA_H
#define RECTAREA_H
#include"Slime2d.h"

class RectArea:public Component
{
    public:
        Rect rect;
        virtual void OnCreated();
        virtual void Start();
        virtual void Update();
        CREATE_CPN(RectArea);
    protected:
    private:
};

#endif // RECTAREA_H
