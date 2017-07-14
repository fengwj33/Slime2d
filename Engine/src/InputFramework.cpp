#include "InputFramework.h"
InputFramework::InputFramework()
{
    mListeners.clear();
}
void InputFramework::refreshEvents()
{
    while( SDL_PollEvent( &event ) )
    {
        if( event.type == SDL_KEYDOWN )
        {

        }
        else if( event.type == SDL_QUIT )
        {
            quit = true;
        }
        else if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            if(!refreshmouseListener(Vector2::vector2(event.motion.x,event.motion.y),MOUSE_DOWN))
            {
                MouseDown=true;
                MousePosition=Vector2::vector2(event.motion.x,event.motion.y);
            }
        }
        else if(event.type ==SDL_MOUSEBUTTONUP )
        {
            if(!refreshmouseListener(Vector2::vector2(event.motion.x,event.motion.y),MOUSE_UP))
            {
                MouseDown=false;
                MousePosition=Vector2::vector2(event.motion.x,event.motion.y);
            }
            MouseDown=false;
        }
        else if(event.type==SDL_MOUSEMOTION)
        {
            refreshmouseListener(Vector2::vector2(event.motion.x,event.motion.y),MOUSE_MOVE);
            MousePosition=Vector2::vector2(event.motion.x,event.motion.y);
        }
        else
        {
            //SDL_GetScancodeFromKey()
        }
    }
}
void InputFramework::addMouseListener(mouseListener* listener)
{
    mListeners.push_back(listener);
    listener->listening=true;
    listener->visited=true;
}
void InputFramework::removeMouseListener(mouseListener* listener)
{
    for(int i=0;i<mListeners.size();i++)
    {
        if(mListeners[i]==listener)
        {
            mListeners[i]->listening=false;
            mListeners.erase(mListeners.begin()+i);
            return;
        }
    }
}
void InputFramework::disvisitAllListener()
{
    for(int i=0;i<mListeners.size();i++)
    {
        mListeners[i]->visited=false;
    }
}
void InputFramework::clearTheListener()
{
    mouseListener* temp;
    for(int i=mListeners.size()-1;i>=0;i--)
    {
        if(mListeners[i]->visited==false)
        {
            temp=mListeners[i];
            temp->listening=false;
            mListeners.erase(mListeners.begin()+i);
        }
    }
}
bool InputFramework::refreshmouseListener(Vector2 position,int EventType)
{
    bool temp=false;
    mouseListener* mtemp;
    if(EventType==MOUSE_DOWN)
    {
        for(int i=0;i<mListeners.size();i++)
        {
            mtemp=mListeners[i];
            if(mtemp->rect->inRect(position))
            {
                mtemp->MouseDown=true;
                temp=true;
            }
        }
    }
    if(EventType==MOUSE_UP)
    {
        for(int i=0;i<mListeners.size();i++)
        {
            mtemp=mListeners[i];
            if(mtemp->rect->inRect(position))
            {
                mtemp->MouseUp=true;

                temp=true;
            }
        }
    }
    return temp;
}
