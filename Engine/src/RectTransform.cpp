#include "RectTransform.h"
BaseTransform::BaseTransform()
{
    BasePoint={0,0};
    Rotation=0;
    Scale=1;
    FlipX=1;
    FlipY=1;
}
RectTransform::RectTransform()
{
    ParentTransform.BasePoint={0,0};
    ParentTransform.Rotation=0;
    ParentTransform.Scale=1;
    localPosition={0,0};
    Position={0,0};
    localRotation=0;
    Rotation=0;
    LocalScale=1;
    Scale=1;
    FlipX=1;
    FlipY=1;
    localFlipX=1;
    localFlipY=1;
    _isChanged=true;
}
void RectTransform::setLocalPosition(Vector2 position)
{
    _isChanged=true;
    localPosition=position;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
    Position=(Vector2::RotateVector(localPosition,ParentTransform.Rotation)*ParentTransform.Scale)+ParentTransform.BasePoint;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
}

Vector2 RectTransform::getLocalPosition()
{
    return localPosition;
}
Vector2 RectTransform::getPosition()
{
    return Position;
}
void RectTransform::setLocalRotation(float rotation)
{
    _isChanged=true;
    localRotation=rotation;
    Rotation=ParentTransform.Rotation+localRotation*FlipX*FlipY;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
    Position=(Vector2::RotateVector(localPosition,ParentTransform.Rotation)*ParentTransform.Scale)+ParentTransform.BasePoint;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
}
float RectTransform::getLocalRotation()
{
    return localRotation;
}
float RectTransform::getRotation()
{
    return Rotation;
}
void RectTransform::setLocalScale(float scale)
{
    _isChanged=true;
    LocalScale=scale;
    Scale=ParentTransform.Scale*LocalScale;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
    Position=(Vector2::RotateVector(localPosition,ParentTransform.Rotation)*ParentTransform.Scale)+ParentTransform.BasePoint;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
}
float RectTransform::getLocalScale()
{
    return LocalScale;
}
float RectTransform::getScale()
{
    return Scale;
}
BaseTransform RectTransform::CreateBaseTransform()
{
    BaseTransform temp;
    temp.BasePoint=Position;
    temp.Rotation=Rotation;
    temp.Scale=Scale;
    temp.FlipX=FlipX;
    temp.FlipY=FlipY;
    return temp;
}
void RectTransform::SetBaseTransform(BaseTransform basetransform)
{
    _isChanged=true;
    ParentTransform=basetransform;
    Scale=ParentTransform.Scale*LocalScale;
    FlipX=basetransform.FlipX*localFlipX;
    FlipY=basetransform.FlipY*localFlipY;
    Rotation=ParentTransform.Rotation+localRotation*FlipX*FlipY;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
    Position=(Vector2::RotateVector(localPosition,ParentTransform.Rotation)*ParentTransform.Scale)+ParentTransform.BasePoint;
    localPosition.x*=ParentTransform.FlipX;
    localPosition.y*=ParentTransform.FlipY;
}
Vector2 RectTransform::getRelativePosition(Vector2 positon)
{
    Vector2 temp;
    temp=positon-Position;
    temp.Rotate(-Rotation,Position);
    temp.x*=FlipX;
    temp.y*=FlipY;
    return temp;
}
void RectTransform::setLocalFlipX(bool flip)
{
    if(flip)
        localFlipX=-1;
    else
        localFlipX=1;
    FlipX=ParentTransform.FlipX*localFlipX;
}
void RectTransform::setLocalFlipY(bool flip)
{
    if(flip)
        localFlipY=-1;
    else
        localFlipY=1;
    FlipY=ParentTransform.FlipY*localFlipY;
}
bool RectTransform::getFlipX()
{
    if(FlipX==1)
        return false;
    else
        return true;
}
bool RectTransform::getFlipY()
{
    if(FlipY==1)
        return false;
    else
        return true;
}
bool RectTransform::getLocalFlipX()
{
    if(localFlipX==1)
        return false;
    else
        return true;
}
bool RectTransform::getLocalFlipY()
{
    if(localFlipY==1)
        return false;
    else
        return true;
}
