#include "CrossRenderer.h"


void CrossRenderer::Start()
{
    Transform=&(gameobject->Transform);
    pRenderFramework=&(pApplication->renderframework);
}
void CrossRenderer::Update()
{
    if(!pApplication->Debug) return;
    Vector2 tempu,tempd,templ,tempr;
    tempu={0,-100};
    tempd={0,100};
    templ={-100,0};
    tempr={100,0};
    tempu.Rotate(Transform->getRotation());
    tempd.Rotate(Transform->getRotation());
    templ.Rotate(Transform->getRotation());
    tempr.Rotate(Transform->getRotation());

    tempu=tempu*Transform->getScale();
    tempd=tempd*Transform->getScale();
    templ=templ*Transform->getScale();
    tempr=tempr*Transform->getScale();
    tempu=tempu+Transform->getPosition();
    tempd=tempd+Transform->getPosition();
    templ=templ+Transform->getPosition();
    tempr=tempr+Transform->getPosition();
    pRenderFramework->Debug_Addline(tempu,tempd);
    pRenderFramework->Debug_Addline(templ,tempr);
}
