#pragma once
#include "CommonInclude.h"
#include "DiGameObject.h"


namespace My
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		// �÷��̾�
		GameObject mPlayer;
	};
}
