#include "DiScene.h"

namespace My
{
	Scene::Scene()
		: mLayers{}
	{
		mLayers.resize((UINT)eLayerType::Max);
		for (size_t i = 0; i < mLayers.size(); i++)
		{
			mLayers[i] = new Layer();
		}
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (auto layer : mLayers)
		{
			if (!layer) continue;
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (auto layer : mLayers)
		{
			if (!layer) continue;
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (auto layer : mLayers)
		{
			if (!layer) continue;
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (auto layer : mLayers)
		{
			if (!layer) continue;
			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}


	void Scene::OnEnter() {}
	void Scene::OnExit() {}

}