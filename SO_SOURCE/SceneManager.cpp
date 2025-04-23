#include "SceneManager.h"

namespace so {
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}
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

	void SceneManager::Release()
	{
		
		for (auto& iter : mScene) {
			delete iter.second;
			iter.second = nullptr;
;		}
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

}
