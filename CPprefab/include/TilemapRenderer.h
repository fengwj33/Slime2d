#ifndef TILEMAPRENDERER_H
#define TILEMAPRENDERER_H
#include"Slime2d.h"
struct TileLayer
{
    string LayerName;
    int LayerID;
    int LayerWidth;
    int LayerHeight;
    int* Data;
    string TextureName;
    string renderlayer;
    float scale;
    float depth;
    RenderPackage*renderPackage;
};
class TilemapRenderer:public Component
{
    public:
        virtual void Start();
        virtual void Update();
        virtual void OnDeleted();
        void LoadMap(char* filename,float textureScale);
        void AddRenderer(string LayerName,string TextureName,string renderlayer="default",float renderdepth=1);
        void AddObjLayer(string LayerName,string TextureName,string renderlayer="default",bool ZOrderSort=true);
        float TextureScale;
        TileMap MainMap;
        CREATE_CPN(TilemapRenderer);

    protected:
    private:


        vector<TileLayer> renderlist;
        RectTransform *Transform;


};

#endif // TILEMAPRENDERER_H
