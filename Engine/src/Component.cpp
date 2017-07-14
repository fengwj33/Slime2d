#include "Component.h"
#include "Slime2d.h"
void Component::transmitPointer(Application* _Application)
{

    pApplication=_Application;
    pDirector=&(pApplication->director);
    pObManager =&(pApplication->ObManager);
    pRenderFramework=&(pApplication->renderframework);
    pAudioFramework=&(pApplication->audioframework);
    pInputFramework=&(pApplication->inputframework);
    OnCreated();
}
Component::~Component()
{
    OnDeleted();
    if(gameobject!=NULL)
        gameobject->removeComponent(this);
}
void Component::Start()
{

}
void Component::Update()
{

}
void Component::OnCreated()
{

}
void Component::OnDeleted()
{

}
