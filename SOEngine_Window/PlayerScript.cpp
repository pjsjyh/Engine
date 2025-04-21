#include "PlayerScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"
namespace so {
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::SitDown)
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
		if (mAnimator == nullptr) {
			mAnimator = GetOwner()->GetComponent<Animator>();
		}
		switch (mState)
		{
		case PlayerScript::eState::SitDown:
			sitDown();
			break;
		case PlayerScript::eState::Walk:
			move();
			break;

		case PlayerScript::eState::Sleep:
			break;
		case PlayerScript::eState::Attack:
			break;
		default:
			break;
		}


		
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::sitDown()
	{
		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::A)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");

		}
		if (Input::GetKey(eKeyCode::W)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");

		}
		if (Input::GetKey(eKeyCode::S)) {
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");

		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPos(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A) 
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}