#ifndef RECTTRANSFORM_H
#define RECTTRANSFORM_H
#include"Define.h"
class BaseTransform
{
public:
    BaseTransform();
    Vector2 BasePoint;
    float Rotation;
    float Scale;
    int FlipX;
    int FlipY;
};
class RectTransform
{
public:
    RectTransform();
    bool _isChanged;
    void setLocalPosition(Vector2 position);
    Vector2 getLocalPosition();
    Vector2 getPosition();
    void setLocalRotation(float rotation);
    float getLocalRotation();
    float getRotation();
    void setLocalScale(float scale);
    float getLocalScale();
    float getScale();
    void setLocalFlipX(bool flip);
    void setLocalFlipY(bool flip);
    bool getFlipX();
    bool getFlipY();
    bool getLocalFlipX();
    bool getLocalFlipY();

    BaseTransform CreateBaseTransform();
    void SetBaseTransform(BaseTransform basetransform);
    Vector2 getRelativePosition(Vector2 positon);
private:
    BaseTransform ParentTransform;
    Vector2 localPosition;
    Vector2 Position;
    float localRotation;
    float Rotation;
    float LocalScale;
    float Scale;
    int localFlipX;
    int localFlipY;
    int FlipX;
    int FlipY;

};

#endif // RECTTRANSFORM_H
