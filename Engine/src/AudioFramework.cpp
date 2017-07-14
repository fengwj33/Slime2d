#include "AudioFramework.h"
AudioClip::~AudioClip()
{
    if(Audio!=NULL)
    {
        Mix_FreeChunk(Audio);
    }
}

AudioFramework::AudioFramework()
{
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    AudioList.clear();
    ClipList.clear();
}
AudioFramework::~AudioFramework()
{
    Mix_CloseAudio();
}
void AudioFramework::CreateAudioClip(string ClipName,char* filename)
{
    AudioClip* temp=new AudioClip();
    temp->Audio=Mix_LoadWAV(filename);
    temp->ClipName=ClipName;
    ClipList.push_back(temp);
}
AudioClip* AudioFramework::GetClip(string ClipName)
{
    AudioClip* temp;
    for(int i=0;i<ClipList.size();i++)
    {
        temp=ClipList[i];
        if(temp->ClipName==ClipName)
        {
            return temp;
        }
    }
    return NULL;
}
void AudioFramework::disVisitTheAudio()
{
    Audio* temp;
    for(int i=AudioList.size()-1;i>=0;i--)
    {
        temp=AudioList[i];
        temp->visited=false;
    }
}
void AudioFramework::ClearDisVisitedAudio()
{
    Audio* temp;
    for(int i=AudioList.size()-1;i>=0;i--)
    {
        temp=AudioList[i];
        if(temp->visited==false)
        {
            Mix_HaltChannel(temp->Channel);
            temp->playing=false;
            AudioList.erase(AudioList.begin()+i);
        }
    }
}
void AudioFramework::CheckTheAudio()
{
    Audio* temp;
    for(int i=AudioList.size()-1;i>=0;i--)
    {
        temp=AudioList[i];
        if(Mix_Playing(temp->Channel)==0)
        {
            temp->playing=false;
            AudioList.erase(AudioList.begin()+i);
        }
    }
}
void AudioFramework::AddAudio(Audio* audio)
{
    int temp;
    CheckTheAudio();
    temp=Mix_PlayChannel(-1,audio->Audioclip->Audio,audio->Loop);
    if(temp!=-1)
    {
        AudioList.push_back(audio);
        audio->Channel=temp;
        audio->playing=true;
    }
    else
    {
        Audio* atemp;
        for(int i=0;i<AudioList.size();i++)
        {
            atemp=AudioList[i];
            if(atemp->Important==false)
            {
                Mix_HaltChannel(atemp->Channel);
                atemp->playing=false;
                AudioList.erase(AudioList.begin()+i);
                temp=Mix_PlayChannel(-1,audio->Audioclip->Audio,audio->Loop);
                if(temp==-1) return;
                AudioList.push_back(audio);
                audio->Channel=temp;
                audio->playing=true;
                return;
            }
        }
    }
}
void AudioFramework::HaltAudio(Audio*audio)
{
    for(int i=0;i<AudioList.size();i++)
    {
        if(AudioList[i]==audio)
        {
            AudioList.erase(AudioList.begin()+i);
            Mix_HaltChannel(audio->Channel);
            audio->playing=false;
            return;
        }
    }
}
