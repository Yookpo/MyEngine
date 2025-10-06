#include "DiApplication.h"

namespace My
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f), mX(0.0f), mY(0.0f)
	{
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mSpeed += 0.01f;

		// 내가 오른쪽 키를 입력받았다면
		// x좌표가 +
		// 왼쪽 -> x - 
		// 위아래는 y +-
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}

	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환 (기존 DC에 등록되어있는 GDI 오브젝트)
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(mHdc, redPen);

		Rectangle(mHdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(mHdc, oldBrush);
		SelectObject(mHdc, oldPen);



		DeleteObject(blueBrush);
		DeleteObject(redPen);

	}
}

