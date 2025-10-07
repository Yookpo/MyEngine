#include "DiApplication.h"
#include "DiInput.h"
#include "DiTime.h"

namespace My
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
	{
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

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
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
}

