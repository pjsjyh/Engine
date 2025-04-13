#include "SceneManager.h"

namespace so {
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	void so::SceneManager::Initialize()
	{
	}

	void so::SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void so::SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void so::SceneManager::Render(HDC hdc)

	{
		mActiveScene->Render(hdc);

	}

}
