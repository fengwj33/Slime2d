#ifndef AUDIOSOURCE_H
#define AUDIOSOURCE_H
#include"Slime2d.h"

class AudioSource:public Component
{
    public:
        virtual void OnCreated();
        virtual void Start();
        virtual void Update();
        virtual void OnDeleted();
        bool isPlaying();
        void PlayNow();
        void StopNow();
        void setLoopTimes(int times);
        void setImportance(bool value);
        void setAudioClip(string ClipName);
        CREATE_CPN(AudioSource);
    protected:
    private:
        Audio* audio=NULL;
        bool playnow=false;
};

#endif // AUDIOSOURCE_H
