#include "DiSceneManager.h"

namespace My
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
	}

	void SceneManager::Update()
	{
		if (mActiveScene)
		{
			mActiveScene->Update();
		}
	}

	void SceneManager::LateUpdate()
	{
		if (mActiveScene)
		{
			mActiveScene->LateUpdate();
		}
	}

	void SceneManager::Render(HDC hdc)
	{
		if (mActiveScene)
		{
			mActiveScene->Render(hdc);
		}
	}
}