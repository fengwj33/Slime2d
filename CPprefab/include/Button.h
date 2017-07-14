#ifndef BUTTON_H
#define BUTTON_H
#include"Slime2d.h"
#include"RectArea.h"
#include"TextureRenderer.h"
class Button:public Component
{
    public:
        virtual void OnCreated();
        virtual void Start();
        virtual void Update();
        virtual void OnDeleted();
        void defaultCallBack();
        void setCallBack(CallBack callback);
        CREATE_CPN(Button);
    protected:
    private:
        RectArea* rectarea=NULL;
        Rect* rect;
        mouseListener listener;
        CallBack callbackfunction;
};

#endif // BUTTON_H
