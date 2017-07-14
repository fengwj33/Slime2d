#ifndef ANIMATION_H
#define ANIMATION_H
#include"Slime2d.h"
#include"TextureRenderer.h"

class Animation:public Component
{
    public:
        virtual void OnCreated();
        virtual void Start();
        virtual void Update();
        virtual void OnDeleted();
        CREATE_CPN(Animation);
    protected:
    private:
        TextureRenderer* texturerenderer;

};

#endif // ANIMATION_H
