#pragma once
#include "Scene.h"
namespace so {
	class ShootingScene : public Scene
	{
	public:
		ShootingScene();
		~ShootingScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}


