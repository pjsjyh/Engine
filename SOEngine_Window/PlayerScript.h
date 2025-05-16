#pragma once
#include "../SO_SOURCE//Script.h"
#include "../SO_SOURCE//Texture.h"

namespace so {
	class PlayerScript:public Script
	{
	public:
		enum class eState {
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};
		PlayerScript();
		~PlayerScript();
		void Initialize() override; 
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetPixelMapTexture(graphics::Texture* texture) { mPixelMap = texture; }

		void AttackEffect();
	private:
		void idle();
		void move();
		void giveWater();
	private:
		eState mState;
		class Animator* mAnimator;

		graphics::Texture* mPixelMap;
		//void(*StartEvent)();
		//void(*CompleteEvent)();
		//void(*EndEvent)();

	};

}