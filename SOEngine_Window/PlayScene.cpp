#include "PlayScene.h"

namespace so {

	so::PlayScene::PlayScene()
	{
	}

	so::PlayScene::~PlayScene()
	{
	}

	void so::PlayScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}
	}

	void so::PlayScene::Update()
	{
		Scene::Update();
	}

	void so::PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void so::PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
}
