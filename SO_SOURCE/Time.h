#pragma once
#include "CommonInclude.h"
namespace so {
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return mDeltaTime; }
	private:
		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER PrevCpuFrequency;
		static LARGE_INTEGER CurrentCpuFrequency;
		static float mDeltaTime;
	};
}


