#include "RenderFramework.h"
//------------------------------------------------------------------------------------------Class Texture
void Texture::setAlpha(int alpha)
{
    if(alpha!=Alpha)
    {
        Alpha=alpha;
        SDL_SetTextureAlphaMod(texture,alpha);
    }
}
Texture::~Texture()
{
    if(texture!=NULL) SDL_DestroyTexture(texture);
    texture=NULL;
}
//------------------------------------------------------------------------------------------Class TextureSheet
TextureAtlas::TextureAtlas(string name,SDL_Renderer* MainRenderer,char* filename,int tile_x,int tile_y)
{
    SDL_Surface* temp;
    temp=IMG_Load(filename);
    texture=SDL_CreateTextureFromSurface(MainRenderer,temp);
    //SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_ADD);
    rect.w=temp->w;
    rect.h=temp->h;
    SDL_FreeSurface(temp);
    Tile_x=tile_x;
    Tile_y=tile_y;
    Tile_width=rect.w/Tile_x;
    Tile_height=rect.h/Tile_y;
    Name=name;
}
TextureAtlas::TextureAtlas(string name,SDL_Renderer* MainRenderer, char* filename,int tile_size)
{
    SDL_Surface* temp;
    temp=IMG_Load(filename);
    texture=SDL_CreateTextureFromSurface(MainRenderer,temp);
    //SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_ADD);
    rect.w=temp->w;
    rect.h=temp->h;
    SDL_FreeSurface(temp);
    Tile_width=tile_size;
    Tile_height=tile_size;
    Tile_x=rect.w/Tile_width;
    Tile_y=rect.h/Tile_height;
    Name=name;
}
SDL_Rect TextureAtlas::getTextureRect(int index)
{
    SDL_Rect temp;
    temp.x=index % Tile_x;
    temp.y=(index-temp.x)/Tile_x;
    temp.x*=Tile_width;
    temp.y*=Tile_height;
    temp.w=Tile_width;
    temp.h=Tile_height;
    return temp;
}
TextureAtlas::~TextureAtlas()
{
    if(texture!=NULL) SDL_DestroyTexture(texture);
    texture=NULL;
}


//-----------------------------------------------------------------------------------------Class RenderLayer
RenderLayer::RenderLayer(RenderFramework* pframework)
{
    pRenderFramework=pframework;
    init();
}
void RenderLayer::init()
{
    renderList.clear();
}
void RenderLayer::addPackage(RenderPackage* renderPackage)
{
    renderList.push_back(renderPackage);
    return;
    /*
    float depth=renderPackage->depth;
    for(int i=0;i<renderList.size();i++)
    {
        if(renderList[i]->depth>depth)
        {
            renderList.insert(renderList.begin()+i,renderPackage);
            return;
        }
    }
    renderList.push_back(renderPackage);
    */
}
void RenderLayer::render()
{
    sort(renderList.begin(),renderList.end(),RenderLayer::comp);
    for(int i=0;i<renderList.size();i++)
    {
        pRenderFramework->RenderTexture(renderList[i]);
    }
    //std::cout<<renderList.size()<<std::endl;
}
bool RenderLayer::comp(RenderPackage* r1,RenderPackage* r2)
{
    if((r1->depth)>(r2->depth))
        return true;
    else
        return false;
}
//-----------------------------------------------------------------------------------------Class RenderFramework
bool RenderFramework::loadFramework()
{
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    TextureList.clear();
    Layers.clear();
    addLayer("default");
    return true;
}
bool RenderFramework::unloadFramework()
{
    for(int i=0;i<TextureList.size();i++)
    {
        delete TextureList[i];
    }
    TextureList.clear();
    SDL_Quit();
    return true;
}
bool RenderFramework::CreateWindow(int width,int height,char* title)
{
    Window =SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,height,NULL);
    if( Window == NULL )
    {
        return false;
    }
    MainRenderer=SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Window_width=width;
    Window_height=height;
    return true;
}
bool RenderFramework::DestroyWindow()
{
    SDL_DestroyRenderer(MainRenderer);
    SDL_DestroyWindow(Window);
    return true;
}
TextureAtlas* RenderFramework::CreateTextureAtlas(string name,char* filename,int tile_x,int tile_y)
{
    TextureAtlas *temp=new TextureAtlas(name,MainRenderer,filename,tile_x,tile_y);
    TextureList.push_back(temp);
    return temp;
}
TextureAtlas* RenderFramework::CreateTextureAtlas(string name,char* filename,int tileSize)
{
    TextureAtlas *temp=new TextureAtlas(name,MainRenderer,filename,tileSize);
    TextureList.push_back(temp);
    return temp;
}

TextureAtlas* RenderFramework::GetTextureAtlas(string name)
{
    for(int i=0;i<TextureList.size();i++)
    {
        if(TextureList[i]->Name==name)
            return TextureList[i];
    }
    return NULL;
}
void RenderFramework::RenderTexture(RenderPackage* rendertexture)
{
    if(rendertexture->rendertype==_SingleTexture)
    {
        SDL_Rect Rect=rendertexture->textureatlas->getTextureRect(rendertexture->index);
        SDL_Rect SrcRect;
        SDL_Point center;
        if(rendertexture->FlipX&&rendertexture->FlipY)
        {
            center.x=rendertexture->center.x*Rect.w*rendertexture->Scale;
            center.y=rendertexture->center.y*Rect.h*rendertexture->Scale;
        }
        else
        {
            if(rendertexture->FlipX)
                center.x=(1-rendertexture->center.x)*Rect.w*rendertexture->Scale;
            else
                center.x=rendertexture->center.x*Rect.w*rendertexture->Scale;
            if(rendertexture->FlipY)
                center.y=(1-rendertexture->center.y)*Rect.h*rendertexture->Scale;
            else
                center.y=rendertexture->center.y*Rect.h*rendertexture->Scale;
        }
        SrcRect.w=Rect.w*rendertexture->Scale;
        SrcRect.h=Rect.h*rendertexture->Scale;
        SrcRect.x=rendertexture->position.x-center.x;
        SrcRect.y=rendertexture->position.y-center.y;
        rendertexture->textureatlas->setAlpha(rendertexture->alpha);
        if(rendertexture->FlipX&&rendertexture->FlipY)
            SDL_RenderCopyEx(MainRenderer,rendertexture->textureatlas->texture,&Rect,&SrcRect,rendertexture->rotation+180,&center,SDL_FLIP_NONE);
        else if(rendertexture->FlipX)
            SDL_RenderCopyEx(MainRenderer,rendertexture->textureatlas->texture,&Rect,&SrcRect,rendertexture->rotation,&center,SDL_FLIP_HORIZONTAL);
        else if(rendertexture->FlipY)
            SDL_RenderCopyEx(MainRenderer,rendertexture->textureatlas->texture,&Rect,&SrcRect,rendertexture->rotation,&center,SDL_FLIP_VERTICAL);
        else
            SDL_RenderCopyEx(MainRenderer,rendertexture->textureatlas->texture,&Rect,&SrcRect,rendertexture->rotation,&center,SDL_FLIP_NONE);
    }
    else if(rendertexture->rendertype==_TileMap)
    {
        SDL_Rect Rect;
        SDL_Rect SrcRect;
        int dataPointer=0;
        int tilesize;
        tilesize=rendertexture->textureatlas->Tile_width*rendertexture->Scale;
        for(int y=0;y<rendertexture->rows;y++)
        {
            for(int x=0;x<rendertexture->cols;x++)
            {
                if(rendertexture->tileData[dataPointer]==0)
                {
                    dataPointer++;
                    continue;
                }
                Rect=rendertexture->textureatlas->getTextureRect(rendertexture->tileData[dataPointer]-1);
                SrcRect.w=tilesize;
                SrcRect.h=tilesize;
                SrcRect.x=rendertexture->position.x+tilesize*x;
                SrcRect.y=rendertexture->position.y+tilesize*y;
                SDL_RenderCopy(MainRenderer,rendertexture->textureatlas->texture,&Rect,&SrcRect);
                dataPointer++;
            }
        }
    }

}
void RenderFramework::addLayer(string LayerName)
{
    RenderLayer* temp=new RenderLayer(this);
    temp->LayerName=LayerName;
    Layers.push_back(temp);
}
void RenderFramework::addPackage(RenderPackage* rendertexture,string LayerName)
{
    for(int i=0;i<Layers.size();i++)
    {
        if(Layers[i]->LayerName==LayerName)
        {
            Layers[i]->addPackage(rendertexture);
            return;
        }
    }
}
void RenderFramework::renderLayers()
{
    for(int i=0;i<Layers.size();i++)
    {
        Layers[i]->render();
    }
}
void RenderFramework::initLayers()
{
    for(int i=0;i<Layers.size();i++)
    {
        Layers[i]->init();
    }
}
void RenderFramework::DebugOn()
{
    Debug=true;
}
void RenderFramework::DebugOff()
{
    Debug=false;
}

void RenderFramework::Debug_Addline(Vector2 from,Vector2 to)
{
    if(!Debug) return;
    line temp;
    temp.from=from;
    temp.to=to;
    DebugLines.push_back(temp);
}
void RenderFramework::Debug_Drawlines()
{
    if(!Debug) return;
    SDL_SetRenderDrawColor(MainRenderer,255,255,255,255);

    for(int i=0;i<DebugLines.size();i++)
    {
        SDL_RenderDrawLine(MainRenderer,DebugLines[i].from.x,DebugLines[i].from.y,DebugLines[i].to.x,DebugLines[i].to.y);
    }
}
void RenderFramework::Debug_initlines()
{
    if(!Debug) return;
    DebugLines.clear();
}
void RenderFramework::Debug_AddRect(Rect rect)
{
    if(!Debug) return;
    DebugRects.push_back(rect);
}
void RenderFramework::Debug_DrawRect()
{
    if(!Debug) return;
    SDL_SetRenderDrawColor(MainRenderer,255,0,255,255);
    Rect* rect;
    Vector2 p1,p2,p3,p4;
    for(int i=0;i<DebugRects.size();i++)
    {
        rect=&(DebugRects[i]);
        p1=rect->ScrCenter-Vector2::vector2(rect->ScrSize.x*rect->AncherPoint.x,rect->ScrSize.y*rect->AncherPoint.y);
        p2=rect->ScrCenter+Vector2::vector2(rect->ScrSize.x*(1-rect->AncherPoint.x),rect->ScrSize.y*(-rect->AncherPoint.y));
        p3=rect->ScrCenter+Vector2::vector2(rect->ScrSize.x*(-rect->AncherPoint.x),rect->ScrSize.y*(1-rect->AncherPoint.y));
        p4=rect->ScrCenter+Vector2::vector2(rect->ScrSize.x*(1-rect->AncherPoint.x),rect->ScrSize.y*(1-rect->AncherPoint.y));
        SDL_RenderDrawLine(MainRenderer,p1.x,p1.y,p2.x,p2.y);
        SDL_RenderDrawLine(MainRenderer,p4.x,p4.y,p2.x,p2.y);
        SDL_RenderDrawLine(MainRenderer,p1.x,p1.y,p3.x,p3.y);
        SDL_RenderDrawLine(MainRenderer,p3.x,p3.y,p4.x,p4.y);
    }
}
void RenderFramework::Debug_initRect()
{
    if(!Debug) return;
    DebugRects.clear();
}




void RenderFramework::flipScr()
{
    SDL_RenderPresent(MainRenderer);
}
void RenderFramework::Debug_delay(int Time)
{
    SDL_Delay(Time);
}
void RenderFramework::ClearScr()
{
    SDL_SetRenderDrawColor(MainRenderer,0,0,0,255);
    SDL_RenderClear(MainRenderer);
}
