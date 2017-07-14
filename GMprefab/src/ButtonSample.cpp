#include "ButtonSample.h"
#include<iostream>
void ButtonSample::Init()
{
    texture=TextureRenderer::CREATE;
    addComponent(texture);
    texture->TextureName="Button";
    rectarea=RectArea::CREATE;
    rectarea->rect.LocalSize={64,32};
    addComponent(rectarea);
    button=Button::CREATE;
    addComponent(button);
    //button->setCallBack(CALLBACK(ButtonSample::mousedown,this));
}

void ButtonSample::setTexture(string texturename)
{
    texture->TextureName=texturename;
}
void ButtonSample::mousedown()
{
    std::cout<<"MouseDown!"<<endl;
}
