#pragma once
#include "Script.h"
#include "Transform.h"
namespace so
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}