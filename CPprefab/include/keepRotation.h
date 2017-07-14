#ifndef KEEPROTATION_H
#define KEEPROTATION_H
#include"Slime2d.h"

class keepRotation:public Component
{
    public:
        float dr=360;
        void Start();
        void Update();
        CREATE_CPN(keepRotation);
    protected:
    private:
        RectTransform* Transform;
};

#endif // KEEPROTATION_H
