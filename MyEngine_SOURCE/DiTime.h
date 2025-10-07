#pragma once
#include "CommonInclude.h"

namespace My
{
	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CpuFrequency;	// 로컬 CPU의 고유 진동수
		static LARGE_INTEGER PrevFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;

	};
}


