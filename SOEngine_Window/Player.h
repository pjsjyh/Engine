#pragma once
#include "../SO_SOURCE/GameObject.h"

namespace so
{

	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		int mHp;
	};
}
