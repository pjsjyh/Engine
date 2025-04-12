#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
namespace so {
	class Application
	{
	public:
		Application();
		~Application();
		void Initialize(HWND hwnd, UINT width, UINT height);
		
		void Update();
		void LateUpdate();
		void Run();
		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		float mSpeed;
		float mX, mY;
		GameObject mPlayer;
	};
}


