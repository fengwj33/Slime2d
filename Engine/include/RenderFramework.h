#ifndef RENDERFRAMEWORK_H
#define RENDERFRAMEWORK_H
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include<algorithm>
#include<iostream>
#include <string>
#include"Define.h"
#undef main
using namespace std;
class Texture
{
public:
    SDL_Texture* texture=NULL;
    SDL_Rect rect;
    void setAlpha(int alpha);
    virtual ~Texture();
protected:
    int Alpha=255;
};
class TextureAtlas:public Texture
{
public:
    string Name;
    TextureAtlas(string name,SDL_Renderer* MainRenderer, char* filename,int tile_x,int tile_y);
    TextureAtlas(string name,SDL_Renderer* MainRenderer, char* filename,int tile_size);
    SDL_Rect getTextureRect(int index);
    int Tile_x,Tile_y;
    int Tile_width,Tile_height;
    virtual ~TextureAtlas();
};


enum RenderType
{
    _SingleTexture,
    _TileMap,
};

class RenderPackage
{
public:
    RenderType rendertype;
    TextureAtlas* textureatlas;




    int index;
    float Scale;
    Vector2 center;
    Vector2 position;
    float rotation;
    bool FlipX;
    bool FlipY;
    float depth;
    int alpha;


    int* tileData;
    int cols,rows;
};
class line
{
public:
    Vector2 from,to;
};



class RenderFramework;
class RenderLayer
{
public:
    RenderLayer(RenderFramework* pframework);
    RenderFramework* pRenderFramework;
    void init();
    string LayerName;
    void addPackage(RenderPackage* renderPackage);
    void render();
    vector<RenderPackage*> renderList;
    static bool comp(RenderPackage* r1,RenderPackage* r2);
};
class RenderFramework
{
    public:
        //init the Framework
        bool loadFramework();
        bool unloadFramework();
        //create the window
        bool CreateWindow(int width,int height,char* title);
        bool DestroyWindow();
        //create the Texture
        TextureAtlas* CreateTextureAtlas(string name,char* filename,int tile_x,int tile_y);
        TextureAtlas* CreateTextureAtlas(string name,char* filename,int tileSize);
        TextureAtlas* GetTextureAtlas(string name);

        void RenderTexture(RenderPackage* rendertexture);

        void addLayer(string LayerName);
        void addPackage(RenderPackage* rendertexture,string LayerName);
        void renderLayers();
        void initLayers();
        void DebugOn();
        void DebugOff();
        void Debug_Addline(Vector2 from,Vector2 to);
        void Debug_Drawlines();
        void Debug_initlines();
        void Debug_AddRect(Rect rect);
        void Debug_DrawRect();
        void Debug_initRect();


        void flipScr();
        void ClearScr();
        void Debug_delay(int Time);

    protected:
    private:
        SDL_Window* Window;
        int Window_width,Window_height;
        SDL_Renderer* MainRenderer;
        bool Debug=false;
        vector<TextureAtlas*> TextureList;
        vector<RenderLayer*>Layers;
        vector<line> DebugLines;
        vector<Rect> DebugRects;
};

#endif // RENDERFRAMEWORK_H
