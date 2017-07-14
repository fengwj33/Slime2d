#ifndef TILEDOBJRENDERER_H
#define TILEDOBJRENDERER_H
#include"Slime2d.h"
#include"TilemapRenderer.h"
#include<iostream>
class TiledObjRenderer:public Component
{
    public:
        virtual void Start();
        virtual void Update();
        virtual void OnDeleted();
        void initTiled(GameObject* Source,int Obj_ID,string TextureName,string renderlayer,bool zOrderSort=true);
        CREATE_CPN(TiledObjRenderer);
    protected:
    private:
        bool TiledIsInited=false;
        GameObject* O_tiledSource;
        TilemapRenderer* C_tiledSource;
        TileMap* Tiles;
        int ObjWidth;
        int ObjHeight;
        int TileSize;
        int* Data;
        RectTransform *Transform;
        RenderPackage renderPackage;
        string _renderlayer;
        float _tileScale;
        bool ZOrderSort;
        Vector2 CenterPoint;





};

#endif // TILEDOBJRENDERER_H
