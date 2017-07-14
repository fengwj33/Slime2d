#include "AudioSource.h"
void AudioSource::OnCreated()
{
    audio=new Audio();
}
void AudioSource::Start()
{

}
void AudioSource::Update()
{
    audio->visited=true;
    if(playnow)
    {
        playnow=false;
        if(audio->Audioclip==NULL) return;
        if(audio->playing==true)
        {
            pAudioFramework->HaltAudio(audio);
        }
        pAudioFramework->AddAudio(audio);
    }
}
void AudioSource::OnDeleted()
{
    pAudioFramework->HaltAudio(audio);
    if(audio!=NULL)
        delete audio;
}
void AudioSource::PlayNow()
{
    playnow=true;
}
void AudioSource::StopNow()
{
    pAudioFramework->HaltAudio(audio);
    playnow=false;
}
void AudioSource::setLoopTimes(int times)
{
    audio->Loop=times;
}
void AudioSource::setImportance(bool value)
{
    audio->Important=value;
}
bool AudioSource::isPlaying()
{
    if(audio==NULL)
        return false;
    else
        return audio->playing;
}
void AudioSource::setAudioClip(string ClipName)
{
    audio->Audioclip=pAudioFramework->GetClip(ClipName);
}

