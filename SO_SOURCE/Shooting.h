#pragma once
#include "CommonInclude.h"
namespace so {
	class Shooting
	{
	public:
		Shooting(float spawnx, float spawny);
		~Shooting();
		void SetXposition(float getx) { shotX = getx; }
		void SetYposition(float gety) { shotY = gety; }

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
	private:
		float shotX;
		float shotY;
		float speed;

		bool goShot = false;
	};
}


