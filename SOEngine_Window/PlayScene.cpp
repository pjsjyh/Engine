#include "PlayScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Input.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Texture.h"
#include "Resources.h"
namespace so {

	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		//게임오브젝트 만들기전에 리소스를 전부 Load해두면 좋다.

		{
		/*	bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"E:/study/c++study/SoEngine/Engine/Resources/CloudOcean.png");



			AddGameObject(bg, enums::eLayerType::BackGround);*/

			
			//graphcis::Texture* tex = new graphcis::Texture();
			//tex->Load(L"E:/study/c++study/SoEngine/Engine/Resources/CloudOcean.png");
			//sr->ImageLoad(L"E:/study/c++study/SoEngine/Engine/Resources/CloudOcean.png");
		}
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg =  Resources::Find<graphcis::Texture>(L"BG");
		sr->SetTexture(bg);
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"TitleScene");
		}

	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* tr
			= bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}
