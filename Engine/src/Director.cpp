#include "Director.h"

Director::Director()
{
    //ctor
}

Director::~Director()
{
    //dtor
}
void Director::setCurrentWorld(GameObject* world)
{
    CurrentWorld=world;
}
GameObject* Director::getCurrentWorld()
{
    return CurrentWorld;
}
