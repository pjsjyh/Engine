#pragma once
#include "Component.h"
namespace so {
	using namespace so::math;
	class Camera:public Component
	{
	public:
		Vector2 CaluatePosition(Vector2 pos) { return pos - mDistance; };
		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; };
		Vector2 CaluateTilePosition(Vector2 pos) { return pos + mDistance; };
	private:
		//std::vector<GameObject*> mGameObjects;
		class GameObject* mTarget;

		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}


