#include "TilemapRenderer.h"
#include"TiledObjRenderer.h"
#include<iostream>
using namespace std;
void TilemapRenderer::Start()
{
    Transform=&(gameobject->Transform);
}
void TilemapRenderer::Update()
{
    TileLayer temp;
    for(int i=0;i<renderlist.size();i++)
    {
        temp=renderlist[i];
        RenderPackage* renderPackage=temp.renderPackage;
        renderPackage->position=Transform->getPosition();
        renderPackage->Scale=Transform->getScale()*temp.scale;
        renderPackage->textureatlas=pRenderFramework->GetTextureAtlas(temp.TextureName);
        renderPackage->rendertype=_TileMap;
        renderPackage->cols=temp.LayerWidth;
        renderPackage->rows=temp.LayerHeight;
        renderPackage->tileData=temp.Data;
        renderPackage->depth=temp.depth;
        pRenderFramework->addPackage(renderPackage,temp.renderlayer);
    }
}
void TilemapRenderer::OnDeleted()
{
    TileLayer temp;
    for(int i=0;i<renderlist.size();i++)
    {
        temp=renderlist[i];
        delete temp.renderPackage;
    }
}
void TilemapRenderer::LoadMap(char* filename,float textureScale)
{
    MainMap.loadMap(filename);
    TextureScale=textureScale;
}
void TilemapRenderer::AddRenderer(string LayerName,string TextureName,string renderlayer,float renderdepth)
{
    TileLayer temp;
    temp.LayerName=LayerName;
    temp.LayerID=MainMap.getLayerID(LayerName);
    temp.renderlayer=renderlayer;
    temp.TextureName=TextureName;
    temp.scale=TextureScale;
    temp.LayerWidth=MainMap.getLayerWidth(temp.LayerID);
    temp.LayerHeight=MainMap.getLayerHeight(temp.LayerID);
    temp.Data=MainMap.getLayerData(temp.LayerID);
    temp.renderPackage=new RenderPackage();
    temp.depth=renderdepth;
    renderlist.push_back(temp);
}
void TilemapRenderer::AddObjLayer(string LayerName,string TextureName,string renderlayer,bool ZOrderSort)
{
    GameObject* LayerRoot=GameObject::CREATE;
    gameobject->addChild(LayerRoot);
    int LayerID=MainMap.getLayerID(LayerName);
    int TileSize=pRenderFramework->GetTextureAtlas(TextureName)->Tile_width* TextureScale;
    int width=MainMap.getLayerWidth(LayerID);
    int height=MainMap.getLayerHeight(LayerID);
    int* Data=MainMap.getLayerData(LayerID);
    int temp=0;
    int Objx,Objy;
    for(int y=0;y<height;y++)
    {
        for(int x=0;x<width;x++)
        {
            if(Data[temp]!=0)
            {
                Objx=TileSize*x;
                Objy=TileSize*y;
                GameObject* TempObj=GameObject::CREATE;
                TiledObjRenderer* TempRend=TiledObjRenderer::CREATE;
                TempObj->addComponent(TempRend);
                TempRend->initTiled(gameobject,Data[temp],TextureName,renderlayer,ZOrderSort);
                LayerRoot->addChild(TempObj);
                TempObj->Transform.setLocalPosition({Objx,Objy});
            }
            temp++;
        }
    }








}
