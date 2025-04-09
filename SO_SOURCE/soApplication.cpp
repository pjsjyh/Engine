#include "soApplication.h"

namespace so {
	Application::Application()
		:mHwnd(nullptr),
		mHdc(nullptr)
		, mSpeed(0.0f)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd) {
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
	}
	void Application::Update() {

		mSpeed += 0.01f;

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
		mPlayer.Render(mHdc);
	}
}

