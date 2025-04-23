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
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T> static T* Instantiate(so::enums::eLayerType type, math::Vector2 position) {
			T* gameObject =  new T();
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPos(position);
			return gameObject;
		}
		static void Destroy(GameObject* obj) {
			obj->Death();
		}
	}
	
} 