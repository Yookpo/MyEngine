#include "DiTitleScene.h"
#include "DiGameObject.h"
#include "DiPlayer.h"
#include "DiTransform.h"
#include "DiSpriteRenderer.h"
#include "../MyEngine_SOURCE/DiInput.h"
#include "../MyEngine_SOURCE/DiSceneManager.h"

namespace My
{
	// �ȳ� �ؽ�Ʈ �����ӿ� ����
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
			// ��� �̹��� ������Ʈ
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

		// ����Ű �Է� ����
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"PlayScene");
		}

		// �ȳ� �ؽ�Ʈ ������ ó��
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

		// Ÿ��Ʋ �ؽ�Ʈ
		SetBkMode(hdc, TRANSPARENT);
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 400, 200, L"Crazy Arcade", lstrlen(L"Crazy Arcade"));

		// �ȳ� ���� (������ ȿ��)
		if (showPressEnter)
		{
			SetTextColor(hdc, RGB(255, 255, 0));
			TextOut(hdc, 420, 400, L"Press Enter to Start", lstrlen(L"Press Enter to Start"));
		}
	}

}

