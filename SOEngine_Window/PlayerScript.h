#pragma once
#include "../SO_SOURCE//Script.h"
namespace so {
	class PlayerScript:public Script
	{
	public:
		PlayerScript();
		~PlayerScript();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	};

}