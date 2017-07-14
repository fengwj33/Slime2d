#include<iostream>
#include<Slime2d.h>
#include"CrossRenderer.h"
#include"TextureRenderer.h"
#include"keepRotation.h"
#include"AudioSource.h"
#include"AutoRemove.h"
#include"Cross.h"
#include"ButtonSample.h"
#include"TilemapRenderer.h"
#include"Camera.h"
#include"TiledObjRenderer.h"
using namespace std;
int main()
{
    //引擎初始化
    Application* pApplication=new Application();
    RenderFramework* pRenderFramework=&(pApplication->renderframework);
    Director* pDirector=&(pApplication->director);
    AudioFramework* pAudioFramework=&(pApplication->audioframework);
    pApplication->setWindowTitle("HelloWorld");
    //pApplication->Debug=true;//设置debug为true
    pApplication->InitGame();
    pApplication->fps=60;

    //添加渲染图层
    pRenderFramework->addLayer("Map");
    pRenderFramework->addLayer("Sprite");
    pRenderFramework->addLayer("UI");

    //加载图片资源
    pRenderFramework->CreateTextureAtlas("Button","Resources\\Button.png",1,3);
    pRenderFramework->CreateTextureAtlas("miniHero","Resources\\miniHero.png",5,5);
    pRenderFramework->CreateTextureAtlas("Tiletest","Resources\\test.png",32);
    //加载音频
    pAudioFramework->CreateAudioClip("Jet","Resources\\test.wav");
    pAudioFramework->CreateAudioClip("Laser","Resources\\laser.mp3");
    //从这里开始是游戏逻辑：

    GameObject* root=GameObject::CREATE;//创建一个空物体作为游戏世界





    GameObject* BackgroundMusicSourse=GameObject::CREATE;//创建一个空物体背景音乐源
    AudioSource* audiosource=AudioSource::CREATE;//创建声音组件
    audiosource->setLoopTimes(0);//以下三行是设置音源属性
    audiosource->setAudioClip("Laser");
    audiosource->PlayNow();
    BackgroundMusicSourse->addComponent(audiosource);//为背景声音源添加声音组件
    root->addChild(BackgroundMusicSourse);//将音源导入世界

    Cross* temp=Cross::CREATE;//这里的Cross类是一个测试用的物体预设，自带Crossrenderer TextureRenderer等组件
    temp->Transform.setLocalPosition({100,100});//设置位置
    temp->Transform.setLocalScale(0.5);
    //temp->Transform.setLocalFlipX(true);
    //temp->Transform.setLocalFlipY(true);
    root->addChild(temp);//将物体加入世界

    Cross*c2=Cross::CREATE;//以下三行同上
    c2->Transform.setLocalPosition({100,100});
    c2->Transform.setLocalScale(0.5);
    temp->addChild(c2);//将物体作为temp的子物体


    GameObject* TileObj=GameObject::CREATE;
    TilemapRenderer* TileRend=TilemapRenderer::CREATE;
    TileObj->addComponent(TileRend);
    TileRend->LoadMap("Resources\\test.tmx",1);
    TileRend->AddRenderer("Map","Tiletest","default",5);
    //TileRend->AddRenderer("subs","Tiletest","default",4);
    //TileRend->AddRenderer("Obj_1","Tiletest","Sprite",1);
    GameObject*CameraObj=GameObject::CREATE;
    Camera* CameraCpn=Camera::CREATE;
    CameraObj->addComponent(CameraCpn);
    CameraObj->addChild(TileObj);
    CrossRenderer*crossrend=CrossRenderer::CREATE;
    CameraObj->addComponent(crossrend);
    root->addChild(CameraObj);
    //CameraCpn->FocusOn_Position({100,100},1);

    TileRend->AddObjLayer("Objs","Tiletest","Sprite",true);
    //TileObj->Transform.setLocalScale(0.5);
    CameraCpn->FocusOn_Position({200,200},1);




    //root->addChild(TileObj);



    ButtonSample* bt=ButtonSample::CREATE;//设置一个按钮
    bt->Transform.setLocalPosition({300,300});
    root->addChild(bt);
    Button* b=((Button*)bt->getComponent("Button"));
    b->setCallBack(CALLBACK(AudioSource::PlayNow,audiosource));//设置回调函数 使摁下按钮时暂停音乐播放







    pDirector->setCurrentWorld(root);//设置主世界

    pApplication->StartGame();//开始游戏主循环










    pApplication->UnloadGame();

}
