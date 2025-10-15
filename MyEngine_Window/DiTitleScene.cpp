#include "DiTitleScene.h"
#include "DiGameObject.h"
#include "DiPlayer.h"
#include "DiTransform.h"
#include "DiSpriteRenderer.h"
#include "../MyEngine_SOURCE/DiInput.h"
#include "../MyEngine_SOURCE/DiSceneManager.h"

namespace My
{

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
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		// ����Ű �Է� ����
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

}

