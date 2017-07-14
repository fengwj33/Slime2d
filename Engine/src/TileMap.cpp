#include "TileMap.h"

TileMap::TileMap()
{
    //ctor
}

TileMap::~TileMap()
{
    if(tilemap!=NULL)
        delete tilemap;
}
void TileMap::loadMap(char * filename)
{
    char * xml = (char*) loadFile( filename, true );
    tilemap = NLLoadTmxMap( xml );
    NLTmxMapLayer* layer=(NLTmxMapLayer*)(tilemap->layers[0]);
}
int TileMap::getLayerID(string layername)
{
    NLTmxMapLayer* layer;
    for(int i=0;i<tilemap->layers.size();i++)
    {
        layer=(NLTmxMapLayer*)(tilemap->layers[i]);
        if(layer->name==layername)
            return i;
    }
    return -1;
}
Vector2 TileMap::getLayerSize(int layerID)
{
    Vector2 temp;
    NLTmxMapLayer* layer=(NLTmxMapLayer*)(tilemap->layers[layerID]);
    temp.x=layer->width;
    temp.y=layer->height;
    return temp;
}
Vector2 TileMap::getLayerSize(string layername)
{
    return getLayerSize(getLayerID(layername));
}
int TileMap::getLayerWidth(int layerID)
{
    NLTmxMapLayer* layer=(NLTmxMapLayer*)(tilemap->layers[layerID]);
    return layer->width;
}
int TileMap::getLayerHeight(int layerID)
{
    NLTmxMapLayer* layer=(NLTmxMapLayer*)(tilemap->layers[layerID]);
    return layer->height;
}


int* TileMap::getLayerData(int layerID)
{
    NLTmxMapLayer* layer=(NLTmxMapLayer*)(tilemap->layers[layerID]);
    return layer->data;
}
int* TileMap::getLayerData(string layerID)
{
    return getLayerData(getLayerID(layerID));
}
