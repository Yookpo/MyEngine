﻿#pragma once
#include "CommonInclude.h"

namespace My
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y);

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }



	private:
		// 게임오브젝트의 좌표
		float mX;
		float mY;
	};

}


