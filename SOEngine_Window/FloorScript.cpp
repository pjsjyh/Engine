#include "FloorScript.h"

#include "CatScript.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "GameObject.h"
#include "Animator.h"
#include "Object.h"
#include "Rigidbody.h"
#include "AudioSource.h"
namespace so
{
	FloorScript::FloorScript()
	{
	}
	FloorScript::~FloorScript()
	{
	}
	void FloorScript::Initialize()
	{


	}
	void FloorScript::Update()
	{

	}
	void FloorScript::LateUpdate()
	{
	}
	void FloorScript::Render(HDC hdc)
	{
	}

	void FloorScript::OnCollisionEnter(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		Transform* playerTr = other->GetOwner()->GetComponent<Transform>();
		Collider* playerCol = other;

		Rigidbody* floorRb = this->GetOwner()->GetComponent<Rigidbody>();
		Transform* floorTr = this->GetOwner()->GetComponent<Transform>();
		Collider* floorCol = this->GetOwner()->GetComponent<Collider>();


		float len = fabs(playerTr->GetPosition().y - floorTr->GetPosition().y);
		float scale = fabs(playerCol->GetSize().y * 100 / 2.0f - floorCol->GetSize().y * 100 / 2.0f);

		if (len < scale)
		{
			Vector2 playerPos = playerTr->GetPosition();
			playerPos.y -= (scale - len) - 1.0f;

			playerTr->SetPos(playerPos);
		}
		AudioSource* as = GetOwner()->GetComponent<AudioSource>();
		//as->SetClip();
		as->SetLoop(true);
		as->Play();

		playerRb->SetGround(true);
	}

	void FloorScript::OnCollisionStay(Collider* other)
	{
	}

	void FloorScript::OnCollisionExit(Collider* other)
	{
		Rigidbody* playerRb = other->GetOwner()->GetComponent<Rigidbody>();
		playerRb->SetGround(false);
	}


}