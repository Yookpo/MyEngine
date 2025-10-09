#pragma once
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

		float GetPositionX() const { return mX; }
		float GetPositionY() const { return mY; }



	private:
		// ���ӿ�����Ʈ�� ��ǥ
		float mX;
		float mY;
	};

}


