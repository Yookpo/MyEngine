#pragma once
#include "DiPlayScene.h"
#include "../MyEngine_SOURCE/DiSceneManager.h"

namespace My
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
