#pragma once
#include <SDKDDKver.h>

#define WIN32_LEAN_AND_MEAN 

//! Windows ��� ����
#include <Windows.h>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

//! C ��Ÿ�� ��� ����
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>

//! C++ ��Ÿ�� ��� ����
#include <iostream>
#include <random>
#include <bitset>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

//===================================
// # ���� ���� ��������� �̰��� �߰� #
//===================================
#include "CommonMacroFunction.h"
#include "RandomFunction.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"

//========================
// # �̱����� �̰��� �߰� #
//========================
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()

//============================
// # ��ũ�� # (������â �ʱ�ȭ)
//============================
#define WINNAME		 (LPTSTR)(TEXT("WindowsAPI"))

//#define FULLSCREEN

#ifdef FULLSCREEN
#define WINSTARTX	 1920
#define WINSTARTY	 0
#define WINSIZEX	 GetSystemMetrics(SM_CXSCREEN)
#define WINSIZEY	 GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE	 WS_POPUPWINDOW | WS_MAXIMIZE
#else
#define WINSTARTX	 400
#define WINSTARTY	 -10
#define WINSIZEX	 1000
#define WINSIZEY	 600
#define WINSTYLE	 WS_CAPTION | WS_SYSMENU
#endif

//===============================================
// # ��ũ�� �Լ� # (Ŭ�������� �����Ҵ�� �κ� ����)
//===============================================
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}

//=============
// # �������� #
//=============
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;