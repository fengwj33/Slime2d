#ifndef AUDIOFRAMEWORK_H
#define AUDIOFRAMEWORK_H
#include"SDL.h"
#include"SDL_mixer.h"
#include<vector>
#include<string>
using namespace std;
class AudioClip
{
public:
    ~AudioClip();
    Mix_Chunk* Audio=NULL;
    string ClipName="NULL";
};

class Audio
{
public:
    AudioClip* Audioclip=NULL;
    int Loop=0;
    bool Important=false;
    bool visited=false;

    int Channel=0;
    bool playing=false;
};

class AudioFramework
{
    public:
        AudioFramework();
        virtual ~AudioFramework();
        void disVisitTheAudio();
        void ClearDisVisitedAudio();
        void CheckTheAudio();
        void AddAudio(Audio* audio);
        void HaltAudio(Audio*audio);
        void CreateAudioClip(string ClipName,char* filename);
        AudioClip* GetClip(string ClipName);
    protected:
    private:
        vector<AudioClip*>ClipList;
        vector<Audio*> AudioList;
};

#endif // AUDIOFRAMEWORK_H
