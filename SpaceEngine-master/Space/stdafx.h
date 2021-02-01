#pragma once

typedef struct D3DXVECTOR2 Vec2;
typedef struct D3DXMATRIX Matrix;

#define dt App::GetInst()->DeltaTime
#define gt App::GetInst()->Time


#define _USE_MATH_DEFINES


template<class T>
inline void SafeDelete(T*& x);

#include<stdio.h>
#include<string>
#include<sstream>

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>

#include<map>
#include<list>
#include<vector>

#include<ctime>
#include<iostream>
#include<cmath>
#include<mmsystem.h> 

#include <fmod.h>
//

#include"Singleton.h"
#include"Input.h"
#include"Renderer.h"
#include"App.h"
#include"Object.h"
#include"Scene.h"
#include"ObjectMgr.h"
#include"CollisionMgr.h"
#include"SceneDirector.h"
#include"TextMgr.h"
#include"SoundMgr.h"
#include"Camera.h"
#include"Sprite.h"
#include"Animation.h"
#include"EffectMgr.h"
#include"LineMgr.h"
#include"Game.h"
//

template<class T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = static_cast<T*>(0);
};