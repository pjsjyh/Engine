#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
namespace so {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd);
		void Update();
		void LateUpdate();
		void Run();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;
		float mX, mY;
		GameObject mPlayer;
	};
}


