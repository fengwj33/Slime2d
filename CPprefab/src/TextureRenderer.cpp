#include "TextureRenderer.h"

void TextureRenderer::Start()
{
    Transform=&(gameobject->Transform);
}
void TextureRenderer::Update()
{
    if(TextureName=="") return;
    if(Transform->getPosition().x<-10 || (Transform->getPosition().x) >pApplication->WindowWidth+10)
        return;
    if(Transform->getPosition().y<-10 || Transform->getPosition().y>pApplication->WindowHeight+10)
            return;
    renderPackage.center=AncherPoint;
    renderPackage.FlipX=Transform->getFlipX();
    renderPackage.FlipY=Transform->getFlipY();
    renderPackage.index=TextureIndex;
    renderPackage.position=Transform->getPosition();
    renderPackage.rotation=Transform->getRotation();
    renderPackage.Scale=Transform->getScale()*TextureScale;
    renderPackage.textureatlas=pRenderFramework->GetTextureAtlas(TextureName);
    renderPackage.depth=depth;
    renderPackage.alpha=alpha;
    renderPackage.rendertype=_SingleTexture;

    //pRenderFramework->RenderTexture(&renderPackage);
    pRenderFramework->addPackage(&renderPackage,Layer);
    return;
}

