#ifndef CAMERA_H
#define CAMERA_H
#include"Slime2d.h"

class Camera:public Component
{
    public:
        virtual void OnCreated();
        void FocusOn_Obj(GameObject* Obj,float Scale);
        void FocusOn_Position(Vector2 position,float Scale);
        void FocusOn_Rect(Rect rect,bool ScaleWithWidth=true);

        CREATE_CPN(Camera);
    protected:
    private:
        int ScrWidth,ScrHeight;

};

#endif // CAMERA_H
