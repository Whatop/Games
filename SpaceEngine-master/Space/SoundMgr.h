#pragma once
class SoundMgr :public Singleton<SoundMgr>
{
public:
	SoundMgr();
	~SoundMgr();

	DWORD LoadWAV(HWND hWnd, LPCTSTR lpszWave);
	void Stop();
};

