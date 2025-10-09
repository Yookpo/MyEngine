#include "DiApplication.h"
#include "DiInput.h"
#include "DiTime.h"

namespace My
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(nullptr)
		, mBackBitmap(nullptr)
	{
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0.0f, 0.0f);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사(그리기)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}

