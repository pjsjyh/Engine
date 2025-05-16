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
#include "Cat.h"
#include "CatScript.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"
#include "CollisionManager.h"
#include "Tile.h"
#include "TilemapRenderer.h"
#include "RigidBody.h"

#include "Floor.h"
#include "FloorScript.h"
#include "UIManager.h"

#include "AudioClip.h"
#include "AudioListener.h"
#include "AudioSource.h"
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


		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(522.0f, 225.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		//camera->AddComponent<PlayerScript>();
		renderer::mainCamera = cameraComp;

		
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
		object::DontDestroyOnLoad(mPlayer);
		mPlayer->AddComponent<AudioListener>();

		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* collider =  mPlayer->AddComponent<BoxCollider2D>();
		//CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* playerTex =  Resources::Find<graphics::Texture>(L"Player");
		Animator* playAnimator = mPlayer->AddComponent<Animator>();
		playAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.2f);
		playAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.2f);

		playAnimator->PlayAnimation(L"Idle", false);

		//전역함수로 넘겨줌. 그래서 주소와 함께 넘겨주는것
		playAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPos(Vector2(300.0f, 250.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
		mPlayer->AddComponent<Rigidbody>();

		Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(100.0f, 600.0f));
		floor->SetName(L"Floor");
		BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
		floorCol->SetSize(Vector2(3.0f, 1.0f));
		floor->AddComponent<FloorScript>();



		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		//cat->SetActive(false);

		cat->AddComponent<CatScript>();
		//cameraComp->SetTarget(cat);
		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		//catAnimator->CreateAnimation(L"DownWalk", catTex
		//	, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"RightWalk", catTex
		//	, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"UpWalk", catTex
		//	, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"LeftWalk", catTex
		//	, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"SitDown", catTex
		//	, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"Grooming", catTex
		//	, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		//catAnimator->CreateAnimation(L"LayDown", catTex
		//	, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		//catAnimator->PlayAnimation(L"SitDown", false);

		catAnimator->CreateAnimationByFolder(L"MushroomIdle", L"..\\Resources\\Mushroom", Vector2::Zero, 0.4f);

		catAnimator->PlayAnimation(L"MushroomIdle", false);
		BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();
		//CircleCollider2D* boxCatCollider = cat->AddComponent<CircleCollider2D>();
		boxCatCollider->SetOffset(Vector2(-50.0f, -50.0f));
		cat->GetComponent<Transform>()->SetPos(Vector2(100.0f, 100.0f));
		//cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		

		///
		/*Player* background = object::Instantiate<Player>(enums::eLayerType::BackGround);
		SpriteRenderer* sr
			= background->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"Background");
		Transform* tr = background->GetComponent<Transform>();

		bg->SetHeight(209.0f);
		bg->SetWidth(1032.0f);
		sr->SetSize(Vector2(2.0f, 2.0f));
		sr->SetTexture(bg);*/
		            



		///

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
		Scene::OnEnter();
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		UIManager::Push(eUIType::Button);
	}
	void PlayScene::OnExit()
	{
		UIManager::Pop(eUIType::Button);
		Scene::OnExit();
		/*Transform* tr
			= bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));*/
	}
}
