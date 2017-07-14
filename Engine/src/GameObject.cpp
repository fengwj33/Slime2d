#include "GameObject.h"
#include "Slime2d.h"
#include<iostream>
using namespace std;
GameObject::GameObject()
{
    Name="GameObject";
    active=true;
    Child.clear();
    parent=NULL;

    Tag="default";

}
void GameObject::transmitPointer(Application* _Application)
{
    pApplication=_Application;
    pDirector=&(pApplication->director);
    pObManager =&(pApplication->ObManager);
    pRenderFramework=&(pApplication->renderframework);
    pAudioFramework=&(pApplication->audioframework);
    pInputFramework=&(pApplication->inputframework);
    pObManager->regGameObject(this,(char*)Tag.data());
    Init();
}
GameObject::~GameObject()
{
    GameObject* temp;
    Component* Ctemp;
    if(parent!=NULL) removeFromParent();
    pObManager->unregGameObject(this,(char*)Tag.data());
    for(int i=Child.size()-1;i>=0;i--)
    {
        temp=Child[i];
        temp->parent=NULL;
        Child.erase(Child.begin()+i);
        delete temp;
    }
    for(int i=Components.size()-1;i>=0;i--)
    {
        Ctemp=Components[i];
        Components.erase(Components.begin()+i);
        delete Ctemp;
    }

}
void GameObject::addChild(GameObject* gameObject,bool worldPositionStays)
{
    if(gameObject->parent!=NULL)
    {
        gameObject->removeFromParent();
    }
    Child.push_back(gameObject);
    gameObject->parent=this;
    if(worldPositionStays)
    {
        RectTransform &RSource=gameObject->Transform;
        RSource.setLocalPosition(Transform.getRelativePosition(RSource.getPosition()));
        RSource.setLocalRotation(RSource.getRotation()-Transform.getRotation());
    }
    transmitTransform(gameObject);
}
void GameObject::setParent(GameObject* gameObject,bool worldPositionStays)
{
    if(parent!=NULL)
    {
        removeFromParent();
    }
    if(gameObject!=NULL)
    {
        gameObject->addChild(this,worldPositionStays);
    }
    else
        parent=NULL;
}
void GameObject::printChilds()
{
    for(int i=0;i<Child.size();i++)
    {
        cout<<Child[i]->Name<<endl;
    }
}
void GameObject::removeChild(GameObject* gameObject)
{
    for(int i=0;i<Child.size();i++)
    {
        if(Child[i]==gameObject)
        {
            Child.erase(Child.begin()+i);
            return;
        }
    }
}
void GameObject::removeChild(string Name)
{
    for(int i=Child.size()-1;i>=0;i--)
    {
        if(Child[i]->Name==Name)
        {
            Child.erase(Child.begin()+i);
        }
    }
}
void GameObject::removeFromParent()
{
    parent->removeChild(this);
    parent=NULL;
}
string GameObject::getTag()
{
    return Tag;
}
void GameObject::setTag(string newtag)
{
    pObManager->unregGameObject(this,(char*)Tag.data());
    Tag=newtag;
    pObManager->regGameObject(this,(char*)Tag.data());
}

void GameObject::transmitTransform(GameObject* gameobject)
{
    gameobject->Transform.SetBaseTransform(Transform.CreateBaseTransform());
}




void GameObject::addComponent(Component* component)
{
    if(component->gameobject!=NULL)
        component->gameobject->removeComponent(component);
    Components.push_back(component);
    component->gameobject=this;
}
void GameObject::removeComponent(Component* component)
{
    for(int i=0;i<Components.size();i++)
    {
        if(Components[i]==component)
        {
            Components.erase(Components.begin()+i);
            component->gameobject=NULL;
            return;
        }
    }
}
Component* GameObject::getComponent(string name)
{
    for(int i=0;i<Components.size();i++)
    {
        if(Components[i]->Name==name)
        {
            return Components[i];
        }
    }
    return NULL;
}




void GameObject::Update()
{

}
void GameObject::SystemUpdate()
{
    if(!active)
        return;
    Update();
    for(int i=0;i<Components.size();i++)
    {
        if(Components[i]->inited==false)
        {
            Components[i]->Start();
            Components[i]->inited=true;
        }
        Components[i]->Update();
    }
    for(int i=0;i<Child.size();i++)
    {
        GameObject* temp=Child[i];
        if(Transform._isChanged)
        {
            transmitTransform(temp);
        }
        temp->Update();
        temp->SystemUpdate();
    }
    Transform._isChanged=false;
}
void GameObject::Init()
{
    //cout<<"Gameobject is inited"<<endl;
}
