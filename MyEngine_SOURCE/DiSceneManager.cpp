#include "DiSceneManager.h"

namespace My
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		auto iter = mScene.find(name);
		if (iter != mScene.end())
		{
			mActiveScene = iter->second;
			mActiveScene->OnEnter();
		}

		return mActiveScene;
	}

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