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
		void Release();
		void Destroy();

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();
	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		float mSpeed;
		float mX, mY;
		//GameObject mPlayer;

		//std::vector<GameObject*> mGameObjects;
	};
}


