#ifndef CROSSRENDERER_H
#define CROSSRENDERER_H
#include"Slime2d.h"

class CrossRenderer:public Component
{
    public:

        virtual void Start();
        virtual void Update();
        CREATE_CPN(CrossRenderer);
    protected:
    private:
        RectTransform *Transform;
        RenderFramework* pRenderFramework;
};

#endif // CROSSRENDERER_H
