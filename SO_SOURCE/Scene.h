#pragma once
#include "Entity.h"

#include "GameObject.h"
#include "Shooting.h"
namespace so {
	class Scene:public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);
		void AddShootingObject(Shooting* gameObject);

		 void StartShoot(Shooting* shootObj);
	private:
		std::vector<GameObject*> mGameObjects;
		std::vector<Shooting*> mShootingObj;
	};
}


