#include "soApplication.h"
#include "Input.h"
#include "Time.h"
#include "SceneManager.h"
#include "Resources.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "Fmod.h"
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
		
		adjustWindowRect(hwnd, width, height);
		
		createBuffer(width, height);
		initializeEtc();

		Fmod::Initialize();
		CollisionManager::Initialize();
		UIManager::Initialize();
		SceneManager::Initialize();


		
	}
	void Application::Update() {

		Input::Update();
		Time::Update();
		CollisionManager::Update();
		UIManager::Update();
		SceneManager::Update();

	}
	void Application::LateUpdate()
	{
		CollisionManager::LateUpdate();
		UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();

		Destroy();
	}
	void Application::Render()
	{
		clearRenderTarget();
		Time::Render(mBackHdc);
		CollisionManager::Render(mBackHdc);
		UIManager::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		//backbuffer에 있는걸 원본에 복사
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::Release()
	{
		SceneManager::Release();
		UIManager::Release();
		Resources::Release();
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::clearRenderTarget()
	{
		HBRUSH grayBrush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, grayBrush);

		Rectangle(mBackHdc, -1, -1, 1601, 901);

		(HBRUSH)SelectObject(mBackHdc, oldBrush);
		DeleteObject(grayBrush);

	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);



		RECT rect = { 0,0,width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}
}

