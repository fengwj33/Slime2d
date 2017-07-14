#ifndef INPUTFRAMEWORK_H
#define INPUTFRAMEWORK_H
#include"SDL.h"
#include"Define.h"
#include<vector>
#define MOUSE_UP 0
#define MOUSE_DOWN 1
#define MOUSE_MOVE 2
using namespace std;
class keyListener
{
public:

};
class mouseListener
{
public:
    Rect* rect;
    bool visited=false;
    bool listening=false;
    bool MouseDown=false;
    bool MouseUp=false;
    bool MousePass=false;
};
class InputFramework
{
    public:
        InputFramework();
        void refreshEvents();
        bool quit=false;
        Vector2 getMousePosition();
        bool MouseDown;

        void addMouseListener(mouseListener* listener);
        void removeMouseListener(mouseListener* listener);
        void disvisitAllListener();
        void clearTheListener();

        bool refreshmouseListener(Vector2 position,int EventType);
    protected:
    private:
        SDL_Event event;
        Vector2 MousePosition;
        vector<mouseListener*> mListeners;
};

#endif // INPUTFRAMEWORK_H
