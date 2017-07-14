#ifndef COMPONENT_H
#define COMPONENT_H
#include<string>
#include"RectTransform.h"
using namespace std;
class GameObject;
class Application;
class Director;
class ObjectsManager;
class RenderFramework;
class AudioFramework;
class InputFramework;
class Component
{
    public:
        void transmitPointer(Application* _Application);
        virtual  ~Component();
        string Name;
        bool active;
        bool inited;
        GameObject* gameobject;
        virtual void Start();
        virtual void Update();
        virtual void OnCreated();
        virtual void OnDeleted();
        static Component* create(Application* _Application)
        {
            Component *pRet = new Component();
            pRet->transmitPointer(_Application);
            return pRet;
        }
        Component()
        {
            inited=false;
            gameobject=NULL;
            Name="Component";
        }
    protected:
        Application* pApplication;
        Director* pDirector;
        ObjectsManager* pObManager;
        RenderFramework* pRenderFramework;
        AudioFramework* pAudioFramework;
        InputFramework* pInputFramework;
    private:

};

#endif // COMPONENT_H
