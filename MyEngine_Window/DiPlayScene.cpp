#include "DiPlayScene.h"
#include "DiGameObject.h"
#include "DiPlayer.h"
#include "DiTransform.h"
#include "DiSpriteRenderer.h"

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
		Player* p1 = new Player();
		Transform* tr = p1->AddComponent<Transform>();
		tr->SetPos(800, 450);

		tr->SetName(L"TR");

		SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(p1);

		
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}