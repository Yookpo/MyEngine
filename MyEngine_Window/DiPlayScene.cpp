﻿#include "DiPlayScene.h"
#include "DiGameObject.h"

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
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1000, rand() % 600);
			AddGameObject(obj);
		}
		
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