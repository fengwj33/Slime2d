#include "ObjectsManager.h"
#include<iostream>
using namespace std;
GMList::GMList(char* tag)
{
    Tag=tag;
    GameObjects.clear();
}
ObjectsManager::ObjectsManager()
{
    GMList* defaultList=new GMList("default");
    TagList.push_back(defaultList);
}

ObjectsManager::~ObjectsManager()
{
    //dtor
}

void ObjectsManager::addTag(char* tag)
{
    GMList* newList=new GMList(tag);
    TagList.push_back(newList);
}

void ObjectsManager::regGameObject(GameObject* gameObject,char* tag)
{
    string temp=(string)tag;
    if(temp=="") temp="default";
    for(int i=0;i<TagList.size();i++)
    {
        if(temp==TagList[i]->Tag)
        {
            TagList[i]->GameObjects.push_back(gameObject);
        }
    }
    return;
}
void ObjectsManager::unregGameObject(GameObject* gameObject,char* tag)
{
    string temp;
    temp=tag;
    if(temp=="") temp="default";
    for(int i=0;i<TagList.size();i++)
    {
        if(temp==TagList[i]->Tag)
        {
            for(int j=0;j<TagList[i]->GameObjects.size();j++)
            {
                if(TagList[i]->GameObjects[j]==gameObject)
                {
                    TagList[i]->GameObjects.erase(TagList[i]->GameObjects.begin() + j);
                    return;
                }
            }
        }
    }





}
bool ObjectsManager::GOisExist(GameObject* gameObject,char* tag)
{
    string temp=(string)tag;
    for(int i=0;i<TagList.size();i++)
    {
        if(temp==TagList[i]->Tag||temp=="")
        {
            for(int j=0;j<TagList[i]->GameObjects.size();j++)
            {
                if(TagList[i]->GameObjects[j]==gameObject)
                {
                    cout<<"~";
                    return true;
                }
            }
        }
    }
    cout<<"!";
    return false;
}
