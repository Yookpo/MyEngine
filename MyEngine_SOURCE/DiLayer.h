#pragma once
#include "DiEntity.h"
#include "CommonInclude.h"
#include "DiGameObject.h"

namespace My
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* gameObj);

	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};


}
