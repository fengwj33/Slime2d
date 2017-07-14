#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <vector>
#include "Application.h"
#include "Director.h"
#include "RenderFramework.h"
#include "AudioFramework.h"
#include "RectTransform.h"
#include "InputFramework.h"
class Component;
class ObjectsManager;
using namespace std;

class GameObject
{
    public:
        string Name;
        bool active;
        GameObject();
        void transmitPointer(Application* _Application);
        virtual ~GameObject();
        GameObject* parent;//Don't Change this directly!!Please use the function setParent instead!!
        void addChild(GameObject* gameObject,bool worldPositionStays=false);
        void setParent(GameObject* gameObject,bool worldPositionStays=false);
        void removeChild(GameObject* gameObject);
        void removeChild(string Name);
        void removeFromParent();
        string getTag();
        void setTag(string newtag);
        void printChilds();

        RectTransform Transform;
        void transmitTransform(GameObject* gameobject);


        void addComponent(Component* component);
        void removeComponent(Component* component);
        Component* getComponent(string name);


        virtual void Init();
        virtual void Update();
        void SystemUpdate();


        CREATE_OBJ(GameObject);
    protected:
        Application* pApplication;
        Director* pDirector;
        ObjectsManager* pObManager;
        RenderFramework* pRenderFramework;
        AudioFramework* pAudioFramework;
        InputFramework* pInputFramework;
    private:
        string Tag;
        vector<GameObject*> Child;
        vector<Component*> Components;

};

#endif // GAMEOBJECT_H
