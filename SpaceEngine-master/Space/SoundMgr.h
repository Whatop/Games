#pragma once

#ifndef _CSOUND_H_
#define _CSOUND_H_

#define SOUND_MAX 1.0f
#define SOUND_MIN 0.0f
#define SOUND_DEFAULT 0.5f
#define SOUND_WEIGHT 0.1f

class SoundMgr :public Singleton<SoundMgr>
{
private:
    static FMOD_SYSTEM* g_sound_system;

    FMOD_SOUND* m_sound;
    FMOD_CHANNEL* m_channel;

    float m_volume;
    FMOD_BOOL m_bool;
public:
    SoundMgr();
    SoundMgr(const char* path, bool loop);
    ~SoundMgr();

    static void Init();
    static void Release();

    void play();
    void pause();
    void resume();
    void stop();
    void volumeUp();
    void volumeDown();

    void Update(float deltaTime,float Time);
};
#endif
