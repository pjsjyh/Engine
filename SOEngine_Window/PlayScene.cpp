#include "PlayScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
namespace so {

	so::PlayScene::PlayScene()
	{
	}

	so::PlayScene::~PlayScene()
	{
	}

	void so::PlayScene::Initialize()
	{
		/*for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}*/
		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(800, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(300, 450);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			Transform* tr
				= pl->AddComponent<Transform>();
			tr->SetPos(100, 650);

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= pl->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");

			AddGameObject(pl);
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
