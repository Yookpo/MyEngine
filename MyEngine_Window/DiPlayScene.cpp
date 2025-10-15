#include "DiPlayScene.h"
#include "DiGameObject.h"
#include "DiPlayer.h"
#include "DiTransform.h"
#include "DiSpriteRenderer.h"
#include "DiInput.h"
#include "DiTitleScene.h"
#include "DiSceneManager.h"

namespace My
{
	PlayScene::PlayScene()
		:Scene()
	{
	}

	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		{
			bg = new Player();

			Transform* tr = bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0.0f, 0.0f));
			tr->SetName(L"TR");
			
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\Diguedman\\source\\repos\\MyEngine\\Resources\\CloudOcean.png");


			Player* bz = new Player();

			Transform* tr1 = bz->AddComponent<Transform>();
			tr1->SetPos(Vector2(20.0f, 20.0f));
			tr1->SetName(L"TR");

			SpriteRenderer* sr1 = bz->AddComponent<SpriteRenderer>();
			sr1->SetName(L"SR");
			sr1->ImageLoad(L"C:\\Users\\Diguedman\\source\\repos\\MyEngine\\Resources\\baezzi.png");


			AddGameObject(bz, eLayerType::Player);
			AddGameObject(bg, eLayerType::BackGround);
		}

		
	}
	void PlayScene::Update()
	{
		Scene::Update();

		
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0.0f, 0.0f));
	}
}