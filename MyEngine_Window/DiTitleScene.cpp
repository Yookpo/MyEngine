#include "DiTitleScene.h"
#include "DiGameObject.h"
#include "DiPlayer.h"
#include "DiTransform.h"
#include "DiSpriteRenderer.h"
#include "../MyEngine_SOURCE/DiInput.h"
#include "../MyEngine_SOURCE/DiSceneManager.h"

namespace My
{
	// 안내 텍스트 깜빡임용 변수
	static int blinkCounter = 0;
	static bool showPressEnter = true;


	TitleScene::TitleScene()
		:Scene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		{
			// 배경 이미지 오브젝트
			Player* bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0.0f, 0.0f));

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\Diguedman\\source\\repos\\MyEngine\\Resources\\CrazyArcade.png");

			AddGameObject(bg);
		}

	}

	void TitleScene::Update()
	{
		Scene::Update();

		// 엔터키 입력 감지
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

		// 안내 텍스트 깜빡임 처리
		blinkCounter++;
		if (blinkCounter > 30)
		{
			showPressEnter = !showPressEnter;
			blinkCounter = 0;
		}
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		// 타이틀 텍스트
		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 400, 200, L"Crazy Arcade", lstrlen(L"Crazy Arcade"));

		// 안내 문구 (깜빡임 효과)
		if (showPressEnter)
		{
			SetTextColor(hdc, RGB(255, 255, 0));
			TextOut(hdc, 420, 400, L"Press Enter to Start", lstrlen(L"Press Enter to Start"));
		}
	}

}

