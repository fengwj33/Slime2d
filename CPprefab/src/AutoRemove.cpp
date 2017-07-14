#include "AutoRemove.h"

void AutoRemove::Start()
{
    timer=Life*pApplication->fps;
}
void AutoRemove::Update()
{
    timer--;
    if(timer<=0)
        delete gameobject;
}
void AutoRemove::setLife(int life)
{
    Life=life;
}
