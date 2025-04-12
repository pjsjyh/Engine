#include "soApplication.h"
#include "Input.h"
#include "Time.h"
namespace so {
	Application::Application()
		:mHwnd(nullptr),
		mHdc(nullptr)
		, mSpeed(0.0f),
		mWidth(0),
		mHeight(0),
		mBackHdc(NULL),
		mBackBitmap(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);



		RECT rect = {0,0,width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight,0);
		ShowWindow(mHwnd, true);

		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);
		Input::Initialize();
		Time::Initialize();
	}
	void Application::Update() {

		Input::Update();
		Time::Update();
		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		//backbuffer에 있는걸 원본에 복사
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0,0,SRCCOPY);
	}
}

