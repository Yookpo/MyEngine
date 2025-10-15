#pragma once
#include "DiEntity.h"
#include "DiGameObject.h"

namespace My
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

