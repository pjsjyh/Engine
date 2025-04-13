#pragma once

#include "CommonInclude.h"
#include "Component.h"
namespace so {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void SetPosition(float x, float y);
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		float mX;
		float mY;
	};
}


