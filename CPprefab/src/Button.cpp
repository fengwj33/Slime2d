#include "Button.h"
#include<iostream>
using namespace std;
void Button::OnCreated()
{
    callbackfunction=CALLBACK(Button::defaultCallBack,this);
}
void Button::Start()
{
    rectarea=(RectArea*)(gameobject->getComponent("RectArea"));
}
void Button::OnDeleted()
{
    if(listener.listening)
        pInputFramework->removeMouseListener(&listener);
}
void Button::Update()
{
    listener.visited=true;
    if(rectarea==NULL)
    {
        rectarea=(RectArea*)(gameobject->getComponent("RectArea"));
        if(rectarea==NULL)
            return;
    }
    rect=&(rectarea->rect);
    listener.rect=rect;
    if(!listener.listening)
        pInputFramework->addMouseListener(&listener);

    TextureRenderer* temp;
    if(listener.MouseDown)
    {
        temp=((TextureRenderer*)(gameobject->getComponent("TextureRenderer")));
        temp->TextureIndex=2;
        callbackfunction();
    }
    if(listener.MouseUp)
    {
        temp=((TextureRenderer*)(gameobject->getComponent("TextureRenderer")));
        temp->TextureIndex=0;
    }
    listener.MouseDown=false;
    listener.MouseUp=false;

}
void Button::defaultCallBack()
{
    cout<<"warning:Please set the CallBack Function first if you want to use this button."<<endl;
}
void Button::setCallBack(CallBack callback)
{
    callbackfunction=callback;
}
