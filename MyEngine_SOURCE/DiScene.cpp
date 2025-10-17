#include "DiScene.h"

namespace My
{
	Scene::Scene()
		: mLayers{}
	{
		createLayers();
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

	void Scene::AddGameObject(GameObject* gameObj, const  enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < mLayers.size(); i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter() {}
	void Scene::OnExit() {}

}