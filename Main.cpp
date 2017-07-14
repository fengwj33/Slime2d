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
    //�����ʼ��
    Application* pApplication=new Application();
    RenderFramework* pRenderFramework=&(pApplication->renderframework);
    Director* pDirector=&(pApplication->director);
    AudioFramework* pAudioFramework=&(pApplication->audioframework);
    pApplication->setWindowTitle("HelloWorld");
    //pApplication->Debug=true;//����debugΪtrue
    pApplication->InitGame();
    pApplication->fps=60;

    //�����Ⱦͼ��
    pRenderFramework->addLayer("Map");
    pRenderFramework->addLayer("Sprite");
    pRenderFramework->addLayer("UI");

    //����ͼƬ��Դ
    pRenderFramework->CreateTextureAtlas("Button","Resources\\Button.png",1,3);
    pRenderFramework->CreateTextureAtlas("miniHero","Resources\\miniHero.png",5,5);
    pRenderFramework->CreateTextureAtlas("Tiletest","Resources\\test.png",32);
    //������Ƶ
    pAudioFramework->CreateAudioClip("Jet","Resources\\test.wav");
    pAudioFramework->CreateAudioClip("Laser","Resources\\laser.mp3");
    //�����￪ʼ����Ϸ�߼���

    GameObject* root=GameObject::CREATE;//����һ����������Ϊ��Ϸ����





    GameObject* BackgroundMusicSourse=GameObject::CREATE;//����һ�������屳������Դ
    AudioSource* audiosource=AudioSource::CREATE;//�����������
    audiosource->setLoopTimes(0);//����������������Դ����
    audiosource->setAudioClip("Laser");
    audiosource->PlayNow();
    BackgroundMusicSourse->addComponent(audiosource);//Ϊ��������Դ����������
    root->addChild(BackgroundMusicSourse);//����Դ��������

    Cross* temp=Cross::CREATE;//�����Cross����һ�������õ�����Ԥ�裬�Դ�Crossrenderer TextureRenderer�����
    temp->Transform.setLocalPosition({100,100});//����λ��
    temp->Transform.setLocalScale(0.5);
    //temp->Transform.setLocalFlipX(true);
    //temp->Transform.setLocalFlipY(true);
    root->addChild(temp);//�������������

    Cross*c2=Cross::CREATE;//��������ͬ��
    c2->Transform.setLocalPosition({100,100});
    c2->Transform.setLocalScale(0.5);
    temp->addChild(c2);//��������Ϊtemp��������


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



    ButtonSample* bt=ButtonSample::CREATE;//����һ����ť
    bt->Transform.setLocalPosition({300,300});
    root->addChild(bt);
    Button* b=((Button*)bt->getComponent("Button"));
    b->setCallBack(CALLBACK(AudioSource::PlayNow,audiosource));//���ûص����� ʹ���°�ťʱ��ͣ���ֲ���







    pDirector->setCurrentWorld(root);//����������

    pApplication->StartGame();//��ʼ��Ϸ��ѭ��










    pApplication->UnloadGame();

}
