#pragma once
#include "DiGameObject.h"

namespace My
{
	class Bullet : public GameObject
	{
	public:
		Bullet();
		~Bullet();

		void Update();
		void Render(HDC hdc);

	private:
	};


}

