#include "soApplication.h"
#include "Input.h"
#include "Time.h"
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
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}

