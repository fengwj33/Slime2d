#ifndef TEXTURERENDERER_H
#define TEXTURERENDERER_H
#include"Slime2d.h"

class TextureRenderer:public Component
{
    public:

        virtual void Start();
        virtual void Update();

        float depth=-1;
        string TextureName;
        string Layer="default";
        int TextureIndex=0;
        Vector2 AncherPoint={0.5,0.5};
        float TextureScale=1;
        int alpha=255;
        CREATE_CPN(TextureRenderer);
    protected:
    private:
        RectTransform *Transform;
        RenderPackage renderPackage;

};

#endif // TEXTURERENDERER_H
