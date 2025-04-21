#include "PlayScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "GameObject.h"

#include "TitleScene.h"
#include "SceneManager.h"
#include "Object.h"
#include "Input.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Renderer.h"
#include "Animator.h"
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

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Player, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<PlayerScript>();
		renderer::mainCamera = cameraComp;



		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
	/*	SpriteRenderer* sr
			= mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		mPlayer->AddComponent<PlayerScript>();

		/*graphcis::Texture* packmanTexture =  Resources::Find<graphcis::Texture>(L"MapleEffect");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);

		animator->PlayAnimation(L"CatFrontMove", true);*/

		graphcis::Texture* packmanTexture =  Resources::Find<graphcis::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", packmanTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		animator->CreateAnimation(L"RightWalk", packmanTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		animator->CreateAnimation(L"UpWalk", packmanTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		animator->CreateAnimation(L"LeftWalk", packmanTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		animator->CreateAnimation(L"SitDown", packmanTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		animator->CreateAnimation(L"Grooming", packmanTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);


		animator->PlayAnimation(L"SitDown", false);
		mPlayer->GetComponent<Transform>()->SetPos(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
	/*	sr->SetTexture(packMan);*/


		GameObject* bg = object::Instantiate<Player>(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr
			= bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

		GameObject* bg2 = object::Instantiate<Player>(enums::eLayerType::Particle/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr2
			= bg2->AddComponent<SpriteRenderer>();
		graphcis::Texture* bbTexture = Resources::Find<graphcis::Texture>(L"Bubble");
		bgSr2->SetTexture(bbTexture);

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

		/*wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);*/
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
