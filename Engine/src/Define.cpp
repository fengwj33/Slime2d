#include"Define.h"
#include<iostream>
using namespace std;
Vector2 Vector2::vector2(float x,float y)
{
    Vector2 temp={x,y};
    return temp;
}
Vector2 Vector2::RotateVector(Vector2 Vector,float Angle,Vector2 BasePoint)
{
    Vector2 Temp;
    float Sin,Cos;
    Angle=Angle/180*pi;
    Sin=sinf(Angle);
    Cos=cosf(Angle);
    Temp=BasePoint;
    Vector=Vector-BasePoint;
    Temp.x+=Cos*Vector.x-Sin*Vector.y;
    Temp.y+=Sin*Vector.x+Cos*Vector.y;
    return Temp;
}
void Vector2::Rotate(float Angle,Vector2 BasePoint)
{
    Vector2 Temp,Vector;
    Vector={x,y};
    float Sin,Cos;
    Angle=Angle/180*pi;
    Sin=sinf(Angle);
    Cos=cosf(Angle);
    Temp=BasePoint;
    Vector=Vector-BasePoint;
    Temp.x+=Cos*Vector.x-Sin*Vector.y;
    Temp.y+=Sin*Vector.x+Cos*Vector.y;
    x=Temp.x;
    y=Temp.y;
}
Vector2 Vector2::operator+(Vector2 Vector)
{
    Vector2 temp;
    temp.x=x+Vector.x;
    temp.y=y+Vector.y;
    return temp;
}
Vector2 Vector2::operator-(Vector2 Vector)
{
    Vector2 temp;
    temp.x=x-Vector.x;
    temp.y=y-Vector.y;
    return temp;
}
Vector2 Vector2::operator*(float n)
{
    Vector2 temp;
    temp.x=x*n;
    temp.y=y*n;
    return temp;
}

void Vector2::print()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

void Rect::refreshRect(Vector2 BasePoint,float rotation,float Scale)
{
    ScrCenter=Vector2::RotateVector(LocalCenter*Scale,rotation)+BasePoint;
    ScrSize=LocalSize*Scale;
    x1=ScrCenter.x-AncherPoint.x*ScrSize.x;
    x2=ScrCenter.x+(1-AncherPoint.x)*ScrSize.x;
    y1=ScrCenter.y-AncherPoint.y*ScrSize.y;
    y2=ScrCenter.y+(1-AncherPoint.y)*ScrSize.y;
}
bool Rect::inRect(Vector2 position)
{
    if(position.x>x1 && position.x<x2 && position.y>y1 && position.y<y2)
        return true;
    return false;
}
