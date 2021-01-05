#include "stdafx.h"
#include "SoundMgr.h"


SoundMgr::SoundMgr()
{
}


SoundMgr::~SoundMgr()
{
}

DWORD SoundMgr::LoadWAV(HWND hWnd, LPCTSTR lpszWave)
{
	MCI_OPEN_PARMS      mciOpen; //파일을 로드
	MCI_PLAY_PARMS       mciPlay; //파일을 재생
	MCI_STATUS_PARMS   mciStatus; //파일의 상
	//WCHAR szFullPath[256] = L"../Sound/";
	//lstrcatW(szFullPath, pFileName);

	UINT wDeviceID = 0;
	DWORD Result;


	mciOpenParms.lpstrDeviceType = L"WaveAudio";

	//WaveAudio 대신 MPEGVideo를 사용하면 mp3 형식을 재생합니다.


	mciOpenParms.lpstrElementName = lpszWave;

	Result = mciSendCommand(wDeviceID, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpenParms);

	if (Result)
		return Result;

	wDeviceID = mciOpenParms.wDeviceID;

	mciPlayParms.dwCallback = (DWORD)hWnd;

	if (Result)
		return Result;


	return 0;
}
void SoundMgr::Stop()
{
	PlaySound(nullptr, NULL, SND_ASYNC);
}