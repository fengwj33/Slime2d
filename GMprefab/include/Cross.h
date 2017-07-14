#ifndef CROSS_H
#define CROSS_H
#include"Slime2d.h"
#include"CrossRenderer.h"
#include"keepRotation.h"
#include"TextureRenderer.h"
class Cross:public GameObject
{
    public:
        virtual void Init();
        CREATE_OBJ(Cross);
    protected:
    private:
        CrossRenderer* cr;
        keepRotation* kr;
        TextureRenderer* tr;
};

#endif // CROSS_H
