#pragma once
#include "../SO_SOURCE//Script.h"
#include "../SO_SOURCE//Transform.h"
namespace so {
	class CatScript :public Script
	{
	public:
		enum class eState {
			SitDown,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection {
			Left,
			Right,
			Down,
			Up,
			End
		};
		CatScript();
		~CatScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:
		void sitDown();
		void move();
		void LayDown();
		void PlayWalkAnimationBydirection(eDirection dir);
		void translate(Transform* tr);
	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		float mTime;
		float mDeathTime;
	};

}