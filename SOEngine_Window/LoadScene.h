#pragma once
#include "SceneManager.h"
#include "PlayScene.h"
#include "ShootingScene.h"
#include "TitleScene.h"
#include "ToolScene.h"
//
//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\SoEngine_Window.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\SoEngine_Window.lib")
//#endif

namespace so {
	void LoadScene()
	{
	/*	SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");*/

		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		//SceneManager::CreateScene<ShootingScene>(L"ShootingScene");

		SceneManager::LoadScene(L"ToolScene");
	};
}
