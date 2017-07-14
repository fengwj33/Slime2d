#include "Camera.h"
void Camera::OnCreated()
{
    ScrWidth=pApplication->WindowWidth;
    ScrHeight=pApplication->WindowHeight;
}
void Camera::FocusOn_Obj(GameObject* Obj,float Scale)
{

}
void Camera::FocusOn_Position(Vector2 position,float Scale)
{
    int x,y;
    x=position.x*Scale;
    y=position.y*Scale;
    gameobject->Transform.setLocalPosition({-x+ScrWidth/2,-y+ScrHeight/2});
    gameobject->Transform.setLocalScale(Scale);
}
void Camera::FocusOn_Rect(Rect rect,bool ScaleWithWidth)
{

}
