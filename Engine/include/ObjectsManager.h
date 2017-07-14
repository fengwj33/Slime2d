#ifndef OBJECTSMANAGER_H
#define OBJECTSMANAGER_H
#include<vector>
#include<string>
using namespace std;
class GameObject;
class GMList
{
public:
    GMList(char* tag);
    string Tag;
    vector<GameObject*> GameObjects;
};
class ObjectsManager
{
    public:
        ObjectsManager();
        virtual ~ObjectsManager();
        void addTag(char* tag);
        void regGameObject(GameObject* gameObject,char* tag="");
        void unregGameObject(GameObject* gameObject,char* tag="");
        bool GOisExist(GameObject* gameObject,char* tag="");
    protected:
    private:
        vector<GameObject*> GameObjects;
        vector<GMList*> TagList;
};

#endif // OBJECTSMANAGER_H
