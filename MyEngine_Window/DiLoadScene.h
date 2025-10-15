#pragma once
#include "DiPlayScene.h"
#include "DiTitleScene.h"
#include "../MyEngine_SOURCE/DiSceneManager.h"

namespace My
{
	void LoadScene()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");


		SceneManager::LoadScene(L"TitleScene");
	}
}
