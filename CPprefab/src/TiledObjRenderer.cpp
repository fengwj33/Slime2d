#include "TiledObjRenderer.h"
using namespace std;
void TiledObjRenderer::initTiled(GameObject* Source,int Obj_ID,string TextureName,string renderlayer,bool zOrderSort)
{
    char str[10];
    string Str;
    ZOrderSort=zOrderSort;
    TiledIsInited=true;
    O_tiledSource=Source;
    C_tiledSource=(TilemapRenderer*)(Source->getComponent("TilemapRenderer"));
    Tiles=&(C_tiledSource->MainMap);
    sprintf(str,"Obj_%d",Obj_ID);
    Str=str;
    int index=Tiles->getLayerID(str);
    Data=Tiles->getLayerData(index);
    ObjHeight=Tiles->getLayerHeight(index);
    ObjWidth=Tiles->getLayerWidth(index);
    renderPackage.textureatlas=pRenderFramework->GetTextureAtlas(TextureName);
    _renderlayer=renderlayer;
    _tileScale=C_tiledSource->TextureScale;
    TileSize=pRenderFramework->GetTextureAtlas(TextureName)->Tile_width;

    sprintf(str,"Obj_%d_Center",Obj_ID);
    Str=str;
    index=Tiles->getLayerID(str);
    int* attribData=Tiles->getLayerData(index);
    int i=0;
    CenterPoint={0,0};
    bool flag=false;
    for(int y=0;y<ObjHeight;y++)
    {
        for(int x=0;x<ObjWidth;x++)
        {
            if(attribData[i]==1)
            {
                CenterPoint.x=x;
                CenterPoint.y=y;
                flag=true;
                break;
            }
            i++;
        }
        if(flag) break;
    }
    CenterPoint.x*=TileSize*_tileScale;
    CenterPoint.y*=TileSize*_tileScale;






}
void TiledObjRenderer::Start()
{
    Transform=&(gameobject->Transform);

}
void TiledObjRenderer::Update()
{
    if(!TiledIsInited)
        return;
    renderPackage.position=Transform->getPosition()-CenterPoint*Transform->getScale();
    renderPackage.Scale=Transform->getScale()*_tileScale;
    renderPackage.rendertype=_TileMap;
    renderPackage.cols=ObjWidth;
    renderPackage.rows=ObjHeight;
    renderPackage.tileData=Data;
    if(ZOrderSort)
        renderPackage.depth=-Transform->getPosition().y;
    pRenderFramework->addPackage(&renderPackage,_renderlayer);






}
void TiledObjRenderer::OnDeleted()
{

}
