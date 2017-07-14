#include "Application.h"
#include "GameObject.h"
#include <SDL.h> //I decide to include this headfile because i want to use the function SDL_Delay. so if you want to transplant this engine to the other basic drawing platform like OpenGL es, the only thing you need to do is change here and replace the SDL_Delay.
#include<iostream>
void Application::setWindowSize(int width,int height)
{
    WindowWidth=width;
    WindowHeight=height;
}
void Application::setWindowTitle(string title)
{
    Title=title;
}
void Application::InitGame()
{
    renderframework.loadFramework();
    renderframework.CreateWindow(WindowWidth,WindowHeight,(char*)Title.data());
}
void Application::UnloadGame()
{
    renderframework.DestroyWindow();
    renderframework.unloadFramework();
}
void Application::StartGame()
{
    int c=0,cl=0,cn=0;
    int fl=0,fn=0,fd=0;
    float dt;
    if(director.getCurrentWorld()==NULL)
        return;
    SDL_Event event;
    cl=SDL_GetTicks();
    fl=SDL_GetTicks();
    if(!Debug)
        renderframework.DebugOff();
    while(true)
    {
        audioframework.disVisitTheAudio();
        renderframework.ClearScr();
        renderframework.initLayers();
        if(Debug)
            renderframework.DebugOn();
        if(Debug)
        {
            renderframework.Debug_initlines();
            renderframework.Debug_initRect();
        }

        director.getCurrentWorld()->SystemUpdate();
        renderframework.renderLayers();
        if(Debug)
        {
            renderframework.Debug_Drawlines();
            renderframework.Debug_DrawRect();
        }
        renderframework.DebugOff();
        renderframework.flipScr();
        fn=SDL_GetTicks();
        fd=fn-fl;
        fl=fn;
        dt=1000/fps-fd;
        if(dt<0) dt=0.1;

        audioframework.ClearDisVisitedAudio();
        audioframework.CheckTheAudio();
        inputframework.clearTheListener();
        SDL_Delay(dt);
        inputframework.refreshEvents();
        inputframework.disvisitAllListener();
        if(inputframework.quit)
            return;

        c++;
        if(c==10)
        {
            c=0;
            cn=SDL_GetTicks();
            std::cout<<1000/((float)(cn-cl)/10)<<endl;
            cl=cn;
        }
        fl=SDL_GetTicks();
    }
}
