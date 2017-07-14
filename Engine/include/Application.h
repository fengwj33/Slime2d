#ifndef APPLICATION_H
#define APPLICATION_H
#include"Director.h"
#include"ObjectsManager.h"
#include"AudioFramework.h"
#include"InputFramework.h"
#include<string>
using namespace std;
class Application
{
    public:
        Director director;
        ObjectsManager ObManager;
        RenderFramework renderframework;
        AudioFramework audioframework;
        InputFramework inputframework;
        bool Debug=false;
        int fps=60;
        void InitGame();
        void UnloadGame();
        void setWindowSize(int width,int height);
        void setWindowTitle(string title);
        void StartGame();
        int WindowWidth=640,WindowHeight=480;
    protected:
    private:

        string Title="Slime2d";
};

#endif // APPLICATION_H
