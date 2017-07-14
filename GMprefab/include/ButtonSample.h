#ifndef BUTTONSAMPLE_H
#define BUTTONSAMPLE_H
#include"Slime2d.h"
#include"TextureRenderer.h"
#include"RectArea.h"
#include"Button.h"
#include<string>
class ButtonSample:public GameObject
{
    public:
        virtual void Init();
        void mousedown();
        void setTexture(string texturename);
        CREATE_OBJ(ButtonSample);
    protected:
    private:
        TextureRenderer* texture;
        RectArea* rectarea;
        Button* button;
};

#endif // BUTTONSAMPLE_H
