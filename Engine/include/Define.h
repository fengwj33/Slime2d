#ifndef DEFINE_H
#define DEFINE_H
#define pi 3.141592
#include<math.h>
#include <functional>
#define CREATE_OBJ(__TYPE__) \
static __TYPE__* create(Application* _Application) \
{ \
    __TYPE__ *pRet = new __TYPE__(); \
    pRet->transmitPointer(_Application);\
    return pRet; \
}

#define CREATE_CPN(__TYPE__) \
static __TYPE__* create(Application* _Application) \
{ \
    __TYPE__ *pRet = new __TYPE__(); \
    pRet->transmitPointer(_Application);\
    return pRet; \
}\
__TYPE__()\
{\
    inited=false;\
    gameobject=NULL;\
    Name=ToString(__TYPE__);\
}\
virtual ~__TYPE__()\
{\
    OnDeleted();\
}
#define ToString(x) #x
#define CREATE create(pApplication);


#define CALLBACK(__FUNCTION__,__TARGET___) std::bind(&__FUNCTION__,__TARGET___)
typedef std::function<void ()> CallBack;


class Vector2
{
public:
    float x,y;
    static Vector2 RotateVector(Vector2 Vector,float Angle,Vector2 BasePoint={0,0});
    static Vector2 vector2(float x,float y);
    Vector2 operator+(Vector2 Vector);
    Vector2 operator-(Vector2 Vector);
    Vector2 operator*(float n);
    void Rotate(float Angle,Vector2 BasePoint={0,0});
    void print();
};

class Rect
{
public:
    Vector2 ScrCenter;
    Vector2 LocalCenter={0,0};
    Vector2 ScrSize;
    Vector2 LocalSize={50,50};
    Vector2 AncherPoint={0.5,0.5};
    float x1,x2,y1,y2;
    void refreshRect(Vector2 BasePoint,float rotation,float Scale);
    bool inRect(Vector2 position);
};

#endif // DEFINE_H
