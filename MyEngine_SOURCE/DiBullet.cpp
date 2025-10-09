#include "DIBullet.h"
#include "DiTime.h"

namespace My
{
	Bullet::Bullet()
	{
	}
	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
		const float speed = 500.0f;

		float posX = GetPositionX();
		float posY = GetPositionY();

		posX += speed * Time::DeltaTime();

		SetPosition(posX, posY);
	}

	void Bullet::Render(HDC hdc)
	{
		float posX = GetPositionX();
		float posY = GetPositionY();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		Ellipse(hdc, posX - 5, posY - 5, posX + 5, posY + 5);

		SelectObject(hdc, oldPen);
		SelectObject(hdc, oldBrush);

		DeleteObject(redPen);
		DeleteObject(redBrush);
	}
}