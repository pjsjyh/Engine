#include "Time.h"

namespace so {
	 LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevCpuFrequency = {};
	LARGE_INTEGER Time::CurrentCpuFrequency = {};
	float Time::mDeltaTime = 0.0f;

	void so::Time::Initialize()
	{
		//cpu 고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);
		//프로그램이 시작 했을 떄 현재 진동수
		QueryPerformanceCounter(&PrevCpuFrequency);
	}

	void so::Time::Update()
	{
		QueryPerformanceCounter(&CurrentCpuFrequency);

		float differenceFrequency 
			= static_cast<float>(CurrentCpuFrequency.QuadPart - PrevCpuFrequency.QuadPart);

		mDeltaTime = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);

		PrevCpuFrequency.QuadPart = CurrentCpuFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += mDeltaTime;
		float fps = 1.0f / mDeltaTime;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0,0,str,len);
	}
}

