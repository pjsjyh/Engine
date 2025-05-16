#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Renderer.h"
#include "Animator.h"
#include <Cat.h>
#include "CatScript.h"
#include "Object.h"
#include "RigidBody.h"
#include "UIManager.h"
namespace so {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case so::PlayerScript::eState::Idle:
			idle();
			break;
		case so::PlayerScript::eState::Walk:
			move();
			break;

		case so::PlayerScript::eState::Sleep:
			break;
		case so::PlayerScript::eState::GiveWater:
			giveWater();
			break;

		case so::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		COLORREF color = mPixelMap->GetPixel(pos.x, pos.y + 50);

		Rigidbody* playerRb = GetOwner()->GetComponent<Rigidbody>();
		if (color == RGB(255, 0, 0))
		{
			playerRb->SetGround(true);

			pos.y -= 1;
			tr->SetPos(pos);
		}
		else
		{
			playerRb->SetGround(false);
		}


		
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::AttackEffect()
	{
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal/*, Vector2(100.0f, 100.0f)*/);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.2f);


		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPos(Vector2(100.0f, 100.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(0.0f);
	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		//other->GetOwner()->GetComponent<Transform>()->SetPos(Vector2(400.0f, 500.0f));
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			mState = PlayerScript::eState::GiveWater;
			mAnimator->PlayAnimation(L"FrontGiveWater", false);

			Vector2 mousePos = Input::GetMousePosition();
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			//rb->AddForce(Vector2(0.0f, 200.0f));
			Vector2 velocity = rb->GetVelocity();
			velocity.y = -500.0f;
			rb->SetVelocity(velocity);
			rb->SetGround(false);
		}
		//if (Input::GetKey(eKeyCode::S))
		//{
		//	//pos.y += 100.0f * Time::DeltaTime();
		//	rb->AddForce(Vector2(0.0f, -200.0f));
		//}
		if (Input::GetKeyDown(eKeyCode::I))
		{
			UIManager::Push(eUIType::HpBar);
			//UIManager::Push(eUIType::Button);

		}

		if (Input::GetKeyDown(eKeyCode::O))
		{
			UIManager::Pop(eUIType::HpBar);

		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();
		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, 200.0f));
		}
		if (Input::GetKey(eKeyCode::S))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, -200.0f));
		}
		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A) 
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete()) {
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}