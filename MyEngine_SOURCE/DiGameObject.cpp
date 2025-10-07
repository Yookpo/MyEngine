#include "DiGameObject.h"
#include "DiInput.h" 
#include "DiTime.h"

namespace My
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;

		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환 (기존 DC에 등록되어있는 GDI 오브젝트)
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}

	void GameObject::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}
}