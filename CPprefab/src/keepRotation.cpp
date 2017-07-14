#include "keepRotation.h"
void keepRotation::Start()
{
    Transform=&(gameobject->Transform);

}
void keepRotation::Update()
{
    Transform->setLocalRotation(Transform->getLocalRotation()+dr/pApplication->fps);
}
