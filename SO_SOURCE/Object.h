#pragma once
#include "Component.h"
#include "Layer.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"
namespace so
 {
	namespace object {
		template <typename T> static T* Instantiate(so::enums::eLayerType type) {
			T* gameObject =  new T();
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T> static T* Instantiate(so::enums::eLayerType type, math::Vector2 position) {
			T* gameObject =  new T();
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPos(position);
			return gameObject;
		}
		/*static void Destroy(GameObject* obj) {
			obj->Death();
		}*/
		static void DontDestroyOnLoad(GameObject* gameObject)
		{
			Scene* activeScene = SceneManager::GetActiveScene();
			// 현재씬에서 게임오브젝트를 지워준다.
			activeScene->EraseGameObject(gameObject);

			// 해당 게임오브젝트를 -> DontDestroy씬으로 넣어준다.
			Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
			dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
		}
	}
	
} 