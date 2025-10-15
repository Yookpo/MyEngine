#include "DiLayer.h"

namespace My
{
	Layer::Layer()
		: mGameObjects{}
	{
	}
	Layer::~Layer()
	{
	}
	void Layer::Initialize()
	{
		for (auto gameObj : mGameObjects)
		{
			if (!gameObj) continue;
			gameObj->Initialize();
		}
	}
	void Layer::Update()
	{
		for (auto gameObj : mGameObjects)
		{
			if (!gameObj) continue;
			gameObj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (auto gameObj : mGameObjects)
		{
			if (!gameObj) continue;
			gameObj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (auto gameObj : mGameObjects)
		{
			if (!gameObj) continue;
			gameObj->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObj)
	{
		if (!gameObj) return;
		mGameObjects.push_back(gameObj);
	}
}