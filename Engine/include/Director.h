#ifndef DIRECTOR_H
#define DIRECTOR_H
#include"RenderFramework.h"
#include"ObjectsManager.h"
using namespace std;

class GameObject;
class Director
{
    public:
        Director();
        virtual ~Director();
        void setCurrentWorld(GameObject* world);
        GameObject* getCurrentWorld();
    protected:
    private:
        GameObject* CurrentWorld=NULL;

};

#endif // DIRECTOR_H
