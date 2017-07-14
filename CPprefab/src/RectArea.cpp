#include "RectArea.h"

void RectArea::OnCreated()
{

}
void RectArea::Start()
{

}
void RectArea::Update()
{

    if(gameobject->Transform.getFlipX()&&gameobject->Transform.getFlipY())
        rect.refreshRect(gameobject->Transform.getPosition(),gameobject->Transform.getRotation()+180,gameobject->Transform.getScale());
    else if(gameobject->Transform.getFlipX())
        rect.refreshRect(gameobject->Transform.getPosition(),(gameobject->Transform.getRotation()+90),gameobject->Transform.getScale());
    else if(gameobject->Transform.getFlipY())
        rect.refreshRect(gameobject->Transform.getPosition(),(gameobject->Transform.getRotation()-90),gameobject->Transform.getScale());
    else
        rect.refreshRect(gameobject->Transform.getPosition(),gameobject->Transform.getRotation(),gameobject->Transform.getScale());
    if(!pApplication->Debug) return;
    pRenderFramework->Debug_AddRect(rect);
}
