#include "Cross.h"
#include "RectArea.h"
void Cross::Init()
{
    /*cr=CrossRenderer::CREATE;
    addComponent(cr);
    kr=keepRotation::CREATE;
    addComponent(kr);
    kr=(keepRotation*)getComponent("keepRotation");*/

    tr=TextureRenderer::CREATE;
    addComponent(tr);
    tr->TextureName="miniHero";
    tr->TextureIndex=0;
    tr->TextureScale=5;
    tr->AncherPoint={0.5,0.8};

    RectArea* ra=RectArea::CREATE;
    addComponent(ra);
    ra->rect.LocalSize={50,70};
    //ra->rect.LocalCenter={30,30};
    cr=CrossRenderer::CREATE;
    addComponent(cr);



    //kr=keepRotation::CREATE;
    //addComponent(kr);

    //cr=CrossRenderer::CREATE;
    //addComponent(cr);
}
